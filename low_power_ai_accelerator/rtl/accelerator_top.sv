
`timescale 1ns/1ps
module accelerator_top #(parameter int FIFO_DEPTH = 8)(
    input  logic        ctrl_clk, comp_clk, ctrl_rst_n, comp_rst_n,
    input  logic             load_weight,
    input  logic signed [7:0] weights [3:0][3:0],
    input  logic        act_wen,
    input  logic [31:0] act_wdata,
    output logic        act_wfull,
    input  logic        result_ren,
    output logic [31:0] result_rdata,
    output logic        result_rempty,
    input  logic        start, powerdown_req, wakeup,
    output logic        clk_en_out, iso_en, power_down,
    // DEBUG PORTS — expose snap[] and sa_psum_out[]
    output logic signed [31:0] dbg_snap    [0:3],
    output logic signed [31:0] dbg_psum    [0:3],
    output logic        [1:0]  dbg_state,
    output logic        [1:0]  dbg_snapcnt,
    output logic               dbg_snapwait
);
    logic clk_en, clk_en_s1, clk_en_comp;
    always_ff @(posedge comp_clk or negedge comp_rst_n) begin
        if (!comp_rst_n) begin clk_en_s1<=1'b0; clk_en_comp<=1'b0; end
        else begin clk_en_s1<=clk_en; clk_en_comp<=clk_en_s1; end
    end
    logic lw_s1, lw_comp;
    always_ff @(posedge comp_clk or negedge comp_rst_n) begin
        if (!comp_rst_n) begin lw_s1<=1'b0; lw_comp<=1'b0; end
        else begin lw_s1<=load_weight; lw_comp<=lw_s1; end
    end
    logic inference_done_comp, inf_done_s1, inference_done_ctrl;
    always_ff @(posedge ctrl_clk or negedge ctrl_rst_n) begin
        if (!ctrl_rst_n) begin inf_done_s1<=1'b0; inference_done_ctrl<=1'b0; end
        else begin inf_done_s1<=inference_done_comp; inference_done_ctrl<=inf_done_s1; end
    end
    power_ctrl_fsm #(.GATE_TIMEOUT(16)) u_power_fsm (
        .clk(ctrl_clk),.rst_n(ctrl_rst_n),.start(start),
        .inference_done(inference_done_ctrl),.powerdown_req(powerdown_req),
        .wakeup(wakeup),.clk_en(clk_en),.iso_en(iso_en),.power_down(power_down)
    );
    assign clk_en_out = clk_en;
    logic act_rempty, act_ren;
    logic [31:0] act_rdata;
    async_fifo #(.DEPTH(FIFO_DEPTH),.WIDTH(32)) u_act_fifo (
        .wclk(ctrl_clk),.wrst_n(ctrl_rst_n),.wen(act_wen),.wdata(act_wdata),.wfull(act_wfull),
        .rclk(comp_clk),.rrst_n(comp_rst_n),.ren(act_ren),.rdata(act_rdata),.rempty(act_rempty)
    );
    logic result_wfull, result_wen_r;
    logic [31:0] result_wdata_r;
    async_fifo #(.DEPTH(FIFO_DEPTH),.WIDTH(32)) u_result_fifo (
        .wclk(comp_clk),.wrst_n(comp_rst_n),.wen(result_wen_r),.wdata(result_wdata_r),.wfull(result_wfull),
        .rclk(ctrl_clk),.rrst_n(ctrl_rst_n),.ren(result_ren),.rdata(result_rdata),.rempty(result_rempty)
    );
    logic signed [7:0]  sa_act_in [0:3];
    logic signed [31:0] sa_psum_out [0:3];
    logic sa_output_valid;
    systolic_array u_array (
        .clk(comp_clk),.rst_n(comp_rst_n),.clk_en(clk_en_comp),.load_weight(lw_comp),
        .weights(weights),.act_in(sa_act_in),.psum_out(sa_psum_out),.output_valid(sa_output_valid)
    );
    typedef enum logic [1:0] {
        C_IDLE=2'b00, C_FEED=2'b01, C_SNAP=2'b10, C_DRAIN=2'b11
    } comp_state_t;
    comp_state_t comp_state;
    logic [1:0] feed_cnt, snap_cnt, drain_cnt;
    logic snap_wait;
    logic signed [7:0]  act_lat [0:3];
    logic signed [31:0] snap [0:3];
    // Expose debug ports
    assign dbg_snap[0]=snap[0]; assign dbg_snap[1]=snap[1];
    assign dbg_snap[2]=snap[2]; assign dbg_snap[3]=snap[3];
    assign dbg_psum[0]=sa_psum_out[0]; assign dbg_psum[1]=sa_psum_out[1];
    assign dbg_psum[2]=sa_psum_out[2]; assign dbg_psum[3]=sa_psum_out[3];
    assign dbg_state=comp_state; assign dbg_snapcnt=snap_cnt; assign dbg_snapwait=snap_wait;
    always_ff @(posedge comp_clk or negedge comp_rst_n) begin
        if (!comp_rst_n) begin
            comp_state<=C_IDLE; feed_cnt<=2'b0; snap_cnt<=2'b0;
            snap_wait<=1'b0; drain_cnt<=2'b0;
            result_wen_r<=1'b0; result_wdata_r<=32'sh0;
            for (int i=0;i<4;i++) begin act_lat[i]<=8'sh0; snap[i]<=32'sh0; end
        end else if (clk_en_comp) begin
            result_wen_r<=1'b0;
            case (comp_state)
                C_IDLE: if (!act_rempty) begin
                    act_lat[0]<=signed'(act_rdata[7:0]);
                    act_lat[1]<=signed'(act_rdata[15:8]);
                    act_lat[2]<=signed'(act_rdata[23:16]);
                    act_lat[3]<=signed'(act_rdata[31:24]);
                    feed_cnt<=2'b0; comp_state<=C_FEED;
                end
                C_FEED: begin
                    feed_cnt<=feed_cnt+2'b1;
                    if (feed_cnt==2'b11) begin snap_wait<=1'b0; snap_cnt<=2'b0; comp_state<=C_SNAP; end
                end
                C_SNAP: begin
                    if (!snap_wait) begin
                        snap_wait<=1'b1;
                    end else begin
                        snap[snap_cnt]<=sa_psum_out[snap_cnt];
                        snap_cnt<=snap_cnt+2'b1;
                        if (snap_cnt==2'b11) begin drain_cnt<=2'b0; comp_state<=C_DRAIN; end
                    end
                end
                C_DRAIN: if (!result_wfull) begin
                    result_wen_r<=1'b1;
                    result_wdata_r<=snap[drain_cnt];
                    drain_cnt<=drain_cnt+2'b1;
                    if (drain_cnt==2'b11) comp_state<=C_IDLE;
                end
                default: comp_state<=C_IDLE;
            endcase
        end
    end
    assign act_ren=(comp_state==C_IDLE)&&!act_rempty&&clk_en_comp;
    always_comb begin
        for (int r=0;r<4;r++)
            sa_act_in[r]=(comp_state==C_FEED&&feed_cnt==2'(r))?act_lat[r]:8'sh0;
    end
    logic inference_done_reg;
    always_ff @(posedge comp_clk or negedge comp_rst_n) begin
        if (!comp_rst_n) inference_done_reg<=1'b0;
        else if (clk_en_comp) begin
            if (comp_state==C_DRAIN&&drain_cnt==2'b11&&!result_wfull) inference_done_reg<=1'b1;
            else if (comp_state==C_FEED) inference_done_reg<=1'b0;
        end
    end
    assign inference_done_comp=inference_done_reg;
endmodule

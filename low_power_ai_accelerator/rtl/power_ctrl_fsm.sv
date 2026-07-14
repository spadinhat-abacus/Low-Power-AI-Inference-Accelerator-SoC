// ============================================================
// power_ctrl_fsm.sv — Accelerator power control FSM
//
// States:
//   IDLE       — reset state, array gated, awaiting inference request
//   ACTIVE     — inference running, array clock enabled
//   GATE       — inference done, array gated, awaiting next request
//                or timeout before deeper power-down
//   POWERDOWN  — deep power save, isolation enabled, domain off-request
//
// Transitions:
//   IDLE       → ACTIVE     : start asserted
//   ACTIVE     → GATE       : inference_done (output_valid from array)
//   GATE       → ACTIVE     : start asserted (new inference)
//   GATE       → POWERDOWN  : gate_cnt reaches GATE_TIMEOUT, or powerdown_req
//   POWERDOWN  → IDLE       : wakeup asserted
//
// Output sequencing on POWERDOWN entry:
//   Cycle 0 : iso_en asserted (isolate compute domain outputs)
//   Cycle 1 : power_down asserted (request domain shutoff)
//   This ensures isolation cells are active before supply is removed.
//
// Parameter:
//   GATE_TIMEOUT — idle cycles in GATE before entering POWERDOWN
// ============================================================
`timescale 1ns/1ps

module power_ctrl_fsm #(
    parameter int GATE_TIMEOUT = 16
)(
    input  logic clk,
    input  logic rst_n,

    // Control inputs
    input  logic start,           // Inference request from host interface
    input  logic inference_done,  // output_valid from systolic array
    input  logic powerdown_req,   // External power-down request
    input  logic wakeup,          // Wake-up / power-up complete signal

    // Power control outputs
    output logic clk_en,          // Clock enable to systolic array
    output logic iso_en,          // Isolation enable (assert before power_down)
    output logic power_down       // Power-down request to supply network
);

    // --------------------------------------------------------
    // State encoding
    // --------------------------------------------------------
    typedef enum logic [1:0] {
        IDLE      = 2'b00,
        ACTIVE    = 2'b01,
        GATE      = 2'b10,
        POWERDOWN = 2'b11
    } state_t;

    state_t curr_state, next_state;

    // --------------------------------------------------------
    // Gate timeout counter
    // Counts idle cycles in GATE state before requesting powerdown
    // --------------------------------------------------------
    localparam int CNT_W = $clog2(GATE_TIMEOUT + 1);
    logic [CNT_W-1:0] gate_cnt;
    logic             gate_timeout;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            gate_cnt <= '0;
        else if (curr_state == GATE)
            gate_cnt <= gate_timeout ? gate_cnt : gate_cnt + CNT_W'(1);
        else
            gate_cnt <= '0;
    end

    assign gate_timeout = (gate_cnt == CNT_W'(GATE_TIMEOUT - 1));

    // --------------------------------------------------------
    // Isolation sequencing register
    // iso_en is asserted one cycle before power_down on entry
    // to POWERDOWN, ensuring isolation cells clamp outputs first.
    // --------------------------------------------------------
    logic iso_pending;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            iso_pending <= 1'b0;
        else if (next_state == POWERDOWN && curr_state != POWERDOWN)
            iso_pending <= 1'b1;   // about to enter POWERDOWN — raise iso
        else if (curr_state != POWERDOWN)
            iso_pending <= 1'b0;
    end

    // --------------------------------------------------------
    // State register
    // --------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            curr_state <= IDLE;
        else
            curr_state <= next_state;
    end

    // --------------------------------------------------------
    // Next-state logic
    // --------------------------------------------------------
    always_comb begin
        next_state = curr_state;
        case (curr_state)
            IDLE:      if (start)                          next_state = ACTIVE;
            ACTIVE:    if (inference_done)                 next_state = GATE;
            GATE:      begin
                           if (start)                      next_state = ACTIVE;
                           else if (gate_timeout
                                    || powerdown_req)      next_state = POWERDOWN;
                       end
            POWERDOWN: if (wakeup)                         next_state = IDLE;
            default:                                       next_state = IDLE;
        endcase
    end

    // --------------------------------------------------------
    // Output logic (registered for glitch-free drive)
    // --------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            clk_en     <= 1'b0;
            iso_en     <= 1'b0;
            power_down <= 1'b0;
        end else begin
            case (next_state)
                IDLE: begin
                    clk_en     <= 1'b0;
                    iso_en     <= 1'b0;
                    power_down <= 1'b0;
                end
                ACTIVE: begin
                    clk_en     <= 1'b1;
                    iso_en     <= 1'b0;
                    power_down <= 1'b0;
                end
                GATE: begin
                    clk_en     <= 1'b0;
                    iso_en     <= 1'b0;
                    power_down <= 1'b0;
                end
                POWERDOWN: begin
                    clk_en     <= 1'b0;
                    iso_en     <= 1'b1;          // isolate first
                    power_down <= iso_pending;   // assert power_down one cycle after iso
                end
                default: begin
                    clk_en     <= 1'b0;
                    iso_en     <= 1'b0;
                    power_down <= 1'b0;
                end
            endcase
        end
    end

endmodule

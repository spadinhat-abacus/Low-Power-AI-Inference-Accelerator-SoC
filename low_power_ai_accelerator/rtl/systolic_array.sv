// ============================================================
// systolic_array.sv — 4×4 INT8 weight-stationary systolic array
//
// Computes for each output column c:
//   psum_out[c] = Σ_r ( W[r][c] × X[r] )
//
// Data flow:
//   act   — left → right  (1 cycle per PE)
//   psum  — top  → bottom (1 cycle per PE)
//
// Caller must stagger act_in[] by 1 cycle per row before
// presenting to the array (external skew convention).
//
// output_valid asserts after ROWS+COLS cycles (pipeline fill
// + 1 cycle for the output register).
// ============================================================
`timescale 1ns/1ps

module systolic_array #(
    parameter int ROWS = 4,
    parameter int COLS = 4
)(
    input  logic        clk,
    input  logic        rst_n,
    input  logic        clk_en,            // Array-level gate

    // Weight loading — hold load_weight high for 1 cycle
    // with all weights valid on weights[][]
    input  logic             load_weight,
    input  logic signed [7:0] weights [ROWS-1:0][COLS-1:0],

    // Staggered activation inputs — caller pre-staggers by 1 cycle/row
    input  logic signed [7:0]  act_in   [ROWS-1:0],

    // Outputs — registered, valid only when output_valid is high
    output logic signed [31:0] psum_out [COLS-1:0],
    output logic               output_valid
);

    // --------------------------------------------------------
    // Internal wires
    // act_wire[r][c]  — activation entering PE(r,c)
    // psum_wire[r][c] — partial sum entering PE(r,c) from above
    // --------------------------------------------------------
    logic signed [7:0]  act_wire  [ROWS-1:0][COLS:0];
    logic signed [31:0] psum_wire [ROWS:0][COLS-1:0];

    // Left boundary: connect activation inputs to column 0
    generate
        for (genvar r = 0; r < ROWS; r++) begin : act_left
            assign act_wire[r][0] = act_in[r];
        end
    endgenerate

    // Top boundary: zero partial sums into row 0
    generate
        for (genvar c = 0; c < COLS; c++) begin : psum_top
            assign psum_wire[0][c] = 32'sh0;
        end
    endgenerate

    // --------------------------------------------------------
    // PE grid
    // --------------------------------------------------------
    generate
        for (genvar r = 0; r < ROWS; r++) begin : row_g
            for (genvar c = 0; c < COLS; c++) begin : col_g
                pe u_pe (
                    .clk         (clk),
                    .rst_n       (rst_n),
                    .clk_en      (clk_en),
                    .load_weight (load_weight),
                    .weight_in   (weights[r][c]),
                    .act_in      (act_wire[r][c]),
                    .psum_in     (psum_wire[r][c]),
                    .act_out     (act_wire[r][c+1]),
                    .psum_out    (psum_wire[r+1][c])
                );
            end
        end
    endgenerate

    // --------------------------------------------------------
    // Output register — psum_wire[ROWS][c] is combinational;
    // register it for a glitch-free, timing-clean output
    // --------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            for (int c = 0; c < COLS; c++)
                psum_out[c] <= 32'sh0;
        end else if (clk_en) begin
            for (int c = 0; c < COLS; c++)
                psum_out[c] <= psum_wire[ROWS][c];
        end
    end

    // --------------------------------------------------------
    // output_valid counter
    // Pipeline fill = ROWS + COLS - 1 cycles
    // +1 for the output register = ROWS + COLS total
    // --------------------------------------------------------
    localparam int VALID_CYCLE = ROWS + COLS;
    localparam int CNT_WIDTH   = $clog2(VALID_CYCLE + 1);
    logic [CNT_WIDTH-1:0] cycle_cnt;

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            cycle_cnt    <= '0;
            output_valid <= 1'b0;
        end else if (clk_en) begin
            if (!output_valid) begin
                if (cycle_cnt == CNT_WIDTH'(VALID_CYCLE - 1))
                    output_valid <= 1'b1;
                else
                    cycle_cnt <= cycle_cnt + 1;
            end
        end
    end

endmodule

// ============================================================
// pe.sv — INT8 Processing Element
// Weight-stationary dataflow
// Holds one INT8 weight, receives activation from left,
// partial sum from above, outputs activation right, sum below
// Accumulator: 32-bit to prevent overflow across 4 MACs
//
// Clock enable (clk_en) gates both the MAC accumulator and
// the activation pipeline. In the 4×4 array, clk_en should
// be asserted/deasserted at the row or array level — do NOT
// gate individual PEs mid-computation as this will stall
// activation propagation to right-hand neighbors.
// ============================================================
`timescale 1ns/1ps

module pe (
    input  logic        clk,
    input  logic        rst_n,
    input  logic        clk_en,              // Per-PE fine-grain clock gate

    // Weight loading
    input  logic        load_weight,
    input  logic signed [7:0]  weight_in,

    // Dataflow ports
    input  logic signed [7:0]  act_in,       // From left neighbor
    input  logic signed [31:0] psum_in,      // From above neighbor
    output logic signed [7:0]  act_out,      // To right neighbor
    output logic signed [31:0] psum_out      // To below neighbor
);

    logic signed [7:0]  weight_reg;
    logic signed [15:0] product;             // Intermediate: 8×8 signed → 16 bits

    // --------------------------------------------------------
    // Weight register — loaded once, stationary during inference
    // Not gated: weight must be retained during idle periods
    // --------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            weight_reg <= 8'h0;
        else if (load_weight)
            weight_reg <= weight_in;
    end

    // --------------------------------------------------------
    // Combinational multiply
    // 8×8 signed product fits in 16 bits (max: 128×128 = 16,384)
    // --------------------------------------------------------
    always_comb
        product = weight_reg * act_in;

    // --------------------------------------------------------
    // Activation pipeline — 1 cycle delay, propagates right
    // Gated with clk_en: holds last value when PE is idle
    // --------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            act_out <= 8'h0;
        else if (clk_en)
            act_out <= act_in;
    end

    // --------------------------------------------------------
    // MAC: psum_out = psum_in + (weight * activation)
    // 16-bit product sign-extended to 32 bits before addition
    // --------------------------------------------------------
    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n)
            psum_out <= 32'h0;
        else if (clk_en)
            psum_out <= psum_in + 32'(product);
    end

endmodule

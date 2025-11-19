//============================================================
// sync_fifo.sv
// Simple synchronous FIFO with separate push/pop
//============================================================

module sync_fifo #(
    parameter int WIDTH = 128,
    parameter int DEPTH = 8
)(
    input  logic               clk,
    input  logic               reset,

    input  logic               push,
    input  logic [WIDTH-1:0]   din,
    output logic               full,

    input  logic               pop,
    output logic [WIDTH-1:0]   dout,
    output logic               empty
);
  // Address width
  localparam int AW = (DEPTH <= 2)  ? 1 :
                      (DEPTH <= 4)  ? 2 :
                      (DEPTH <= 8)  ? 3 :
                      (DEPTH <= 16) ? 4 :
                      (DEPTH <= 32) ? 5 :
                                      6;

  logic [WIDTH-1:0] mem [0:DEPTH-1];
  logic [AW-1:0]    rd_ptr, wr_ptr;
  logic [AW:0]      count;

  assign full  = (count == DEPTH);
  assign empty = (count == 0);
  assign dout  = mem[rd_ptr];

  always_ff @(posedge clk or posedge reset) begin
    if (reset) begin
      rd_ptr <= '0;
      wr_ptr <= '0;
      count  <= '0;
    end else begin
      // push
      if (push && !full) begin
        mem[wr_ptr] <= din;
        wr_ptr      <= wr_ptr + 1'b1;
        count       <= count  + 1'b1;
      end

      // pop
      if (pop && !empty) begin
        rd_ptr <= rd_ptr + 1'b1;
        count  <= count  - 1'b1;
      end
    end
  end
endmodule


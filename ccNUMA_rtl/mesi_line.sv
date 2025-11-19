// mesi_line.sv
`include "ccnuma_pkg.sv"
module mesi_line #(
  parameter ADDR_W = ccnuma_pkg::ADDR_W
) (
  input  logic                clk,
  input  logic                rst_n,

  // control
  input  logic                local_read,   // local core read request to this line (single-cycle pulse)
  input  logic                local_write,  // local core write request (single-cycle pulse)
  input  logic                snoop_read,   // snoop: some remote read request
  input  logic                snoop_upgrade,// snoop: remote upgrade (R->W intent)
  input  logic                snoop_inv,    // snoop invalidate

  // outputs
  output logic [1:0]          state_out,    // exported state for monitors (2-bit enum mapped below)
  output logic                must_send_data // owner must forward data on intervention
);

  typedef enum logic [3:0] {
    S_I=4'd0,
    S_IS=4'd1, // waiting for data on a local read miss
    S_S=4'd2,
    S_SM=4'd3, // upgrade in progress
    S_E=4'd4,
    S_M=4'd5
  } state_t;

  state_t state, next_state;

  // combinational next-state logic (simplified)
  always_comb begin
    next_state = state;
    must_send_data = 1'b0;
    case (state)
      S_I: begin
        if (local_read) next_state = S_IS;
        else if (local_write) next_state = S_M;
        else next_state = S_I;
      end
      S_IS: begin
        // assume data returns next cycle (testbench will drive)
        if (snoop_read) begin
          // remote snoop while waiting - improbable in simple model
          next_state = S_IS;
        end
      end
      S_S: begin
        if (local_write) next_state = S_SM; // request upgrade
        else next_state = S_S;
        if (snoop_upgrade) begin
          // remote upgrade to write -> invalidate local shared
          next_state = S_I;
        end
        if (snoop_read) begin end
      end
      S_SM: begin
        // waiting for invalidation acks; after success go to M
      end
      S_E: begin
        if (local_write) next_state = S_M;
        if (snoop_read) begin
          // downgrade E->S and supply data
          must_send_data = 1'b1;
          next_state = S_S;
        end
      end
      S_M: begin
        if (snoop_read) begin
          // supply data and downgrade to S (or I depending)
          must_send_data = 1'b1;
          next_state = S_S;
        end
        if (snoop_inv) begin
          // remote invalidate forces writeback
          next_state = S_I;
        end
      end
      default: next_state = S_I;
    endcase
  end

  // sequential update
  always_ff @(posedge clk or negedge rst_n) begin
    if (!rst_n) state <= S_I;
    else state <= next_state;
  end

  // expose a compact state_out: 00=I,01=S,10=E,11=M
  always_comb begin
    case (state)
      S_I:   state_out = 2'b00;
      S_S:   state_out = 2'b01;
      S_E:   state_out = 2'b10;
      S_M:   state_out = 2'b11;
      default: state_out = 2'b00;
    endcase
  end

  // Basic sanity assertions (formal-friendly style)
  // no two states here; kept per-line so only local checks
  // For more: add temporal assertions in testbench monitors.

endmodule


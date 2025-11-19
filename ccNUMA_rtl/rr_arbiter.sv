//============================================================
// rr_arbiter.sv
// Parameterizable round-robin arbiter
//============================================================

module rr_arbiter #(
    parameter int N_REQ = 4
)(
    input  logic                   clk,
    input  logic                   reset,
    input  logic [N_REQ-1:0]       req,
    output logic [N_REQ-1:0]       grant,
    output logic [$clog2(N_REQ)-1:0] grant_idx
);
  logic [$clog2(N_REQ)-1:0]       last_grant;

  // combinational: pick next requester after last_grant
  always_comb begin
    grant      = '0;
    grant_idx  = '0;
    if (req != '0) begin
      // simple linear search from last_grant+1
      for (int i = 0; i < N_REQ; i++) begin
        int idx = (last_grant + 1 + i) % N_REQ;
        if (req[idx]) begin
          grant[idx] = 1'b1;
          grant_idx  = idx[$clog2(N_REQ)-1:0];
          break;
        end
      end
    end
  end

  // update pointer
  always_ff @(posedge clk or posedge reset) begin
    if (reset) begin
      last_grant <= '0;
    end else begin
      if (grant != '0) begin
        last_grant <= grant_idx;
      end
    end
  end

endmodule


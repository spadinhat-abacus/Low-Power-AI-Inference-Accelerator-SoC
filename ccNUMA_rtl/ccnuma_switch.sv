// ccnuma_switch.sv
// N-port switch with simple round-robin arbitration and
// broadcast support (dst == CCNUMA_DST_BCAST).
//============================================================

`include "ccnuma_pkg.sv"
`include "node_port_if.sv"
`include "rr_arbiter.sv"

module ccnuma_switch #(
    parameter int N_PORTS = 4
)(
    input  logic clk,
    input  logic reset,

    // Fabric ports (array of node_port_if)
    node_port_if ports [N_PORTS]
);
  import ccnuma_pkg::*;

  // ---------------------------------------
  // Collect request valids
  // ---------------------------------------
  logic [N_PORTS-1:0] req_vec;
  for (genvar i = 0; i < N_PORTS; i++) begin : g_req_vec
    assign req_vec[i] = ports[i].req_valid;
  end

  // Arbiter outputs
  logic [N_PORTS-1:0] grant_vec;
  logic [$clog2(N_PORTS)-1:0] grant_idx;

  rr_arbiter #(
    .N_REQ(N_PORTS)
  ) u_rr (
    .clk       (clk),
    .reset     (reset),
    .req       (req_vec),
    .grant     (grant_vec),
    .grant_idx (grant_idx)
  );

  // Handy signal
  logic have_grant;
  assign have_grant = (grant_vec != '0);

  // ---------------------------------------
  // Main routing logic
  // ---------------------------------------
  packet_t cur_pkt;
  logic    cur_pkt_valid;

  // Latch granted packet (simple 1-stage pipeline)
  always_ff @(posedge clk or posedge reset) begin
    if (reset) begin
      cur_pkt       <= '0;
      cur_pkt_valid <= 1'b0;
    end else begin
      if (have_grant && ports[grant_idx].req_valid && ports[grant_idx].req_ready) begin
        cur_pkt       <= ports[grant_idx].req_pkt;
        cur_pkt_valid <= 1'b1;
      end else if (cur_pkt_valid) begin
        // Packet consumed in same cycle as routed
        cur_pkt_valid <= 1'b0;
      end
    end
  end

  // By default, no responses
  for (genvar j = 0; j < N_PORTS; j++) begin : g_default_rsp
    // default rsp_valid deasserted; rsp_pkt don't-care
    // We'll override combinationally below
    // Use procedural block to avoid multiple drivers.
  end

  // req_ready generation:
  // Source sees ready when we have a grant and we've successfully
  // delivered the packet to all destinations (simple model).
  // Here we take a very conservative approach:
  // - For unicast: dest rsp_ready must be high
  // - For broadcast: all target rsp_ready must be high.
  always_comb begin
    // default: nobody ready
    for (int i = 0; i < N_PORTS; i++) begin
      ports[i].req_ready = 1'b0;
    end

    if (have_grant) begin
      int src = grant_idx;
      packet_t pkt = ports[src].req_pkt;

      if (pkt.dst == CCNUMA_DST_BCAST) begin
        // check all destinations except src
        logic all_ready = 1'b1;
        for (int d = 0; d < N_PORTS; d++) begin
          if (d != src) begin
            if (!ports[d].rsp_ready)
              all_ready = 1'b0;
          end
        end
        ports[src].req_ready = all_ready;
      end else begin
        int dst_idx = pkt.dst; // NOTE: requires dst < N_PORTS
        if (dst_idx < N_PORTS) begin
          ports[src].req_ready = ports[dst_idx].rsp_ready;
        end else begin
          ports[src].req_ready = 1'b0; // illegal dst; could assert
        end
      end
    end
  end

  // Drive responses (fabric->agent)
  always_comb begin
    // default outputs
    for (int d = 0; d < N_PORTS; d++) begin
      ports[d].rsp_valid = 1'b0;
      ports[d].rsp_pkt   = '0;
    end

    if (have_grant) begin
      int src = grant_idx;
      packet_t pkt = ports[src].req_pkt;

      if (ports[src].req_ready && ports[src].req_valid) begin
        if (pkt.dst == CCNUMA_DST_BCAST) begin
          for (int d = 0; d < N_PORTS; d++) begin
            if (d != src) begin
              ports[d].rsp_valid = 1'b1;
              ports[d].rsp_pkt   = pkt;
            end
          end
        end else begin
          int dst_idx = pkt.dst;
          if (dst_idx < N_PORTS) begin
            ports[dst_idx].rsp_valid = 1'b1;
            ports[dst_idx].rsp_pkt   = pkt;
          end
        end
      end
    end
  end

  // TODO: hook in snoop filter, directory, transaction tracker, QoS, etc.
endmodule



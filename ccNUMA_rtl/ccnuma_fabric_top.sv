//============================================================
// ccnuma_fabric_top.sv
// Simple top-level wrapper instantiating the switch and
// exposing an array of node_port_if ports.
//============================================================

`include "ccnuma_pkg.sv"
`include "node_port_if.sv"
`include "ccnuma_switch.sv"

module ccnuma_fabric_top #(
    parameter int N_PORTS = 4
)(
    input  logic clk,
    input  logic reset,

    // Expose ports to be connected to NIUs or direct agents
    output node_port_if ports [N_PORTS]
);
  // Bind clock/reset into interfaces
  for (genvar i = 0; i < N_PORTS; i++) begin : g_bind
    assign ports[i].clk   = clk;
    assign ports[i].reset = reset;
  end

  // Switch
  ccnuma_switch #(
    .N_PORTS(N_PORTS)
  ) u_switch (
    .clk   (clk),
    .reset (reset),
    .ports (ports)
  );

endmodule


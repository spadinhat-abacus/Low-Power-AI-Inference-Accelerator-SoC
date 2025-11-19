//============================================================
// node_port_if.sv
// Common fabric port interface for all agents
//============================================================

`include "ccnuma_pkg.sv"

interface node_port_if #(parameter int ID = 0)
(
  input  logic clk,
  input  logic reset
);
  import ccnuma_pkg::*;

  // ---------------------------
  // Request channel (agent->fabric)
  // ---------------------------
  logic    req_valid;
  packet_t req_pkt;
  logic    req_ready;

  // ---------------------------
  // Response channel (fabric->agent)
  // ---------------------------
  logic    rsp_valid;
  packet_t rsp_pkt;
  logic    rsp_ready;

endinterface : node_port_if


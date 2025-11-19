//============================================================
// niu.sv
// Node Interface Unit skeleton
// - Bridges an "agent" to the ccNUMA fabric node_port_if
// - Agent side also uses packet_t here (you can replace
//   later with a more CPU/memory-friendly interface).
//============================================================

`include "ccnuma_pkg.sv"
`include "node_port_if.sv"

module niu #(
    parameter int ID            = 0,
    parameter int TX_DEPTH      = 8,
    parameter int RX_DEPTH      = 8
)(
    input  logic         clk,
    input  logic         reset,

    // ------------------------------
    // Agent side (to core/mem/IO)
    // ------------------------------
    input  logic                 ag_req_valid,
    input  ccnuma_pkg::packet_t  ag_req_pkt,
    output logic                 ag_req_ready,

    output logic                 ag_rsp_valid,
    output ccnuma_pkg::packet_t  ag_rsp_pkt,
    input  logic                 ag_rsp_ready,

    // ------------------------------
    // Fabric port
    // ------------------------------
    node_port_if #(ID)           port
);
  import ccnuma_pkg::*;

  // TX FIFO (agent -> fabric)
  logic                      tx_push, tx_pop;
  logic [ $bits(packet_t)-1:0 ] tx_din, tx_dout;
  logic                      tx_full, tx_empty;

  sync_fifo #(
    .WIDTH($bits(packet_t)),
    .DEPTH(TX_DEPTH)
  ) u_tx_fifo (
    .clk   (clk),
    .reset (reset),
    .push  (tx_push),
    .din   (tx_din),
    .full  (tx_full),
    .pop   (tx_pop),
    .dout  (tx_dout),
    .empty (tx_empty)
  );

  // RX FIFO (fabric -> agent)
  logic                      rx_push, rx_pop;
  logic [ $bits(packet_t)-1:0 ] rx_din, rx_dout;
  logic                      rx_full, rx_empty;

  sync_fifo #(
    .WIDTH($bits(packet_t)),
    .DEPTH(RX_DEPTH)
  ) u_rx_fifo (
    .clk   (clk),
    .reset (reset),
    .push  (rx_push),
    .din   (rx_din),
    .full  (rx_full),
    .pop   (rx_pop),
    .dout  (rx_dout),
    .empty (rx_empty)
  );

  // ------------------------------
  // Agent -> TX FIFO
  // ------------------------------
  assign ag_req_ready = !tx_full;
  assign tx_push      = ag_req_valid && ag_req_ready;
  assign tx_din       = ag_req_pkt;

  // ------------------------------
  // TX FIFO -> fabric req channel
  // ------------------------------
  assign port.req_valid = !tx_empty;
  assign port.req_pkt   = packet_t'(tx_dout);
  assign tx_pop         = port.req_valid && port.req_ready;

  // ------------------------------
  // Fabric rsp channel -> RX FIFO
  // ------------------------------
  assign rx_push = port.rsp_valid && !rx_full;
  assign rx_din  = port.rsp_pkt;
  assign port.rsp_ready = !rx_full;

  // ------------------------------
  // RX FIFO -> Agent
  // ------------------------------
  assign ag_rsp_valid = !rx_empty;
  assign ag_rsp_pkt   = packet_t'(rx_dout);
  assign rx_pop       = ag_rsp_valid && ag_rsp_ready;

endmodule


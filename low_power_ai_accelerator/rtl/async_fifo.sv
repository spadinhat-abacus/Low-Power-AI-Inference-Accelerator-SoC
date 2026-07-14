// ============================================================
// async_fifo.sv — Gray-coded asynchronous FIFO
//
// Parameters:
//   DEPTH — number of entries (must be power of 2, default 8)
//   WIDTH — data width (default 32)
//
// Full/empty flags:
//   wfull  — in write clock domain, based on sync'd read pointer
//   rempty — in read clock domain, based on sync'd write pointer
//
// CDC handling:
//   Two-flop synchronizers on Gray-coded pointer crossings.
//   Gray code ensures only one bit changes per pointer increment,
//   making the crossing safe despite metastability.
//
// Reset:
//   wrst_n and rrst_n are treated as pre-synchronized to their
//   respective clock domains. Both should be asserted together
//   and de-asserted after their domain's clock is stable.
// ============================================================
`timescale 1ns/1ps

module async_fifo #(
    parameter int DEPTH = 8,    // must be power of 2
    parameter int WIDTH = 32
)(
    // Write side (control/IO clock domain)
    input  logic             wclk,
    input  logic             wrst_n,
    input  logic             wen,
    input  logic [WIDTH-1:0] wdata,
    output logic             wfull,

    // Read side (compute clock domain)
    input  logic             rclk,
    input  logic             rrst_n,
    input  logic             ren,
    output logic [WIDTH-1:0] rdata,
    output logic             rempty
);

    localparam int ADDR_WIDTH = $clog2(DEPTH);

    // --------------------------------------------------------
    // Dual-port memory
    // Written in wclk domain, read combinationally in rclk domain
    // --------------------------------------------------------
    logic [WIDTH-1:0] mem [0:DEPTH-1];

    // --------------------------------------------------------
    // Write pointer — write clock domain
    // Binary for address, Gray for CDC crossing
    // --------------------------------------------------------
    logic [ADDR_WIDTH:0] wptr_bin;
    logic [ADDR_WIDTH:0] wptr_gray;

    always_ff @(posedge wclk or negedge wrst_n) begin
        if (!wrst_n)
            wptr_bin <= '0;
        else if (wen && !wfull) begin
            mem[wptr_bin[ADDR_WIDTH-1:0]] <= wdata;
            wptr_bin                      <= wptr_bin + 1;
        end
    end

    assign wptr_gray = wptr_bin ^ (wptr_bin >> 1);

    // --------------------------------------------------------
    // Read pointer — read clock domain
    // --------------------------------------------------------
    logic [ADDR_WIDTH:0] rptr_bin;
    logic [ADDR_WIDTH:0] rptr_gray;

    always_ff @(posedge rclk or negedge rrst_n) begin
        if (!rrst_n)
            rptr_bin <= '0;
        else if (ren && !rempty)
            rptr_bin <= rptr_bin + 1;
    end

    assign rptr_gray = rptr_bin ^ (rptr_bin >> 1);
    assign rdata     = mem[rptr_bin[ADDR_WIDTH-1:0]];

    // --------------------------------------------------------
    // Synchronize write pointer → read clock domain (2-flop)
    // --------------------------------------------------------
    logic [ADDR_WIDTH:0] wptr_sync1, wptr_sync;

    always_ff @(posedge rclk or negedge rrst_n) begin
        if (!rrst_n) begin
            wptr_sync1 <= '0;
            wptr_sync  <= '0;
        end else begin
            wptr_sync1 <= wptr_gray;
            wptr_sync  <= wptr_sync1;
        end
    end

    // --------------------------------------------------------
    // Synchronize read pointer → write clock domain (2-flop)
    // --------------------------------------------------------
    logic [ADDR_WIDTH:0] rptr_sync1, rptr_sync;

    always_ff @(posedge wclk or negedge wrst_n) begin
        if (!wrst_n) begin
            rptr_sync1 <= '0;
            rptr_sync  <= '0;
        end else begin
            rptr_sync1 <= rptr_gray;
            rptr_sync  <= rptr_sync1;
        end
    end

    // --------------------------------------------------------
    // Full flag — write clock domain
    // Full when MSB and MSB-1 of wptr_gray are inverted relative
    // to rptr_sync, with all lower bits matching.
    // This detects when write has lapped read by exactly DEPTH.
    // --------------------------------------------------------
    assign wfull = (wptr_gray == {~rptr_sync[ADDR_WIDTH:ADDR_WIDTH-1],
                                    rptr_sync[ADDR_WIDTH-2:0]});

    // --------------------------------------------------------
    // Empty flag — read clock domain
    // Empty when rptr_gray equals synchronized write pointer.
    // Conservative: may read slightly stale wptr — safe to under-read.
    // --------------------------------------------------------
    assign rempty = (rptr_gray == wptr_sync);

endmodule

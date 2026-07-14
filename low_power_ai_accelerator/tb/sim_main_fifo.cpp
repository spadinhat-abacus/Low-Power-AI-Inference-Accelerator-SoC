// ============================================================
// sim_main_fifo.cpp — Verilator testbench for async_fifo.sv
//
// Compile:
//   verilator --cc rtl/async_fifo.sv --exe tb/sim_main_fifo.cpp &&
//   make -C obj_dir -f Vasync_fifo.mk && ./obj_dir/Vasync_fifo
//
// Test coverage:
//   T1  Reset — rempty=1, wfull=0
//   T2  Single write/read — data integrity
//   T3  Fill to full — wfull asserts
//   T4  Write when full — no corruption
//   T5  Drain to empty — all data correct, rempty asserts
//   T6  Wrap-around — fill, drain, fill again
//   T7  Different clock rates — write 2x faster than read
//
// Note on read timing:
//   rdata is combinational (mem[rptr_bin]). Read rdata BEFORE
//   calling rtick() — the tick increments rptr, after which
//   rdata points to the next (unread) address.
// ============================================================

#include "Vasync_fifo.h"
#include "verilated.h"
#include <iostream>
#include <cstdint>

Vasync_fifo* dut;
int pass_count = 0, fail_count = 0;
static const int DEPTH = 8;  // must match RTL parameter

// --------------------------------------------------------
void wtick() { dut->wclk = 1; dut->eval(); dut->wclk = 0; dut->eval(); }
void rtick() { dut->rclk = 1; dut->eval(); dut->rclk = 0; dut->eval(); }
void tick_both() {
    dut->wclk = 1; dut->rclk = 1; dut->eval();
    dut->wclk = 0; dut->rclk = 0; dut->eval();
}

// --------------------------------------------------------
void reset_fifo() {
    dut->wrst_n = 0; dut->rrst_n = 0;
    dut->wen = 0;    dut->ren = 0; dut->wdata = 0;
    for (int i = 0; i < 3; i++) tick_both();
    dut->wrst_n = 1; dut->rrst_n = 1;
    tick_both();
}

// --------------------------------------------------------
// Write one entry — caller must ensure !wfull
// --------------------------------------------------------
void write_one(uint32_t data) {
    dut->wen = 1; dut->wdata = data;
    wtick();
    dut->wen = 0;
}

// --------------------------------------------------------
// Read one entry — caller must ensure !rempty
// Captures rdata BEFORE rtick (combinational read)
// --------------------------------------------------------
uint32_t read_one() {
    uint32_t data = dut->rdata;  // valid at current rptr
    dut->ren = 1;
    rtick();                     // advance rptr
    dut->ren = 0;
    return data;
}

// --------------------------------------------------------
// Let write pointer propagate to read clock domain (2-flop sync)
void sync_w_to_r(int n = 3) { for (int i = 0; i < n; i++) rtick(); }

// Let read pointer propagate to write clock domain
void sync_r_to_w(int n = 3) { for (int i = 0; i < n; i++) wtick(); }

// --------------------------------------------------------
void check(const char* name, bool ok) {
    if (ok) { std::cout << "[PASS] " << name << "\n"; pass_count++; }
    else     { std::cerr << "[FAIL] " << name << "\n"; fail_count++; }
}

// --------------------------------------------------------
int main(int argc, char** argv) {
    VerilatedContext* ctx = new VerilatedContext;
    ctx->commandArgs(argc, argv);
    dut = new Vasync_fifo{ctx};

    std::cout << "=== Async FIFO Testbench ===\n";

    // ------------------------------------------------
    // T1: Reset
    // ------------------------------------------------
    reset_fifo();
    check("T1: Reset — rempty=1 wfull=0",
          dut->rempty == 1 && dut->wfull == 0);

    // ------------------------------------------------
    // T2: Single write then read — data integrity
    // ------------------------------------------------
    reset_fifo();
    write_one(0xDEADBEEF);
    sync_w_to_r();                          // let wptr reach read domain
    check("T2a: Not empty after write", dut->rempty == 0);
    uint32_t val = read_one();
    check("T2b: Data correct (0xDEADBEEF)", val == 0xDEADBEEF);
    sync_w_to_r();                          // rptr now matches wptr in read domain
    check("T2c: Empty after drain",  dut->rempty == 1);

    // ------------------------------------------------
    // T3: Fill to full — wfull asserts after DEPTH writes
    // ------------------------------------------------
    reset_fifo();
    for (int i = 0; i < DEPTH; i++) write_one((uint32_t)i);
    sync_r_to_w();                          // rptr_sync=0 still, but let it settle
    check("T3: wfull after DEPTH writes", dut->wfull == 1);

    // ------------------------------------------------
    // T4: Write when full — no data corruption
    // ------------------------------------------------
    reset_fifo();
    for (int i = 0; i < DEPTH; i++) write_one((uint32_t)i);
    sync_r_to_w();
    // Attempt write to full FIFO — should be blocked
    dut->wen = 1; dut->wdata = 0xFF;
    wtick(); dut->wen = 0;
    // Drain and verify original data intact
    sync_w_to_r();
    bool no_corruption = true;
    for (int i = 0; i < DEPTH; i++) {
        uint32_t d = read_one();
        if (d != (uint32_t)i) no_corruption = false;
    }
    check("T4: No corruption on write-when-full", no_corruption);

    // ------------------------------------------------
    // T5: Drain to empty — all data correct, rempty asserts
    // ------------------------------------------------
    reset_fifo();
    for (int i = 0; i < DEPTH; i++) write_one((uint32_t)(i * 10));
    sync_w_to_r();
    bool data_ok = true;
    for (int i = 0; i < DEPTH; i++) {
        uint32_t d = read_one();
        if (d != (uint32_t)(i * 10)) data_ok = false;
    }
    sync_w_to_r();                          // let wptr settle in read domain
    check("T5a: Data integrity on full drain", data_ok);
    check("T5b: rempty after drain",          dut->rempty == 1);

    // ------------------------------------------------
    // T6: Wrap-around — fill, drain, fill again
    // Pointer wraps from DEPTH*2 (mod 2*DEPTH) back to 0
    // ------------------------------------------------
    reset_fifo();
    // First fill and drain
    for (int i = 0; i < DEPTH; i++) write_one((uint32_t)i);
    sync_w_to_r();
    for (int i = 0; i < DEPTH; i++) read_one();
    sync_r_to_w(); sync_w_to_r();          // sync both pointers after wrap
    // Second fill with distinct data
    for (int i = 0; i < DEPTH; i++) write_one((uint32_t)(i + 100));
    sync_w_to_r();
    bool wrap_ok = true;
    for (int i = 0; i < DEPTH; i++) {
        uint32_t d = read_one();
        if (d != (uint32_t)(i + 100)) wrap_ok = false;
    }
    check("T6: Wrap-around data correct", wrap_ok);

    // ------------------------------------------------
    // T7: Different clock rates — wclk 2x faster than rclk
    // Write 4 entries at 2x rate, read back at 1x rate
    // ------------------------------------------------
    reset_fifo();
    for (int i = 0; i < 4; i++) {
        write_one((uint32_t)(i + 200));
        wtick();                            // extra wclk tick (2x rate)
    }
    sync_w_to_r();
    bool rate_ok = true;
    for (int i = 0; i < 4; i++) {
        uint32_t d = read_one();
        if (d != (uint32_t)(i + 200)) rate_ok = false;
    }
    check("T7: Data correct at 2x write / 1x read rate", rate_ok);

    // ------------------------------------------------
    std::cout << "============================\n"
              << pass_count << " PASSED | " << fail_count << " FAILED\n"
              << "============================\n";

    delete dut; delete ctx;
    return fail_count ? 1 : 0;
}

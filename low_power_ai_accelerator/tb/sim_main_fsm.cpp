// ============================================================
// sim_main_fsm.cpp — Verilator testbench for power_ctrl_fsm.sv
//
// Compile:
//   verilator --cc rtl/power_ctrl_fsm.sv --exe tb/sim_main_fsm.cpp &&
//   make -C obj_dir -f Vpower_ctrl_fsm.mk && ./obj_dir/Vpower_ctrl_fsm
//
// Test coverage:
//   T1  Reset — all outputs deasserted
//   T2  IDLE → ACTIVE — clk_en asserts on start
//   T3  ACTIVE → GATE — clk_en deasserts on inference_done
//   T4  GATE → ACTIVE — clk_en re-asserts on new start
//   T5  GATE → POWERDOWN via timeout
//   T6  GATE → POWERDOWN via explicit powerdown_req
//   T7  Isolation sequencing — iso_en leads power_down by 1 cycle
//   T8  POWERDOWN → IDLE on wakeup — all outputs clear
//   T9  Back-to-back inferences — GATE→ACTIVE→GATE cycle
// ============================================================

#include "Vpower_ctrl_fsm.h"
#include "verilated.h"
#include <iostream>
#include <cstdint>

Vpower_ctrl_fsm* dut;
int pass_count = 0, fail_count = 0;
static const int GATE_TIMEOUT = 16;  // must match RTL parameter

// --------------------------------------------------------
void tick() { dut->clk = 1; dut->eval(); dut->clk = 0; dut->eval(); }

void reset_fsm() {
    dut->rst_n = 0;
    dut->start = 0; dut->inference_done = 0;
    dut->powerdown_req = 0; dut->wakeup = 0;
    tick(); tick();
    dut->rst_n = 1; tick();
}

void check(const char* name, bool ok) {
    if (ok) { std::cout << "[PASS] " << name << "\n"; pass_count++; }
    else     { std::cerr << "[FAIL] " << name << "\n"; fail_count++; }
}

// --------------------------------------------------------
// Drive FSM into ACTIVE (from IDLE)
// --------------------------------------------------------
void goto_active() {
    dut->start = 1; tick(); dut->start = 0;
}

// --------------------------------------------------------
// Drive FSM into GATE (from IDLE via ACTIVE)
// --------------------------------------------------------
void goto_gate() {
    goto_active();
    dut->inference_done = 1; tick(); dut->inference_done = 0;
}

// --------------------------------------------------------
// Drive FSM into POWERDOWN via timeout from GATE
// --------------------------------------------------------
void goto_powerdown() {
    goto_gate();
    for (int i = 0; i < GATE_TIMEOUT; i++) tick();
}

// --------------------------------------------------------
int main(int argc, char** argv) {
    VerilatedContext* ctx = new VerilatedContext;
    ctx->commandArgs(argc, argv);
    dut = new Vpower_ctrl_fsm{ctx};

    std::cout << "=== Power Control FSM Testbench ===\n";

    // ------------------------------------------------
    // T1: Reset — all outputs deasserted
    // ------------------------------------------------
    reset_fsm();
    check("T1: Reset — clk_en=0 iso_en=0 power_down=0",
          dut->clk_en == 0 && dut->iso_en == 0 && dut->power_down == 0);

    // ------------------------------------------------
    // T2: IDLE → ACTIVE — clk_en asserts
    // ------------------------------------------------
    reset_fsm();
    goto_active();
    check("T2: IDLE→ACTIVE — clk_en=1",
          dut->clk_en == 1 && dut->iso_en == 0 && dut->power_down == 0);

    // ------------------------------------------------
    // T3: ACTIVE → GATE — clk_en deasserts on inference_done
    // ------------------------------------------------
    reset_fsm();
    goto_gate();
    check("T3: ACTIVE→GATE — clk_en=0",
          dut->clk_en == 0 && dut->iso_en == 0 && dut->power_down == 0);

    // ------------------------------------------------
    // T4: GATE → ACTIVE — clk_en re-asserts on new start
    // ------------------------------------------------
    reset_fsm();
    goto_gate();
    dut->start = 1; tick(); dut->start = 0;
    check("T4: GATE→ACTIVE — clk_en=1",
          dut->clk_en == 1 && dut->iso_en == 0 && dut->power_down == 0);

    // ------------------------------------------------
    // T5: GATE → POWERDOWN via timeout (GATE_TIMEOUT=16 cycles)
    // After timeout: iso_en=1, power_down=0 (entry cycle)
    // One more tick:  iso_en=1, power_down=1 (settled)
    // ------------------------------------------------
    reset_fsm();
    goto_gate();
    for (int i = 0; i < GATE_TIMEOUT; i++) tick();
    check("T5a: Timeout — iso_en=1 power_down=0 on entry",
          dut->clk_en == 0 && dut->iso_en == 1 && dut->power_down == 0);
    tick();
    check("T5b: Timeout — power_down=1 one cycle after iso_en",
          dut->iso_en == 1 && dut->power_down == 1);

    // ------------------------------------------------
    // T6: GATE → POWERDOWN via explicit powerdown_req
    // ------------------------------------------------
    reset_fsm();
    goto_gate();
    tick(); tick();                          // a few cycles in GATE, not at timeout
    dut->powerdown_req = 1; tick(); dut->powerdown_req = 0;
    check("T6: Explicit powerdown_req — iso_en=1",
          dut->clk_en == 0 && dut->iso_en == 1 && dut->power_down == 0);

    // ------------------------------------------------
    // T7: Isolation sequencing
    // iso_en MUST assert one full cycle before power_down
    // This is the critical ordering requirement for power shutoff
    // ------------------------------------------------
    reset_fsm();
    goto_gate();
    for (int i = 0; i < GATE_TIMEOUT - 1; i++) tick();  // one tick before timeout
    bool before_pd  = (dut->iso_en == 0 && dut->power_down == 0);
    tick();                                  // timeout fires — POWERDOWN entry
    bool iso_first  = (dut->iso_en == 1 && dut->power_down == 0);
    tick();                                  // settled in POWERDOWN
    bool pd_follows = (dut->iso_en == 1 && dut->power_down == 1);
    check("T7a: Before POWERDOWN — iso=0 pd=0",  before_pd);
    check("T7b: Entry cycle — iso=1 pd=0",       iso_first);
    check("T7c: Settled — iso=1 pd=1",           pd_follows);

    // ------------------------------------------------
    // T8: POWERDOWN → IDLE on wakeup — all outputs clear
    // ------------------------------------------------
    reset_fsm();
    goto_powerdown();
    tick(); tick();                          // settle in POWERDOWN
    dut->wakeup = 1; tick(); dut->wakeup = 0;
    check("T8: POWERDOWN→IDLE — clk_en=0 iso=0 pd=0",
          dut->clk_en == 0 && dut->iso_en == 0 && dut->power_down == 0);

    // ------------------------------------------------
    // T9: Back-to-back inferences — GATE→ACTIVE→GATE
    // Verifies gate_cnt resets on re-entry to GATE
    // ------------------------------------------------
    reset_fsm();
    goto_gate();
    tick(); tick();                          // 2 cycles in GATE (before timeout)
    dut->start = 1; tick(); dut->start = 0; // new inference
    check("T9a: GATE→ACTIVE (second inference)", dut->clk_en == 1);
    dut->inference_done = 1; tick(); dut->inference_done = 0;
    check("T9b: ACTIVE→GATE (second done)",
          dut->clk_en == 0 && dut->iso_en == 0);
    // Verify gate_cnt restarted — run full timeout again
    for (int i = 0; i < GATE_TIMEOUT; i++) tick();
    check("T9c: Timeout still fires after gate_cnt reset",
          dut->iso_en == 1 && dut->power_down == 0);

    // ------------------------------------------------
    std::cout << "===================================\n"
              << pass_count << " PASSED | " << fail_count << " FAILED\n"
              << "===================================\n";

    delete dut; delete ctx;
    return fail_count ? 1 : 0;
}

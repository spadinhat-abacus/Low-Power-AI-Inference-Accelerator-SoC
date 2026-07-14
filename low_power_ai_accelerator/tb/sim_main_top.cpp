// ============================================================
// sim_main_top.cpp — Verilator testbench for accelerator_top.sv
//
// Compile:
//   verilator --top-module accelerator_top --cc            \
//     rtl/PE.sv rtl/systolic_array.sv                      \
//     rtl/async_fifo.sv rtl/power_ctrl_fsm.sv              \
//     rtl/accelerator_top.sv --exe tb/sim_main_top.cpp &&  \
//   make -C obj_dir -f Vaccelerator_top.mk &&              \
//   ./obj_dir/Vaccelerator_top
//
// Clock ratio: comp_clk runs 2x per ctrl_clk tick in collect_results.
// This ensures the compute domain drains results before the power
// FSM can gate clk_en — realistic for SoCs where compute clock
// is faster than the control/IO clock.
//
// Note: back-to-back inferences without reset are not tested here.
// inference_done clearing across clock domains requires a handshake
// protocol; flagged as a known design gap for future work.
//
// Test coverage:
//   T1  Reset — power outputs deasserted, result FIFO empty
//   T2  Identity weights — end-to-end output mirrors input vector
//   T3  Arbitrary W×X — validated against C++ golden reference
//   T4  Power FSM integration — clk_en asserts on start
//   T5  Negative weights — signed arithmetic end-to-end
// ============================================================

#include "Vaccelerator_top.h"
#include "verilated.h"
#include <iostream>
#include <cstdint>

Vaccelerator_top* dut;
int pass_count = 0, fail_count = 0;

void ctrl_tick() { dut->ctrl_clk=1; dut->eval(); dut->ctrl_clk=0; dut->eval(); }
void comp_tick() { dut->comp_clk=1; dut->eval(); dut->comp_clk=0; dut->eval(); }
void tick_both() {
    dut->ctrl_clk=1; dut->comp_clk=1; dut->eval();
    dut->ctrl_clk=0; dut->comp_clk=0; dut->eval();
}

// --------------------------------------------------------
void reset_top() {
    dut->ctrl_rst_n=0; dut->comp_rst_n=0;
    dut->load_weight=0; dut->act_wen=0;
    dut->result_ren=0; dut->start=0;
    dut->powerdown_req=0; dut->wakeup=0;
    dut->act_wdata=0;
    for (int r=0; r<4; r++)
        for (int c=0; c<4; c++)
            dut->weights[r][c] = 0;
    for (int i=0; i<4; i++) tick_both();
    dut->ctrl_rst_n=1; dut->comp_rst_n=1;
    tick_both();
}

// --------------------------------------------------------
// Load weights — hold load_weight=1 through comp_ticks so the
// two-flop synchronizer (lw_s1 → lw_comp) catches it on comp_clk.
// Deassert only after lw_comp has propagated.
// --------------------------------------------------------
void load_w(int8_t W[4][4]) {
    for (int r=0; r<4; r++)
        for (int c=0; c<4; c++)
            dut->weights[r][c] = (uint8_t)W[r][c];
    dut->load_weight = 1;
    ctrl_tick();
    for (int i=0; i<3; i++) comp_tick();  // comp samples load_weight=1 ✓
    dut->load_weight = 0;
    comp_tick();                           // lw_comp settles to 0
}

// --------------------------------------------------------
// Assert start — power FSM IDLE→ACTIVE, clk_en asserts
// --------------------------------------------------------
void go_active() {
    dut->start = 1; ctrl_tick(); dut->start = 0;
    for (int i=0; i<3; i++) comp_tick();   // sync clk_en into comp domain
}

// --------------------------------------------------------
// Write packed activation to input FIFO
// wdata = {act[3], act[2], act[1], act[0]}
// --------------------------------------------------------
void write_act(int8_t act[4]) {
    uint32_t packed = ((uint8_t)act[3] << 24) | ((uint8_t)act[2] << 16) |
                      ((uint8_t)act[1] <<  8) | ((uint8_t)act[0]);
    dut->act_wen = 1; dut->act_wdata = packed;
    ctrl_tick(); dut->act_wen = 0;
    for (int i=0; i<3; i++) comp_tick();   // sync write pointer to comp domain
}

// --------------------------------------------------------
// Run until 4 results appear in result FIFO, collect them.
// Ticks comp 2x per ctrl tick so compute domain drains results
// before ctrl FSM can deassert clk_en.
// rdata is combinational — captured BEFORE ren advances rptr.
// --------------------------------------------------------
bool collect_results(int32_t got[4], const char* label="", int timeout=500) {
    int n = 0;
    int iter = 0;
    while (n < 4 && timeout-- > 0) {
        comp_tick(); comp_tick(); ctrl_tick();
        iter++;
        // Print debug info during C_SNAP phase (state=2)
        if (dut->dbg_state == 2)
            std::cout << "  [DBG] iter=" << iter
                      << " state=SNAP snap_cnt=" << (int)dut->dbg_snapcnt
                      << " snap_wait=" << (int)dut->dbg_snapwait
                      << " psum=[" << (int32_t)dut->dbg_psum[0]
                      << "," << (int32_t)dut->dbg_psum[1]
                      << "," << (int32_t)dut->dbg_psum[2]
                      << "," << (int32_t)dut->dbg_psum[3] << "]\n";
        if (!dut->result_rempty) {
            got[n] = (int32_t)dut->result_rdata;
            std::cout << "  [DBG] iter=" << iter << " read got[" << n << "]=" << got[n]
                      << " snap=[" << (int32_t)dut->dbg_snap[0]
                      << "," << (int32_t)dut->dbg_snap[1]
                      << "," << (int32_t)dut->dbg_snap[2]
                      << "," << (int32_t)dut->dbg_snap[3] << "]\n";
            n++;
            dut->result_ren = 1; ctrl_tick(); dut->result_ren = 0;
        }
    }
    return (n == 4);
}

// --------------------------------------------------------
// Golden reference: psum_out[c] = Σ_r W[r][c] * X[r]
// --------------------------------------------------------
void golden(int8_t W[4][4], int8_t X[4], int32_t exp[4]) {
    for (int c=0; c<4; c++) {
        exp[c] = 0;
        for (int r=0; r<4; r++)
            exp[c] += (int32_t)W[r][c] * (int32_t)X[r];
    }
}

// --------------------------------------------------------
void check(const char* name, bool ok) {
    if (ok) { std::cout << "[PASS] " << name << "\n"; pass_count++; }
    else     { std::cerr << "[FAIL] " << name << "\n"; fail_count++; }
}

void check_results(const char* name, int32_t got[4], int32_t exp[4]) {
    bool ok = true;
    for (int c=0; c<4; c++) if (got[c] != exp[c]) ok = false;
    if (!ok)
        for (int c=0; c<4; c++)
            std::cerr << "  psum[" << c << "] got=" << got[c]
                      << " exp=" << exp[c] << "\n";
    check(name, ok);
}

// --------------------------------------------------------
int main(int argc, char** argv) {
    VerilatedContext* ctx = new VerilatedContext;
    ctx->commandArgs(argc, argv);
    dut = new Vaccelerator_top{ctx};

    std::cout << "=== Accelerator Top Testbench ===\n";

    int32_t got[4], exp[4];

    // ------------------------------------------------
    // T1: Reset — power outputs clear, result FIFO empty
    // ------------------------------------------------
    reset_top();
    check("T1: Reset — clk_en=0 iso=0 pd=0",
          dut->clk_en_out==0 && dut->iso_en==0 && dut->power_down==0);
    check("T1: Reset — result_rempty=1", dut->result_rempty==1);

    // ------------------------------------------------
    // T2: Identity weights — output mirrors input vector
    // W = I, X = [1,2,3,4] → psum_out[c] = X[c]
    // ------------------------------------------------
    {
        int8_t W[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
        int8_t X[4]    = {1, 2, 3, 4};
        reset_top(); load_w(W); go_active(); write_act(X);
        bool ok = collect_results(got);
        golden(W, X, exp);
        check("T2: Results collected",            ok);
        check_results("T2: Identity W — out=X",  got, exp);
    }

    // ------------------------------------------------
    // T3: Arbitrary weights — golden reference validation
    // W = [[1,2,3,4],[5,6,7,8],[1,1,1,1],[2,3,4,5]]
    // X = [1,2,3,4] → expected [22,29,36,43]
    // ------------------------------------------------
    {
        int8_t W[4][4] = {{1,2,3,4},{5,6,7,8},{1,1,1,1},{2,3,4,5}};
        int8_t X[4]    = {1, 2, 3, 4};
        reset_top(); load_w(W); go_active(); write_act(X);
        bool ok = collect_results(got);
        golden(W, X, exp);
        check("T3: Results collected",           ok);
        check_results("T3: Arbitrary W×X",       got, exp);
    }

    // ------------------------------------------------
    // T4: Power FSM integration
    // Verify clk_en asserts after start, results still correct
    // ------------------------------------------------
    {
        int8_t W[4][4] = {{2,0,0,0},{0,2,0,0},{0,0,2,0},{0,0,0,2}};
        int8_t X[4]    = {3, 3, 3, 3};
        reset_top(); load_w(W); go_active();
        check("T4: clk_en=1 after start", dut->clk_en_out==1);
        write_act(X);
        bool ok = collect_results(got);
        golden(W, X, exp);
        check("T4: Results collected",                   ok);
        check_results("T4: Correct results via power FSM", got, exp);
    }

    // ------------------------------------------------
    // T5: Negative weights — signed arithmetic end-to-end
    // W = -I, X = [1,2,3,4] → psum_out[c] = -X[c]
    // ------------------------------------------------
    {
        int8_t W[4][4] = {{-1,0,0,0},{0,-1,0,0},{0,0,-1,0},{0,0,0,-1}};
        int8_t X[4]    = {1, 2, 3, 4};
        reset_top(); load_w(W); go_active(); write_act(X);
        bool ok = collect_results(got);
        golden(W, X, exp);
        check("T5: Results collected",           ok);
        check_results("T5: Negative weights (-I)", got, exp);
    }

    // ------------------------------------------------
    std::cout << "=================================\n"
              << pass_count << " PASSED | " << fail_count << " FAILED\n"
              << "=================================\n";

    delete dut; delete ctx;
    return fail_count ? 1 : 0;
}

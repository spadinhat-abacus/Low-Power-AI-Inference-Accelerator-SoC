// sim_main.cpp — Verilator testbench for pe.sv
// verilator --cc rtl/PE.sv --exe tb/sim_main.cpp &&
// make -C obj_dir -f VPE.mk && ./obj_dir/VPE

#include "VPE.h"
#include "verilated.h"
#include <iostream>
#include <cstdint>

VPE* dut;
int  pass_count = 0, fail_count = 0;

void tick() {
    dut->clk = 1; dut->eval();
    dut->clk = 0; dut->eval();
}

void reset() {
    dut->rst_n = 0; dut->clk_en = 0;
    dut->load_weight = 0; dut->weight_in = 0;
    dut->act_in = 0; dut->psum_in = 0;
    tick(); tick();
    dut->rst_n = 1; tick();
}

void load_w(int8_t w) {
    dut->load_weight = 1; dut->weight_in = w;
    tick(); dut->load_weight = 0;
}

void check(const char* name, int8_t a, int32_t ps, int8_t ea, int32_t ep) {
    dut->act_in = a; dut->psum_in = ps; dut->clk_en = 1;
    tick();
    int8_t  ga = dut->act_out;
    int32_t gp = dut->psum_out;
    if (ga == ea && gp == ep) {
        std::cout << "[PASS] " << name << "\n"; pass_count++;
    } else {
        std::cerr << "[FAIL] " << name
                  << " act=" << (int)ga << "(exp " << (int)ea << ")"
                  << " psum=" << gp << "(exp " << ep << ")\n"; fail_count++;
    }
}

int main(int argc, char** argv) {
    VerilatedContext* ctx = new VerilatedContext;
    ctx->commandArgs(argc, argv);
    dut = new VPE{ctx};

    std::cout << "=== PE Testbench ===\n";

    // T1: Reset
    reset();
    if ((int8_t)dut->act_out == 0 && (int32_t)dut->psum_out == 0) {
        std::cout << "[PASS] T1: Reset\n"; pass_count++;
    } else {
        std::cerr << "[FAIL] T1: Reset\n"; fail_count++;
    }

    // T2: Basic MAC — w=3, a=4, ps=0 → psum=12
    load_w(3);
    check("T2: Basic MAC      (w= 3, a= 4, ps=  0)", 4, 0, 4, 12);

    // T3: Partial sum — w=3, a=4, ps=20 → psum=32
    check("T3: Partial sum    (w= 3, a= 4, ps= 20)", 4, 20, 4, 32);

    // T4: Neg weight — w=-5, a=6, ps=0 → psum=-30
    load_w(-5);
    check("T4: Neg weight     (w=-5, a= 6, ps=  0)", 6, 0, 6, -30);

    // T5: Neg activation — w=4, a=-7, ps=0 → psum=-28
    load_w(4);
    check("T5: Neg activation (w= 4, a=-7, ps=  0)", -7, 0, -7, -28);

    // T6: Both negative — w=-3, a=-8, ps=0 → psum=24
    load_w(-3);
    check("T6: Both negative  (w=-3, a=-8, ps=  0)", -8, 0, -8, 24);

    // T7: Clock gating — outputs must hold when clk_en=0
    load_w(2);
    check("T7a: Pre-gate      (w= 2, a=10, ps=  0)", 10, 0, 10, 20);
    dut->clk_en = 0; dut->act_in = 77; dut->psum_in = 999;
    tick(); tick();
    if ((int8_t)dut->act_out == 10 && (int32_t)dut->psum_out == 20) {
        std::cout << "[PASS] T7b: Clock gating held\n"; pass_count++;
    } else {
        std::cerr << "[FAIL] T7b: Clock gating\n"; fail_count++;
    }

    // T8: Column sim — w=2, acts={1,2,3,4}, feed psum back each cycle → 20
    reset(); load_w(2); dut->clk_en = 1;
    int8_t  acts[4]   = {1, 2, 3, 4};
    int32_t running   = 0;
    for (int i = 0; i < 4; i++) {
        dut->act_in = acts[i]; dut->psum_in = running;
        tick(); running = dut->psum_out;
    }
    if (running == 20) {
        std::cout << "[PASS] T8: Column accumulation psum=" << running << "\n"; pass_count++;
    } else {
        std::cerr << "[FAIL] T8: Column accumulation psum=" << running << "(exp 20)\n"; fail_count++;
    }

    // T9: Max values — w=127, a=127 → psum=16129
    reset(); load_w(127);
    check("T9: Max values     (w=127, a=127, ps=  0)", 127, 0, 127, 16129);

    std::cout << "===================\n"
              << pass_count << " PASSED | " << fail_count << " FAILED\n"
              << "===================\n";

    delete dut; delete ctx;
    return fail_count ? 1 : 0;
}

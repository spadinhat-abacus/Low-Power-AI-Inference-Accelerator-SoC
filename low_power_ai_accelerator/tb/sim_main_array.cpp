// ============================================================
// sim_main.cpp — Verilator testbench for systolic_array.sv
//
// Compile:
//   verilator --cc rtl/PE.sv rtl/systolic_array.sv \
//             --exe tb/sim_main.cpp &&
//   make -C obj_dir -f Vsystolic_array.mk &&
//   ./obj_dir/Vsystolic_array
//
// Array computes: psum_out[c] = Σ_r ( W[r][c] × X[r] )
//
// Sampling convention:
//   After 4 staggered activation ticks, psum_out[c] is
//   valid one tick per column — read got[c] immediately
//   after tick ROWS + c (before next tick overwrites it).
//   output_valid fires on the 8th clk_en tick (ROWS+COLS).
//
// Test coverage:
//   T1  Reset — outputs cleared, output_valid low
//   T2  Identity weights — output mirrors input vector
//   T3  All-ones weights — each output = sum of inputs
//   T4  Negative weights
//   T5  Negative activations
//   T6  Arbitrary W×X validated against golden reference
//   T7  Clock gating — pipeline frozen, results still correct
// ============================================================

#include "Vsystolic_array.h"
#include "verilated.h"
#include <iostream>
#include <cstdint>

Vsystolic_array* dut;
int pass_count = 0, fail_count = 0;

// --------------------------------------------------------
void tick() {
    dut->clk = 1; dut->eval();
    dut->clk = 0; dut->eval();
}

// --------------------------------------------------------
void reset_array() {
    dut->rst_n = 0; dut->clk_en = 0; dut->load_weight = 0;
    for (int r = 0; r < 4; r++) dut->act_in[r] = 0;
    tick(); tick();
    dut->rst_n = 1; tick();
}

// --------------------------------------------------------
// Load all 16 weights in one cycle (load_weight pulse)
// Weight register in PE is not clk_en gated — works at clk_en=0
// --------------------------------------------------------
void load_w(int8_t W[4][4]) {
    for (int r = 0; r < 4; r++)
        for (int c = 0; c < 4; c++)
            dut->weights[r][c] = (uint8_t)W[r][c];
    dut->load_weight = 1; tick(); dut->load_weight = 0;
}

// --------------------------------------------------------
// Golden reference: psum_out[c] = Σ_r W[r][c] * X[r]
// --------------------------------------------------------
void golden(int8_t W[4][4], int8_t X[4], int32_t exp[4]) {
    for (int c = 0; c < 4; c++) {
        exp[c] = 0;
        for (int r = 0; r < 4; r++)
            exp[c] += (int32_t)W[r][c] * (int32_t)X[r];
    }
}

// --------------------------------------------------------
// Run one matrix-vector multiply and collect outputs.
// Staggered activation: row r receives X[r] on tick r.
// Outputs sampled at their individual valid cycles.
// --------------------------------------------------------
void run(int8_t X[4], int32_t got[4]) {
    dut->clk_en = 1;

    // 4 staggered activation ticks
    for (int t = 0; t < 4; t++) {
        for (int r = 0; r < 4; r++)
            dut->act_in[r] = (r == t) ? (uint8_t)X[r] : 0;
        tick();
    }

    // 4 drain ticks — one column becomes valid per tick
    // psum_out[c] valid immediately after tick ROWS + c
    for (int r = 0; r < 4; r++) dut->act_in[r] = 0;
    for (int c = 0; c < 4; c++) {
        tick();
        got[c] = (int32_t)dut->psum_out[c];
    }
    // After tick 7 (ROWS+COLS): output_valid should be high
}

// --------------------------------------------------------
void check(const char* name, int32_t got[4], int32_t exp[4]) {
    bool ok = true;
    for (int c = 0; c < 4; c++) if (got[c] != exp[c]) ok = false;
    if (ok) {
        std::cout << "[PASS] " << name << "\n";
        pass_count++;
    } else {
        std::cerr << "[FAIL] " << name << "\n";
        for (int c = 0; c < 4; c++)
            if (got[c] != exp[c])
                std::cerr << "  psum[" << c << "] got=" << got[c]
                          << " exp=" << exp[c] << "\n";
        fail_count++;
    }
}

// --------------------------------------------------------
int main(int argc, char** argv) {
    VerilatedContext* ctx = new VerilatedContext;
    ctx->commandArgs(argc, argv);
    dut = new Vsystolic_array{ctx};

    std::cout << "=== Systolic Array Testbench ===\n";

    int32_t got[4], exp[4];

    // ------------------------------------------------
    // T1: Reset — all psum_out zero, output_valid low
    // ------------------------------------------------
    reset_array();
    {
        bool ok = !dut->output_valid;
        for (int c = 0; c < 4; c++)
            if ((int32_t)dut->psum_out[c] != 0) ok = false;
        if (ok) { std::cout << "[PASS] T1: Reset\n"; pass_count++; }
        else    { std::cerr << "[FAIL] T1: Reset\n"; fail_count++; }
    }

    // ------------------------------------------------
    // T2: Identity weights — W[r][c] = 1 if r==c else 0
    // X = [1,2,3,4] → psum_out[c] = X[c]
    // ------------------------------------------------
    {
        int8_t W[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
        int8_t X[4]    = {1, 2, 3, 4};
        reset_array(); load_w(W); run(X, got); golden(W, X, exp);
        check("T2: Identity weights — out mirrors X", got, exp);
        if (dut->output_valid) { std::cout << "[PASS] T2: output_valid asserted\n"; pass_count++; }
        else { std::cerr << "[FAIL] T2: output_valid did not assert\n"; fail_count++; }
    }

    // ------------------------------------------------
    // T3: All-ones weights, X = [1,1,1,1]
    // psum_out[c] = 4 for all c
    // ------------------------------------------------
    {
        int8_t W[4][4] = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
        int8_t X[4]    = {1, 1, 1, 1};
        reset_array(); load_w(W); run(X, got); golden(W, X, exp);
        check("T3: All-ones weights — out = 4 per col", got, exp);
    }

    // ------------------------------------------------
    // T4: Negative weights — W = -I, X = [1,2,3,4]
    // psum_out[c] = -X[c]
    // ------------------------------------------------
    {
        int8_t W[4][4] = {{-1,0,0,0},{0,-1,0,0},{0,0,-1,0},{0,0,0,-1}};
        int8_t X[4]    = {1, 2, 3, 4};
        reset_array(); load_w(W); run(X, got); golden(W, X, exp);
        check("T4: Negative weights (-I)", got, exp);
    }

    // ------------------------------------------------
    // T5: Negative activations — W = I, X = [-1,-2,-3,-4]
    // ------------------------------------------------
    {
        int8_t W[4][4] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
        int8_t X[4]    = {-1, -2, -3, -4};
        reset_array(); load_w(W); run(X, got); golden(W, X, exp);
        check("T5: Negative activations", got, exp);
    }

    // ------------------------------------------------
    // T6: Arbitrary W and X — golden reference validates
    // W = [[1,2,3,4],[5,6,7,8],[1,1,1,1],[2,3,4,5]]
    // X = [1,2,3,4]
    // Expected: [22, 29, 36, 43]
    // ------------------------------------------------
    {
        int8_t W[4][4] = {{1,2,3,4},{5,6,7,8},{1,1,1,1},{2,3,4,5}};
        int8_t X[4]    = {1, 2, 3, 4};
        reset_array(); load_w(W); run(X, got); golden(W, X, exp);
        check("T6: Arbitrary W×X", got, exp);
    }

    // ------------------------------------------------
    // T7: Clock gating — pipeline freezes during gate,
    // output_valid must not fire, results correct after re-enable
    // ------------------------------------------------
    {
        int8_t W[4][4] = {{2,0,0,0},{0,2,0,0},{0,0,2,0},{0,0,0,2}};
        int8_t X[4]    = {3, 3, 3, 3};
        reset_array(); load_w(W);

        // Gate for 10 cycles — counter must not advance
        dut->clk_en = 0;
        for (int i = 0; i < 10; i++) tick();
        if (!dut->output_valid) {
            std::cout << "[PASS] T7a: output_valid held low during gate\n"; pass_count++;
        } else {
            std::cerr << "[FAIL] T7a: output_valid spuriously asserted\n"; fail_count++;
        }

        // Re-enable and run — results must still be correct
        run(X, got); golden(W, X, exp);
        check("T7b: Correct result after gate/re-enable", got, exp);
    }

    // ------------------------------------------------
    std::cout << "================================\n"
              << pass_count << " PASSED | " << fail_count << " FAILED\n"
              << "================================\n";

    delete dut; delete ctx;
    return fail_count ? 1 : 0;
}

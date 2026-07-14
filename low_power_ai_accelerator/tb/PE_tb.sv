// ============================================================
// pe_tb.sv — Testbench for INT8 Processing Element
//
// Test coverage:
//   1.  Reset — all outputs cleared
//   2.  Basic positive MAC
//   3.  Partial sum accumulation
//   4.  Signed — negative weight
//   5.  Signed — negative activation
//   6.  Signed — both negative
//   7.  Clock gating — outputs hold when clk_en=0
//   8.  Multi-cycle accumulation (column simulation)
//   9.  Maximum positive values — no 32-bit overflow
// ============================================================
`timescale 1ns/1ps

module pe_tb;

    // --------------------------------------------------------
    // DUT signals
    // --------------------------------------------------------
    logic        clk;
    logic        rst_n;
    logic        clk_en;
    logic        load_weight;
    logic signed [7:0]  weight_in;
    logic signed [7:0]  act_in;
    logic signed [31:0] psum_in;
    logic signed [7:0]  act_out;
    logic signed [31:0] psum_out;

    // --------------------------------------------------------
    // DUT instantiation
    // --------------------------------------------------------
    pe dut (
        .clk         (clk),
        .rst_n       (rst_n),
        .clk_en      (clk_en),
        .load_weight (load_weight),
        .weight_in   (weight_in),
        .act_in      (act_in),
        .psum_in     (psum_in),
        .act_out     (act_out),
        .psum_out    (psum_out)
    );

    // --------------------------------------------------------
    // Clock: 10ns period (100 MHz)
    // --------------------------------------------------------
    initial clk = 1'b0;
    always  #5 clk = ~clk;

    // --------------------------------------------------------
    // Waveform dump
    // --------------------------------------------------------
    initial begin
        $dumpfile("pe_tb.vcd");
        $dumpvars(0, pe_tb);
    end

    // --------------------------------------------------------
    // Test counters
    // --------------------------------------------------------
    int pass_count = 0;
    int fail_count = 0;

    // --------------------------------------------------------
    // Task: apply reset and clear all inputs
    // --------------------------------------------------------
    task automatic apply_reset();
        rst_n       = 1'b0;
        clk_en      = 1'b0;
        load_weight = 1'b0;
        weight_in   = 8'sh0;
        act_in      = 8'sh0;
        psum_in     = 32'sh0;
        repeat(2) @(posedge clk);
        #1 rst_n = 1'b1;
        @(posedge clk); #1;
    endtask

    // --------------------------------------------------------
    // Task: load weight into PE weight register
    // --------------------------------------------------------
    task automatic load_w(input logic signed [7:0] w);
        load_weight = 1'b1;
        weight_in   = w;
        @(posedge clk); #1;
        load_weight = 1'b0;
    endtask

    // --------------------------------------------------------
    // Task: drive one cycle of inputs and check outputs
    // #1 delay after clock edge lets non-blocking assignments settle
    // --------------------------------------------------------
    task automatic check_pe(
        input string           test_name,
        input logic signed [7:0]  a_in,
        input logic signed [31:0] ps_in,
        input logic signed [7:0]  exp_act,
        input logic signed [31:0] exp_psum
    );
        act_in  = a_in;
        psum_in = ps_in;
        clk_en  = 1'b1;
        @(posedge clk); #1;

        if (act_out === exp_act && psum_out === exp_psum) begin
            $display("[PASS] %s", test_name);
            pass_count++;
        end else begin
            $error("[FAIL] %s | act_out=%0d (exp %0d) | psum_out=%0d (exp %0d)",
                   test_name, act_out, exp_act, psum_out, exp_psum);
            fail_count++;
        end
    endtask

    // --------------------------------------------------------
    // Main test sequence
    // --------------------------------------------------------
    initial begin
        $display("================================================");
        $display("  pe_tb — INT8 Processing Element Testbench");
        $display("================================================");

        // ----------------------------------------------------
        // Test 1: Reset
        // All outputs must be zero immediately after de-assert
        // ----------------------------------------------------
        apply_reset();
        if (act_out === 8'sh0 && psum_out === 32'sh0) begin
            $display("[PASS] T1: Reset — outputs cleared");
            pass_count++;
        end else begin
            $error("[FAIL] T1: Reset | act_out=%0d psum_out=%0d", act_out, psum_out);
            fail_count++;
        end

        // ----------------------------------------------------
        // Test 2: Basic positive MAC
        // weight=3, act=4, psum_in=0
        // Expected: psum_out = 0 + 3×4 = 12,  act_out = 4
        // ----------------------------------------------------
        load_w(8'sd3);
        check_pe("T2: Basic MAC (w=3, a=4, ps=0)",
                  8'sd4, 32'sd0, 8'sd4, 32'sd12);

        // ----------------------------------------------------
        // Test 3: Partial sum accumulation
        // weight=3 (held), act=4, psum_in=20
        // Expected: psum_out = 20 + 12 = 32,  act_out = 4
        // ----------------------------------------------------
        check_pe("T3: Partial sum (w=3, a=4, ps=20)",
                  8'sd4, 32'sd20, 8'sd4, 32'sd32);

        // ----------------------------------------------------
        // Test 4: Signed — negative weight
        // weight=-5, act=6, psum_in=0
        // Expected: psum_out = -30,  act_out = 6
        // ----------------------------------------------------
        load_w(-8'sd5);
        check_pe("T4: Neg weight (w=-5, a=6, ps=0)",
                  8'sd6, 32'sd0, 8'sd6, -32'sd30);

        // ----------------------------------------------------
        // Test 5: Signed — negative activation
        // weight=4, act=-7, psum_in=0
        // Expected: psum_out = -28,  act_out = -7
        // ----------------------------------------------------
        load_w(8'sd4);
        check_pe("T5: Neg activation (w=4, a=-7, ps=0)",
                 -8'sd7, 32'sd0, -8'sd7, -32'sd28);

        // ----------------------------------------------------
        // Test 6: Both negative
        // weight=-3, act=-8, psum_in=0
        // Expected: psum_out = 24,  act_out = -8
        // ----------------------------------------------------
        load_w(-8'sd3);
        check_pe("T6: Both neg (w=-3, a=-8, ps=0)",
                 -8'sd8, 32'sd0, -8'sd8, 32'sd24);

        // ----------------------------------------------------
        // Test 7: Clock gating
        // Establish known state, then deassert clk_en and change
        // inputs — act_out and psum_out must hold their values
        // weight=2, act=10, psum_in=0 → psum_out=20, act_out=10
        // ----------------------------------------------------
        load_w(8'sd2);
        check_pe("T7a: Pre-gate state (w=2, a=10, ps=0)",
                  8'sd10, 32'sd0, 8'sd10, 32'sd20);

        clk_en  = 1'b0;             // Gate the PE
        act_in  = 8'sd77;           // Change inputs — should be ignored
        psum_in = 32'sd999;
        repeat(2) @(posedge clk); #1;

        if (act_out === 8'sd10 && psum_out === 32'sd20) begin
            $display("[PASS] T7b: Clock gating — outputs held");
            pass_count++;
        end else begin
            $error("[FAIL] T7b: Clock gating | act_out=%0d (exp 10) psum_out=%0d (exp 20)",
                   act_out, psum_out);
            fail_count++;
        end

        // ----------------------------------------------------
        // Test 8: Multi-cycle accumulation (column simulation)
        // Simulates 4 PEs in a column each adding weight×activation
        // weight=2, activations = {1, 2, 3, 4}
        // Cycle 1: ps=0  + 2×1 = 2
        // Cycle 2: ps=2  + 2×2 = 6
        // Cycle 3: ps=6  + 2×3 = 12
        // Cycle 4: ps=12 + 2×4 = 20  ← expected final
        // ----------------------------------------------------
        begin
            logic signed [31:0] running_psum;
            logic signed [7:0]  acts [0:3];
            int i;

            apply_reset();
            load_w(8'sd2);
            clk_en       = 1'b1;
            running_psum = 32'sd0;
            acts[0] = 8'sd1;
            acts[1] = 8'sd2;
            acts[2] = 8'sd3;
            acts[3] = 8'sd4;

            for (i = 0; i < 4; i++) begin
                act_in  = acts[i];
                psum_in = running_psum;
                @(posedge clk); #1;
                running_psum = psum_out;
            end

            if (running_psum === 32'sd20) begin
                $display("[PASS] T8: Column accumulation — final psum=%0d", running_psum);
                pass_count++;
            end else begin
                $error("[FAIL] T8: Column accumulation | psum=%0d (exp 20)", running_psum);
                fail_count++;
            end
        end

        // ----------------------------------------------------
        // Test 9: Maximum positive values — no 32-bit overflow
        // weight=127, act=127, psum_in=0
        // 127×127 = 16129 — well within 32-bit signed range
        // Expected: psum_out = 16129,  act_out = 127
        // ----------------------------------------------------
        apply_reset();
        load_w(8'sd127);
        check_pe("T9: Max values (w=127, a=127, ps=0)",
                  8'sd127, 32'sd0, 8'sd127, 32'sd16129);

        // ----------------------------------------------------
        // Summary
        // ----------------------------------------------------
        $display("================================================");
        $display("  Results: %0d PASSED  |  %0d FAILED",
                  pass_count, fail_count);
        $display("================================================");
        if (fail_count == 0)
            $display("  ALL TESTS PASSED");
        else
            $display("  FAILURES DETECTED — review errors above");
        $display("================================================");

        $finish;
    end

    // --------------------------------------------------------
    // Timeout watchdog — fails simulation if hung
    // --------------------------------------------------------
    initial begin
        #50000;
        $error("WATCHDOG: simulation timed out");
        $finish;
    end

endmodule

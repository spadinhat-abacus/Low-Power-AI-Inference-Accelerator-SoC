#!/bin/bash
# ============================================================
# run_regress.sh — Low Power AI Accelerator Regression
#
# Compiles and runs all unit and integration tests.
# Returns exit code 0 if all pass, 1 if any fail.
#
# Usage:
#   chmod +x scripts/run_regress.sh
#   ./scripts/run_regress.sh
# ============================================================

PASS=0
FAIL=0
ERRORS=()

# Clean stale Verilator build artifacts before each run
rm -rf obj_dir

# Colours
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

run_test() {
    local name="$1"
    local compile_cmd="$2"
    local run_cmd="$3"

    echo "--------------------------------------------"
    echo "Running: $name"

    # Compile
    eval "$compile_cmd" > /dev/null 2>&1
    if [ $? -ne 0 ]; then
        echo -e "${RED}[FAIL]${NC} $name — compile error"
        ERRORS+=("$name: compile error")
        FAIL=$((FAIL + 1))
        return
    fi

    # Run
    output=$(eval "$run_cmd" 2>&1)
    exit_code=$?

    echo "$output"

    if [ $exit_code -eq 0 ]; then
        echo -e "${GREEN}[PASS]${NC} $name"
        PASS=$((PASS + 1))
    else
        echo -e "${RED}[FAIL]${NC} $name"
        ERRORS+=("$name: test failure")
        FAIL=$((FAIL + 1))
    fi
}

# ============================================================
# T1 — PE unit tests
# ============================================================
run_test "PE unit tests" \
    "verilator --cc rtl/PE.sv --exe tb/sim_main.cpp -o pe_sim" \
    "make -C obj_dir -f VPE.mk > /dev/null 2>&1 && ./obj_dir/pe_sim"

# ============================================================
# T2 — Systolic array integration tests
# ============================================================
run_test "Systolic array integration" \
    "verilator --top-module systolic_array --cc rtl/PE.sv rtl/systolic_array.sv --exe tb/sim_main_array.cpp" \
    "make -C obj_dir -f Vsystolic_array.mk > /dev/null 2>&1 && ./obj_dir/Vsystolic_array"

# ============================================================
# T3 — Async FIFO unit tests
# ============================================================
run_test "Async FIFO unit tests" \
    "verilator --cc rtl/async_fifo.sv --exe tb/sim_main_fifo.cpp" \
    "make -C obj_dir -f Vasync_fifo.mk > /dev/null 2>&1 && ./obj_dir/Vasync_fifo"

# ============================================================
# T4 — Power control FSM unit tests
# ============================================================
run_test "Power control FSM unit tests" \
    "verilator --cc rtl/power_ctrl_fsm.sv --exe tb/sim_main_fsm.cpp" \
    "make -C obj_dir -f Vpower_ctrl_fsm.mk > /dev/null 2>&1 && ./obj_dir/Vpower_ctrl_fsm"

# ============================================================
# Summary
# ============================================================
echo "============================================"
echo "  Regression Summary"
echo "============================================"
echo -e "  ${GREEN}PASSED: $PASS${NC}"
if [ $FAIL -gt 0 ]; then
    echo -e "  ${RED}FAILED: $FAIL${NC}"
    for err in "${ERRORS[@]}"; do
        echo -e "  ${RED}  ✗ $err${NC}"
    done
    echo "============================================"
    exit 1
else
    echo "  FAILED: 0"
    echo -e "  ${GREEN}ALL TESTS PASSED${NC}"
    echo "============================================"
    exit 0
fi

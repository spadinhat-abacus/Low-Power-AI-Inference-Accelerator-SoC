# Low-Power-AI-Inference-Accelerator-SoC

A dual-clock-domain INT8 systolic array accelerator implemented in 
SystemVerilog, targeting performance-per-watt optimization for neural 
network inference workloads.

## Architecture Overview
- 4×4 INT8 systolic array for matrix multiply operations
- DVFS-style frequency scaling with 3 operating points (200/400/800MHz)
- Glitch-free clock transition FSM
- CDC infrastructure with async FIFOs and two-flop synchronizers
- VCD-based switching activity analysis for power estimation

## Tools
- Simulation: Verilator
- Verification: cocotb, SVA assertions
- Power Analysis: VCD toggle analysis, Python/Pandas
- Synthesis: Yosys

## Results


## Project Structure


## How to Run


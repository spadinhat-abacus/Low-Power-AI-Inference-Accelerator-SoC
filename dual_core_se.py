from m5.objects import *
import m5

# -------------------------
# System
# -------------------------
system = System()
system.clk_domain = SrcClockDomain()
system.clk_domain.clock = '1GHz'
system.clk_domain.voltage_domain = VoltageDomain()

system.mem_mode = 'timing'
system.mem_ranges = [AddrRange('512MB')]

# -------------------------
# RTL Dual-Core System
# -------------------------
system.rtl = DualCoreRTL(
    clock_period = 1,      # 1 tick per cycle -> sync with gem5 clock
    debug = False
)

# -------------------------
# Memory hierarchy
# -------------------------
system.membus = SystemXBar()

# RTL memory interface connection:
# RTL → Master generates mem requests → connect to membus slave
system.rtl.master = system.membus.slave

# gem5 memory → RTL response returns through slave port
system.rtl.slave = system.membus.master

# DDR3 Controller
system.mem_ctrl = MemCtrl()
system.mem_ctrl.dram = DDR3_1600_8x8()
system.mem_ctrl.dram.range = system.mem_ranges[0]
system.mem_ctrl.port = system.membus.master

# System port
system.system_port = system.membus.slave

# -------------------------
# Instantiate + Sim
# -------------------------
root = Root(full_system=False, system=system)

m5.instantiate()
print("===== Starting gem5–Verilated dual-core RTL simulation =====")
exit_event = m5.simulate()
print(f"Exited @ tick {m5.curTick()} because {exit_event.getCause()}")


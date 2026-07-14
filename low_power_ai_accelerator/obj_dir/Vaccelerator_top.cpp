// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vaccelerator_top__pch.h"

//============================================================
// Constructors

Vaccelerator_top::Vaccelerator_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vaccelerator_top__Syms(contextp(), _vcname__, this)}
    , ctrl_clk{vlSymsp->TOP.ctrl_clk}
    , comp_clk{vlSymsp->TOP.comp_clk}
    , ctrl_rst_n{vlSymsp->TOP.ctrl_rst_n}
    , comp_rst_n{vlSymsp->TOP.comp_rst_n}
    , load_weight{vlSymsp->TOP.load_weight}
    , act_wen{vlSymsp->TOP.act_wen}
    , act_wfull{vlSymsp->TOP.act_wfull}
    , result_ren{vlSymsp->TOP.result_ren}
    , result_rempty{vlSymsp->TOP.result_rempty}
    , start{vlSymsp->TOP.start}
    , powerdown_req{vlSymsp->TOP.powerdown_req}
    , wakeup{vlSymsp->TOP.wakeup}
    , clk_en_out{vlSymsp->TOP.clk_en_out}
    , iso_en{vlSymsp->TOP.iso_en}
    , power_down{vlSymsp->TOP.power_down}
    , dbg_state{vlSymsp->TOP.dbg_state}
    , dbg_snapcnt{vlSymsp->TOP.dbg_snapcnt}
    , dbg_snapwait{vlSymsp->TOP.dbg_snapwait}
    , act_wdata{vlSymsp->TOP.act_wdata}
    , result_rdata{vlSymsp->TOP.result_rdata}
    , weights{vlSymsp->TOP.weights}
    , dbg_snap{vlSymsp->TOP.dbg_snap}
    , dbg_psum{vlSymsp->TOP.dbg_psum}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vaccelerator_top::Vaccelerator_top(const char* _vcname__)
    : Vaccelerator_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vaccelerator_top::~Vaccelerator_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vaccelerator_top___024root___eval_debug_assertions(Vaccelerator_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vaccelerator_top___024root___eval_static(Vaccelerator_top___024root* vlSelf);
void Vaccelerator_top___024root___eval_initial(Vaccelerator_top___024root* vlSelf);
void Vaccelerator_top___024root___eval_settle(Vaccelerator_top___024root* vlSelf);
void Vaccelerator_top___024root___eval(Vaccelerator_top___024root* vlSelf);

void Vaccelerator_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vaccelerator_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vaccelerator_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vaccelerator_top___024root___eval_static(&(vlSymsp->TOP));
        Vaccelerator_top___024root___eval_initial(&(vlSymsp->TOP));
        Vaccelerator_top___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vaccelerator_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vaccelerator_top::eventsPending() { return false; }

uint64_t Vaccelerator_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vaccelerator_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vaccelerator_top___024root___eval_final(Vaccelerator_top___024root* vlSelf);

VL_ATTR_COLD void Vaccelerator_top::final() {
    Vaccelerator_top___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vaccelerator_top::hierName() const { return vlSymsp->name(); }
const char* Vaccelerator_top::modelName() const { return "Vaccelerator_top"; }
unsigned Vaccelerator_top::threads() const { return 1; }
void Vaccelerator_top::prepareClone() const { contextp()->prepareClone(); }
void Vaccelerator_top::atClone() const {
    contextp()->threadPoolpOnClone();
}

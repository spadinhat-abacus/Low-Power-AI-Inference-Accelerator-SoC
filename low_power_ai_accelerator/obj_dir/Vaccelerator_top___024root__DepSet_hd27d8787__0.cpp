// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaccelerator_top.h for the primary calling header

#include "Vaccelerator_top__pch.h"
#include "Vaccelerator_top__Syms.h"
#include "Vaccelerator_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaccelerator_top___024root___dump_triggers__ico(Vaccelerator_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vaccelerator_top___024root___eval_triggers__ico(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___eval_triggers__ico\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vaccelerator_top___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaccelerator_top___024root___dump_triggers__act(Vaccelerator_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vaccelerator_top___024root___eval_triggers__act(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___eval_triggers__act\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.comp_clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__comp_clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((~ (IData)(vlSelfRef.comp_rst_n)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__comp_rst_n__0)));
    vlSelfRef.__VactTriggered.setBit(2U, ((IData)(vlSelfRef.ctrl_clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ctrl_clk__0))));
    vlSelfRef.__VactTriggered.setBit(3U, ((~ (IData)(vlSelfRef.ctrl_rst_n)) 
                                          & (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ctrl_rst_n__0)));
    vlSelfRef.__Vtrigprevexpr___TOP__comp_clk__0 = vlSelfRef.comp_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__comp_rst_n__0 
        = vlSelfRef.comp_rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__ctrl_clk__0 = vlSelfRef.ctrl_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__ctrl_rst_n__0 
        = vlSelfRef.ctrl_rst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vaccelerator_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}

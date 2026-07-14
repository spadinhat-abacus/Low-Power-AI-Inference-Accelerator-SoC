// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaccelerator_top.h for the primary calling header

#include "Vaccelerator_top__pch.h"
#include "Vaccelerator_top___024root.h"

VL_ATTR_COLD void Vaccelerator_top___024root___eval_static(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___eval_static\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__comp_clk__0 = vlSelfRef.comp_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__comp_rst_n__0 
        = vlSelfRef.comp_rst_n;
    vlSelfRef.__Vtrigprevexpr___TOP__ctrl_clk__0 = vlSelfRef.ctrl_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__ctrl_rst_n__0 
        = vlSelfRef.ctrl_rst_n;
}

VL_ATTR_COLD void Vaccelerator_top___024root___eval_initial__TOP(Vaccelerator_top___024root* vlSelf);

VL_ATTR_COLD void Vaccelerator_top___024root___eval_initial(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___eval_initial\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vaccelerator_top___024root___eval_initial__TOP(vlSelf);
}

VL_ATTR_COLD void Vaccelerator_top___024root___eval_initial__TOP(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___eval_initial__TOP\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire[0U][0U] = 0U;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire[0U][1U] = 0U;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire[0U][2U] = 0U;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire[0U][3U] = 0U;
}

VL_ATTR_COLD void Vaccelerator_top___024root___eval_final(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___eval_final\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaccelerator_top___024root___dump_triggers__stl(Vaccelerator_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vaccelerator_top___024root___eval_phase__stl(Vaccelerator_top___024root* vlSelf);

VL_ATTR_COLD void Vaccelerator_top___024root___eval_settle(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___eval_settle\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vaccelerator_top___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("rtl/accelerator_top.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vaccelerator_top___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaccelerator_top___024root___dump_triggers__stl(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___dump_triggers__stl\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vaccelerator_top___024root___stl_sequent__TOP__0(Vaccelerator_top___024root* vlSelf);

VL_ATTR_COLD void Vaccelerator_top___024root___eval_stl(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___eval_stl\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vaccelerator_top___024root___stl_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*1:0*/, 128> Vaccelerator_top__ConstPool__TABLE_he412d8f6_0;

VL_ATTR_COLD void Vaccelerator_top___024root___stl_sequent__TOP__0(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___stl_sequent__TOP__0\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelfRef.clk_en_out = vlSelfRef.accelerator_top__DOT__clk_en;
    vlSelfRef.dbg_state = vlSelfRef.accelerator_top__DOT__comp_state;
    vlSelfRef.dbg_snapcnt = vlSelfRef.accelerator_top__DOT__snap_cnt;
    vlSelfRef.dbg_snapwait = vlSelfRef.accelerator_top__DOT__snap_wait;
    vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__gate_timeout 
        = (0xfU == (IData)(vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__gate_cnt));
    vlSelfRef.accelerator_top__DOT__act_rdata = vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__mem
        [(7U & (IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_bin))];
    vlSelfRef.result_rdata = vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__mem
        [(7U & (IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_bin))];
    vlSelfRef.accelerator_top__DOT__sa_psum_out[0U] 
        = vlSelfRef.accelerator_top__DOT____Vcellout__u_array__psum_out
        [3U];
    vlSelfRef.accelerator_top__DOT__sa_psum_out[1U] 
        = vlSelfRef.accelerator_top__DOT____Vcellout__u_array__psum_out
        [2U];
    vlSelfRef.accelerator_top__DOT__sa_psum_out[2U] 
        = vlSelfRef.accelerator_top__DOT____Vcellout__u_array__psum_out
        [1U];
    vlSelfRef.accelerator_top__DOT__sa_psum_out[3U] 
        = vlSelfRef.accelerator_top__DOT____Vcellout__u_array__psum_out
        [0U];
    vlSelfRef.dbg_psum[0U] = vlSelfRef.accelerator_top__DOT____Vcellout__u_array__psum_out
        [3U];
    vlSelfRef.dbg_psum[1U] = vlSelfRef.accelerator_top__DOT____Vcellout__u_array__psum_out
        [2U];
    vlSelfRef.dbg_psum[2U] = vlSelfRef.accelerator_top__DOT____Vcellout__u_array__psum_out
        [1U];
    vlSelfRef.dbg_psum[3U] = vlSelfRef.accelerator_top__DOT____Vcellout__u_array__psum_out
        [0U];
    vlSelfRef.dbg_snap[0U] = vlSelfRef.accelerator_top__DOT__snap
        [0U];
    vlSelfRef.dbg_snap[1U] = vlSelfRef.accelerator_top__DOT__snap
        [1U];
    vlSelfRef.dbg_snap[2U] = vlSelfRef.accelerator_top__DOT__snap
        [2U];
    vlSelfRef.dbg_snap[3U] = vlSelfRef.accelerator_top__DOT__snap
        [3U];
    vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_gray 
        = (0xfU & ((IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_bin) 
                   ^ VL_SHIFTR_III(4,4,32, (IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_bin), 1U)));
    vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__wptr_gray 
        = (0xfU & ((IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__wptr_bin) 
                   ^ VL_SHIFTR_III(4,4,32, (IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__wptr_bin), 1U)));
    vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__wptr_gray 
        = (0xfU & ((IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__wptr_bin) 
                   ^ VL_SHIFTR_III(4,4,32, (IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__wptr_bin), 1U)));
    vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_gray 
        = (0xfU & ((IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_bin) 
                   ^ VL_SHIFTR_III(4,4,32, (IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_bin), 1U)));
    __Vtableidx1 = (((((IData)(vlSelfRef.accelerator_top__DOT__inference_done_ctrl) 
                       << 6U) | ((IData)(vlSelfRef.powerdown_req) 
                                 << 5U)) | (((0xfU 
                                              == (IData)(vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__gate_cnt)) 
                                             << 4U) 
                                            | ((IData)(vlSelfRef.start) 
                                               << 3U))) 
                    | (((IData)(vlSelfRef.wakeup) << 2U) 
                       | (IData)(vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__curr_state)));
    vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__next_state 
        = Vaccelerator_top__ConstPool__TABLE_he412d8f6_0
        [__Vtableidx1];
    vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire[1U][0U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__psum_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire[1U][1U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__psum_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire[1U][2U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__psum_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire[1U][3U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__psum_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire[2U][0U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__psum_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire[2U][1U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__psum_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire[2U][2U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__psum_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire[2U][3U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__psum_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire[3U][0U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__psum_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire[3U][1U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__psum_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire[3U][2U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__psum_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire[3U][3U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__psum_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire[4U][0U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__psum_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire[4U][1U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__psum_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire[4U][2U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__psum_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire[4U][3U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__psum_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire[0U][1U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__act_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire[0U][2U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__act_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire[0U][3U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__act_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire[0U][4U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__act_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire[1U][1U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__act_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire[1U][2U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__act_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire[1U][3U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__act_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire[1U][4U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__act_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire[2U][1U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__act_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire[2U][2U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__act_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire[2U][3U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__act_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire[2U][4U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__act_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire[3U][1U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__act_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire[3U][2U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__act_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire[3U][3U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__act_out;
    vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire[3U][4U] 
        = vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__act_out;
    vlSelfRef.accelerator_top__DOT__sa_act_in[0U] = 
        (((1U == (IData)(vlSelfRef.accelerator_top__DOT__comp_state)) 
          & (0U == (IData)(vlSelfRef.accelerator_top__DOT__feed_cnt)))
          ? vlSelfRef.accelerator_top__DOT__act_lat
         [0U] : 0U);
    vlSelfRef.accelerator_top__DOT__sa_act_in[1U] = 
        (((1U == (IData)(vlSelfRef.accelerator_top__DOT__comp_state)) 
          & (1U == (IData)(vlSelfRef.accelerator_top__DOT__feed_cnt)))
          ? vlSelfRef.accelerator_top__DOT__act_lat
         [1U] : 0U);
    vlSelfRef.accelerator_top__DOT__sa_act_in[2U] = 
        (((1U == (IData)(vlSelfRef.accelerator_top__DOT__comp_state)) 
          & (2U == (IData)(vlSelfRef.accelerator_top__DOT__feed_cnt)))
          ? vlSelfRef.accelerator_top__DOT__act_lat
         [2U] : 0U);
    vlSelfRef.accelerator_top__DOT__sa_act_in[3U] = 
        (((1U == (IData)(vlSelfRef.accelerator_top__DOT__comp_state)) 
          & (3U == (IData)(vlSelfRef.accelerator_top__DOT__feed_cnt)))
          ? vlSelfRef.accelerator_top__DOT__act_lat
         [3U] : 0U);
    vlSelfRef.accelerator_top__DOT__act_rempty = ((IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_gray) 
                                                  == (IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__wptr_sync));
    vlSelfRef.act_wfull = ((IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__wptr_gray) 
                           == ((0xcU & ((~ ((IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_sync) 
                                            >> 2U)) 
                                        << 2U)) | (3U 
                                                   & (IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_sync))));
    vlSelfRef.accelerator_top__DOT__result_wfull = 
        ((IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__wptr_gray) 
         == ((0xcU & ((~ ((IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_sync) 
                          >> 2U)) << 2U)) | (3U & (IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_sync))));
    vlSelfRef.result_rempty = ((IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_gray) 
                               == (IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__wptr_sync));
    vlSelfRef.accelerator_top__DOT____Vcellinp__u_array__act_in[0U] 
        = vlSelfRef.accelerator_top__DOT__sa_act_in
        [3U];
    vlSelfRef.accelerator_top__DOT____Vcellinp__u_array__act_in[1U] 
        = vlSelfRef.accelerator_top__DOT__sa_act_in
        [2U];
    vlSelfRef.accelerator_top__DOT____Vcellinp__u_array__act_in[2U] 
        = vlSelfRef.accelerator_top__DOT__sa_act_in
        [1U];
    vlSelfRef.accelerator_top__DOT____Vcellinp__u_array__act_in[3U] 
        = vlSelfRef.accelerator_top__DOT__sa_act_in
        [0U];
    vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire[0U][0U] 
        = vlSelfRef.accelerator_top__DOT____Vcellinp__u_array__act_in
        [0U];
    vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire[1U][0U] 
        = vlSelfRef.accelerator_top__DOT____Vcellinp__u_array__act_in
        [1U];
    vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire[2U][0U] 
        = vlSelfRef.accelerator_top__DOT____Vcellinp__u_array__act_in
        [2U];
    vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire[3U][0U] 
        = vlSelfRef.accelerator_top__DOT____Vcellinp__u_array__act_in
        [3U];
}

VL_ATTR_COLD void Vaccelerator_top___024root___eval_triggers__stl(Vaccelerator_top___024root* vlSelf);

VL_ATTR_COLD bool Vaccelerator_top___024root___eval_phase__stl(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___eval_phase__stl\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vaccelerator_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vaccelerator_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaccelerator_top___024root___dump_triggers__ico(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___dump_triggers__ico\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaccelerator_top___024root___dump_triggers__act(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___dump_triggers__act\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge comp_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge comp_rst_n)\n");
    }
    if ((4ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge ctrl_clk)\n");
    }
    if ((8ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(negedge ctrl_rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaccelerator_top___024root___dump_triggers__nba(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___dump_triggers__nba\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge comp_clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge comp_rst_n)\n");
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge ctrl_clk)\n");
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(negedge ctrl_rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vaccelerator_top___024root___ctor_var_reset(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___ctor_var_reset\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->ctrl_clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7227096419631241342ull);
    vlSelf->comp_clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6357776256472998310ull);
    vlSelf->ctrl_rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15546594360624516262ull);
    vlSelf->comp_rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12327344082713245583ull);
    vlSelf->load_weight = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1420195517439409484ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->weights[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15258019614976312503ull);
        }
    }
    vlSelf->act_wen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1044185296317403766ull);
    vlSelf->act_wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2011516594707436859ull);
    vlSelf->act_wfull = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 810939589679988486ull);
    vlSelf->result_ren = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12985284564774992598ull);
    vlSelf->result_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11590306821195781477ull);
    vlSelf->result_rempty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14664727070182069424ull);
    vlSelf->start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9867861323841650631ull);
    vlSelf->powerdown_req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15541070572735427958ull);
    vlSelf->wakeup = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10646407662617503039ull);
    vlSelf->clk_en_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4137661879172781582ull);
    vlSelf->iso_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7799471059571910219ull);
    vlSelf->power_down = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6917626189501808786ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->dbg_snap[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6317025243192241618ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->dbg_psum[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13380159354186326894ull);
    }
    vlSelf->dbg_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9035414299298431771ull);
    vlSelf->dbg_snapcnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6469883902324171040ull);
    vlSelf->dbg_snapwait = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1410214415079936910ull);
    vlSelf->accelerator_top__DOT__clk_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13471653841686171795ull);
    vlSelf->accelerator_top__DOT__clk_en_s1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2962662854790377230ull);
    vlSelf->accelerator_top__DOT__clk_en_comp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8527914848961943794ull);
    vlSelf->accelerator_top__DOT__lw_s1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4965538155540800137ull);
    vlSelf->accelerator_top__DOT__lw_comp = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16523534932003846654ull);
    vlSelf->accelerator_top__DOT__inf_done_s1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10501073835360650305ull);
    vlSelf->accelerator_top__DOT__inference_done_ctrl = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2018722151090770385ull);
    vlSelf->accelerator_top__DOT__act_rempty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8706479735320523858ull);
    vlSelf->accelerator_top__DOT__act_rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 5657775583456747241ull);
    vlSelf->accelerator_top__DOT__result_wfull = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16366923085760312315ull);
    vlSelf->accelerator_top__DOT__result_wen_r = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17390309626864929727ull);
    vlSelf->accelerator_top__DOT__result_wdata_r = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9522747635557932829ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->accelerator_top__DOT__sa_act_in[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16300553022712952207ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->accelerator_top__DOT__sa_psum_out[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13501264005523698683ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->accelerator_top__DOT____Vcellout__u_array__psum_out[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7972520628314840082ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->accelerator_top__DOT____Vcellinp__u_array__act_in[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9892973549731164399ull);
    }
    vlSelf->accelerator_top__DOT__comp_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 7748046267019581667ull);
    vlSelf->accelerator_top__DOT__feed_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11543271184654235463ull);
    vlSelf->accelerator_top__DOT__snap_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11954026716918392295ull);
    vlSelf->accelerator_top__DOT__drain_cnt = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8463512646240485748ull);
    vlSelf->accelerator_top__DOT__snap_wait = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6240964842245807776ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->accelerator_top__DOT__act_lat[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13501810792727678567ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->accelerator_top__DOT__snap[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7967687063814716817ull);
    }
    vlSelf->accelerator_top__DOT__inference_done_reg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1562682829332730573ull);
    vlSelf->accelerator_top__DOT__u_power_fsm__DOT__curr_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12425754102866142877ull);
    vlSelf->accelerator_top__DOT__u_power_fsm__DOT__next_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 6330269401530507569ull);
    vlSelf->accelerator_top__DOT__u_power_fsm__DOT__gate_cnt = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1497419795373518977ull);
    vlSelf->accelerator_top__DOT__u_power_fsm__DOT__gate_timeout = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17392515027659875140ull);
    vlSelf->accelerator_top__DOT__u_power_fsm__DOT__iso_pending = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12025228647353791090ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->accelerator_top__DOT__u_act_fifo__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1258130144562532902ull);
    }
    vlSelf->accelerator_top__DOT__u_act_fifo__DOT__wptr_bin = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18063161642523973369ull);
    vlSelf->accelerator_top__DOT__u_act_fifo__DOT__wptr_gray = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15313102622921224958ull);
    vlSelf->accelerator_top__DOT__u_act_fifo__DOT__rptr_bin = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9116111851669796792ull);
    vlSelf->accelerator_top__DOT__u_act_fifo__DOT__rptr_gray = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3102112667713648686ull);
    vlSelf->accelerator_top__DOT__u_act_fifo__DOT__wptr_sync1 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6034707051555914536ull);
    vlSelf->accelerator_top__DOT__u_act_fifo__DOT__wptr_sync = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6155280159337717344ull);
    vlSelf->accelerator_top__DOT__u_act_fifo__DOT__rptr_sync1 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8444008120867499984ull);
    vlSelf->accelerator_top__DOT__u_act_fifo__DOT__rptr_sync = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 8899509442328995223ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->accelerator_top__DOT__u_result_fifo__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2812096847064060336ull);
    }
    vlSelf->accelerator_top__DOT__u_result_fifo__DOT__wptr_bin = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3870201384636095262ull);
    vlSelf->accelerator_top__DOT__u_result_fifo__DOT__wptr_gray = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3498640512202277424ull);
    vlSelf->accelerator_top__DOT__u_result_fifo__DOT__rptr_bin = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17221938041740184921ull);
    vlSelf->accelerator_top__DOT__u_result_fifo__DOT__rptr_gray = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7723018712202224623ull);
    vlSelf->accelerator_top__DOT__u_result_fifo__DOT__wptr_sync1 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 830992742843211877ull);
    vlSelf->accelerator_top__DOT__u_result_fifo__DOT__wptr_sync = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3555130201983253060ull);
    vlSelf->accelerator_top__DOT__u_result_fifo__DOT__rptr_sync1 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 576799619028746855ull);
    vlSelf->accelerator_top__DOT__u_result_fifo__DOT__rptr_sync = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13466671407731040011ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 5; ++__Vi1) {
            vlSelf->accelerator_top__DOT__u_array__DOT__act_wire[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11257580509756091752ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->accelerator_top__DOT__u_array__DOT__psum_wire[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7330769447910874060ull);
        }
    }
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__psum_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9322490169215994682ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__act_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10657223628359254014ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__psum_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12755393875056166398ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__act_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 12490682823776749090ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__psum_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12733682298071212173ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__act_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3065519536810796104ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__psum_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1675864049185215642ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__act_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1489089439436538335ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__psum_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2440768662073390533ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__act_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11157379195372099628ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__psum_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 2026500480702023930ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__act_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 112330313039446795ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__psum_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1371146509702111500ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__act_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 347111804872056400ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__psum_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16980340492298152323ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__act_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11689465242400406013ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__psum_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6834011796351636617ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__act_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 13935507911031708302ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__psum_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12088851930401401430ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__act_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9845166120370294599ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__psum_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1895146166436752912ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__act_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 6374838986775938890ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__psum_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 6477218498634986364ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__act_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 574402789057912737ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__psum_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16912555938551887303ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__act_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17451351960146940378ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__psum_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 177374894869020361ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__act_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 18117205646383339514ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__psum_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15298573682695797813ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__act_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14594407365062095302ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__psum_out = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 16087119317126222042ull);
    vlSelf->accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__act_out = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10679287664462219696ull);
    vlSelf->accelerator_top__DOT__u_array__DOT__row_g__BRA__0__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__DOT__weight_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 15163179023069320259ull);
    vlSelf->accelerator_top__DOT__u_array__DOT__row_g__BRA__0__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__DOT__weight_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 7589652198913381390ull);
    vlSelf->accelerator_top__DOT__u_array__DOT__row_g__BRA__0__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__DOT__weight_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 764496497624958643ull);
    vlSelf->accelerator_top__DOT__u_array__DOT__row_g__BRA__0__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__DOT__weight_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2130391557208626375ull);
    vlSelf->accelerator_top__DOT__u_array__DOT__row_g__BRA__1__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__DOT__weight_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11308874687231787061ull);
    vlSelf->accelerator_top__DOT__u_array__DOT__row_g__BRA__1__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__DOT__weight_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17221872352707922812ull);
    vlSelf->accelerator_top__DOT__u_array__DOT__row_g__BRA__1__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__DOT__weight_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 3765876234034490315ull);
    vlSelf->accelerator_top__DOT__u_array__DOT__row_g__BRA__1__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__DOT__weight_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 2035714618414202599ull);
    vlSelf->accelerator_top__DOT__u_array__DOT__row_g__BRA__2__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__DOT__weight_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9951146110556139316ull);
    vlSelf->accelerator_top__DOT__u_array__DOT__row_g__BRA__2__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__DOT__weight_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4687431931594130836ull);
    vlSelf->accelerator_top__DOT__u_array__DOT__row_g__BRA__2__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__DOT__weight_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9144454910469868845ull);
    vlSelf->accelerator_top__DOT__u_array__DOT__row_g__BRA__2__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__DOT__weight_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 16185066903693647056ull);
    vlSelf->accelerator_top__DOT__u_array__DOT__row_g__BRA__3__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__DOT__weight_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4259896660690875483ull);
    vlSelf->accelerator_top__DOT__u_array__DOT__row_g__BRA__3__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__DOT__weight_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4248439929235812263ull);
    vlSelf->accelerator_top__DOT__u_array__DOT__row_g__BRA__3__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__DOT__weight_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17928594378873666163ull);
    vlSelf->accelerator_top__DOT__u_array__DOT__row_g__BRA__3__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__DOT__weight_reg = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17829977229065621627ull);
    vlSelf->__Vtrigprevexpr___TOP__comp_clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7303915417814428436ull);
    vlSelf->__Vtrigprevexpr___TOP__comp_rst_n__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11591250971252565686ull);
    vlSelf->__Vtrigprevexpr___TOP__ctrl_clk__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11524541157549111021ull);
    vlSelf->__Vtrigprevexpr___TOP__ctrl_rst_n__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3422226326347275082ull);
}

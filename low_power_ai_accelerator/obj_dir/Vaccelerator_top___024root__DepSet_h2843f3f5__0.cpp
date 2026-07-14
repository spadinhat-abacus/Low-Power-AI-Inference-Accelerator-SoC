// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vaccelerator_top.h for the primary calling header

#include "Vaccelerator_top__pch.h"
#include "Vaccelerator_top___024root.h"

void Vaccelerator_top___024root___ico_sequent__TOP__0(Vaccelerator_top___024root* vlSelf);

void Vaccelerator_top___024root___eval_ico(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___eval_ico\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vaccelerator_top___024root___ico_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*1:0*/, 128> Vaccelerator_top__ConstPool__TABLE_he412d8f6_0;

VL_INLINE_OPT void Vaccelerator_top___024root___ico_sequent__TOP__0(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___ico_sequent__TOP__0\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
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
}

void Vaccelerator_top___024root___eval_triggers__ico(Vaccelerator_top___024root* vlSelf);

bool Vaccelerator_top___024root___eval_phase__ico(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___eval_phase__ico\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vaccelerator_top___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vaccelerator_top___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vaccelerator_top___024root___eval_act(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___eval_act\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vaccelerator_top___024root___nba_sequent__TOP__0(Vaccelerator_top___024root* vlSelf);
void Vaccelerator_top___024root___nba_sequent__TOP__1(Vaccelerator_top___024root* vlSelf);
void Vaccelerator_top___024root___nba_comb__TOP__0(Vaccelerator_top___024root* vlSelf);
void Vaccelerator_top___024root___nba_sequent__TOP__2(Vaccelerator_top___024root* vlSelf);

void Vaccelerator_top___024root___eval_nba(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___eval_nba\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((0xcULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaccelerator_top___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaccelerator_top___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((0xfULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaccelerator_top___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((0xcULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vaccelerator_top___024root___nba_sequent__TOP__2(vlSelf);
    }
}

VL_INLINE_OPT void Vaccelerator_top___024root___nba_sequent__TOP__0(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___nba_sequent__TOP__0\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VdlyVal__accelerator_top__DOT__u_act_fifo__DOT__mem__v0;
    __VdlyVal__accelerator_top__DOT__u_act_fifo__DOT__mem__v0 = 0;
    CData/*2:0*/ __VdlyDim0__accelerator_top__DOT__u_act_fifo__DOT__mem__v0;
    __VdlyDim0__accelerator_top__DOT__u_act_fifo__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__accelerator_top__DOT__u_act_fifo__DOT__mem__v0;
    __VdlySet__accelerator_top__DOT__u_act_fifo__DOT__mem__v0 = 0;
    // Body
    __VdlySet__accelerator_top__DOT__u_act_fifo__DOT__mem__v0 = 0U;
    if (vlSelfRef.ctrl_rst_n) {
        if (((IData)(vlSelfRef.result_ren) & (~ (IData)(vlSelfRef.result_rempty)))) {
            vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_bin 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_bin)));
        }
        if (((IData)(vlSelfRef.act_wen) & (~ (IData)(vlSelfRef.act_wfull)))) {
            __VdlyVal__accelerator_top__DOT__u_act_fifo__DOT__mem__v0 
                = vlSelfRef.act_wdata;
            __VdlyDim0__accelerator_top__DOT__u_act_fifo__DOT__mem__v0 
                = (7U & (IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__wptr_bin));
            __VdlySet__accelerator_top__DOT__u_act_fifo__DOT__mem__v0 = 1U;
            vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__wptr_bin 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__wptr_bin)));
        }
        vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__gate_cnt 
            = ((2U == (IData)(vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__curr_state))
                ? (0x1fU & ((IData)(vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__gate_timeout)
                             ? (IData)(vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__gate_cnt)
                             : ((IData)(1U) + (IData)(vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__gate_cnt))))
                : 0U);
        vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_sync 
            = vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_sync1;
        vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__wptr_sync 
            = vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__wptr_sync1;
        vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_sync1 
            = vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_gray;
        vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__wptr_sync1 
            = vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__wptr_gray;
    } else {
        vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_bin = 0U;
        vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__wptr_bin = 0U;
        vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__gate_cnt = 0U;
        vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_sync = 0U;
        vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__wptr_sync = 0U;
        vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_sync1 = 0U;
        vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__wptr_sync1 = 0U;
    }
    vlSelfRef.accelerator_top__DOT__inference_done_ctrl 
        = ((IData)(vlSelfRef.ctrl_rst_n) && (IData)(vlSelfRef.accelerator_top__DOT__inf_done_s1));
    if (__VdlySet__accelerator_top__DOT__u_act_fifo__DOT__mem__v0) {
        vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__mem[__VdlyDim0__accelerator_top__DOT__u_act_fifo__DOT__mem__v0] 
            = __VdlyVal__accelerator_top__DOT__u_act_fifo__DOT__mem__v0;
    }
    vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__gate_timeout 
        = (0xfU == (IData)(vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__gate_cnt));
    vlSelfRef.accelerator_top__DOT__inf_done_s1 = ((IData)(vlSelfRef.ctrl_rst_n) 
                                                   && (IData)(vlSelfRef.accelerator_top__DOT__inference_done_reg));
}

VL_INLINE_OPT void Vaccelerator_top___024root___nba_sequent__TOP__1(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___nba_sequent__TOP__1\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*1:0*/ __Vdly__accelerator_top__DOT__drain_cnt;
    __Vdly__accelerator_top__DOT__drain_cnt = 0;
    CData/*1:0*/ __Vdly__accelerator_top__DOT__comp_state;
    __Vdly__accelerator_top__DOT__comp_state = 0;
    CData/*1:0*/ __Vdly__accelerator_top__DOT__snap_cnt;
    __Vdly__accelerator_top__DOT__snap_cnt = 0;
    CData/*1:0*/ __Vdly__accelerator_top__DOT__feed_cnt;
    __Vdly__accelerator_top__DOT__feed_cnt = 0;
    IData/*31:0*/ __VdlyVal__accelerator_top__DOT__snap__v0;
    __VdlyVal__accelerator_top__DOT__snap__v0 = 0;
    CData/*1:0*/ __VdlyDim0__accelerator_top__DOT__snap__v0;
    __VdlyDim0__accelerator_top__DOT__snap__v0 = 0;
    CData/*0:0*/ __VdlySet__accelerator_top__DOT__snap__v0;
    __VdlySet__accelerator_top__DOT__snap__v0 = 0;
    CData/*7:0*/ __VdlyVal__accelerator_top__DOT__act_lat__v0;
    __VdlyVal__accelerator_top__DOT__act_lat__v0 = 0;
    CData/*0:0*/ __VdlySet__accelerator_top__DOT__act_lat__v0;
    __VdlySet__accelerator_top__DOT__act_lat__v0 = 0;
    CData/*7:0*/ __VdlyVal__accelerator_top__DOT__act_lat__v1;
    __VdlyVal__accelerator_top__DOT__act_lat__v1 = 0;
    CData/*0:0*/ __VdlySet__accelerator_top__DOT__act_lat__v1;
    __VdlySet__accelerator_top__DOT__act_lat__v1 = 0;
    CData/*7:0*/ __VdlyVal__accelerator_top__DOT__act_lat__v2;
    __VdlyVal__accelerator_top__DOT__act_lat__v2 = 0;
    CData/*7:0*/ __VdlyVal__accelerator_top__DOT__act_lat__v3;
    __VdlyVal__accelerator_top__DOT__act_lat__v3 = 0;
    CData/*0:0*/ __VdlySet__accelerator_top__DOT__act_lat__v4;
    __VdlySet__accelerator_top__DOT__act_lat__v4 = 0;
    IData/*31:0*/ __VdlyVal__accelerator_top__DOT__u_result_fifo__DOT__mem__v0;
    __VdlyVal__accelerator_top__DOT__u_result_fifo__DOT__mem__v0 = 0;
    CData/*2:0*/ __VdlyDim0__accelerator_top__DOT__u_result_fifo__DOT__mem__v0;
    __VdlyDim0__accelerator_top__DOT__u_result_fifo__DOT__mem__v0 = 0;
    CData/*0:0*/ __VdlySet__accelerator_top__DOT__u_result_fifo__DOT__mem__v0;
    __VdlySet__accelerator_top__DOT__u_result_fifo__DOT__mem__v0 = 0;
    IData/*31:0*/ __VdlyVal__accelerator_top__DOT____Vcellout__u_array__psum_out__v0;
    __VdlyVal__accelerator_top__DOT____Vcellout__u_array__psum_out__v0 = 0;
    CData/*0:0*/ __VdlySet__accelerator_top__DOT____Vcellout__u_array__psum_out__v0;
    __VdlySet__accelerator_top__DOT____Vcellout__u_array__psum_out__v0 = 0;
    IData/*31:0*/ __VdlyVal__accelerator_top__DOT____Vcellout__u_array__psum_out__v1;
    __VdlyVal__accelerator_top__DOT____Vcellout__u_array__psum_out__v1 = 0;
    IData/*31:0*/ __VdlyVal__accelerator_top__DOT____Vcellout__u_array__psum_out__v2;
    __VdlyVal__accelerator_top__DOT____Vcellout__u_array__psum_out__v2 = 0;
    IData/*31:0*/ __VdlyVal__accelerator_top__DOT____Vcellout__u_array__psum_out__v3;
    __VdlyVal__accelerator_top__DOT____Vcellout__u_array__psum_out__v3 = 0;
    CData/*0:0*/ __VdlySet__accelerator_top__DOT____Vcellout__u_array__psum_out__v4;
    __VdlySet__accelerator_top__DOT____Vcellout__u_array__psum_out__v4 = 0;
    // Body
    __VdlySet__accelerator_top__DOT____Vcellout__u_array__psum_out__v0 = 0U;
    __VdlySet__accelerator_top__DOT____Vcellout__u_array__psum_out__v4 = 0U;
    __Vdly__accelerator_top__DOT__drain_cnt = vlSelfRef.accelerator_top__DOT__drain_cnt;
    __Vdly__accelerator_top__DOT__snap_cnt = vlSelfRef.accelerator_top__DOT__snap_cnt;
    __VdlySet__accelerator_top__DOT__snap__v0 = 0U;
    __Vdly__accelerator_top__DOT__feed_cnt = vlSelfRef.accelerator_top__DOT__feed_cnt;
    __Vdly__accelerator_top__DOT__comp_state = vlSelfRef.accelerator_top__DOT__comp_state;
    __VdlySet__accelerator_top__DOT__act_lat__v0 = 0U;
    __VdlySet__accelerator_top__DOT__act_lat__v1 = 0U;
    __VdlySet__accelerator_top__DOT__act_lat__v4 = 0U;
    __VdlySet__accelerator_top__DOT__u_result_fifo__DOT__mem__v0 = 0U;
    if (vlSelfRef.comp_rst_n) {
        if ((IData)((((0U == (IData)(vlSelfRef.accelerator_top__DOT__comp_state)) 
                      & (~ (IData)(vlSelfRef.accelerator_top__DOT__act_rempty))) 
                     & (IData)(vlSelfRef.accelerator_top__DOT__clk_en_comp)))) {
            vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_bin 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_bin)));
        }
        if (((IData)(vlSelfRef.accelerator_top__DOT__result_wen_r) 
             & (~ (IData)(vlSelfRef.accelerator_top__DOT__result_wfull)))) {
            __VdlyVal__accelerator_top__DOT__u_result_fifo__DOT__mem__v0 
                = vlSelfRef.accelerator_top__DOT__result_wdata_r;
            __VdlyDim0__accelerator_top__DOT__u_result_fifo__DOT__mem__v0 
                = (7U & (IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__wptr_bin));
            __VdlySet__accelerator_top__DOT__u_result_fifo__DOT__mem__v0 = 1U;
            vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__wptr_bin 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__wptr_bin)));
        }
        if (vlSelfRef.accelerator_top__DOT__clk_en_comp) {
            __VdlyVal__accelerator_top__DOT____Vcellout__u_array__psum_out__v0 
                = vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire
                [4U][0U];
            __VdlySet__accelerator_top__DOT____Vcellout__u_array__psum_out__v0 = 1U;
            __VdlyVal__accelerator_top__DOT____Vcellout__u_array__psum_out__v1 
                = vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire
                [4U][1U];
            __VdlyVal__accelerator_top__DOT____Vcellout__u_array__psum_out__v2 
                = vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire
                [4U][2U];
            __VdlyVal__accelerator_top__DOT____Vcellout__u_array__psum_out__v3 
                = vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire
                [4U][3U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__act_out 
                = vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                [0U][0U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__act_out 
                = vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                [0U][1U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__act_out 
                = vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                [0U][2U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__act_out 
                = vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                [0U][3U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__act_out 
                = vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                [1U][0U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__act_out 
                = vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                [1U][1U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__act_out 
                = vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                [1U][2U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__act_out 
                = vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                [1U][3U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__act_out 
                = vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                [2U][0U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__act_out 
                = vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                [2U][1U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__act_out 
                = vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                [2U][2U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__act_out 
                = vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                [2U][3U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__act_out 
                = vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                [3U][0U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__act_out 
                = vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                [3U][1U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__act_out 
                = vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                [3U][2U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__act_out 
                = vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                [3U][3U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__psum_out 
                = (vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire
                   [0U][0U] + VL_EXTENDS_II(32,16, 
                                            (0xffffU 
                                             & VL_MULS_III(16, 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__0__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__DOT__weight_reg))), 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, 
                                                                            vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                                                                            [0U]
                                                                            [0U]))))));
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__psum_out 
                = (vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire
                   [0U][1U] + VL_EXTENDS_II(32,16, 
                                            (0xffffU 
                                             & VL_MULS_III(16, 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__0__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__DOT__weight_reg))), 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, 
                                                                            vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                                                                            [0U]
                                                                            [1U]))))));
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__psum_out 
                = (vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire
                   [0U][2U] + VL_EXTENDS_II(32,16, 
                                            (0xffffU 
                                             & VL_MULS_III(16, 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__0__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__DOT__weight_reg))), 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, 
                                                                            vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                                                                            [0U]
                                                                            [2U]))))));
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__psum_out 
                = (vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire
                   [0U][3U] + VL_EXTENDS_II(32,16, 
                                            (0xffffU 
                                             & VL_MULS_III(16, 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__0__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__DOT__weight_reg))), 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, 
                                                                            vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                                                                            [0U]
                                                                            [3U]))))));
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__psum_out 
                = (vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire
                   [1U][0U] + VL_EXTENDS_II(32,16, 
                                            (0xffffU 
                                             & VL_MULS_III(16, 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__1__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__DOT__weight_reg))), 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, 
                                                                            vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                                                                            [1U]
                                                                            [0U]))))));
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__psum_out 
                = (vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire
                   [1U][1U] + VL_EXTENDS_II(32,16, 
                                            (0xffffU 
                                             & VL_MULS_III(16, 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__1__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__DOT__weight_reg))), 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, 
                                                                            vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                                                                            [1U]
                                                                            [1U]))))));
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__psum_out 
                = (vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire
                   [1U][2U] + VL_EXTENDS_II(32,16, 
                                            (0xffffU 
                                             & VL_MULS_III(16, 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__1__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__DOT__weight_reg))), 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, 
                                                                            vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                                                                            [1U]
                                                                            [2U]))))));
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__psum_out 
                = (vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire
                   [1U][3U] + VL_EXTENDS_II(32,16, 
                                            (0xffffU 
                                             & VL_MULS_III(16, 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__1__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__DOT__weight_reg))), 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, 
                                                                            vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                                                                            [1U]
                                                                            [3U]))))));
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__psum_out 
                = (vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire
                   [2U][0U] + VL_EXTENDS_II(32,16, 
                                            (0xffffU 
                                             & VL_MULS_III(16, 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__2__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__DOT__weight_reg))), 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, 
                                                                            vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                                                                            [2U]
                                                                            [0U]))))));
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__psum_out 
                = (vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire
                   [2U][1U] + VL_EXTENDS_II(32,16, 
                                            (0xffffU 
                                             & VL_MULS_III(16, 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__2__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__DOT__weight_reg))), 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, 
                                                                            vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                                                                            [2U]
                                                                            [1U]))))));
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__psum_out 
                = (vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire
                   [2U][2U] + VL_EXTENDS_II(32,16, 
                                            (0xffffU 
                                             & VL_MULS_III(16, 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__2__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__DOT__weight_reg))), 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, 
                                                                            vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                                                                            [2U]
                                                                            [2U]))))));
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__psum_out 
                = (vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire
                   [2U][3U] + VL_EXTENDS_II(32,16, 
                                            (0xffffU 
                                             & VL_MULS_III(16, 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__2__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__DOT__weight_reg))), 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, 
                                                                            vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                                                                            [2U]
                                                                            [3U]))))));
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__psum_out 
                = (vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire
                   [3U][0U] + VL_EXTENDS_II(32,16, 
                                            (0xffffU 
                                             & VL_MULS_III(16, 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__3__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__DOT__weight_reg))), 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, 
                                                                            vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                                                                            [3U]
                                                                            [0U]))))));
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__psum_out 
                = (vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire
                   [3U][1U] + VL_EXTENDS_II(32,16, 
                                            (0xffffU 
                                             & VL_MULS_III(16, 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__3__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__DOT__weight_reg))), 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, 
                                                                            vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                                                                            [3U]
                                                                            [1U]))))));
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__psum_out 
                = (vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire
                   [3U][2U] + VL_EXTENDS_II(32,16, 
                                            (0xffffU 
                                             & VL_MULS_III(16, 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__3__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__DOT__weight_reg))), 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, 
                                                                            vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                                                                            [3U]
                                                                            [2U]))))));
            vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__psum_out 
                = (vlSelfRef.accelerator_top__DOT__u_array__DOT__psum_wire
                   [3U][3U] + VL_EXTENDS_II(32,16, 
                                            (0xffffU 
                                             & VL_MULS_III(16, 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, (IData)(vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__3__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__DOT__weight_reg))), 
                                                           (0xffffU 
                                                            & VL_EXTENDS_II(16,8, 
                                                                            vlSelfRef.accelerator_top__DOT__u_array__DOT__act_wire
                                                                            [3U]
                                                                            [3U]))))));
            if ((((3U == (IData)(vlSelfRef.accelerator_top__DOT__comp_state)) 
                  & (3U == (IData)(vlSelfRef.accelerator_top__DOT__drain_cnt))) 
                 & (~ (IData)(vlSelfRef.accelerator_top__DOT__result_wfull)))) {
                vlSelfRef.accelerator_top__DOT__inference_done_reg = 1U;
            } else if ((1U == (IData)(vlSelfRef.accelerator_top__DOT__comp_state))) {
                vlSelfRef.accelerator_top__DOT__inference_done_reg = 0U;
            }
            vlSelfRef.accelerator_top__DOT__result_wen_r = 0U;
            if ((2U & (IData)(vlSelfRef.accelerator_top__DOT__comp_state))) {
                if ((1U & (IData)(vlSelfRef.accelerator_top__DOT__comp_state))) {
                    if ((1U & (~ (IData)(vlSelfRef.accelerator_top__DOT__result_wfull)))) {
                        vlSelfRef.accelerator_top__DOT__result_wen_r = 1U;
                        vlSelfRef.accelerator_top__DOT__result_wdata_r 
                            = vlSelfRef.accelerator_top__DOT__snap
                            [vlSelfRef.accelerator_top__DOT__drain_cnt];
                        __Vdly__accelerator_top__DOT__drain_cnt 
                            = (3U & ((IData)(1U) + (IData)(vlSelfRef.accelerator_top__DOT__drain_cnt)));
                        if ((3U == (IData)(vlSelfRef.accelerator_top__DOT__drain_cnt))) {
                            __Vdly__accelerator_top__DOT__comp_state = 0U;
                        }
                    }
                } else if (vlSelfRef.accelerator_top__DOT__snap_wait) {
                    __VdlyVal__accelerator_top__DOT__snap__v0 
                        = vlSelfRef.accelerator_top__DOT__sa_psum_out
                        [vlSelfRef.accelerator_top__DOT__snap_cnt];
                    __VdlyDim0__accelerator_top__DOT__snap__v0 
                        = vlSelfRef.accelerator_top__DOT__snap_cnt;
                    __VdlySet__accelerator_top__DOT__snap__v0 = 1U;
                    __Vdly__accelerator_top__DOT__snap_cnt 
                        = (3U & ((IData)(1U) + (IData)(vlSelfRef.accelerator_top__DOT__snap_cnt)));
                    if ((3U == (IData)(vlSelfRef.accelerator_top__DOT__snap_cnt))) {
                        __Vdly__accelerator_top__DOT__drain_cnt = 0U;
                        __Vdly__accelerator_top__DOT__comp_state = 3U;
                    }
                } else {
                    vlSelfRef.accelerator_top__DOT__snap_wait = 1U;
                }
            } else if ((1U & (IData)(vlSelfRef.accelerator_top__DOT__comp_state))) {
                __Vdly__accelerator_top__DOT__feed_cnt 
                    = (3U & ((IData)(1U) + (IData)(vlSelfRef.accelerator_top__DOT__feed_cnt)));
                if ((3U == (IData)(vlSelfRef.accelerator_top__DOT__feed_cnt))) {
                    vlSelfRef.accelerator_top__DOT__snap_wait = 0U;
                    __Vdly__accelerator_top__DOT__snap_cnt = 0U;
                    __Vdly__accelerator_top__DOT__comp_state = 2U;
                }
            } else if ((1U & (~ (IData)(vlSelfRef.accelerator_top__DOT__act_rempty)))) {
                __VdlyVal__accelerator_top__DOT__act_lat__v0 
                    = (0xffU & vlSelfRef.accelerator_top__DOT__act_rdata);
                __VdlySet__accelerator_top__DOT__act_lat__v0 = 1U;
                __Vdly__accelerator_top__DOT__feed_cnt = 0U;
                __Vdly__accelerator_top__DOT__comp_state = 1U;
                __VdlyVal__accelerator_top__DOT__act_lat__v1 
                    = (0xffU & (vlSelfRef.accelerator_top__DOT__act_rdata 
                                >> 8U));
                __VdlySet__accelerator_top__DOT__act_lat__v1 = 1U;
                __VdlyVal__accelerator_top__DOT__act_lat__v2 
                    = (0xffU & (vlSelfRef.accelerator_top__DOT__act_rdata 
                                >> 0x10U));
                __VdlyVal__accelerator_top__DOT__act_lat__v3 
                    = (vlSelfRef.accelerator_top__DOT__act_rdata 
                       >> 0x18U);
            }
        }
        vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__wptr_sync 
            = vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__wptr_sync1;
        vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_sync 
            = vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_sync1;
        vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__wptr_sync1 
            = vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__wptr_gray;
        vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_sync1 
            = vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_gray;
        if (vlSelfRef.accelerator_top__DOT__lw_comp) {
            vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__0__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__DOT__weight_reg 
                = vlSelfRef.weights[0U][0U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__0__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__DOT__weight_reg 
                = vlSelfRef.weights[0U][1U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__0__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__DOT__weight_reg 
                = vlSelfRef.weights[0U][2U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__0__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__DOT__weight_reg 
                = vlSelfRef.weights[0U][3U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__1__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__DOT__weight_reg 
                = vlSelfRef.weights[1U][0U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__1__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__DOT__weight_reg 
                = vlSelfRef.weights[1U][1U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__1__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__DOT__weight_reg 
                = vlSelfRef.weights[1U][2U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__1__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__DOT__weight_reg 
                = vlSelfRef.weights[1U][3U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__2__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__DOT__weight_reg 
                = vlSelfRef.weights[2U][0U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__2__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__DOT__weight_reg 
                = vlSelfRef.weights[2U][1U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__2__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__DOT__weight_reg 
                = vlSelfRef.weights[2U][2U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__2__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__DOT__weight_reg 
                = vlSelfRef.weights[2U][3U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__3__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__DOT__weight_reg 
                = vlSelfRef.weights[3U][0U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__3__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__DOT__weight_reg 
                = vlSelfRef.weights[3U][1U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__3__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__DOT__weight_reg 
                = vlSelfRef.weights[3U][2U];
            vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__3__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__DOT__weight_reg 
                = vlSelfRef.weights[3U][3U];
        }
    } else {
        vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_bin = 0U;
        __VdlySet__accelerator_top__DOT____Vcellout__u_array__psum_out__v4 = 1U;
        vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__wptr_bin = 0U;
        vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__wptr_sync = 0U;
        vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_sync = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__act_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__act_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__act_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__act_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__act_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__act_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__act_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__act_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__act_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__act_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__act_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__act_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__act_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__act_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__act_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__act_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__psum_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__psum_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__psum_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__psum_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__psum_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__psum_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__psum_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__psum_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__psum_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__psum_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__psum_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__psum_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__psum_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__psum_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__psum_out = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__psum_out = 0U;
        vlSelfRef.accelerator_top__DOT__inference_done_reg = 0U;
        __Vdly__accelerator_top__DOT__comp_state = 0U;
        __Vdly__accelerator_top__DOT__feed_cnt = 0U;
        __Vdly__accelerator_top__DOT__snap_cnt = 0U;
        vlSelfRef.accelerator_top__DOT__snap_wait = 0U;
        __Vdly__accelerator_top__DOT__drain_cnt = 0U;
        vlSelfRef.accelerator_top__DOT__result_wen_r = 0U;
        vlSelfRef.accelerator_top__DOT__result_wdata_r = 0U;
        __VdlySet__accelerator_top__DOT__act_lat__v4 = 1U;
        vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__wptr_sync1 = 0U;
        vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_sync1 = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__0__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__DOT__weight_reg = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__0__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__DOT__weight_reg = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__0__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__DOT__weight_reg = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__0__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__DOT__weight_reg = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__1__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__DOT__weight_reg = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__1__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__DOT__weight_reg = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__1__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__DOT__weight_reg = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__1__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__DOT__weight_reg = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__2__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__DOT__weight_reg = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__2__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__DOT__weight_reg = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__2__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__DOT__weight_reg = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__2__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__DOT__weight_reg = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__3__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__DOT__weight_reg = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__3__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__DOT__weight_reg = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__3__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__DOT__weight_reg = 0U;
        vlSelfRef.accelerator_top__DOT__u_array__DOT__row_g__BRA__3__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__DOT__weight_reg = 0U;
    }
    if (__VdlySet__accelerator_top__DOT____Vcellout__u_array__psum_out__v0) {
        vlSelfRef.accelerator_top__DOT____Vcellout__u_array__psum_out[0U] 
            = __VdlyVal__accelerator_top__DOT____Vcellout__u_array__psum_out__v0;
        vlSelfRef.accelerator_top__DOT____Vcellout__u_array__psum_out[1U] 
            = __VdlyVal__accelerator_top__DOT____Vcellout__u_array__psum_out__v1;
        vlSelfRef.accelerator_top__DOT____Vcellout__u_array__psum_out[2U] 
            = __VdlyVal__accelerator_top__DOT____Vcellout__u_array__psum_out__v2;
        vlSelfRef.accelerator_top__DOT____Vcellout__u_array__psum_out[3U] 
            = __VdlyVal__accelerator_top__DOT____Vcellout__u_array__psum_out__v3;
    }
    if (__VdlySet__accelerator_top__DOT____Vcellout__u_array__psum_out__v4) {
        vlSelfRef.accelerator_top__DOT____Vcellout__u_array__psum_out[0U] = 0U;
        vlSelfRef.accelerator_top__DOT____Vcellout__u_array__psum_out[1U] = 0U;
        vlSelfRef.accelerator_top__DOT____Vcellout__u_array__psum_out[2U] = 0U;
        vlSelfRef.accelerator_top__DOT____Vcellout__u_array__psum_out[3U] = 0U;
    }
    if (__VdlySet__accelerator_top__DOT__u_result_fifo__DOT__mem__v0) {
        vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__mem[__VdlyDim0__accelerator_top__DOT__u_result_fifo__DOT__mem__v0] 
            = __VdlyVal__accelerator_top__DOT__u_result_fifo__DOT__mem__v0;
    }
    vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_gray 
        = (0xfU & ((IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_bin) 
                   ^ VL_SHIFTR_III(4,4,32, (IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_bin), 1U)));
    vlSelfRef.dbg_psum[0U] = vlSelfRef.accelerator_top__DOT____Vcellout__u_array__psum_out
        [3U];
    vlSelfRef.dbg_psum[1U] = vlSelfRef.accelerator_top__DOT____Vcellout__u_array__psum_out
        [2U];
    vlSelfRef.dbg_psum[2U] = vlSelfRef.accelerator_top__DOT____Vcellout__u_array__psum_out
        [1U];
    vlSelfRef.dbg_psum[3U] = vlSelfRef.accelerator_top__DOT____Vcellout__u_array__psum_out
        [0U];
    vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__wptr_gray 
        = (0xfU & ((IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__wptr_bin) 
                   ^ VL_SHIFTR_III(4,4,32, (IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__wptr_bin), 1U)));
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
    vlSelfRef.accelerator_top__DOT__act_rempty = ((IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_gray) 
                                                  == (IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__wptr_sync));
    vlSelfRef.accelerator_top__DOT__snap_cnt = __Vdly__accelerator_top__DOT__snap_cnt;
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
    vlSelfRef.accelerator_top__DOT__feed_cnt = __Vdly__accelerator_top__DOT__feed_cnt;
    if (__VdlySet__accelerator_top__DOT__snap__v0) {
        vlSelfRef.accelerator_top__DOT__snap[__VdlyDim0__accelerator_top__DOT__snap__v0] 
            = __VdlyVal__accelerator_top__DOT__snap__v0;
    }
    if (__VdlySet__accelerator_top__DOT__act_lat__v0) {
        vlSelfRef.accelerator_top__DOT__act_lat[0U] 
            = __VdlyVal__accelerator_top__DOT__act_lat__v0;
    }
    if (__VdlySet__accelerator_top__DOT__act_lat__v1) {
        vlSelfRef.accelerator_top__DOT__act_lat[1U] 
            = __VdlyVal__accelerator_top__DOT__act_lat__v1;
        vlSelfRef.accelerator_top__DOT__act_lat[2U] 
            = __VdlyVal__accelerator_top__DOT__act_lat__v2;
        vlSelfRef.accelerator_top__DOT__act_lat[3U] 
            = __VdlyVal__accelerator_top__DOT__act_lat__v3;
    }
    if (__VdlySet__accelerator_top__DOT__act_lat__v4) {
        vlSelfRef.accelerator_top__DOT__snap[0U] = 0U;
        vlSelfRef.accelerator_top__DOT__snap[1U] = 0U;
        vlSelfRef.accelerator_top__DOT__snap[2U] = 0U;
        vlSelfRef.accelerator_top__DOT__snap[3U] = 0U;
        vlSelfRef.accelerator_top__DOT__act_lat[0U] = 0U;
        vlSelfRef.accelerator_top__DOT__act_lat[1U] = 0U;
        vlSelfRef.accelerator_top__DOT__act_lat[2U] = 0U;
        vlSelfRef.accelerator_top__DOT__act_lat[3U] = 0U;
    }
    vlSelfRef.accelerator_top__DOT__drain_cnt = __Vdly__accelerator_top__DOT__drain_cnt;
    vlSelfRef.accelerator_top__DOT__result_wfull = 
        ((IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__wptr_gray) 
         == ((0xcU & ((~ ((IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_sync) 
                          >> 2U)) << 2U)) | (3U & (IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_sync))));
    vlSelfRef.accelerator_top__DOT__comp_state = __Vdly__accelerator_top__DOT__comp_state;
    vlSelfRef.dbg_snapcnt = vlSelfRef.accelerator_top__DOT__snap_cnt;
    vlSelfRef.dbg_snapwait = vlSelfRef.accelerator_top__DOT__snap_wait;
    vlSelfRef.dbg_snap[0U] = vlSelfRef.accelerator_top__DOT__snap
        [0U];
    vlSelfRef.dbg_snap[1U] = vlSelfRef.accelerator_top__DOT__snap
        [1U];
    vlSelfRef.dbg_snap[2U] = vlSelfRef.accelerator_top__DOT__snap
        [2U];
    vlSelfRef.dbg_snap[3U] = vlSelfRef.accelerator_top__DOT__snap
        [3U];
    vlSelfRef.dbg_state = vlSelfRef.accelerator_top__DOT__comp_state;
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
    vlSelfRef.accelerator_top__DOT__clk_en_comp = ((IData)(vlSelfRef.comp_rst_n) 
                                                   && (IData)(vlSelfRef.accelerator_top__DOT__clk_en_s1));
    vlSelfRef.accelerator_top__DOT__lw_comp = ((IData)(vlSelfRef.comp_rst_n) 
                                               && (IData)(vlSelfRef.accelerator_top__DOT__lw_s1));
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
    vlSelfRef.accelerator_top__DOT__clk_en_s1 = ((IData)(vlSelfRef.comp_rst_n) 
                                                 && (IData)(vlSelfRef.accelerator_top__DOT__clk_en));
    vlSelfRef.accelerator_top__DOT__lw_s1 = ((IData)(vlSelfRef.comp_rst_n) 
                                             && (IData)(vlSelfRef.load_weight));
}

VL_INLINE_OPT void Vaccelerator_top___024root___nba_comb__TOP__0(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___nba_comb__TOP__0\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.result_rdata = vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__mem
        [(7U & (IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_bin))];
    vlSelfRef.accelerator_top__DOT__act_rdata = vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__mem
        [(7U & (IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_bin))];
}

extern const VlUnpacked<CData/*0:0*/, 16> Vaccelerator_top__ConstPool__TABLE_h4ed7b7f5_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vaccelerator_top__ConstPool__TABLE_hb6c640d9_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vaccelerator_top__ConstPool__TABLE_h163969a3_0;

VL_INLINE_OPT void Vaccelerator_top___024root___nba_sequent__TOP__2(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___nba_sequent__TOP__2\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    // Body
    vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__wptr_gray 
        = (0xfU & ((IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__wptr_bin) 
                   ^ VL_SHIFTR_III(4,4,32, (IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__wptr_bin), 1U)));
    vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_gray 
        = (0xfU & ((IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_bin) 
                   ^ VL_SHIFTR_III(4,4,32, (IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_bin), 1U)));
    vlSelfRef.act_wfull = ((IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__wptr_gray) 
                           == ((0xcU & ((~ ((IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_sync) 
                                            >> 2U)) 
                                        << 2U)) | (3U 
                                                   & (IData)(vlSelfRef.accelerator_top__DOT__u_act_fifo__DOT__rptr_sync))));
    vlSelfRef.result_rempty = ((IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__rptr_gray) 
                               == (IData)(vlSelfRef.accelerator_top__DOT__u_result_fifo__DOT__wptr_sync));
    __Vtableidx2 = (((IData)(vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__iso_pending) 
                     << 3U) | (((IData)(vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__next_state) 
                                << 1U) | (IData)(vlSelfRef.ctrl_rst_n)));
    vlSelfRef.accelerator_top__DOT__clk_en = Vaccelerator_top__ConstPool__TABLE_h4ed7b7f5_0
        [__Vtableidx2];
    vlSelfRef.iso_en = Vaccelerator_top__ConstPool__TABLE_hb6c640d9_0
        [__Vtableidx2];
    vlSelfRef.power_down = Vaccelerator_top__ConstPool__TABLE_h163969a3_0
        [__Vtableidx2];
    vlSelfRef.clk_en_out = vlSelfRef.accelerator_top__DOT__clk_en;
    if (vlSelfRef.ctrl_rst_n) {
        if (((3U == (IData)(vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__next_state)) 
             & (3U != (IData)(vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__curr_state)))) {
            vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__iso_pending = 1U;
        } else if ((3U != (IData)(vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__curr_state))) {
            vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__iso_pending = 0U;
        }
        vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__curr_state 
            = vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__next_state;
    } else {
        vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__iso_pending = 0U;
        vlSelfRef.accelerator_top__DOT__u_power_fsm__DOT__curr_state = 0U;
    }
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
}

void Vaccelerator_top___024root___eval_triggers__act(Vaccelerator_top___024root* vlSelf);

bool Vaccelerator_top___024root___eval_phase__act(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___eval_phase__act\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vaccelerator_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vaccelerator_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vaccelerator_top___024root___eval_phase__nba(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___eval_phase__nba\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vaccelerator_top___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vaccelerator_top___024root___dump_triggers__ico(Vaccelerator_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vaccelerator_top___024root___dump_triggers__nba(Vaccelerator_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vaccelerator_top___024root___dump_triggers__act(Vaccelerator_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vaccelerator_top___024root___eval(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___eval\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vaccelerator_top___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rtl/accelerator_top.sv", 3, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vaccelerator_top___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vaccelerator_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/accelerator_top.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vaccelerator_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/accelerator_top.sv", 3, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vaccelerator_top___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vaccelerator_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vaccelerator_top___024root___eval_debug_assertions(Vaccelerator_top___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vaccelerator_top___024root___eval_debug_assertions\n"); );
    Vaccelerator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.ctrl_clk & 0xfeU)))) {
        Verilated::overWidthError("ctrl_clk");}
    if (VL_UNLIKELY(((vlSelfRef.comp_clk & 0xfeU)))) {
        Verilated::overWidthError("comp_clk");}
    if (VL_UNLIKELY(((vlSelfRef.ctrl_rst_n & 0xfeU)))) {
        Verilated::overWidthError("ctrl_rst_n");}
    if (VL_UNLIKELY(((vlSelfRef.comp_rst_n & 0xfeU)))) {
        Verilated::overWidthError("comp_rst_n");}
    if (VL_UNLIKELY(((vlSelfRef.load_weight & 0xfeU)))) {
        Verilated::overWidthError("load_weight");}
    if (VL_UNLIKELY(((vlSelfRef.act_wen & 0xfeU)))) {
        Verilated::overWidthError("act_wen");}
    if (VL_UNLIKELY(((vlSelfRef.result_ren & 0xfeU)))) {
        Verilated::overWidthError("result_ren");}
    if (VL_UNLIKELY(((vlSelfRef.start & 0xfeU)))) {
        Verilated::overWidthError("start");}
    if (VL_UNLIKELY(((vlSelfRef.powerdown_req & 0xfeU)))) {
        Verilated::overWidthError("powerdown_req");}
    if (VL_UNLIKELY(((vlSelfRef.wakeup & 0xfeU)))) {
        Verilated::overWidthError("wakeup");}
}
#endif  // VL_DEBUG

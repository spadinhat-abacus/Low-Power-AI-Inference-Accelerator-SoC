// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vaccelerator_top.h for the primary calling header

#ifndef VERILATED_VACCELERATOR_TOP___024ROOT_H_
#define VERILATED_VACCELERATOR_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vaccelerator_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vaccelerator_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(ctrl_clk,0,0);
        VL_IN8(comp_clk,0,0);
        VL_IN8(ctrl_rst_n,0,0);
        VL_IN8(comp_rst_n,0,0);
        VL_IN8(load_weight,0,0);
        VL_IN8(act_wen,0,0);
        VL_OUT8(act_wfull,0,0);
        VL_IN8(result_ren,0,0);
        VL_OUT8(result_rempty,0,0);
        VL_IN8(start,0,0);
        VL_IN8(powerdown_req,0,0);
        VL_IN8(wakeup,0,0);
        VL_OUT8(clk_en_out,0,0);
        VL_OUT8(iso_en,0,0);
        VL_OUT8(power_down,0,0);
        VL_OUT8(dbg_state,1,0);
        VL_OUT8(dbg_snapcnt,1,0);
        VL_OUT8(dbg_snapwait,0,0);
        CData/*0:0*/ accelerator_top__DOT__clk_en;
        CData/*0:0*/ accelerator_top__DOT__clk_en_s1;
        CData/*0:0*/ accelerator_top__DOT__clk_en_comp;
        CData/*0:0*/ accelerator_top__DOT__lw_s1;
        CData/*0:0*/ accelerator_top__DOT__lw_comp;
        CData/*0:0*/ accelerator_top__DOT__inf_done_s1;
        CData/*0:0*/ accelerator_top__DOT__inference_done_ctrl;
        CData/*0:0*/ accelerator_top__DOT__act_rempty;
        CData/*0:0*/ accelerator_top__DOT__result_wfull;
        CData/*0:0*/ accelerator_top__DOT__result_wen_r;
        CData/*1:0*/ accelerator_top__DOT__comp_state;
        CData/*1:0*/ accelerator_top__DOT__feed_cnt;
        CData/*1:0*/ accelerator_top__DOT__snap_cnt;
        CData/*1:0*/ accelerator_top__DOT__drain_cnt;
        CData/*0:0*/ accelerator_top__DOT__snap_wait;
        CData/*0:0*/ accelerator_top__DOT__inference_done_reg;
        CData/*1:0*/ accelerator_top__DOT__u_power_fsm__DOT__curr_state;
        CData/*1:0*/ accelerator_top__DOT__u_power_fsm__DOT__next_state;
        CData/*4:0*/ accelerator_top__DOT__u_power_fsm__DOT__gate_cnt;
        CData/*0:0*/ accelerator_top__DOT__u_power_fsm__DOT__gate_timeout;
        CData/*0:0*/ accelerator_top__DOT__u_power_fsm__DOT__iso_pending;
        CData/*3:0*/ accelerator_top__DOT__u_act_fifo__DOT__wptr_bin;
        CData/*3:0*/ accelerator_top__DOT__u_act_fifo__DOT__wptr_gray;
        CData/*3:0*/ accelerator_top__DOT__u_act_fifo__DOT__rptr_bin;
        CData/*3:0*/ accelerator_top__DOT__u_act_fifo__DOT__rptr_gray;
        CData/*3:0*/ accelerator_top__DOT__u_act_fifo__DOT__wptr_sync1;
        CData/*3:0*/ accelerator_top__DOT__u_act_fifo__DOT__wptr_sync;
        CData/*3:0*/ accelerator_top__DOT__u_act_fifo__DOT__rptr_sync1;
        CData/*3:0*/ accelerator_top__DOT__u_act_fifo__DOT__rptr_sync;
        CData/*3:0*/ accelerator_top__DOT__u_result_fifo__DOT__wptr_bin;
        CData/*3:0*/ accelerator_top__DOT__u_result_fifo__DOT__wptr_gray;
        CData/*3:0*/ accelerator_top__DOT__u_result_fifo__DOT__rptr_bin;
        CData/*3:0*/ accelerator_top__DOT__u_result_fifo__DOT__rptr_gray;
        CData/*3:0*/ accelerator_top__DOT__u_result_fifo__DOT__wptr_sync1;
        CData/*3:0*/ accelerator_top__DOT__u_result_fifo__DOT__wptr_sync;
        CData/*3:0*/ accelerator_top__DOT__u_result_fifo__DOT__rptr_sync1;
        CData/*3:0*/ accelerator_top__DOT__u_result_fifo__DOT__rptr_sync;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__act_out;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__act_out;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__act_out;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__act_out;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__act_out;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__act_out;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__act_out;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__act_out;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__act_out;
    };
    struct {
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__act_out;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__act_out;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__act_out;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__act_out;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__act_out;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__act_out;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__act_out;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT__row_g__BRA__0__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__DOT__weight_reg;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT__row_g__BRA__0__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__DOT__weight_reg;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT__row_g__BRA__0__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__DOT__weight_reg;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT__row_g__BRA__0__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__DOT__weight_reg;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT__row_g__BRA__1__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__DOT__weight_reg;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT__row_g__BRA__1__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__DOT__weight_reg;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT__row_g__BRA__1__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__DOT__weight_reg;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT__row_g__BRA__1__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__DOT__weight_reg;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT__row_g__BRA__2__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__DOT__weight_reg;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT__row_g__BRA__2__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__DOT__weight_reg;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT__row_g__BRA__2__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__DOT__weight_reg;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT__row_g__BRA__2__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__DOT__weight_reg;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT__row_g__BRA__3__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__DOT__weight_reg;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT__row_g__BRA__3__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__DOT__weight_reg;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT__row_g__BRA__3__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__DOT__weight_reg;
        CData/*7:0*/ accelerator_top__DOT__u_array__DOT__row_g__BRA__3__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__DOT__weight_reg;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VicoFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__comp_clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__comp_rst_n__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__ctrl_clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__ctrl_rst_n__0;
        CData/*0:0*/ __VactContinue;
        VL_IN(act_wdata,31,0);
        VL_OUT(result_rdata,31,0);
        IData/*31:0*/ accelerator_top__DOT__act_rdata;
        IData/*31:0*/ accelerator_top__DOT__result_wdata_r;
        IData/*31:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__psum_out;
        IData/*31:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__psum_out;
        IData/*31:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__psum_out;
        IData/*31:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__0__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__psum_out;
        IData/*31:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__psum_out;
        IData/*31:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__psum_out;
        IData/*31:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__psum_out;
        IData/*31:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__1__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__psum_out;
        IData/*31:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__psum_out;
        IData/*31:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__psum_out;
        IData/*31:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__psum_out;
        IData/*31:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__2__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__psum_out;
        IData/*31:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__0__KET____DOT__u_pe__psum_out;
        IData/*31:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__1__KET____DOT__u_pe__psum_out;
        IData/*31:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__2__KET____DOT__u_pe__psum_out;
        IData/*31:0*/ accelerator_top__DOT__u_array__DOT____Vcellout__row_g__BRA__3__KET____DOT__col_g__BRA__3__KET____DOT__u_pe__psum_out;
        IData/*31:0*/ __VactIterCount;
        VL_IN8(weights[4][4],7,0);
        VL_OUT(dbg_snap[4],31,0);
        VL_OUT(dbg_psum[4],31,0);
        VlUnpacked<CData/*7:0*/, 4> accelerator_top__DOT__sa_act_in;
        VlUnpacked<IData/*31:0*/, 4> accelerator_top__DOT__sa_psum_out;
        VlUnpacked<IData/*31:0*/, 4> accelerator_top__DOT____Vcellout__u_array__psum_out;
        VlUnpacked<CData/*7:0*/, 4> accelerator_top__DOT____Vcellinp__u_array__act_in;
        VlUnpacked<CData/*7:0*/, 4> accelerator_top__DOT__act_lat;
        VlUnpacked<IData/*31:0*/, 4> accelerator_top__DOT__snap;
        VlUnpacked<IData/*31:0*/, 8> accelerator_top__DOT__u_act_fifo__DOT__mem;
        VlUnpacked<IData/*31:0*/, 8> accelerator_top__DOT__u_result_fifo__DOT__mem;
        VlUnpacked<VlUnpacked<CData/*7:0*/, 5>, 4> accelerator_top__DOT__u_array__DOT__act_wire;
        VlUnpacked<VlUnpacked<IData/*31:0*/, 4>, 5> accelerator_top__DOT__u_array__DOT__psum_wire;
    };
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vaccelerator_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vaccelerator_top___024root(Vaccelerator_top__Syms* symsp, const char* v__name);
    ~Vaccelerator_top___024root();
    VL_UNCOPYABLE(Vaccelerator_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

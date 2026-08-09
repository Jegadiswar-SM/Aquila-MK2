// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_affhc.h for the primary calling header

#ifndef VERILATED_VTB_AFFHC___024ROOT_H_
#define VERILATED_VTB_AFFHC___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_affhc__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_affhc___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_affhc__DOT__clk;
    CData/*0:0*/ tb_affhc__DOT__rst_n;
    CData/*0:0*/ tb_affhc__DOT__e_valid;
    CData/*4:0*/ tb_affhc__DOT__s_axi_awaddr;
    CData/*0:0*/ tb_affhc__DOT__s_axi_awvalid;
    CData/*0:0*/ tb_affhc__DOT__s_axi_wvalid;
    CData/*0:0*/ tb_affhc__DOT__s_axi_awready;
    CData/*0:0*/ tb_affhc__DOT__s_axi_wready;
    CData/*1:0*/ tb_affhc__DOT__fsm_state_dbg;
    CData/*1:0*/ tb_affhc__DOT__dut__DOT__state;
    CData/*1:0*/ tb_affhc__DOT__dut__DOT__next_state;
    CData/*2:0*/ tb_affhc__DOT__dut__DOT__cnt_up;
    CData/*3:0*/ tb_affhc__DOT__dut__DOT__cnt_down;
    CData/*5:0*/ tb_affhc__DOT__dut__DOT__lockout_cnt;
    CData/*0:0*/ tb_affhc__DOT__dut__DOT__lockout_active;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_affhc__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_affhc__DOT__rst_n__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ tb_affhc__DOT__e_in;
    SData/*15:0*/ tb_affhc__DOT__lambda_out;
    SData/*15:0*/ tb_affhc__DOT__dut__DOT__lambda_slow;
    SData/*15:0*/ tb_affhc__DOT__dut__DOT__lambda_mid;
    SData/*15:0*/ tb_affhc__DOT__dut__DOT__lambda_fast;
    SData/*15:0*/ tb_affhc__DOT__dut__DOT__threshold_up_reg;
    SData/*15:0*/ tb_affhc__DOT__dut__DOT__threshold_down_reg;
    SData/*15:0*/ tb_affhc__DOT__dut__DOT__e_prev;
    IData/*31:0*/ tb_affhc__DOT__s_axi_wdata;
    IData/*31:0*/ tb_affhc__DOT__pass;
    IData/*31:0*/ tb_affhc__DOT__fail;
    IData/*16:0*/ tb_affhc__DOT__dut__DOT__delta_e;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h1cbcd60f__0;
    VlTriggerScheduler __VtrigSched_h1cbcd6ce__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_affhc__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_affhc___024root(Vtb_affhc__Syms* symsp, const char* v__name);
    ~Vtb_affhc___024root();
    VL_UNCOPYABLE(Vtb_affhc___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

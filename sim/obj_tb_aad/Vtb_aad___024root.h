// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_aad.h for the primary calling header

#ifndef VERILATED_VTB_AAD___024ROOT_H_
#define VERILATED_VTB_AAD___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_aad__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_aad___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_aad__DOT__clk;
    CData/*0:0*/ tb_aad__DOT__rst_n;
    CData/*0:0*/ tb_aad__DOT__x_valid;
    CData/*3:0*/ tb_aad__DOT__s_axi_awaddr;
    CData/*0:0*/ tb_aad__DOT__s_axi_awvalid;
    CData/*0:0*/ tb_aad__DOT__s_axi_wvalid;
    CData/*0:0*/ tb_aad__DOT__s_axi_awready;
    CData/*0:0*/ tb_aad__DOT__s_axi_wready;
    CData/*0:0*/ tb_aad__DOT__signal_active;
    CData/*0:0*/ tb_aad__DOT__clk_gate_en;
    CData/*3:0*/ tb_aad__DOT__dut__DOT__ratio_shift_reg;
    CData/*0:0*/ tb_aad__DOT__dut__DOT__activity_cmp;
    CData/*2:0*/ tb_aad__DOT__dut__DOT__assert_cnt;
    CData/*6:0*/ tb_aad__DOT__dut__DOT__deassert_cnt;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_aad__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_aad__DOT__rst_n__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ tb_aad__DOT__x_in;
    IData/*31:0*/ tb_aad__DOT__s_axi_wdata;
    IData/*31:0*/ tb_aad__DOT__pass;
    IData/*31:0*/ tb_aad__DOT__fail;
    IData/*31:0*/ tb_aad__DOT__dut__DOT__x_sq;
    IData/*31:0*/ tb_aad__DOT__dut__DOT__mul_tmp;
    IData/*31:0*/ __VactIterCount;
    QData/*39:0*/ tb_aad__DOT__acc_A_dbg;
    QData/*39:0*/ tb_aad__DOT__acc_B_dbg;
    QData/*39:0*/ tb_aad__DOT__dut__DOT__acc_A;
    QData/*39:0*/ tb_aad__DOT__dut__DOT__acc_B;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h826be8d7__0;
    VlTriggerScheduler __VtrigSched_h826be896__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_aad__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_aad___024root(Vtb_aad__Syms* symsp, const char* v__name);
    ~Vtb_aad___024root();
    VL_UNCOPYABLE(Vtb_aad___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

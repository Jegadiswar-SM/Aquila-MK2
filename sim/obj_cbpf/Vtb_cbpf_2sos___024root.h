// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_cbpf_2sos.h for the primary calling header

#ifndef VERILATED_VTB_CBPF_2SOS___024ROOT_H_
#define VERILATED_VTB_CBPF_2SOS___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_cbpf_2sos__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_cbpf_2sos___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_cbpf_2sos__DOT__clk;
    CData/*0:0*/ tb_cbpf_2sos__DOT__rst_n;
    CData/*0:0*/ tb_cbpf_2sos__DOT__x_valid;
    CData/*3:0*/ tb_cbpf_2sos__DOT__s_axi_awaddr;
    CData/*0:0*/ tb_cbpf_2sos__DOT__s_axi_awvalid;
    CData/*0:0*/ tb_cbpf_2sos__DOT__s_axi_wvalid;
    CData/*0:0*/ tb_cbpf_2sos__DOT__s_axi_awready;
    CData/*0:0*/ tb_cbpf_2sos__DOT__s_axi_wready;
    CData/*0:0*/ tb_cbpf_2sos__DOT__y_valid;
    CData/*0:0*/ tb_cbpf_2sos__DOT__clip_s1;
    CData/*0:0*/ tb_cbpf_2sos__DOT__clip_s2;
    CData/*0:0*/ tb_cbpf_2sos__DOT__dut__DOT__bypass_reg;
    CData/*0:0*/ tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg1;
    CData/*0:0*/ tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg2;
    CData/*0:0*/ tb_cbpf_2sos__DOT__dut__DOT__s2_valid_stg1;
    CData/*0:0*/ tb_cbpf_2sos__DOT__dut__DOT__s2_valid_stg2;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_cbpf_2sos__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_cbpf_2sos__DOT__rst_n__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ tb_cbpf_2sos__DOT__x_in;
    SData/*15:0*/ tb_cbpf_2sos__DOT__y_out;
    SData/*15:0*/ tb_cbpf_2sos__DOT__dut__DOT__y_s1_trunc;
    SData/*15:0*/ tb_cbpf_2sos__DOT__dut__DOT__y_s2_trunc;
    IData/*31:0*/ tb_cbpf_2sos__DOT__s_axi_wdata;
    IData/*31:0*/ tb_cbpf_2sos__DOT__pass;
    IData/*31:0*/ tb_cbpf_2sos__DOT__fail;
    IData/*31:0*/ tb_cbpf_2sos__DOT__dut__DOT__w1_s1;
    IData/*31:0*/ tb_cbpf_2sos__DOT__dut__DOT__w2_s1;
    IData/*31:0*/ tb_cbpf_2sos__DOT__dut__DOT__w0_s1;
    IData/*31:0*/ tb_cbpf_2sos__DOT__dut__DOT__y_s1;
    IData/*31:0*/ tb_cbpf_2sos__DOT__dut__DOT__mul_a1_s1;
    IData/*31:0*/ tb_cbpf_2sos__DOT__dut__DOT__mul_a2_s1;
    IData/*31:0*/ tb_cbpf_2sos__DOT__dut__DOT__mul_b0_s1;
    IData/*31:0*/ tb_cbpf_2sos__DOT__dut__DOT__mul_b1_s1;
    IData/*31:0*/ tb_cbpf_2sos__DOT__dut__DOT__mul_b2_s1;
    IData/*31:0*/ tb_cbpf_2sos__DOT__dut__DOT__w1_s2;
    IData/*31:0*/ tb_cbpf_2sos__DOT__dut__DOT__w2_s2;
    IData/*31:0*/ tb_cbpf_2sos__DOT__dut__DOT__w0_s2;
    IData/*31:0*/ tb_cbpf_2sos__DOT__dut__DOT__y_s2;
    IData/*31:0*/ tb_cbpf_2sos__DOT__dut__DOT__mul_a1_s2;
    IData/*31:0*/ tb_cbpf_2sos__DOT__dut__DOT__mul_a2_s2;
    IData/*31:0*/ tb_cbpf_2sos__DOT__dut__DOT__mul_b0_s2;
    IData/*31:0*/ tb_cbpf_2sos__DOT__dut__DOT__mul_b1_s2;
    IData/*31:0*/ tb_cbpf_2sos__DOT__dut__DOT__mul_b2_s2;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h34e2bf4d__0;
    VlTriggerScheduler __VtrigSched_h34e2bf0c__0;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_cbpf_2sos__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_cbpf_2sos___024root(Vtb_cbpf_2sos__Syms* symsp, const char* v__name);
    ~Vtb_cbpf_2sos___024root();
    VL_UNCOPYABLE(Vtb_cbpf_2sos___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

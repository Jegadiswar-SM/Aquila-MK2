// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_rcim.h for the primary calling header

#ifndef VERILATED_VTB_RCIM___024ROOT_H_
#define VERILATED_VTB_RCIM___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_rcim__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_rcim___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_rcim__DOT__clk;
    CData/*0:0*/ tb_rcim__DOT__rst_n;
    CData/*0:0*/ tb_rcim__DOT__samples_valid;
    CData/*4:0*/ tb_rcim__DOT__s_axi_awaddr;
    CData/*0:0*/ tb_rcim__DOT__s_axi_awvalid;
    CData/*0:0*/ tb_rcim__DOT__s_axi_wvalid;
    CData/*0:0*/ tb_rcim__DOT__s_axi_awready;
    CData/*0:0*/ tb_rcim__DOT__s_axi_wready;
    CData/*0:0*/ tb_rcim__DOT__ref_channel_fault;
    CData/*3:0*/ tb_rcim__DOT__dut__DOT__ratio_shift;
    CData/*7:0*/ tb_rcim__DOT__dut__DOT__fault_cnt;
    CData/*7:0*/ tb_rcim__DOT__dut__DOT__recover_cnt;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_rcim__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_rcim__DOT__rst_n__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ tb_rcim__DOT__d_in;
    SData/*15:0*/ tb_rcim__DOT__x_in;
    SData/*15:0*/ tb_rcim__DOT__x_out_muxed;
    SData/*15:0*/ tb_rcim__DOT__dut__DOT__corr_threshold;
    SData/*15:0*/ tb_rcim__DOT__dut__DOT__recip_approx;
    IData/*31:0*/ tb_rcim__DOT__s_axi_wdata;
    IData/*31:0*/ tb_rcim__DOT__pass;
    IData/*31:0*/ tb_rcim__DOT__fail;
    IData/*31:0*/ tb_rcim__DOT__dut__DOT__mul_dx;
    IData/*31:0*/ tb_rcim__DOT__dut__DOT__mul_xx;
    IData/*31:0*/ tb_rcim__DOT__dut__DOT__nr_term;
    IData/*31:0*/ tb_rcim__DOT__dut__DOT__nr_prod;
    IData/*31:0*/ tb_rcim__DOT__dut__DOT__mul_nr1;
    IData/*31:0*/ tb_rcim__DOT__dut__DOT__mul_nr2;
    IData/*31:0*/ tb_rcim__DOT__dut__DOT__norm_corr_prod;
    IData/*31:0*/ tb_rcim__DOT__dut__DOT__mul_norm;
    IData/*31:0*/ __VactIterCount;
    QData/*39:0*/ tb_rcim__DOT__dut__DOT__corr_acc;
    QData/*39:0*/ tb_rcim__DOT__dut__DOT__ref_power_acc;
    VlUnpacked<SData/*15:0*/, 16> tb_rcim__DOT__dut__DOT__lutram;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hbcae1c96__0;
    VlTriggerScheduler __VtrigSched_hbcae1d57__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_rcim__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_rcim___024root(Vtb_rcim__Syms* symsp, const char* v__name);
    ~Vtb_rcim___024root();
    VL_UNCOPYABLE(Vtb_rcim___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

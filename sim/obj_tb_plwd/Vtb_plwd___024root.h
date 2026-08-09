// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_plwd.h for the primary calling header

#ifndef VERILATED_VTB_PLWD___024ROOT_H_
#define VERILATED_VTB_PLWD___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_plwd__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_plwd___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_plwd__DOT__clk;
    CData/*0:0*/ tb_plwd__DOT__rst_n;
    CData/*0:0*/ tb_plwd__DOT__m_axis_tvalid;
    CData/*3:0*/ tb_plwd__DOT__s_axi_araddr;
    CData/*0:0*/ tb_plwd__DOT__s_axi_arvalid;
    CData/*0:0*/ tb_plwd__DOT__s_axi_rvalid;
    CData/*3:0*/ tb_plwd__DOT__s_axi_awaddr;
    CData/*0:0*/ tb_plwd__DOT__s_axi_awvalid;
    CData/*0:0*/ tb_plwd__DOT__s_axi_wvalid;
    CData/*0:0*/ tb_plwd__DOT__s_axi_awready;
    CData/*0:0*/ tb_plwd__DOT__s_axi_wready;
    CData/*0:0*/ tb_plwd__DOT__pipeline_srst;
    CData/*0:0*/ tb_plwd__DOT__irq_fault;
    CData/*0:0*/ tb_plwd__DOT__dut__DOT__pipeline_stall_fault;
    CData/*4:0*/ tb_plwd__DOT__dut__DOT__stuck_cnt;
    CData/*0:0*/ tb_plwd__DOT__dut__DOT__output_stuck_fault;
    CData/*1:0*/ tb_plwd__DOT__dut__DOT__fault_type_reg;
    CData/*7:0*/ tb_plwd__DOT__dut__DOT__fault_count_reg;
    CData/*1:0*/ tb_plwd__DOT__dut__DOT__rcv_state;
    CData/*2:0*/ tb_plwd__DOT__dut__DOT__drain_cnt;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_plwd__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_plwd__DOT__rst_n__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ tb_plwd__DOT__m_axis_tdata;
    SData/*15:0*/ tb_plwd__DOT__dut__DOT__timeout_cnt;
    SData/*15:0*/ tb_plwd__DOT__dut__DOT__last_sample;
    IData/*31:0*/ tb_plwd__DOT__s_axi_rdata;
    IData/*31:0*/ tb_plwd__DOT__s_axi_wdata;
    IData/*31:0*/ tb_plwd__DOT__pass;
    IData/*31:0*/ tb_plwd__DOT__fail;
    IData/*31:0*/ tb_plwd__DOT__dut__DOT__global_sample_cnt;
    IData/*31:0*/ tb_plwd__DOT__dut__DOT__fault_sample_cnt;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 4> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h5a37603f__0;
    VlTriggerScheduler __VtrigSched_h5a375ffe__0;
    VlTriggerVec<4> __VactTriggered;
    VlTriggerVec<4> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_plwd__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_plwd___024root(Vtb_plwd__Syms* symsp, const char* v__name);
    ~Vtb_plwd___024root();
    VL_UNCOPYABLE(Vtb_plwd___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

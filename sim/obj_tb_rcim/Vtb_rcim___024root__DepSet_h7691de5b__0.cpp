// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rcim.h for the primary calling header

#include "Vtb_rcim__pch.h"
#include "Vtb_rcim___024root.h"

VL_ATTR_COLD void Vtb_rcim___024root___eval_initial__TOP(Vtb_rcim___024root* vlSelf);
VlCoroutine Vtb_rcim___024root___eval_initial__TOP__Vtiming__0(Vtb_rcim___024root* vlSelf);
VlCoroutine Vtb_rcim___024root___eval_initial__TOP__Vtiming__1(Vtb_rcim___024root* vlSelf);
VlCoroutine Vtb_rcim___024root___eval_initial__TOP__Vtiming__2(Vtb_rcim___024root* vlSelf);

void Vtb_rcim___024root___eval_initial(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___eval_initial\n"); );
    // Body
    Vtb_rcim___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vtb_rcim___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_rcim___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_rcim___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_rcim__DOT__clk__0 
        = vlSelf->tb_rcim__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_rcim__DOT__rst_n__0 
        = vlSelf->tb_rcim__DOT__rst_n;
}

VL_INLINE_OPT VlCoroutine Vtb_rcim___024root___eval_initial__TOP__Vtiming__0(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    IData/*31:0*/ tb_rcim__DOT____Vrepeat2;
    tb_rcim__DOT____Vrepeat2 = 0;
    // Body
    VL_WRITEF_NX("===== tb_rcim: start =====\n",0);
    vlSelf->tb_rcim__DOT__pass = 0U;
    vlSelf->tb_rcim__DOT__fail = 0U;
    vlSelf->tb_rcim__DOT__rst_n = 0U;
    vlSelf->tb_rcim__DOT__samples_valid = 0U;
    vlSelf->tb_rcim__DOT__d_in = 0U;
    vlSelf->tb_rcim__DOT__x_in = 0U;
    vlSelf->tb_rcim__DOT__s_axi_awaddr = 0U;
    vlSelf->tb_rcim__DOT__s_axi_awvalid = 0U;
    vlSelf->tb_rcim__DOT__s_axi_wdata = 0U;
    vlSelf->tb_rcim__DOT__s_axi_wvalid = 0U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       49);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       49);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       49);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       49);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       49);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       49);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       49);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       49);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       49);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       49);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1d57__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_rcim__DOT__rst_n = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       51);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_rcim__DOT__d_in = 0x4000U;
    vlSelf->tb_rcim__DOT__x_in = 0x4000U;
    vlSelf->tb_rcim__DOT__samples_valid = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       55);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_rcim__DOT__ref_channel_fault) {
        VL_WRITEF_NX("FAIL: unexpected fault\n",0);
        vlSelf->tb_rcim__DOT__fail = ((IData)(1U) + vlSelf->tb_rcim__DOT__fail);
    } else {
        VL_WRITEF_NX("PASS: no fault with correlated channels\n",0);
        vlSelf->tb_rcim__DOT__pass = ((IData)(1U) + vlSelf->tb_rcim__DOT__pass);
    }
    vlSelf->tb_rcim__DOT__d_in = 0x4000U;
    vlSelf->tb_rcim__DOT__x_in = 0U;
    vlSelf->tb_rcim__DOT__samples_valid = 1U;
    tb_rcim__DOT____Vrepeat2 = 0xc8U;
    while (VL_LTS_III(32, 0U, tb_rcim__DOT____Vrepeat2)) {
        co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_rcim.clk)", 
                                                           "tb/tb_rcim.v", 
                                                           64);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        tb_rcim__DOT____Vrepeat2 = (tb_rcim__DOT____Vrepeat2 
                                    - (IData)(1U));
    }
    if (vlSelf->tb_rcim__DOT__ref_channel_fault) {
        VL_WRITEF_NX("PASS: fault detected with uncorrelated reference\n",0);
        vlSelf->tb_rcim__DOT__pass = ((IData)(1U) + vlSelf->tb_rcim__DOT__pass);
    } else {
        VL_WRITEF_NX("FAIL: expected fault not detected\n",0);
        vlSelf->tb_rcim__DOT__fail = ((IData)(1U) + vlSelf->tb_rcim__DOT__fail);
    }
    if ((0U == (IData)(vlSelf->tb_rcim__DOT__x_out_muxed))) {
        VL_WRITEF_NX("PASS: x_out_muxed = 0 during fault\n",0);
        vlSelf->tb_rcim__DOT__pass = ((IData)(1U) + vlSelf->tb_rcim__DOT__pass);
    } else {
        VL_WRITEF_NX("FAIL: x_out_muxed != 0 during fault (0x%04x)\n",0,
                     16,vlSelf->tb_rcim__DOT__x_out_muxed);
        vlSelf->tb_rcim__DOT__fail = ((IData)(1U) + vlSelf->tb_rcim__DOT__fail);
    }
    vlSelf->tb_rcim__DOT__samples_valid = 0U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbcae1c96__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_rcim.clk)", 
                                                       "tb/tb_rcim.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("===== tb_rcim: %0d pass, %0d fail =====\n",0,
                 32,vlSelf->tb_rcim__DOT__pass,32,vlSelf->tb_rcim__DOT__fail);
    if ((0U != vlSelf->tb_rcim__DOT__fail)) {
        VL_WRITEF_NX("RESULT: FAIL\n",0);
    } else {
        VL_WRITEF_NX("RESULT: PASS\n",0);
    }
    VL_FINISH_MT("tb/tb_rcim.v", 84, "");
    vlSelf->__Vm_traceActivity[2U] = 1U;
}

VL_INLINE_OPT VlCoroutine Vtb_rcim___024root___eval_initial__TOP__Vtiming__1(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0x1dcd6500ULL, 
                                       nullptr, "tb/tb_rcim.v", 
                                       87);
    VL_WRITEF_NX("TIMEOUT\n",0);
    VL_FINISH_MT("tb/tb_rcim.v", 87, "");
}

VL_INLINE_OPT VlCoroutine Vtb_rcim___024root___eval_initial__TOP__Vtiming__2(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "tb/tb_rcim.v", 
                                           36);
        vlSelf->tb_rcim__DOT__clk = (1U & (~ (IData)(vlSelf->tb_rcim__DOT__clk)));
    }
}

void Vtb_rcim___024root___eval_act(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___eval_act\n"); );
}

void Vtb_rcim___024root___nba_sequent__TOP__0(Vtb_rcim___024root* vlSelf);

void Vtb_rcim___024root___eval_nba(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_rcim___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vtb_rcim___024root___nba_sequent__TOP__0(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___nba_sequent__TOP__0\n"); );
    // Init
    QData/*39:0*/ __Vdly__tb_rcim__DOT__dut__DOT__corr_acc;
    __Vdly__tb_rcim__DOT__dut__DOT__corr_acc = 0;
    QData/*39:0*/ __Vdly__tb_rcim__DOT__dut__DOT__ref_power_acc;
    __Vdly__tb_rcim__DOT__dut__DOT__ref_power_acc = 0;
    CData/*7:0*/ __Vdly__tb_rcim__DOT__dut__DOT__fault_cnt;
    __Vdly__tb_rcim__DOT__dut__DOT__fault_cnt = 0;
    CData/*7:0*/ __Vdly__tb_rcim__DOT__dut__DOT__recover_cnt;
    __Vdly__tb_rcim__DOT__dut__DOT__recover_cnt = 0;
    CData/*0:0*/ __Vdly__tb_rcim__DOT__ref_channel_fault;
    __Vdly__tb_rcim__DOT__ref_channel_fault = 0;
    CData/*0:0*/ __VdlySet__tb_rcim__DOT__dut__DOT__lutram__v0;
    __VdlySet__tb_rcim__DOT__dut__DOT__lutram__v0 = 0;
    // Body
    __VdlySet__tb_rcim__DOT__dut__DOT__lutram__v0 = 0U;
    __Vdly__tb_rcim__DOT__dut__DOT__corr_acc = vlSelf->tb_rcim__DOT__dut__DOT__corr_acc;
    __Vdly__tb_rcim__DOT__dut__DOT__ref_power_acc = vlSelf->tb_rcim__DOT__dut__DOT__ref_power_acc;
    __Vdly__tb_rcim__DOT__ref_channel_fault = vlSelf->tb_rcim__DOT__ref_channel_fault;
    __Vdly__tb_rcim__DOT__dut__DOT__recover_cnt = vlSelf->tb_rcim__DOT__dut__DOT__recover_cnt;
    __Vdly__tb_rcim__DOT__dut__DOT__fault_cnt = vlSelf->tb_rcim__DOT__dut__DOT__fault_cnt;
    if (vlSelf->tb_rcim__DOT__rst_n) {
        if (vlSelf->tb_rcim__DOT__samples_valid) {
            __Vdly__tb_rcim__DOT__dut__DOT__corr_acc 
                = (0xffffffffffULL & ((vlSelf->tb_rcim__DOT__dut__DOT__corr_acc 
                                       - VL_SHIFTRS_QQI(40,40,4, vlSelf->tb_rcim__DOT__dut__DOT__corr_acc, (IData)(vlSelf->tb_rcim__DOT__dut__DOT__ratio_shift))) 
                                      + VL_EXTENDS_QI(40,32, vlSelf->tb_rcim__DOT__dut__DOT__mul_dx)));
            __Vdly__tb_rcim__DOT__dut__DOT__ref_power_acc 
                = (0xffffffffffULL & ((vlSelf->tb_rcim__DOT__dut__DOT__ref_power_acc 
                                       - VL_SHIFTRS_QQI(40,40,4, vlSelf->tb_rcim__DOT__dut__DOT__ref_power_acc, (IData)(vlSelf->tb_rcim__DOT__dut__DOT__ratio_shift))) 
                                      + VL_EXTENDS_QI(40,32, vlSelf->tb_rcim__DOT__dut__DOT__mul_xx)));
        }
    } else {
        __Vdly__tb_rcim__DOT__dut__DOT__corr_acc = 0ULL;
        __Vdly__tb_rcim__DOT__dut__DOT__ref_power_acc = 0ULL;
    }
    if ((1U & (~ (IData)(vlSelf->tb_rcim__DOT__rst_n)))) {
        __VdlySet__tb_rcim__DOT__dut__DOT__lutram__v0 = 1U;
        vlSelf->tb_rcim__DOT__dut__DOT__ratio_shift = 5U;
    }
    if (vlSelf->tb_rcim__DOT__rst_n) {
        if (vlSelf->tb_rcim__DOT__samples_valid) {
            if (((0xffffU & (vlSelf->tb_rcim__DOT__dut__DOT__mul_norm 
                             >> 0xfU)) < (IData)(vlSelf->tb_rcim__DOT__dut__DOT__corr_threshold))) {
                __Vdly__tb_rcim__DOT__dut__DOT__fault_cnt 
                    = (0xffU & ((0xffU == (IData)(vlSelf->tb_rcim__DOT__dut__DOT__fault_cnt))
                                 ? (IData)(vlSelf->tb_rcim__DOT__dut__DOT__fault_cnt)
                                 : ((IData)(1U) + (IData)(vlSelf->tb_rcim__DOT__dut__DOT__fault_cnt))));
                __Vdly__tb_rcim__DOT__dut__DOT__recover_cnt = 0U;
                if ((0x7fU <= (IData)(vlSelf->tb_rcim__DOT__dut__DOT__fault_cnt))) {
                    __Vdly__tb_rcim__DOT__ref_channel_fault = 1U;
                }
            } else {
                if (vlSelf->tb_rcim__DOT__ref_channel_fault) {
                    __Vdly__tb_rcim__DOT__dut__DOT__recover_cnt 
                        = (0xffU & ((0xffU == (IData)(vlSelf->tb_rcim__DOT__dut__DOT__recover_cnt))
                                     ? (IData)(vlSelf->tb_rcim__DOT__dut__DOT__recover_cnt)
                                     : ((IData)(1U) 
                                        + (IData)(vlSelf->tb_rcim__DOT__dut__DOT__recover_cnt))));
                    if ((0xfU <= (IData)(vlSelf->tb_rcim__DOT__dut__DOT__recover_cnt))) {
                        __Vdly__tb_rcim__DOT__ref_channel_fault = 0U;
                    }
                }
                __Vdly__tb_rcim__DOT__dut__DOT__fault_cnt = 0U;
            }
            vlSelf->tb_rcim__DOT__dut__DOT__mul_dx 
                = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_rcim__DOT__d_in)), 
                              VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_rcim__DOT__x_in)));
            vlSelf->tb_rcim__DOT__dut__DOT__mul_xx 
                = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_rcim__DOT__x_in)), 
                              VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_rcim__DOT__x_in)));
        }
        vlSelf->tb_rcim__DOT__x_out_muxed = ((IData)(vlSelf->tb_rcim__DOT__ref_channel_fault)
                                              ? 0U : (IData)(vlSelf->tb_rcim__DOT__x_in));
        vlSelf->tb_rcim__DOT__s_axi_wready = 0U;
        vlSelf->tb_rcim__DOT__s_axi_awready = 0U;
        if ((((IData)(vlSelf->tb_rcim__DOT__s_axi_awvalid) 
              & (IData)(vlSelf->tb_rcim__DOT__s_axi_wvalid)) 
             & (0U == (IData)(vlSelf->tb_rcim__DOT__s_axi_awaddr)))) {
            vlSelf->tb_rcim__DOT__s_axi_wready = 1U;
            vlSelf->tb_rcim__DOT__s_axi_awready = 1U;
            vlSelf->tb_rcim__DOT__dut__DOT__corr_threshold 
                = (0xffffU & vlSelf->tb_rcim__DOT__s_axi_wdata);
        }
        vlSelf->tb_rcim__DOT__dut__DOT__mul_norm = 
            VL_MULS_III(32, VL_EXTENDS_II(32,16, (0xffffU 
                                                  & ((1U 
                                                      & (IData)(
                                                                (vlSelf->tb_rcim__DOT__dut__DOT__corr_acc 
                                                                 >> 0x1fU)))
                                                      ? 
                                                     ((IData)(1U) 
                                                      + 
                                                      (~ (IData)(
                                                                 (vlSelf->tb_rcim__DOT__dut__DOT__corr_acc 
                                                                  >> 0xfU))))
                                                      : (IData)(
                                                                (vlSelf->tb_rcim__DOT__dut__DOT__corr_acc 
                                                                 >> 0xfU))))), 
                        VL_EXTENDS_II(32,16, (0xffffU 
                                              & (vlSelf->tb_rcim__DOT__dut__DOT__mul_nr2 
                                                 >> 0xfU))));
        vlSelf->tb_rcim__DOT__dut__DOT__mul_nr2 = VL_MULS_III(32, 
                                                              VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_rcim__DOT__dut__DOT__recip_approx)), 
                                                              VL_EXTENDS_II(32,17, 
                                                                            (0x1ffffU 
                                                                             & ((IData)(0xffffU) 
                                                                                - 
                                                                                (0xffffU 
                                                                                & (vlSelf->tb_rcim__DOT__dut__DOT__mul_nr1 
                                                                                >> 0xfU))))));
        vlSelf->tb_rcim__DOT__dut__DOT__mul_nr1 = VL_MULS_III(32, 
                                                              VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_rcim__DOT__dut__DOT__recip_approx)), 
                                                              VL_EXTENDS_II(32,16, 
                                                                            (0xffffU 
                                                                             & (IData)(
                                                                                (vlSelf->tb_rcim__DOT__dut__DOT__ref_power_acc 
                                                                                >> 0xfU)))));
    } else {
        __Vdly__tb_rcim__DOT__dut__DOT__fault_cnt = 0U;
        __Vdly__tb_rcim__DOT__dut__DOT__recover_cnt = 0U;
        __Vdly__tb_rcim__DOT__ref_channel_fault = 0U;
        vlSelf->tb_rcim__DOT__x_out_muxed = 0U;
        vlSelf->tb_rcim__DOT__s_axi_wready = 0U;
        vlSelf->tb_rcim__DOT__s_axi_awready = 0U;
        vlSelf->tb_rcim__DOT__dut__DOT__mul_dx = 0U;
        vlSelf->tb_rcim__DOT__dut__DOT__mul_xx = 0U;
        vlSelf->tb_rcim__DOT__dut__DOT__corr_threshold = 0x1999U;
        vlSelf->tb_rcim__DOT__dut__DOT__mul_norm = 0U;
        vlSelf->tb_rcim__DOT__dut__DOT__mul_nr2 = 0U;
        vlSelf->tb_rcim__DOT__dut__DOT__mul_nr1 = 0U;
    }
    if (__VdlySet__tb_rcim__DOT__dut__DOT__lutram__v0) {
        vlSelf->tb_rcim__DOT__dut__DOT__lutram[0U] = 0xffffU;
        vlSelf->tb_rcim__DOT__dut__DOT__lutram[1U] = 0x7fffU;
        vlSelf->tb_rcim__DOT__dut__DOT__lutram[2U] = 0x3fffU;
        vlSelf->tb_rcim__DOT__dut__DOT__lutram[3U] = 0x2aaaU;
        vlSelf->tb_rcim__DOT__dut__DOT__lutram[4U] = 0x2000U;
        vlSelf->tb_rcim__DOT__dut__DOT__lutram[5U] = 0x1999U;
        vlSelf->tb_rcim__DOT__dut__DOT__lutram[6U] = 0x1555U;
        vlSelf->tb_rcim__DOT__dut__DOT__lutram[7U] = 0x1249U;
        vlSelf->tb_rcim__DOT__dut__DOT__lutram[8U] = 0x1000U;
        vlSelf->tb_rcim__DOT__dut__DOT__lutram[9U] = 0xe38U;
        vlSelf->tb_rcim__DOT__dut__DOT__lutram[0xaU] = 0xcccU;
        vlSelf->tb_rcim__DOT__dut__DOT__lutram[0xbU] = 0xba2U;
        vlSelf->tb_rcim__DOT__dut__DOT__lutram[0xcU] = 0xaaaU;
        vlSelf->tb_rcim__DOT__dut__DOT__lutram[0xdU] = 0x9d8U;
        vlSelf->tb_rcim__DOT__dut__DOT__lutram[0xeU] = 0x924U;
        vlSelf->tb_rcim__DOT__dut__DOT__lutram[0xfU] = 0x888U;
    }
    vlSelf->tb_rcim__DOT__dut__DOT__fault_cnt = __Vdly__tb_rcim__DOT__dut__DOT__fault_cnt;
    vlSelf->tb_rcim__DOT__dut__DOT__recover_cnt = __Vdly__tb_rcim__DOT__dut__DOT__recover_cnt;
    vlSelf->tb_rcim__DOT__ref_channel_fault = __Vdly__tb_rcim__DOT__ref_channel_fault;
    vlSelf->tb_rcim__DOT__dut__DOT__corr_acc = __Vdly__tb_rcim__DOT__dut__DOT__corr_acc;
    vlSelf->tb_rcim__DOT__dut__DOT__ref_power_acc = __Vdly__tb_rcim__DOT__dut__DOT__ref_power_acc;
    vlSelf->tb_rcim__DOT__dut__DOT__recip_approx = 
        vlSelf->tb_rcim__DOT__dut__DOT__lutram[(0xfU 
                                                & (IData)(
                                                          (vlSelf->tb_rcim__DOT__dut__DOT__ref_power_acc 
                                                           >> 0x23U)))];
}

void Vtb_rcim___024root___timing_resume(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___timing_resume\n"); );
    // Body
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_hbcae1c96__0.resume("@(posedge tb_rcim.clk)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_hbcae1d57__0.resume("@(negedge tb_rcim.clk)");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_rcim___024root___timing_commit(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___timing_commit\n"); );
    // Body
    if ((! (2ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_hbcae1c96__0.commit("@(posedge tb_rcim.clk)");
    }
    if ((! (4ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_hbcae1d57__0.commit("@(negedge tb_rcim.clk)");
    }
}

void Vtb_rcim___024root___eval_triggers__act(Vtb_rcim___024root* vlSelf);

bool Vtb_rcim___024root___eval_phase__act(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_rcim___024root___eval_triggers__act(vlSelf);
    Vtb_rcim___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_rcim___024root___timing_resume(vlSelf);
        Vtb_rcim___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_rcim___024root___eval_phase__nba(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_rcim___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rcim___024root___dump_triggers__nba(Vtb_rcim___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rcim___024root___dump_triggers__act(Vtb_rcim___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_rcim___024root___eval(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_rcim___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_rcim.v", 4, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_rcim___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/tb_rcim.v", 4, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_rcim___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_rcim___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_rcim___024root___eval_debug_assertions(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG

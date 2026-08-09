// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_plwd.h for the primary calling header

#include "Vtb_plwd__pch.h"
#include "Vtb_plwd___024root.h"

VL_ATTR_COLD void Vtb_plwd___024root___eval_initial__TOP(Vtb_plwd___024root* vlSelf);
VlCoroutine Vtb_plwd___024root___eval_initial__TOP__Vtiming__0(Vtb_plwd___024root* vlSelf);
VlCoroutine Vtb_plwd___024root___eval_initial__TOP__Vtiming__1(Vtb_plwd___024root* vlSelf);
VlCoroutine Vtb_plwd___024root___eval_initial__TOP__Vtiming__2(Vtb_plwd___024root* vlSelf);

void Vtb_plwd___024root___eval_initial(Vtb_plwd___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root___eval_initial\n"); );
    // Body
    Vtb_plwd___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vtb_plwd___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_plwd___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_plwd___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_plwd__DOT__clk__0 
        = vlSelf->tb_plwd__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_plwd__DOT__rst_n__0 
        = vlSelf->tb_plwd__DOT__rst_n;
}

VL_INLINE_OPT VlCoroutine Vtb_plwd___024root___eval_initial__TOP__Vtiming__0(Vtb_plwd___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    VL_WRITEF_NX("===== tb_plwd: start =====\n",0);
    vlSelf->tb_plwd__DOT__pass = 0U;
    vlSelf->tb_plwd__DOT__fail = 0U;
    vlSelf->tb_plwd__DOT__rst_n = 1U;
    vlSelf->tb_plwd__DOT__m_axis_tvalid = 0U;
    vlSelf->tb_plwd__DOT__m_axis_tdata = 0U;
    vlSelf->tb_plwd__DOT__s_axi_araddr = 0U;
    vlSelf->tb_plwd__DOT__s_axi_arvalid = 0U;
    vlSelf->tb_plwd__DOT__s_axi_awaddr = 0U;
    vlSelf->tb_plwd__DOT__s_axi_awvalid = 0U;
    vlSelf->tb_plwd__DOT__s_axi_wdata = 0U;
    vlSelf->tb_plwd__DOT__s_axi_wvalid = 0U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_plwd__DOT__rst_n = 0U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       61);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       61);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       61);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       61);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       61);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a375ffe__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       62);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_plwd__DOT__rst_n = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       63);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_plwd__DOT__m_axis_tvalid = 1U;
    vlSelf->tb_plwd__DOT__m_axis_tdata = 0x1000U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       67);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       67);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       67);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       67);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       67);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       67);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       67);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       67);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       67);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       67);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_plwd__DOT__m_axis_tdata = 0x2000U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       70);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       70);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       70);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       70);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       70);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       70);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       70);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       70);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       70);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       70);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if ((1U & ((~ (IData)(vlSelf->tb_plwd__DOT__pipeline_srst)) 
               & (~ (IData)(vlSelf->tb_plwd__DOT__irq_fault))))) {
        VL_WRITEF_NX("PASS: no false fault with valid stream\n",0);
        vlSelf->tb_plwd__DOT__pass = ((IData)(1U) + vlSelf->tb_plwd__DOT__pass);
    } else {
        VL_WRITEF_NX("FAIL: spurious fault\n",0);
        vlSelf->tb_plwd__DOT__fail = ((IData)(1U) + vlSelf->tb_plwd__DOT__fail);
    }
    vlSelf->tb_plwd__DOT__m_axis_tvalid = 0U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       79);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_plwd__DOT__pipeline_srst) {
        VL_WRITEF_NX("PASS: stall detected, pipeline_srst asserted\n",0);
        vlSelf->tb_plwd__DOT__pass = ((IData)(1U) + vlSelf->tb_plwd__DOT__pass);
    } else {
        VL_WRITEF_NX("FAIL: stall not detected\n",0);
        vlSelf->tb_plwd__DOT__fail = ((IData)(1U) + vlSelf->tb_plwd__DOT__fail);
    }
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       87);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       87);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       87);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       87);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       87);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       87);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       87);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       87);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       87);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       87);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       87);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       87);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       87);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       87);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       87);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       87);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       87);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       87);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       87);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       87);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_plwd__DOT__pipeline_srst) {
        VL_WRITEF_NX("FAIL: pipeline_srst stuck high\n",0);
        vlSelf->tb_plwd__DOT__fail = ((IData)(1U) + vlSelf->tb_plwd__DOT__fail);
    } else {
        VL_WRITEF_NX("PASS: pipeline_srst deasserted after recovery\n",0);
        vlSelf->tb_plwd__DOT__pass = ((IData)(1U) + vlSelf->tb_plwd__DOT__pass);
    }
    co_await vlSelf->__VtrigSched_h5a375ffe__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       95);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_plwd__DOT__s_axi_araddr = 0U;
    vlSelf->tb_plwd__DOT__s_axi_arvalid = 1U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       97);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_plwd__DOT__s_axi_arvalid = 0U;
    co_await vlSelf->__VtrigSched_h5a37603f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_plwd.clk)", 
                                                       "tb/tb_plwd.v", 
                                                       99);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if ((1U == (3U & vlSelf->tb_plwd__DOT__s_axi_rdata))) {
        VL_WRITEF_NX("PASS: fault_type_reg = %b (stall)\n",0,
                     2,(3U & vlSelf->tb_plwd__DOT__s_axi_rdata));
        vlSelf->tb_plwd__DOT__pass = ((IData)(1U) + vlSelf->tb_plwd__DOT__pass);
    } else {
        VL_WRITEF_NX("FAIL: expected fault_type=01 got %b\n",0,
                     2,(3U & vlSelf->tb_plwd__DOT__s_axi_rdata));
        vlSelf->tb_plwd__DOT__fail = ((IData)(1U) + vlSelf->tb_plwd__DOT__fail);
    }
    VL_WRITEF_NX("===== tb_plwd: %0d pass, %0d fail =====\n",0,
                 32,vlSelf->tb_plwd__DOT__pass,32,vlSelf->tb_plwd__DOT__fail);
    if ((0U != vlSelf->tb_plwd__DOT__fail)) {
        VL_WRITEF_NX("RESULT: FAIL\n",0);
    } else {
        VL_WRITEF_NX("RESULT: PASS\n",0);
    }
    VL_FINISH_MT("tb/tb_plwd.v", 109, "");
    vlSelf->__Vm_traceActivity[2U] = 1U;
}

VL_INLINE_OPT VlCoroutine Vtb_plwd___024root___eval_initial__TOP__Vtiming__1(Vtb_plwd___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0xbebc200ULL, 
                                       nullptr, "tb/tb_plwd.v", 
                                       112);
    VL_WRITEF_NX("TIMEOUT\n",0);
    VL_FINISH_MT("tb/tb_plwd.v", 112, "");
}

VL_INLINE_OPT VlCoroutine Vtb_plwd___024root___eval_initial__TOP__Vtiming__2(Vtb_plwd___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "tb/tb_plwd.v", 
                                           45);
        vlSelf->tb_plwd__DOT__clk = (1U & (~ (IData)(vlSelf->tb_plwd__DOT__clk)));
    }
}

void Vtb_plwd___024root___eval_act(Vtb_plwd___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root___eval_act\n"); );
}

void Vtb_plwd___024root___nba_sequent__TOP__0(Vtb_plwd___024root* vlSelf);

void Vtb_plwd___024root___eval_nba(Vtb_plwd___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_plwd___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vtb_plwd___024root___nba_sequent__TOP__0(Vtb_plwd___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*15:0*/ __Vdly__tb_plwd__DOT__dut__DOT__timeout_cnt;
    __Vdly__tb_plwd__DOT__dut__DOT__timeout_cnt = 0;
    CData/*4:0*/ __Vdly__tb_plwd__DOT__dut__DOT__stuck_cnt;
    __Vdly__tb_plwd__DOT__dut__DOT__stuck_cnt = 0;
    IData/*31:0*/ __Vdly__tb_plwd__DOT__dut__DOT__global_sample_cnt;
    __Vdly__tb_plwd__DOT__dut__DOT__global_sample_cnt = 0;
    CData/*0:0*/ __Vdly__tb_plwd__DOT__pipeline_srst;
    __Vdly__tb_plwd__DOT__pipeline_srst = 0;
    CData/*1:0*/ __Vdly__tb_plwd__DOT__dut__DOT__rcv_state;
    __Vdly__tb_plwd__DOT__dut__DOT__rcv_state = 0;
    CData/*7:0*/ __Vdly__tb_plwd__DOT__dut__DOT__fault_count_reg;
    __Vdly__tb_plwd__DOT__dut__DOT__fault_count_reg = 0;
    // Body
    __Vdly__tb_plwd__DOT__dut__DOT__global_sample_cnt 
        = vlSelf->tb_plwd__DOT__dut__DOT__global_sample_cnt;
    __Vdly__tb_plwd__DOT__dut__DOT__timeout_cnt = vlSelf->tb_plwd__DOT__dut__DOT__timeout_cnt;
    __Vdly__tb_plwd__DOT__dut__DOT__stuck_cnt = vlSelf->tb_plwd__DOT__dut__DOT__stuck_cnt;
    __Vdly__tb_plwd__DOT__dut__DOT__rcv_state = vlSelf->tb_plwd__DOT__dut__DOT__rcv_state;
    __Vdly__tb_plwd__DOT__pipeline_srst = vlSelf->tb_plwd__DOT__pipeline_srst;
    __Vdly__tb_plwd__DOT__dut__DOT__fault_count_reg 
        = vlSelf->tb_plwd__DOT__dut__DOT__fault_count_reg;
    if (vlSelf->tb_plwd__DOT__rst_n) {
        vlSelf->tb_plwd__DOT__s_axi_rvalid = 0U;
        if (vlSelf->tb_plwd__DOT__s_axi_arvalid) {
            vlSelf->tb_plwd__DOT__s_axi_rvalid = 1U;
            vlSelf->tb_plwd__DOT__s_axi_rdata = ((0U 
                                                  == (IData)(vlSelf->tb_plwd__DOT__s_axi_araddr))
                                                  ? (IData)(vlSelf->tb_plwd__DOT__dut__DOT__fault_type_reg)
                                                  : 
                                                 ((4U 
                                                   == (IData)(vlSelf->tb_plwd__DOT__s_axi_araddr))
                                                   ? vlSelf->tb_plwd__DOT__dut__DOT__fault_sample_cnt
                                                   : 
                                                  ((8U 
                                                    == (IData)(vlSelf->tb_plwd__DOT__s_axi_araddr))
                                                    ? (IData)(vlSelf->tb_plwd__DOT__dut__DOT__fault_count_reg)
                                                    : 0U)));
        }
        vlSelf->tb_plwd__DOT__s_axi_wready = 0U;
        vlSelf->tb_plwd__DOT__s_axi_awready = 0U;
        if ((((IData)(vlSelf->tb_plwd__DOT__s_axi_awvalid) 
              & (IData)(vlSelf->tb_plwd__DOT__s_axi_wvalid)) 
             & (0xcU == (IData)(vlSelf->tb_plwd__DOT__s_axi_awaddr)))) {
            __Vdly__tb_plwd__DOT__dut__DOT__fault_count_reg = 0U;
            vlSelf->tb_plwd__DOT__s_axi_wready = 1U;
            vlSelf->tb_plwd__DOT__s_axi_awready = 1U;
            vlSelf->tb_plwd__DOT__dut__DOT__fault_type_reg = 0U;
        }
        if (((IData)(vlSelf->tb_plwd__DOT__s_axi_arvalid) 
             & (0U == (IData)(vlSelf->tb_plwd__DOT__s_axi_araddr)))) {
            vlSelf->tb_plwd__DOT__irq_fault = 0U;
        }
        if ((2U & (IData)(vlSelf->tb_plwd__DOT__dut__DOT__rcv_state))) {
            if ((1U & (IData)(vlSelf->tb_plwd__DOT__dut__DOT__rcv_state))) {
                __Vdly__tb_plwd__DOT__pipeline_srst = 0U;
                vlSelf->tb_plwd__DOT__irq_fault = 1U;
                __Vdly__tb_plwd__DOT__dut__DOT__rcv_state = 0U;
            } else {
                __Vdly__tb_plwd__DOT__pipeline_srst = 1U;
                if ((7U == (IData)(vlSelf->tb_plwd__DOT__dut__DOT__drain_cnt))) {
                    __Vdly__tb_plwd__DOT__dut__DOT__rcv_state = 3U;
                } else {
                    vlSelf->tb_plwd__DOT__dut__DOT__drain_cnt 
                        = (7U & ((IData)(1U) + (IData)(vlSelf->tb_plwd__DOT__dut__DOT__drain_cnt)));
                }
            }
        } else if ((1U & (IData)(vlSelf->tb_plwd__DOT__dut__DOT__rcv_state))) {
            __Vdly__tb_plwd__DOT__dut__DOT__fault_count_reg 
                = (0xffU & ((IData)(1U) + (IData)(vlSelf->tb_plwd__DOT__dut__DOT__fault_count_reg)));
            vlSelf->tb_plwd__DOT__dut__DOT__drain_cnt = 0U;
            vlSelf->tb_plwd__DOT__dut__DOT__fault_type_reg 
                = ((IData)(vlSelf->tb_plwd__DOT__dut__DOT__pipeline_stall_fault)
                    ? 1U : 2U);
            vlSelf->tb_plwd__DOT__dut__DOT__fault_sample_cnt 
                = vlSelf->tb_plwd__DOT__dut__DOT__global_sample_cnt;
            __Vdly__tb_plwd__DOT__pipeline_srst = 1U;
            __Vdly__tb_plwd__DOT__dut__DOT__rcv_state = 2U;
        } else {
            __Vdly__tb_plwd__DOT__pipeline_srst = 0U;
            vlSelf->tb_plwd__DOT__irq_fault = 0U;
            if (((IData)(vlSelf->tb_plwd__DOT__dut__DOT__pipeline_stall_fault) 
                 | (IData)(vlSelf->tb_plwd__DOT__dut__DOT__output_stuck_fault))) {
                __Vdly__tb_plwd__DOT__dut__DOT__rcv_state = 1U;
            }
        }
        if (vlSelf->tb_plwd__DOT__m_axis_tvalid) {
            __Vdly__tb_plwd__DOT__dut__DOT__global_sample_cnt 
                = ((IData)(1U) + vlSelf->tb_plwd__DOT__dut__DOT__global_sample_cnt);
            __Vdly__tb_plwd__DOT__dut__DOT__timeout_cnt = 8U;
            __Vdly__tb_plwd__DOT__dut__DOT__stuck_cnt 
                = (((IData)(vlSelf->tb_plwd__DOT__m_axis_tdata) 
                    == (IData)(vlSelf->tb_plwd__DOT__dut__DOT__last_sample))
                    ? (0x1fU & ((0x1fU == (IData)(vlSelf->tb_plwd__DOT__dut__DOT__stuck_cnt))
                                 ? (IData)(vlSelf->tb_plwd__DOT__dut__DOT__stuck_cnt)
                                 : ((IData)(1U) + (IData)(vlSelf->tb_plwd__DOT__dut__DOT__stuck_cnt))))
                    : 0U);
            if ((3U <= (IData)(vlSelf->tb_plwd__DOT__dut__DOT__stuck_cnt))) {
                vlSelf->tb_plwd__DOT__dut__DOT__output_stuck_fault = 1U;
            }
            vlSelf->tb_plwd__DOT__dut__DOT__last_sample 
                = vlSelf->tb_plwd__DOT__m_axis_tdata;
        } else if ((0U != (IData)(vlSelf->tb_plwd__DOT__dut__DOT__timeout_cnt))) {
            __Vdly__tb_plwd__DOT__dut__DOT__timeout_cnt 
                = (0xffffU & ((IData)(vlSelf->tb_plwd__DOT__dut__DOT__timeout_cnt) 
                              - (IData)(1U)));
        }
        if ((0U == (IData)(vlSelf->tb_plwd__DOT__dut__DOT__timeout_cnt))) {
            vlSelf->tb_plwd__DOT__dut__DOT__pipeline_stall_fault = 1U;
        } else if (vlSelf->tb_plwd__DOT__pipeline_srst) {
            vlSelf->tb_plwd__DOT__dut__DOT__pipeline_stall_fault = 0U;
        }
        if (vlSelf->tb_plwd__DOT__pipeline_srst) {
            vlSelf->tb_plwd__DOT__dut__DOT__output_stuck_fault = 0U;
            __Vdly__tb_plwd__DOT__dut__DOT__stuck_cnt = 0U;
        }
    } else {
        __Vdly__tb_plwd__DOT__dut__DOT__global_sample_cnt = 0U;
        vlSelf->tb_plwd__DOT__s_axi_rvalid = 0U;
        vlSelf->tb_plwd__DOT__s_axi_wready = 0U;
        vlSelf->tb_plwd__DOT__s_axi_awready = 0U;
        vlSelf->tb_plwd__DOT__s_axi_rdata = 0U;
        vlSelf->tb_plwd__DOT__dut__DOT__drain_cnt = 0U;
        __Vdly__tb_plwd__DOT__dut__DOT__fault_count_reg = 0U;
        __Vdly__tb_plwd__DOT__dut__DOT__rcv_state = 0U;
        __Vdly__tb_plwd__DOT__pipeline_srst = 0U;
        vlSelf->tb_plwd__DOT__irq_fault = 0U;
        vlSelf->tb_plwd__DOT__dut__DOT__fault_type_reg = 0U;
        vlSelf->tb_plwd__DOT__dut__DOT__fault_sample_cnt = 0U;
        __Vdly__tb_plwd__DOT__dut__DOT__timeout_cnt = 8U;
        vlSelf->tb_plwd__DOT__dut__DOT__pipeline_stall_fault = 0U;
        __Vdly__tb_plwd__DOT__dut__DOT__stuck_cnt = 0U;
        vlSelf->tb_plwd__DOT__dut__DOT__output_stuck_fault = 0U;
        vlSelf->tb_plwd__DOT__dut__DOT__last_sample = 0U;
    }
    vlSelf->tb_plwd__DOT__dut__DOT__rcv_state = __Vdly__tb_plwd__DOT__dut__DOT__rcv_state;
    vlSelf->tb_plwd__DOT__dut__DOT__global_sample_cnt 
        = __Vdly__tb_plwd__DOT__dut__DOT__global_sample_cnt;
    vlSelf->tb_plwd__DOT__dut__DOT__fault_count_reg 
        = __Vdly__tb_plwd__DOT__dut__DOT__fault_count_reg;
    vlSelf->tb_plwd__DOT__dut__DOT__timeout_cnt = __Vdly__tb_plwd__DOT__dut__DOT__timeout_cnt;
    vlSelf->tb_plwd__DOT__dut__DOT__stuck_cnt = __Vdly__tb_plwd__DOT__dut__DOT__stuck_cnt;
    vlSelf->tb_plwd__DOT__pipeline_srst = __Vdly__tb_plwd__DOT__pipeline_srst;
}

void Vtb_plwd___024root___timing_resume(Vtb_plwd___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root___timing_resume\n"); );
    // Body
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h5a37603f__0.resume("@(posedge tb_plwd.clk)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h5a375ffe__0.resume("@(negedge tb_plwd.clk)");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_plwd___024root___timing_commit(Vtb_plwd___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root___timing_commit\n"); );
    // Body
    if ((! (2ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h5a37603f__0.commit("@(posedge tb_plwd.clk)");
    }
    if ((! (4ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h5a375ffe__0.commit("@(negedge tb_plwd.clk)");
    }
}

void Vtb_plwd___024root___eval_triggers__act(Vtb_plwd___024root* vlSelf);

bool Vtb_plwd___024root___eval_phase__act(Vtb_plwd___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_plwd___024root___eval_triggers__act(vlSelf);
    Vtb_plwd___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_plwd___024root___timing_resume(vlSelf);
        Vtb_plwd___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_plwd___024root___eval_phase__nba(Vtb_plwd___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_plwd___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_plwd___024root___dump_triggers__nba(Vtb_plwd___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_plwd___024root___dump_triggers__act(Vtb_plwd___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_plwd___024root___eval(Vtb_plwd___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_plwd___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_plwd.v", 4, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_plwd___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/tb_plwd.v", 4, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_plwd___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_plwd___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_plwd___024root___eval_debug_assertions(Vtb_plwd___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG

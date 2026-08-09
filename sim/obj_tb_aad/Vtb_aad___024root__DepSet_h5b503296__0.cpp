// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_aad.h for the primary calling header

#include "Vtb_aad__pch.h"
#include "Vtb_aad___024root.h"

VL_ATTR_COLD void Vtb_aad___024root___eval_initial__TOP(Vtb_aad___024root* vlSelf);
VlCoroutine Vtb_aad___024root___eval_initial__TOP__Vtiming__0(Vtb_aad___024root* vlSelf);
VlCoroutine Vtb_aad___024root___eval_initial__TOP__Vtiming__1(Vtb_aad___024root* vlSelf);
VlCoroutine Vtb_aad___024root___eval_initial__TOP__Vtiming__2(Vtb_aad___024root* vlSelf);

void Vtb_aad___024root___eval_initial(Vtb_aad___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_aad__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_aad___024root___eval_initial\n"); );
    // Body
    Vtb_aad___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vtb_aad___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_aad___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_aad___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_aad__DOT__clk__0 
        = vlSelf->tb_aad__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_aad__DOT__rst_n__0 
        = vlSelf->tb_aad__DOT__rst_n;
}

VL_INLINE_OPT VlCoroutine Vtb_aad___024root___eval_initial__TOP__Vtiming__0(Vtb_aad___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_aad__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_aad___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    IData/*31:0*/ tb_aad__DOT____Vrepeat3;
    tb_aad__DOT____Vrepeat3 = 0;
    // Body
    VL_WRITEF_NX("===== tb_aad: start =====\n",0);
    vlSelf->tb_aad__DOT__pass = 0U;
    vlSelf->tb_aad__DOT__fail = 0U;
    vlSelf->tb_aad__DOT__rst_n = 0U;
    vlSelf->tb_aad__DOT__x_valid = 0U;
    vlSelf->tb_aad__DOT__x_in = 0U;
    vlSelf->tb_aad__DOT__s_axi_awaddr = 0U;
    vlSelf->tb_aad__DOT__s_axi_awvalid = 0U;
    vlSelf->tb_aad__DOT__s_axi_wdata = 0U;
    vlSelf->tb_aad__DOT__s_axi_wvalid = 0U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be896__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       51);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_aad__DOT__rst_n = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       52);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_aad__DOT__x_in = 0U;
    vlSelf->tb_aad__DOT__x_valid = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_aad__DOT__signal_active) {
        VL_WRITEF_NX("FAIL: expected inactive\n",0);
        vlSelf->tb_aad__DOT__fail = ((IData)(1U) + vlSelf->tb_aad__DOT__fail);
    } else {
        VL_WRITEF_NX("PASS: silence -> signal inactive\n",0);
        vlSelf->tb_aad__DOT__pass = ((IData)(1U) + vlSelf->tb_aad__DOT__pass);
    }
    vlSelf->tb_aad__DOT__x_in = 0x6000U;
    vlSelf->tb_aad__DOT__x_valid = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       65);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       65);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       65);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       65);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       65);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       65);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       65);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       65);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       65);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       65);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       65);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       65);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       65);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       65);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       65);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       65);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       65);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       65);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       65);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       65);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_aad__DOT__signal_active) {
        VL_WRITEF_NX("PASS: loud -> signal active\n",0);
        vlSelf->tb_aad__DOT__pass = ((IData)(1U) + vlSelf->tb_aad__DOT__pass);
    } else {
        VL_WRITEF_NX("FAIL: expected active\n",0);
        vlSelf->tb_aad__DOT__fail = ((IData)(1U) + vlSelf->tb_aad__DOT__fail);
    }
    vlSelf->tb_aad__DOT__x_in = 0U;
    vlSelf->tb_aad__DOT__x_valid = 1U;
    tb_aad__DOT____Vrepeat3 = 0x64U;
    while (VL_LTS_III(32, 0U, tb_aad__DOT____Vrepeat3)) {
        co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                           nullptr, 
                                                           "@(posedge tb_aad.clk)", 
                                                           "tb/tb_aad.v", 
                                                           74);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        tb_aad__DOT____Vrepeat3 = (tb_aad__DOT____Vrepeat3 
                                   - (IData)(1U));
    }
    if (vlSelf->tb_aad__DOT__signal_active) {
        VL_WRITEF_NX("FAIL: expected inactive after silence\n",0);
        vlSelf->tb_aad__DOT__fail = ((IData)(1U) + vlSelf->tb_aad__DOT__fail);
    } else {
        VL_WRITEF_NX("PASS: returned to inactive\n",0);
        vlSelf->tb_aad__DOT__pass = ((IData)(1U) + vlSelf->tb_aad__DOT__pass);
    }
    vlSelf->tb_aad__DOT__x_valid = 0U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       82);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       82);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       82);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       82);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       82);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       82);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       82);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       82);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       82);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h826be8d7__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_aad.clk)", 
                                                       "tb/tb_aad.v", 
                                                       82);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("===== tb_aad: %0d pass, %0d fail =====\n",0,
                 32,vlSelf->tb_aad__DOT__pass,32,vlSelf->tb_aad__DOT__fail);
    if ((0U != vlSelf->tb_aad__DOT__fail)) {
        VL_WRITEF_NX("RESULT: FAIL\n",0);
    } else {
        VL_WRITEF_NX("RESULT: PASS\n",0);
    }
    VL_FINISH_MT("tb/tb_aad.v", 87, "");
    vlSelf->__Vm_traceActivity[2U] = 1U;
}

VL_INLINE_OPT VlCoroutine Vtb_aad___024root___eval_initial__TOP__Vtiming__1(Vtb_aad___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_aad__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_aad___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0x11e1a300ULL, 
                                       nullptr, "tb/tb_aad.v", 
                                       90);
    VL_WRITEF_NX("TIMEOUT\n",0);
    VL_FINISH_MT("tb/tb_aad.v", 90, "");
}

VL_INLINE_OPT VlCoroutine Vtb_aad___024root___eval_initial__TOP__Vtiming__2(Vtb_aad___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_aad__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_aad___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "tb/tb_aad.v", 
                                           38);
        vlSelf->tb_aad__DOT__clk = (1U & (~ (IData)(vlSelf->tb_aad__DOT__clk)));
    }
}

void Vtb_aad___024root___eval_act(Vtb_aad___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_aad__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_aad___024root___eval_act\n"); );
}

void Vtb_aad___024root___nba_sequent__TOP__0(Vtb_aad___024root* vlSelf);

void Vtb_aad___024root___eval_nba(Vtb_aad___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_aad__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_aad___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_aad___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vtb_aad___024root___nba_sequent__TOP__0(Vtb_aad___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_aad__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_aad___024root___nba_sequent__TOP__0\n"); );
    // Init
    QData/*39:0*/ __Vdly__tb_aad__DOT__dut__DOT__acc_A;
    __Vdly__tb_aad__DOT__dut__DOT__acc_A = 0;
    QData/*39:0*/ __Vdly__tb_aad__DOT__dut__DOT__acc_B;
    __Vdly__tb_aad__DOT__dut__DOT__acc_B = 0;
    CData/*2:0*/ __Vdly__tb_aad__DOT__dut__DOT__assert_cnt;
    __Vdly__tb_aad__DOT__dut__DOT__assert_cnt = 0;
    CData/*6:0*/ __Vdly__tb_aad__DOT__dut__DOT__deassert_cnt;
    __Vdly__tb_aad__DOT__dut__DOT__deassert_cnt = 0;
    // Body
    __Vdly__tb_aad__DOT__dut__DOT__assert_cnt = vlSelf->tb_aad__DOT__dut__DOT__assert_cnt;
    __Vdly__tb_aad__DOT__dut__DOT__deassert_cnt = vlSelf->tb_aad__DOT__dut__DOT__deassert_cnt;
    __Vdly__tb_aad__DOT__dut__DOT__acc_B = vlSelf->tb_aad__DOT__dut__DOT__acc_B;
    __Vdly__tb_aad__DOT__dut__DOT__acc_A = vlSelf->tb_aad__DOT__dut__DOT__acc_A;
    vlSelf->tb_aad__DOT__clk_gate_en = ((1U & (~ (IData)(vlSelf->tb_aad__DOT__rst_n))) 
                                        || (IData)(vlSelf->tb_aad__DOT__signal_active));
    if (vlSelf->tb_aad__DOT__rst_n) {
        if (vlSelf->tb_aad__DOT__x_valid) {
            __Vdly__tb_aad__DOT__dut__DOT__assert_cnt 
                = ((IData)(vlSelf->tb_aad__DOT__dut__DOT__activity_cmp)
                    ? (7U & ((7U == (IData)(vlSelf->tb_aad__DOT__dut__DOT__assert_cnt))
                              ? (IData)(vlSelf->tb_aad__DOT__dut__DOT__assert_cnt)
                              : ((IData)(1U) + (IData)(vlSelf->tb_aad__DOT__dut__DOT__assert_cnt))))
                    : 0U);
            __Vdly__tb_aad__DOT__dut__DOT__acc_B = 
                (0xffffffffffULL & ((vlSelf->tb_aad__DOT__dut__DOT__acc_B 
                                     - VL_SHIFTR_QQI(40,40,32, vlSelf->tb_aad__DOT__dut__DOT__acc_B, 0xcU)) 
                                    + (QData)((IData)(vlSelf->tb_aad__DOT__dut__DOT__x_sq))));
            __Vdly__tb_aad__DOT__dut__DOT__acc_A = 
                (0xffffffffffULL & ((vlSelf->tb_aad__DOT__dut__DOT__acc_A 
                                     - VL_SHIFTR_QQI(40,40,32, vlSelf->tb_aad__DOT__dut__DOT__acc_A, 8U)) 
                                    + (QData)((IData)(vlSelf->tb_aad__DOT__dut__DOT__x_sq))));
            vlSelf->tb_aad__DOT__dut__DOT__x_sq = vlSelf->tb_aad__DOT__dut__DOT__mul_tmp;
            vlSelf->tb_aad__DOT__dut__DOT__mul_tmp 
                = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_aad__DOT__x_in)), 
                              VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_aad__DOT__x_in)));
        }
        if (((IData)(vlSelf->tb_aad__DOT__x_valid) 
             & (IData)(vlSelf->tb_aad__DOT__signal_active))) {
            __Vdly__tb_aad__DOT__dut__DOT__deassert_cnt 
                = ((IData)(vlSelf->tb_aad__DOT__dut__DOT__activity_cmp)
                    ? 0U : (0x7fU & ((0x7fU == (IData)(vlSelf->tb_aad__DOT__dut__DOT__deassert_cnt))
                                      ? (IData)(vlSelf->tb_aad__DOT__dut__DOT__deassert_cnt)
                                      : ((IData)(1U) 
                                         + (IData)(vlSelf->tb_aad__DOT__dut__DOT__deassert_cnt)))));
        }
        vlSelf->tb_aad__DOT__acc_B_dbg = vlSelf->tb_aad__DOT__dut__DOT__acc_B;
        vlSelf->tb_aad__DOT__acc_A_dbg = vlSelf->tb_aad__DOT__dut__DOT__acc_A;
        vlSelf->tb_aad__DOT__s_axi_wready = 0U;
        vlSelf->tb_aad__DOT__s_axi_awready = 0U;
        if ((((IData)(vlSelf->tb_aad__DOT__s_axi_awvalid) 
              & (IData)(vlSelf->tb_aad__DOT__s_axi_wvalid)) 
             & (0U == (IData)(vlSelf->tb_aad__DOT__s_axi_awaddr)))) {
            vlSelf->tb_aad__DOT__s_axi_wready = 1U;
            vlSelf->tb_aad__DOT__s_axi_awready = 1U;
            vlSelf->tb_aad__DOT__dut__DOT__ratio_shift_reg 
                = (0xfU & vlSelf->tb_aad__DOT__s_axi_wdata);
        }
        if ((3U <= (IData)(vlSelf->tb_aad__DOT__dut__DOT__assert_cnt))) {
            vlSelf->tb_aad__DOT__signal_active = 1U;
        } else if ((0x3fU <= (IData)(vlSelf->tb_aad__DOT__dut__DOT__deassert_cnt))) {
            vlSelf->tb_aad__DOT__signal_active = 0U;
        }
    } else {
        __Vdly__tb_aad__DOT__dut__DOT__assert_cnt = 0U;
        __Vdly__tb_aad__DOT__dut__DOT__deassert_cnt = 0U;
        __Vdly__tb_aad__DOT__dut__DOT__acc_B = 0ULL;
        __Vdly__tb_aad__DOT__dut__DOT__acc_A = 0ULL;
        vlSelf->tb_aad__DOT__acc_B_dbg = 0ULL;
        vlSelf->tb_aad__DOT__acc_A_dbg = 0ULL;
        vlSelf->tb_aad__DOT__s_axi_wready = 0U;
        vlSelf->tb_aad__DOT__s_axi_awready = 0U;
        vlSelf->tb_aad__DOT__dut__DOT__ratio_shift_reg = 2U;
        vlSelf->tb_aad__DOT__dut__DOT__x_sq = 0U;
        vlSelf->tb_aad__DOT__signal_active = 0U;
    }
    vlSelf->tb_aad__DOT__dut__DOT__acc_B = __Vdly__tb_aad__DOT__dut__DOT__acc_B;
    vlSelf->tb_aad__DOT__dut__DOT__acc_A = __Vdly__tb_aad__DOT__dut__DOT__acc_A;
    vlSelf->tb_aad__DOT__dut__DOT__activity_cmp = (vlSelf->tb_aad__DOT__dut__DOT__acc_A 
                                                   > 
                                                   (0xffffffffffULL 
                                                    & (vlSelf->tb_aad__DOT__dut__DOT__acc_B 
                                                       >> (IData)(vlSelf->tb_aad__DOT__dut__DOT__ratio_shift_reg))));
    vlSelf->tb_aad__DOT__dut__DOT__assert_cnt = __Vdly__tb_aad__DOT__dut__DOT__assert_cnt;
    vlSelf->tb_aad__DOT__dut__DOT__deassert_cnt = __Vdly__tb_aad__DOT__dut__DOT__deassert_cnt;
}

void Vtb_aad___024root___timing_resume(Vtb_aad___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_aad__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_aad___024root___timing_resume\n"); );
    // Body
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h826be8d7__0.resume("@(posedge tb_aad.clk)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h826be896__0.resume("@(negedge tb_aad.clk)");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_aad___024root___timing_commit(Vtb_aad___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_aad__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_aad___024root___timing_commit\n"); );
    // Body
    if ((! (2ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h826be8d7__0.commit("@(posedge tb_aad.clk)");
    }
    if ((! (4ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h826be896__0.commit("@(negedge tb_aad.clk)");
    }
}

void Vtb_aad___024root___eval_triggers__act(Vtb_aad___024root* vlSelf);

bool Vtb_aad___024root___eval_phase__act(Vtb_aad___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_aad__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_aad___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_aad___024root___eval_triggers__act(vlSelf);
    Vtb_aad___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_aad___024root___timing_resume(vlSelf);
        Vtb_aad___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_aad___024root___eval_phase__nba(Vtb_aad___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_aad__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_aad___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_aad___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_aad___024root___dump_triggers__nba(Vtb_aad___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_aad___024root___dump_triggers__act(Vtb_aad___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_aad___024root___eval(Vtb_aad___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_aad__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_aad___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_aad___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_aad.v", 4, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_aad___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/tb_aad.v", 4, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_aad___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_aad___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_aad___024root___eval_debug_assertions(Vtb_aad___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_aad__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_aad___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG

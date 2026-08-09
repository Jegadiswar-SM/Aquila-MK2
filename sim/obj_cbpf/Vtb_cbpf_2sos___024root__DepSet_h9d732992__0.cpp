// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_cbpf_2sos.h for the primary calling header

#include "Vtb_cbpf_2sos__pch.h"
#include "Vtb_cbpf_2sos___024root.h"

VL_ATTR_COLD void Vtb_cbpf_2sos___024root___eval_initial__TOP(Vtb_cbpf_2sos___024root* vlSelf);
VlCoroutine Vtb_cbpf_2sos___024root___eval_initial__TOP__Vtiming__0(Vtb_cbpf_2sos___024root* vlSelf);
VlCoroutine Vtb_cbpf_2sos___024root___eval_initial__TOP__Vtiming__1(Vtb_cbpf_2sos___024root* vlSelf);
VlCoroutine Vtb_cbpf_2sos___024root___eval_initial__TOP__Vtiming__2(Vtb_cbpf_2sos___024root* vlSelf);

void Vtb_cbpf_2sos___024root___eval_initial(Vtb_cbpf_2sos___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root___eval_initial\n"); );
    // Body
    Vtb_cbpf_2sos___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vtb_cbpf_2sos___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_cbpf_2sos___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_cbpf_2sos___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_cbpf_2sos__DOT__clk__0 
        = vlSelf->tb_cbpf_2sos__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_cbpf_2sos__DOT__rst_n__0 
        = vlSelf->tb_cbpf_2sos__DOT__rst_n;
}

VL_INLINE_OPT VlCoroutine Vtb_cbpf_2sos___024root___eval_initial__TOP__Vtiming__0(Vtb_cbpf_2sos___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    VL_WRITEF_NX("===== tb_cbpf_2sos: start =====\n",0);
    vlSelf->tb_cbpf_2sos__DOT__pass = 0U;
    vlSelf->tb_cbpf_2sos__DOT__fail = 0U;
    vlSelf->tb_cbpf_2sos__DOT__rst_n = 0U;
    vlSelf->tb_cbpf_2sos__DOT__x_valid = 0U;
    vlSelf->tb_cbpf_2sos__DOT__x_in = 0U;
    vlSelf->tb_cbpf_2sos__DOT__s_axi_awaddr = 0U;
    vlSelf->tb_cbpf_2sos__DOT__s_axi_awvalid = 0U;
    vlSelf->tb_cbpf_2sos__DOT__s_axi_wdata = 0U;
    vlSelf->tb_cbpf_2sos__DOT__s_axi_wvalid = 0U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       50);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf0c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       51);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_cbpf_2sos__DOT__rst_n = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       52);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_cbpf_2sos__DOT__x_in = 0x7fffU;
    vlSelf->tb_cbpf_2sos__DOT__x_valid = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       56);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_cbpf_2sos__DOT__x_valid = 0U;
    vlSelf->tb_cbpf_2sos__DOT__x_in = 0U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (vlSelf->tb_cbpf_2sos__DOT__y_valid) {
        VL_WRITEF_NX("PASS: y_valid asserted after impulse, y=0x%04x clip=%b%b\n",0,
                     16,vlSelf->tb_cbpf_2sos__DOT__y_out,
                     1,(IData)(vlSelf->tb_cbpf_2sos__DOT__clip_s1),
                     1,vlSelf->tb_cbpf_2sos__DOT__clip_s2);
        vlSelf->tb_cbpf_2sos__DOT__pass = ((IData)(1U) 
                                           + vlSelf->tb_cbpf_2sos__DOT__pass);
    } else {
        VL_WRITEF_NX("FAIL: y_valid never asserted\n",0);
        vlSelf->tb_cbpf_2sos__DOT__fail = ((IData)(1U) 
                                           + vlSelf->tb_cbpf_2sos__DOT__fail);
    }
    co_await vlSelf->__VtrigSched_h34e2bf0c__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       69);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_cbpf_2sos__DOT__s_axi_awaddr = 0U;
    vlSelf->tb_cbpf_2sos__DOT__s_axi_awvalid = 1U;
    vlSelf->tb_cbpf_2sos__DOT__s_axi_wdata = 1U;
    vlSelf->tb_cbpf_2sos__DOT__s_axi_wvalid = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       72);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_cbpf_2sos__DOT__s_axi_awvalid = 0U;
    vlSelf->tb_cbpf_2sos__DOT__s_axi_wvalid = 0U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       74);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       74);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       74);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       74);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       74);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_cbpf_2sos__DOT__x_in = 0x1234U;
    vlSelf->tb_cbpf_2sos__DOT__x_valid = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       78);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_cbpf_2sos__DOT__x_valid = 0U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       80);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       80);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       80);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       80);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       80);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       80);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       80);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       80);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       80);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h34e2bf4d__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_cbpf_2sos.clk)", 
                                                       "tb/tb_cbpf_2sos.v", 
                                                       80);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("===== tb_cbpf_2sos: %0d pass, %0d fail =====\n",0,
                 32,vlSelf->tb_cbpf_2sos__DOT__pass,
                 32,vlSelf->tb_cbpf_2sos__DOT__fail);
    if ((0U != vlSelf->tb_cbpf_2sos__DOT__fail)) {
        VL_WRITEF_NX("RESULT: FAIL\n",0);
    } else {
        VL_WRITEF_NX("RESULT: PASS\n",0);
    }
    VL_FINISH_MT("tb/tb_cbpf_2sos.v", 86, "");
    vlSelf->__Vm_traceActivity[2U] = 1U;
}

VL_INLINE_OPT VlCoroutine Vtb_cbpf_2sos___024root___eval_initial__TOP__Vtiming__1(Vtb_cbpf_2sos___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0xbebc200ULL, 
                                       nullptr, "tb/tb_cbpf_2sos.v", 
                                       89);
    VL_WRITEF_NX("TIMEOUT\n",0);
    VL_FINISH_MT("tb/tb_cbpf_2sos.v", 89, "");
}

VL_INLINE_OPT VlCoroutine Vtb_cbpf_2sos___024root___eval_initial__TOP__Vtiming__2(Vtb_cbpf_2sos___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "tb/tb_cbpf_2sos.v", 
                                           38);
        vlSelf->tb_cbpf_2sos__DOT__clk = (1U & (~ (IData)(vlSelf->tb_cbpf_2sos__DOT__clk)));
    }
}

void Vtb_cbpf_2sos___024root___eval_act(Vtb_cbpf_2sos___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root___eval_act\n"); );
}

void Vtb_cbpf_2sos___024root___nba_sequent__TOP__0(Vtb_cbpf_2sos___024root* vlSelf);

void Vtb_cbpf_2sos___024root___eval_nba(Vtb_cbpf_2sos___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_cbpf_2sos___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
}

VL_INLINE_OPT void Vtb_cbpf_2sos___024root___nba_sequent__TOP__0(Vtb_cbpf_2sos___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root___nba_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ __Vdly__tb_cbpf_2sos__DOT__dut__DOT__y_s1;
    __Vdly__tb_cbpf_2sos__DOT__dut__DOT__y_s1 = 0;
    CData/*0:0*/ __Vdly__tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg2;
    __Vdly__tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg2 = 0;
    IData/*31:0*/ __Vdly__tb_cbpf_2sos__DOT__dut__DOT__w0_s1;
    __Vdly__tb_cbpf_2sos__DOT__dut__DOT__w0_s1 = 0;
    IData/*31:0*/ __Vdly__tb_cbpf_2sos__DOT__dut__DOT__y_s2;
    __Vdly__tb_cbpf_2sos__DOT__dut__DOT__y_s2 = 0;
    IData/*31:0*/ __Vdly__tb_cbpf_2sos__DOT__dut__DOT__w0_s2;
    __Vdly__tb_cbpf_2sos__DOT__dut__DOT__w0_s2 = 0;
    // Body
    __Vdly__tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg2 
        = vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg2;
    __Vdly__tb_cbpf_2sos__DOT__dut__DOT__y_s1 = vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s1;
    __Vdly__tb_cbpf_2sos__DOT__dut__DOT__y_s2 = vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s2;
    __Vdly__tb_cbpf_2sos__DOT__dut__DOT__w0_s1 = vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w0_s1;
    __Vdly__tb_cbpf_2sos__DOT__dut__DOT__w0_s2 = vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w0_s2;
    vlSelf->tb_cbpf_2sos__DOT__y_valid = ((IData)(vlSelf->tb_cbpf_2sos__DOT__rst_n) 
                                          && (IData)(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s2_valid_stg2));
    if (vlSelf->tb_cbpf_2sos__DOT__rst_n) {
        if (vlSelf->tb_cbpf_2sos__DOT__x_valid) {
            __Vdly__tb_cbpf_2sos__DOT__dut__DOT__w0_s1 
                = (((((- (IData)((1U & ((IData)(vlSelf->tb_cbpf_2sos__DOT__x_in) 
                                        >> 0xfU)))) 
                      << 0x1eU) | ((IData)(vlSelf->tb_cbpf_2sos__DOT__x_in) 
                                   << 0xeU)) + (IData)(
                                                       (0x3fffffffffffULL 
                                                        & VL_SHIFTR_QQI(46,46,32, (QData)((IData)(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_a1_s1)), 0xfU)))) 
                   + (IData)((0x3fffffffffffULL & VL_SHIFTR_QQI(46,46,32, (QData)((IData)(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_a2_s1)), 0xfU))));
            vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_a1_s1 
                = VL_MULS_III(32, (IData)(0x7fffU), vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w1_s1);
            vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_a2_s1 
                = VL_MULS_III(32, (IData)(0xffffc250U), vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w2_s1);
        }
        if (vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg2) {
            __Vdly__tb_cbpf_2sos__DOT__dut__DOT__w0_s2 
                = (((((- (IData)((1U & ((IData)(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s1_trunc) 
                                        >> 0xfU)))) 
                      << 0x1eU) | ((IData)(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s1_trunc) 
                                   << 0xeU)) + (IData)(
                                                       (0x3fffffffffffULL 
                                                        & VL_SHIFTR_QQI(46,46,32, (QData)((IData)(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_a1_s2)), 0xfU)))) 
                   + (IData)((0x3fffffffffffULL & VL_SHIFTR_QQI(46,46,32, (QData)((IData)(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_a2_s2)), 0xfU))));
            vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s1_trunc 
                = (0xffffU & (vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s1 
                              >> 0xeU));
            vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_a1_s2 
                = VL_MULS_III(32, (IData)(0x7148U), vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w1_s2);
            vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_a2_s2 
                = VL_MULS_III(32, (IData)(0xffffcaa1U), vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w2_s2);
        }
        vlSelf->tb_cbpf_2sos__DOT__s_axi_wready = 0U;
        vlSelf->tb_cbpf_2sos__DOT__s_axi_awready = 0U;
        vlSelf->tb_cbpf_2sos__DOT__y_out = ((IData)(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__bypass_reg)
                                             ? (IData)(vlSelf->tb_cbpf_2sos__DOT__x_in)
                                             : (IData)(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s2_trunc));
        if ((((IData)(vlSelf->tb_cbpf_2sos__DOT__s_axi_awvalid) 
              & (IData)(vlSelf->tb_cbpf_2sos__DOT__s_axi_wvalid)) 
             & (0U == (IData)(vlSelf->tb_cbpf_2sos__DOT__s_axi_awaddr)))) {
            vlSelf->tb_cbpf_2sos__DOT__s_axi_wready = 1U;
            vlSelf->tb_cbpf_2sos__DOT__s_axi_awready = 1U;
            vlSelf->tb_cbpf_2sos__DOT__dut__DOT__bypass_reg 
                = (1U & vlSelf->tb_cbpf_2sos__DOT__s_axi_wdata);
        }
        if (vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg1) {
            vlSelf->tb_cbpf_2sos__DOT__clip_s1 = ((0U 
                                                   != 
                                                   (vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s1 
                                                    >> 0x1eU)) 
                                                  & (3U 
                                                     != 
                                                     (vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s1 
                                                      >> 0x1eU)));
            __Vdly__tb_cbpf_2sos__DOT__dut__DOT__y_s1 
                = ((VL_SHIFTRS_III(32,32,32, vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b0_s1, 0xfU) 
                    + VL_SHIFTRS_III(32,32,32, vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b1_s1, 0xfU)) 
                   + VL_SHIFTRS_III(32,32,32, vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b2_s1, 0xfU));
            vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b0_s1 
                = VL_MULS_III(32, (IData)(0x2afU), vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w0_s1);
            vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b1_s1 
                = VL_MULS_III(32, (IData)(0x55eU), vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w1_s1);
            vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b2_s1 
                = VL_MULS_III(32, (IData)(0x2afU), vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w2_s1);
            vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w2_s1 
                = vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w1_s1;
            vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w1_s1 
                = vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w0_s1;
            __Vdly__tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg2 = 1U;
        } else {
            __Vdly__tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg2 = 0U;
        }
        if (vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s2_valid_stg1) {
            vlSelf->tb_cbpf_2sos__DOT__clip_s2 = ((0U 
                                                   != 
                                                   (vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s2 
                                                    >> 0x1eU)) 
                                                  & (3U 
                                                     != 
                                                     (vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s2 
                                                      >> 0x1eU)));
            __Vdly__tb_cbpf_2sos__DOT__dut__DOT__y_s2 
                = ((VL_SHIFTRS_III(32,32,32, vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b0_s2, 0xfU) 
                    + VL_SHIFTRS_III(32,32,32, vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b1_s2, 0xfU)) 
                   + VL_SHIFTRS_III(32,32,32, vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b2_s2, 0xfU));
            vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b0_s2 
                = VL_MULS_III(32, (IData)(0x4000U), vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w0_s2);
            vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b1_s2 
                = VL_MULS_III(32, (IData)(0xffff8000U), vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w1_s2);
            vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b2_s2 
                = VL_MULS_III(32, (IData)(0x4000U), vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w2_s2);
            vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w2_s2 
                = vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w1_s2;
            vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w1_s2 
                = vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w0_s2;
        }
        if (vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s2_valid_stg2) {
            vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s2_trunc 
                = (0xffffU & (vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s2 
                              >> 0xeU));
        }
        vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s2_valid_stg2 
            = vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s2_valid_stg1;
    } else {
        __Vdly__tb_cbpf_2sos__DOT__dut__DOT__w0_s1 = 0U;
        __Vdly__tb_cbpf_2sos__DOT__dut__DOT__w0_s2 = 0U;
        vlSelf->tb_cbpf_2sos__DOT__s_axi_wready = 0U;
        vlSelf->tb_cbpf_2sos__DOT__s_axi_awready = 0U;
        vlSelf->tb_cbpf_2sos__DOT__y_out = 0U;
        vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w1_s1 = 0U;
        vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w2_s1 = 0U;
        __Vdly__tb_cbpf_2sos__DOT__dut__DOT__y_s1 = 0U;
        vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s1_trunc = 0U;
        __Vdly__tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg2 = 0U;
        vlSelf->tb_cbpf_2sos__DOT__clip_s1 = 0U;
        vlSelf->tb_cbpf_2sos__DOT__dut__DOT__bypass_reg = 0U;
        vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w1_s2 = 0U;
        vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w2_s2 = 0U;
        __Vdly__tb_cbpf_2sos__DOT__dut__DOT__y_s2 = 0U;
        vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s2_trunc = 0U;
        vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s2_valid_stg2 = 0U;
        vlSelf->tb_cbpf_2sos__DOT__clip_s2 = 0U;
    }
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w0_s1 = __Vdly__tb_cbpf_2sos__DOT__dut__DOT__w0_s1;
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s1 = __Vdly__tb_cbpf_2sos__DOT__dut__DOT__y_s1;
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w0_s2 = __Vdly__tb_cbpf_2sos__DOT__dut__DOT__w0_s2;
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s2 = __Vdly__tb_cbpf_2sos__DOT__dut__DOT__y_s2;
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg1 
        = ((IData)(vlSelf->tb_cbpf_2sos__DOT__rst_n) 
           && (IData)(vlSelf->tb_cbpf_2sos__DOT__x_valid));
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s2_valid_stg1 
        = ((IData)(vlSelf->tb_cbpf_2sos__DOT__rst_n) 
           && (IData)(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg2));
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg2 
        = __Vdly__tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg2;
}

void Vtb_cbpf_2sos___024root___timing_resume(Vtb_cbpf_2sos___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root___timing_resume\n"); );
    // Body
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h34e2bf4d__0.resume("@(posedge tb_cbpf_2sos.clk)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h34e2bf0c__0.resume("@(negedge tb_cbpf_2sos.clk)");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_cbpf_2sos___024root___timing_commit(Vtb_cbpf_2sos___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root___timing_commit\n"); );
    // Body
    if ((! (2ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h34e2bf4d__0.commit("@(posedge tb_cbpf_2sos.clk)");
    }
    if ((! (4ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h34e2bf0c__0.commit("@(negedge tb_cbpf_2sos.clk)");
    }
}

void Vtb_cbpf_2sos___024root___eval_triggers__act(Vtb_cbpf_2sos___024root* vlSelf);

bool Vtb_cbpf_2sos___024root___eval_phase__act(Vtb_cbpf_2sos___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_cbpf_2sos___024root___eval_triggers__act(vlSelf);
    Vtb_cbpf_2sos___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_cbpf_2sos___024root___timing_resume(vlSelf);
        Vtb_cbpf_2sos___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_cbpf_2sos___024root___eval_phase__nba(Vtb_cbpf_2sos___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_cbpf_2sos___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cbpf_2sos___024root___dump_triggers__nba(Vtb_cbpf_2sos___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cbpf_2sos___024root___dump_triggers__act(Vtb_cbpf_2sos___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_cbpf_2sos___024root___eval(Vtb_cbpf_2sos___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_cbpf_2sos___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_cbpf_2sos.v", 4, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_cbpf_2sos___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/tb_cbpf_2sos.v", 4, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_cbpf_2sos___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_cbpf_2sos___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_cbpf_2sos___024root___eval_debug_assertions(Vtb_cbpf_2sos___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_affhc.h for the primary calling header

#include "Vtb_affhc__pch.h"
#include "Vtb_affhc___024root.h"

VL_ATTR_COLD void Vtb_affhc___024root___eval_initial__TOP(Vtb_affhc___024root* vlSelf);
VlCoroutine Vtb_affhc___024root___eval_initial__TOP__Vtiming__0(Vtb_affhc___024root* vlSelf);
VlCoroutine Vtb_affhc___024root___eval_initial__TOP__Vtiming__1(Vtb_affhc___024root* vlSelf);
VlCoroutine Vtb_affhc___024root___eval_initial__TOP__Vtiming__2(Vtb_affhc___024root* vlSelf);

void Vtb_affhc___024root___eval_initial(Vtb_affhc___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_affhc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_affhc___024root___eval_initial\n"); );
    // Body
    Vtb_affhc___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vtb_affhc___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_affhc___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    Vtb_affhc___024root___eval_initial__TOP__Vtiming__2(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_affhc__DOT__clk__0 
        = vlSelf->tb_affhc__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_affhc__DOT__rst_n__0 
        = vlSelf->tb_affhc__DOT__rst_n;
}

VL_INLINE_OPT VlCoroutine Vtb_affhc___024root___eval_initial__TOP__Vtiming__0(Vtb_affhc___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_affhc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_affhc___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    VL_WRITEF_NX("===== tb_affhc: start =====\n",0);
    vlSelf->tb_affhc__DOT__pass = 0U;
    vlSelf->tb_affhc__DOT__fail = 0U;
    vlSelf->tb_affhc__DOT__rst_n = 0U;
    vlSelf->tb_affhc__DOT__e_valid = 0U;
    vlSelf->tb_affhc__DOT__e_in = 0U;
    vlSelf->tb_affhc__DOT__s_axi_awaddr = 0U;
    vlSelf->tb_affhc__DOT__s_axi_awvalid = 0U;
    vlSelf->tb_affhc__DOT__s_axi_wdata = 0U;
    vlSelf->tb_affhc__DOT__s_axi_wvalid = 0U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       46);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       46);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       46);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       46);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       46);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       46);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       46);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       46);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       46);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       46);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd6ce__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(negedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       47);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_affhc__DOT__rst_n = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       48);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if (((0U == (IData)(vlSelf->tb_affhc__DOT__fsm_state_dbg)) 
         & (0x7f00U == (IData)(vlSelf->tb_affhc__DOT__lambda_out)))) {
        VL_WRITEF_NX("PASS: initial state STEADY, lambda=0x%04x\n",0,
                     16,vlSelf->tb_affhc__DOT__lambda_out);
        vlSelf->tb_affhc__DOT__pass = ((IData)(1U) 
                                       + vlSelf->tb_affhc__DOT__pass);
    } else {
        VL_WRITEF_NX("FAIL: initial state=%b lambda=0x%04x\n",0,
                     2,vlSelf->tb_affhc__DOT__fsm_state_dbg,
                     16,(IData)(vlSelf->tb_affhc__DOT__lambda_out));
        vlSelf->tb_affhc__DOT__fail = ((IData)(1U) 
                                       + vlSelf->tb_affhc__DOT__fail);
    }
    vlSelf->tb_affhc__DOT__e_in = 0xbb8U;
    vlSelf->tb_affhc__DOT__e_valid = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       59);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if ((1U == (IData)(vlSelf->tb_affhc__DOT__fsm_state_dbg))) {
        VL_WRITEF_NX("PASS: transition to TRACKING\n",0);
        vlSelf->tb_affhc__DOT__pass = ((IData)(1U) 
                                       + vlSelf->tb_affhc__DOT__pass);
    } else {
        VL_WRITEF_NX("FAIL: expected TRACKING got %b\n",0,
                     2,vlSelf->tb_affhc__DOT__fsm_state_dbg);
        vlSelf->tb_affhc__DOT__fail = ((IData)(1U) 
                                       + vlSelf->tb_affhc__DOT__fail);
    }
    vlSelf->tb_affhc__DOT__e_in = 0x32U;
    vlSelf->tb_affhc__DOT__e_valid = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       68);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       68);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       68);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       68);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       68);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       68);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       68);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       68);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       68);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       68);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       68);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       68);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       68);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       68);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       68);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       68);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    if ((0U == (IData)(vlSelf->tb_affhc__DOT__fsm_state_dbg))) {
        VL_WRITEF_NX("PASS: returned to STEADY\n",0);
        vlSelf->tb_affhc__DOT__pass = ((IData)(1U) 
                                       + vlSelf->tb_affhc__DOT__pass);
    } else {
        VL_WRITEF_NX("FAIL: expected STEADY got %b\n",0,
                     2,vlSelf->tb_affhc__DOT__fsm_state_dbg);
        vlSelf->tb_affhc__DOT__fail = ((IData)(1U) 
                                       + vlSelf->tb_affhc__DOT__fail);
    }
    vlSelf->tb_affhc__DOT__e_valid = 0U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       76);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       76);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       76);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       76);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       76);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       76);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       76);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       76);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       76);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_h1cbcd60f__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_affhc.clk)", 
                                                       "tb/tb_affhc.v", 
                                                       76);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_WRITEF_NX("===== tb_affhc: %0d pass, %0d fail =====\n",0,
                 32,vlSelf->tb_affhc__DOT__pass,32,
                 vlSelf->tb_affhc__DOT__fail);
    if ((0U != vlSelf->tb_affhc__DOT__fail)) {
        VL_WRITEF_NX("RESULT: FAIL\n",0);
    } else {
        VL_WRITEF_NX("RESULT: PASS\n",0);
    }
    VL_FINISH_MT("tb/tb_affhc.v", 81, "");
    vlSelf->__Vm_traceActivity[2U] = 1U;
}

VL_INLINE_OPT VlCoroutine Vtb_affhc___024root___eval_initial__TOP__Vtiming__1(Vtb_affhc___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_affhc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_affhc___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    co_await vlSelf->__VdlySched.delay(0xbebc200ULL, 
                                       nullptr, "tb/tb_affhc.v", 
                                       84);
    VL_WRITEF_NX("TIMEOUT\n",0);
    VL_FINISH_MT("tb/tb_affhc.v", 84, "");
}

VL_INLINE_OPT VlCoroutine Vtb_affhc___024root___eval_initial__TOP__Vtiming__2(Vtb_affhc___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_affhc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_affhc___024root___eval_initial__TOP__Vtiming__2\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "tb/tb_affhc.v", 
                                           34);
        vlSelf->tb_affhc__DOT__clk = (1U & (~ (IData)(vlSelf->tb_affhc__DOT__clk)));
    }
}

void Vtb_affhc___024root___act_comb__TOP__0(Vtb_affhc___024root* vlSelf);

void Vtb_affhc___024root___eval_act(Vtb_affhc___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_affhc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_affhc___024root___eval_act\n"); );
    // Body
    if ((6ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb_affhc___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_affhc___024root___act_comb__TOP__0(Vtb_affhc___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_affhc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_affhc___024root___act_comb__TOP__0\n"); );
    // Body
    vlSelf->tb_affhc__DOT__dut__DOT__delta_e = (0x1ffffU 
                                                & (VL_GTS_III(16, (IData)(vlSelf->tb_affhc__DOT__e_in), (IData)(vlSelf->tb_affhc__DOT__dut__DOT__e_prev))
                                                    ? 
                                                   (VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_affhc__DOT__e_in)) 
                                                    - 
                                                    VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_affhc__DOT__dut__DOT__e_prev)))
                                                    : 
                                                   (VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_affhc__DOT__dut__DOT__e_prev)) 
                                                    - 
                                                    VL_EXTENDS_II(17,16, (IData)(vlSelf->tb_affhc__DOT__e_in)))));
}

void Vtb_affhc___024root___nba_sequent__TOP__0(Vtb_affhc___024root* vlSelf);

void Vtb_affhc___024root___eval_nba(Vtb_affhc___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_affhc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_affhc___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_affhc___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    if ((7ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_affhc___024root___act_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtb_affhc___024root___nba_sequent__TOP__0(Vtb_affhc___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_affhc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_affhc___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*1:0*/ __Vdly__tb_affhc__DOT__dut__DOT__state;
    __Vdly__tb_affhc__DOT__dut__DOT__state = 0;
    CData/*2:0*/ __Vdly__tb_affhc__DOT__dut__DOT__cnt_up;
    __Vdly__tb_affhc__DOT__dut__DOT__cnt_up = 0;
    CData/*3:0*/ __Vdly__tb_affhc__DOT__dut__DOT__cnt_down;
    __Vdly__tb_affhc__DOT__dut__DOT__cnt_down = 0;
    // Body
    __Vdly__tb_affhc__DOT__dut__DOT__cnt_down = vlSelf->tb_affhc__DOT__dut__DOT__cnt_down;
    __Vdly__tb_affhc__DOT__dut__DOT__cnt_up = vlSelf->tb_affhc__DOT__dut__DOT__cnt_up;
    __Vdly__tb_affhc__DOT__dut__DOT__state = vlSelf->tb_affhc__DOT__dut__DOT__state;
    if (vlSelf->tb_affhc__DOT__rst_n) {
        if (vlSelf->tb_affhc__DOT__e_valid) {
            vlSelf->tb_affhc__DOT__dut__DOT__e_prev 
                = vlSelf->tb_affhc__DOT__e_in;
        }
        vlSelf->tb_affhc__DOT__s_axi_wready = 0U;
        vlSelf->tb_affhc__DOT__s_axi_awready = 0U;
        if (vlSelf->tb_affhc__DOT__dut__DOT__lockout_active) {
            if (vlSelf->tb_affhc__DOT__e_valid) {
                if ((0U == (IData)(vlSelf->tb_affhc__DOT__dut__DOT__lockout_cnt))) {
                    vlSelf->tb_affhc__DOT__dut__DOT__lockout_active = 0U;
                    __Vdly__tb_affhc__DOT__dut__DOT__state 
                        = vlSelf->tb_affhc__DOT__dut__DOT__next_state;
                } else {
                    vlSelf->tb_affhc__DOT__dut__DOT__lockout_cnt 
                        = (0x3fU & ((IData)(vlSelf->tb_affhc__DOT__dut__DOT__lockout_cnt) 
                                    - (IData)(1U)));
                }
            }
        } else if (vlSelf->tb_affhc__DOT__e_valid) {
            if ((vlSelf->tb_affhc__DOT__dut__DOT__delta_e 
                 > (IData)(vlSelf->tb_affhc__DOT__dut__DOT__threshold_up_reg))) {
                __Vdly__tb_affhc__DOT__dut__DOT__cnt_up 
                    = (7U & ((7U == (IData)(vlSelf->tb_affhc__DOT__dut__DOT__cnt_up))
                              ? (IData)(vlSelf->tb_affhc__DOT__dut__DOT__cnt_up)
                              : ((IData)(1U) + (IData)(vlSelf->tb_affhc__DOT__dut__DOT__cnt_up))));
                __Vdly__tb_affhc__DOT__dut__DOT__cnt_down = 0U;
            } else if ((vlSelf->tb_affhc__DOT__dut__DOT__delta_e 
                        < (IData)(vlSelf->tb_affhc__DOT__dut__DOT__threshold_down_reg))) {
                __Vdly__tb_affhc__DOT__dut__DOT__cnt_down 
                    = (0xfU & ((IData)(1U) + (IData)(vlSelf->tb_affhc__DOT__dut__DOT__cnt_down)));
                __Vdly__tb_affhc__DOT__dut__DOT__cnt_up = 0U;
            } else {
                __Vdly__tb_affhc__DOT__dut__DOT__cnt_up = 0U;
                __Vdly__tb_affhc__DOT__dut__DOT__cnt_down = 0U;
            }
            if ((0U == (IData)(vlSelf->tb_affhc__DOT__dut__DOT__state))) {
                if ((3U <= (IData)(vlSelf->tb_affhc__DOT__dut__DOT__cnt_up))) {
                    vlSelf->tb_affhc__DOT__dut__DOT__lockout_active = 1U;
                    vlSelf->tb_affhc__DOT__dut__DOT__lockout_cnt = 0x20U;
                    vlSelf->tb_affhc__DOT__dut__DOT__next_state = 1U;
                    __Vdly__tb_affhc__DOT__dut__DOT__state = 3U;
                }
            } else if ((1U == (IData)(vlSelf->tb_affhc__DOT__dut__DOT__state))) {
                if ((3U <= (IData)(vlSelf->tb_affhc__DOT__dut__DOT__cnt_up))) {
                    vlSelf->tb_affhc__DOT__dut__DOT__lockout_active = 1U;
                    vlSelf->tb_affhc__DOT__dut__DOT__lockout_cnt = 0x20U;
                    vlSelf->tb_affhc__DOT__dut__DOT__next_state = 2U;
                    __Vdly__tb_affhc__DOT__dut__DOT__state = 3U;
                } else if ((8U <= (IData)(vlSelf->tb_affhc__DOT__dut__DOT__cnt_down))) {
                    vlSelf->tb_affhc__DOT__dut__DOT__lockout_active = 1U;
                    vlSelf->tb_affhc__DOT__dut__DOT__lockout_cnt = 0x20U;
                    vlSelf->tb_affhc__DOT__dut__DOT__next_state = 0U;
                    __Vdly__tb_affhc__DOT__dut__DOT__state = 3U;
                }
            } else if ((2U == (IData)(vlSelf->tb_affhc__DOT__dut__DOT__state))) {
                if ((8U <= (IData)(vlSelf->tb_affhc__DOT__dut__DOT__cnt_down))) {
                    vlSelf->tb_affhc__DOT__dut__DOT__lockout_active = 1U;
                    vlSelf->tb_affhc__DOT__dut__DOT__lockout_cnt = 0x20U;
                    vlSelf->tb_affhc__DOT__dut__DOT__next_state = 1U;
                    __Vdly__tb_affhc__DOT__dut__DOT__state = 3U;
                }
            }
        }
        vlSelf->tb_affhc__DOT__lambda_out = ((0U == (IData)(vlSelf->tb_affhc__DOT__dut__DOT__state))
                                              ? (IData)(vlSelf->tb_affhc__DOT__dut__DOT__lambda_slow)
                                              : ((1U 
                                                  == (IData)(vlSelf->tb_affhc__DOT__dut__DOT__state))
                                                  ? (IData)(vlSelf->tb_affhc__DOT__dut__DOT__lambda_mid)
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlSelf->tb_affhc__DOT__dut__DOT__state))
                                                   ? (IData)(vlSelf->tb_affhc__DOT__dut__DOT__lambda_fast)
                                                   : (IData)(vlSelf->tb_affhc__DOT__lambda_out))));
        if (((IData)(vlSelf->tb_affhc__DOT__s_axi_awvalid) 
             & (IData)(vlSelf->tb_affhc__DOT__s_axi_wvalid))) {
            vlSelf->tb_affhc__DOT__s_axi_wready = 1U;
            vlSelf->tb_affhc__DOT__s_axi_awready = 1U;
            if ((0U != (IData)(vlSelf->tb_affhc__DOT__s_axi_awaddr))) {
                if ((4U != (IData)(vlSelf->tb_affhc__DOT__s_axi_awaddr))) {
                    if ((8U != (IData)(vlSelf->tb_affhc__DOT__s_axi_awaddr))) {
                        if ((0xcU == (IData)(vlSelf->tb_affhc__DOT__s_axi_awaddr))) {
                            vlSelf->tb_affhc__DOT__dut__DOT__threshold_up_reg 
                                = (0xffffU & vlSelf->tb_affhc__DOT__s_axi_wdata);
                        }
                        if ((0xcU != (IData)(vlSelf->tb_affhc__DOT__s_axi_awaddr))) {
                            if ((0x10U == (IData)(vlSelf->tb_affhc__DOT__s_axi_awaddr))) {
                                vlSelf->tb_affhc__DOT__dut__DOT__threshold_down_reg 
                                    = (0xffffU & vlSelf->tb_affhc__DOT__s_axi_wdata);
                            }
                        }
                    }
                    if ((8U == (IData)(vlSelf->tb_affhc__DOT__s_axi_awaddr))) {
                        vlSelf->tb_affhc__DOT__dut__DOT__lambda_fast 
                            = (0xffffU & vlSelf->tb_affhc__DOT__s_axi_wdata);
                    }
                }
                if ((4U == (IData)(vlSelf->tb_affhc__DOT__s_axi_awaddr))) {
                    vlSelf->tb_affhc__DOT__dut__DOT__lambda_mid 
                        = (0xffffU & vlSelf->tb_affhc__DOT__s_axi_wdata);
                }
            }
            if ((0U == (IData)(vlSelf->tb_affhc__DOT__s_axi_awaddr))) {
                vlSelf->tb_affhc__DOT__dut__DOT__lambda_slow 
                    = (0xffffU & vlSelf->tb_affhc__DOT__s_axi_wdata);
            }
        }
        vlSelf->tb_affhc__DOT__fsm_state_dbg = vlSelf->tb_affhc__DOT__dut__DOT__state;
    } else {
        vlSelf->tb_affhc__DOT__dut__DOT__e_prev = 0U;
        vlSelf->tb_affhc__DOT__s_axi_wready = 0U;
        vlSelf->tb_affhc__DOT__s_axi_awready = 0U;
        __Vdly__tb_affhc__DOT__dut__DOT__cnt_up = 0U;
        __Vdly__tb_affhc__DOT__dut__DOT__state = 0U;
        vlSelf->tb_affhc__DOT__dut__DOT__next_state = 0U;
        __Vdly__tb_affhc__DOT__dut__DOT__cnt_down = 0U;
        vlSelf->tb_affhc__DOT__dut__DOT__lockout_cnt = 0U;
        vlSelf->tb_affhc__DOT__dut__DOT__lockout_active = 0U;
        vlSelf->tb_affhc__DOT__lambda_out = 0x7f00U;
        vlSelf->tb_affhc__DOT__fsm_state_dbg = 0U;
        vlSelf->tb_affhc__DOT__dut__DOT__threshold_up_reg = 0x200U;
        vlSelf->tb_affhc__DOT__dut__DOT__threshold_down_reg = 0x80U;
        vlSelf->tb_affhc__DOT__dut__DOT__lambda_slow = 0x7f00U;
        vlSelf->tb_affhc__DOT__dut__DOT__lambda_mid = 0x7e00U;
        vlSelf->tb_affhc__DOT__dut__DOT__lambda_fast = 0x7800U;
    }
    vlSelf->tb_affhc__DOT__dut__DOT__state = __Vdly__tb_affhc__DOT__dut__DOT__state;
    vlSelf->tb_affhc__DOT__dut__DOT__cnt_up = __Vdly__tb_affhc__DOT__dut__DOT__cnt_up;
    vlSelf->tb_affhc__DOT__dut__DOT__cnt_down = __Vdly__tb_affhc__DOT__dut__DOT__cnt_down;
}

void Vtb_affhc___024root___timing_resume(Vtb_affhc___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_affhc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_affhc___024root___timing_resume\n"); );
    // Body
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h1cbcd60f__0.resume("@(posedge tb_affhc.clk)");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_h1cbcd6ce__0.resume("@(negedge tb_affhc.clk)");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_affhc___024root___timing_commit(Vtb_affhc___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_affhc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_affhc___024root___timing_commit\n"); );
    // Body
    if ((! (2ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h1cbcd60f__0.commit("@(posedge tb_affhc.clk)");
    }
    if ((! (4ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_h1cbcd6ce__0.commit("@(negedge tb_affhc.clk)");
    }
}

void Vtb_affhc___024root___eval_triggers__act(Vtb_affhc___024root* vlSelf);

bool Vtb_affhc___024root___eval_phase__act(Vtb_affhc___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_affhc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_affhc___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<4> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_affhc___024root___eval_triggers__act(vlSelf);
    Vtb_affhc___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_affhc___024root___timing_resume(vlSelf);
        Vtb_affhc___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_affhc___024root___eval_phase__nba(Vtb_affhc___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_affhc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_affhc___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_affhc___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_affhc___024root___dump_triggers__nba(Vtb_affhc___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_affhc___024root___dump_triggers__act(Vtb_affhc___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_affhc___024root___eval(Vtb_affhc___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_affhc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_affhc___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_affhc___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_affhc.v", 4, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_affhc___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("tb/tb_affhc.v", 4, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_affhc___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_affhc___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_affhc___024root___eval_debug_assertions(Vtb_affhc___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_affhc__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_affhc___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG

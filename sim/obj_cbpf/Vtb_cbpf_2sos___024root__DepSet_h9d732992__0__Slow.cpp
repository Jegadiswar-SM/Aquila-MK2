// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_cbpf_2sos.h for the primary calling header

#include "Vtb_cbpf_2sos__pch.h"
#include "Vtb_cbpf_2sos___024root.h"

VL_ATTR_COLD void Vtb_cbpf_2sos___024root___eval_static(Vtb_cbpf_2sos___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtb_cbpf_2sos___024root___eval_final(Vtb_cbpf_2sos___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtb_cbpf_2sos___024root___eval_settle(Vtb_cbpf_2sos___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cbpf_2sos___024root___dump_triggers__act(Vtb_cbpf_2sos___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ vlSelf->__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_cbpf_2sos.clk or negedge tb_cbpf_2sos.rst_n)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb_cbpf_2sos.clk)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(negedge tb_cbpf_2sos.clk)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_cbpf_2sos___024root___dump_triggers__nba(Vtb_cbpf_2sos___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ vlSelf->__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_cbpf_2sos.clk or negedge tb_cbpf_2sos.rst_n)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb_cbpf_2sos.clk)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(negedge tb_cbpf_2sos.clk)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_cbpf_2sos___024root___ctor_var_reset(Vtb_cbpf_2sos___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_cbpf_2sos__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_cbpf_2sos__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_cbpf_2sos__DOT__x_in = VL_RAND_RESET_I(16);
    vlSelf->tb_cbpf_2sos__DOT__x_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_cbpf_2sos__DOT__s_axi_awaddr = VL_RAND_RESET_I(4);
    vlSelf->tb_cbpf_2sos__DOT__s_axi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_cbpf_2sos__DOT__s_axi_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__s_axi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_cbpf_2sos__DOT__s_axi_awready = VL_RAND_RESET_I(1);
    vlSelf->tb_cbpf_2sos__DOT__s_axi_wready = VL_RAND_RESET_I(1);
    vlSelf->tb_cbpf_2sos__DOT__y_out = VL_RAND_RESET_I(16);
    vlSelf->tb_cbpf_2sos__DOT__y_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_cbpf_2sos__DOT__clip_s1 = VL_RAND_RESET_I(1);
    vlSelf->tb_cbpf_2sos__DOT__clip_s2 = VL_RAND_RESET_I(1);
    vlSelf->tb_cbpf_2sos__DOT__pass = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__fail = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__bypass_reg = VL_RAND_RESET_I(1);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w1_s1 = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w2_s1 = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w0_s1 = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s1 = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_a1_s1 = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_a2_s1 = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b0_s1 = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b1_s1 = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b2_s1 = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s1_trunc = VL_RAND_RESET_I(16);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg1 = VL_RAND_RESET_I(1);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg2 = VL_RAND_RESET_I(1);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w1_s2 = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w2_s2 = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w0_s2 = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s2 = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_a1_s2 = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_a2_s2 = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b0_s2 = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b1_s2 = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b2_s2 = VL_RAND_RESET_I(32);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s2_trunc = VL_RAND_RESET_I(16);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s2_valid_stg1 = VL_RAND_RESET_I(1);
    vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s2_valid_stg2 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_cbpf_2sos__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_cbpf_2sos__DOT__rst_n__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_plwd.h for the primary calling header

#include "Vtb_plwd__pch.h"
#include "Vtb_plwd___024root.h"

VL_ATTR_COLD void Vtb_plwd___024root___eval_static(Vtb_plwd___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtb_plwd___024root___eval_final(Vtb_plwd___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vtb_plwd___024root___eval_settle(Vtb_plwd___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_plwd___024root___dump_triggers__act(Vtb_plwd___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ vlSelf->__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_plwd.clk or negedge tb_plwd.rst_n)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb_plwd.clk)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(negedge tb_plwd.clk)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_plwd___024root___dump_triggers__nba(Vtb_plwd___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ vlSelf->__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_plwd.clk or negedge tb_plwd.rst_n)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb_plwd.clk)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(negedge tb_plwd.clk)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_plwd___024root___ctor_var_reset(Vtb_plwd___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_plwd__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_plwd___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_plwd__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_plwd__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_plwd__DOT__m_axis_tvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_plwd__DOT__m_axis_tdata = VL_RAND_RESET_I(16);
    vlSelf->tb_plwd__DOT__s_axi_araddr = VL_RAND_RESET_I(4);
    vlSelf->tb_plwd__DOT__s_axi_arvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_plwd__DOT__s_axi_rdata = VL_RAND_RESET_I(32);
    vlSelf->tb_plwd__DOT__s_axi_rvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_plwd__DOT__s_axi_awaddr = VL_RAND_RESET_I(4);
    vlSelf->tb_plwd__DOT__s_axi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_plwd__DOT__s_axi_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_plwd__DOT__s_axi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_plwd__DOT__s_axi_awready = VL_RAND_RESET_I(1);
    vlSelf->tb_plwd__DOT__s_axi_wready = VL_RAND_RESET_I(1);
    vlSelf->tb_plwd__DOT__pipeline_srst = VL_RAND_RESET_I(1);
    vlSelf->tb_plwd__DOT__irq_fault = VL_RAND_RESET_I(1);
    vlSelf->tb_plwd__DOT__pass = VL_RAND_RESET_I(32);
    vlSelf->tb_plwd__DOT__fail = VL_RAND_RESET_I(32);
    vlSelf->tb_plwd__DOT__dut__DOT__timeout_cnt = VL_RAND_RESET_I(16);
    vlSelf->tb_plwd__DOT__dut__DOT__pipeline_stall_fault = VL_RAND_RESET_I(1);
    vlSelf->tb_plwd__DOT__dut__DOT__last_sample = VL_RAND_RESET_I(16);
    vlSelf->tb_plwd__DOT__dut__DOT__stuck_cnt = VL_RAND_RESET_I(5);
    vlSelf->tb_plwd__DOT__dut__DOT__output_stuck_fault = VL_RAND_RESET_I(1);
    vlSelf->tb_plwd__DOT__dut__DOT__global_sample_cnt = VL_RAND_RESET_I(32);
    vlSelf->tb_plwd__DOT__dut__DOT__fault_type_reg = VL_RAND_RESET_I(2);
    vlSelf->tb_plwd__DOT__dut__DOT__fault_sample_cnt = VL_RAND_RESET_I(32);
    vlSelf->tb_plwd__DOT__dut__DOT__fault_count_reg = VL_RAND_RESET_I(8);
    vlSelf->tb_plwd__DOT__dut__DOT__rcv_state = VL_RAND_RESET_I(2);
    vlSelf->tb_plwd__DOT__dut__DOT__drain_cnt = VL_RAND_RESET_I(3);
    vlSelf->__Vtrigprevexpr___TOP__tb_plwd__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_plwd__DOT__rst_n__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}

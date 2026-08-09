// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rcim.h for the primary calling header

#include "Vtb_rcim__pch.h"
#include "Vtb_rcim___024root.h"

VL_ATTR_COLD void Vtb_rcim___024root___eval_static(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtb_rcim___024root___eval_final(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rcim___024root___dump_triggers__stl(Vtb_rcim___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_rcim___024root___eval_phase__stl(Vtb_rcim___024root* vlSelf);

VL_ATTR_COLD void Vtb_rcim___024root___eval_settle(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb_rcim___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("tb/tb_rcim.v", 4, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_rcim___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rcim___024root___dump_triggers__stl(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ vlSelf->__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_rcim___024root___stl_sequent__TOP__0(Vtb_rcim___024root* vlSelf);

VL_ATTR_COLD void Vtb_rcim___024root___eval_stl(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_rcim___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void Vtb_rcim___024root___stl_sequent__TOP__0(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->tb_rcim__DOT__dut__DOT__recip_approx = 
        vlSelf->tb_rcim__DOT__dut__DOT__lutram[(0xfU 
                                                & (IData)(
                                                          (vlSelf->tb_rcim__DOT__dut__DOT__ref_power_acc 
                                                           >> 0x23U)))];
}

VL_ATTR_COLD void Vtb_rcim___024root___eval_triggers__stl(Vtb_rcim___024root* vlSelf);

VL_ATTR_COLD bool Vtb_rcim___024root___eval_phase__stl(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_rcim___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_rcim___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rcim___024root___dump_triggers__act(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ vlSelf->__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_rcim.clk or negedge tb_rcim.rst_n)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb_rcim.clk)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(negedge tb_rcim.clk)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rcim___024root___dump_triggers__nba(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ vlSelf->__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_rcim.clk or negedge tb_rcim.rst_n)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb_rcim.clk)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(negedge tb_rcim.clk)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_rcim___024root___ctor_var_reset(Vtb_rcim___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_rcim__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_rcim__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_rcim__DOT__d_in = VL_RAND_RESET_I(16);
    vlSelf->tb_rcim__DOT__x_in = VL_RAND_RESET_I(16);
    vlSelf->tb_rcim__DOT__samples_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_rcim__DOT__s_axi_awaddr = VL_RAND_RESET_I(5);
    vlSelf->tb_rcim__DOT__s_axi_awvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rcim__DOT__s_axi_wdata = VL_RAND_RESET_I(32);
    vlSelf->tb_rcim__DOT__s_axi_wvalid = VL_RAND_RESET_I(1);
    vlSelf->tb_rcim__DOT__s_axi_awready = VL_RAND_RESET_I(1);
    vlSelf->tb_rcim__DOT__s_axi_wready = VL_RAND_RESET_I(1);
    vlSelf->tb_rcim__DOT__ref_channel_fault = VL_RAND_RESET_I(1);
    vlSelf->tb_rcim__DOT__x_out_muxed = VL_RAND_RESET_I(16);
    vlSelf->tb_rcim__DOT__pass = VL_RAND_RESET_I(32);
    vlSelf->tb_rcim__DOT__fail = VL_RAND_RESET_I(32);
    vlSelf->tb_rcim__DOT__dut__DOT__corr_threshold = VL_RAND_RESET_I(16);
    vlSelf->tb_rcim__DOT__dut__DOT__ratio_shift = VL_RAND_RESET_I(4);
    vlSelf->tb_rcim__DOT__dut__DOT__corr_acc = VL_RAND_RESET_Q(40);
    vlSelf->tb_rcim__DOT__dut__DOT__ref_power_acc = VL_RAND_RESET_Q(40);
    vlSelf->tb_rcim__DOT__dut__DOT__mul_dx = VL_RAND_RESET_I(32);
    vlSelf->tb_rcim__DOT__dut__DOT__mul_xx = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_rcim__DOT__dut__DOT__lutram[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->tb_rcim__DOT__dut__DOT__recip_approx = VL_RAND_RESET_I(16);
    vlSelf->tb_rcim__DOT__dut__DOT__nr_term = VL_RAND_RESET_I(32);
    vlSelf->tb_rcim__DOT__dut__DOT__nr_prod = VL_RAND_RESET_I(32);
    vlSelf->tb_rcim__DOT__dut__DOT__mul_nr1 = VL_RAND_RESET_I(32);
    vlSelf->tb_rcim__DOT__dut__DOT__mul_nr2 = VL_RAND_RESET_I(32);
    vlSelf->tb_rcim__DOT__dut__DOT__norm_corr_prod = VL_RAND_RESET_I(32);
    vlSelf->tb_rcim__DOT__dut__DOT__mul_norm = VL_RAND_RESET_I(32);
    vlSelf->tb_rcim__DOT__dut__DOT__fault_cnt = VL_RAND_RESET_I(8);
    vlSelf->tb_rcim__DOT__dut__DOT__recover_cnt = VL_RAND_RESET_I(8);
    vlSelf->__Vtrigprevexpr___TOP__tb_rcim__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_rcim__DOT__rst_n__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}

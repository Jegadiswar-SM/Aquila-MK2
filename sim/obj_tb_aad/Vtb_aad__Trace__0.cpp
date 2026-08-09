// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_aad__Syms.h"


void Vtb_aad___024root__trace_chg_0_sub_0(Vtb_aad___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_aad___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_aad___024root__trace_chg_0\n"); );
    // Init
    Vtb_aad___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_aad___024root*>(voidSelf);
    Vtb_aad__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_aad___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_aad___024root__trace_chg_0_sub_0(Vtb_aad___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_aad__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_aad___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+0,(vlSelf->tb_aad__DOT__rst_n));
        bufp->chgSData(oldp+1,(vlSelf->tb_aad__DOT__x_in),16);
        bufp->chgBit(oldp+2,(vlSelf->tb_aad__DOT__x_valid));
        bufp->chgCData(oldp+3,(vlSelf->tb_aad__DOT__s_axi_awaddr),4);
        bufp->chgBit(oldp+4,(vlSelf->tb_aad__DOT__s_axi_awvalid));
        bufp->chgIData(oldp+5,(vlSelf->tb_aad__DOT__s_axi_wdata),32);
        bufp->chgBit(oldp+6,(vlSelf->tb_aad__DOT__s_axi_wvalid));
        bufp->chgIData(oldp+7,(vlSelf->tb_aad__DOT__pass),32);
        bufp->chgIData(oldp+8,(vlSelf->tb_aad__DOT__fail),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgBit(oldp+9,(vlSelf->tb_aad__DOT__s_axi_awready));
        bufp->chgBit(oldp+10,(vlSelf->tb_aad__DOT__s_axi_wready));
        bufp->chgBit(oldp+11,(vlSelf->tb_aad__DOT__signal_active));
        bufp->chgBit(oldp+12,(vlSelf->tb_aad__DOT__clk_gate_en));
        bufp->chgQData(oldp+13,(vlSelf->tb_aad__DOT__acc_A_dbg),40);
        bufp->chgQData(oldp+15,(vlSelf->tb_aad__DOT__acc_B_dbg),40);
        bufp->chgCData(oldp+17,(vlSelf->tb_aad__DOT__dut__DOT__ratio_shift_reg),4);
        bufp->chgIData(oldp+18,(vlSelf->tb_aad__DOT__dut__DOT__x_sq),32);
        bufp->chgIData(oldp+19,(vlSelf->tb_aad__DOT__dut__DOT__mul_tmp),32);
        bufp->chgQData(oldp+20,(vlSelf->tb_aad__DOT__dut__DOT__acc_A),40);
        bufp->chgQData(oldp+22,(vlSelf->tb_aad__DOT__dut__DOT__acc_B),40);
        bufp->chgBit(oldp+24,(vlSelf->tb_aad__DOT__dut__DOT__activity_cmp));
        bufp->chgCData(oldp+25,(vlSelf->tb_aad__DOT__dut__DOT__assert_cnt),3);
        bufp->chgCData(oldp+26,(vlSelf->tb_aad__DOT__dut__DOT__deassert_cnt),7);
    }
    bufp->chgBit(oldp+27,(vlSelf->tb_aad__DOT__clk));
}

void Vtb_aad___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_aad___024root__trace_cleanup\n"); );
    // Init
    Vtb_aad___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_aad___024root*>(voidSelf);
    Vtb_aad__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}

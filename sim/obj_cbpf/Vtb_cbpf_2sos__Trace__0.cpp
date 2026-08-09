// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_cbpf_2sos__Syms.h"


void Vtb_cbpf_2sos___024root__trace_chg_0_sub_0(Vtb_cbpf_2sos___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_cbpf_2sos___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root__trace_chg_0\n"); );
    // Init
    Vtb_cbpf_2sos___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_cbpf_2sos___024root*>(voidSelf);
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_cbpf_2sos___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_cbpf_2sos___024root__trace_chg_0_sub_0(Vtb_cbpf_2sos___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+0,(vlSelf->tb_cbpf_2sos__DOT__rst_n));
        bufp->chgSData(oldp+1,(vlSelf->tb_cbpf_2sos__DOT__x_in),16);
        bufp->chgBit(oldp+2,(vlSelf->tb_cbpf_2sos__DOT__x_valid));
        bufp->chgCData(oldp+3,(vlSelf->tb_cbpf_2sos__DOT__s_axi_awaddr),4);
        bufp->chgBit(oldp+4,(vlSelf->tb_cbpf_2sos__DOT__s_axi_awvalid));
        bufp->chgIData(oldp+5,(vlSelf->tb_cbpf_2sos__DOT__s_axi_wdata),32);
        bufp->chgBit(oldp+6,(vlSelf->tb_cbpf_2sos__DOT__s_axi_wvalid));
        bufp->chgIData(oldp+7,(vlSelf->tb_cbpf_2sos__DOT__pass),32);
        bufp->chgIData(oldp+8,(vlSelf->tb_cbpf_2sos__DOT__fail),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgBit(oldp+9,(vlSelf->tb_cbpf_2sos__DOT__s_axi_awready));
        bufp->chgBit(oldp+10,(vlSelf->tb_cbpf_2sos__DOT__s_axi_wready));
        bufp->chgSData(oldp+11,(vlSelf->tb_cbpf_2sos__DOT__y_out),16);
        bufp->chgBit(oldp+12,(vlSelf->tb_cbpf_2sos__DOT__y_valid));
        bufp->chgBit(oldp+13,(vlSelf->tb_cbpf_2sos__DOT__clip_s1));
        bufp->chgBit(oldp+14,(vlSelf->tb_cbpf_2sos__DOT__clip_s2));
        bufp->chgBit(oldp+15,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__bypass_reg));
        bufp->chgIData(oldp+16,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w1_s1),32);
        bufp->chgIData(oldp+17,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w2_s1),32);
        bufp->chgIData(oldp+18,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w0_s1),32);
        bufp->chgIData(oldp+19,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s1),32);
        bufp->chgIData(oldp+20,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_a1_s1),32);
        bufp->chgIData(oldp+21,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_a2_s1),32);
        bufp->chgIData(oldp+22,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b0_s1),32);
        bufp->chgIData(oldp+23,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b1_s1),32);
        bufp->chgIData(oldp+24,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b2_s1),32);
        bufp->chgSData(oldp+25,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s1_trunc),16);
        bufp->chgBit(oldp+26,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg1));
        bufp->chgBit(oldp+27,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg2));
        bufp->chgIData(oldp+28,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w1_s2),32);
        bufp->chgIData(oldp+29,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w2_s2),32);
        bufp->chgIData(oldp+30,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w0_s2),32);
        bufp->chgIData(oldp+31,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s2),32);
        bufp->chgIData(oldp+32,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_a1_s2),32);
        bufp->chgIData(oldp+33,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_a2_s2),32);
        bufp->chgIData(oldp+34,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b0_s2),32);
        bufp->chgIData(oldp+35,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b1_s2),32);
        bufp->chgIData(oldp+36,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b2_s2),32);
        bufp->chgSData(oldp+37,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s2_trunc),16);
        bufp->chgBit(oldp+38,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s2_valid_stg1));
        bufp->chgBit(oldp+39,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s2_valid_stg2));
    }
    bufp->chgBit(oldp+40,(vlSelf->tb_cbpf_2sos__DOT__clk));
}

void Vtb_cbpf_2sos___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root__trace_cleanup\n"); );
    // Init
    Vtb_cbpf_2sos___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_cbpf_2sos___024root*>(voidSelf);
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}

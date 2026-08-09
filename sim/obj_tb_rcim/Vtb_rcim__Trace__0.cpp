// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_rcim__Syms.h"


void Vtb_rcim___024root__trace_chg_0_sub_0(Vtb_rcim___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_rcim___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root__trace_chg_0\n"); );
    // Init
    Vtb_rcim___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_rcim___024root*>(voidSelf);
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_rcim___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_rcim___024root__trace_chg_0_sub_0(Vtb_rcim___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+0,(vlSelf->tb_rcim__DOT__rst_n));
        bufp->chgSData(oldp+1,(vlSelf->tb_rcim__DOT__d_in),16);
        bufp->chgSData(oldp+2,(vlSelf->tb_rcim__DOT__x_in),16);
        bufp->chgBit(oldp+3,(vlSelf->tb_rcim__DOT__samples_valid));
        bufp->chgCData(oldp+4,(vlSelf->tb_rcim__DOT__s_axi_awaddr),5);
        bufp->chgBit(oldp+5,(vlSelf->tb_rcim__DOT__s_axi_awvalid));
        bufp->chgIData(oldp+6,(vlSelf->tb_rcim__DOT__s_axi_wdata),32);
        bufp->chgBit(oldp+7,(vlSelf->tb_rcim__DOT__s_axi_wvalid));
        bufp->chgIData(oldp+8,(vlSelf->tb_rcim__DOT__pass),32);
        bufp->chgIData(oldp+9,(vlSelf->tb_rcim__DOT__fail),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgBit(oldp+10,(vlSelf->tb_rcim__DOT__s_axi_awready));
        bufp->chgBit(oldp+11,(vlSelf->tb_rcim__DOT__s_axi_wready));
        bufp->chgBit(oldp+12,(vlSelf->tb_rcim__DOT__ref_channel_fault));
        bufp->chgSData(oldp+13,(vlSelf->tb_rcim__DOT__x_out_muxed),16);
        bufp->chgSData(oldp+14,(vlSelf->tb_rcim__DOT__dut__DOT__corr_threshold),16);
        bufp->chgCData(oldp+15,(vlSelf->tb_rcim__DOT__dut__DOT__ratio_shift),4);
        bufp->chgQData(oldp+16,(vlSelf->tb_rcim__DOT__dut__DOT__corr_acc),40);
        bufp->chgQData(oldp+18,(vlSelf->tb_rcim__DOT__dut__DOT__ref_power_acc),40);
        bufp->chgIData(oldp+20,(vlSelf->tb_rcim__DOT__dut__DOT__mul_dx),32);
        bufp->chgIData(oldp+21,(vlSelf->tb_rcim__DOT__dut__DOT__mul_xx),32);
        bufp->chgSData(oldp+22,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[0]),16);
        bufp->chgSData(oldp+23,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[1]),16);
        bufp->chgSData(oldp+24,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[2]),16);
        bufp->chgSData(oldp+25,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[3]),16);
        bufp->chgSData(oldp+26,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[4]),16);
        bufp->chgSData(oldp+27,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[5]),16);
        bufp->chgSData(oldp+28,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[6]),16);
        bufp->chgSData(oldp+29,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[7]),16);
        bufp->chgSData(oldp+30,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[8]),16);
        bufp->chgSData(oldp+31,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[9]),16);
        bufp->chgSData(oldp+32,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[10]),16);
        bufp->chgSData(oldp+33,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[11]),16);
        bufp->chgSData(oldp+34,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[12]),16);
        bufp->chgSData(oldp+35,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[13]),16);
        bufp->chgSData(oldp+36,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[14]),16);
        bufp->chgSData(oldp+37,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[15]),16);
        bufp->chgCData(oldp+38,((0xfU & (IData)((vlSelf->tb_rcim__DOT__dut__DOT__ref_power_acc 
                                                 >> 0x23U)))),4);
        bufp->chgSData(oldp+39,(vlSelf->tb_rcim__DOT__dut__DOT__recip_approx),16);
        bufp->chgSData(oldp+40,((0xffffU & (IData)(
                                                   (vlSelf->tb_rcim__DOT__dut__DOT__ref_power_acc 
                                                    >> 0xfU)))),16);
        bufp->chgSData(oldp+41,((0xffffU & (vlSelf->tb_rcim__DOT__dut__DOT__mul_nr2 
                                            >> 0xfU))),16);
        bufp->chgIData(oldp+42,(vlSelf->tb_rcim__DOT__dut__DOT__mul_nr1),32);
        bufp->chgIData(oldp+43,(vlSelf->tb_rcim__DOT__dut__DOT__mul_nr2),32);
        bufp->chgSData(oldp+44,((0xffffU & ((1U & (IData)(
                                                          (vlSelf->tb_rcim__DOT__dut__DOT__corr_acc 
                                                           >> 0x1fU)))
                                             ? ((IData)(1U) 
                                                + (~ (IData)(
                                                             (vlSelf->tb_rcim__DOT__dut__DOT__corr_acc 
                                                              >> 0xfU))))
                                             : (IData)(
                                                       (vlSelf->tb_rcim__DOT__dut__DOT__corr_acc 
                                                        >> 0xfU))))),16);
        bufp->chgSData(oldp+45,((0xffffU & (vlSelf->tb_rcim__DOT__dut__DOT__mul_norm 
                                            >> 0xfU))),16);
        bufp->chgIData(oldp+46,(vlSelf->tb_rcim__DOT__dut__DOT__mul_norm),32);
        bufp->chgCData(oldp+47,(vlSelf->tb_rcim__DOT__dut__DOT__fault_cnt),8);
        bufp->chgCData(oldp+48,(vlSelf->tb_rcim__DOT__dut__DOT__recover_cnt),8);
    }
    bufp->chgBit(oldp+49,(vlSelf->tb_rcim__DOT__clk));
}

void Vtb_rcim___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root__trace_cleanup\n"); );
    // Init
    Vtb_rcim___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_rcim___024root*>(voidSelf);
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
}

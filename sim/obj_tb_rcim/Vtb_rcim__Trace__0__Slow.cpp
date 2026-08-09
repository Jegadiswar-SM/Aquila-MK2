// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_rcim__Syms.h"


VL_ATTR_COLD void Vtb_rcim___024root__trace_init_sub__TOP__0(Vtb_rcim___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("tb_rcim", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+50,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"d_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"x_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+4,0,"samples_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"s_axi_awaddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+6,0,"s_axi_awvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"s_axi_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+8,0,"s_axi_wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"s_axi_awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"s_axi_wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"ref_channel_fault",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+14,0,"x_out_muxed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+9,0,"pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+10,0,"fail",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+51,0,"WINDOW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+52,0,"FAULT_PERSIST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+53,0,"LUTRAM_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+50,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"d_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+3,0,"x_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+4,0,"samples_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+5,0,"s_axi_awaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+6,0,"s_axi_awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+7,0,"s_axi_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+8,0,"s_axi_wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"s_axi_awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+12,0,"s_axi_wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+13,0,"ref_channel_fault",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+14,0,"x_out_muxed",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+15,0,"corr_threshold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+16,0,"ratio_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declQuad(c+17,0,"corr_acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declQuad(c+19,0,"ref_power_acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declBus(c+21,0,"mul_dx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+22,0,"mul_xx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("lutram", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+23+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+39,0,"lut_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+40,0,"recip_approx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+41,0,"ref_power_norm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+54,0,"nr_term",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+55,0,"nr_prod",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"refined_recip",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+43,0,"mul_nr1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+44,0,"mul_nr2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+45,0,"corr_mag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+56,0,"norm_corr_prod",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+46,0,"norm_corr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+47,0,"mul_norm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+48,0,"fault_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+49,0,"recover_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_rcim___024root__trace_init_top(Vtb_rcim___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root__trace_init_top\n"); );
    // Body
    Vtb_rcim___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_rcim___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_rcim___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_rcim___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_rcim___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_rcim___024root__trace_register(Vtb_rcim___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vtb_rcim___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtb_rcim___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtb_rcim___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtb_rcim___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_rcim___024root__trace_const_0_sub_0(Vtb_rcim___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_rcim___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root__trace_const_0\n"); );
    // Init
    Vtb_rcim___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_rcim___024root*>(voidSelf);
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_rcim___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_rcim___024root__trace_const_0_sub_0(Vtb_rcim___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+51,(0x20U),32);
    bufp->fullIData(oldp+52,(0x80U),32);
    bufp->fullIData(oldp+53,(0x10U),32);
    bufp->fullIData(oldp+54,(vlSelf->tb_rcim__DOT__dut__DOT__nr_term),32);
    bufp->fullIData(oldp+55,(vlSelf->tb_rcim__DOT__dut__DOT__nr_prod),32);
    bufp->fullIData(oldp+56,(vlSelf->tb_rcim__DOT__dut__DOT__norm_corr_prod),32);
}

VL_ATTR_COLD void Vtb_rcim___024root__trace_full_0_sub_0(Vtb_rcim___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_rcim___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root__trace_full_0\n"); );
    // Init
    Vtb_rcim___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_rcim___024root*>(voidSelf);
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_rcim___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_rcim___024root__trace_full_0_sub_0(Vtb_rcim___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rcim__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rcim___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->tb_rcim__DOT__rst_n));
    bufp->fullSData(oldp+2,(vlSelf->tb_rcim__DOT__d_in),16);
    bufp->fullSData(oldp+3,(vlSelf->tb_rcim__DOT__x_in),16);
    bufp->fullBit(oldp+4,(vlSelf->tb_rcim__DOT__samples_valid));
    bufp->fullCData(oldp+5,(vlSelf->tb_rcim__DOT__s_axi_awaddr),5);
    bufp->fullBit(oldp+6,(vlSelf->tb_rcim__DOT__s_axi_awvalid));
    bufp->fullIData(oldp+7,(vlSelf->tb_rcim__DOT__s_axi_wdata),32);
    bufp->fullBit(oldp+8,(vlSelf->tb_rcim__DOT__s_axi_wvalid));
    bufp->fullIData(oldp+9,(vlSelf->tb_rcim__DOT__pass),32);
    bufp->fullIData(oldp+10,(vlSelf->tb_rcim__DOT__fail),32);
    bufp->fullBit(oldp+11,(vlSelf->tb_rcim__DOT__s_axi_awready));
    bufp->fullBit(oldp+12,(vlSelf->tb_rcim__DOT__s_axi_wready));
    bufp->fullBit(oldp+13,(vlSelf->tb_rcim__DOT__ref_channel_fault));
    bufp->fullSData(oldp+14,(vlSelf->tb_rcim__DOT__x_out_muxed),16);
    bufp->fullSData(oldp+15,(vlSelf->tb_rcim__DOT__dut__DOT__corr_threshold),16);
    bufp->fullCData(oldp+16,(vlSelf->tb_rcim__DOT__dut__DOT__ratio_shift),4);
    bufp->fullQData(oldp+17,(vlSelf->tb_rcim__DOT__dut__DOT__corr_acc),40);
    bufp->fullQData(oldp+19,(vlSelf->tb_rcim__DOT__dut__DOT__ref_power_acc),40);
    bufp->fullIData(oldp+21,(vlSelf->tb_rcim__DOT__dut__DOT__mul_dx),32);
    bufp->fullIData(oldp+22,(vlSelf->tb_rcim__DOT__dut__DOT__mul_xx),32);
    bufp->fullSData(oldp+23,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[0]),16);
    bufp->fullSData(oldp+24,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[1]),16);
    bufp->fullSData(oldp+25,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[2]),16);
    bufp->fullSData(oldp+26,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[3]),16);
    bufp->fullSData(oldp+27,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[4]),16);
    bufp->fullSData(oldp+28,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[5]),16);
    bufp->fullSData(oldp+29,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[6]),16);
    bufp->fullSData(oldp+30,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[7]),16);
    bufp->fullSData(oldp+31,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[8]),16);
    bufp->fullSData(oldp+32,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[9]),16);
    bufp->fullSData(oldp+33,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[10]),16);
    bufp->fullSData(oldp+34,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[11]),16);
    bufp->fullSData(oldp+35,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[12]),16);
    bufp->fullSData(oldp+36,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[13]),16);
    bufp->fullSData(oldp+37,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[14]),16);
    bufp->fullSData(oldp+38,(vlSelf->tb_rcim__DOT__dut__DOT__lutram[15]),16);
    bufp->fullCData(oldp+39,((0xfU & (IData)((vlSelf->tb_rcim__DOT__dut__DOT__ref_power_acc 
                                              >> 0x23U)))),4);
    bufp->fullSData(oldp+40,(vlSelf->tb_rcim__DOT__dut__DOT__recip_approx),16);
    bufp->fullSData(oldp+41,((0xffffU & (IData)((vlSelf->tb_rcim__DOT__dut__DOT__ref_power_acc 
                                                 >> 0xfU)))),16);
    bufp->fullSData(oldp+42,((0xffffU & (vlSelf->tb_rcim__DOT__dut__DOT__mul_nr2 
                                         >> 0xfU))),16);
    bufp->fullIData(oldp+43,(vlSelf->tb_rcim__DOT__dut__DOT__mul_nr1),32);
    bufp->fullIData(oldp+44,(vlSelf->tb_rcim__DOT__dut__DOT__mul_nr2),32);
    bufp->fullSData(oldp+45,((0xffffU & ((1U & (IData)(
                                                       (vlSelf->tb_rcim__DOT__dut__DOT__corr_acc 
                                                        >> 0x1fU)))
                                          ? ((IData)(1U) 
                                             + (~ (IData)(
                                                          (vlSelf->tb_rcim__DOT__dut__DOT__corr_acc 
                                                           >> 0xfU))))
                                          : (IData)(
                                                    (vlSelf->tb_rcim__DOT__dut__DOT__corr_acc 
                                                     >> 0xfU))))),16);
    bufp->fullSData(oldp+46,((0xffffU & (vlSelf->tb_rcim__DOT__dut__DOT__mul_norm 
                                         >> 0xfU))),16);
    bufp->fullIData(oldp+47,(vlSelf->tb_rcim__DOT__dut__DOT__mul_norm),32);
    bufp->fullCData(oldp+48,(vlSelf->tb_rcim__DOT__dut__DOT__fault_cnt),8);
    bufp->fullCData(oldp+49,(vlSelf->tb_rcim__DOT__dut__DOT__recover_cnt),8);
    bufp->fullBit(oldp+50,(vlSelf->tb_rcim__DOT__clk));
}

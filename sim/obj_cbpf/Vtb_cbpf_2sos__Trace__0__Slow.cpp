// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_cbpf_2sos__Syms.h"


VL_ATTR_COLD void Vtb_cbpf_2sos___024root__trace_init_sub__TOP__0(Vtb_cbpf_2sos___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("tb_cbpf_2sos", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+41,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"x_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+3,0,"x_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"s_axi_awaddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+5,0,"s_axi_awvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"s_axi_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+7,0,"s_axi_wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"s_axi_awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"s_axi_wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"y_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+13,0,"y_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"clip_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"clip_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"pass",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+9,0,"fail",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+41,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+1,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+2,0,"x_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+3,0,"x_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+4,0,"s_axi_awaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+5,0,"s_axi_awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+6,0,"s_axi_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+7,0,"s_axi_wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+10,0,"s_axi_awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+11,0,"s_axi_wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+12,0,"y_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+13,0,"y_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"clip_s1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+15,0,"clip_s2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+42,0,"B0_S1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+43,0,"B1_S1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+42,0,"B2_S1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+44,0,"A1_S1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+45,0,"A2_S1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+46,0,"B0_S2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+47,0,"B1_S2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+46,0,"B2_S2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+48,0,"A1_S2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+49,0,"A2_S2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+16,0,"bypass_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+17,0,"w1_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+18,0,"w2_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+19,0,"w0_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+20,0,"y_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+21,0,"mul_a1_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+22,0,"mul_a2_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+23,0,"mul_b0_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"mul_b1_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,0,"mul_b2_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+26,0,"y_s1_trunc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+27,0,"s1_valid_stg1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+28,0,"s1_valid_stg2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+29,0,"w1_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+30,0,"w2_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+31,0,"w0_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+32,0,"y_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+33,0,"mul_a1_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+34,0,"mul_a2_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+35,0,"mul_b0_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+36,0,"mul_b1_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+37,0,"mul_b2_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+38,0,"y_s2_trunc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+39,0,"s2_valid_stg1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+40,0,"s2_valid_stg2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_cbpf_2sos___024root__trace_init_top(Vtb_cbpf_2sos___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root__trace_init_top\n"); );
    // Body
    Vtb_cbpf_2sos___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_cbpf_2sos___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_cbpf_2sos___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_cbpf_2sos___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_cbpf_2sos___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_cbpf_2sos___024root__trace_register(Vtb_cbpf_2sos___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vtb_cbpf_2sos___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtb_cbpf_2sos___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtb_cbpf_2sos___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtb_cbpf_2sos___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_cbpf_2sos___024root__trace_const_0_sub_0(Vtb_cbpf_2sos___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_cbpf_2sos___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root__trace_const_0\n"); );
    // Init
    Vtb_cbpf_2sos___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_cbpf_2sos___024root*>(voidSelf);
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_cbpf_2sos___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_cbpf_2sos___024root__trace_const_0_sub_0(Vtb_cbpf_2sos___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullSData(oldp+42,(0x2afU),16);
    bufp->fullSData(oldp+43,(0x55eU),16);
    bufp->fullSData(oldp+44,(0x7fffU),16);
    bufp->fullSData(oldp+45,(0xc250U),16);
    bufp->fullSData(oldp+46,(0x4000U),16);
    bufp->fullSData(oldp+47,(0x8000U),16);
    bufp->fullSData(oldp+48,(0x7148U),16);
    bufp->fullSData(oldp+49,(0xcaa1U),16);
}

VL_ATTR_COLD void Vtb_cbpf_2sos___024root__trace_full_0_sub_0(Vtb_cbpf_2sos___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_cbpf_2sos___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root__trace_full_0\n"); );
    // Init
    Vtb_cbpf_2sos___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_cbpf_2sos___024root*>(voidSelf);
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_cbpf_2sos___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_cbpf_2sos___024root__trace_full_0_sub_0(Vtb_cbpf_2sos___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_cbpf_2sos__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_cbpf_2sos___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->tb_cbpf_2sos__DOT__rst_n));
    bufp->fullSData(oldp+2,(vlSelf->tb_cbpf_2sos__DOT__x_in),16);
    bufp->fullBit(oldp+3,(vlSelf->tb_cbpf_2sos__DOT__x_valid));
    bufp->fullCData(oldp+4,(vlSelf->tb_cbpf_2sos__DOT__s_axi_awaddr),4);
    bufp->fullBit(oldp+5,(vlSelf->tb_cbpf_2sos__DOT__s_axi_awvalid));
    bufp->fullIData(oldp+6,(vlSelf->tb_cbpf_2sos__DOT__s_axi_wdata),32);
    bufp->fullBit(oldp+7,(vlSelf->tb_cbpf_2sos__DOT__s_axi_wvalid));
    bufp->fullIData(oldp+8,(vlSelf->tb_cbpf_2sos__DOT__pass),32);
    bufp->fullIData(oldp+9,(vlSelf->tb_cbpf_2sos__DOT__fail),32);
    bufp->fullBit(oldp+10,(vlSelf->tb_cbpf_2sos__DOT__s_axi_awready));
    bufp->fullBit(oldp+11,(vlSelf->tb_cbpf_2sos__DOT__s_axi_wready));
    bufp->fullSData(oldp+12,(vlSelf->tb_cbpf_2sos__DOT__y_out),16);
    bufp->fullBit(oldp+13,(vlSelf->tb_cbpf_2sos__DOT__y_valid));
    bufp->fullBit(oldp+14,(vlSelf->tb_cbpf_2sos__DOT__clip_s1));
    bufp->fullBit(oldp+15,(vlSelf->tb_cbpf_2sos__DOT__clip_s2));
    bufp->fullBit(oldp+16,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__bypass_reg));
    bufp->fullIData(oldp+17,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w1_s1),32);
    bufp->fullIData(oldp+18,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w2_s1),32);
    bufp->fullIData(oldp+19,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w0_s1),32);
    bufp->fullIData(oldp+20,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s1),32);
    bufp->fullIData(oldp+21,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_a1_s1),32);
    bufp->fullIData(oldp+22,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_a2_s1),32);
    bufp->fullIData(oldp+23,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b0_s1),32);
    bufp->fullIData(oldp+24,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b1_s1),32);
    bufp->fullIData(oldp+25,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b2_s1),32);
    bufp->fullSData(oldp+26,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s1_trunc),16);
    bufp->fullBit(oldp+27,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg1));
    bufp->fullBit(oldp+28,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s1_valid_stg2));
    bufp->fullIData(oldp+29,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w1_s2),32);
    bufp->fullIData(oldp+30,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w2_s2),32);
    bufp->fullIData(oldp+31,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__w0_s2),32);
    bufp->fullIData(oldp+32,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s2),32);
    bufp->fullIData(oldp+33,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_a1_s2),32);
    bufp->fullIData(oldp+34,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_a2_s2),32);
    bufp->fullIData(oldp+35,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b0_s2),32);
    bufp->fullIData(oldp+36,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b1_s2),32);
    bufp->fullIData(oldp+37,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__mul_b2_s2),32);
    bufp->fullSData(oldp+38,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__y_s2_trunc),16);
    bufp->fullBit(oldp+39,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s2_valid_stg1));
    bufp->fullBit(oldp+40,(vlSelf->tb_cbpf_2sos__DOT__dut__DOT__s2_valid_stg2));
    bufp->fullBit(oldp+41,(vlSelf->tb_cbpf_2sos__DOT__clk));
}

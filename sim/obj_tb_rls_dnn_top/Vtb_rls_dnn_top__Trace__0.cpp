// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_rls_dnn_top__Syms.h"


void Vtb_rls_dnn_top___024root__trace_chg_0_sub_0(Vtb_rls_dnn_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_rls_dnn_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root__trace_chg_0\n"); );
    // Init
    Vtb_rls_dnn_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_rls_dnn_top___024root*>(voidSelf);
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_rls_dnn_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_rls_dnn_top___024root__trace_chg_0_sub_0(Vtb_rls_dnn_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    VlWide<4>/*127:0*/ __Vtemp_3;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgSData(oldp+0,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0]),16);
        bufp->chgSData(oldp+1,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[1]),16);
        bufp->chgSData(oldp+2,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[2]),16);
        bufp->chgSData(oldp+3,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[3]),16);
        bufp->chgSData(oldp+4,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[4]),16);
        bufp->chgSData(oldp+5,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[5]),16);
        bufp->chgSData(oldp+6,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[6]),16);
        bufp->chgSData(oldp+7,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[7]),16);
        bufp->chgSData(oldp+8,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[8]),16);
        bufp->chgSData(oldp+9,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[9]),16);
        bufp->chgSData(oldp+10,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[10]),16);
        bufp->chgSData(oldp+11,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[11]),16);
        bufp->chgSData(oldp+12,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[12]),16);
        bufp->chgSData(oldp+13,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[13]),16);
        bufp->chgSData(oldp+14,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[14]),16);
        bufp->chgSData(oldp+15,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[15]),16);
        bufp->chgSData(oldp+16,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[16]),16);
        bufp->chgSData(oldp+17,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[17]),16);
        bufp->chgSData(oldp+18,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[18]),16);
        bufp->chgSData(oldp+19,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[19]),16);
        bufp->chgSData(oldp+20,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[20]),16);
        bufp->chgSData(oldp+21,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[21]),16);
        bufp->chgSData(oldp+22,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[22]),16);
        bufp->chgSData(oldp+23,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[23]),16);
        bufp->chgSData(oldp+24,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[24]),16);
        bufp->chgSData(oldp+25,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[25]),16);
        bufp->chgSData(oldp+26,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[26]),16);
        bufp->chgSData(oldp+27,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[27]),16);
        bufp->chgSData(oldp+28,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[28]),16);
        bufp->chgSData(oldp+29,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[29]),16);
        bufp->chgSData(oldp+30,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[30]),16);
        bufp->chgSData(oldp+31,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[31]),16);
        bufp->chgSData(oldp+32,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0]),16);
        bufp->chgSData(oldp+33,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[1]),16);
        bufp->chgSData(oldp+34,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[2]),16);
        bufp->chgSData(oldp+35,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[3]),16);
        bufp->chgSData(oldp+36,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[4]),16);
        bufp->chgSData(oldp+37,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[5]),16);
        bufp->chgSData(oldp+38,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[6]),16);
        bufp->chgSData(oldp+39,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[7]),16);
        bufp->chgSData(oldp+40,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[8]),16);
        bufp->chgSData(oldp+41,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[9]),16);
        bufp->chgSData(oldp+42,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[10]),16);
        bufp->chgSData(oldp+43,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[11]),16);
        bufp->chgSData(oldp+44,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[12]),16);
        bufp->chgSData(oldp+45,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[13]),16);
        bufp->chgSData(oldp+46,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[14]),16);
        bufp->chgSData(oldp+47,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[15]),16);
        bufp->chgSData(oldp+48,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[16]),16);
        bufp->chgSData(oldp+49,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[17]),16);
        bufp->chgSData(oldp+50,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[18]),16);
        bufp->chgSData(oldp+51,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[19]),16);
        bufp->chgSData(oldp+52,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[20]),16);
        bufp->chgSData(oldp+53,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[21]),16);
        bufp->chgSData(oldp+54,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[22]),16);
        bufp->chgSData(oldp+55,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[23]),16);
        bufp->chgSData(oldp+56,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[24]),16);
        bufp->chgSData(oldp+57,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[25]),16);
        bufp->chgSData(oldp+58,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[26]),16);
        bufp->chgSData(oldp+59,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[27]),16);
        bufp->chgSData(oldp+60,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[28]),16);
        bufp->chgSData(oldp+61,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[29]),16);
        bufp->chgSData(oldp+62,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[30]),16);
        bufp->chgSData(oldp+63,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[31]),16);
        bufp->chgSData(oldp+64,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b3_rom[0]),16);
        bufp->chgSData(oldp+65,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[0]),16);
        bufp->chgSData(oldp+66,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[1]),16);
        bufp->chgSData(oldp+67,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[2]),16);
        bufp->chgSData(oldp+68,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[3]),16);
        bufp->chgSData(oldp+69,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[4]),16);
        bufp->chgSData(oldp+70,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[5]),16);
        bufp->chgSData(oldp+71,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[6]),16);
        bufp->chgSData(oldp+72,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[7]),16);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+73,(vlSelf->tb_rls_dnn_top__DOT__rst_n));
        bufp->chgBit(oldp+74,(vlSelf->tb_rls_dnn_top__DOT__m_axis_tready));
        bufp->chgCData(oldp+75,(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr),8);
        bufp->chgBit(oldp+76,(vlSelf->tb_rls_dnn_top__DOT__s_axi_awvalid));
        bufp->chgIData(oldp+77,(vlSelf->tb_rls_dnn_top__DOT__s_axi_wdata),32);
        bufp->chgBit(oldp+78,(vlSelf->tb_rls_dnn_top__DOT__s_axi_wvalid));
        bufp->chgBit(oldp+79,(vlSelf->tb_rls_dnn_top__DOT__s_axi_bready));
        bufp->chgCData(oldp+80,(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr),8);
        bufp->chgBit(oldp+81,(vlSelf->tb_rls_dnn_top__DOT__s_axi_arvalid));
        bufp->chgBit(oldp+82,(vlSelf->tb_rls_dnn_top__DOT__s_axi_rready));
        bufp->chgCData(oldp+83,((7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                       >> 4U))),3);
        bufp->chgBit(oldp+84,((0U == (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                            >> 4U)))));
        bufp->chgBit(oldp+85,((1U == (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                            >> 4U)))));
        bufp->chgBit(oldp+86,((2U == (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                            >> 4U)))));
        bufp->chgBit(oldp+87,((3U == (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                            >> 4U)))));
        bufp->chgBit(oldp+88,((4U == (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                            >> 4U)))));
        bufp->chgBit(oldp+89,((5U == (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                            >> 4U)))));
        bufp->chgBit(oldp+90,((6U <= (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                            >> 4U)))));
        bufp->chgCData(oldp+91,((7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr) 
                                       >> 4U))),3);
        bufp->chgBit(oldp+92,((3U == (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr) 
                                            >> 4U)))));
        bufp->chgBit(oldp+93,((6U == (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr) 
                                            >> 4U)))));
        bufp->chgCData(oldp+94,((0xfU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))),4);
        bufp->chgCData(oldp+95,((0x1fU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))),5);
        bufp->chgCData(oldp+96,((0xfU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr))),4);
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[3U] 
                     | vlSelf->__Vm_traceActivity[7U]))) {
        bufp->chgBit(oldp+97,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_affhc__s_axi_awvalid));
        bufp->chgBit(oldp+98,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_affhc__s_axi_wvalid));
        bufp->chgBit(oldp+99,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_plwd__s_axi_arvalid));
        bufp->chgBit(oldp+100,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_plwd__s_axi_awvalid));
        bufp->chgBit(oldp+101,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_plwd__s_axi_wvalid));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[3U] 
                     | vlSelf->__Vm_traceActivity[0xaU]))) {
        bufp->chgBit(oldp+102,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__s_axi_awvalid));
        bufp->chgBit(oldp+103,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__s_axi_wvalid));
        bufp->chgBit(oldp+104,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_latprof__s_axi_arvalid));
        bufp->chgBit(oldp+105,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_rcim__s_axi_awvalid));
        bufp->chgBit(oldp+106,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_rcim__s_axi_wvalid));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgBit(oldp+107,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_clk_gate_en));
        bufp->chgBit(oldp+108,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_clip_s1));
        bufp->chgBit(oldp+109,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_signal_active));
        bufp->chgQData(oldp+110,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__acc_A_dbg),40);
        bufp->chgQData(oldp+112,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__acc_B_dbg),40);
        bufp->chgCData(oldp+114,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__ratio_shift_reg),4);
        bufp->chgIData(oldp+115,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__x_sq),32);
        bufp->chgIData(oldp+116,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__mul_tmp),32);
        bufp->chgQData(oldp+117,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__acc_A),40);
        bufp->chgQData(oldp+119,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__acc_B),40);
        bufp->chgBit(oldp+121,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__activity_cmp));
        bufp->chgCData(oldp+122,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__assert_cnt),3);
        bufp->chgCData(oldp+123,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__deassert_cnt),7);
        bufp->chgIData(oldp+124,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w1_s1),32);
        bufp->chgIData(oldp+125,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w2_s1),32);
        bufp->chgIData(oldp+126,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w0_s1),32);
        bufp->chgIData(oldp+127,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s1),32);
        bufp->chgIData(oldp+128,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_a1_s1),32);
        bufp->chgIData(oldp+129,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_a2_s1),32);
        bufp->chgIData(oldp+130,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b0_s1),32);
        bufp->chgIData(oldp+131,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b1_s1),32);
        bufp->chgIData(oldp+132,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b2_s1),32);
        bufp->chgSData(oldp+133,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s1_trunc),16);
        bufp->chgBit(oldp+134,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s1_valid_stg1));
        bufp->chgSData(oldp+135,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__corr_threshold),16);
        bufp->chgCData(oldp+136,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__ratio_shift),4);
        bufp->chgQData(oldp+137,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__corr_acc),40);
        bufp->chgQData(oldp+139,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__ref_power_acc),40);
        bufp->chgIData(oldp+141,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__mul_dx),32);
        bufp->chgIData(oldp+142,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__mul_xx),32);
        bufp->chgSData(oldp+143,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[0]),16);
        bufp->chgSData(oldp+144,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[1]),16);
        bufp->chgSData(oldp+145,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[2]),16);
        bufp->chgSData(oldp+146,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[3]),16);
        bufp->chgSData(oldp+147,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[4]),16);
        bufp->chgSData(oldp+148,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[5]),16);
        bufp->chgSData(oldp+149,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[6]),16);
        bufp->chgSData(oldp+150,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[7]),16);
        bufp->chgSData(oldp+151,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[8]),16);
        bufp->chgSData(oldp+152,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[9]),16);
        bufp->chgSData(oldp+153,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[10]),16);
        bufp->chgSData(oldp+154,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[11]),16);
        bufp->chgSData(oldp+155,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[12]),16);
        bufp->chgSData(oldp+156,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[13]),16);
        bufp->chgSData(oldp+157,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[14]),16);
        bufp->chgSData(oldp+158,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[15]),16);
        bufp->chgCData(oldp+159,((0xfU & (IData)((vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__ref_power_acc 
                                                  >> 0x23U)))),4);
        bufp->chgSData(oldp+160,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__recip_approx),16);
        bufp->chgSData(oldp+161,((0xffffU & (IData)(
                                                    (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__ref_power_acc 
                                                     >> 0xfU)))),16);
        bufp->chgSData(oldp+162,((0xffffU & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__mul_nr2 
                                             >> 0xfU))),16);
        bufp->chgIData(oldp+163,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__mul_nr1),32);
        bufp->chgIData(oldp+164,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__mul_nr2),32);
        bufp->chgSData(oldp+165,((0xffffU & ((1U & (IData)(
                                                           (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__corr_acc 
                                                            >> 0x1fU)))
                                              ? ((IData)(1U) 
                                                 + 
                                                 (~ (IData)(
                                                            (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__corr_acc 
                                                             >> 0xfU))))
                                              : (IData)(
                                                        (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__corr_acc 
                                                         >> 0xfU))))),16);
        bufp->chgSData(oldp+166,((0xffffU & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__mul_norm 
                                             >> 0xfU))),16);
        bufp->chgIData(oldp+167,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__mul_norm),32);
        bufp->chgCData(oldp+168,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__fault_cnt),8);
        bufp->chgCData(oldp+169,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__recover_cnt),8);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[5U])) {
        bufp->chgIData(oldp+170,(vlSelf->tb_rls_dnn_top__DOT__out_cnt),32);
        bufp->chgIData(oldp+171,(vlSelf->tb_rls_dnn_top__DOT__pass_cnt),32);
        bufp->chgIData(oldp+172,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__i),32);
        __Vtemp_3[0U] = ((vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                          [6U] << 0x10U) | vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                         [7U]);
        __Vtemp_3[1U] = (((0xffffU & vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                           [5U]) | (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                                    [6U] >> 0x10U)) 
                         | ((IData)((((QData)((IData)(
                                                      ((vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                                                        [1U] 
                                                        << 0x10U) 
                                                       | vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                                                       [2U]))) 
                                      << 0x20U) | (QData)((IData)(
                                                                  ((vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                                                                    [3U] 
                                                                    << 0x10U) 
                                                                   | vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                                                                   [4U]))))) 
                            << 0x10U));
        __Vtemp_3[2U] = (((IData)((((QData)((IData)(
                                                    ((vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                                                      [1U] 
                                                      << 0x10U) 
                                                     | vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                                                     [2U]))) 
                                    << 0x20U) | (QData)((IData)(
                                                                ((vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                                                                  [3U] 
                                                                  << 0x10U) 
                                                                 | vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                                                                 [4U]))))) 
                          >> 0x10U) | ((IData)(((((QData)((IData)(
                                                                  ((vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                                                                    [1U] 
                                                                    << 0x10U) 
                                                                   | vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                                                                   [2U]))) 
                                                  << 0x20U) 
                                                 | (QData)((IData)(
                                                                   ((vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                                                                     [3U] 
                                                                     << 0x10U) 
                                                                    | vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                                                                    [4U])))) 
                                                >> 0x20U)) 
                                       << 0x10U));
        __Vtemp_3[3U] = ((vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                          [0U] << 0x10U) | ((IData)(
                                                    ((((QData)((IData)(
                                                                       ((vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                                                                         [1U] 
                                                                         << 0x10U) 
                                                                        | vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                                                                        [2U]))) 
                                                       << 0x20U) 
                                                      | (QData)((IData)(
                                                                        ((vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                                                                          [3U] 
                                                                          << 0x10U) 
                                                                         | vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                                                                         [4U])))) 
                                                     >> 0x20U)) 
                                            >> 0x10U));
        bufp->chgWData(oldp+173,(__Vtemp_3),128);
        bufp->chgSData(oldp+177,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__mlp_noise_est),16);
        bufp->chgSData(oldp+178,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__fwes_e_weighted),16);
        bufp->chgSData(oldp+179,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_err_pipe[0]),16);
        bufp->chgSData(oldp+180,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_err_pipe[1]),16);
        bufp->chgSData(oldp+181,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_err_pipe[2]),16);
        bufp->chgBit(oldp+182,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_vld_pipe[0]));
        bufp->chgBit(oldp+183,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_vld_pipe[1]));
        bufp->chgBit(oldp+184,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_vld_pipe[2]));
        bufp->chgIData(oldp+185,((0x1ffffU & VL_SHIFTR_III(17,17,32, 
                                                           ((0x10000U 
                                                             & ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__mlp_noise_est) 
                                                                << 1U)) 
                                                            | (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__mlp_noise_est)), 4U))),17);
        bufp->chgBit(oldp+186,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__latprof_rvalid));
        bufp->chgSData(oldp+187,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_leak_factor),16);
        bufp->chgSData(oldp+188,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__fwes_alpha_reg),16);
        bufp->chgSData(oldp+189,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_fwes__DOT__e_w_prev),16);
        bufp->chgIData(oldp+190,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_fwes__DOT__unnamedblk1__DOT__alpha_term),32);
        bufp->chgIData(oldp+191,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__free_cnt_snap),32);
        bufp->chgSData(oldp+192,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[0]),16);
        bufp->chgSData(oldp+193,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[1]),16);
        bufp->chgSData(oldp+194,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[2]),16);
        bufp->chgSData(oldp+195,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[3]),16);
        bufp->chgSData(oldp+196,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[4]),16);
        bufp->chgSData(oldp+197,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[5]),16);
        bufp->chgSData(oldp+198,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[6]),16);
        bufp->chgSData(oldp+199,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[7]),16);
        bufp->chgSData(oldp+200,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[0]),16);
        bufp->chgSData(oldp+201,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[1]),16);
        bufp->chgSData(oldp+202,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[2]),16);
        bufp->chgSData(oldp+203,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[3]),16);
        bufp->chgSData(oldp+204,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[4]),16);
        bufp->chgSData(oldp+205,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[5]),16);
        bufp->chgSData(oldp+206,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[6]),16);
        bufp->chgSData(oldp+207,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[7]),16);
        bufp->chgSData(oldp+208,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[8]),16);
        bufp->chgSData(oldp+209,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[9]),16);
        bufp->chgSData(oldp+210,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[10]),16);
        bufp->chgSData(oldp+211,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[11]),16);
        bufp->chgSData(oldp+212,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[12]),16);
        bufp->chgSData(oldp+213,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[13]),16);
        bufp->chgSData(oldp+214,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[14]),16);
        bufp->chgSData(oldp+215,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[15]),16);
        bufp->chgSData(oldp+216,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[16]),16);
        bufp->chgSData(oldp+217,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[17]),16);
        bufp->chgSData(oldp+218,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[18]),16);
        bufp->chgSData(oldp+219,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[19]),16);
        bufp->chgSData(oldp+220,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[20]),16);
        bufp->chgSData(oldp+221,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[21]),16);
        bufp->chgSData(oldp+222,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[22]),16);
        bufp->chgSData(oldp+223,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[23]),16);
        bufp->chgSData(oldp+224,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[24]),16);
        bufp->chgSData(oldp+225,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[25]),16);
        bufp->chgSData(oldp+226,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[26]),16);
        bufp->chgSData(oldp+227,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[27]),16);
        bufp->chgSData(oldp+228,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[28]),16);
        bufp->chgSData(oldp+229,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[29]),16);
        bufp->chgSData(oldp+230,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[30]),16);
        bufp->chgSData(oldp+231,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[31]),16);
        bufp->chgIData(oldp+232,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER1__DOT__L1_COMPUTE__DOT__n),32);
        bufp->chgIData(oldp+233,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER1__DOT__L1_COMPUTE__DOT__k),32);
        bufp->chgQData(oldp+234,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER1__DOT__L1_COMPUTE__DOT__acc),40);
        bufp->chgIData(oldp+236,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER2__DOT__L2_COMPUTE__DOT__n),32);
        bufp->chgIData(oldp+237,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER2__DOT__L2_COMPUTE__DOT__k),32);
        bufp->chgQData(oldp+238,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER2__DOT__L2_COMPUTE__DOT__acc),40);
        bufp->chgIData(oldp+240,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER3__DOT__L3_COMPUTE__DOT__k),32);
        bufp->chgQData(oldp+241,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER3__DOT__L3_COMPUTE__DOT__acc),40);
        bufp->chgSData(oldp+243,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr[0]),16);
        bufp->chgSData(oldp+244,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr[1]),16);
        bufp->chgSData(oldp+245,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr[2]),16);
        bufp->chgSData(oldp+246,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr[3]),16);
        bufp->chgSData(oldp+247,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr[4]),16);
        bufp->chgSData(oldp+248,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr[5]),16);
        bufp->chgSData(oldp+249,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr[6]),16);
        bufp->chgSData(oldp+250,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr[7]),16);
        bufp->chgIData(oldp+251,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__i),32);
        bufp->chgSData(oldp+252,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__p_scalar),16);
        bufp->chgSData(oldp+253,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__e_reg),16);
        bufp->chgIData(oldp+254,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__i),32);
        bufp->chgSData(oldp+255,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_denom_p1),16);
        bufp->chgSData(oldp+256,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_x1),16);
        bufp->chgSData(oldp+257,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_x2),16);
        bufp->chgSData(oldp+258,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly_p1[0]),16);
        bufp->chgSData(oldp+259,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly_p1[1]),16);
        bufp->chgSData(oldp+260,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly_p1[2]),16);
        bufp->chgSData(oldp+261,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly_p1[3]),16);
        bufp->chgSData(oldp+262,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly_p1[4]),16);
        bufp->chgSData(oldp+263,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly_p1[5]),16);
        bufp->chgSData(oldp+264,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly_p1[6]),16);
        bufp->chgSData(oldp+265,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly_p1[7]),16);
        bufp->chgSData(oldp+266,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__e_reg_p1),16);
        bufp->chgIData(oldp+267,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__j),32);
        bufp->chgIData(oldp+268,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__denom),32);
        bufp->chgSData(oldp+269,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__d_norm),16);
        bufp->chgCData(oldp+270,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__lut_idx),3);
        bufp->chgSData(oldp+271,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__x0),16);
        bufp->chgIData(oldp+272,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__Dx0),32);
        bufp->chgSData(oldp+273,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__residual1),16);
        bufp->chgIData(oldp+274,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__Dx1),32);
        bufp->chgIData(oldp+275,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__p_over_denom),32);
        bufp->chgIData(oldp+276,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke),32);
        bufp->chgSData(oldp+277,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__residual2),16);
        bufp->chgIData(oldp+278,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__j),32);
        bufp->chgIData(oldp+279,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__P_UPDATE__DOT__p_new),32);
        bufp->chgIData(oldp+280,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked),32);
        bufp->chgSData(oldp+281,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__update_err),16);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[6U])) {
        bufp->chgCData(oldp+282,(vlSelf->tb_rls_dnn_top__DOT__s_axi_bresp),2);
        bufp->chgBit(oldp+283,(vlSelf->tb_rls_dnn_top__DOT__s_axi_bvalid));
        bufp->chgIData(oldp+284,(vlSelf->tb_rls_dnn_top__DOT__s_axi_rdata),32);
        bufp->chgCData(oldp+285,(vlSelf->tb_rls_dnn_top__DOT__s_axi_rresp),2);
        bufp->chgBit(oldp+286,(vlSelf->tb_rls_dnn_top__DOT__s_axi_rvalid));
        bufp->chgSData(oldp+287,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_lambda_out),16);
        bufp->chgCData(oldp+288,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_fsm_state_dbg),2);
        bufp->chgBit(oldp+289,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_awready));
        bufp->chgBit(oldp+290,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_wready));
        bufp->chgBit(oldp+291,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_awready));
        bufp->chgBit(oldp+292,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_wready));
        bufp->chgIData(oldp+293,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_rdata),32);
        bufp->chgBit(oldp+294,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_rvalid));
        bufp->chgSData(oldp+295,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lambda_slow),16);
        bufp->chgSData(oldp+296,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lambda_mid),16);
        bufp->chgSData(oldp+297,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lambda_fast),16);
        bufp->chgSData(oldp+298,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__threshold_up_reg),16);
        bufp->chgSData(oldp+299,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__threshold_down_reg),16);
        bufp->chgCData(oldp+300,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state),2);
        bufp->chgCData(oldp+301,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__next_state),2);
        bufp->chgSData(oldp+302,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__e_prev),16);
        bufp->chgCData(oldp+303,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_up),3);
        bufp->chgCData(oldp+304,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_down),4);
        bufp->chgCData(oldp+305,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_cnt),6);
        bufp->chgBit(oldp+306,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_active));
        bufp->chgSData(oldp+307,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__timeout_cnt),16);
        bufp->chgSData(oldp+308,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__last_sample),16);
        bufp->chgCData(oldp+309,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__stuck_cnt),5);
        bufp->chgSData(oldp+310,(((0U == (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_lambda_out))
                                   ? 0x7f00U : (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_lambda_out))),16);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[8U])) {
        bufp->chgBit(oldp+311,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_awready));
        bufp->chgBit(oldp+312,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_wready));
        bufp->chgBit(oldp+313,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_awready));
        bufp->chgBit(oldp+314,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_wready));
        bufp->chgBit(oldp+315,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_awready));
        bufp->chgBit(oldp+316,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_wready));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[9U])) {
        bufp->chgSData(oldp+317,(vlSelf->tb_rls_dnn_top__DOT__m_axis_tdata),16);
        bufp->chgBit(oldp+318,(vlSelf->tb_rls_dnn_top__DOT__m_axis_tvalid));
        bufp->chgSData(oldp+319,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_error),16);
        bufp->chgSData(oldp+320,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_y_hat),16);
        bufp->chgBit(oldp+321,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_valid_out));
        bufp->chgBit(oldp+322,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__mlp_valid_out));
        bufp->chgBit(oldp+323,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__poly_rls_en));
        bufp->chgCData(oldp+324,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__poly_decim_cnt_dbg),3);
        bufp->chgCData(oldp+325,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__decim_ratio),3);
        bufp->chgSData(oldp+326,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[0]),16);
        bufp->chgSData(oldp+327,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[1]),16);
        bufp->chgSData(oldp+328,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[2]),16);
        bufp->chgSData(oldp+329,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[3]),16);
        bufp->chgSData(oldp+330,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[4]),16);
        bufp->chgSData(oldp+331,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[5]),16);
        bufp->chgBit(oldp+332,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__decim_q));
        bufp->chgBit(oldp+333,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_en));
        bufp->chgIData(oldp+334,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sub_full),17);
        bufp->chgSData(oldp+335,((0xffffU & (((1U & 
                                               (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sub_full 
                                                >> 0x10U)) 
                                              == (1U 
                                                  & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sub_full 
                                                     >> 0xfU)))
                                              ? vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sub_full
                                              : ((0x10000U 
                                                  & vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sub_full)
                                                  ? 0x8000U
                                                  : 0x7fffU)))),16);
        bufp->chgIData(oldp+336,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__latprof_rdata),32);
        bufp->chgIData(oldp+337,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__free_cnt),32);
        bufp->chgIData(oldp+338,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_cbpf),32);
        bufp->chgIData(oldp+339,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_rls),32);
        bufp->chgIData(oldp+340,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_ptdl),32);
        bufp->chgIData(oldp+341,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_mlp),32);
        bufp->chgIData(oldp+342,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_output),32);
        bufp->chgIData(oldp+343,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_cbpf_to_rls),32);
        bufp->chgIData(oldp+344,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_rls_to_ptdl),32);
        bufp->chgIData(oldp+345,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_ptdl_to_mlp),32);
        bufp->chgIData(oldp+346,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_mlp_to_out),32);
        bufp->chgIData(oldp+347,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_total),32);
        bufp->chgBit(oldp+348,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__s0_valid));
        bufp->chgBit(oldp+349,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__s1_valid));
        bufp->chgCData(oldp+350,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_poly__DOT__decim_cnt),3);
        bufp->chgSData(oldp+351,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly
                                 [4U]),16);
        bufp->chgSData(oldp+352,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly
                                 [5U]),16);
        bufp->chgSData(oldp+353,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[0]),16);
        bufp->chgSData(oldp+354,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[1]),16);
        bufp->chgSData(oldp+355,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[2]),16);
        bufp->chgSData(oldp+356,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[3]),16);
        bufp->chgSData(oldp+357,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[4]),16);
        bufp->chgSData(oldp+358,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[5]),16);
        bufp->chgSData(oldp+359,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[6]),16);
        bufp->chgSData(oldp+360,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[7]),16);
        bufp->chgSData(oldp+361,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[0]),16);
        bufp->chgSData(oldp+362,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[1]),16);
        bufp->chgSData(oldp+363,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[2]),16);
        bufp->chgSData(oldp+364,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[3]),16);
        bufp->chgSData(oldp+365,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[4]),16);
        bufp->chgSData(oldp+366,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[5]),16);
        bufp->chgSData(oldp+367,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[6]),16);
        bufp->chgSData(oldp+368,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[7]),16);
        bufp->chgQData(oldp+369,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__y_acc),40);
        bufp->chgQData(oldp+371,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__xTx_acc),40);
        bufp->chgSData(oldp+373,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__d_pipe),16);
        bufp->chgBit(oldp+374,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__s1_valid));
        bufp->chgBit(oldp+375,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_p1_valid));
        bufp->chgBit(oldp+376,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_p2_valid));
        bufp->chgSData(oldp+377,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__d_pipe_p1),16);
        bufp->chgQData(oldp+378,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y),40);
        bufp->chgQData(oldp+380,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx),40);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0xbU])) {
        bufp->chgSData(oldp+382,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__x_cbpf),16);
        bufp->chgBit(oldp+383,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_y_valid));
        bufp->chgBit(oldp+384,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_clip_s2));
        bufp->chgBit(oldp+385,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_ref_channel_fault));
        bufp->chgSData(oldp+386,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_x_out_muxed),16);
        bufp->chgBit(oldp+387,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__bypass_reg));
        bufp->chgBit(oldp+388,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s1_valid_stg2));
        bufp->chgIData(oldp+389,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w1_s2),32);
        bufp->chgIData(oldp+390,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w2_s2),32);
        bufp->chgIData(oldp+391,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w0_s2),32);
        bufp->chgIData(oldp+392,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s2),32);
        bufp->chgIData(oldp+393,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_a1_s2),32);
        bufp->chgIData(oldp+394,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_a2_s2),32);
        bufp->chgIData(oldp+395,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b0_s2),32);
        bufp->chgIData(oldp+396,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b1_s2),32);
        bufp->chgIData(oldp+397,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b2_s2),32);
        bufp->chgSData(oldp+398,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s2_trunc),16);
        bufp->chgBit(oldp+399,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s2_valid_stg1));
        bufp->chgBit(oldp+400,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s2_valid_stg2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0xcU])) {
        bufp->chgBit(oldp+401,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst));
        bufp->chgBit(oldp+402,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__pipeline_stall_fault));
        bufp->chgBit(oldp+403,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__output_stuck_fault));
        bufp->chgIData(oldp+404,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__global_sample_cnt),32);
        bufp->chgIData(oldp+405,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_sample_cnt),32);
        bufp->chgCData(oldp+406,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_count_reg),8);
        bufp->chgCData(oldp+407,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__rcv_state),2);
        bufp->chgCData(oldp+408,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__drain_cnt),3);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0xdU])) {
        bufp->chgIData(oldp+409,(vlSelf->tb_rls_dnn_top__DOT__clk_cnt),32);
        bufp->chgIData(oldp+410,(vlSelf->tb_rls_dnn_top__DOT__sample_idx),32);
        bufp->chgSData(oldp+411,(vlSelf->tb_rls_dnn_top__DOT__d_sample),16);
        bufp->chgSData(oldp+412,(vlSelf->tb_rls_dnn_top__DOT__x_sample),16);
        bufp->chgDouble(oldp+413,(vlSelf->tb_rls_dnn_top__DOT__sin_lut__Vstatic__angle));
    }
    bufp->chgBit(oldp+415,(vlSelf->tb_rls_dnn_top__DOT__clk));
    bufp->chgBit(oldp+416,(vlSelf->tb_rls_dnn_top__DOT__sample_enable));
    bufp->chgIData(oldp+417,(vlSelf->tb_rls_dnn_top__DOT__s_axis_tdata),32);
    bufp->chgBit(oldp+418,(vlSelf->tb_rls_dnn_top__DOT__s_axis_tvalid));
    bufp->chgBit(oldp+419,(vlSelf->tb_rls_dnn_top__DOT__s_axis_tready));
    bufp->chgBit(oldp+420,(((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_awready) 
                            | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_awready) 
                               | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_awready) 
                                  | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_awready) 
                                     | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_awready) 
                                        | (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____VdfgRegularize_h739c3624_2_0))))))));
    bufp->chgBit(oldp+421,(((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_wready) 
                            | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_wready) 
                               | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_wready) 
                                  | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_wready) 
                                     | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_wready) 
                                        | (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____VdfgRegularize_h739c3624_2_0))))))));
    bufp->chgBit(oldp+422,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_irq_fault));
    bufp->chgSData(oldp+423,((0xffffU & vlSelf->tb_rls_dnn_top__DOT__s_axis_tdata)),16);
    bufp->chgSData(oldp+424,((vlSelf->tb_rls_dnn_top__DOT__s_axis_tdata 
                              >> 0x10U)),16);
    bufp->chgBit(oldp+425,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sample_consumed_cbpf));
    bufp->chgBit(oldp+426,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__rst_n));
    bufp->chgIData(oldp+427,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__delta_e),17);
    bufp->chgBit(oldp+428,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_cbpf__s_axi_awvalid));
    bufp->chgBit(oldp+429,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_cbpf__s_axi_wvalid));
    bufp->chgIData(oldp+430,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii),32);
    bufp->chgCData(oldp+431,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_type_reg),2);
}

void Vtb_rls_dnn_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root__trace_cleanup\n"); );
    // Init
    Vtb_rls_dnn_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_rls_dnn_top___024root*>(voidSelf);
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[6U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[7U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[8U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[9U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xaU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xbU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xcU] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[0xdU] = 0U;
}

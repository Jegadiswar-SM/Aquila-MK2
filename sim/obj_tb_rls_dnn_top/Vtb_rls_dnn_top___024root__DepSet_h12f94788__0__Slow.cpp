// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_rls_dnn_top.h for the primary calling header

#include "Vtb_rls_dnn_top__pch.h"
#include "Vtb_rls_dnn_top__Syms.h"
#include "Vtb_rls_dnn_top___024root.h"

extern const VlWide<256>/*8191:0*/ Vtb_rls_dnn_top__ConstPool__CONST_h3321abed_0;
extern const VlWide<1024>/*32767:0*/ Vtb_rls_dnn_top__ConstPool__CONST_h428f1078_0;

VL_ATTR_COLD void Vtb_rls_dnn_top___024root___eval_initial__TOP(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_1;
    // Body
    vlSelf->tb_rls_dnn_top__DOT__clk = 0U;
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x5f746f70U;
    __Vtemp_1[2U] = 0x5f646e6eU;
    __Vtemp_1[3U] = 0x726c73U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(4, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[0U] = 0xbc00U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[1U] = 0xb400U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[2U] = 0xac00U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[3U] = 0xa400U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[4U] = 0x9c00U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[5U] = 0x9400U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[6U] = 0x8c00U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[7U] = 0x8400U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii = 0U;
    while (VL_GTS_III(32, 0x200U, vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii)) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w1_rom[(0x1ffU 
                                                                   & vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii)] 
            = (0xffffU & (((0U == (0x1fU & VL_MULS_III(32, (IData)(0x10U), 
                                                       ((IData)(0x1ffU) 
                                                        - vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii))))
                            ? 0U : (Vtb_rls_dnn_top__ConstPool__CONST_h3321abed_0[
                                    (((IData)(0xfU) 
                                      + (0x1fffU & 
                                         VL_MULS_III(32, (IData)(0x10U), 
                                                     ((IData)(0x1ffU) 
                                                      - vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii)))) 
                                     >> 5U)] << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_MULS_III(32, (IData)(0x10U), 
                                                                ((IData)(0x1ffU) 
                                                                 - vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii)))))) 
                          | (Vtb_rls_dnn_top__ConstPool__CONST_h3321abed_0[
                             (0xffU & (VL_MULS_III(32, (IData)(0x10U), 
                                                   ((IData)(0x1ffU) 
                                                    - vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii)) 
                                       >> 5U))] >> 
                             (0x1fU & VL_MULS_III(32, (IData)(0x10U), 
                                                  ((IData)(0x1ffU) 
                                                   - vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii))))));
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii 
            = ((IData)(1U) + vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii);
    }
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0U] = 0xb29U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[1U] = 0xdfc5U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[2U] = 0xf36fU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[3U] = 0xd879U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[4U] = 0x2523U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[5U] = 0xd707U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[6U] = 0x231bU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[7U] = 0xffb9U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[8U] = 0xfc79U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[9U] = 0x1a0bU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0xaU] = 0xfc3cU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0xbU] = 0x1910U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0xcU] = 0x220dU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0xdU] = 0xe00fU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0xeU] = 0x1356U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0xfU] = 0xabdU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x10U] = 0x851U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x11U] = 0x5feU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x12U] = 0xbeeU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x13U] = 0xf55cU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x14U] = 0xfcd2U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x15U] = 0x28ebU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x16U] = 0x1845U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x17U] = 0xfcf5U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x18U] = 0xdd49U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x19U] = 0x1d3U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x1aU] = 0xe4abU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x1bU] = 0x1f5eU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x1cU] = 0xe57bU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x1dU] = 0xf9b2U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x1eU] = 0xf7d9U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x1fU] = 0x94bU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x20U] = 0x2c2cU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x21U] = 0x442U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x22U] = 0x7a6U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x23U] = 0x22ccU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x24U] = 0x1cabU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x25U] = 0xeeaaU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x26U] = 0xf4cbU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x27U] = 0xbcdU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x28U] = 0xf2a4U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x29U] = 0x14beU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x2aU] = 0xf7b8U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x2bU] = 0xe25bU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x2cU] = 0x1285U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x2dU] = 0x6e6U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x2eU] = 0x1433U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x2fU] = 0x2f8aU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x30U] = 0x1ba9U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x31U] = 0x2901U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x32U] = 0xfc53U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x33U] = 0xdcdfU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x34U] = 0xe2a8U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x35U] = 0xe74aU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x36U] = 0xd72aU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x37U] = 0xeb1aU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x38U] = 0xe175U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x39U] = 0xd5afU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x3aU] = 0xfce0U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x3bU] = 0xd142U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x3cU] = 0xe301U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x3dU] = 0x1275U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x3eU] = 0x17c3U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b1_rom[0x3fU] = 0xf29aU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii = 0U;
    while (VL_GTS_III(32, 0x800U, vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii)) {
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w2_rom[(0x7ffU 
                                                                   & vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii)] 
            = (0xffffU & (((0U == (0x1fU & VL_MULS_III(32, (IData)(0x10U), 
                                                       ((IData)(0x7ffU) 
                                                        - vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii))))
                            ? 0U : (Vtb_rls_dnn_top__ConstPool__CONST_h428f1078_0[
                                    (((IData)(0xfU) 
                                      + (0x7fffU & 
                                         VL_MULS_III(32, (IData)(0x10U), 
                                                     ((IData)(0x7ffU) 
                                                      - vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii)))) 
                                     >> 5U)] << ((IData)(0x20U) 
                                                 - 
                                                 (0x1fU 
                                                  & VL_MULS_III(32, (IData)(0x10U), 
                                                                ((IData)(0x7ffU) 
                                                                 - vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii)))))) 
                          | (Vtb_rls_dnn_top__ConstPool__CONST_h428f1078_0[
                             (0x3ffU & (VL_MULS_III(32, (IData)(0x10U), 
                                                    ((IData)(0x7ffU) 
                                                     - vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii)) 
                                        >> 5U))] >> 
                             (0x1fU & VL_MULS_III(32, (IData)(0x10U), 
                                                  ((IData)(0x7ffU) 
                                                   - vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii))))));
        vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii 
            = ((IData)(1U) + vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii);
    }
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0U] = 0xf8afU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[1U] = 0xb14U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[2U] = 0xf9f4U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[3U] = 0x1ebU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[4U] = 0x6dcU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[5U] = 0xf0a4U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[6U] = 0x55eU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[7U] = 0xfac0U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[8U] = 0x560U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[9U] = 0xcb2U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0xaU] = 0xf756U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0xbU] = 0xfc7fU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0xcU] = 0xe5cU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0xdU] = 0xfe91U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0xeU] = 0xfc27U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0xfU] = 0xef2U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0x10U] = 0xf513U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0x11U] = 0xff9eU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0x12U] = 0x6f6U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0x13U] = 0x2f4U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0x14U] = 0xf34cU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0x15U] = 0xf4U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0x16U] = 0xf5edU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0x17U] = 0xf467U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0x18U] = 0xcedU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0x19U] = 0xf95fU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0x1aU] = 0xf515U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0x1bU] = 0x423U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0x1cU] = 0x123U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0x1dU] = 0xf9afU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0x1eU] = 0xf286U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0x1fU] = 0xedf4U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0U] = 0x5ddU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[1U] = 0xf057U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[2U] = 0x114aU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[3U] = 0xf243U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[4U] = 0xed83U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[5U] = 0xec07U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[6U] = 0xee3aU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[7U] = 0xf615U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[8U] = 0xff1fU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[9U] = 0xe589U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0xaU] = 0xe75dU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0xbU] = 0xf7aU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0xcU] = 0xb82U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0xdU] = 0xefc0U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0xeU] = 0xfdb4U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0xfU] = 0x13e8U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0x10U] = 0xea50U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0x11U] = 0xf459U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0x12U] = 0xdffaU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0x13U] = 0xfb4eU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0x14U] = 0xfe0cU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0x15U] = 0xebf1U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0x16U] = 0x11fbU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0x17U] = 0xea92U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0x18U] = 0x143aU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0x19U] = 0xec1cU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0x1aU] = 0x16f4U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0x1bU] = 0x87dU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0x1cU] = 0xfb84U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0x1dU] = 0x1c45U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0x1eU] = 0xed6eU;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0x1fU] = 0xfb95U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b3_rom[0U] = 0xf2c0U;
    vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii = 1U;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_rls_dnn_top___024root___dump_triggers__stl(Vtb_rls_dnn_top___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_rls_dnn_top___024root___eval_triggers__stl(Vtb_rls_dnn_top___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_rls_dnn_top___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

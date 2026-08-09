// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_nr2_isolated.h for the primary calling header

#ifndef VERILATED_VTB_NR2_ISOLATED___024ROOT_H_
#define VERILATED_VTB_NR2_ISOLATED___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_nr2_isolated__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_nr2_isolated___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_nr2_isolated__DOT__clk;
    CData/*0:0*/ tb_nr2_isolated__DOT__rst_n;
    CData/*0:0*/ tb_nr2_isolated__DOT__srst;
    CData/*0:0*/ tb_nr2_isolated__DOT__sample_en;
    CData/*0:0*/ tb_nr2_isolated__DOT__dut__DOT__s1_valid;
    CData/*0:0*/ tb_nr2_isolated__DOT__dut__DOT__nr_p1_valid;
    CData/*4:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__lut_idx;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_nr2_isolated__DOT__clk__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ tb_nr2_isolated__DOT__d_in;
    SData/*15:0*/ tb_nr2_isolated__DOT__x_in;
    SData/*15:0*/ tb_nr2_isolated__DOT__lambda_in;
    SData/*15:0*/ tb_nr2_isolated__DOT__leak_factor;
    SData/*15:0*/ tb_nr2_isolated__DOT__e_weighted;
    SData/*15:0*/ tb_nr2_isolated__DOT__dut__DOT__p_scalar;
    SData/*15:0*/ tb_nr2_isolated__DOT__dut__DOT__e_reg;
    SData/*15:0*/ tb_nr2_isolated__DOT__dut__DOT__nr_denom_p1;
    SData/*15:0*/ tb_nr2_isolated__DOT__dut__DOT__nr_x1;
    SData/*15:0*/ tb_nr2_isolated__DOT__dut__DOT__nr_x2;
    SData/*15:0*/ tb_nr2_isolated__DOT__dut__DOT__e_reg_p1;
    SData/*15:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__d_norm;
    SData/*15:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__x0;
    SData/*15:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__Dx0_q214;
    SData/*15:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__residual1;
    SData/*15:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__Dx1_q214;
    SData/*15:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__residual2;
    SData/*15:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__update_err;
    IData/*31:0*/ tb_nr2_isolated__DOT__d_q;
    IData/*31:0*/ tb_nr2_isolated__DOT__x2_signed;
    IData/*31:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__denom;
    IData/*31:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__lambda_ext;
    IData/*31:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__p_scalar_ext;
    IData/*31:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__xTx_q15;
    IData/*31:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__Dx0;
    IData/*31:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__denom_prod_q15;
    IData/*31:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__Dx1;
    IData/*31:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__p_over_denom;
    IData/*31:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke;
    IData/*31:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked;
    IData/*31:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_sum;
    IData/*31:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__P_UPDATE__DOT__p_new;
    IData/*31:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__P_UPDATE__DOT__p_scalar_ext;
    IData/*31:0*/ __VactIterCount;
    QData/*39:0*/ tb_nr2_isolated__DOT__dut__DOT__y_acc;
    QData/*39:0*/ tb_nr2_isolated__DOT__dut__DOT__xTx_acc;
    QData/*39:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y;
    QData/*39:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx;
    QData/*63:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__denom_prod;
    QData/*63:0*/ tb_nr2_isolated__DOT__dut__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__denom_prod_shift;
    VlUnpacked<SData/*15:0*/, 8> tb_nr2_isolated__DOT__dut__DOT__w;
    VlUnpacked<SData/*15:0*/, 8> tb_nr2_isolated__DOT__dut__DOT__x_dly;
    VlUnpacked<SData/*15:0*/, 32> tb_nr2_isolated__DOT__dut__DOT__nr_lut;
    VlUnpacked<SData/*15:0*/, 8> tb_nr2_isolated__DOT__dut__DOT__x_dly_p1;
    double tb_nr2_isolated__DOT__d_float;
    double tb_nr2_isolated__DOT__true_inv;
    double tb_nr2_isolated__DOT__hw_inv;
    double tb_nr2_isolated__DOT__err;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h4dfc4760__0;
    VlTriggerScheduler __VtrigSched_h4dfc46b1__0;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_nr2_isolated__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_nr2_isolated___024root(Vtb_nr2_isolated__Syms* symsp, const char* v__name);
    ~Vtb_nr2_isolated___024root();
    VL_UNCOPYABLE(Vtb_nr2_isolated___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

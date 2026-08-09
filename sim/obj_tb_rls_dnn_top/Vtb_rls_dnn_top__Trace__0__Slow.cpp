// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_rls_dnn_top__Syms.h"


VL_ATTR_COLD void Vtb_rls_dnn_top___024root__trace_init_sub__TOP__0(Vtb_rls_dnn_top___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("tb_rls_dnn_top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+416,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+417,0,"sample_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+418,0,"s_axis_tdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+419,0,"s_axis_tvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+420,0,"s_axis_tready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+318,0,"m_axis_tdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+319,0,"m_axis_tvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"m_axis_tready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+76,0,"s_axi_awaddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+77,0,"s_axi_awvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+421,0,"s_axi_awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+78,0,"s_axi_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+79,0,"s_axi_wvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+422,0,"s_axi_wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+283,0,"s_axi_bresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+284,0,"s_axi_bvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"s_axi_bready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+81,0,"s_axi_araddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+82,0,"s_axi_arvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+433,0,"s_axi_arready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+285,0,"s_axi_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+286,0,"s_axi_rresp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+287,0,"s_axi_rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"s_axi_rready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"clk_gate_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+423,0,"irq_fault",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+434,0,"SAMPLE_DIV",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+410,0,"clk_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+411,0,"sample_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declDouble(c+435,0,"sin_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declDouble(c+437,0,"noise_val",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBus(c+412,0,"d_sample",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+413,0,"x_sample",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declDouble(c+414,0,"sin_lut__Vstatic__angle",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::DOUBLE, false,-1);
    tracep->declBus(c+171,0,"out_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+172,0,"pass_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("dut", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+416,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+417,0,"sample_enable",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+418,0,"s_axis_tdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+419,0,"s_axis_tvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+420,0,"s_axis_tready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+318,0,"m_axis_tdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+319,0,"m_axis_tvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"m_axis_tready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+76,0,"s_axi_awaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+77,0,"s_axi_awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+421,0,"s_axi_awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+78,0,"s_axi_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+79,0,"s_axi_wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+422,0,"s_axi_wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+283,0,"s_axi_bresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+284,0,"s_axi_bvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+80,0,"s_axi_bready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+81,0,"s_axi_araddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+82,0,"s_axi_arvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+433,0,"s_axi_arready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+285,0,"s_axi_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+286,0,"s_axi_rresp",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBit(c+287,0,"s_axi_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+83,0,"s_axi_rready",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"clk_gate_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+423,0,"irq_fault",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+424,0,"d_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+425,0,"x_in",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+426,0,"sample_consumed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+173,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+383,0,"x_cbpf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+384,0,"cbpf_y_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+109,0,"cbpf_clip_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+385,0,"cbpf_clip_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+110,0,"aad_signal_active",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"aad_clk_gate_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+386,0,"rcim_ref_channel_fault",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+387,0,"rcim_x_out_muxed",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+320,0,"rls_error",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+321,0,"rls_y_hat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+322,0,"rls_valid_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+288,0,"affhc_lambda_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+289,0,"affhc_fsm_state_dbg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declArray(c+174,0,"ptdl_taps",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+178,0,"mlp_noise_est",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+323,0,"mlp_valid_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+402,0,"plwd_pipeline_srst",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+423,0,"plwd_irq_fault",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+324,0,"poly_rls_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+417,0,"poly_cbpf_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+325,0,"poly_decim_cnt_dbg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+326,0,"decim_ratio",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+426,0,"sample_consumed_cbpf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("d_dly", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 6; ++i) {
        tracep->declBus(c+327+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+333,0,"decim_q",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+334,0,"rls_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+179,0,"fwes_e_weighted",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+439,0,"PIPE_DELAY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("rls_err_pipe", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBus(c+180+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("rls_vld_pipe", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 3; ++i) {
        tracep->declBit(c+183+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0));
    }
    tracep->popPrefix();
    tracep->declBus(c+186,0,"mlp_scaled",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+335,0,"sub_full",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+336,0,"sub_sat",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+187,0,"latprof_rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+337,0,"latprof_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+188,0,"rls_leak_factor",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+189,0,"fwes_alpha_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+84,0,"aw_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+85,0,"affhc_aw_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+86,0,"aad_aw_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+87,0,"cbpf_aw_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+88,0,"plwd_aw_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+89,0,"rcim_aw_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+90,0,"rlsctl_aw_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+91,0,"other_aw_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+92,0,"ar_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+93,0,"plwd_ar_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+94,0,"latprof_ar_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+290,0,"affhc_awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+291,0,"affhc_wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+312,0,"aad_awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+313,0,"aad_wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+314,0,"cbpf_awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+315,0,"cbpf_wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+292,0,"plwd_awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+293,0,"plwd_wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+316,0,"rcim_awready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+317,0,"rcim_wready",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+294,0,"plwd_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+295,0,"plwd_rvalid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("u_aad", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+440,0,"SHORT_SHIFT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+441,0,"LONG_SHIFT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+442,0,"RATIO_SHIFT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+443,0,"ASSERT_CNT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+444,0,"DEASSERT_CNT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+416,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+427,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+383,0,"x_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+384,0,"x_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+95,0,"s_axi_awaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+103,0,"s_axi_awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+78,0,"s_axi_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+104,0,"s_axi_wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+312,0,"s_axi_awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+313,0,"s_axi_wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+110,0,"signal_active",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"clk_gate_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declQuad(c+111,0,"acc_A_dbg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declQuad(c+113,0,"acc_B_dbg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declBus(c+115,0,"ratio_shift_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+116,0,"x_sq",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+117,0,"mul_tmp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declQuad(c+118,0,"acc_A",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declQuad(c+120,0,"acc_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declBit(c+122,0,"activity_cmp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+123,0,"assert_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+124,0,"deassert_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_affhc", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+445,0,"THRESHOLD_UP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+446,0,"THRESHOLD_DOWN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+439,0,"DWELL_UP",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+440,0,"DWELL_DOWN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+447,0,"LOCKOUT_CYCLES",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+416,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+320,0,"e_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+322,0,"e_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+96,0,"s_axi_awaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+98,0,"s_axi_awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+78,0,"s_axi_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+99,0,"s_axi_wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+290,0,"s_axi_awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+291,0,"s_axi_wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+288,0,"lambda_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+289,0,"fsm_state_dbg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+296,0,"lambda_slow",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+297,0,"lambda_mid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+298,0,"lambda_fast",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+299,0,"threshold_up_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+300,0,"threshold_down_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+448,0,"STEADY",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+449,0,"TRACKING",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+450,0,"FAST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+451,0,"LOCKOUT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+301,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+302,0,"next_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+303,0,"e_prev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+428,0,"delta_e",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->declBus(c+304,0,"cnt_up",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+305,0,"cnt_down",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+306,0,"lockout_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 5,0);
    tracep->declBit(c+307,0,"lockout_active",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_cbpf", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+416,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+427,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+425,0,"x_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+426,0,"x_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+95,0,"s_axi_awaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+429,0,"s_axi_awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+78,0,"s_axi_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+430,0,"s_axi_wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+314,0,"s_axi_awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+315,0,"s_axi_wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+383,0,"y_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+384,0,"y_valid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+109,0,"clip_s1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+385,0,"clip_s2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+452,0,"B0_S1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+453,0,"B1_S1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+452,0,"B2_S1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+454,0,"A1_S1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+455,0,"A2_S1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+456,0,"B0_S2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+457,0,"B1_S2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+456,0,"B2_S2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+458,0,"A1_S2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+459,0,"A2_S2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+388,0,"bypass_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+125,0,"w1_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+126,0,"w2_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+127,0,"w0_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+128,0,"y_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+129,0,"mul_a1_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+130,0,"mul_a2_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+131,0,"mul_b0_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+132,0,"mul_b1_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+133,0,"mul_b2_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+134,0,"y_s1_trunc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+135,0,"s1_valid_stg1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+389,0,"s1_valid_stg2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+390,0,"w1_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+391,0,"w2_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+392,0,"w0_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+393,0,"y_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+394,0,"mul_a1_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+395,0,"mul_a2_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+396,0,"mul_b0_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+397,0,"mul_b1_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+398,0,"mul_b2_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+399,0,"y_s2_trunc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+400,0,"s2_valid_stg1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+401,0,"s2_valid_stg2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("u_fwes", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+416,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+320,0,"e_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+322,0,"e_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+189,0,"alpha_reg",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+179,0,"e_weighted",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+320,0,"e_output",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+190,0,"e_w_prev",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+191,0,"alpha_term",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_latprof", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+416,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+384,0,"cbpf_y_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+322,0,"rls_out_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+322,0,"ptdl_out_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+323,0,"mlp_out_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+319,0,"m_axis_tvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+81,0,"s_axi_araddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+105,0,"s_axi_arvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+337,0,"s_axi_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+187,0,"s_axi_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+338,0,"free_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+339,0,"ts_cbpf",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+340,0,"ts_rls",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+341,0,"ts_ptdl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+342,0,"ts_mlp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+343,0,"ts_output",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+344,0,"lat_cbpf_to_rls",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+345,0,"lat_rls_to_ptdl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+346,0,"lat_ptdl_to_mlp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+347,0,"lat_mlp_to_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+348,0,"lat_total",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+192,0,"free_cnt_snap",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_mlp", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+416,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+427,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+322,0,"en_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declArray(c+174,0,"features_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->declBus(c+178,0,"y_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+323,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+460,0,"W1_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+461,0,"W1_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+462,0,"W2_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("b2_rom", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+1+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("w3_rom", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+33+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("b3_rom", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 1; ++i) {
        tracep->declBus(c+65+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+431,0,"ii",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("feat", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+193+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+349,0,"s0_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+463,0,"mul_s0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("h2", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+201+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->declBit(c+350,0,"s1_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+464,0,"mul_s1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+465,0,"mul_s2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+466,0,"W1_INIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 8191,0);
    tracep->declArray(c+722,0,"B1_INIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1023,0);
    tracep->declArray(c+754,0,"W2_INIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 32767,0);
    tracep->declArray(c+1778,0,"B2_INIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 511,0);
    tracep->declArray(c+1794,0,"W3_INIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 511,0);
    tracep->declBus(c+1810,0,"B3_INIT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("LAYER1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("L1_COMPUTE", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+233,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+234,0,"k",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declQuad(c+235,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("LAYER2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("L2_COMPUTE", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+237,0,"n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+238,0,"k",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declQuad(c+239,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("LAYER3", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("L3_COMPUTE", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+241,0,"k",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declQuad(c+242,0,"acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("u_plwd", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1811,0,"VALID_TIMEOUT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1812,0,"STUCK_THRESHOLD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+416,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+319,0,"m_axis_tvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+318,0,"m_axis_tdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+97,0,"s_axi_araddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+100,0,"s_axi_arvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+294,0,"s_axi_rdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+295,0,"s_axi_rvalid",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+95,0,"s_axi_awaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+101,0,"s_axi_awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+78,0,"s_axi_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+102,0,"s_axi_wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+292,0,"s_axi_awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+293,0,"s_axi_wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+402,0,"pipeline_srst",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+423,0,"irq_fault",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+308,0,"timeout_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+403,0,"pipeline_stall_fault",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+309,0,"last_sample",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+310,0,"stuck_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+404,0,"output_stuck_fault",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+405,0,"global_sample_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+432,0,"fault_type_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+406,0,"fault_sample_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+407,0,"fault_count_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+448,0,"IDLE",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+449,0,"FAULT_DETECT",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+450,0,"PIPELINE_DRAIN",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+451,0,"FORCE_RESET",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+408,0,"rcv_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+409,0,"drain_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_poly", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+416,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+417,0,"sample_enable_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+326,0,"decim_ratio",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBit(c+324,0,"sample_enable_rls",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+417,0,"sample_enable_cbpf",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+325,0,"decim_cnt_dbg",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+351,0,"decim_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_ptdl", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+416,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+427,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+322,0,"sample_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+320,0,"e_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declArray(c+174,0,"taps_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 127,0);
    tracep->pushPrefix("sr", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+244+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+252,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_rcim", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+447,0,"WINDOW",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1813,0,"FAULT_PERSIST",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1812,0,"LUTRAM_DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+416,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+427,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+352,0,"d_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+383,0,"x_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+384,0,"samples_valid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+96,0,"s_axi_awaddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+106,0,"s_axi_awvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+78,0,"s_axi_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+107,0,"s_axi_wvalid",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+316,0,"s_axi_awready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+317,0,"s_axi_wready",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+386,0,"ref_channel_fault",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+387,0,"x_out_muxed",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+136,0,"corr_threshold",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+137,0,"ratio_shift",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declQuad(c+138,0,"corr_acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declQuad(c+140,0,"ref_power_acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declBus(c+142,0,"mul_dx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+143,0,"mul_xx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("lutram", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+144+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+160,0,"lut_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+161,0,"recip_approx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+162,0,"ref_power_norm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+1814,0,"nr_term",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1815,0,"nr_prod",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+163,0,"refined_recip",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+164,0,"mul_nr1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+165,0,"mul_nr2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+166,0,"corr_mag",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+1816,0,"norm_corr_prod",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+167,0,"norm_corr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+168,0,"mul_norm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+169,0,"fault_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+170,0,"recover_cnt",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("u_rls", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+440,0,"N",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1812,0,"W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1817,0,"LAMBDA_Q15",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+416,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+402,0,"srst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+334,0,"sample_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+353,0,"d_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+387,0,"x_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+288,0,"lambda_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+188,0,"leak_factor",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+179,0,"e_weighted",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+320,0,"error_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+322,0,"valid_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+321,0,"y_hat",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+1818,0,"ACC_W",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+1819,0,"FRAC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+311,0,"lambda_used",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("w", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+354+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("x_dly", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+362+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+253,0,"p_scalar",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declQuad(c+370,0,"y_acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declQuad(c+372,0,"xTx_acc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declBus(c+254,0,"e_reg",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+374,0,"d_pipe",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+375,0,"s1_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+255,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->declBus(c+1820,0,"mul_tmp",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("nr_lut", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+66+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+256,0,"nr_denom_p1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+257,0,"nr_x1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+258,0,"nr_x2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBit(c+376,0,"nr_p1_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+377,0,"nr_p2_valid",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("x_dly_p1", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 8; ++i) {
        tracep->declBus(c+259+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 15,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+267,0,"e_reg_p1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+378,0,"d_pipe_p1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->pushPrefix("STAGE0", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("DOT_PRODUCT", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declQuad(c+379,0,"acc_y",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declQuad(c+381,0,"acc_xx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 39,0);
    tracep->declBus(c+268,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("STAGE1_NR1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("NR_STAGE1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+269,0,"denom",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+270,0,"d_norm",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+271,0,"lut_idx",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+272,0,"x0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+273,0,"Dx0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+274,0,"residual1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("STAGE2_NR2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+275,0,"Dx1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+276,0,"p_over_denom",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+277,0,"ke",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+278,0,"residual2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->declBus(c+279,0,"j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->pushPrefix("P_UPDATE", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+280,0,"p_new",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+281,0,"w_leaked",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+282,0,"update_err",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 15,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_rls_dnn_top___024root__trace_init_top(Vtb_rls_dnn_top___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root__trace_init_top\n"); );
    // Body
    Vtb_rls_dnn_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_rls_dnn_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_rls_dnn_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_rls_dnn_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_rls_dnn_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_rls_dnn_top___024root__trace_register(Vtb_rls_dnn_top___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vtb_rls_dnn_top___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtb_rls_dnn_top___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtb_rls_dnn_top___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtb_rls_dnn_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_rls_dnn_top___024root__trace_const_0_sub_0(Vtb_rls_dnn_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_rls_dnn_top___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root__trace_const_0\n"); );
    // Init
    Vtb_rls_dnn_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_rls_dnn_top___024root*>(voidSelf);
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_rls_dnn_top___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<256>/*8191:0*/ Vtb_rls_dnn_top__ConstPool__CONST_h3321abed_0;
extern const VlWide<32>/*1023:0*/ Vtb_rls_dnn_top__ConstPool__CONST_hcec1e506_0;
extern const VlWide<1024>/*32767:0*/ Vtb_rls_dnn_top__ConstPool__CONST_h428f1078_0;
extern const VlWide<16>/*511:0*/ Vtb_rls_dnn_top__ConstPool__CONST_h2a93a067_0;
extern const VlWide<16>/*511:0*/ Vtb_rls_dnn_top__ConstPool__CONST_h50d85f33_0;

VL_ATTR_COLD void Vtb_rls_dnn_top___024root__trace_const_0_sub_0(Vtb_rls_dnn_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+433,(1U));
    bufp->fullIData(oldp+434,(0x14U),32);
    bufp->fullDouble(oldp+435,(vlSelf->tb_rls_dnn_top__DOT__sin_val));
    bufp->fullDouble(oldp+437,(vlSelf->tb_rls_dnn_top__DOT__noise_val));
    bufp->fullIData(oldp+439,(3U),32);
    bufp->fullIData(oldp+440,(8U),32);
    bufp->fullIData(oldp+441,(0xcU),32);
    bufp->fullIData(oldp+442,(2U),32);
    bufp->fullIData(oldp+443,(4U),32);
    bufp->fullIData(oldp+444,(0x40U),32);
    bufp->fullSData(oldp+445,(0x200U),16);
    bufp->fullSData(oldp+446,(0x80U),16);
    bufp->fullIData(oldp+447,(0x20U),32);
    bufp->fullCData(oldp+448,(0U),2);
    bufp->fullCData(oldp+449,(1U),2);
    bufp->fullCData(oldp+450,(2U),2);
    bufp->fullCData(oldp+451,(3U),2);
    bufp->fullSData(oldp+452,(0x2afU),16);
    bufp->fullSData(oldp+453,(0x55eU),16);
    bufp->fullSData(oldp+454,(0x7fffU),16);
    bufp->fullSData(oldp+455,(0xc250U),16);
    bufp->fullSData(oldp+456,(0x4000U),16);
    bufp->fullSData(oldp+457,(0x8000U),16);
    bufp->fullSData(oldp+458,(0x7148U),16);
    bufp->fullSData(oldp+459,(0xcaa1U),16);
    bufp->fullIData(oldp+460,(0x200U),32);
    bufp->fullIData(oldp+461,(0x10U),32);
    bufp->fullIData(oldp+462,(0x800U),32);
    bufp->fullIData(oldp+463,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__mul_s0),32);
    bufp->fullIData(oldp+464,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__mul_s1),32);
    bufp->fullIData(oldp+465,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__mul_s2),32);
    bufp->fullWData(oldp+466,(Vtb_rls_dnn_top__ConstPool__CONST_h3321abed_0),8192);
    bufp->fullWData(oldp+722,(Vtb_rls_dnn_top__ConstPool__CONST_hcec1e506_0),1024);
    bufp->fullWData(oldp+754,(Vtb_rls_dnn_top__ConstPool__CONST_h428f1078_0),32768);
    bufp->fullWData(oldp+1778,(Vtb_rls_dnn_top__ConstPool__CONST_h2a93a067_0),512);
    bufp->fullWData(oldp+1794,(Vtb_rls_dnn_top__ConstPool__CONST_h50d85f33_0),512);
    bufp->fullSData(oldp+1810,(0xf2c0U),16);
    bufp->fullIData(oldp+1811,(0x200U),32);
    bufp->fullIData(oldp+1812,(0x10U),32);
    bufp->fullIData(oldp+1813,(0x80U),32);
    bufp->fullIData(oldp+1814,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__nr_term),32);
    bufp->fullIData(oldp+1815,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__nr_prod),32);
    bufp->fullIData(oldp+1816,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__norm_corr_prod),32);
    bufp->fullSData(oldp+1817,(0x7f00U),16);
    bufp->fullIData(oldp+1818,(0x28U),32);
    bufp->fullIData(oldp+1819,(0xfU),32);
    bufp->fullIData(oldp+1820,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__mul_tmp),32);
}

VL_ATTR_COLD void Vtb_rls_dnn_top___024root__trace_full_0_sub_0(Vtb_rls_dnn_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_rls_dnn_top___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root__trace_full_0\n"); );
    // Init
    Vtb_rls_dnn_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_rls_dnn_top___024root*>(voidSelf);
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_rls_dnn_top___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_rls_dnn_top___024root__trace_full_0_sub_0(Vtb_rls_dnn_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_rls_dnn_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_rls_dnn_top___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<4>/*127:0*/ __Vtemp_3;
    // Body
    bufp->fullSData(oldp+1,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[0]),16);
    bufp->fullSData(oldp+2,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[1]),16);
    bufp->fullSData(oldp+3,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[2]),16);
    bufp->fullSData(oldp+4,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[3]),16);
    bufp->fullSData(oldp+5,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[4]),16);
    bufp->fullSData(oldp+6,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[5]),16);
    bufp->fullSData(oldp+7,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[6]),16);
    bufp->fullSData(oldp+8,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[7]),16);
    bufp->fullSData(oldp+9,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[8]),16);
    bufp->fullSData(oldp+10,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[9]),16);
    bufp->fullSData(oldp+11,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[10]),16);
    bufp->fullSData(oldp+12,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[11]),16);
    bufp->fullSData(oldp+13,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[12]),16);
    bufp->fullSData(oldp+14,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[13]),16);
    bufp->fullSData(oldp+15,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[14]),16);
    bufp->fullSData(oldp+16,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[15]),16);
    bufp->fullSData(oldp+17,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[16]),16);
    bufp->fullSData(oldp+18,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[17]),16);
    bufp->fullSData(oldp+19,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[18]),16);
    bufp->fullSData(oldp+20,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[19]),16);
    bufp->fullSData(oldp+21,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[20]),16);
    bufp->fullSData(oldp+22,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[21]),16);
    bufp->fullSData(oldp+23,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[22]),16);
    bufp->fullSData(oldp+24,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[23]),16);
    bufp->fullSData(oldp+25,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[24]),16);
    bufp->fullSData(oldp+26,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[25]),16);
    bufp->fullSData(oldp+27,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[26]),16);
    bufp->fullSData(oldp+28,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[27]),16);
    bufp->fullSData(oldp+29,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[28]),16);
    bufp->fullSData(oldp+30,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[29]),16);
    bufp->fullSData(oldp+31,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[30]),16);
    bufp->fullSData(oldp+32,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b2_rom[31]),16);
    bufp->fullSData(oldp+33,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[0]),16);
    bufp->fullSData(oldp+34,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[1]),16);
    bufp->fullSData(oldp+35,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[2]),16);
    bufp->fullSData(oldp+36,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[3]),16);
    bufp->fullSData(oldp+37,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[4]),16);
    bufp->fullSData(oldp+38,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[5]),16);
    bufp->fullSData(oldp+39,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[6]),16);
    bufp->fullSData(oldp+40,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[7]),16);
    bufp->fullSData(oldp+41,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[8]),16);
    bufp->fullSData(oldp+42,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[9]),16);
    bufp->fullSData(oldp+43,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[10]),16);
    bufp->fullSData(oldp+44,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[11]),16);
    bufp->fullSData(oldp+45,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[12]),16);
    bufp->fullSData(oldp+46,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[13]),16);
    bufp->fullSData(oldp+47,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[14]),16);
    bufp->fullSData(oldp+48,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[15]),16);
    bufp->fullSData(oldp+49,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[16]),16);
    bufp->fullSData(oldp+50,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[17]),16);
    bufp->fullSData(oldp+51,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[18]),16);
    bufp->fullSData(oldp+52,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[19]),16);
    bufp->fullSData(oldp+53,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[20]),16);
    bufp->fullSData(oldp+54,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[21]),16);
    bufp->fullSData(oldp+55,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[22]),16);
    bufp->fullSData(oldp+56,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[23]),16);
    bufp->fullSData(oldp+57,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[24]),16);
    bufp->fullSData(oldp+58,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[25]),16);
    bufp->fullSData(oldp+59,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[26]),16);
    bufp->fullSData(oldp+60,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[27]),16);
    bufp->fullSData(oldp+61,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[28]),16);
    bufp->fullSData(oldp+62,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[29]),16);
    bufp->fullSData(oldp+63,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[30]),16);
    bufp->fullSData(oldp+64,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__w3_rom[31]),16);
    bufp->fullSData(oldp+65,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__b3_rom[0]),16);
    bufp->fullSData(oldp+66,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[0]),16);
    bufp->fullSData(oldp+67,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[1]),16);
    bufp->fullSData(oldp+68,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[2]),16);
    bufp->fullSData(oldp+69,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[3]),16);
    bufp->fullSData(oldp+70,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[4]),16);
    bufp->fullSData(oldp+71,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[5]),16);
    bufp->fullSData(oldp+72,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[6]),16);
    bufp->fullSData(oldp+73,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_lut[7]),16);
    bufp->fullBit(oldp+74,(vlSelf->tb_rls_dnn_top__DOT__rst_n));
    bufp->fullBit(oldp+75,(vlSelf->tb_rls_dnn_top__DOT__m_axis_tready));
    bufp->fullCData(oldp+76,(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr),8);
    bufp->fullBit(oldp+77,(vlSelf->tb_rls_dnn_top__DOT__s_axi_awvalid));
    bufp->fullIData(oldp+78,(vlSelf->tb_rls_dnn_top__DOT__s_axi_wdata),32);
    bufp->fullBit(oldp+79,(vlSelf->tb_rls_dnn_top__DOT__s_axi_wvalid));
    bufp->fullBit(oldp+80,(vlSelf->tb_rls_dnn_top__DOT__s_axi_bready));
    bufp->fullCData(oldp+81,(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr),8);
    bufp->fullBit(oldp+82,(vlSelf->tb_rls_dnn_top__DOT__s_axi_arvalid));
    bufp->fullBit(oldp+83,(vlSelf->tb_rls_dnn_top__DOT__s_axi_rready));
    bufp->fullCData(oldp+84,((7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                    >> 4U))),3);
    bufp->fullBit(oldp+85,((0U == (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                         >> 4U)))));
    bufp->fullBit(oldp+86,((1U == (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                         >> 4U)))));
    bufp->fullBit(oldp+87,((2U == (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                         >> 4U)))));
    bufp->fullBit(oldp+88,((3U == (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                         >> 4U)))));
    bufp->fullBit(oldp+89,((4U == (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                         >> 4U)))));
    bufp->fullBit(oldp+90,((5U == (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                         >> 4U)))));
    bufp->fullBit(oldp+91,((6U <= (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr) 
                                         >> 4U)))));
    bufp->fullCData(oldp+92,((7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr) 
                                    >> 4U))),3);
    bufp->fullBit(oldp+93,((3U == (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr) 
                                         >> 4U)))));
    bufp->fullBit(oldp+94,((6U == (7U & ((IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr) 
                                         >> 4U)))));
    bufp->fullCData(oldp+95,((0xfU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))),4);
    bufp->fullCData(oldp+96,((0x1fU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_awaddr))),5);
    bufp->fullCData(oldp+97,((0xfU & (IData)(vlSelf->tb_rls_dnn_top__DOT__s_axi_araddr))),4);
    bufp->fullBit(oldp+98,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_affhc__s_axi_awvalid));
    bufp->fullBit(oldp+99,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_affhc__s_axi_wvalid));
    bufp->fullBit(oldp+100,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_plwd__s_axi_arvalid));
    bufp->fullBit(oldp+101,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_plwd__s_axi_awvalid));
    bufp->fullBit(oldp+102,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_plwd__s_axi_wvalid));
    bufp->fullBit(oldp+103,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__s_axi_awvalid));
    bufp->fullBit(oldp+104,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__s_axi_wvalid));
    bufp->fullBit(oldp+105,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_latprof__s_axi_arvalid));
    bufp->fullBit(oldp+106,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_rcim__s_axi_awvalid));
    bufp->fullBit(oldp+107,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_rcim__s_axi_wvalid));
    bufp->fullBit(oldp+108,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_clk_gate_en));
    bufp->fullBit(oldp+109,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_clip_s1));
    bufp->fullBit(oldp+110,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_signal_active));
    bufp->fullQData(oldp+111,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__acc_A_dbg),40);
    bufp->fullQData(oldp+113,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__acc_B_dbg),40);
    bufp->fullCData(oldp+115,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__ratio_shift_reg),4);
    bufp->fullIData(oldp+116,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__x_sq),32);
    bufp->fullIData(oldp+117,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__mul_tmp),32);
    bufp->fullQData(oldp+118,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__acc_A),40);
    bufp->fullQData(oldp+120,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__acc_B),40);
    bufp->fullBit(oldp+122,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__activity_cmp));
    bufp->fullCData(oldp+123,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__assert_cnt),3);
    bufp->fullCData(oldp+124,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_aad__DOT__deassert_cnt),7);
    bufp->fullIData(oldp+125,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w1_s1),32);
    bufp->fullIData(oldp+126,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w2_s1),32);
    bufp->fullIData(oldp+127,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w0_s1),32);
    bufp->fullIData(oldp+128,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s1),32);
    bufp->fullIData(oldp+129,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_a1_s1),32);
    bufp->fullIData(oldp+130,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_a2_s1),32);
    bufp->fullIData(oldp+131,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b0_s1),32);
    bufp->fullIData(oldp+132,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b1_s1),32);
    bufp->fullIData(oldp+133,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b2_s1),32);
    bufp->fullSData(oldp+134,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s1_trunc),16);
    bufp->fullBit(oldp+135,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s1_valid_stg1));
    bufp->fullSData(oldp+136,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__corr_threshold),16);
    bufp->fullCData(oldp+137,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__ratio_shift),4);
    bufp->fullQData(oldp+138,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__corr_acc),40);
    bufp->fullQData(oldp+140,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__ref_power_acc),40);
    bufp->fullIData(oldp+142,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__mul_dx),32);
    bufp->fullIData(oldp+143,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__mul_xx),32);
    bufp->fullSData(oldp+144,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[0]),16);
    bufp->fullSData(oldp+145,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[1]),16);
    bufp->fullSData(oldp+146,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[2]),16);
    bufp->fullSData(oldp+147,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[3]),16);
    bufp->fullSData(oldp+148,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[4]),16);
    bufp->fullSData(oldp+149,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[5]),16);
    bufp->fullSData(oldp+150,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[6]),16);
    bufp->fullSData(oldp+151,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[7]),16);
    bufp->fullSData(oldp+152,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[8]),16);
    bufp->fullSData(oldp+153,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[9]),16);
    bufp->fullSData(oldp+154,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[10]),16);
    bufp->fullSData(oldp+155,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[11]),16);
    bufp->fullSData(oldp+156,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[12]),16);
    bufp->fullSData(oldp+157,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[13]),16);
    bufp->fullSData(oldp+158,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[14]),16);
    bufp->fullSData(oldp+159,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__lutram[15]),16);
    bufp->fullCData(oldp+160,((0xfU & (IData)((vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__ref_power_acc 
                                               >> 0x23U)))),4);
    bufp->fullSData(oldp+161,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__recip_approx),16);
    bufp->fullSData(oldp+162,((0xffffU & (IData)((vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__ref_power_acc 
                                                  >> 0xfU)))),16);
    bufp->fullSData(oldp+163,((0xffffU & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__mul_nr2 
                                          >> 0xfU))),16);
    bufp->fullIData(oldp+164,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__mul_nr1),32);
    bufp->fullIData(oldp+165,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__mul_nr2),32);
    bufp->fullSData(oldp+166,((0xffffU & ((1U & (IData)(
                                                        (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__corr_acc 
                                                         >> 0x1fU)))
                                           ? ((IData)(1U) 
                                              + (~ (IData)(
                                                           (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__corr_acc 
                                                            >> 0xfU))))
                                           : (IData)(
                                                     (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__corr_acc 
                                                      >> 0xfU))))),16);
    bufp->fullSData(oldp+167,((0xffffU & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__mul_norm 
                                          >> 0xfU))),16);
    bufp->fullIData(oldp+168,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__mul_norm),32);
    bufp->fullCData(oldp+169,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__fault_cnt),8);
    bufp->fullCData(oldp+170,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rcim__DOT__recover_cnt),8);
    bufp->fullIData(oldp+171,(vlSelf->tb_rls_dnn_top__DOT__out_cnt),32);
    bufp->fullIData(oldp+172,(vlSelf->tb_rls_dnn_top__DOT__pass_cnt),32);
    bufp->fullIData(oldp+173,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__i),32);
    __Vtemp_3[0U] = ((vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                      [6U] << 0x10U) | vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                     [7U]);
    __Vtemp_3[1U] = (((0xffffU & vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                       [5U]) | (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
                                [6U] >> 0x10U)) | ((IData)(
                                                           (((QData)((IData)(
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
                                                                               [4U]))))) 
                                                   << 0x10U));
    __Vtemp_3[2U] = (((IData)((((QData)((IData)(((vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr
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
                      [0U] << 0x10U) | ((IData)(((((QData)((IData)(
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
    bufp->fullWData(oldp+174,(__Vtemp_3),128);
    bufp->fullSData(oldp+178,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__mlp_noise_est),16);
    bufp->fullSData(oldp+179,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__fwes_e_weighted),16);
    bufp->fullSData(oldp+180,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_err_pipe[0]),16);
    bufp->fullSData(oldp+181,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_err_pipe[1]),16);
    bufp->fullSData(oldp+182,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_err_pipe[2]),16);
    bufp->fullBit(oldp+183,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_vld_pipe[0]));
    bufp->fullBit(oldp+184,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_vld_pipe[1]));
    bufp->fullBit(oldp+185,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_vld_pipe[2]));
    bufp->fullIData(oldp+186,((0x1ffffU & VL_SHIFTR_III(17,17,32, 
                                                        ((0x10000U 
                                                          & ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__mlp_noise_est) 
                                                             << 1U)) 
                                                         | (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__mlp_noise_est)), 4U))),17);
    bufp->fullBit(oldp+187,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__latprof_rvalid));
    bufp->fullSData(oldp+188,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_leak_factor),16);
    bufp->fullSData(oldp+189,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__fwes_alpha_reg),16);
    bufp->fullSData(oldp+190,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_fwes__DOT__e_w_prev),16);
    bufp->fullIData(oldp+191,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_fwes__DOT__unnamedblk1__DOT__alpha_term),32);
    bufp->fullIData(oldp+192,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__free_cnt_snap),32);
    bufp->fullSData(oldp+193,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[0]),16);
    bufp->fullSData(oldp+194,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[1]),16);
    bufp->fullSData(oldp+195,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[2]),16);
    bufp->fullSData(oldp+196,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[3]),16);
    bufp->fullSData(oldp+197,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[4]),16);
    bufp->fullSData(oldp+198,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[5]),16);
    bufp->fullSData(oldp+199,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[6]),16);
    bufp->fullSData(oldp+200,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__feat[7]),16);
    bufp->fullSData(oldp+201,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[0]),16);
    bufp->fullSData(oldp+202,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[1]),16);
    bufp->fullSData(oldp+203,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[2]),16);
    bufp->fullSData(oldp+204,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[3]),16);
    bufp->fullSData(oldp+205,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[4]),16);
    bufp->fullSData(oldp+206,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[5]),16);
    bufp->fullSData(oldp+207,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[6]),16);
    bufp->fullSData(oldp+208,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[7]),16);
    bufp->fullSData(oldp+209,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[8]),16);
    bufp->fullSData(oldp+210,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[9]),16);
    bufp->fullSData(oldp+211,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[10]),16);
    bufp->fullSData(oldp+212,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[11]),16);
    bufp->fullSData(oldp+213,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[12]),16);
    bufp->fullSData(oldp+214,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[13]),16);
    bufp->fullSData(oldp+215,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[14]),16);
    bufp->fullSData(oldp+216,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[15]),16);
    bufp->fullSData(oldp+217,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[16]),16);
    bufp->fullSData(oldp+218,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[17]),16);
    bufp->fullSData(oldp+219,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[18]),16);
    bufp->fullSData(oldp+220,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[19]),16);
    bufp->fullSData(oldp+221,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[20]),16);
    bufp->fullSData(oldp+222,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[21]),16);
    bufp->fullSData(oldp+223,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[22]),16);
    bufp->fullSData(oldp+224,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[23]),16);
    bufp->fullSData(oldp+225,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[24]),16);
    bufp->fullSData(oldp+226,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[25]),16);
    bufp->fullSData(oldp+227,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[26]),16);
    bufp->fullSData(oldp+228,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[27]),16);
    bufp->fullSData(oldp+229,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[28]),16);
    bufp->fullSData(oldp+230,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[29]),16);
    bufp->fullSData(oldp+231,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[30]),16);
    bufp->fullSData(oldp+232,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__h2[31]),16);
    bufp->fullIData(oldp+233,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER1__DOT__L1_COMPUTE__DOT__n),32);
    bufp->fullIData(oldp+234,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER1__DOT__L1_COMPUTE__DOT__k),32);
    bufp->fullQData(oldp+235,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER1__DOT__L1_COMPUTE__DOT__acc),40);
    bufp->fullIData(oldp+237,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER2__DOT__L2_COMPUTE__DOT__n),32);
    bufp->fullIData(oldp+238,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER2__DOT__L2_COMPUTE__DOT__k),32);
    bufp->fullQData(oldp+239,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER2__DOT__L2_COMPUTE__DOT__acc),40);
    bufp->fullIData(oldp+241,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER3__DOT__L3_COMPUTE__DOT__k),32);
    bufp->fullQData(oldp+242,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__LAYER3__DOT__L3_COMPUTE__DOT__acc),40);
    bufp->fullSData(oldp+244,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr[0]),16);
    bufp->fullSData(oldp+245,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr[1]),16);
    bufp->fullSData(oldp+246,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr[2]),16);
    bufp->fullSData(oldp+247,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr[3]),16);
    bufp->fullSData(oldp+248,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr[4]),16);
    bufp->fullSData(oldp+249,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr[5]),16);
    bufp->fullSData(oldp+250,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr[6]),16);
    bufp->fullSData(oldp+251,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__sr[7]),16);
    bufp->fullIData(oldp+252,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_ptdl__DOT__i),32);
    bufp->fullSData(oldp+253,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__p_scalar),16);
    bufp->fullSData(oldp+254,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__e_reg),16);
    bufp->fullIData(oldp+255,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__i),32);
    bufp->fullSData(oldp+256,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_denom_p1),16);
    bufp->fullSData(oldp+257,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_x1),16);
    bufp->fullSData(oldp+258,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_x2),16);
    bufp->fullSData(oldp+259,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly_p1[0]),16);
    bufp->fullSData(oldp+260,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly_p1[1]),16);
    bufp->fullSData(oldp+261,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly_p1[2]),16);
    bufp->fullSData(oldp+262,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly_p1[3]),16);
    bufp->fullSData(oldp+263,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly_p1[4]),16);
    bufp->fullSData(oldp+264,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly_p1[5]),16);
    bufp->fullSData(oldp+265,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly_p1[6]),16);
    bufp->fullSData(oldp+266,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly_p1[7]),16);
    bufp->fullSData(oldp+267,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__e_reg_p1),16);
    bufp->fullIData(oldp+268,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__j),32);
    bufp->fullIData(oldp+269,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__denom),32);
    bufp->fullSData(oldp+270,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__d_norm),16);
    bufp->fullCData(oldp+271,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__lut_idx),3);
    bufp->fullSData(oldp+272,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__x0),16);
    bufp->fullIData(oldp+273,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__Dx0),32);
    bufp->fullSData(oldp+274,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE1_NR1__DOT__NR_STAGE1__DOT__residual1),16);
    bufp->fullIData(oldp+275,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__Dx1),32);
    bufp->fullIData(oldp+276,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__p_over_denom),32);
    bufp->fullIData(oldp+277,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__ke),32);
    bufp->fullSData(oldp+278,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__residual2),16);
    bufp->fullIData(oldp+279,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__j),32);
    bufp->fullIData(oldp+280,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__P_UPDATE__DOT__p_new),32);
    bufp->fullIData(oldp+281,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__w_leaked),32);
    bufp->fullSData(oldp+282,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE2_NR2__DOT__unnamedblk1__DOT__unnamedblk2__DOT__update_err),16);
    bufp->fullCData(oldp+283,(vlSelf->tb_rls_dnn_top__DOT__s_axi_bresp),2);
    bufp->fullBit(oldp+284,(vlSelf->tb_rls_dnn_top__DOT__s_axi_bvalid));
    bufp->fullIData(oldp+285,(vlSelf->tb_rls_dnn_top__DOT__s_axi_rdata),32);
    bufp->fullCData(oldp+286,(vlSelf->tb_rls_dnn_top__DOT__s_axi_rresp),2);
    bufp->fullBit(oldp+287,(vlSelf->tb_rls_dnn_top__DOT__s_axi_rvalid));
    bufp->fullSData(oldp+288,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_lambda_out),16);
    bufp->fullCData(oldp+289,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_fsm_state_dbg),2);
    bufp->fullBit(oldp+290,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_awready));
    bufp->fullBit(oldp+291,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_wready));
    bufp->fullBit(oldp+292,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_awready));
    bufp->fullBit(oldp+293,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_wready));
    bufp->fullIData(oldp+294,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_rdata),32);
    bufp->fullBit(oldp+295,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_rvalid));
    bufp->fullSData(oldp+296,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lambda_slow),16);
    bufp->fullSData(oldp+297,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lambda_mid),16);
    bufp->fullSData(oldp+298,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lambda_fast),16);
    bufp->fullSData(oldp+299,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__threshold_up_reg),16);
    bufp->fullSData(oldp+300,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__threshold_down_reg),16);
    bufp->fullCData(oldp+301,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__state),2);
    bufp->fullCData(oldp+302,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__next_state),2);
    bufp->fullSData(oldp+303,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__e_prev),16);
    bufp->fullCData(oldp+304,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_up),3);
    bufp->fullCData(oldp+305,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__cnt_down),4);
    bufp->fullCData(oldp+306,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_cnt),6);
    bufp->fullBit(oldp+307,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__lockout_active));
    bufp->fullSData(oldp+308,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__timeout_cnt),16);
    bufp->fullSData(oldp+309,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__last_sample),16);
    bufp->fullCData(oldp+310,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__stuck_cnt),5);
    bufp->fullSData(oldp+311,(((0U == (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_lambda_out))
                                ? 0x7f00U : (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_lambda_out))),16);
    bufp->fullBit(oldp+312,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_awready));
    bufp->fullBit(oldp+313,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_wready));
    bufp->fullBit(oldp+314,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_awready));
    bufp->fullBit(oldp+315,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_wready));
    bufp->fullBit(oldp+316,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_awready));
    bufp->fullBit(oldp+317,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_wready));
    bufp->fullSData(oldp+318,(vlSelf->tb_rls_dnn_top__DOT__m_axis_tdata),16);
    bufp->fullBit(oldp+319,(vlSelf->tb_rls_dnn_top__DOT__m_axis_tvalid));
    bufp->fullSData(oldp+320,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_error),16);
    bufp->fullSData(oldp+321,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_y_hat),16);
    bufp->fullBit(oldp+322,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_valid_out));
    bufp->fullBit(oldp+323,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__mlp_valid_out));
    bufp->fullBit(oldp+324,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__poly_rls_en));
    bufp->fullCData(oldp+325,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__poly_decim_cnt_dbg),3);
    bufp->fullCData(oldp+326,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__decim_ratio),3);
    bufp->fullSData(oldp+327,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[0]),16);
    bufp->fullSData(oldp+328,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[1]),16);
    bufp->fullSData(oldp+329,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[2]),16);
    bufp->fullSData(oldp+330,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[3]),16);
    bufp->fullSData(oldp+331,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[4]),16);
    bufp->fullSData(oldp+332,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly[5]),16);
    bufp->fullBit(oldp+333,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__decim_q));
    bufp->fullBit(oldp+334,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rls_en));
    bufp->fullIData(oldp+335,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sub_full),17);
    bufp->fullSData(oldp+336,((0xffffU & (((1U & (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sub_full 
                                                  >> 0x10U)) 
                                           == (1U & 
                                               (vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sub_full 
                                                >> 0xfU)))
                                           ? vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sub_full
                                           : ((0x10000U 
                                               & vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sub_full)
                                               ? 0x8000U
                                               : 0x7fffU)))),16);
    bufp->fullIData(oldp+337,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__latprof_rdata),32);
    bufp->fullIData(oldp+338,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__free_cnt),32);
    bufp->fullIData(oldp+339,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_cbpf),32);
    bufp->fullIData(oldp+340,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_rls),32);
    bufp->fullIData(oldp+341,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_ptdl),32);
    bufp->fullIData(oldp+342,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_mlp),32);
    bufp->fullIData(oldp+343,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__ts_output),32);
    bufp->fullIData(oldp+344,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_cbpf_to_rls),32);
    bufp->fullIData(oldp+345,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_rls_to_ptdl),32);
    bufp->fullIData(oldp+346,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_ptdl_to_mlp),32);
    bufp->fullIData(oldp+347,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_mlp_to_out),32);
    bufp->fullIData(oldp+348,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_latprof__DOT__lat_total),32);
    bufp->fullBit(oldp+349,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__s0_valid));
    bufp->fullBit(oldp+350,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__s1_valid));
    bufp->fullCData(oldp+351,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_poly__DOT__decim_cnt),3);
    bufp->fullSData(oldp+352,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly
                              [4U]),16);
    bufp->fullSData(oldp+353,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__d_dly
                              [5U]),16);
    bufp->fullSData(oldp+354,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[0]),16);
    bufp->fullSData(oldp+355,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[1]),16);
    bufp->fullSData(oldp+356,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[2]),16);
    bufp->fullSData(oldp+357,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[3]),16);
    bufp->fullSData(oldp+358,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[4]),16);
    bufp->fullSData(oldp+359,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[5]),16);
    bufp->fullSData(oldp+360,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[6]),16);
    bufp->fullSData(oldp+361,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__w[7]),16);
    bufp->fullSData(oldp+362,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[0]),16);
    bufp->fullSData(oldp+363,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[1]),16);
    bufp->fullSData(oldp+364,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[2]),16);
    bufp->fullSData(oldp+365,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[3]),16);
    bufp->fullSData(oldp+366,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[4]),16);
    bufp->fullSData(oldp+367,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[5]),16);
    bufp->fullSData(oldp+368,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[6]),16);
    bufp->fullSData(oldp+369,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__x_dly[7]),16);
    bufp->fullQData(oldp+370,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__y_acc),40);
    bufp->fullQData(oldp+372,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__xTx_acc),40);
    bufp->fullSData(oldp+374,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__d_pipe),16);
    bufp->fullBit(oldp+375,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__s1_valid));
    bufp->fullBit(oldp+376,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_p1_valid));
    bufp->fullBit(oldp+377,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__nr_p2_valid));
    bufp->fullSData(oldp+378,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__d_pipe_p1),16);
    bufp->fullQData(oldp+379,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_y),40);
    bufp->fullQData(oldp+381,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_rls__DOT__STAGE0__DOT__DOT_PRODUCT__DOT__acc_xx),40);
    bufp->fullSData(oldp+383,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__x_cbpf),16);
    bufp->fullBit(oldp+384,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_y_valid));
    bufp->fullBit(oldp+385,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_clip_s2));
    bufp->fullBit(oldp+386,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_ref_channel_fault));
    bufp->fullSData(oldp+387,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_x_out_muxed),16);
    bufp->fullBit(oldp+388,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__bypass_reg));
    bufp->fullBit(oldp+389,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s1_valid_stg2));
    bufp->fullIData(oldp+390,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w1_s2),32);
    bufp->fullIData(oldp+391,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w2_s2),32);
    bufp->fullIData(oldp+392,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__w0_s2),32);
    bufp->fullIData(oldp+393,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s2),32);
    bufp->fullIData(oldp+394,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_a1_s2),32);
    bufp->fullIData(oldp+395,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_a2_s2),32);
    bufp->fullIData(oldp+396,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b0_s2),32);
    bufp->fullIData(oldp+397,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b1_s2),32);
    bufp->fullIData(oldp+398,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__mul_b2_s2),32);
    bufp->fullSData(oldp+399,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__y_s2_trunc),16);
    bufp->fullBit(oldp+400,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s2_valid_stg1));
    bufp->fullBit(oldp+401,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_cbpf__DOT__s2_valid_stg2));
    bufp->fullBit(oldp+402,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_pipeline_srst));
    bufp->fullBit(oldp+403,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__pipeline_stall_fault));
    bufp->fullBit(oldp+404,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__output_stuck_fault));
    bufp->fullIData(oldp+405,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__global_sample_cnt),32);
    bufp->fullIData(oldp+406,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_sample_cnt),32);
    bufp->fullCData(oldp+407,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_count_reg),8);
    bufp->fullCData(oldp+408,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__rcv_state),2);
    bufp->fullCData(oldp+409,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__drain_cnt),3);
    bufp->fullIData(oldp+410,(vlSelf->tb_rls_dnn_top__DOT__clk_cnt),32);
    bufp->fullIData(oldp+411,(vlSelf->tb_rls_dnn_top__DOT__sample_idx),32);
    bufp->fullSData(oldp+412,(vlSelf->tb_rls_dnn_top__DOT__d_sample),16);
    bufp->fullSData(oldp+413,(vlSelf->tb_rls_dnn_top__DOT__x_sample),16);
    bufp->fullDouble(oldp+414,(vlSelf->tb_rls_dnn_top__DOT__sin_lut__Vstatic__angle));
    bufp->fullBit(oldp+416,(vlSelf->tb_rls_dnn_top__DOT__clk));
    bufp->fullBit(oldp+417,(vlSelf->tb_rls_dnn_top__DOT__sample_enable));
    bufp->fullIData(oldp+418,(vlSelf->tb_rls_dnn_top__DOT__s_axis_tdata),32);
    bufp->fullBit(oldp+419,(vlSelf->tb_rls_dnn_top__DOT__s_axis_tvalid));
    bufp->fullBit(oldp+420,(vlSelf->tb_rls_dnn_top__DOT__s_axis_tready));
    bufp->fullBit(oldp+421,(((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_awready) 
                             | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_awready) 
                                | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_awready) 
                                   | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_awready) 
                                      | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_awready) 
                                         | (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____VdfgRegularize_h739c3624_2_0))))))));
    bufp->fullBit(oldp+422,(((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__affhc_wready) 
                             | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__aad_wready) 
                                | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__cbpf_wready) 
                                   | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_wready) 
                                      | ((IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__rcim_wready) 
                                         | (IData)(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____VdfgRegularize_h739c3624_2_0))))))));
    bufp->fullBit(oldp+423,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__plwd_irq_fault));
    bufp->fullSData(oldp+424,((0xffffU & vlSelf->tb_rls_dnn_top__DOT__s_axis_tdata)),16);
    bufp->fullSData(oldp+425,((vlSelf->tb_rls_dnn_top__DOT__s_axis_tdata 
                               >> 0x10U)),16);
    bufp->fullBit(oldp+426,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__sample_consumed_cbpf));
    bufp->fullBit(oldp+427,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_aad__rst_n));
    bufp->fullIData(oldp+428,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_affhc__DOT__delta_e),17);
    bufp->fullBit(oldp+429,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_cbpf__s_axi_awvalid));
    bufp->fullBit(oldp+430,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT____Vcellinp__u_cbpf__s_axi_wvalid));
    bufp->fullIData(oldp+431,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_mlp__DOT__ii),32);
    bufp->fullCData(oldp+432,(vlSelf->tb_rls_dnn_top__DOT__dut__DOT__u_plwd__DOT__fault_type_reg),2);
}

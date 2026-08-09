// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_cbpf_2sos.h for the primary calling header

#include "Vtb_cbpf_2sos__pch.h"
#include "Vtb_cbpf_2sos__Syms.h"
#include "Vtb_cbpf_2sos___024root.h"

void Vtb_cbpf_2sos___024root___ctor_var_reset(Vtb_cbpf_2sos___024root* vlSelf);

Vtb_cbpf_2sos___024root::Vtb_cbpf_2sos___024root(Vtb_cbpf_2sos__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_cbpf_2sos___024root___ctor_var_reset(this);
}

void Vtb_cbpf_2sos___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_cbpf_2sos___024root::~Vtb_cbpf_2sos___024root() {
}

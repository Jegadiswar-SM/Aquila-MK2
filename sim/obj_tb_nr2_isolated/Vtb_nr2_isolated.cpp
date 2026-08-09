// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_nr2_isolated__pch.h"

//============================================================
// Constructors

Vtb_nr2_isolated::Vtb_nr2_isolated(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_nr2_isolated__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_nr2_isolated::Vtb_nr2_isolated(const char* _vcname__)
    : Vtb_nr2_isolated(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_nr2_isolated::~Vtb_nr2_isolated() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_nr2_isolated___024root___eval_debug_assertions(Vtb_nr2_isolated___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_nr2_isolated___024root___eval_static(Vtb_nr2_isolated___024root* vlSelf);
void Vtb_nr2_isolated___024root___eval_initial(Vtb_nr2_isolated___024root* vlSelf);
void Vtb_nr2_isolated___024root___eval_settle(Vtb_nr2_isolated___024root* vlSelf);
void Vtb_nr2_isolated___024root___eval(Vtb_nr2_isolated___024root* vlSelf);

void Vtb_nr2_isolated::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_nr2_isolated::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_nr2_isolated___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_nr2_isolated___024root___eval_static(&(vlSymsp->TOP));
        Vtb_nr2_isolated___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_nr2_isolated___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_nr2_isolated___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_nr2_isolated::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtb_nr2_isolated::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_nr2_isolated::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_nr2_isolated___024root___eval_final(Vtb_nr2_isolated___024root* vlSelf);

VL_ATTR_COLD void Vtb_nr2_isolated::final() {
    Vtb_nr2_isolated___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_nr2_isolated::hierName() const { return vlSymsp->name(); }
const char* Vtb_nr2_isolated::modelName() const { return "Vtb_nr2_isolated"; }
unsigned Vtb_nr2_isolated::threads() const { return 1; }
void Vtb_nr2_isolated::prepareClone() const { contextp()->prepareClone(); }
void Vtb_nr2_isolated::atClone() const {
    contextp()->threadPoolpOnClone();
}

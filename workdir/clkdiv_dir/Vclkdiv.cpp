// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vclkdiv.h"
#include "Vclkdiv__Syms.h"

//============================================================
// Constructors

Vclkdiv::Vclkdiv(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vclkdiv__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , hzX{vlSymsp->TOP.hzX}
    , lim{vlSymsp->TOP.lim}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vclkdiv::Vclkdiv(const char* _vcname__)
    : Vclkdiv(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vclkdiv::~Vclkdiv() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vclkdiv___024root___eval_debug_assertions(Vclkdiv___024root* vlSelf);
#endif  // VL_DEBUG
void Vclkdiv___024root___eval_static(Vclkdiv___024root* vlSelf);
void Vclkdiv___024root___eval_initial(Vclkdiv___024root* vlSelf);
void Vclkdiv___024root___eval_settle(Vclkdiv___024root* vlSelf);
void Vclkdiv___024root___eval(Vclkdiv___024root* vlSelf);

void Vclkdiv::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vclkdiv::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vclkdiv___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vclkdiv___024root___eval_static(&(vlSymsp->TOP));
        Vclkdiv___024root___eval_initial(&(vlSymsp->TOP));
        Vclkdiv___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vclkdiv___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vclkdiv::eventsPending() { return false; }

uint64_t Vclkdiv::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vclkdiv::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vclkdiv___024root___eval_final(Vclkdiv___024root* vlSelf);

VL_ATTR_COLD void Vclkdiv::final() {
    Vclkdiv___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vclkdiv::hierName() const { return vlSymsp->name(); }
const char* Vclkdiv::modelName() const { return "Vclkdiv"; }
unsigned Vclkdiv::threads() const { return 1; }

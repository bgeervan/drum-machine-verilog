// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCLKDIV__SYMS_H_
#define VERILATED_VCLKDIV__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vclkdiv.h"

// INCLUDE MODULE CLASSES
#include "Vclkdiv___024root.h"

// SYMS CLASS (contains all model state)
class Vclkdiv__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vclkdiv* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vclkdiv___024root              TOP;

    // CONSTRUCTORS
    Vclkdiv__Syms(VerilatedContext* contextp, const char* namep, Vclkdiv* modelp);
    ~Vclkdiv__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard

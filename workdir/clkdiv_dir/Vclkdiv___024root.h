// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vclkdiv.h for the primary calling header

#ifndef VERILATED_VCLKDIV___024ROOT_H_
#define VERILATED_VCLKDIV___024ROOT_H_  // guard

#include "verilated.h"

class Vclkdiv__Syms;

class Vclkdiv___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(hzX,0,0);
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __Vtrigrprev__TOP__rst;
    CData/*0:0*/ __VactContinue;
    VL_IN(lim,19,0);
    IData/*19:0*/ clkdiv__DOT__counter;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vclkdiv__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vclkdiv___024root(Vclkdiv__Syms* symsp, const char* v__name);
    ~Vclkdiv___024root();
    VL_UNCOPYABLE(Vclkdiv___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard

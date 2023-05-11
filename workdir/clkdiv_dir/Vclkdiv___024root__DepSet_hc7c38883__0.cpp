// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vclkdiv.h for the primary calling header

#include "verilated.h"

#include "Vclkdiv___024root.h"

void Vclkdiv___024root___eval_act(Vclkdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkdiv___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vclkdiv___024root___nba_sequent__TOP__0(Vclkdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkdiv___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdly__hzX;
    __Vdly__hzX = 0;
    IData/*19:0*/ __Vdly__clkdiv__DOT__counter;
    __Vdly__clkdiv__DOT__counter = 0;
    // Body
    __Vdly__clkdiv__DOT__counter = vlSelf->clkdiv__DOT__counter;
    __Vdly__hzX = vlSelf->hzX;
    if (vlSelf->rst) {
        __Vdly__hzX = 0U;
        __Vdly__clkdiv__DOT__counter = 0U;
    } else {
        __Vdly__clkdiv__DOT__counter = (0xfffffU & 
                                        ((IData)(1U) 
                                         + vlSelf->clkdiv__DOT__counter));
        if ((vlSelf->clkdiv__DOT__counter == vlSelf->lim)) {
            __Vdly__hzX = (1U & (~ (IData)(vlSelf->hzX)));
            __Vdly__clkdiv__DOT__counter = 0U;
        }
    }
    vlSelf->hzX = __Vdly__hzX;
    vlSelf->clkdiv__DOT__counter = __Vdly__clkdiv__DOT__counter;
}

void Vclkdiv___024root___eval_nba(Vclkdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkdiv___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vclkdiv___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vclkdiv___024root___eval_triggers__act(Vclkdiv___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vclkdiv___024root___dump_triggers__act(Vclkdiv___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vclkdiv___024root___dump_triggers__nba(Vclkdiv___024root* vlSelf);
#endif  // VL_DEBUG

void Vclkdiv___024root___eval(Vclkdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkdiv___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vclkdiv___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vclkdiv___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("clkdiv.sv", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vclkdiv___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vclkdiv___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("clkdiv.sv", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vclkdiv___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vclkdiv___024root___eval_debug_assertions(Vclkdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkdiv___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->lim & 0xfff00000U))) {
        Verilated::overWidthError("lim");}
}
#endif  // VL_DEBUG

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vclkdiv.h for the primary calling header

#include "verilated.h"

#include "Vclkdiv___024root.h"

VL_ATTR_COLD void Vclkdiv___024root___eval_static(Vclkdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkdiv___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vclkdiv___024root___eval_initial(Vclkdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkdiv___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__rst = vlSelf->rst;
}

VL_ATTR_COLD void Vclkdiv___024root___eval_final(Vclkdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkdiv___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vclkdiv___024root___eval_settle(Vclkdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkdiv___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vclkdiv___024root___dump_triggers__act(Vclkdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkdiv___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vclkdiv___024root___dump_triggers__nba(Vclkdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkdiv___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vclkdiv___024root___ctor_var_reset(Vclkdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkdiv___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = 0;
    vlSelf->rst = 0;
    vlSelf->lim = 0;
    vlSelf->hzX = 0;
    vlSelf->clkdiv__DOT__counter = 0;
    vlSelf->__Vtrigrprev__TOP__clk = 0;
    vlSelf->__Vtrigrprev__TOP__rst = 0;
}

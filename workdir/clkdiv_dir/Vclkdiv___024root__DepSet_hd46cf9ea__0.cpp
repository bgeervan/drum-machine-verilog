// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vclkdiv.h for the primary calling header

#include "verilated.h"

#include "Vclkdiv__Syms.h"
#include "Vclkdiv___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vclkdiv___024root___dump_triggers__act(Vclkdiv___024root* vlSelf);
#endif  // VL_DEBUG

void Vclkdiv___024root___eval_triggers__act(Vclkdiv___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vclkdiv__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vclkdiv___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = (((IData)(vlSelf->clk) 
                                       & (~ (IData)(vlSelf->__Vtrigrprev__TOP__clk))) 
                                      | ((IData)(vlSelf->rst) 
                                         & (~ (IData)(vlSelf->__Vtrigrprev__TOP__rst))));
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
    vlSelf->__Vtrigrprev__TOP__rst = vlSelf->rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vclkdiv___024root___dump_triggers__act(vlSelf);
    }
#endif
}

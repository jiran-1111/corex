// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop___024root.h"

void VCoreTop___024root___eval_triggers__ico(VCoreTop___024root* vlSelf);
void VCoreTop___024root___eval_ico(VCoreTop___024root* vlSelf);

bool VCoreTop___024root___eval_phase__ico(VCoreTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreTop___024root___eval_phase__ico\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VCoreTop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        VCoreTop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VCoreTop___024root___eval_act(VCoreTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreTop___024root___eval_act\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void VCoreTop___024root___eval_triggers__act(VCoreTop___024root* vlSelf);

bool VCoreTop___024root___eval_phase__act(VCoreTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreTop___024root___eval_phase__act\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<8> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VCoreTop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VCoreTop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

void VCoreTop___024root___eval_nba(VCoreTop___024root* vlSelf);

bool VCoreTop___024root___eval_phase__nba(VCoreTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreTop___024root___eval_phase__nba\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VCoreTop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCoreTop___024root___dump_triggers__ico(VCoreTop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VCoreTop___024root___dump_triggers__nba(VCoreTop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VCoreTop___024root___dump_triggers__act(VCoreTop___024root* vlSelf);
#endif  // VL_DEBUG

void VCoreTop___024root___eval(VCoreTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreTop___024root___eval\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            VCoreTop___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 10, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VCoreTop___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VCoreTop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 10, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VCoreTop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/ranrr/pku_workspace/corex/hdl_sv/core/core.sv", 10, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VCoreTop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VCoreTop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VCoreTop___024root___eval_debug_assertions(VCoreTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreTop___024root___eval_debug_assertions\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY(((vlSelfRef.start & 0xfeU)))) {
        Verilated::overWidthError("start");}
}
#endif  // VL_DEBUG

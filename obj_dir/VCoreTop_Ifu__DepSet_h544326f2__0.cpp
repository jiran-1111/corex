// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_Ifu.h"

VL_INLINE_OPT void VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__3(VCoreTop_Ifu* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__3\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.PC_reg = vlSelfRef.__Vdly__PC_reg;
    vlSelfRef.PC_plus4 = ((IData)(4U) + vlSelfRef.PC_reg);
}

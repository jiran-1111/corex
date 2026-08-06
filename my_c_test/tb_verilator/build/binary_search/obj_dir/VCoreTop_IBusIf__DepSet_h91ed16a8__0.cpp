// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_IBusIf.h"
#include "VCoreTop__Syms.h"

VL_INLINE_OPT void VCoreTop_IBusIf___ico_sequent__TOP__CoreTop__u_ifu__IMem__ibus__0(VCoreTop_IBusIf* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VCoreTop_IBusIf___ico_sequent__TOP__CoreTop__u_ifu__IMem__ibus__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.err = vlSymsp->TOP__CoreTop__u_ifu__IMem__imem.err;
    vlSelfRef.gnt = vlSymsp->TOP__CoreTop__u_ifu__IMem__imem.gnt;
    vlSelfRef.rdata = vlSymsp->TOP__CoreTop__u_ifu__IMem__imem.rdata_q;
    vlSelfRef.req = vlSymsp->TOP__CoreTop__u_ifu__IMem.req;
    vlSelfRef.addr = vlSymsp->TOP__CoreTop__u_ifu__IMem.addr;
}

VL_INLINE_OPT void VCoreTop_IBusIf___nba_sequent__TOP__CoreTop__u_ifu__IMem__ibus__0(VCoreTop_IBusIf* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VCoreTop_IBusIf___nba_sequent__TOP__CoreTop__u_ifu__IMem__ibus__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.addr = vlSymsp->TOP__CoreTop__u_ifu__IMem.addr;
}

VL_INLINE_OPT void VCoreTop_IBusIf___nba_sequent__TOP__CoreTop__u_ifu__IMem__ibus__2(VCoreTop_IBusIf* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VCoreTop_IBusIf___nba_sequent__TOP__CoreTop__u_ifu__IMem__ibus__2\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rdata = vlSymsp->TOP__CoreTop__u_ifu__IMem__imem.rdata_q;
}

VL_INLINE_OPT void VCoreTop_IBusIf___nba_sequent__TOP__CoreTop__u_ifu__IMem__ibus__3(VCoreTop_IBusIf* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VCoreTop_IBusIf___nba_sequent__TOP__CoreTop__u_ifu__IMem__ibus__3\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.req = vlSymsp->TOP__CoreTop__u_ifu__IMem.req;
}

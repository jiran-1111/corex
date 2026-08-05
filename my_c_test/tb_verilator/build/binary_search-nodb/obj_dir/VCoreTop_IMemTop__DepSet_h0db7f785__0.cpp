// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_IMemTop.h"
#include "VCoreTop__Syms.h"

VL_INLINE_OPT void VCoreTop_IMemTop___ico_sequent__TOP__CoreTop__u_ifu__IMem__0(VCoreTop_IMemTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VCoreTop_IMemTop___ico_sequent__TOP__CoreTop__u_ifu__IMem__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.req = vlSymsp->TOP__CoreTop__u_ifu.fetch;
    vlSelfRef.addr = vlSymsp->TOP__CoreTop__u_ifu.PC_reg;
    vlSelfRef.ack = vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.ack;
    vlSelfRef.clk = vlSymsp->TOP__CoreTop__u_ifu.clk;
    vlSelfRef.rst = vlSymsp->TOP__CoreTop__u_ifu.rst;
}

VL_INLINE_OPT void VCoreTop_IMemTop___ico_sequent__TOP__CoreTop__u_ifu__IMem__1(VCoreTop_IMemTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VCoreTop_IMemTop___ico_sequent__TOP__CoreTop__u_ifu__IMem__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.err = vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.err;
    vlSelfRef.gnt = vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.gnt;
    vlSelfRef.rdata = vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.rdata;
}

VL_INLINE_OPT void VCoreTop_IMemTop___nba_sequent__TOP__CoreTop__u_ifu__IMem__0(VCoreTop_IMemTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VCoreTop_IMemTop___nba_sequent__TOP__CoreTop__u_ifu__IMem__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.addr = vlSymsp->TOP__CoreTop__u_ifu.PC_reg;
    vlSelfRef.req = vlSymsp->TOP__CoreTop__u_ifu.fetch;
}

VL_INLINE_OPT void VCoreTop_IMemTop___nba_sequent__TOP__CoreTop__u_ifu__IMem__1(VCoreTop_IMemTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VCoreTop_IMemTop___nba_sequent__TOP__CoreTop__u_ifu__IMem__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ack = vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.ack;
    vlSelfRef.rdata = vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.rdata;
}

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
    if (((IData)(vlSelfRef.ack) ^ (IData)(vlSelfRef.__Vtogcov__ack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6567, vlSelfRef.ack, vlSelfRef.__Vtogcov__ack);
        vlSelfRef.__Vtogcov__ack = vlSelfRef.ack;
    }
    vlSelfRef.err = vlSymsp->TOP__CoreTop__u_ifu__IMem__imem.err;
    vlSelfRef.gnt = vlSymsp->TOP__CoreTop__u_ifu__IMem__imem.gnt;
    vlSelfRef.rdata = vlSymsp->TOP__CoreTop__u_ifu__IMem__imem.rdata_q;
    if (((IData)(vlSelfRef.err) ^ (IData)(vlSelfRef.__Vtogcov__err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6569, vlSelfRef.err, vlSelfRef.__Vtogcov__err);
        vlSelfRef.__Vtogcov__err = vlSelfRef.err;
    }
    if (((IData)(vlSelfRef.gnt) ^ (IData)(vlSelfRef.__Vtogcov__gnt))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6565, vlSelfRef.gnt, vlSelfRef.__Vtogcov__gnt);
        vlSelfRef.__Vtogcov__gnt = vlSelfRef.gnt;
    }
    if ((vlSelfRef.rdata ^ vlSelfRef.__Vtogcov__rdata)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 6571, vlSelfRef.rdata, vlSelfRef.__Vtogcov__rdata);
        vlSelfRef.__Vtogcov__rdata = vlSelfRef.rdata;
    }
}

VL_INLINE_OPT void VCoreTop_IBusIf___ico_sequent__TOP__CoreTop__u_ifu__IMem__ibus__1(VCoreTop_IBusIf* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VCoreTop_IBusIf___ico_sequent__TOP__CoreTop__u_ifu__IMem__ibus__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.req = vlSymsp->TOP__CoreTop__u_ifu__IMem.req;
    vlSelfRef.addr = vlSymsp->TOP__CoreTop__u_ifu__IMem.addr;
    if (((IData)(vlSelfRef.req) ^ (IData)(vlSelfRef.__Vtogcov__req))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6499, vlSelfRef.req, vlSelfRef.__Vtogcov__req);
        vlSelfRef.__Vtogcov__req = vlSelfRef.req;
    }
    if ((vlSelfRef.addr ^ vlSelfRef.__Vtogcov__addr)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 6501, vlSelfRef.addr, vlSelfRef.__Vtogcov__addr);
        vlSelfRef.__Vtogcov__addr = vlSelfRef.addr;
    }
}

VL_INLINE_OPT void VCoreTop_IBusIf___nba_sequent__TOP__CoreTop__u_ifu__IMem__ibus__0(VCoreTop_IBusIf* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VCoreTop_IBusIf___nba_sequent__TOP__CoreTop__u_ifu__IMem__ibus__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.addr = vlSymsp->TOP__CoreTop__u_ifu__IMem.addr;
    if ((vlSelfRef.addr ^ vlSelfRef.__Vtogcov__addr)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 6501, vlSelfRef.addr, vlSelfRef.__Vtogcov__addr);
        vlSelfRef.__Vtogcov__addr = vlSelfRef.addr;
    }
}

VL_INLINE_OPT void VCoreTop_IBusIf___nba_sequent__TOP__CoreTop__u_ifu__IMem__ibus__2(VCoreTop_IBusIf* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VCoreTop_IBusIf___nba_sequent__TOP__CoreTop__u_ifu__IMem__ibus__2\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rdata = vlSymsp->TOP__CoreTop__u_ifu__IMem__imem.rdata_q;
    if (((IData)(vlSelfRef.ack) ^ (IData)(vlSelfRef.__Vtogcov__ack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6567, vlSelfRef.ack, vlSelfRef.__Vtogcov__ack);
        vlSelfRef.__Vtogcov__ack = vlSelfRef.ack;
    }
    if ((vlSelfRef.rdata ^ vlSelfRef.__Vtogcov__rdata)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 6571, vlSelfRef.rdata, vlSelfRef.__Vtogcov__rdata);
        vlSelfRef.__Vtogcov__rdata = vlSelfRef.rdata;
    }
}

VL_INLINE_OPT void VCoreTop_IBusIf___nba_sequent__TOP__CoreTop__u_ifu__IMem__ibus__3(VCoreTop_IBusIf* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VCoreTop_IBusIf___nba_sequent__TOP__CoreTop__u_ifu__IMem__ibus__3\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.req = vlSymsp->TOP__CoreTop__u_ifu__IMem.req;
    if (((IData)(vlSelfRef.req) ^ (IData)(vlSelfRef.__Vtogcov__req))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6499, vlSelfRef.req, vlSelfRef.__Vtogcov__req);
        vlSelfRef.__Vtogcov__req = vlSelfRef.req;
    }
}

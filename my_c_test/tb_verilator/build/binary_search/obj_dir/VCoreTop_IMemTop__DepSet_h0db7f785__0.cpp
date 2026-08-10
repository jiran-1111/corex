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
    vlSelfRef.err = vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.err;
    vlSelfRef.gnt = vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.gnt;
    vlSelfRef.rdata = vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.rdata;
    if (((IData)(vlSelfRef.req) ^ (IData)(vlSelfRef.__Vtogcov__req))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6043, vlSelfRef.req, vlSelfRef.__Vtogcov__req);
        vlSelfRef.__Vtogcov__req = vlSelfRef.req;
    }
    if ((vlSelfRef.addr ^ vlSelfRef.__Vtogcov__addr)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 6045, vlSelfRef.addr, vlSelfRef.__Vtogcov__addr);
        vlSelfRef.__Vtogcov__addr = vlSelfRef.addr;
    }
    if (((IData)(vlSelfRef.ack) ^ (IData)(vlSelfRef.__Vtogcov__ack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6111, vlSelfRef.ack, vlSelfRef.__Vtogcov__ack);
        vlSelfRef.__Vtogcov__ack = vlSelfRef.ack;
    }
    if (((IData)(vlSelfRef.clk) ^ (IData)(vlSelfRef.__Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6039, vlSelfRef.clk, vlSelfRef.__Vtogcov__clk);
        vlSelfRef.__Vtogcov__clk = vlSelfRef.clk;
    }
    if (((IData)(vlSelfRef.rst) ^ (IData)(vlSelfRef.__Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6041, vlSelfRef.rst, vlSelfRef.__Vtogcov__rst);
        vlSelfRef.__Vtogcov__rst = vlSelfRef.rst;
    }
    if (((IData)(vlSelfRef.err) ^ (IData)(vlSelfRef.__Vtogcov__err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6113, vlSelfRef.err, vlSelfRef.__Vtogcov__err);
        vlSelfRef.__Vtogcov__err = vlSelfRef.err;
    }
    if (((IData)(vlSelfRef.gnt) ^ (IData)(vlSelfRef.__Vtogcov__gnt))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6109, vlSelfRef.gnt, vlSelfRef.__Vtogcov__gnt);
        vlSelfRef.__Vtogcov__gnt = vlSelfRef.gnt;
    }
    if ((vlSelfRef.rdata ^ vlSelfRef.__Vtogcov__rdata)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 6115, vlSelfRef.rdata, vlSelfRef.__Vtogcov__rdata);
        vlSelfRef.__Vtogcov__rdata = vlSelfRef.rdata;
    }
}

VL_INLINE_OPT void VCoreTop_IMemTop___nba_sequent__TOP__CoreTop__u_ifu__IMem__0(VCoreTop_IMemTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VCoreTop_IMemTop___nba_sequent__TOP__CoreTop__u_ifu__IMem__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.addr = vlSymsp->TOP__CoreTop__u_ifu.PC_reg;
    vlSelfRef.req = vlSymsp->TOP__CoreTop__u_ifu.fetch;
    if ((vlSelfRef.addr ^ vlSelfRef.__Vtogcov__addr)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 6045, vlSelfRef.addr, vlSelfRef.__Vtogcov__addr);
        vlSelfRef.__Vtogcov__addr = vlSelfRef.addr;
    }
    if (((IData)(vlSelfRef.req) ^ (IData)(vlSelfRef.__Vtogcov__req))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6043, vlSelfRef.req, vlSelfRef.__Vtogcov__req);
        vlSelfRef.__Vtogcov__req = vlSelfRef.req;
    }
}

VL_INLINE_OPT void VCoreTop_IMemTop___nba_sequent__TOP__CoreTop__u_ifu__IMem__1(VCoreTop_IMemTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VCoreTop_IMemTop___nba_sequent__TOP__CoreTop__u_ifu__IMem__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.ack = vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.ack;
    vlSelfRef.rdata = vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.rdata;
    if (((IData)(vlSelfRef.ack) ^ (IData)(vlSelfRef.__Vtogcov__ack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6111, vlSelfRef.ack, vlSelfRef.__Vtogcov__ack);
        vlSelfRef.__Vtogcov__ack = vlSelfRef.ack;
    }
    if ((vlSelfRef.rdata ^ vlSelfRef.__Vtogcov__rdata)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 6115, vlSelfRef.rdata, vlSelfRef.__Vtogcov__rdata);
        vlSelfRef.__Vtogcov__rdata = vlSelfRef.rdata;
    }
}

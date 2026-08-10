// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_DBusIf.h"
#include "VCoreTop__Syms.h"

VL_INLINE_OPT void VCoreTop_DBusIf___ico_sequent__TOP__CoreTop__u_dmem__DOT__dbus__0(VCoreTop_DBusIf* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VCoreTop_DBusIf___ico_sequent__TOP__CoreTop__u_dmem__DOT__dbus__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (((IData)(vlSelfRef.wack) ^ (IData)(vlSelfRef.__Vtogcov__wack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6323, vlSelfRef.wack, vlSelfRef.__Vtogcov__wack);
        vlSelfRef.__Vtogcov__wack = vlSelfRef.wack;
    }
    vlSelfRef.gnt = vlSymsp->TOP__CoreTop.u_dmem__DOT__dmem__DOT__gnt;
    vlSelfRef.err = vlSymsp->TOP__CoreTop.u_dmem__DOT__dmem__DOT__err;
    vlSelfRef.write = vlSymsp->TOP__CoreTop.u_dmem__DOT__write;
    vlSelfRef.wdata = vlSymsp->TOP__CoreTop.u_dmem__DOT__wdata;
    vlSelfRef.wbe = vlSymsp->TOP__CoreTop.u_dmem__DOT__wbe;
    vlSelfRef.read = vlSymsp->TOP__CoreTop.u_dmem__DOT__read;
    vlSelfRef.addr = vlSymsp->TOP__CoreTop.u_dmem__DOT__addr;
    if (((IData)(vlSelfRef.gnt) ^ (IData)(vlSelfRef.__Vtogcov__gnt))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6319, vlSelfRef.gnt, vlSelfRef.__Vtogcov__gnt);
        vlSelfRef.__Vtogcov__gnt = vlSelfRef.gnt;
    }
    if (((IData)(vlSelfRef.err) ^ (IData)(vlSelfRef.__Vtogcov__err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6325, vlSelfRef.err, vlSelfRef.__Vtogcov__err);
        vlSelfRef.__Vtogcov__err = vlSelfRef.err;
    }
    if (((IData)(vlSelfRef.write) ^ (IData)(vlSelfRef.__Vtogcov__write))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6181, vlSelfRef.write, vlSelfRef.__Vtogcov__write);
        vlSelfRef.__Vtogcov__write = vlSelfRef.write;
    }
    if ((vlSelfRef.wdata ^ vlSelfRef.__Vtogcov__wdata)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 6247, vlSelfRef.wdata, vlSelfRef.__Vtogcov__wdata);
        vlSelfRef.__Vtogcov__wdata = vlSelfRef.wdata;
    }
    if (((IData)(vlSelfRef.wbe) ^ (IData)(vlSelfRef.__Vtogcov__wbe))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSymsp->__Vcoverage + 6311, vlSelfRef.wbe, vlSelfRef.__Vtogcov__wbe);
        vlSelfRef.__Vtogcov__wbe = vlSelfRef.wbe;
    }
    if (((IData)(vlSelfRef.read) ^ (IData)(vlSelfRef.__Vtogcov__read))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6179, vlSelfRef.read, vlSelfRef.__Vtogcov__read);
        vlSelfRef.__Vtogcov__read = vlSelfRef.read;
    }
    vlSelfRef.rack = ((~ (IData)(vlSymsp->TOP__CoreTop.u_dmem__DOT__dmem__DOT__rst)) 
                      & ((IData)(vlSymsp->TOP__CoreTop.u_dmem__DOT__dmem__DOT__gnt) 
                         & (IData)(vlSelfRef.read)));
    if ((vlSelfRef.addr ^ vlSelfRef.__Vtogcov__addr)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 6183, vlSelfRef.addr, vlSelfRef.__Vtogcov__addr);
        vlSelfRef.__Vtogcov__addr = vlSelfRef.addr;
    }
    if (((IData)(vlSelfRef.rack) ^ (IData)(vlSelfRef.__Vtogcov__rack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6321, vlSelfRef.rack, vlSelfRef.__Vtogcov__rack);
        vlSelfRef.__Vtogcov__rack = vlSelfRef.rack;
    }
}

VL_INLINE_OPT void VCoreTop_DBusIf___ico_sequent__TOP__CoreTop__u_dmem__DOT__dbus__1(VCoreTop_DBusIf* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VCoreTop_DBusIf___ico_sequent__TOP__CoreTop__u_dmem__DOT__dbus__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rdata = vlSymsp->TOP__CoreTop.u_dmem__DOT__dmem__DOT__mem
        [vlSymsp->TOP__CoreTop.u_dmem__DOT__dmem__DOT__mem_addr];
    if ((vlSelfRef.rdata ^ vlSelfRef.__Vtogcov__rdata)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 6327, vlSelfRef.rdata, vlSelfRef.__Vtogcov__rdata);
        vlSelfRef.__Vtogcov__rdata = vlSelfRef.rdata;
    }
}

VL_INLINE_OPT void VCoreTop_DBusIf___nba_sequent__TOP__CoreTop__u_dmem__DOT__dbus__1(VCoreTop_DBusIf* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VCoreTop_DBusIf___nba_sequent__TOP__CoreTop__u_dmem__DOT__dbus__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (((IData)(vlSelfRef.wack) ^ (IData)(vlSelfRef.__Vtogcov__wack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6323, vlSelfRef.wack, vlSelfRef.__Vtogcov__wack);
        vlSelfRef.__Vtogcov__wack = vlSelfRef.wack;
    }
}

VL_INLINE_OPT void VCoreTop_DBusIf___nba_sequent__TOP__CoreTop__u_dmem__DOT__dbus__2(VCoreTop_DBusIf* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VCoreTop_DBusIf___nba_sequent__TOP__CoreTop__u_dmem__DOT__dbus__2\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.write = vlSymsp->TOP__CoreTop.u_dmem__DOT__write;
    vlSelfRef.wdata = vlSymsp->TOP__CoreTop.u_dmem__DOT__wdata;
    vlSelfRef.wbe = vlSymsp->TOP__CoreTop.u_dmem__DOT__wbe;
    vlSelfRef.read = vlSymsp->TOP__CoreTop.u_dmem__DOT__read;
    vlSelfRef.addr = vlSymsp->TOP__CoreTop.u_dmem__DOT__addr;
    if (((IData)(vlSelfRef.write) ^ (IData)(vlSelfRef.__Vtogcov__write))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6181, vlSelfRef.write, vlSelfRef.__Vtogcov__write);
        vlSelfRef.__Vtogcov__write = vlSelfRef.write;
    }
    if ((vlSelfRef.wdata ^ vlSelfRef.__Vtogcov__wdata)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 6247, vlSelfRef.wdata, vlSelfRef.__Vtogcov__wdata);
        vlSelfRef.__Vtogcov__wdata = vlSelfRef.wdata;
    }
    if (((IData)(vlSelfRef.wbe) ^ (IData)(vlSelfRef.__Vtogcov__wbe))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSymsp->__Vcoverage + 6311, vlSelfRef.wbe, vlSelfRef.__Vtogcov__wbe);
        vlSelfRef.__Vtogcov__wbe = vlSelfRef.wbe;
    }
    if (((IData)(vlSelfRef.read) ^ (IData)(vlSelfRef.__Vtogcov__read))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6179, vlSelfRef.read, vlSelfRef.__Vtogcov__read);
        vlSelfRef.__Vtogcov__read = vlSelfRef.read;
    }
    vlSelfRef.rack = ((~ (IData)(vlSymsp->TOP__CoreTop.u_dmem__DOT__dmem__DOT__rst)) 
                      & ((IData)(vlSymsp->TOP__CoreTop.u_dmem__DOT__dmem__DOT__gnt) 
                         & (IData)(vlSelfRef.read)));
    if ((vlSelfRef.addr ^ vlSelfRef.__Vtogcov__addr)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 6183, vlSelfRef.addr, vlSelfRef.__Vtogcov__addr);
        vlSelfRef.__Vtogcov__addr = vlSelfRef.addr;
    }
    if (((IData)(vlSelfRef.rack) ^ (IData)(vlSelfRef.__Vtogcov__rack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6321, vlSelfRef.rack, vlSelfRef.__Vtogcov__rack);
        vlSelfRef.__Vtogcov__rack = vlSelfRef.rack;
    }
}

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
    vlSelfRef.gnt = vlSymsp->TOP__CoreTop.u_dmem__DOT__dmem__DOT__gnt;
    vlSelfRef.err = vlSymsp->TOP__CoreTop.u_dmem__DOT__dmem__DOT__err;
    vlSelfRef.write = vlSymsp->TOP__CoreTop.u_dmem__DOT__write;
    vlSelfRef.wdata = vlSymsp->TOP__CoreTop.u_dmem__DOT__wdata;
    vlSelfRef.wbe = vlSymsp->TOP__CoreTop.u_dmem__DOT__wbe;
    vlSelfRef.read = vlSymsp->TOP__CoreTop.u_dmem__DOT__read;
    vlSelfRef.addr = vlSymsp->TOP__CoreTop.u_dmem__DOT__addr;
    vlSelfRef.rack = ((~ (IData)(vlSymsp->TOP__CoreTop.u_dmem__DOT__dmem__DOT__rst)) 
                      & ((IData)(vlSymsp->TOP__CoreTop.u_dmem__DOT__dmem__DOT__gnt) 
                         & (IData)(vlSelfRef.read)));
}

VL_INLINE_OPT void VCoreTop_DBusIf___ico_sequent__TOP__CoreTop__u_dmem__DOT__dbus__1(VCoreTop_DBusIf* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VCoreTop_DBusIf___ico_sequent__TOP__CoreTop__u_dmem__DOT__dbus__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.rdata = vlSymsp->TOP__CoreTop.u_dmem__DOT__dmem__DOT__mem
        [vlSymsp->TOP__CoreTop.u_dmem__DOT__dmem__DOT__mem_addr];
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
    vlSelfRef.rack = ((~ (IData)(vlSymsp->TOP__CoreTop.u_dmem__DOT__dmem__DOT__rst)) 
                      & ((IData)(vlSymsp->TOP__CoreTop.u_dmem__DOT__dmem__DOT__gnt) 
                         & (IData)(vlSelfRef.read)));
}

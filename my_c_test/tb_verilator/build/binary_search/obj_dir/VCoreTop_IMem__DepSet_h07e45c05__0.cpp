// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_IMem.h"
#include "VCoreTop__Syms.h"

VL_INLINE_OPT void VCoreTop_IMem___ico_sequent__TOP__CoreTop__u_ifu__IMem__imem__0(VCoreTop_IMem* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VCoreTop_IMem___ico_sequent__TOP__CoreTop__u_ifu__IMem__imem__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.clk = vlSymsp->TOP__CoreTop__u_ifu__IMem.clk;
    vlSelfRef.rst = vlSymsp->TOP__CoreTop__u_ifu__IMem.rst;
    vlSelfRef.mem_addr = (0xfffU & (vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.addr 
                                    >> 2U));
}

VL_INLINE_OPT void VCoreTop_IMem___nba_sequent__TOP__CoreTop__u_ifu__IMem__imem__0(VCoreTop_IMem* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VCoreTop_IMem___nba_sequent__TOP__CoreTop__u_ifu__IMem__imem__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.ack = 
        ((1U & (~ (IData)(vlSelfRef.rst))) && ((IData)(vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.req) 
                                               & (IData)(vlSelfRef.gnt)));
    if (((IData)(vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.req) 
         & (IData)(vlSelfRef.gnt))) {
        vlSelfRef.rdata_q = vlSelfRef.mem[vlSelfRef.mem_addr];
    }
}

VL_INLINE_OPT void VCoreTop_IMem___nba_sequent__TOP__CoreTop__u_ifu__IMem__imem__1(VCoreTop_IMem* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VCoreTop_IMem___nba_sequent__TOP__CoreTop__u_ifu__IMem__imem__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mem_addr = (0xfffU & (vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.addr 
                                    >> 2U));
}

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
    if (((IData)(vlSelfRef.gnt) ^ (IData)(vlSelfRef.__Vtogcov__gnt))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6395, vlSelfRef.gnt, vlSelfRef.__Vtogcov__gnt);
        vlSelfRef.__Vtogcov__gnt = vlSelfRef.gnt;
    }
    if (((IData)(vlSelfRef.err) ^ (IData)(vlSelfRef.__Vtogcov__err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6397, vlSelfRef.err, vlSelfRef.__Vtogcov__err);
        vlSelfRef.__Vtogcov__err = vlSelfRef.err;
    }
    if ((vlSelfRef.rdata_q ^ vlSelfRef.__Vtogcov__rdata_q)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 6423, vlSelfRef.rdata_q, vlSelfRef.__Vtogcov__rdata_q);
        vlSelfRef.__Vtogcov__rdata_q = vlSelfRef.rdata_q;
    }
}

VL_INLINE_OPT void VCoreTop_IMem___ico_sequent__TOP__CoreTop__u_ifu__IMem__imem__1(VCoreTop_IMem* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VCoreTop_IMem___ico_sequent__TOP__CoreTop__u_ifu__IMem__imem__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.clk = vlSymsp->TOP__CoreTop__u_ifu__IMem.clk;
    vlSelfRef.rst = vlSymsp->TOP__CoreTop__u_ifu__IMem.rst;
    vlSelfRef.mem_addr = (0xfffU & (vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.addr 
                                    >> 2U));
    if (((IData)(vlSelfRef.clk) ^ (IData)(vlSelfRef.__Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6391, vlSelfRef.clk, vlSelfRef.__Vtogcov__clk);
        vlSelfRef.__Vtogcov__clk = vlSelfRef.clk;
    }
    if (((IData)(vlSelfRef.rst) ^ (IData)(vlSelfRef.__Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 6393, vlSelfRef.rst, vlSelfRef.__Vtogcov__rst);
        vlSelfRef.__Vtogcov__rst = vlSelfRef.rst;
    }
    if (((IData)(vlSelfRef.mem_addr) ^ (IData)(vlSelfRef.__Vtogcov__mem_addr))) {
        VL_COV_TOGGLE_CHG_ST_I(12, vlSymsp->__Vcoverage + 6399, vlSelfRef.mem_addr, vlSelfRef.__Vtogcov__mem_addr);
        vlSelfRef.__Vtogcov__mem_addr = vlSelfRef.mem_addr;
    }
}

VL_INLINE_OPT void VCoreTop_IMem___nba_sequent__TOP__CoreTop__u_ifu__IMem__imem__0(VCoreTop_IMem* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VCoreTop_IMem___nba_sequent__TOP__CoreTop__u_ifu__IMem__imem__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.rst) {
        ++(vlSymsp->__Vcoverage[6496]);
        vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.ack = 0U;
    } else {
        if (((IData)(vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.req) 
             & (IData)(vlSelfRef.gnt))) {
            ++(vlSymsp->__Vcoverage[6493]);
        }
        vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.ack 
            = ((IData)(vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.req) 
               & (IData)(vlSelfRef.gnt));
        if ((1U & (~ (IData)(vlSelfRef.gnt)))) {
            ++(vlSymsp->__Vcoverage[6494]);
        }
        if ((1U & (~ (IData)(vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.req)))) {
            ++(vlSymsp->__Vcoverage[6495]);
        }
        ++(vlSymsp->__Vcoverage[6497]);
    }
    ++(vlSymsp->__Vcoverage[6498]);
    if (((IData)(vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.req) 
         & (IData)(vlSelfRef.gnt))) {
        ++(vlSymsp->__Vcoverage[6487]);
        vlSelfRef.rdata_q = vlSelfRef.mem[vlSelfRef.mem_addr];
    } else {
        ++(vlSymsp->__Vcoverage[6488]);
    }
    if (((IData)(vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.req) 
         & (IData)(vlSelfRef.gnt))) {
        ++(vlSymsp->__Vcoverage[6489]);
    }
    if ((1U & (~ (IData)(vlSelfRef.gnt)))) {
        ++(vlSymsp->__Vcoverage[6490]);
    }
    if ((1U & (~ (IData)(vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.req)))) {
        ++(vlSymsp->__Vcoverage[6491]);
    }
    ++(vlSymsp->__Vcoverage[6492]);
    if ((vlSelfRef.rdata_q ^ vlSelfRef.__Vtogcov__rdata_q)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 6423, vlSelfRef.rdata_q, vlSelfRef.__Vtogcov__rdata_q);
        vlSelfRef.__Vtogcov__rdata_q = vlSelfRef.rdata_q;
    }
}

VL_INLINE_OPT void VCoreTop_IMem___nba_sequent__TOP__CoreTop__u_ifu__IMem__imem__1(VCoreTop_IMem* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VCoreTop_IMem___nba_sequent__TOP__CoreTop__u_ifu__IMem__imem__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.mem_addr = (0xfffU & (vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus.addr 
                                    >> 2U));
    if (((IData)(vlSelfRef.mem_addr) ^ (IData)(vlSelfRef.__Vtogcov__mem_addr))) {
        VL_COV_TOGGLE_CHG_ST_I(12, vlSymsp->__Vcoverage + 6399, vlSelfRef.mem_addr, vlSelfRef.__Vtogcov__mem_addr);
        vlSelfRef.__Vtogcov__mem_addr = vlSelfRef.mem_addr;
    }
}

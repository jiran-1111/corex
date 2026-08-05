// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_CoreTop.h"

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__1(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VdlySet__u_dmem__DOT__dmem__DOT__mem__v0 = 0U;
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__11(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__11\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.cycle_cnt = vlSelfRef.__Vdly__cycle_cnt;
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__12(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__12\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_if_id_reg__DOT__ctrl_in = vlSelfRef.if_valid;
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__2(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_comb__TOP__CoreTop__2\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_decoder__DOT__rs1_data_bypass = (((IData)(vlSelfRef.u_decoder__DOT__rs1) 
                                                  == (IData)(vlSelfRef.u_decoder__DOT__write_reg)) 
                                                 & ((0U 
                                                     != (IData)(vlSelfRef.u_decoder__DOT__write_reg)) 
                                                    & ((IData)(vlSelfRef.u_decoder__DOT__reg_write) 
                                                       & (0U 
                                                          != (IData)(vlSelfRef.u_decoder__DOT__rs1)))));
    vlSelfRef.u_decoder__DOT__rs2_data_bypass = (((IData)(vlSelfRef.u_decoder__DOT__rs2) 
                                                  == (IData)(vlSelfRef.u_decoder__DOT__write_reg)) 
                                                 & ((IData)(vlSelfRef.u_decoder__DOT__reg_write) 
                                                    & (0U 
                                                       != (IData)(vlSelfRef.u_decoder__DOT__rs2))));
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__4(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_comb__TOP__CoreTop__4\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_if_id_reg__DOT__data_in = (((QData)((IData)(vlSelfRef.if_pc)) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.if_instruction)));
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__6(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_comb__TOP__CoreTop__6\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.real_if_id_flush = ((IData)(vlSelfRef.flush) 
                                  | (IData)(vlSelfRef.flush_d));
    vlSelfRef.u_if_id_reg__DOT__flush = vlSelfRef.real_if_id_flush;
}

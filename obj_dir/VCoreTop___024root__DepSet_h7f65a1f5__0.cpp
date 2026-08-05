// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop__Syms.h"
#include "VCoreTop___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VCoreTop___024root___dump_triggers__ico(VCoreTop___024root* vlSelf);
#endif  // VL_DEBUG

void VCoreTop___024root___eval_triggers__ico(VCoreTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreTop___024root___eval_triggers__ico\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VCoreTop___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

void VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__0(VCoreTop_CoreTop* vlSelf);
void VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__0(VCoreTop_Ifu* vlSelf);
void VCoreTop_IMemTop___ico_sequent__TOP__CoreTop__u_ifu__IMem__0(VCoreTop_IMemTop* vlSelf);
void VCoreTop_DBusIf___ico_sequent__TOP__CoreTop__u_dmem__DOT__dbus__0(VCoreTop_DBusIf* vlSelf);
void VCoreTop_IBusIf___ico_sequent__TOP__CoreTop__u_ifu__IMem__ibus__0(VCoreTop_IBusIf* vlSelf);
void VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__1(VCoreTop_CoreTop* vlSelf);
void VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__1(VCoreTop_Ifu* vlSelf);
void VCoreTop_IMem___ico_sequent__TOP__CoreTop__u_ifu__IMem__imem__0(VCoreTop_IMem* vlSelf);
void VCoreTop_IMemTop___ico_sequent__TOP__CoreTop__u_ifu__IMem__1(VCoreTop_IMemTop* vlSelf);
void VCoreTop_DBusIf___ico_sequent__TOP__CoreTop__u_dmem__DOT__dbus__1(VCoreTop_DBusIf* vlSelf);
void VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__2(VCoreTop_CoreTop* vlSelf);
void VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__2(VCoreTop_Ifu* vlSelf);
void VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__3(VCoreTop_CoreTop* vlSelf);

void VCoreTop___024root___eval_ico(VCoreTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreTop___024root___eval_ico\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__0((&vlSymsp->TOP__CoreTop));
        VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__0((&vlSymsp->TOP__CoreTop__u_ifu));
        VCoreTop_IMemTop___ico_sequent__TOP__CoreTop__u_ifu__IMem__0((&vlSymsp->TOP__CoreTop__u_ifu__IMem));
        VCoreTop_DBusIf___ico_sequent__TOP__CoreTop__u_dmem__DOT__dbus__0((&vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus));
        VCoreTop_IBusIf___ico_sequent__TOP__CoreTop__u_ifu__IMem__ibus__0((&vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus));
        VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__1((&vlSymsp->TOP__CoreTop));
        VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__1((&vlSymsp->TOP__CoreTop__u_ifu));
        VCoreTop_IMem___ico_sequent__TOP__CoreTop__u_ifu__IMem__imem__0((&vlSymsp->TOP__CoreTop__u_ifu__IMem__imem));
        VCoreTop_IMemTop___ico_sequent__TOP__CoreTop__u_ifu__IMem__1((&vlSymsp->TOP__CoreTop__u_ifu__IMem));
        VCoreTop_DBusIf___ico_sequent__TOP__CoreTop__u_dmem__DOT__dbus__1((&vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus));
        VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__2((&vlSymsp->TOP__CoreTop));
        VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__2((&vlSymsp->TOP__CoreTop__u_ifu));
        VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__3((&vlSymsp->TOP__CoreTop));
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCoreTop___024root___dump_triggers__act(VCoreTop___024root* vlSelf);
#endif  // VL_DEBUG

void VCoreTop___024root___eval_triggers__act(VCoreTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreTop___024root___eval_triggers__act\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSymsp->TOP__CoreTop.clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__CoreTop__clk__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((IData)(vlSymsp->TOP__CoreTop.rst) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__CoreTop__rst__0))));
    vlSelfRef.__VactTriggered.setBit(2U, ((IData)(vlSymsp->TOP__CoreTop.u_if_id_reg__DOT__clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__CoreTop__u_if_id_reg__DOT__clk__0))));
    vlSelfRef.__VactTriggered.setBit(3U, ((IData)(vlSymsp->TOP__CoreTop.u_decoder__DOT__u_regfile__DOT__clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__CoreTop__u_decoder__DOT__u_regfile__DOT__clk__0))));
    vlSelfRef.__VactTriggered.setBit(4U, ((IData)(vlSymsp->TOP__CoreTop.u_ex_mem_reg__DOT__clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__CoreTop__u_ex_mem_reg__DOT__clk__0))));
    vlSelfRef.__VactTriggered.setBit(5U, ((IData)(vlSymsp->TOP__CoreTop.u_dmem__DOT__dmem__DOT__clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__CoreTop__u_dmem__DOT__dmem__DOT__clk__0))));
    vlSelfRef.__VactTriggered.setBit(6U, ((IData)(vlSymsp->TOP__CoreTop__u_ifu.clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__CoreTop__u_ifu__clk__0))));
    vlSelfRef.__VactTriggered.setBit(7U, ((IData)(vlSymsp->TOP__CoreTop__u_ifu__IMem__imem.clk) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__CoreTop__u_ifu__IMem__imem__clk__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__CoreTop__clk__0 
        = vlSymsp->TOP__CoreTop.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__CoreTop__rst__0 
        = vlSymsp->TOP__CoreTop.rst;
    vlSelfRef.__Vtrigprevexpr___TOP__CoreTop__u_if_id_reg__DOT__clk__0 
        = vlSymsp->TOP__CoreTop.u_if_id_reg__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__CoreTop__u_decoder__DOT__u_regfile__DOT__clk__0 
        = vlSymsp->TOP__CoreTop.u_decoder__DOT__u_regfile__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__CoreTop__u_ex_mem_reg__DOT__clk__0 
        = vlSymsp->TOP__CoreTop.u_ex_mem_reg__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__CoreTop__u_dmem__DOT__dmem__DOT__clk__0 
        = vlSymsp->TOP__CoreTop.u_dmem__DOT__dmem__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__CoreTop__u_ifu__clk__0 
        = vlSymsp->TOP__CoreTop__u_ifu.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__CoreTop__u_ifu__IMem__imem__clk__0 
        = vlSymsp->TOP__CoreTop__u_ifu__IMem__imem.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VCoreTop___024root___dump_triggers__act(vlSelf);
    }
#endif
}

void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__0(VCoreTop_CoreTop* vlSelf);
void VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__0(VCoreTop_Ifu* vlSelf);
void VCoreTop_IMemTop___nba_sequent__TOP__CoreTop__u_ifu__IMem__0(VCoreTop_IMemTop* vlSelf);
void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__1(VCoreTop_CoreTop* vlSelf);
void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__2(VCoreTop_CoreTop* vlSelf);
void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__3(VCoreTop_CoreTop* vlSelf);
void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__4(VCoreTop_CoreTop* vlSelf);
void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__5(VCoreTop_CoreTop* vlSelf);
void VCoreTop_IMem___nba_sequent__TOP__CoreTop__u_ifu__IMem__imem__0(VCoreTop_IMem* vlSelf);
void VCoreTop_IBusIf___nba_sequent__TOP__CoreTop__u_ifu__IMem__ibus__1(VCoreTop_IBusIf* vlSelf);
void VCoreTop_IMemTop___nba_sequent__TOP__CoreTop__u_ifu__IMem__1(VCoreTop_IMemTop* vlSelf);
void VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__1(VCoreTop_Ifu* vlSelf);
void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__6(VCoreTop_CoreTop* vlSelf);
void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__7(VCoreTop_CoreTop* vlSelf);
void VCoreTop_DBusIf___nba_sequent__TOP__CoreTop__u_dmem__DOT__dbus__2(VCoreTop_DBusIf* vlSelf);
void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__8(VCoreTop_CoreTop* vlSelf);
void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__9(VCoreTop_CoreTop* vlSelf);
void VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__2(VCoreTop_Ifu* vlSelf);
void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__10(VCoreTop_CoreTop* vlSelf);
void VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__3(VCoreTop_Ifu* vlSelf);
void VCoreTop_IBusIf___nba_sequent__TOP__CoreTop__u_ifu__IMem__ibus__2(VCoreTop_IBusIf* vlSelf);
void VCoreTop_IMemTop___nba_sequent__TOP__CoreTop__u_ifu__IMem__2(VCoreTop_IMemTop* vlSelf);
void VCoreTop_IBusIf___nba_sequent__TOP__CoreTop__u_ifu__IMem__ibus__3(VCoreTop_IBusIf* vlSelf);
void VCoreTop_IMem___nba_sequent__TOP__CoreTop__u_ifu__IMem__imem__1(VCoreTop_IMem* vlSelf);
void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__11(VCoreTop_CoreTop* vlSelf);
void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__0(VCoreTop_CoreTop* vlSelf);
void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__1(VCoreTop_CoreTop* vlSelf);
void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__12(VCoreTop_CoreTop* vlSelf);
void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__2(VCoreTop_CoreTop* vlSelf);
void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__3(VCoreTop_CoreTop* vlSelf);
void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__4(VCoreTop_CoreTop* vlSelf);
void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__5(VCoreTop_CoreTop* vlSelf);
void VCoreTop_Ifu___nba_comb__TOP__CoreTop__u_ifu__0(VCoreTop_Ifu* vlSelf);
void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__6(VCoreTop_CoreTop* vlSelf);
void VCoreTop_Ifu___nba_comb__TOP__CoreTop__u_ifu__1(VCoreTop_Ifu* vlSelf);

void VCoreTop___024root___eval_nba(VCoreTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreTop___024root___eval_nba\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__0((&vlSymsp->TOP__CoreTop));
    }
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__0((&vlSymsp->TOP__CoreTop__u_ifu));
        VCoreTop_IMemTop___nba_sequent__TOP__CoreTop__u_ifu__IMem__0((&vlSymsp->TOP__CoreTop__u_ifu__IMem));
    }
    if ((0x20ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__1((&vlSymsp->TOP__CoreTop));
        VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__2((&vlSymsp->TOP__CoreTop));
        VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__3((&vlSymsp->TOP__CoreTop));
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__4((&vlSymsp->TOP__CoreTop));
    }
    if ((8ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__5((&vlSymsp->TOP__CoreTop));
    }
    if ((0x80ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCoreTop_IMem___nba_sequent__TOP__CoreTop__u_ifu__IMem__imem__0((&vlSymsp->TOP__CoreTop__u_ifu__IMem__imem));
        VCoreTop_IBusIf___nba_sequent__TOP__CoreTop__u_ifu__IMem__ibus__1((&vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus));
        VCoreTop_IMemTop___nba_sequent__TOP__CoreTop__u_ifu__IMem__1((&vlSymsp->TOP__CoreTop__u_ifu__IMem));
        VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__1((&vlSymsp->TOP__CoreTop__u_ifu));
        VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__6((&vlSymsp->TOP__CoreTop));
    }
    if ((0x10ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__7((&vlSymsp->TOP__CoreTop));
        VCoreTop_DBusIf___nba_sequent__TOP__CoreTop__u_dmem__DOT__dbus__2((&vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus));
        VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__8((&vlSymsp->TOP__CoreTop));
    }
    if ((4ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__9((&vlSymsp->TOP__CoreTop));
        VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__2((&vlSymsp->TOP__CoreTop__u_ifu));
    }
    if ((0x40ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__10((&vlSymsp->TOP__CoreTop));
        VCoreTop_Ifu___nba_sequent__TOP__CoreTop__u_ifu__3((&vlSymsp->TOP__CoreTop__u_ifu));
        VCoreTop_IBusIf___nba_sequent__TOP__CoreTop__u_ifu__IMem__ibus__2((&vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus));
        VCoreTop_IMemTop___nba_sequent__TOP__CoreTop__u_ifu__IMem__2((&vlSymsp->TOP__CoreTop__u_ifu__IMem));
        VCoreTop_IBusIf___nba_sequent__TOP__CoreTop__u_ifu__IMem__ibus__3((&vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus));
        VCoreTop_IMem___nba_sequent__TOP__CoreTop__u_ifu__IMem__imem__1((&vlSymsp->TOP__CoreTop__u_ifu__IMem__imem));
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__11((&vlSymsp->TOP__CoreTop));
    }
    if ((0x30ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCoreTop_CoreTop___nba_comb__TOP__CoreTop__0((&vlSymsp->TOP__CoreTop));
        VCoreTop_DBusIf___ico_sequent__TOP__CoreTop__u_dmem__DOT__dbus__1((&vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus));
        VCoreTop_CoreTop___nba_comb__TOP__CoreTop__1((&vlSymsp->TOP__CoreTop));
    }
    if ((0x80ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__12((&vlSymsp->TOP__CoreTop));
    }
    if ((0x14ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCoreTop_CoreTop___nba_comb__TOP__CoreTop__2((&vlSymsp->TOP__CoreTop));
    }
    if ((0xcULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCoreTop_CoreTop___nba_comb__TOP__CoreTop__3((&vlSymsp->TOP__CoreTop));
    }
    if ((0xc0ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCoreTop_CoreTop___nba_comb__TOP__CoreTop__4((&vlSymsp->TOP__CoreTop));
    }
    if ((0x3cULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCoreTop_CoreTop___nba_comb__TOP__CoreTop__5((&vlSymsp->TOP__CoreTop));
        VCoreTop_Ifu___nba_comb__TOP__CoreTop__u_ifu__0((&vlSymsp->TOP__CoreTop__u_ifu));
    }
    if ((0x3fULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCoreTop_CoreTop___nba_comb__TOP__CoreTop__6((&vlSymsp->TOP__CoreTop));
    }
    if ((0x7cULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VCoreTop_Ifu___nba_comb__TOP__CoreTop__u_ifu__1((&vlSymsp->TOP__CoreTop__u_ifu));
    }
}

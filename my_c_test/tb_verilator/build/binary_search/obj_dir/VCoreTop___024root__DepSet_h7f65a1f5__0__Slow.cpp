// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop__Syms.h"
#include "VCoreTop___024root.h"

VL_ATTR_COLD void VCoreTop___024root___eval_static(VCoreTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreTop___024root___eval_static\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
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
}

VL_ATTR_COLD void VCoreTop_CoreTop___eval_initial__TOP__CoreTop(VCoreTop_CoreTop* vlSelf);
VL_ATTR_COLD void VCoreTop_IMem___eval_initial__TOP__CoreTop__u_ifu__IMem__imem(VCoreTop_IMem* vlSelf);

VL_ATTR_COLD void VCoreTop___024root___eval_initial(VCoreTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreTop___024root___eval_initial\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VCoreTop_CoreTop___eval_initial__TOP__CoreTop((&vlSymsp->TOP__CoreTop));
    VCoreTop_IMem___eval_initial__TOP__CoreTop__u_ifu__IMem__imem((&vlSymsp->TOP__CoreTop__u_ifu__IMem__imem));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VCoreTop___024root___dump_triggers__stl(VCoreTop___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VCoreTop___024root___eval_triggers__stl(VCoreTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreTop___024root___eval_triggers__stl\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.setBit(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VCoreTop___024root___dump_triggers__stl(vlSelf);
    }
#endif
}

VL_ATTR_COLD void VCoreTop_CoreTop___stl_sequent__TOP__CoreTop__0(VCoreTop_CoreTop* vlSelf);
void VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__0(VCoreTop_Ifu* vlSelf);
void VCoreTop_DBusIf___ico_sequent__TOP__CoreTop__u_dmem__DOT__dbus__0(VCoreTop_DBusIf* vlSelf);
void VCoreTop_IMem___ico_sequent__TOP__CoreTop__u_ifu__IMem__imem__0(VCoreTop_IMem* vlSelf);
void VCoreTop_IBusIf___ico_sequent__TOP__CoreTop__u_ifu__IMem__ibus__0(VCoreTop_IBusIf* vlSelf);
void VCoreTop_IMemTop___ico_sequent__TOP__CoreTop__u_ifu__IMem__0(VCoreTop_IMemTop* vlSelf);
void VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__1(VCoreTop_CoreTop* vlSelf);
void VCoreTop_IBusIf___ico_sequent__TOP__CoreTop__u_ifu__IMem__ibus__1(VCoreTop_IBusIf* vlSelf);
void VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__1(VCoreTop_Ifu* vlSelf);
void VCoreTop_IMem___ico_sequent__TOP__CoreTop__u_ifu__IMem__imem__1(VCoreTop_IMem* vlSelf);
void VCoreTop_DBusIf___ico_sequent__TOP__CoreTop__u_dmem__DOT__dbus__1(VCoreTop_DBusIf* vlSelf);
void VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__2(VCoreTop_CoreTop* vlSelf);
void VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__2(VCoreTop_Ifu* vlSelf);

VL_ATTR_COLD void VCoreTop___024root___eval_stl(VCoreTop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VCoreTop___024root___eval_stl\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VCoreTop_CoreTop___stl_sequent__TOP__CoreTop__0((&vlSymsp->TOP__CoreTop));
        VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__0((&vlSymsp->TOP__CoreTop__u_ifu));
        VCoreTop_DBusIf___ico_sequent__TOP__CoreTop__u_dmem__DOT__dbus__0((&vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus));
        VCoreTop_IMem___ico_sequent__TOP__CoreTop__u_ifu__IMem__imem__0((&vlSymsp->TOP__CoreTop__u_ifu__IMem__imem));
        VCoreTop_IBusIf___ico_sequent__TOP__CoreTop__u_ifu__IMem__ibus__0((&vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus));
        VCoreTop_IMemTop___ico_sequent__TOP__CoreTop__u_ifu__IMem__0((&vlSymsp->TOP__CoreTop__u_ifu__IMem));
        VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__1((&vlSymsp->TOP__CoreTop));
        VCoreTop_IBusIf___ico_sequent__TOP__CoreTop__u_ifu__IMem__ibus__1((&vlSymsp->TOP__CoreTop__u_ifu__IMem__ibus));
        VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__1((&vlSymsp->TOP__CoreTop__u_ifu));
        VCoreTop_IMem___ico_sequent__TOP__CoreTop__u_ifu__IMem__imem__1((&vlSymsp->TOP__CoreTop__u_ifu__IMem__imem));
        VCoreTop_DBusIf___ico_sequent__TOP__CoreTop__u_dmem__DOT__dbus__1((&vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus));
        VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__2((&vlSymsp->TOP__CoreTop));
        VCoreTop_Ifu___ico_sequent__TOP__CoreTop__u_ifu__2((&vlSymsp->TOP__CoreTop__u_ifu));
    }
}

// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_CoreTop.h"
#include "VCoreTop__Syms.h"

VL_INLINE_OPT void VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__0(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<3>/*95:0*/ __Vtemp_2;
    // Body
    if (((IData)(vlSelfRef.stall) ^ (IData)(vlSelfRef.__Vtogcov__stall))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 70, vlSelfRef.stall, vlSelfRef.__Vtogcov__stall);
        vlSelfRef.__Vtogcov__stall = vlSelfRef.stall;
    }
    if (((IData)(vlSelfRef.flush_d) ^ (IData)(vlSelfRef.__Vtogcov__flush_d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1410, vlSelfRef.flush_d, vlSelfRef.__Vtogcov__flush_d);
        vlSelfRef.__Vtogcov__flush_d = vlSelfRef.flush_d;
    }
    if (((IData)(vlSelfRef.u_if_id_reg__DOT__ctrl_q) 
         ^ (IData)(vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1697, vlSelfRef.u_if_id_reg__DOT__ctrl_q, vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_q);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_q 
            = vlSelfRef.u_if_id_reg__DOT__ctrl_q;
    }
    if ((vlSelfRef.u_if_id_reg__DOT__data_q ^ vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_q)) {
        VL_COV_TOGGLE_CHG_ST_Q(64, vlSymsp->__Vcoverage + 1699, vlSelfRef.u_if_id_reg__DOT__data_q, vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_q);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_q 
            = vlSelfRef.u_if_id_reg__DOT__data_q;
    }
    if ((vlSelfRef.u_decoder__DOT__uj_imm ^ vlSelfRef.u_decoder__DOT____Vtogcov__uj_imm)) {
        VL_COV_TOGGLE_CHG_ST_I(20, vlSymsp->__Vcoverage + 2934, vlSelfRef.u_decoder__DOT__uj_imm, vlSelfRef.u_decoder__DOT____Vtogcov__uj_imm);
        vlSelfRef.u_decoder__DOT____Vtogcov__uj_imm 
            = vlSelfRef.u_decoder__DOT__uj_imm;
    }
    if (((IData)(vlSelfRef.u_ex_mem_reg__DOT__flush) 
         ^ (IData)(vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__flush))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4524, vlSelfRef.u_ex_mem_reg__DOT__flush, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__flush);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__flush 
            = vlSelfRef.u_ex_mem_reg__DOT__flush;
    }
    if (((IData)(vlSelfRef.u_ex_mem_reg__DOT__ctrl_q) 
         ^ (IData)(vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4840, vlSelfRef.u_ex_mem_reg__DOT__ctrl_q, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_q);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_q 
            = vlSelfRef.u_ex_mem_reg__DOT__ctrl_q;
    }
    __Vtemp_1[0U] = (vlSelfRef.u_ex_mem_reg__DOT__data_q[0U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q[0U]);
    __Vtemp_1[1U] = (vlSelfRef.u_ex_mem_reg__DOT__data_q[1U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q[1U]);
    __Vtemp_1[2U] = (vlSelfRef.u_ex_mem_reg__DOT__data_q[2U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q[2U]);
    if (__Vtemp_1) {
        VL_COV_TOGGLE_CHG_ST_W(77, vlSymsp->__Vcoverage + 4842, vlSelfRef.u_ex_mem_reg__DOT__data_q, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q[0U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_q[0U];
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q[1U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_q[1U];
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q[2U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_q[2U];
    }
    if (((IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__gnt) 
         ^ (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__gnt))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5229, vlSelfRef.u_dmem__DOT__dmem__DOT__gnt, vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__gnt);
        vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__gnt 
            = vlSelfRef.u_dmem__DOT__dmem__DOT__gnt;
    }
    if (((IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__err) 
         ^ (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5231, vlSelfRef.u_dmem__DOT__dmem__DOT__err, vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__err);
        vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__err 
            = vlSelfRef.u_dmem__DOT__dmem__DOT__err;
    }
    vlSelfRef.u_execute__DOT__stall = vlSelfRef.stall;
    vlSelfRef.program_address = vlSymsp->TOP.program_address;
    vlSelfRef.start = vlSymsp->TOP.start;
    vlSelfRef.u_ex_mem_reg__DOT__en = (1U & (~ (IData)(vlSelfRef.stall)));
    vlSelfRef.u_dmem__DOT__wack = vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wack;
    vlSelfRef.clk = vlSymsp->TOP.clk;
    vlSelfRef.rst = vlSymsp->TOP.rst;
    vlSelfRef.u_ex_mem_reg__DOT__ctrl_out = vlSelfRef.u_ex_mem_reg__DOT__ctrl_q;
    vlSelfRef.u_ex_mem_reg__DOT__data_out[0U] = vlSelfRef.u_ex_mem_reg__DOT__data_q[0U];
    vlSelfRef.u_ex_mem_reg__DOT__data_out[1U] = vlSelfRef.u_ex_mem_reg__DOT__data_q[1U];
    vlSelfRef.u_ex_mem_reg__DOT__data_out[2U] = vlSelfRef.u_ex_mem_reg__DOT__data_q[2U];
    vlSelfRef.u_if_id_reg__DOT__ctrl_out = vlSelfRef.u_if_id_reg__DOT__ctrl_q;
    vlSelfRef.u_if_id_reg__DOT__data_out = vlSelfRef.u_if_id_reg__DOT__data_q;
    if (((IData)(vlSelfRef.u_execute__DOT__stall) ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__stall))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3433, vlSelfRef.u_execute__DOT__stall, vlSelfRef.u_execute__DOT____Vtogcov__stall);
        vlSelfRef.u_execute__DOT____Vtogcov__stall 
            = vlSelfRef.u_execute__DOT__stall;
    }
    if ((vlSelfRef.program_address ^ vlSelfRef.__Vtogcov__program_address)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 6, vlSelfRef.program_address, vlSelfRef.__Vtogcov__program_address);
        vlSelfRef.__Vtogcov__program_address = vlSelfRef.program_address;
    }
    if (((IData)(vlSelfRef.start) ^ (IData)(vlSelfRef.__Vtogcov__start))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4, vlSelfRef.start, vlSelfRef.__Vtogcov__start);
        vlSelfRef.__Vtogcov__start = vlSelfRef.start;
    }
    if (((IData)(vlSelfRef.u_ex_mem_reg__DOT__en) ^ (IData)(vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4526, vlSelfRef.u_ex_mem_reg__DOT__en, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__en);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__en 
            = vlSelfRef.u_ex_mem_reg__DOT__en;
    }
    vlSelfRef.u_if_id_reg__DOT__en = vlSelfRef.u_ex_mem_reg__DOT__en;
    if (((IData)(vlSelfRef.u_dmem__DOT__wack) ^ (IData)(vlSelfRef.u_dmem__DOT____Vtogcov__wack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5153, vlSelfRef.u_dmem__DOT__wack, vlSelfRef.u_dmem__DOT____Vtogcov__wack);
        vlSelfRef.u_dmem__DOT____Vtogcov__wack = vlSelfRef.u_dmem__DOT__wack;
    }
    vlSelfRef.dmem_wack = vlSelfRef.u_dmem__DOT__wack;
    if (((IData)(vlSelfRef.clk) ^ (IData)(vlSelfRef.__Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 0, vlSelfRef.clk, vlSelfRef.__Vtogcov__clk);
        vlSelfRef.__Vtogcov__clk = vlSelfRef.clk;
    }
    vlSelfRef.u_if_id_reg__DOT__clk = vlSelfRef.clk;
    vlSelfRef.u_ex_mem_reg__DOT__clk = vlSelfRef.clk;
    vlSelfRef.u_control_unit__DOT__clk = vlSelfRef.clk;
    vlSelfRef.u_execute__DOT__clk = vlSelfRef.clk;
    vlSelfRef.u_decoder__DOT__clk = vlSelfRef.clk;
    vlSelfRef.u_dmem__DOT__clk = vlSelfRef.clk;
    if (((IData)(vlSelfRef.rst) ^ (IData)(vlSelfRef.__Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 2, vlSelfRef.rst, vlSelfRef.__Vtogcov__rst);
        vlSelfRef.__Vtogcov__rst = vlSelfRef.rst;
    }
    vlSelfRef.u_if_id_reg__DOT__rst = vlSelfRef.rst;
    vlSelfRef.u_control_unit__DOT__rst = vlSelfRef.rst;
    vlSelfRef.u_execute__DOT__rst = vlSelfRef.rst;
    vlSelfRef.u_ex_mem_reg__DOT__rst = vlSelfRef.rst;
    vlSelfRef.u_decoder__DOT__rst = vlSelfRef.rst;
    vlSelfRef.u_dmem__DOT__rst = vlSelfRef.rst;
    if (((IData)(vlSelfRef.u_ex_mem_reg__DOT__ctrl_out) 
         ^ (IData)(vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_out))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4530, vlSelfRef.u_ex_mem_reg__DOT__ctrl_out, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_out);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_out 
            = vlSelfRef.u_ex_mem_reg__DOT__ctrl_out;
    }
    vlSelfRef.mem_ctrl_out = vlSelfRef.u_ex_mem_reg__DOT__ctrl_out;
    __Vtemp_2[0U] = (vlSelfRef.u_ex_mem_reg__DOT__data_out[0U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out[0U]);
    __Vtemp_2[1U] = (vlSelfRef.u_ex_mem_reg__DOT__data_out[1U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out[1U]);
    __Vtemp_2[2U] = (vlSelfRef.u_ex_mem_reg__DOT__data_out[2U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out[2U]);
    if (__Vtemp_2) {
        VL_COV_TOGGLE_CHG_ST_W(77, vlSymsp->__Vcoverage + 4686, vlSelfRef.u_ex_mem_reg__DOT__data_out, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out[0U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_out[0U];
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out[1U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_out[1U];
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out[2U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_out[2U];
    }
    vlSelfRef.mem_data_out[0U] = vlSelfRef.u_ex_mem_reg__DOT__data_out[0U];
    vlSelfRef.mem_data_out[1U] = vlSelfRef.u_ex_mem_reg__DOT__data_out[1U];
    vlSelfRef.mem_data_out[2U] = vlSelfRef.u_ex_mem_reg__DOT__data_out[2U];
    if (((IData)(vlSelfRef.u_if_id_reg__DOT__ctrl_out) 
         ^ (IData)(vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_out))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1439, vlSelfRef.u_if_id_reg__DOT__ctrl_out, vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_out);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_out 
            = vlSelfRef.u_if_id_reg__DOT__ctrl_out;
    }
    vlSelfRef.id_valid = vlSelfRef.u_if_id_reg__DOT__ctrl_out;
    if ((vlSelfRef.u_if_id_reg__DOT__data_out ^ vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_out)) {
        VL_COV_TOGGLE_CHG_ST_Q(64, vlSymsp->__Vcoverage + 1569, vlSelfRef.u_if_id_reg__DOT__data_out, vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_out);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_out 
            = vlSelfRef.u_if_id_reg__DOT__data_out;
    }
    vlSelfRef.id_pc = (IData)((vlSelfRef.u_if_id_reg__DOT__data_out 
                               >> 0x20U));
    vlSelfRef.id_instruction = (IData)(vlSelfRef.u_if_id_reg__DOT__data_out);
    if (((IData)(vlSelfRef.u_if_id_reg__DOT__en) ^ (IData)(vlSelfRef.u_if_id_reg__DOT____Vtogcov__en))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1435, vlSelfRef.u_if_id_reg__DOT__en, vlSelfRef.u_if_id_reg__DOT____Vtogcov__en);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__en = vlSelfRef.u_if_id_reg__DOT__en;
    }
    if (((IData)(vlSelfRef.dmem_wack) ^ (IData)(vlSelfRef.__Vtogcov__dmem_wack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1406, vlSelfRef.dmem_wack, vlSelfRef.__Vtogcov__dmem_wack);
        vlSelfRef.__Vtogcov__dmem_wack = vlSelfRef.dmem_wack;
    }
    if (((IData)(vlSelfRef.u_if_id_reg__DOT__clk) ^ (IData)(vlSelfRef.u_if_id_reg__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1429, vlSelfRef.u_if_id_reg__DOT__clk, vlSelfRef.u_if_id_reg__DOT____Vtogcov__clk);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__clk 
            = vlSelfRef.u_if_id_reg__DOT__clk;
    }
    if (((IData)(vlSelfRef.u_ex_mem_reg__DOT__clk) 
         ^ (IData)(vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4520, vlSelfRef.u_ex_mem_reg__DOT__clk, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__clk);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__clk 
            = vlSelfRef.u_ex_mem_reg__DOT__clk;
    }
    if (((IData)(vlSelfRef.u_control_unit__DOT__clk) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1836, vlSelfRef.u_control_unit__DOT__clk, vlSelfRef.u_control_unit__DOT____Vtogcov__clk);
        vlSelfRef.u_control_unit__DOT____Vtogcov__clk 
            = vlSelfRef.u_control_unit__DOT__clk;
    }
    if (((IData)(vlSelfRef.u_execute__DOT__clk) ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3429, vlSelfRef.u_execute__DOT__clk, vlSelfRef.u_execute__DOT____Vtogcov__clk);
        vlSelfRef.u_execute__DOT____Vtogcov__clk = vlSelfRef.u_execute__DOT__clk;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__clk) ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1934, vlSelfRef.u_decoder__DOT__clk, vlSelfRef.u_decoder__DOT____Vtogcov__clk);
        vlSelfRef.u_decoder__DOT____Vtogcov__clk = vlSelfRef.u_decoder__DOT__clk;
    }
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__clk = vlSelfRef.u_decoder__DOT__clk;
    if (((IData)(vlSelfRef.u_dmem__DOT__clk) ^ (IData)(vlSelfRef.u_dmem__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5005, vlSelfRef.u_dmem__DOT__clk, vlSelfRef.u_dmem__DOT____Vtogcov__clk);
        vlSelfRef.u_dmem__DOT____Vtogcov__clk = vlSelfRef.u_dmem__DOT__clk;
    }
    vlSelfRef.u_dmem__DOT__dmem__DOT__clk = vlSelfRef.u_dmem__DOT__clk;
    if (((IData)(vlSelfRef.u_if_id_reg__DOT__rst) ^ (IData)(vlSelfRef.u_if_id_reg__DOT____Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1431, vlSelfRef.u_if_id_reg__DOT__rst, vlSelfRef.u_if_id_reg__DOT____Vtogcov__rst);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__rst 
            = vlSelfRef.u_if_id_reg__DOT__rst;
    }
    if (((IData)(vlSelfRef.u_control_unit__DOT__rst) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1838, vlSelfRef.u_control_unit__DOT__rst, vlSelfRef.u_control_unit__DOT____Vtogcov__rst);
        vlSelfRef.u_control_unit__DOT____Vtogcov__rst 
            = vlSelfRef.u_control_unit__DOT__rst;
    }
    if (((IData)(vlSelfRef.u_execute__DOT__rst) ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3431, vlSelfRef.u_execute__DOT__rst, vlSelfRef.u_execute__DOT____Vtogcov__rst);
        vlSelfRef.u_execute__DOT____Vtogcov__rst = vlSelfRef.u_execute__DOT__rst;
    }
    if (((IData)(vlSelfRef.u_ex_mem_reg__DOT__rst) 
         ^ (IData)(vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4522, vlSelfRef.u_ex_mem_reg__DOT__rst, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__rst);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__rst 
            = vlSelfRef.u_ex_mem_reg__DOT__rst;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__rst) ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1936, vlSelfRef.u_decoder__DOT__rst, vlSelfRef.u_decoder__DOT____Vtogcov__rst);
        vlSelfRef.u_decoder__DOT____Vtogcov__rst = vlSelfRef.u_decoder__DOT__rst;
    }
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__rst = vlSelfRef.u_decoder__DOT__rst;
    if (((IData)(vlSelfRef.u_dmem__DOT__rst) ^ (IData)(vlSelfRef.u_dmem__DOT____Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5007, vlSelfRef.u_dmem__DOT__rst, vlSelfRef.u_dmem__DOT____Vtogcov__rst);
        vlSelfRef.u_dmem__DOT____Vtogcov__rst = vlSelfRef.u_dmem__DOT__rst;
    }
    vlSelfRef.u_dmem__DOT__dmem__DOT__rst = vlSelfRef.u_dmem__DOT__rst;
    if (((IData)(vlSelfRef.mem_ctrl_out) ^ (IData)(vlSelfRef.__Vtogcov__mem_ctrl_out))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1028, vlSelfRef.mem_ctrl_out, vlSelfRef.__Vtogcov__mem_ctrl_out);
        vlSelfRef.__Vtogcov__mem_ctrl_out = vlSelfRef.mem_ctrl_out;
    }
    if ((0x1000U & (vlSelfRef.mem_data_out[2U] ^ vlSelfRef.__Vtogcov__mem_data_out[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1184, 
                               (vlSelfRef.mem_data_out[2U] 
                                >> 0xcU), (vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                           >> 0xcU));
        vlSelfRef.__Vtogcov__mem_data_out[2U] = ((0xfffU 
                                                  & vlSelfRef.__Vtogcov__mem_data_out[2U]) 
                                                 | (0x1000U 
                                                    & vlSelfRef.mem_data_out[2U]));
    }
    if ((0x800U & (vlSelfRef.mem_data_out[2U] ^ vlSelfRef.__Vtogcov__mem_data_out[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1186, 
                               (vlSelfRef.mem_data_out[2U] 
                                >> 0xbU), (vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                           >> 0xbU));
        vlSelfRef.__Vtogcov__mem_data_out[2U] = ((0x17ffU 
                                                  & vlSelfRef.__Vtogcov__mem_data_out[2U]) 
                                                 | (0x800U 
                                                    & vlSelfRef.mem_data_out[2U]));
    }
    if ((0x400U & (vlSelfRef.mem_data_out[2U] ^ vlSelfRef.__Vtogcov__mem_data_out[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1188, 
                               (vlSelfRef.mem_data_out[2U] 
                                >> 0xaU), (vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                           >> 0xaU));
        vlSelfRef.__Vtogcov__mem_data_out[2U] = ((0x1bffU 
                                                  & vlSelfRef.__Vtogcov__mem_data_out[2U]) 
                                                 | (0x400U 
                                                    & vlSelfRef.mem_data_out[2U]));
    }
    if ((0x200U & (vlSelfRef.mem_data_out[2U] ^ vlSelfRef.__Vtogcov__mem_data_out[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1190, 
                               (vlSelfRef.mem_data_out[2U] 
                                >> 9U), (vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                         >> 9U));
        vlSelfRef.__Vtogcov__mem_data_out[2U] = ((0x1dffU 
                                                  & vlSelfRef.__Vtogcov__mem_data_out[2U]) 
                                                 | (0x200U 
                                                    & vlSelfRef.mem_data_out[2U]));
    }
    if ((0xfU & (((vlSelfRef.mem_data_out[2U] << 0x1bU) 
                  | (vlSelfRef.mem_data_out[2U] >> 5U)) 
                 ^ ((vlSelfRef.__Vtogcov__mem_data_out[2U] 
                     << 0x1bU) | (vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                  >> 5U))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSymsp->__Vcoverage + 1192, 
                               ((vlSelfRef.mem_data_out[2U] 
                                 << 0x1bU) | (vlSelfRef.mem_data_out[2U] 
                                              >> 5U)), 
                               ((vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                 << 0x1bU) | (vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                              >> 5U)));
        vlSelfRef.__Vtogcov__mem_data_out[2U] = ((0x1e1fU 
                                                  & vlSelfRef.__Vtogcov__mem_data_out[2U]) 
                                                 | (0x1e0U 
                                                    & vlSelfRef.mem_data_out[2U]));
    }
    if ((0x1fU & (vlSelfRef.mem_data_out[2U] ^ vlSelfRef.__Vtogcov__mem_data_out[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 1200, 
                               vlSelfRef.mem_data_out[2U], 
                               vlSelfRef.__Vtogcov__mem_data_out[2U]);
        vlSelfRef.__Vtogcov__mem_data_out[2U] = ((0x1fe0U 
                                                  & vlSelfRef.__Vtogcov__mem_data_out[2U]) 
                                                 | (0x1fU 
                                                    & vlSelfRef.mem_data_out[2U]));
    }
    if ((vlSelfRef.mem_data_out[1U] ^ vlSelfRef.__Vtogcov__mem_data_out[1U])) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 1210, 
                               vlSelfRef.mem_data_out[1U], 
                               vlSelfRef.__Vtogcov__mem_data_out[1U]);
        vlSelfRef.__Vtogcov__mem_data_out[1U] = vlSelfRef.mem_data_out[1U];
    }
    if ((vlSelfRef.mem_data_out[0U] ^ vlSelfRef.__Vtogcov__mem_data_out[0U])) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 1274, 
                               vlSelfRef.mem_data_out[0U], 
                               vlSelfRef.__Vtogcov__mem_data_out[0U]);
        vlSelfRef.__Vtogcov__mem_data_out[0U] = vlSelfRef.mem_data_out[0U];
    }
    vlSelfRef.u_dmem__DOT__write = (1U & (vlSelfRef.mem_data_out[2U] 
                                          >> 9U));
    vlSelfRef.u_dmem__DOT__wdata = vlSelfRef.mem_data_out[0U];
    vlSelfRef.u_dmem__DOT__wbe = (0xfU & (vlSelfRef.mem_data_out[2U] 
                                          >> 5U));
    vlSelfRef.u_dmem__DOT__read = (1U & (vlSelfRef.mem_data_out[2U] 
                                         >> 0xaU));
    vlSelfRef.wb_write_reg = (0x1fU & vlSelfRef.mem_data_out[2U]);
    vlSelfRef.wb_reg_write = ((vlSelfRef.mem_data_out[2U] 
                               >> 0xcU) & (IData)(vlSelfRef.mem_ctrl_out));
    vlSelfRef.u_dmem__DOT__addr = vlSelfRef.mem_data_out[1U];
    if (((IData)(vlSelfRef.id_valid) ^ (IData)(vlSelfRef.__Vtogcov__id_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 530, vlSelfRef.id_valid, vlSelfRef.__Vtogcov__id_valid);
        vlSelfRef.__Vtogcov__id_valid = vlSelfRef.id_valid;
    }
    vlSelfRef.u_ex_mem_reg__DOT__ctrl_in = vlSelfRef.id_valid;
    if ((vlSelfRef.id_pc ^ vlSelfRef.__Vtogcov__id_pc)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 466, vlSelfRef.id_pc, vlSelfRef.__Vtogcov__id_pc);
        vlSelfRef.__Vtogcov__id_pc = vlSelfRef.id_pc;
    }
    vlSelfRef.u_decoder__DOT__PC = vlSelfRef.id_pc;
    vlSelfRef.u_execute__DOT__PC = vlSelfRef.id_pc;
    if ((vlSelfRef.id_instruction ^ vlSelfRef.__Vtogcov__id_instruction)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 402, vlSelfRef.id_instruction, vlSelfRef.__Vtogcov__id_instruction);
        vlSelfRef.__Vtogcov__id_instruction = vlSelfRef.id_instruction;
    }
    vlSelfRef.id_instruction_real = ((IData)(vlSelfRef.id_valid)
                                      ? ([&]() {
                ++(vlSymsp->__Vcoverage[1417]);
            }(), vlSelfRef.id_instruction) : ([&]() {
                ++(vlSymsp->__Vcoverage[1418]);
            }(), 0x13U));
    if (((IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__clk) 
         ^ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3189, vlSelfRef.u_decoder__DOT__u_regfile__DOT__clk, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__clk);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__clk 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__clk;
    }
    if (((IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__clk) 
         ^ (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__clk))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5221, vlSelfRef.u_dmem__DOT__dmem__DOT__clk, vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__clk);
        vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__clk 
            = vlSelfRef.u_dmem__DOT__dmem__DOT__clk;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__rst) 
         ^ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3191, vlSelfRef.u_decoder__DOT__u_regfile__DOT__rst, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rst);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rst 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__rst;
    }
    if (((IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__rst) 
         ^ (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__rst))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5223, vlSelfRef.u_dmem__DOT__dmem__DOT__rst, vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__rst);
        vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__rst 
            = vlSelfRef.u_dmem__DOT__dmem__DOT__rst;
    }
    if (((IData)(vlSelfRef.u_dmem__DOT__write) ^ (IData)(vlSelfRef.u_dmem__DOT____Vtogcov__write))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5011, vlSelfRef.u_dmem__DOT__write, vlSelfRef.u_dmem__DOT____Vtogcov__write);
        vlSelfRef.u_dmem__DOT____Vtogcov__write = vlSelfRef.u_dmem__DOT__write;
    }
    if ((vlSelfRef.u_dmem__DOT__wdata ^ vlSelfRef.u_dmem__DOT____Vtogcov__wdata)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5077, vlSelfRef.u_dmem__DOT__wdata, vlSelfRef.u_dmem__DOT____Vtogcov__wdata);
        vlSelfRef.u_dmem__DOT____Vtogcov__wdata = vlSelfRef.u_dmem__DOT__wdata;
    }
    if (((IData)(vlSelfRef.u_dmem__DOT__wbe) ^ (IData)(vlSelfRef.u_dmem__DOT____Vtogcov__wbe))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSymsp->__Vcoverage + 5141, vlSelfRef.u_dmem__DOT__wbe, vlSelfRef.u_dmem__DOT____Vtogcov__wbe);
        vlSelfRef.u_dmem__DOT____Vtogcov__wbe = vlSelfRef.u_dmem__DOT__wbe;
    }
    if (((IData)(vlSelfRef.u_dmem__DOT__read) ^ (IData)(vlSelfRef.u_dmem__DOT____Vtogcov__read))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5009, vlSelfRef.u_dmem__DOT__read, vlSelfRef.u_dmem__DOT____Vtogcov__read);
        vlSelfRef.u_dmem__DOT____Vtogcov__read = vlSelfRef.u_dmem__DOT__read;
    }
    if (((IData)(vlSelfRef.wb_write_reg) ^ (IData)(vlSelfRef.__Vtogcov__wb_write_reg))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 954, vlSelfRef.wb_write_reg, vlSelfRef.__Vtogcov__wb_write_reg);
        vlSelfRef.__Vtogcov__wb_write_reg = vlSelfRef.wb_write_reg;
    }
    vlSelfRef.u_decoder__DOT__write_reg = vlSelfRef.wb_write_reg;
    if (((IData)(vlSelfRef.wb_reg_write) ^ (IData)(vlSelfRef.__Vtogcov__wb_reg_write))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 952, vlSelfRef.wb_reg_write, vlSelfRef.__Vtogcov__wb_reg_write);
        vlSelfRef.__Vtogcov__wb_reg_write = vlSelfRef.wb_reg_write;
    }
    vlSelfRef.u_decoder__DOT__reg_write = vlSelfRef.wb_reg_write;
    if ((vlSelfRef.u_dmem__DOT__addr ^ vlSelfRef.u_dmem__DOT____Vtogcov__addr)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5013, vlSelfRef.u_dmem__DOT__addr, vlSelfRef.u_dmem__DOT____Vtogcov__addr);
        vlSelfRef.u_dmem__DOT____Vtogcov__addr = vlSelfRef.u_dmem__DOT__addr;
    }
    if (((IData)(vlSelfRef.u_ex_mem_reg__DOT__ctrl_in) 
         ^ (IData)(vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_in))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4528, vlSelfRef.u_ex_mem_reg__DOT__ctrl_in, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_in);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_in 
            = vlSelfRef.u_ex_mem_reg__DOT__ctrl_in;
    }
    if ((vlSelfRef.u_decoder__DOT__PC ^ vlSelfRef.u_decoder__DOT____Vtogcov__PC)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2002, vlSelfRef.u_decoder__DOT__PC, vlSelfRef.u_decoder__DOT____Vtogcov__PC);
        vlSelfRef.u_decoder__DOT____Vtogcov__PC = vlSelfRef.u_decoder__DOT__PC;
    }
    if ((vlSelfRef.u_execute__DOT__PC ^ vlSelfRef.u_execute__DOT____Vtogcov__PC)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3467, vlSelfRef.u_execute__DOT__PC, vlSelfRef.u_execute__DOT____Vtogcov__PC);
        vlSelfRef.u_execute__DOT____Vtogcov__PC = vlSelfRef.u_execute__DOT__PC;
    }
    if ((vlSelfRef.id_instruction_real ^ vlSelfRef.__Vtogcov__id_instruction_real)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 532, vlSelfRef.id_instruction_real, vlSelfRef.__Vtogcov__id_instruction_real);
        vlSelfRef.__Vtogcov__id_instruction_real = vlSelfRef.id_instruction_real;
    }
    vlSelfRef.u_decoder__DOT__instruction = vlSelfRef.id_instruction_real;
    if (((IData)(vlSelfRef.u_decoder__DOT__write_reg) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__write_reg))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 2074, vlSelfRef.u_decoder__DOT__write_reg, vlSelfRef.u_decoder__DOT____Vtogcov__write_reg);
        vlSelfRef.u_decoder__DOT____Vtogcov__write_reg 
            = vlSelfRef.u_decoder__DOT__write_reg;
    }
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__waddr 
        = vlSelfRef.u_decoder__DOT__write_reg;
    if (((IData)(vlSelfRef.u_decoder__DOT__reg_write) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__reg_write))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 2072, vlSelfRef.u_decoder__DOT__reg_write, vlSelfRef.u_decoder__DOT____Vtogcov__reg_write);
        vlSelfRef.u_decoder__DOT____Vtogcov__reg_write 
            = vlSelfRef.u_decoder__DOT__reg_write;
    }
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen = vlSelfRef.u_decoder__DOT__reg_write;
    if ((vlSelfRef.u_decoder__DOT__instruction ^ vlSelfRef.u_decoder__DOT____Vtogcov__instruction)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 1938, vlSelfRef.u_decoder__DOT__instruction, vlSelfRef.u_decoder__DOT____Vtogcov__instruction);
        vlSelfRef.u_decoder__DOT____Vtogcov__instruction 
            = vlSelfRef.u_decoder__DOT__instruction;
    }
    vlSelfRef.u_decoder__DOT__funct3 = (7U & (vlSelfRef.u_decoder__DOT__instruction 
                                              >> 0xcU));
    vlSelfRef.u_decoder__DOT__u_imm = (vlSelfRef.u_decoder__DOT__instruction 
                                       >> 0xcU);
    vlSelfRef.u_decoder__DOT__i_imm_orig = (vlSelfRef.u_decoder__DOT__instruction 
                                            >> 0x14U);
    vlSelfRef.u_decoder__DOT__uj_imm_32 = (((- (IData)(
                                                       (vlSelfRef.u_decoder__DOT__instruction 
                                                        >> 0x1fU))) 
                                            << 0x14U) 
                                           | (((0xff000U 
                                                & vlSelfRef.u_decoder__DOT__instruction) 
                                               | (0x800U 
                                                  & (vlSelfRef.u_decoder__DOT__instruction 
                                                     >> 9U))) 
                                              | (0x7feU 
                                                 & (vlSelfRef.u_decoder__DOT__instruction 
                                                    >> 0x14U))));
    vlSelfRef.u_decoder__DOT__rs1 = (0x1fU & (vlSelfRef.u_decoder__DOT__instruction 
                                              >> 0xfU));
    vlSelfRef.u_decoder__DOT__rs2 = (0x1fU & (vlSelfRef.u_decoder__DOT__instruction 
                                              >> 0x14U));
    vlSelfRef.u_decoder__DOT__rd = (0x1fU & (vlSelfRef.u_decoder__DOT__instruction 
                                             >> 7U));
    vlSelfRef.u_decoder__DOT__funct7 = (vlSelfRef.u_decoder__DOT__instruction 
                                        >> 0x19U);
    vlSelfRef.u_decoder__DOT__opcode = (0x7fU & vlSelfRef.u_decoder__DOT__instruction);
    if (((IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__waddr) 
         ^ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__waddr))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 3195, vlSelfRef.u_decoder__DOT__u_regfile__DOT__waddr, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__waddr);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__waddr 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__waddr;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen) 
         ^ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__wen))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3193, vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__wen);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__wen 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__funct3) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__funct3))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 2176, vlSelfRef.u_decoder__DOT__funct3, vlSelfRef.u_decoder__DOT____Vtogcov__funct3);
        vlSelfRef.u_decoder__DOT____Vtogcov__funct3 
            = vlSelfRef.u_decoder__DOT__funct3;
    }
    vlSelfRef.id_funct3 = vlSelfRef.u_decoder__DOT__funct3;
    if ((vlSelfRef.u_decoder__DOT__u_imm ^ vlSelfRef.u_decoder__DOT____Vtogcov__u_imm)) {
        VL_COV_TOGGLE_CHG_ST_I(20, vlSymsp->__Vcoverage + 2564, vlSelfRef.u_decoder__DOT__u_imm, vlSelfRef.u_decoder__DOT____Vtogcov__u_imm);
        vlSelfRef.u_decoder__DOT____Vtogcov__u_imm 
            = vlSelfRef.u_decoder__DOT__u_imm;
    }
    vlSelfRef.u_decoder__DOT__u_imm_32 = (vlSelfRef.u_decoder__DOT__u_imm 
                                          << 0xcU);
    if (((IData)(vlSelfRef.u_decoder__DOT__i_imm_orig) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__i_imm_orig))) {
        VL_COV_TOGGLE_CHG_ST_I(12, vlSymsp->__Vcoverage + 2540, vlSelfRef.u_decoder__DOT__i_imm_orig, vlSelfRef.u_decoder__DOT____Vtogcov__i_imm_orig);
        vlSelfRef.u_decoder__DOT____Vtogcov__i_imm_orig 
            = vlSelfRef.u_decoder__DOT__i_imm_orig;
    }
    vlSelfRef.u_decoder__DOT__i_imm_32 = (((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.u_decoder__DOT__i_imm_orig) 
                                                          >> 0xbU)))) 
                                           << 0xcU) 
                                          | (IData)(vlSelfRef.u_decoder__DOT__i_imm_orig));
    if ((vlSelfRef.u_decoder__DOT__uj_imm_32 ^ vlSelfRef.u_decoder__DOT____Vtogcov__uj_imm_32)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2974, vlSelfRef.u_decoder__DOT__uj_imm_32, vlSelfRef.u_decoder__DOT____Vtogcov__uj_imm_32);
        vlSelfRef.u_decoder__DOT____Vtogcov__uj_imm_32 
            = vlSelfRef.u_decoder__DOT__uj_imm_32;
    }
    vlSelfRef.u_decoder__DOT__JAL_target = (vlSelfRef.u_decoder__DOT__PC 
                                            + vlSelfRef.u_decoder__DOT__uj_imm_32);
    if (((IData)(vlSelfRef.u_decoder__DOT__rs1) ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__rs1))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 2182, vlSelfRef.u_decoder__DOT__rs1, vlSelfRef.u_decoder__DOT____Vtogcov__rs1);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs1 = vlSelfRef.u_decoder__DOT__rs1;
    }
    vlSelfRef.id_rs1 = vlSelfRef.u_decoder__DOT__rs1;
    vlSelfRef.u_decoder__DOT__rs1_data_bypass = (((IData)(vlSelfRef.u_decoder__DOT__rs1) 
                                                  == (IData)(vlSelfRef.u_decoder__DOT__write_reg)) 
                                                 & ((0U 
                                                     != (IData)(vlSelfRef.u_decoder__DOT__write_reg)) 
                                                    & ((IData)(vlSelfRef.u_decoder__DOT__reg_write) 
                                                       & (0U 
                                                          != (IData)(vlSelfRef.u_decoder__DOT__rs1)))));
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1 
        = vlSelfRef.u_decoder__DOT__rs1;
    if (((IData)(vlSelfRef.u_decoder__DOT__rs2) ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__rs2))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 2192, vlSelfRef.u_decoder__DOT__rs2, vlSelfRef.u_decoder__DOT____Vtogcov__rs2);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs2 = vlSelfRef.u_decoder__DOT__rs2;
    }
    vlSelfRef.id_rs2 = vlSelfRef.u_decoder__DOT__rs2;
    vlSelfRef.u_decoder__DOT__rs2_data_bypass = (((IData)(vlSelfRef.u_decoder__DOT__rs2) 
                                                  == (IData)(vlSelfRef.u_decoder__DOT__write_reg)) 
                                                 & ((IData)(vlSelfRef.u_decoder__DOT__reg_write) 
                                                    & (0U 
                                                       != (IData)(vlSelfRef.u_decoder__DOT__rs2))));
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2 
        = vlSelfRef.u_decoder__DOT__rs2;
    if (((IData)(vlSelfRef.u_decoder__DOT__rd) ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__rd))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 2202, vlSelfRef.u_decoder__DOT__rd, vlSelfRef.u_decoder__DOT____Vtogcov__rd);
        vlSelfRef.u_decoder__DOT____Vtogcov__rd = vlSelfRef.u_decoder__DOT__rd;
    }
    vlSelfRef.id_rd = vlSelfRef.u_decoder__DOT__rd;
    vlSelfRef.u_decoder__DOT__s_imm_lsb = vlSelfRef.u_decoder__DOT__rd;
    if (((IData)(vlSelfRef.u_decoder__DOT__funct7) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__funct7))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 2162, vlSelfRef.u_decoder__DOT__funct7, vlSelfRef.u_decoder__DOT____Vtogcov__funct7);
        vlSelfRef.u_decoder__DOT____Vtogcov__funct7 
            = vlSelfRef.u_decoder__DOT__funct7;
    }
    vlSelfRef.id_funct7 = vlSelfRef.u_decoder__DOT__funct7;
    vlSelfRef.u_decoder__DOT__s_imm_msb = vlSelfRef.u_decoder__DOT__funct7;
    if (((IData)(vlSelfRef.u_decoder__DOT__opcode) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__opcode))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 2148, vlSelfRef.u_decoder__DOT__opcode, vlSelfRef.u_decoder__DOT____Vtogcov__opcode);
        vlSelfRef.u_decoder__DOT____Vtogcov__opcode 
            = vlSelfRef.u_decoder__DOT__opcode;
    }
    if ((0x23U == (IData)(vlSelfRef.u_decoder__DOT__opcode))) {
        if ((0U == (IData)(vlSelfRef.u_decoder__DOT__funct3))) {
            vlSelfRef.u_decoder__DOT__mem_wbe = 1U;
            ++(vlSymsp->__Vcoverage[3182]);
        } else if ((1U == (IData)(vlSelfRef.u_decoder__DOT__funct3))) {
            ++(vlSymsp->__Vcoverage[3183]);
            vlSelfRef.u_decoder__DOT__mem_wbe = 3U;
        } else if ((2U == (IData)(vlSelfRef.u_decoder__DOT__funct3))) {
            ++(vlSymsp->__Vcoverage[3184]);
            vlSelfRef.u_decoder__DOT__mem_wbe = 0xfU;
        } else {
            ++(vlSymsp->__Vcoverage[3185]);
            vlSelfRef.u_decoder__DOT__mem_wbe = 0U;
        }
        ++(vlSymsp->__Vcoverage[3186]);
    } else {
        ++(vlSymsp->__Vcoverage[3187]);
        vlSelfRef.u_decoder__DOT__mem_wbe = 0U;
    }
    ++(vlSymsp->__Vcoverage[3188]);
    vlSelfRef.id_opcode = vlSelfRef.u_decoder__DOT__opcode;
    if (((IData)(vlSelfRef.id_funct3) ^ (IData)(vlSelfRef.__Vtogcov__id_funct3))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 652, vlSelfRef.id_funct3, vlSelfRef.__Vtogcov__id_funct3);
        vlSelfRef.__Vtogcov__id_funct3 = vlSelfRef.id_funct3;
    }
    vlSelfRef.u_execute__DOT__funct3 = vlSelfRef.id_funct3;
    if ((vlSelfRef.u_decoder__DOT__u_imm_32 ^ vlSelfRef.u_decoder__DOT____Vtogcov__u_imm_32)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2668, vlSelfRef.u_decoder__DOT__u_imm_32, vlSelfRef.u_decoder__DOT____Vtogcov__u_imm_32);
        vlSelfRef.u_decoder__DOT____Vtogcov__u_imm_32 
            = vlSelfRef.u_decoder__DOT__u_imm_32;
    }
    if ((vlSelfRef.u_decoder__DOT__i_imm_32 ^ vlSelfRef.u_decoder__DOT____Vtogcov__i_imm_32)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2604, vlSelfRef.u_decoder__DOT__i_imm_32, vlSelfRef.u_decoder__DOT____Vtogcov__i_imm_32);
        vlSelfRef.u_decoder__DOT____Vtogcov__i_imm_32 
            = vlSelfRef.u_decoder__DOT__i_imm_32;
    }
    if ((vlSelfRef.u_decoder__DOT__JAL_target ^ vlSelfRef.u_decoder__DOT____Vtogcov__JAL_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2468, vlSelfRef.u_decoder__DOT__JAL_target, vlSelfRef.u_decoder__DOT____Vtogcov__JAL_target);
        vlSelfRef.u_decoder__DOT____Vtogcov__JAL_target 
            = vlSelfRef.u_decoder__DOT__JAL_target;
    }
    vlSelfRef.id_jal_target = vlSelfRef.u_decoder__DOT__JAL_target;
    if (((IData)(vlSelfRef.id_rs1) ^ (IData)(vlSelfRef.__Vtogcov__id_rs1))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 658, vlSelfRef.id_rs1, vlSelfRef.__Vtogcov__id_rs1);
        vlSelfRef.__Vtogcov__id_rs1 = vlSelfRef.id_rs1;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__rs1_data_bypass) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data_bypass))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3038, vlSelfRef.u_decoder__DOT__rs1_data_bypass, vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data_bypass);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data_bypass 
            = vlSelfRef.u_decoder__DOT__rs1_data_bypass;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1) 
         ^ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__raddr1))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 3269, vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__raddr1);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__raddr1 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1;
    }
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1 
        = ((0U == (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1))
            ? ([&]() {
                ++(vlSymsp->__Vcoverage[3417]);
            }(), 0U) : ([&]() {
                ++(vlSymsp->__Vcoverage[3418]);
            }(), vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs
                        [vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1]));
    if (((IData)(vlSelfRef.id_rs2) ^ (IData)(vlSelfRef.__Vtogcov__id_rs2))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 668, vlSelfRef.id_rs2, vlSelfRef.__Vtogcov__id_rs2);
        vlSelfRef.__Vtogcov__id_rs2 = vlSelfRef.id_rs2;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__rs2_data_bypass) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data_bypass))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3040, vlSelfRef.u_decoder__DOT__rs2_data_bypass, vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data_bypass);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data_bypass 
            = vlSelfRef.u_decoder__DOT__rs2_data_bypass;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2) 
         ^ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__raddr2))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 3279, vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__raddr2);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__raddr2 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2;
    }
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2 
        = ((0U == (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2))
            ? ([&]() {
                ++(vlSymsp->__Vcoverage[3419]);
            }(), 0U) : ([&]() {
                ++(vlSymsp->__Vcoverage[3420]);
            }(), vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs
                        [vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2]));
    if (((IData)(vlSelfRef.id_rd) ^ (IData)(vlSelfRef.__Vtogcov__id_rd))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 678, vlSelfRef.id_rd, vlSelfRef.__Vtogcov__id_rd);
        vlSelfRef.__Vtogcov__id_rd = vlSelfRef.id_rd;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__s_imm_lsb) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_lsb))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 2746, vlSelfRef.u_decoder__DOT__s_imm_lsb, vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_lsb);
        vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_lsb 
            = vlSelfRef.u_decoder__DOT__s_imm_lsb;
    }
    if (((IData)(vlSelfRef.id_funct7) ^ (IData)(vlSelfRef.__Vtogcov__id_funct7))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 638, vlSelfRef.id_funct7, vlSelfRef.__Vtogcov__id_funct7);
        vlSelfRef.__Vtogcov__id_funct7 = vlSelfRef.id_funct7;
    }
    vlSelfRef.u_execute__DOT__funct7 = vlSelfRef.id_funct7;
    if (((IData)(vlSelfRef.u_decoder__DOT__s_imm_msb) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_msb))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 2732, vlSelfRef.u_decoder__DOT__s_imm_msb, vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_msb);
        vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_msb 
            = vlSelfRef.u_decoder__DOT__s_imm_msb;
    }
    vlSelfRef.u_decoder__DOT__s_imm_orig = (((IData)(vlSelfRef.u_decoder__DOT__s_imm_msb) 
                                             << 5U) 
                                            | (IData)(vlSelfRef.u_decoder__DOT__s_imm_lsb));
    vlSelfRef.u_decoder__DOT__sb_imm_orig = (((0x1000U 
                                               & ((IData)(vlSelfRef.u_decoder__DOT__s_imm_msb) 
                                                  << 6U)) 
                                              | (0x800U 
                                                 & ((IData)(vlSelfRef.u_decoder__DOT__s_imm_lsb) 
                                                    << 0xbU))) 
                                             | ((0x7e0U 
                                                 & ((IData)(vlSelfRef.u_decoder__DOT__s_imm_msb) 
                                                    << 5U)) 
                                                | (0x1eU 
                                                   & (IData)(vlSelfRef.u_decoder__DOT__s_imm_lsb))));
    if (((IData)(vlSelfRef.u_decoder__DOT__mem_wbe) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__mem_wbe))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSymsp->__Vcoverage + 2532, vlSelfRef.u_decoder__DOT__mem_wbe, vlSelfRef.u_decoder__DOT____Vtogcov__mem_wbe);
        vlSelfRef.u_decoder__DOT____Vtogcov__mem_wbe 
            = vlSelfRef.u_decoder__DOT__mem_wbe;
    }
    vlSelfRef.id_mem_wbe = vlSelfRef.u_decoder__DOT__mem_wbe;
    if (((IData)(vlSelfRef.id_opcode) ^ (IData)(vlSelfRef.__Vtogcov__id_opcode))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 624, vlSelfRef.id_opcode, vlSelfRef.__Vtogcov__id_opcode);
        vlSelfRef.__Vtogcov__id_opcode = vlSelfRef.id_opcode;
    }
    vlSelfRef.u_control_unit__DOT__opcode = vlSelfRef.id_opcode;
    if (((IData)(vlSelfRef.u_execute__DOT__funct3) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__funct3))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 3455, vlSelfRef.u_execute__DOT__funct3, vlSelfRef.u_execute__DOT____Vtogcov__funct3);
        vlSelfRef.u_execute__DOT____Vtogcov__funct3 
            = vlSelfRef.u_execute__DOT__funct3;
    }
    if ((vlSelfRef.id_jal_target ^ vlSelfRef.__Vtogcov__id_jal_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 274, vlSelfRef.id_jal_target, vlSelfRef.__Vtogcov__id_jal_target);
        vlSelfRef.__Vtogcov__id_jal_target = vlSelfRef.id_jal_target;
    }
    if ((vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1 
         ^ vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rdata1)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3289, vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rdata1);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rdata1 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1;
    }
    vlSelfRef.u_decoder__DOT__rs1_data_decode = vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1;
    if ((vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2 
         ^ vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rdata2)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3353, vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rdata2);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rdata2 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2;
    }
    vlSelfRef.u_decoder__DOT__rs2_data_decode = vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2;
    if (((IData)(vlSelfRef.u_execute__DOT__funct7) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__funct7))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 3441, vlSelfRef.u_execute__DOT__funct7, vlSelfRef.u_execute__DOT____Vtogcov__funct7);
        vlSelfRef.u_execute__DOT____Vtogcov__funct7 
            = vlSelfRef.u_execute__DOT__funct7;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__s_imm_orig) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_orig))) {
        VL_COV_TOGGLE_CHG_ST_I(12, vlSymsp->__Vcoverage + 2756, vlSelfRef.u_decoder__DOT__s_imm_orig, vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_orig);
        vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_orig 
            = vlSelfRef.u_decoder__DOT__s_imm_orig;
    }
    vlSelfRef.u_decoder__DOT__s_imm_32 = (((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.u_decoder__DOT__s_imm_orig) 
                                                          >> 0xbU)))) 
                                           << 0xcU) 
                                          | (IData)(vlSelfRef.u_decoder__DOT__s_imm_orig));
    if (((IData)(vlSelfRef.u_decoder__DOT__sb_imm_orig) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__sb_imm_orig))) {
        VL_COV_TOGGLE_CHG_ST_I(13, vlSymsp->__Vcoverage + 2844, vlSelfRef.u_decoder__DOT__sb_imm_orig, vlSelfRef.u_decoder__DOT____Vtogcov__sb_imm_orig);
        vlSelfRef.u_decoder__DOT____Vtogcov__sb_imm_orig 
            = vlSelfRef.u_decoder__DOT__sb_imm_orig;
    }
    vlSelfRef.u_decoder__DOT__sb_imm_32 = (((- (IData)(
                                                       (1U 
                                                        & ((IData)(vlSelfRef.u_decoder__DOT__sb_imm_orig) 
                                                           >> 0xcU)))) 
                                            << 0xdU) 
                                           | (IData)(vlSelfRef.u_decoder__DOT__sb_imm_orig));
    if (((IData)(vlSelfRef.id_mem_wbe) ^ (IData)(vlSelfRef.__Vtogcov__id_mem_wbe))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSymsp->__Vcoverage + 880, vlSelfRef.id_mem_wbe, vlSelfRef.__Vtogcov__id_mem_wbe);
        vlSelfRef.__Vtogcov__id_mem_wbe = vlSelfRef.id_mem_wbe;
    }
    if (((IData)(vlSelfRef.u_control_unit__DOT__opcode) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__opcode))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 1840, vlSelfRef.u_control_unit__DOT__opcode, vlSelfRef.u_control_unit__DOT____Vtogcov__opcode);
        vlSelfRef.u_control_unit__DOT____Vtogcov__opcode 
            = vlSelfRef.u_control_unit__DOT__opcode;
    }
    vlSelfRef.u_control_unit__DOT__next_PC_sel = (3U 
                                                  & ((0x63U 
                                                      == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                      ? 
                                                     ([&]() {
                    ++(vlSymsp->__Vcoverage[1928]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1933]);
                }(), ((0x6fU == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                       ? ([&]() {
                            ++(vlSymsp->__Vcoverage[1929]);
                        }(), 2U) : ([&]() {
                            ++(vlSymsp->__Vcoverage[1932]);
                        }(), ((0x67U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                               ? ([&]() {
                                    ++(vlSymsp->__Vcoverage[1930]);
                                }(), 3U) : ([&]() {
                                    ++(vlSymsp->__Vcoverage[1931]);
                                }(), 0U)))))));
    vlSelfRef.u_control_unit__DOT__branch_op = (1U 
                                                & ((0x63U 
                                                    == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                    ? 
                                                   ([&]() {
                    ++(vlSymsp->__Vcoverage[1922]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1923]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__regWrite = (1U & 
                                               ((((((((0x33U 
                                                       == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                                      | (0x13U 
                                                         == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                     | (3U 
                                                        == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                    | (0x67U 
                                                       == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                   | (0x6fU 
                                                      == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                  | (0x17U 
                                                     == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                 | (0x37U 
                                                    == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                                 ? 
                                                ([&]() {
                    ++(vlSymsp->__Vcoverage[1886]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1887]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__memWrite = (1U & 
                                               ((0x23U 
                                                 == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                 ? 
                                                ([&]() {
                    ++(vlSymsp->__Vcoverage[1920]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1921]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__memRead = (1U & 
                                              ((3U 
                                                == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                ? ([&]() {
                    ++(vlSymsp->__Vcoverage[1924]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1925]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__memtoReg = (1U & 
                                               ((3U 
                                                 == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                 ? 
                                                ([&]() {
                    ++(vlSymsp->__Vcoverage[1926]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1927]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__ALUOp = (7U & ((0x33U 
                                                   == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                   ? 
                                                  ([&]() {
                    ++(vlSymsp->__Vcoverage[1888]);
                }(), 0U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1901]);
                }(), ((0x13U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                       ? ([&]() {
                            ++(vlSymsp->__Vcoverage[1889]);
                        }(), 1U) : ([&]() {
                            ++(vlSymsp->__Vcoverage[1900]);
                        }(), ((0x23U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                               ? ([&]() {
                                    ++(vlSymsp->__Vcoverage[1890]);
                                }(), 5U) : ([&]() {
                                    ++(vlSymsp->__Vcoverage[1899]);
                                }(), ((3U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                       ? ([&]() {
                                            ++(vlSymsp->__Vcoverage[1891]);
                                        }(), 4U) : 
                                      ([&]() {
                                            ++(vlSymsp->__Vcoverage[1898]);
                                        }(), ((0x63U 
                                               == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                               ? ([&]() {
                                                    ++(vlSymsp->__Vcoverage[1892]);
                                                }(), 2U)
                                               : ([&]() {
                                                    ++(vlSymsp->__Vcoverage[1897]);
                                                }(), 
                                                  (((0x67U 
                                                     == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                                    | (0x6fU 
                                                       == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                                    ? 
                                                   ([&]() {
                                                            ++(vlSymsp->__Vcoverage[1893]);
                                                        }(), 3U)
                                                    : 
                                                   ([&]() {
                                                            ++(vlSymsp->__Vcoverage[1896]);
                                                        }(), 
                                                    (((0x17U 
                                                       == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                                      | (0x37U 
                                                         == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                                      ? 
                                                     ([&]() {
                                                                    ++(vlSymsp->__Vcoverage[1894]);
                                                                }(), 6U)
                                                      : 
                                                     ([&]() {
                                                                    ++(vlSymsp->__Vcoverage[1895]);
                                                                }(), 0U)))))))))))))));
    vlSelfRef.u_control_unit__DOT__operand_A = (3U 
                                                & ((0x17U 
                                                    == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                    ? 
                                                   ([&]() {
                    ++(vlSymsp->__Vcoverage[1902]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1907]);
                }(), ((0x37U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                       ? ([&]() {
                            ++(vlSymsp->__Vcoverage[1903]);
                        }(), 3U) : ([&]() {
                            ++(vlSymsp->__Vcoverage[1906]);
                        }(), (((0x67U == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                               | (0x6fU == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                               ? ([&]() {
                                    ++(vlSymsp->__Vcoverage[1904]);
                                }(), 2U) : ([&]() {
                                    ++(vlSymsp->__Vcoverage[1905]);
                                }(), 0U)))))));
    vlSelfRef.u_control_unit__DOT__operand_B = (1U 
                                                & ((((((0x13U 
                                                        == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                                       | (0x23U 
                                                          == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                      | (3U 
                                                         == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                     | (0x17U 
                                                        == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                    | (0x37U 
                                                       == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                                    ? 
                                                   ([&]() {
                    ++(vlSymsp->__Vcoverage[1908]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1909]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__extend_sel = (((
                                                   (0x13U 
                                                    == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                                   | (3U 
                                                      == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                  | (0x67U 
                                                     == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                                  ? 
                                                 ([&]() {
                ++(vlSymsp->__Vcoverage[1910]);
            }(), 0U) : ([&]() {
                ++(vlSymsp->__Vcoverage[1919]);
            }(), ((0x23U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                   ? ([&]() {
                        ++(vlSymsp->__Vcoverage[1911]);
                    }(), 1U) : ([&]() {
                        ++(vlSymsp->__Vcoverage[1918]);
                    }(), ((0x63U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                           ? ([&]() {
                                ++(vlSymsp->__Vcoverage[1912]);
                            }(), 2U) : ([&]() {
                                ++(vlSymsp->__Vcoverage[1917]);
                            }(), (((0x17U == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                   | (0x37U == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                   ? ([&]() {
                                        ++(vlSymsp->__Vcoverage[1913]);
                                    }(), 3U) : ([&]() {
                                        ++(vlSymsp->__Vcoverage[1916]);
                                    }(), ((0x6fU == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                           ? ([&]() {
                                                ++(vlSymsp->__Vcoverage[1914]);
                                            }(), 4U)
                                           : ([&]() {
                                                ++(vlSymsp->__Vcoverage[1915]);
                                            }(), 0U))))))))));
    if ((vlSelfRef.u_decoder__DOT__rs1_data_decode 
         ^ vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data_decode)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3042, vlSelfRef.u_decoder__DOT__rs1_data_decode, vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data_decode);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data_decode 
            = vlSelfRef.u_decoder__DOT__rs1_data_decode;
    }
    if ((vlSelfRef.u_decoder__DOT__rs2_data_decode 
         ^ vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data_decode)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3106, vlSelfRef.u_decoder__DOT__rs2_data_decode, vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data_decode);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data_decode 
            = vlSelfRef.u_decoder__DOT__rs2_data_decode;
    }
    if ((vlSelfRef.u_decoder__DOT__s_imm_32 ^ vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_32)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2780, vlSelfRef.u_decoder__DOT__s_imm_32, vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_32);
        vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_32 
            = vlSelfRef.u_decoder__DOT__s_imm_32;
    }
    if ((vlSelfRef.u_decoder__DOT__sb_imm_32 ^ vlSelfRef.u_decoder__DOT____Vtogcov__sb_imm_32)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2870, vlSelfRef.u_decoder__DOT__sb_imm_32, vlSelfRef.u_decoder__DOT____Vtogcov__sb_imm_32);
        vlSelfRef.u_decoder__DOT____Vtogcov__sb_imm_32 
            = vlSelfRef.u_decoder__DOT__sb_imm_32;
    }
    vlSelfRef.u_decoder__DOT__branch_target = (vlSelfRef.u_decoder__DOT__PC 
                                               + vlSelfRef.u_decoder__DOT__sb_imm_32);
    if (((IData)(vlSelfRef.u_control_unit__DOT__next_PC_sel) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__next_PC_sel))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSymsp->__Vcoverage + 1882, vlSelfRef.u_control_unit__DOT__next_PC_sel, vlSelfRef.u_control_unit__DOT____Vtogcov__next_PC_sel);
        vlSelfRef.u_control_unit__DOT____Vtogcov__next_PC_sel 
            = vlSelfRef.u_control_unit__DOT__next_PC_sel;
    }
    vlSelfRef.id_pc_sel = vlSelfRef.u_control_unit__DOT__next_PC_sel;
    if (((IData)(vlSelfRef.u_control_unit__DOT__branch_op) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__branch_op))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1874, vlSelfRef.u_control_unit__DOT__branch_op, vlSelfRef.u_control_unit__DOT____Vtogcov__branch_op);
        vlSelfRef.u_control_unit__DOT____Vtogcov__branch_op 
            = vlSelfRef.u_control_unit__DOT__branch_op;
    }
    vlSelfRef.id_branch_op = vlSelfRef.u_control_unit__DOT__branch_op;
    if (((IData)(vlSelfRef.u_control_unit__DOT__regWrite) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__regWrite))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1872, vlSelfRef.u_control_unit__DOT__regWrite, vlSelfRef.u_control_unit__DOT____Vtogcov__regWrite);
        vlSelfRef.u_control_unit__DOT____Vtogcov__regWrite 
            = vlSelfRef.u_control_unit__DOT__regWrite;
    }
    vlSelfRef.id_reg_write = vlSelfRef.u_control_unit__DOT__regWrite;
    if (((IData)(vlSelfRef.u_control_unit__DOT__memWrite) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__memWrite))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1878, vlSelfRef.u_control_unit__DOT__memWrite, vlSelfRef.u_control_unit__DOT____Vtogcov__memWrite);
        vlSelfRef.u_control_unit__DOT____Vtogcov__memWrite 
            = vlSelfRef.u_control_unit__DOT__memWrite;
    }
    vlSelfRef.id_mem_write = vlSelfRef.u_control_unit__DOT__memWrite;
    if (((IData)(vlSelfRef.u_control_unit__DOT__memRead) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__memRead))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1876, vlSelfRef.u_control_unit__DOT__memRead, vlSelfRef.u_control_unit__DOT____Vtogcov__memRead);
        vlSelfRef.u_control_unit__DOT____Vtogcov__memRead 
            = vlSelfRef.u_control_unit__DOT__memRead;
    }
    vlSelfRef.id_mem_read = vlSelfRef.u_control_unit__DOT__memRead;
    if (((IData)(vlSelfRef.u_control_unit__DOT__memtoReg) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__memtoReg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1880, vlSelfRef.u_control_unit__DOT__memtoReg, vlSelfRef.u_control_unit__DOT____Vtogcov__memtoReg);
        vlSelfRef.u_control_unit__DOT____Vtogcov__memtoReg 
            = vlSelfRef.u_control_unit__DOT__memtoReg;
    }
    vlSelfRef.id_mem_to_reg = vlSelfRef.u_control_unit__DOT__memtoReg;
    if (((IData)(vlSelfRef.u_control_unit__DOT__ALUOp) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__ALUOp))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 1854, vlSelfRef.u_control_unit__DOT__ALUOp, vlSelfRef.u_control_unit__DOT____Vtogcov__ALUOp);
        vlSelfRef.u_control_unit__DOT____Vtogcov__ALUOp 
            = vlSelfRef.u_control_unit__DOT__ALUOp;
    }
    vlSelfRef.id_alu_op = vlSelfRef.u_control_unit__DOT__ALUOp;
    if (((IData)(vlSelfRef.u_control_unit__DOT__operand_A) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__operand_A))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSymsp->__Vcoverage + 1860, vlSelfRef.u_control_unit__DOT__operand_A, vlSelfRef.u_control_unit__DOT____Vtogcov__operand_A);
        vlSelfRef.u_control_unit__DOT____Vtogcov__operand_A 
            = vlSelfRef.u_control_unit__DOT__operand_A;
    }
    vlSelfRef.id_operand_a = vlSelfRef.u_control_unit__DOT__operand_A;
    if (((IData)(vlSelfRef.u_control_unit__DOT__operand_B) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__operand_B))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1864, vlSelfRef.u_control_unit__DOT__operand_B, vlSelfRef.u_control_unit__DOT____Vtogcov__operand_B);
        vlSelfRef.u_control_unit__DOT____Vtogcov__operand_B 
            = vlSelfRef.u_control_unit__DOT__operand_B;
    }
    vlSelfRef.id_operand_b = vlSelfRef.u_control_unit__DOT__operand_B;
    if (((IData)(vlSelfRef.u_control_unit__DOT__extend_sel) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__extend_sel))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 1866, vlSelfRef.u_control_unit__DOT__extend_sel, vlSelfRef.u_control_unit__DOT____Vtogcov__extend_sel);
        vlSelfRef.u_control_unit__DOT____Vtogcov__extend_sel 
            = vlSelfRef.u_control_unit__DOT__extend_sel;
    }
    vlSelfRef.id_extend_sel = vlSelfRef.u_control_unit__DOT__extend_sel;
    if ((vlSelfRef.u_decoder__DOT__branch_target ^ vlSelfRef.u_decoder__DOT____Vtogcov__branch_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2404, vlSelfRef.u_decoder__DOT__branch_target, vlSelfRef.u_decoder__DOT____Vtogcov__branch_target);
        vlSelfRef.u_decoder__DOT____Vtogcov__branch_target 
            = vlSelfRef.u_decoder__DOT__branch_target;
    }
    vlSelfRef.id_branch_target = vlSelfRef.u_decoder__DOT__branch_target;
    if (((IData)(vlSelfRef.id_pc_sel) ^ (IData)(vlSelfRef.__Vtogcov__id_pc_sel))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSymsp->__Vcoverage + 204, vlSelfRef.id_pc_sel, vlSelfRef.__Vtogcov__id_pc_sel);
        vlSelfRef.__Vtogcov__id_pc_sel = vlSelfRef.id_pc_sel;
    }
    if (((IData)(vlSelfRef.id_branch_op) ^ (IData)(vlSelfRef.__Vtogcov__id_branch_op))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 616, vlSelfRef.id_branch_op, vlSelfRef.__Vtogcov__id_branch_op);
        vlSelfRef.__Vtogcov__id_branch_op = vlSelfRef.id_branch_op;
    }
    vlSelfRef.u_execute__DOT__branch_op = vlSelfRef.id_branch_op;
    if (((IData)(vlSelfRef.id_reg_write) ^ (IData)(vlSelfRef.__Vtogcov__id_reg_write))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 614, vlSelfRef.id_reg_write, vlSelfRef.__Vtogcov__id_reg_write);
        vlSelfRef.__Vtogcov__id_reg_write = vlSelfRef.id_reg_write;
    }
    VL_ASSIGNBIT_WI(0x4cU, vlSelfRef.id_ex_data_in, 
                    ((IData)(vlSelfRef.id_valid) ? 
                     ([&]() {
                    ++(vlSymsp->__Vcoverage[1419]);
                }(), (IData)(vlSelfRef.id_reg_write))
                      : ([&]() {
                    ++(vlSymsp->__Vcoverage[1420]);
                }(), 0U)));
    if (((IData)(vlSelfRef.id_mem_write) ^ (IData)(vlSelfRef.__Vtogcov__id_mem_write))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 620, vlSelfRef.id_mem_write, vlSelfRef.__Vtogcov__id_mem_write);
        vlSelfRef.__Vtogcov__id_mem_write = vlSelfRef.id_mem_write;
    }
    VL_ASSIGNBIT_WI(0x49U, vlSelfRef.id_ex_data_in, 
                    ((IData)(vlSelfRef.id_valid) ? 
                     ([&]() {
                    ++(vlSymsp->__Vcoverage[1421]);
                }(), (IData)(vlSelfRef.id_mem_write))
                      : ([&]() {
                    ++(vlSymsp->__Vcoverage[1422]);
                }(), 0U)));
    if (((IData)(vlSelfRef.id_mem_read) ^ (IData)(vlSelfRef.__Vtogcov__id_mem_read))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 618, vlSelfRef.id_mem_read, vlSelfRef.__Vtogcov__id_mem_read);
        vlSelfRef.__Vtogcov__id_mem_read = vlSelfRef.id_mem_read;
    }
    VL_ASSIGNBIT_WI(0x4aU, vlSelfRef.id_ex_data_in, 
                    ((IData)(vlSelfRef.id_valid) ? 
                     ([&]() {
                    ++(vlSymsp->__Vcoverage[1423]);
                }(), (IData)(vlSelfRef.id_mem_read))
                      : ([&]() {
                    ++(vlSymsp->__Vcoverage[1424]);
                }(), 0U)));
    if (((IData)(vlSelfRef.id_mem_to_reg) ^ (IData)(vlSelfRef.__Vtogcov__id_mem_to_reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 622, vlSelfRef.id_mem_to_reg, vlSelfRef.__Vtogcov__id_mem_to_reg);
        vlSelfRef.__Vtogcov__id_mem_to_reg = vlSelfRef.id_mem_to_reg;
    }
    VL_ASSIGNBIT_WI(0x4bU, vlSelfRef.id_ex_data_in, 
                    ((IData)(vlSelfRef.id_valid) ? 
                     ([&]() {
                    ++(vlSymsp->__Vcoverage[1425]);
                }(), (IData)(vlSelfRef.id_mem_to_reg))
                      : ([&]() {
                    ++(vlSymsp->__Vcoverage[1426]);
                }(), 0U)));
    if (((IData)(vlSelfRef.id_alu_op) ^ (IData)(vlSelfRef.__Vtogcov__id_alu_op))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 596, vlSelfRef.id_alu_op, vlSelfRef.__Vtogcov__id_alu_op);
        vlSelfRef.__Vtogcov__id_alu_op = vlSelfRef.id_alu_op;
    }
    vlSelfRef.u_execute__DOT__ALU_Operation = vlSelfRef.id_alu_op;
    if (((IData)(vlSelfRef.id_operand_a) ^ (IData)(vlSelfRef.__Vtogcov__id_operand_a))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSymsp->__Vcoverage + 602, vlSelfRef.id_operand_a, vlSelfRef.__Vtogcov__id_operand_a);
        vlSelfRef.__Vtogcov__id_operand_a = vlSelfRef.id_operand_a;
    }
    vlSelfRef.u_execute__DOT__ALU_ASrc = vlSelfRef.id_operand_a;
    if (((IData)(vlSelfRef.id_operand_b) ^ (IData)(vlSelfRef.__Vtogcov__id_operand_b))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 606, vlSelfRef.id_operand_b, vlSelfRef.__Vtogcov__id_operand_b);
        vlSelfRef.__Vtogcov__id_operand_b = vlSelfRef.id_operand_b;
    }
    vlSelfRef.u_execute__DOT__ALU_BSrc = vlSelfRef.id_operand_b;
    if (((IData)(vlSelfRef.id_extend_sel) ^ (IData)(vlSelfRef.__Vtogcov__id_extend_sel))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 608, vlSelfRef.id_extend_sel, vlSelfRef.__Vtogcov__id_extend_sel);
        vlSelfRef.__Vtogcov__id_extend_sel = vlSelfRef.id_extend_sel;
    }
    vlSelfRef.u_decoder__DOT__extend_sel = vlSelfRef.id_extend_sel;
    if ((vlSelfRef.id_branch_target ^ vlSelfRef.__Vtogcov__id_branch_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 210, vlSelfRef.id_branch_target, vlSelfRef.__Vtogcov__id_branch_target);
        vlSelfRef.__Vtogcov__id_branch_target = vlSelfRef.id_branch_target;
    }
    if (((IData)(vlSelfRef.u_execute__DOT__branch_op) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__branch_op))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3723, vlSelfRef.u_execute__DOT__branch_op, vlSelfRef.u_execute__DOT____Vtogcov__branch_op);
        vlSelfRef.u_execute__DOT____Vtogcov__branch_op 
            = vlSelfRef.u_execute__DOT__branch_op;
    }
    if (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__ALU_Operation))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 3435, vlSelfRef.u_execute__DOT__ALU_Operation, vlSelfRef.u_execute__DOT____Vtogcov__ALU_Operation);
        vlSelfRef.u_execute__DOT____Vtogcov__ALU_Operation 
            = vlSelfRef.u_execute__DOT__ALU_Operation;
    }
    if ((0U == (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
                 << 7U) | (IData)(vlSelfRef.u_execute__DOT__funct7)))) {
        vlSelfRef.u_execute__DOT__ALU_Control = vlSelfRef.u_execute__DOT__funct3;
        ++(vlSymsp->__Vcoverage[3876]);
    } else if ((0x20U == (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
                           << 7U) | (IData)(vlSelfRef.u_execute__DOT__funct7)))) {
        ++(vlSymsp->__Vcoverage[3875]);
        vlSelfRef.u_execute__DOT__ALU_Control = (8U 
                                                 | (IData)(vlSelfRef.u_execute__DOT__funct3));
    } else if ((0x680U == (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
                            << 0xaU) | (((IData)(vlSelfRef.u_execute__DOT__funct3) 
                                         << 7U) | (IData)(vlSelfRef.u_execute__DOT__funct7))))) {
        ++(vlSymsp->__Vcoverage[3874]);
        vlSelfRef.u_execute__DOT__ALU_Control = vlSelfRef.u_execute__DOT__funct3;
    } else if ((0x6a0U == (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
                            << 0xaU) | (((IData)(vlSelfRef.u_execute__DOT__funct3) 
                                         << 7U) | (IData)(vlSelfRef.u_execute__DOT__funct7))))) {
        ++(vlSymsp->__Vcoverage[3873]);
        vlSelfRef.u_execute__DOT__ALU_Control = (8U 
                                                 | (IData)(vlSelfRef.u_execute__DOT__funct3));
    } else if ((1U == (IData)(vlSelfRef.u_execute__DOT__ALU_Operation))) {
        ++(vlSymsp->__Vcoverage[3872]);
        vlSelfRef.u_execute__DOT__ALU_Control = vlSelfRef.u_execute__DOT__funct3;
    } else if ((2U == (IData)(vlSelfRef.u_execute__DOT__ALU_Operation))) {
        ++(vlSymsp->__Vcoverage[3871]);
        vlSelfRef.u_execute__DOT__ALU_Control = (0x10U 
                                                 | (IData)(vlSelfRef.u_execute__DOT__funct3));
    } else if ((3U == (IData)(vlSelfRef.u_execute__DOT__ALU_Operation))) {
        ++(vlSymsp->__Vcoverage[3869]);
        vlSelfRef.u_execute__DOT__ALU_Control = 0x1fU;
    } else {
        ++(vlSymsp->__Vcoverage[3870]);
        vlSelfRef.u_execute__DOT__ALU_Control = 0U;
    }
    ++(vlSymsp->__Vcoverage[3877]);
    if (((IData)(vlSelfRef.u_execute__DOT__ALU_ASrc) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__ALU_ASrc))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSymsp->__Vcoverage + 3461, vlSelfRef.u_execute__DOT__ALU_ASrc, vlSelfRef.u_execute__DOT____Vtogcov__ALU_ASrc);
        vlSelfRef.u_execute__DOT____Vtogcov__ALU_ASrc 
            = vlSelfRef.u_execute__DOT__ALU_ASrc;
    }
    if (((IData)(vlSelfRef.u_execute__DOT__ALU_BSrc) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__ALU_BSrc))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3465, vlSelfRef.u_execute__DOT__ALU_BSrc, vlSelfRef.u_execute__DOT____Vtogcov__ALU_BSrc);
        vlSelfRef.u_execute__DOT____Vtogcov__ALU_BSrc 
            = vlSelfRef.u_execute__DOT__ALU_BSrc;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__extend_sel) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__extend_sel))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 2066, vlSelfRef.u_decoder__DOT__extend_sel, vlSelfRef.u_decoder__DOT____Vtogcov__extend_sel);
        vlSelfRef.u_decoder__DOT____Vtogcov__extend_sel 
            = vlSelfRef.u_decoder__DOT__extend_sel;
    }
    vlSelfRef.u_decoder__DOT__extend_imm = ((1U == (IData)(vlSelfRef.u_decoder__DOT__extend_sel))
                                             ? ([&]() {
                ++(vlSymsp->__Vcoverage[3170]);
            }(), vlSelfRef.u_decoder__DOT__s_imm_32)
                                             : ([&]() {
                ++(vlSymsp->__Vcoverage[3177]);
            }(), ((2U == (IData)(vlSelfRef.u_decoder__DOT__extend_sel))
                   ? ([&]() {
                        ++(vlSymsp->__Vcoverage[3171]);
                    }(), vlSelfRef.u_decoder__DOT__sb_imm_32)
                   : ([&]() {
                        ++(vlSymsp->__Vcoverage[3176]);
                    }(), ((3U == (IData)(vlSelfRef.u_decoder__DOT__extend_sel))
                           ? ([&]() {
                                ++(vlSymsp->__Vcoverage[3172]);
                            }(), vlSelfRef.u_decoder__DOT__u_imm_32)
                           : ([&]() {
                                ++(vlSymsp->__Vcoverage[3175]);
                            }(), ((4U == (IData)(vlSelfRef.u_decoder__DOT__extend_sel))
                                   ? ([&]() {
                                        ++(vlSymsp->__Vcoverage[3173]);
                                    }(), vlSelfRef.u_decoder__DOT__uj_imm_32)
                                   : ([&]() {
                                        ++(vlSymsp->__Vcoverage[3174]);
                                    }(), vlSelfRef.u_decoder__DOT__i_imm_32))))))));
    if (((IData)(vlSelfRef.u_execute__DOT__ALU_Control) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__ALU_Control))) {
        VL_COV_TOGGLE_CHG_ST_I(6, vlSymsp->__Vcoverage + 3855, vlSelfRef.u_execute__DOT__ALU_Control, vlSelfRef.u_execute__DOT____Vtogcov__ALU_Control);
        vlSelfRef.u_execute__DOT____Vtogcov__ALU_Control 
            = vlSelfRef.u_execute__DOT__ALU_Control;
    }
    vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control 
        = vlSelfRef.u_execute__DOT__ALU_Control;
    if ((vlSelfRef.u_decoder__DOT__extend_imm ^ vlSelfRef.u_decoder__DOT____Vtogcov__extend_imm)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2212, vlSelfRef.u_decoder__DOT__extend_imm, vlSelfRef.u_decoder__DOT____Vtogcov__extend_imm);
        vlSelfRef.u_decoder__DOT____Vtogcov__extend_imm 
            = vlSelfRef.u_decoder__DOT__extend_imm;
    }
    vlSelfRef.id_extend_imm = vlSelfRef.u_decoder__DOT__extend_imm;
    if (((IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control) 
         ^ (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__ALU_Control))) {
        VL_COV_TOGGLE_CHG_ST_I(6, vlSymsp->__Vcoverage + 4014, vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__ALU_Control);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__ALU_Control 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control;
    }
    if ((vlSelfRef.id_extend_imm ^ vlSelfRef.__Vtogcov__id_extend_imm)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 688, vlSelfRef.id_extend_imm, vlSelfRef.__Vtogcov__id_extend_imm);
        vlSelfRef.__Vtogcov__id_extend_imm = vlSelfRef.id_extend_imm;
    }
    vlSelfRef.u_execute__DOT__extend = vlSelfRef.id_extend_imm;
    if ((vlSelfRef.u_execute__DOT__extend ^ vlSelfRef.u_execute__DOT____Vtogcov__extend)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3659, vlSelfRef.u_execute__DOT__extend, vlSelfRef.u_execute__DOT____Vtogcov__extend);
        vlSelfRef.u_execute__DOT____Vtogcov__extend 
            = vlSelfRef.u_execute__DOT__extend;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__1(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.if_pc = vlSymsp->TOP__CoreTop__u_ifu.inst_PC;
    vlSelfRef.u_dmem__DOT__gnt = vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.gnt;
    vlSelfRef.u_dmem__DOT__err = vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.err;
    vlSelfRef.u_dmem__DOT__dmem__DOT__mem_addr = (0xfffU 
                                                  & (vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.addr 
                                                     >> 2U));
    vlSelfRef.u_dmem__DOT__rack = vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.rack;
    if ((vlSelfRef.if_pc ^ vlSelfRef.__Vtogcov__if_pc)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 138, vlSelfRef.if_pc, vlSelfRef.__Vtogcov__if_pc);
        vlSelfRef.__Vtogcov__if_pc = vlSelfRef.if_pc;
    }
    if (((IData)(vlSelfRef.u_dmem__DOT__gnt) ^ (IData)(vlSelfRef.u_dmem__DOT____Vtogcov__gnt))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5149, vlSelfRef.u_dmem__DOT__gnt, vlSelfRef.u_dmem__DOT____Vtogcov__gnt);
        vlSelfRef.u_dmem__DOT____Vtogcov__gnt = vlSelfRef.u_dmem__DOT__gnt;
    }
    vlSelfRef.dmem_gnt = vlSelfRef.u_dmem__DOT__gnt;
    if (((IData)(vlSelfRef.u_dmem__DOT__err) ^ (IData)(vlSelfRef.u_dmem__DOT____Vtogcov__err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5155, vlSelfRef.u_dmem__DOT__err, vlSelfRef.u_dmem__DOT____Vtogcov__err);
        vlSelfRef.u_dmem__DOT____Vtogcov__err = vlSelfRef.u_dmem__DOT__err;
    }
    vlSelfRef.dmem_err = vlSelfRef.u_dmem__DOT__err;
    if (((IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__mem_addr) 
         ^ (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__mem_addr))) {
        VL_COV_TOGGLE_CHG_ST_I(12, vlSymsp->__Vcoverage + 5233, vlSelfRef.u_dmem__DOT__dmem__DOT__mem_addr, vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__mem_addr);
        vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__mem_addr 
            = vlSelfRef.u_dmem__DOT__dmem__DOT__mem_addr;
    }
    vlSelfRef.u_dmem__DOT__dmem__DOT__write_data = 
        vlSelfRef.u_dmem__DOT__dmem__DOT__mem[vlSelfRef.u_dmem__DOT__dmem__DOT__mem_addr];
    if ((1U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xffffff00U & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xffU & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
        ++(vlSymsp->__Vcoverage[5321]);
    } else {
        ++(vlSymsp->__Vcoverage[5322]);
    }
    ++(vlSymsp->__Vcoverage[5323]);
    if ((2U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        ++(vlSymsp->__Vcoverage[5321]);
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xffff00ffU & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xff00U & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
    } else {
        ++(vlSymsp->__Vcoverage[5322]);
    }
    ++(vlSymsp->__Vcoverage[5323]);
    if ((4U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        ++(vlSymsp->__Vcoverage[5321]);
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xff00ffffU & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xff0000U & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
    } else {
        ++(vlSymsp->__Vcoverage[5322]);
    }
    ++(vlSymsp->__Vcoverage[5323]);
    if ((8U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        ++(vlSymsp->__Vcoverage[5321]);
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xffffffU & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xff000000U & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
    } else {
        ++(vlSymsp->__Vcoverage[5322]);
    }
    ++(vlSymsp->__Vcoverage[5323]);
    ++(vlSymsp->__Vcoverage[5324]);
    if (((IData)(vlSelfRef.u_dmem__DOT__rack) ^ (IData)(vlSelfRef.u_dmem__DOT____Vtogcov__rack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5151, vlSelfRef.u_dmem__DOT__rack, vlSelfRef.u_dmem__DOT____Vtogcov__rack);
        vlSelfRef.u_dmem__DOT____Vtogcov__rack = vlSelfRef.u_dmem__DOT__rack;
    }
    vlSelfRef.dmem_rack = vlSelfRef.u_dmem__DOT__rack;
    if (((IData)(vlSelfRef.dmem_gnt) ^ (IData)(vlSelfRef.__Vtogcov__dmem_gnt))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1402, vlSelfRef.dmem_gnt, vlSelfRef.__Vtogcov__dmem_gnt);
        vlSelfRef.__Vtogcov__dmem_gnt = vlSelfRef.dmem_gnt;
    }
    if (((IData)(vlSelfRef.dmem_err) ^ (IData)(vlSelfRef.__Vtogcov__dmem_err))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1408, vlSelfRef.dmem_err, vlSelfRef.__Vtogcov__dmem_err);
        vlSelfRef.__Vtogcov__dmem_err = vlSelfRef.dmem_err;
    }
    if ((vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
         ^ vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__write_data)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5257, vlSelfRef.u_dmem__DOT__dmem__DOT__write_data, vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__write_data);
        vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__write_data 
            = vlSelfRef.u_dmem__DOT__dmem__DOT__write_data;
    }
    if (((IData)(vlSelfRef.dmem_rack) ^ (IData)(vlSelfRef.__Vtogcov__dmem_rack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1404, vlSelfRef.dmem_rack, vlSelfRef.__Vtogcov__dmem_rack);
        vlSelfRef.__Vtogcov__dmem_rack = vlSelfRef.dmem_rack;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__2(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___ico_sequent__TOP__CoreTop__2\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_2;
    // Body
    vlSelfRef.if_valid = vlSymsp->TOP__CoreTop__u_ifu.valid;
    vlSelfRef.if_instruction = vlSymsp->TOP__CoreTop__u_ifu.instruction;
    vlSelfRef.u_dmem__DOT__rdata = vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.rdata;
    if (((IData)(vlSelfRef.if_valid) ^ (IData)(vlSelfRef.__Vtogcov__if_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 202, vlSelfRef.if_valid, vlSelfRef.__Vtogcov__if_valid);
        vlSelfRef.__Vtogcov__if_valid = vlSelfRef.if_valid;
    }
    vlSelfRef.u_if_id_reg__DOT__ctrl_in = vlSelfRef.if_valid;
    if ((vlSelfRef.if_instruction ^ vlSelfRef.__Vtogcov__if_instruction)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 74, vlSelfRef.if_instruction, vlSelfRef.__Vtogcov__if_instruction);
        vlSelfRef.__Vtogcov__if_instruction = vlSelfRef.if_instruction;
    }
    vlSelfRef.u_if_id_reg__DOT__data_in = (((QData)((IData)(vlSelfRef.if_pc)) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.if_instruction)));
    if ((vlSelfRef.u_dmem__DOT__rdata ^ vlSelfRef.u_dmem__DOT____Vtogcov__rdata)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5157, vlSelfRef.u_dmem__DOT__rdata, vlSelfRef.u_dmem__DOT____Vtogcov__rdata);
        vlSelfRef.u_dmem__DOT____Vtogcov__rdata = vlSelfRef.u_dmem__DOT__rdata;
    }
    vlSelfRef.mem_rdata = vlSelfRef.u_dmem__DOT__rdata;
    if (((IData)(vlSelfRef.u_if_id_reg__DOT__ctrl_in) 
         ^ (IData)(vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_in))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1437, vlSelfRef.u_if_id_reg__DOT__ctrl_in, vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_in);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_in 
            = vlSelfRef.u_if_id_reg__DOT__ctrl_in;
    }
    if ((vlSelfRef.u_if_id_reg__DOT__data_in ^ vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_in)) {
        VL_COV_TOGGLE_CHG_ST_Q(64, vlSymsp->__Vcoverage + 1441, vlSelfRef.u_if_id_reg__DOT__data_in, vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_in);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_in 
            = vlSelfRef.u_if_id_reg__DOT__data_in;
    }
    if ((vlSelfRef.mem_rdata ^ vlSelfRef.__Vtogcov__mem_rdata)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 1338, vlSelfRef.mem_rdata, vlSelfRef.__Vtogcov__mem_rdata);
        vlSelfRef.__Vtogcov__mem_rdata = vlSelfRef.mem_rdata;
    }
    vlSelfRef.wb_write_data = ((0x800U & vlSelfRef.mem_data_out[2U])
                                ? ([&]() {
                ++(vlSymsp->__Vcoverage[1427]);
            }(), vlSelfRef.mem_rdata) : ([&]() {
                ++(vlSymsp->__Vcoverage[1428]);
            }(), vlSelfRef.mem_data_out[1U]));
    if ((vlSelfRef.wb_write_data ^ vlSelfRef.__Vtogcov__wb_write_data)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 964, vlSelfRef.wb_write_data, vlSelfRef.__Vtogcov__wb_write_data);
        vlSelfRef.__Vtogcov__wb_write_data = vlSelfRef.wb_write_data;
    }
    vlSelfRef.u_decoder__DOT__write_data = vlSelfRef.wb_write_data;
    if ((vlSelfRef.u_decoder__DOT__write_data ^ vlSelfRef.u_decoder__DOT____Vtogcov__write_data)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2084, vlSelfRef.u_decoder__DOT__write_data, vlSelfRef.u_decoder__DOT____Vtogcov__write_data);
        vlSelfRef.u_decoder__DOT____Vtogcov__write_data 
            = vlSelfRef.u_decoder__DOT__write_data;
    }
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__wdata 
        = vlSelfRef.u_decoder__DOT__write_data;
    vlSelfRef.u_decoder__DOT__rs1_data = ((IData)(vlSelfRef.u_decoder__DOT__rs1_data_bypass)
                                           ? ([&]() {
                ++(vlSymsp->__Vcoverage[3179]);
            }(), vlSelfRef.u_decoder__DOT__write_data)
                                           : ([&]() {
                ++(vlSymsp->__Vcoverage[3178]);
            }(), vlSelfRef.u_decoder__DOT__rs1_data_decode));
    vlSelfRef.u_decoder__DOT__rs2_data = ((IData)(vlSelfRef.u_decoder__DOT__rs2_data_bypass)
                                           ? ([&]() {
                ++(vlSymsp->__Vcoverage[3181]);
            }(), vlSelfRef.u_decoder__DOT__write_data)
                                           : ([&]() {
                ++(vlSymsp->__Vcoverage[3180]);
            }(), vlSelfRef.u_decoder__DOT__rs2_data_decode));
    if ((vlSelfRef.u_decoder__DOT__u_regfile__DOT__wdata 
         ^ vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__wdata)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3205, vlSelfRef.u_decoder__DOT__u_regfile__DOT__wdata, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__wdata);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__wdata 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__wdata;
    }
    if ((vlSelfRef.u_decoder__DOT__rs1_data ^ vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2276, vlSelfRef.u_decoder__DOT__rs1_data, vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data 
            = vlSelfRef.u_decoder__DOT__rs1_data;
    }
    vlSelfRef.id_rs1_data = vlSelfRef.u_decoder__DOT__rs1_data;
    if ((vlSelfRef.u_decoder__DOT__rs2_data ^ vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2340, vlSelfRef.u_decoder__DOT__rs2_data, vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data 
            = vlSelfRef.u_decoder__DOT__rs2_data;
    }
    vlSelfRef.id_rs2_data = vlSelfRef.u_decoder__DOT__rs2_data;
    if ((vlSelfRef.id_rs1_data ^ vlSelfRef.__Vtogcov__id_rs1_data)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 752, vlSelfRef.id_rs1_data, vlSelfRef.__Vtogcov__id_rs1_data);
        vlSelfRef.__Vtogcov__id_rs1_data = vlSelfRef.id_rs1_data;
    }
    vlSelfRef.u_execute__DOT__regRead_1 = vlSelfRef.id_rs1_data;
    if ((vlSelfRef.id_rs2_data ^ vlSelfRef.__Vtogcov__id_rs2_data)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 816, vlSelfRef.id_rs2_data, vlSelfRef.__Vtogcov__id_rs2_data);
        vlSelfRef.__Vtogcov__id_rs2_data = vlSelfRef.id_rs2_data;
    }
    vlSelfRef.u_execute__DOT__regRead_2 = vlSelfRef.id_rs2_data;
    if ((vlSelfRef.u_execute__DOT__regRead_1 ^ vlSelfRef.u_execute__DOT____Vtogcov__regRead_1)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3531, vlSelfRef.u_execute__DOT__regRead_1, vlSelfRef.u_execute__DOT____Vtogcov__regRead_1);
        vlSelfRef.u_execute__DOT____Vtogcov__regRead_1 
            = vlSelfRef.u_execute__DOT__regRead_1;
    }
    vlSelfRef.u_execute__DOT__JALR_target = (0xfffffffeU 
                                             & (vlSelfRef.u_execute__DOT__extend 
                                                + vlSelfRef.u_execute__DOT__regRead_1));
    vlSelfRef.u_execute__DOT__alu_in_a = ((1U == (IData)(vlSelfRef.u_execute__DOT__ALU_ASrc))
                                           ? ([&]() {
                ++(vlSymsp->__Vcoverage[4006]);
            }(), vlSelfRef.u_execute__DOT__PC) : ([&]() {
                ++(vlSymsp->__Vcoverage[4011]);
            }(), ((2U == (IData)(vlSelfRef.u_execute__DOT__ALU_ASrc))
                   ? ([&]() {
                        ++(vlSymsp->__Vcoverage[4007]);
                    }(), ((IData)(4U) + vlSelfRef.u_execute__DOT__PC))
                   : ([&]() {
                        ++(vlSymsp->__Vcoverage[4010]);
                    }(), ((3U == (IData)(vlSelfRef.u_execute__DOT__ALU_ASrc))
                           ? ([&]() {
                                ++(vlSymsp->__Vcoverage[4008]);
                            }(), 0U) : ([&]() {
                                ++(vlSymsp->__Vcoverage[4009]);
                            }(), vlSelfRef.u_execute__DOT__regRead_1))))));
    if ((vlSelfRef.u_execute__DOT__regRead_2 ^ vlSelfRef.u_execute__DOT____Vtogcov__regRead_2)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3595, vlSelfRef.u_execute__DOT__regRead_2, vlSelfRef.u_execute__DOT____Vtogcov__regRead_2);
        vlSelfRef.u_execute__DOT____Vtogcov__regRead_2 
            = vlSelfRef.u_execute__DOT__regRead_2;
    }
    vlSelfRef.u_execute__DOT__alu_in_b = ((IData)(vlSelfRef.u_execute__DOT__ALU_BSrc)
                                           ? ([&]() {
                ++(vlSymsp->__Vcoverage[4012]);
            }(), vlSelfRef.u_execute__DOT__extend) : 
                                          ([&]() {
                ++(vlSymsp->__Vcoverage[4013]);
            }(), vlSelfRef.u_execute__DOT__regRead_2));
    if ((vlSelfRef.u_execute__DOT__JALR_target ^ vlSelfRef.u_execute__DOT____Vtogcov__JALR_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3791, vlSelfRef.u_execute__DOT__JALR_target, vlSelfRef.u_execute__DOT____Vtogcov__JALR_target);
        vlSelfRef.u_execute__DOT____Vtogcov__JALR_target 
            = vlSelfRef.u_execute__DOT__JALR_target;
    }
    vlSelfRef.ex_jalr_target = vlSelfRef.u_execute__DOT__JALR_target;
    if ((vlSelfRef.u_execute__DOT__alu_in_a ^ vlSelfRef.u_execute__DOT____Vtogcov__alu_in_a)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3878, vlSelfRef.u_execute__DOT__alu_in_a, vlSelfRef.u_execute__DOT____Vtogcov__alu_in_a);
        vlSelfRef.u_execute__DOT____Vtogcov__alu_in_a 
            = vlSelfRef.u_execute__DOT__alu_in_a;
    }
    vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
        = vlSelfRef.u_execute__DOT__alu_in_a;
    if ((vlSelfRef.u_execute__DOT__alu_in_b ^ vlSelfRef.u_execute__DOT____Vtogcov__alu_in_b)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3942, vlSelfRef.u_execute__DOT__alu_in_b, vlSelfRef.u_execute__DOT____Vtogcov__alu_in_b);
        vlSelfRef.u_execute__DOT____Vtogcov__alu_in_b 
            = vlSelfRef.u_execute__DOT__alu_in_b;
    }
    vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b 
        = vlSelfRef.u_execute__DOT__alu_in_b;
    if ((vlSelfRef.ex_jalr_target ^ vlSelfRef.__Vtogcov__ex_jalr_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 338, vlSelfRef.ex_jalr_target, vlSelfRef.__Vtogcov__ex_jalr_target);
        vlSelfRef.__Vtogcov__ex_jalr_target = vlSelfRef.ex_jalr_target;
    }
    if ((vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
         ^ vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__alu_in_a)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 4026, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__alu_in_a);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__alu_in_a 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a;
    }
    if ((vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b 
         ^ vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__alu_in_b)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 4090, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__alu_in_b);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__alu_in_b 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b;
    }
    vlSelfRef.u_execute__DOT__u_alu__DOT__signed_greater_than_equal 
        = VL_GTES_III(32, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b);
    vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than 
        = VL_LTS_III(32, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b);
    vlSelfRef.u_execute__DOT__u_alu__DOT__unsigned_less_than 
        = (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
           < vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b);
    vlSelfRef.u_execute__DOT__u_alu__DOT__shamt = (0x1fU 
                                                   & vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b);
    if ((vlSelfRef.u_execute__DOT__u_alu__DOT__signed_greater_than_equal 
         ^ vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__signed_greater_than_equal)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 4422, vlSelfRef.u_execute__DOT__u_alu__DOT__signed_greater_than_equal, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__signed_greater_than_equal);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__signed_greater_than_equal 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__signed_greater_than_equal;
    }
    if ((vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than 
         ^ vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__signed_less_than)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 4294, vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__signed_less_than);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__signed_less_than 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than;
    }
    if ((vlSelfRef.u_execute__DOT__u_alu__DOT__unsigned_less_than 
         ^ vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__unsigned_less_than)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 4358, vlSelfRef.u_execute__DOT__u_alu__DOT__unsigned_less_than, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__unsigned_less_than);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__unsigned_less_than 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__unsigned_less_than;
    }
    if (((IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__shamt) 
         ^ (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__shamt))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 4220, vlSelfRef.u_execute__DOT__u_alu__DOT__shamt, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__shamt);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__shamt 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__shamt;
    }
    vlSelfRef.u_execute__DOT__u_alu__DOT__arithmetic_right_shift 
        = VL_SHIFTRS_III(32,32,5, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a, (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__shamt));
    if ((vlSelfRef.u_execute__DOT__u_alu__DOT__arithmetic_right_shift 
         ^ vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__arithmetic_right_shift)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 4230, vlSelfRef.u_execute__DOT__u_alu__DOT__arithmetic_right_shift, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__arithmetic_right_shift);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__arithmetic_right_shift 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__arithmetic_right_shift;
    }
    vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_result 
        = ((0U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
            ? ([&]() {
                ++(vlSymsp->__Vcoverage[4486]);
            }(), (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                  + vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
            : ([&]() {
                ++(vlSymsp->__Vcoverage[4519]);
            }(), ((8U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                   ? ([&]() {
                        ++(vlSymsp->__Vcoverage[4487]);
                    }(), (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                          - vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                   : ([&]() {
                        ++(vlSymsp->__Vcoverage[4518]);
                    }(), ((4U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                           ? ([&]() {
                                ++(vlSymsp->__Vcoverage[4488]);
                            }(), (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                  ^ vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                           : ([&]() {
                                ++(vlSymsp->__Vcoverage[4517]);
                            }(), ((6U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                   ? ([&]() {
                                        ++(vlSymsp->__Vcoverage[4489]);
                                    }(), (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                          | vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                   : ([&]() {
                                        ++(vlSymsp->__Vcoverage[4516]);
                                    }(), ((7U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                           ? ([&]() {
                                                ++(vlSymsp->__Vcoverage[4490]);
                                            }(), (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                  & vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                           : ([&]() {
                                                ++(vlSymsp->__Vcoverage[4515]);
                                            }(), ((2U 
                                                   == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                   ? 
                                                  ([&]() {
                                                        ++(vlSymsp->__Vcoverage[4491]);
                                                    }(), vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than)
                                                   : 
                                                  ([&]() {
                                                        ++(vlSymsp->__Vcoverage[4514]);
                                                    }(), 
                                                   ((3U 
                                                     == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                     ? 
                                                    ([&]() {
                                                                ++(vlSymsp->__Vcoverage[4492]);
                                                            }(), vlSelfRef.u_execute__DOT__u_alu__DOT__unsigned_less_than)
                                                     : 
                                                    ([&]() {
                                                                ++(vlSymsp->__Vcoverage[4513]);
                                                            }(), 
                                                     ((1U 
                                                       == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                       ? 
                                                      ([&]() {
                                                                        ++(vlSymsp->__Vcoverage[4493]);
                                                                    }(), 
                                                       (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                        << (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__shamt)))
                                                       : 
                                                      ([&]() {
                                                                        ++(vlSymsp->__Vcoverage[4512]);
                                                                    }(), 
                                                       ((5U 
                                                         == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                         ? 
                                                        ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4494]);
                                                                            }(), 
                                                         (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                          >> (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__shamt)))
                                                         : 
                                                        ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4511]);
                                                                            }(), 
                                                         ((0xdU 
                                                           == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                           ? 
                                                          ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4495]);
                                                                                }(), vlSelfRef.u_execute__DOT__u_alu__DOT__arithmetic_right_shift)
                                                           : 
                                                          ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4510]);
                                                                                }(), 
                                                           ((0x1fU 
                                                             == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                             ? 
                                                            ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4496]);
                                                                                }(), vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a)
                                                             : 
                                                            ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4509]);
                                                                                }(), 
                                                             ((0x10U 
                                                               == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                               ? 
                                                              ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4497]);
                                                                                }(), 
                                                               (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                                == vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                                               : 
                                                              ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4508]);
                                                                                }(), 
                                                               ((0x11U 
                                                                 == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                                 ? 
                                                                ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4498]);
                                                                                }(), 
                                                                 (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                                  != vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                                                 : 
                                                                ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4507]);
                                                                                }(), 
                                                                 ((0x14U 
                                                                   == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                                   ? 
                                                                  ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4499]);
                                                                                }(), vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than)
                                                                   : 
                                                                  ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4506]);
                                                                                }(), 
                                                                   ((0x15U 
                                                                     == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                                     ? 
                                                                    ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4500]);
                                                                                }(), vlSelfRef.u_execute__DOT__u_alu__DOT__signed_greater_than_equal)
                                                                     : 
                                                                    ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4505]);
                                                                                }(), 
                                                                     ((0x16U 
                                                                       == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                                       ? 
                                                                      ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4501]);
                                                                                }(), 
                                                                       (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                                        < vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                                                       : 
                                                                      ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4504]);
                                                                                }(), 
                                                                       ((0x17U 
                                                                         == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                                         ? 
                                                                        ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4502]);
                                                                                }(), 
                                                                         (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                                          >= vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                                                         : 
                                                                        ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4503]);
                                                                                }(), 0U))))))))))))))))))))))))))))))))));
    if ((vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_result 
         ^ vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__ALU_result)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 4154, vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_result, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__ALU_result);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__ALU_result 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_result;
    }
    vlSelfRef.u_execute__DOT__u_alu__DOT__cmp_out = 
        (1U & vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_result);
    vlSelfRef.u_execute__DOT__ALU_result = vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_result;
    if (((IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__cmp_out) 
         ^ (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__cmp_out))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4218, vlSelfRef.u_execute__DOT__u_alu__DOT__cmp_out, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__cmp_out);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__cmp_out 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__cmp_out;
    }
    vlSelfRef.u_execute__DOT__alu_cmp_out = vlSelfRef.u_execute__DOT__u_alu__DOT__cmp_out;
    if ((vlSelfRef.u_execute__DOT__ALU_result ^ vlSelfRef.u_execute__DOT____Vtogcov__ALU_result)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3725, vlSelfRef.u_execute__DOT__ALU_result, vlSelfRef.u_execute__DOT____Vtogcov__ALU_result);
        vlSelfRef.u_execute__DOT____Vtogcov__ALU_result 
            = vlSelfRef.u_execute__DOT__ALU_result;
    }
    vlSelfRef.ex_alu_result = vlSelfRef.u_execute__DOT__ALU_result;
    if (((IData)(vlSelfRef.u_execute__DOT__alu_cmp_out) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__alu_cmp_out))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3867, vlSelfRef.u_execute__DOT__alu_cmp_out, vlSelfRef.u_execute__DOT____Vtogcov__alu_cmp_out);
        vlSelfRef.u_execute__DOT____Vtogcov__alu_cmp_out 
            = vlSelfRef.u_execute__DOT__alu_cmp_out;
    }
    vlSelfRef.u_execute__DOT__branch_taken = ((IData)(vlSelfRef.u_execute__DOT__alu_cmp_out) 
                                              & (IData)(vlSelfRef.u_execute__DOT__branch_op));
    if ((vlSelfRef.ex_alu_result ^ vlSelfRef.__Vtogcov__ex_alu_result)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 888, vlSelfRef.ex_alu_result, vlSelfRef.__Vtogcov__ex_alu_result);
        vlSelfRef.__Vtogcov__ex_alu_result = vlSelfRef.ex_alu_result;
    }
    vlSelfRef.id_ex_data_in[0U] = (IData)((((QData)((IData)(vlSelfRef.ex_alu_result)) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.id_rs2_data))));
    vlSelfRef.id_ex_data_in[1U] = (IData)(((((QData)((IData)(vlSelfRef.ex_alu_result)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSelfRef.id_rs2_data))) 
                                           >> 0x20U));
    vlSelfRef.id_ex_data_in[2U] = ((0x1e00U & vlSelfRef.id_ex_data_in[2U]) 
                                   | (0x1fffU & (((IData)(vlSelfRef.id_mem_wbe) 
                                                  << 5U) 
                                                 | (IData)(vlSelfRef.id_rd))));
    if (((IData)(vlSelfRef.u_execute__DOT__branch_taken) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__branch_taken))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3789, vlSelfRef.u_execute__DOT__branch_taken, vlSelfRef.u_execute__DOT____Vtogcov__branch_taken);
        vlSelfRef.u_execute__DOT____Vtogcov__branch_taken 
            = vlSelfRef.u_execute__DOT__branch_taken;
    }
    vlSelfRef.ex_branch_taken = vlSelfRef.u_execute__DOT__branch_taken;
    vlSelfRef.u_ex_mem_reg__DOT__data_in[0U] = vlSelfRef.id_ex_data_in[0U];
    vlSelfRef.u_ex_mem_reg__DOT__data_in[1U] = vlSelfRef.id_ex_data_in[1U];
    vlSelfRef.u_ex_mem_reg__DOT__data_in[2U] = vlSelfRef.id_ex_data_in[2U];
    if ((0x1000U & (vlSelfRef.id_ex_data_in[2U] ^ vlSelfRef.__Vtogcov__id_ex_data_in[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1030, 
                               (vlSelfRef.id_ex_data_in[2U] 
                                >> 0xcU), (vlSelfRef.__Vtogcov__id_ex_data_in[2U] 
                                           >> 0xcU));
        vlSelfRef.__Vtogcov__id_ex_data_in[2U] = ((0xfffU 
                                                   & vlSelfRef.__Vtogcov__id_ex_data_in[2U]) 
                                                  | (0x1000U 
                                                     & vlSelfRef.id_ex_data_in[2U]));
    }
    if ((0x800U & (vlSelfRef.id_ex_data_in[2U] ^ vlSelfRef.__Vtogcov__id_ex_data_in[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1032, 
                               (vlSelfRef.id_ex_data_in[2U] 
                                >> 0xbU), (vlSelfRef.__Vtogcov__id_ex_data_in[2U] 
                                           >> 0xbU));
        vlSelfRef.__Vtogcov__id_ex_data_in[2U] = ((0x17ffU 
                                                   & vlSelfRef.__Vtogcov__id_ex_data_in[2U]) 
                                                  | (0x800U 
                                                     & vlSelfRef.id_ex_data_in[2U]));
    }
    if ((0x400U & (vlSelfRef.id_ex_data_in[2U] ^ vlSelfRef.__Vtogcov__id_ex_data_in[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1034, 
                               (vlSelfRef.id_ex_data_in[2U] 
                                >> 0xaU), (vlSelfRef.__Vtogcov__id_ex_data_in[2U] 
                                           >> 0xaU));
        vlSelfRef.__Vtogcov__id_ex_data_in[2U] = ((0x1bffU 
                                                   & vlSelfRef.__Vtogcov__id_ex_data_in[2U]) 
                                                  | (0x400U 
                                                     & vlSelfRef.id_ex_data_in[2U]));
    }
    if ((0x200U & (vlSelfRef.id_ex_data_in[2U] ^ vlSelfRef.__Vtogcov__id_ex_data_in[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1036, 
                               (vlSelfRef.id_ex_data_in[2U] 
                                >> 9U), (vlSelfRef.__Vtogcov__id_ex_data_in[2U] 
                                         >> 9U));
        vlSelfRef.__Vtogcov__id_ex_data_in[2U] = ((0x1dffU 
                                                   & vlSelfRef.__Vtogcov__id_ex_data_in[2U]) 
                                                  | (0x200U 
                                                     & vlSelfRef.id_ex_data_in[2U]));
    }
    if ((0xfU & (((vlSelfRef.id_ex_data_in[2U] << 0x1bU) 
                  | (vlSelfRef.id_ex_data_in[2U] >> 5U)) 
                 ^ ((vlSelfRef.__Vtogcov__id_ex_data_in[2U] 
                     << 0x1bU) | (vlSelfRef.__Vtogcov__id_ex_data_in[2U] 
                                  >> 5U))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSymsp->__Vcoverage + 1038, 
                               ((vlSelfRef.id_ex_data_in[2U] 
                                 << 0x1bU) | (vlSelfRef.id_ex_data_in[2U] 
                                              >> 5U)), 
                               ((vlSelfRef.__Vtogcov__id_ex_data_in[2U] 
                                 << 0x1bU) | (vlSelfRef.__Vtogcov__id_ex_data_in[2U] 
                                              >> 5U)));
        vlSelfRef.__Vtogcov__id_ex_data_in[2U] = ((0x1e1fU 
                                                   & vlSelfRef.__Vtogcov__id_ex_data_in[2U]) 
                                                  | (0x1e0U 
                                                     & vlSelfRef.id_ex_data_in[2U]));
    }
    if ((0x1fU & (vlSelfRef.id_ex_data_in[2U] ^ vlSelfRef.__Vtogcov__id_ex_data_in[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 1046, 
                               vlSelfRef.id_ex_data_in[2U], 
                               vlSelfRef.__Vtogcov__id_ex_data_in[2U]);
        vlSelfRef.__Vtogcov__id_ex_data_in[2U] = ((0x1fe0U 
                                                   & vlSelfRef.__Vtogcov__id_ex_data_in[2U]) 
                                                  | (0x1fU 
                                                     & vlSelfRef.id_ex_data_in[2U]));
    }
    if ((vlSelfRef.id_ex_data_in[1U] ^ vlSelfRef.__Vtogcov__id_ex_data_in[1U])) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 1056, 
                               vlSelfRef.id_ex_data_in[1U], 
                               vlSelfRef.__Vtogcov__id_ex_data_in[1U]);
        vlSelfRef.__Vtogcov__id_ex_data_in[1U] = vlSelfRef.id_ex_data_in[1U];
    }
    if ((vlSelfRef.id_ex_data_in[0U] ^ vlSelfRef.__Vtogcov__id_ex_data_in[0U])) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 1120, 
                               vlSelfRef.id_ex_data_in[0U], 
                               vlSelfRef.__Vtogcov__id_ex_data_in[0U]);
        vlSelfRef.__Vtogcov__id_ex_data_in[0U] = vlSelfRef.id_ex_data_in[0U];
    }
    if (((IData)(vlSelfRef.ex_branch_taken) ^ (IData)(vlSelfRef.__Vtogcov__ex_branch_taken))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 208, vlSelfRef.ex_branch_taken, vlSelfRef.__Vtogcov__ex_branch_taken);
        vlSelfRef.__Vtogcov__ex_branch_taken = vlSelfRef.ex_branch_taken;
    }
    vlSelfRef.flush = (((1U == (IData)(vlSelfRef.id_pc_sel)) 
                        & (IData)(vlSelfRef.ex_branch_taken)) 
                       | ((2U == (IData)(vlSelfRef.id_pc_sel)) 
                          | (3U == (IData)(vlSelfRef.id_pc_sel))));
    __Vtemp_2[0U] = (vlSelfRef.u_ex_mem_reg__DOT__data_in[0U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_in[0U]);
    __Vtemp_2[1U] = (vlSelfRef.u_ex_mem_reg__DOT__data_in[1U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_in[1U]);
    __Vtemp_2[2U] = (vlSelfRef.u_ex_mem_reg__DOT__data_in[2U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_in[2U]);
    if (__Vtemp_2) {
        VL_COV_TOGGLE_CHG_ST_W(77, vlSymsp->__Vcoverage + 4532, vlSelfRef.u_ex_mem_reg__DOT__data_in, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_in);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_in[0U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_in[0U];
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_in[1U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_in[1U];
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_in[2U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_in[2U];
    }
    if (((IData)(vlSelfRef.flush) ^ (IData)(vlSelfRef.__Vtogcov__flush))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 72, vlSelfRef.flush, vlSelfRef.__Vtogcov__flush);
        vlSelfRef.__Vtogcov__flush = vlSelfRef.flush;
    }
    vlSelfRef.real_if_id_flush = ((IData)(vlSelfRef.flush) 
                                  | (IData)(vlSelfRef.flush_d));
    if (((IData)(vlSelfRef.real_if_id_flush) ^ (IData)(vlSelfRef.__Vtogcov__real_if_id_flush))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1412, vlSelfRef.real_if_id_flush, vlSelfRef.__Vtogcov__real_if_id_flush);
        vlSelfRef.__Vtogcov__real_if_id_flush = vlSelfRef.real_if_id_flush;
    }
    vlSelfRef.u_if_id_reg__DOT__flush = vlSelfRef.real_if_id_flush;
    if (((IData)(vlSelfRef.u_if_id_reg__DOT__flush) 
         ^ (IData)(vlSelfRef.u_if_id_reg__DOT____Vtogcov__flush))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1433, vlSelfRef.u_if_id_reg__DOT__flush, vlSelfRef.u_if_id_reg__DOT____Vtogcov__flush);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__flush 
            = vlSelfRef.u_if_id_reg__DOT__flush;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__0(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.if_pc = vlSymsp->TOP__CoreTop__u_ifu.inst_PC;
    if ((vlSelfRef.if_pc ^ vlSelfRef.__Vtogcov__if_pc)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 138, vlSelfRef.if_pc, vlSelfRef.__Vtogcov__if_pc);
        vlSelfRef.__Vtogcov__if_pc = vlSelfRef.if_pc;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__2(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__2\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VdlyVal__u_dmem__DOT__dmem__DOT__mem__v0;
    __VdlyVal__u_dmem__DOT__dmem__DOT__mem__v0 = 0;
    SData/*11:0*/ __VdlyDim0__u_dmem__DOT__dmem__DOT__mem__v0;
    __VdlyDim0__u_dmem__DOT__dmem__DOT__mem__v0 = 0;
    // Body
    if (vlSelfRef.u_dmem__DOT__dmem__DOT__rst) {
        ++(vlSymsp->__Vcoverage[5333]);
        vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wack = 0U;
    } else {
        if (((IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.write) 
             & (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__gnt))) {
            ++(vlSymsp->__Vcoverage[5325]);
            __VdlyVal__u_dmem__DOT__dmem__DOT__mem__v0 
                = vlSelfRef.u_dmem__DOT__dmem__DOT__write_data;
            __VdlyDim0__u_dmem__DOT__dmem__DOT__mem__v0 
                = vlSelfRef.u_dmem__DOT__dmem__DOT__mem_addr;
            vlSelfRef.__VdlySet__u_dmem__DOT__dmem__DOT__mem__v0 = 1U;
        } else {
            ++(vlSymsp->__Vcoverage[5326]);
        }
        vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wack 
            = ((IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.write) 
               & (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__gnt));
        if (((IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.write) 
             & (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__gnt))) {
            ++(vlSymsp->__Vcoverage[5327]);
        }
        if ((1U & (~ (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__gnt)))) {
            ++(vlSymsp->__Vcoverage[5328]);
        }
        if ((1U & (~ (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.write)))) {
            ++(vlSymsp->__Vcoverage[5329]);
        }
        if (((IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.write) 
             & (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__gnt))) {
            ++(vlSymsp->__Vcoverage[5330]);
        }
        if ((1U & (~ (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__gnt)))) {
            ++(vlSymsp->__Vcoverage[5331]);
        }
        if ((1U & (~ (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.write)))) {
            ++(vlSymsp->__Vcoverage[5332]);
        }
        ++(vlSymsp->__Vcoverage[5334]);
    }
    ++(vlSymsp->__Vcoverage[5335]);
    if (vlSelfRef.__VdlySet__u_dmem__DOT__dmem__DOT__mem__v0) {
        vlSelfRef.u_dmem__DOT__dmem__DOT__mem[__VdlyDim0__u_dmem__DOT__dmem__DOT__mem__v0] 
            = __VdlyVal__u_dmem__DOT__dmem__DOT__mem__v0;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__3(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__3\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_dmem__DOT__wack = vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wack;
    if (((IData)(vlSelfRef.u_dmem__DOT__wack) ^ (IData)(vlSelfRef.u_dmem__DOT____Vtogcov__wack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5153, vlSelfRef.u_dmem__DOT__wack, vlSelfRef.u_dmem__DOT____Vtogcov__wack);
        vlSelfRef.u_dmem__DOT____Vtogcov__wack = vlSelfRef.u_dmem__DOT__wack;
    }
    vlSelfRef.dmem_wack = vlSelfRef.u_dmem__DOT__wack;
    if (((IData)(vlSelfRef.dmem_wack) ^ (IData)(vlSelfRef.__Vtogcov__dmem_wack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1406, vlSelfRef.dmem_wack, vlSelfRef.__Vtogcov__dmem_wack);
        vlSelfRef.__Vtogcov__dmem_wack = vlSelfRef.dmem_wack;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__4(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__4\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v0;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v0 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v1;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v1 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v2;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v2 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v3;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v3 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v4;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v4 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v5;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v5 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v6;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v6 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v7;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v7 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v8;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v8 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v9;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v9 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v10;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v10 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v11;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v11 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v12;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v12 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v13;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v13 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v14;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v14 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v15;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v15 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v16;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v16 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v17;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v17 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v18;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v18 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v19;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v19 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v20;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v20 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v21;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v21 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v22;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v22 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v23;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v23 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v24;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v24 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v25;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v25 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v26;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v26 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v27;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v27 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v28;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v28 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v29;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v29 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v30;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v30 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v31;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v31 = 0;
    IData/*31:0*/ __VdlyVal__u_decoder__DOT__u_regfile__DOT__regs__v32;
    __VdlyVal__u_decoder__DOT__u_regfile__DOT__regs__v32 = 0;
    CData/*4:0*/ __VdlyDim0__u_decoder__DOT__u_regfile__DOT__regs__v32;
    __VdlyDim0__u_decoder__DOT__u_regfile__DOT__regs__v32 = 0;
    CData/*0:0*/ __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v32;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v32 = 0;
    // Body
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v0 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v1 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v2 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v3 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v4 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v5 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v6 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v7 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v8 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v9 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v10 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v11 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v12 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v13 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v14 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v15 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v16 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v17 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v18 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v19 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v20 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v21 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v22 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v23 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v24 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v25 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v26 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v27 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v28 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v29 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v30 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v31 = 0U;
    __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v32 = 0U;
    if (vlSelfRef.u_decoder__DOT__u_regfile__DOT__rst) {
        ++(vlSymsp->__Vcoverage[3421]);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0U;
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v0 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 1U;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v1 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 2U;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v2 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 3U;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v3 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 4U;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v4 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 5U;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v5 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 6U;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v6 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 7U;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v7 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 8U;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v8 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 9U;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v9 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0xaU;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v10 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0xbU;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v11 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0xcU;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v12 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0xdU;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v13 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0xeU;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v14 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0xfU;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v15 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x10U;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v16 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x11U;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v17 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x12U;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v18 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x13U;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v19 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x14U;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v20 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x15U;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v21 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x16U;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v22 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x17U;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v23 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x18U;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v24 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x19U;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v25 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x1aU;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v26 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x1bU;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v27 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x1cU;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v28 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x1dU;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v29 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x1eU;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v30 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x1fU;
        ++(vlSymsp->__Vcoverage[3421]);
        __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v31 = 1U;
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__unnamedblk1__DOT__i = 0x20U;
        ++(vlSymsp->__Vcoverage[3427]);
    } else {
        if (((~ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__rst)) 
             & (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen))) {
            ++(vlSymsp->__Vcoverage[3422]);
            __VdlyVal__u_decoder__DOT__u_regfile__DOT__regs__v32 
                = vlSelfRef.u_decoder__DOT__u_regfile__DOT__wdata;
            __VdlyDim0__u_decoder__DOT__u_regfile__DOT__regs__v32 
                = vlSelfRef.u_decoder__DOT__u_regfile__DOT__waddr;
            __VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v32 = 1U;
        } else {
            ++(vlSymsp->__Vcoverage[3423]);
        }
        if (((~ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__rst)) 
             & (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen))) {
            ++(vlSymsp->__Vcoverage[3424]);
        }
        if ((1U & (~ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen)))) {
            ++(vlSymsp->__Vcoverage[3425]);
        }
        if (vlSelfRef.u_decoder__DOT__u_regfile__DOT__rst) {
            ++(vlSymsp->__Vcoverage[3426]);
        }
    }
    ++(vlSymsp->__Vcoverage[3428]);
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v0) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v1) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[1U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v2) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[2U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v3) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[3U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v4) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[4U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v5) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[5U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v6) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[6U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v7) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[7U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v8) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[8U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v9) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[9U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v10) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0xaU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v11) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0xbU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v12) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0xcU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v13) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0xdU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v14) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0xeU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v15) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0xfU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v16) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x10U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v17) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x11U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v18) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x12U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v19) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x13U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v20) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x14U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v21) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x15U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v22) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x16U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v23) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x17U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v24) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x18U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v25) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x19U] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v26) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x1aU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v27) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x1bU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v28) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x1cU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v29) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x1dU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v30) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x1eU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v31) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[0x1fU] = 0U;
    }
    if (__VdlySet__u_decoder__DOT__u_regfile__DOT__regs__v32) {
        vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs[__VdlyDim0__u_decoder__DOT__u_regfile__DOT__regs__v32] 
            = __VdlyVal__u_decoder__DOT__u_regfile__DOT__regs__v32;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__5(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__5\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.rst) {
        ++(vlSymsp->__Vcoverage[1414]);
        vlSelfRef.flush_d = 0U;
    } else {
        ++(vlSymsp->__Vcoverage[1415]);
        vlSelfRef.flush_d = vlSelfRef.flush;
    }
    ++(vlSymsp->__Vcoverage[1416]);
    if (((IData)(vlSelfRef.flush_d) ^ (IData)(vlSelfRef.__Vtogcov__flush_d))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1410, vlSelfRef.flush_d, vlSelfRef.__Vtogcov__flush_d);
        vlSelfRef.__Vtogcov__flush_d = vlSelfRef.flush_d;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__6(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__6\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.if_valid = vlSymsp->TOP__CoreTop__u_ifu.valid;
    vlSelfRef.if_instruction = vlSymsp->TOP__CoreTop__u_ifu.instruction;
    if (((IData)(vlSelfRef.if_valid) ^ (IData)(vlSelfRef.__Vtogcov__if_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 202, vlSelfRef.if_valid, vlSelfRef.__Vtogcov__if_valid);
        vlSelfRef.__Vtogcov__if_valid = vlSelfRef.if_valid;
    }
    if ((vlSelfRef.if_instruction ^ vlSelfRef.__Vtogcov__if_instruction)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 74, vlSelfRef.if_instruction, vlSelfRef.__Vtogcov__if_instruction);
        vlSelfRef.__Vtogcov__if_instruction = vlSelfRef.if_instruction;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__7(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__7\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_1;
    VlWide<3>/*95:0*/ __Vtemp_2;
    // Body
    if (vlSelfRef.u_ex_mem_reg__DOT__rst) {
        ++(vlSymsp->__Vcoverage[4999]);
        vlSelfRef.u_ex_mem_reg__DOT__ctrl_q = 0U;
    } else {
        if (vlSelfRef.u_ex_mem_reg__DOT__flush) {
            ++(vlSymsp->__Vcoverage[4998]);
            vlSelfRef.u_ex_mem_reg__DOT__ctrl_q = 0U;
        } else if (vlSelfRef.u_ex_mem_reg__DOT__en) {
            ++(vlSymsp->__Vcoverage[4996]);
            vlSelfRef.u_ex_mem_reg__DOT__ctrl_q = vlSelfRef.u_ex_mem_reg__DOT__ctrl_in;
        } else {
            ++(vlSymsp->__Vcoverage[4997]);
        }
        ++(vlSymsp->__Vcoverage[5000]);
    }
    ++(vlSymsp->__Vcoverage[5001]);
    if (vlSelfRef.u_ex_mem_reg__DOT__en) {
        ++(vlSymsp->__Vcoverage[5002]);
        vlSelfRef.u_ex_mem_reg__DOT__data_q[0U] = vlSelfRef.u_ex_mem_reg__DOT__data_in[0U];
        vlSelfRef.u_ex_mem_reg__DOT__data_q[1U] = vlSelfRef.u_ex_mem_reg__DOT__data_in[1U];
        vlSelfRef.u_ex_mem_reg__DOT__data_q[2U] = vlSelfRef.u_ex_mem_reg__DOT__data_in[2U];
    } else {
        ++(vlSymsp->__Vcoverage[5003]);
    }
    ++(vlSymsp->__Vcoverage[5004]);
    if (((IData)(vlSelfRef.u_ex_mem_reg__DOT__ctrl_q) 
         ^ (IData)(vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4840, vlSelfRef.u_ex_mem_reg__DOT__ctrl_q, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_q);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_q 
            = vlSelfRef.u_ex_mem_reg__DOT__ctrl_q;
    }
    vlSelfRef.u_ex_mem_reg__DOT__ctrl_out = vlSelfRef.u_ex_mem_reg__DOT__ctrl_q;
    __Vtemp_1[0U] = (vlSelfRef.u_ex_mem_reg__DOT__data_q[0U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q[0U]);
    __Vtemp_1[1U] = (vlSelfRef.u_ex_mem_reg__DOT__data_q[1U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q[1U]);
    __Vtemp_1[2U] = (vlSelfRef.u_ex_mem_reg__DOT__data_q[2U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q[2U]);
    if (__Vtemp_1) {
        VL_COV_TOGGLE_CHG_ST_W(77, vlSymsp->__Vcoverage + 4842, vlSelfRef.u_ex_mem_reg__DOT__data_q, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q[0U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_q[0U];
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q[1U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_q[1U];
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_q[2U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_q[2U];
    }
    vlSelfRef.u_ex_mem_reg__DOT__data_out[0U] = vlSelfRef.u_ex_mem_reg__DOT__data_q[0U];
    vlSelfRef.u_ex_mem_reg__DOT__data_out[1U] = vlSelfRef.u_ex_mem_reg__DOT__data_q[1U];
    vlSelfRef.u_ex_mem_reg__DOT__data_out[2U] = vlSelfRef.u_ex_mem_reg__DOT__data_q[2U];
    if (((IData)(vlSelfRef.u_ex_mem_reg__DOT__ctrl_out) 
         ^ (IData)(vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_out))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4530, vlSelfRef.u_ex_mem_reg__DOT__ctrl_out, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_out);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_out 
            = vlSelfRef.u_ex_mem_reg__DOT__ctrl_out;
    }
    vlSelfRef.mem_ctrl_out = vlSelfRef.u_ex_mem_reg__DOT__ctrl_out;
    __Vtemp_2[0U] = (vlSelfRef.u_ex_mem_reg__DOT__data_out[0U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out[0U]);
    __Vtemp_2[1U] = (vlSelfRef.u_ex_mem_reg__DOT__data_out[1U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out[1U]);
    __Vtemp_2[2U] = (vlSelfRef.u_ex_mem_reg__DOT__data_out[2U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out[2U]);
    if (__Vtemp_2) {
        VL_COV_TOGGLE_CHG_ST_W(77, vlSymsp->__Vcoverage + 4686, vlSelfRef.u_ex_mem_reg__DOT__data_out, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out[0U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_out[0U];
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out[1U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_out[1U];
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_out[2U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_out[2U];
    }
    vlSelfRef.mem_data_out[0U] = vlSelfRef.u_ex_mem_reg__DOT__data_out[0U];
    vlSelfRef.mem_data_out[1U] = vlSelfRef.u_ex_mem_reg__DOT__data_out[1U];
    vlSelfRef.mem_data_out[2U] = vlSelfRef.u_ex_mem_reg__DOT__data_out[2U];
    if (((IData)(vlSelfRef.mem_ctrl_out) ^ (IData)(vlSelfRef.__Vtogcov__mem_ctrl_out))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1028, vlSelfRef.mem_ctrl_out, vlSelfRef.__Vtogcov__mem_ctrl_out);
        vlSelfRef.__Vtogcov__mem_ctrl_out = vlSelfRef.mem_ctrl_out;
    }
    if ((0x1000U & (vlSelfRef.mem_data_out[2U] ^ vlSelfRef.__Vtogcov__mem_data_out[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1184, 
                               (vlSelfRef.mem_data_out[2U] 
                                >> 0xcU), (vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                           >> 0xcU));
        vlSelfRef.__Vtogcov__mem_data_out[2U] = ((0xfffU 
                                                  & vlSelfRef.__Vtogcov__mem_data_out[2U]) 
                                                 | (0x1000U 
                                                    & vlSelfRef.mem_data_out[2U]));
    }
    if ((0x800U & (vlSelfRef.mem_data_out[2U] ^ vlSelfRef.__Vtogcov__mem_data_out[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1186, 
                               (vlSelfRef.mem_data_out[2U] 
                                >> 0xbU), (vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                           >> 0xbU));
        vlSelfRef.__Vtogcov__mem_data_out[2U] = ((0x17ffU 
                                                  & vlSelfRef.__Vtogcov__mem_data_out[2U]) 
                                                 | (0x800U 
                                                    & vlSelfRef.mem_data_out[2U]));
    }
    if ((0x400U & (vlSelfRef.mem_data_out[2U] ^ vlSelfRef.__Vtogcov__mem_data_out[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1188, 
                               (vlSelfRef.mem_data_out[2U] 
                                >> 0xaU), (vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                           >> 0xaU));
        vlSelfRef.__Vtogcov__mem_data_out[2U] = ((0x1bffU 
                                                  & vlSelfRef.__Vtogcov__mem_data_out[2U]) 
                                                 | (0x400U 
                                                    & vlSelfRef.mem_data_out[2U]));
    }
    if ((0x200U & (vlSelfRef.mem_data_out[2U] ^ vlSelfRef.__Vtogcov__mem_data_out[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1190, 
                               (vlSelfRef.mem_data_out[2U] 
                                >> 9U), (vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                         >> 9U));
        vlSelfRef.__Vtogcov__mem_data_out[2U] = ((0x1dffU 
                                                  & vlSelfRef.__Vtogcov__mem_data_out[2U]) 
                                                 | (0x200U 
                                                    & vlSelfRef.mem_data_out[2U]));
    }
    if ((0xfU & (((vlSelfRef.mem_data_out[2U] << 0x1bU) 
                  | (vlSelfRef.mem_data_out[2U] >> 5U)) 
                 ^ ((vlSelfRef.__Vtogcov__mem_data_out[2U] 
                     << 0x1bU) | (vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                  >> 5U))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSymsp->__Vcoverage + 1192, 
                               ((vlSelfRef.mem_data_out[2U] 
                                 << 0x1bU) | (vlSelfRef.mem_data_out[2U] 
                                              >> 5U)), 
                               ((vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                 << 0x1bU) | (vlSelfRef.__Vtogcov__mem_data_out[2U] 
                                              >> 5U)));
        vlSelfRef.__Vtogcov__mem_data_out[2U] = ((0x1e1fU 
                                                  & vlSelfRef.__Vtogcov__mem_data_out[2U]) 
                                                 | (0x1e0U 
                                                    & vlSelfRef.mem_data_out[2U]));
    }
    if ((0x1fU & (vlSelfRef.mem_data_out[2U] ^ vlSelfRef.__Vtogcov__mem_data_out[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 1200, 
                               vlSelfRef.mem_data_out[2U], 
                               vlSelfRef.__Vtogcov__mem_data_out[2U]);
        vlSelfRef.__Vtogcov__mem_data_out[2U] = ((0x1fe0U 
                                                  & vlSelfRef.__Vtogcov__mem_data_out[2U]) 
                                                 | (0x1fU 
                                                    & vlSelfRef.mem_data_out[2U]));
    }
    if ((vlSelfRef.mem_data_out[1U] ^ vlSelfRef.__Vtogcov__mem_data_out[1U])) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 1210, 
                               vlSelfRef.mem_data_out[1U], 
                               vlSelfRef.__Vtogcov__mem_data_out[1U]);
        vlSelfRef.__Vtogcov__mem_data_out[1U] = vlSelfRef.mem_data_out[1U];
    }
    if ((vlSelfRef.mem_data_out[0U] ^ vlSelfRef.__Vtogcov__mem_data_out[0U])) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 1274, 
                               vlSelfRef.mem_data_out[0U], 
                               vlSelfRef.__Vtogcov__mem_data_out[0U]);
        vlSelfRef.__Vtogcov__mem_data_out[0U] = vlSelfRef.mem_data_out[0U];
    }
    vlSelfRef.u_dmem__DOT__write = (1U & (vlSelfRef.mem_data_out[2U] 
                                          >> 9U));
    vlSelfRef.u_dmem__DOT__wdata = vlSelfRef.mem_data_out[0U];
    vlSelfRef.u_dmem__DOT__wbe = (0xfU & (vlSelfRef.mem_data_out[2U] 
                                          >> 5U));
    vlSelfRef.u_dmem__DOT__read = (1U & (vlSelfRef.mem_data_out[2U] 
                                         >> 0xaU));
    vlSelfRef.wb_write_reg = (0x1fU & vlSelfRef.mem_data_out[2U]);
    vlSelfRef.wb_reg_write = ((vlSelfRef.mem_data_out[2U] 
                               >> 0xcU) & (IData)(vlSelfRef.mem_ctrl_out));
    vlSelfRef.u_dmem__DOT__addr = vlSelfRef.mem_data_out[1U];
    if (((IData)(vlSelfRef.u_dmem__DOT__write) ^ (IData)(vlSelfRef.u_dmem__DOT____Vtogcov__write))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5011, vlSelfRef.u_dmem__DOT__write, vlSelfRef.u_dmem__DOT____Vtogcov__write);
        vlSelfRef.u_dmem__DOT____Vtogcov__write = vlSelfRef.u_dmem__DOT__write;
    }
    if ((vlSelfRef.u_dmem__DOT__wdata ^ vlSelfRef.u_dmem__DOT____Vtogcov__wdata)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5077, vlSelfRef.u_dmem__DOT__wdata, vlSelfRef.u_dmem__DOT____Vtogcov__wdata);
        vlSelfRef.u_dmem__DOT____Vtogcov__wdata = vlSelfRef.u_dmem__DOT__wdata;
    }
    if (((IData)(vlSelfRef.u_dmem__DOT__wbe) ^ (IData)(vlSelfRef.u_dmem__DOT____Vtogcov__wbe))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSymsp->__Vcoverage + 5141, vlSelfRef.u_dmem__DOT__wbe, vlSelfRef.u_dmem__DOT____Vtogcov__wbe);
        vlSelfRef.u_dmem__DOT____Vtogcov__wbe = vlSelfRef.u_dmem__DOT__wbe;
    }
    if (((IData)(vlSelfRef.u_dmem__DOT__read) ^ (IData)(vlSelfRef.u_dmem__DOT____Vtogcov__read))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5009, vlSelfRef.u_dmem__DOT__read, vlSelfRef.u_dmem__DOT____Vtogcov__read);
        vlSelfRef.u_dmem__DOT____Vtogcov__read = vlSelfRef.u_dmem__DOT__read;
    }
    if (((IData)(vlSelfRef.wb_write_reg) ^ (IData)(vlSelfRef.__Vtogcov__wb_write_reg))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 954, vlSelfRef.wb_write_reg, vlSelfRef.__Vtogcov__wb_write_reg);
        vlSelfRef.__Vtogcov__wb_write_reg = vlSelfRef.wb_write_reg;
    }
    vlSelfRef.u_decoder__DOT__write_reg = vlSelfRef.wb_write_reg;
    if (((IData)(vlSelfRef.wb_reg_write) ^ (IData)(vlSelfRef.__Vtogcov__wb_reg_write))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 952, vlSelfRef.wb_reg_write, vlSelfRef.__Vtogcov__wb_reg_write);
        vlSelfRef.__Vtogcov__wb_reg_write = vlSelfRef.wb_reg_write;
    }
    vlSelfRef.u_decoder__DOT__reg_write = vlSelfRef.wb_reg_write;
    if ((vlSelfRef.u_dmem__DOT__addr ^ vlSelfRef.u_dmem__DOT____Vtogcov__addr)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5013, vlSelfRef.u_dmem__DOT__addr, vlSelfRef.u_dmem__DOT____Vtogcov__addr);
        vlSelfRef.u_dmem__DOT____Vtogcov__addr = vlSelfRef.u_dmem__DOT__addr;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__write_reg) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__write_reg))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 2074, vlSelfRef.u_decoder__DOT__write_reg, vlSelfRef.u_decoder__DOT____Vtogcov__write_reg);
        vlSelfRef.u_decoder__DOT____Vtogcov__write_reg 
            = vlSelfRef.u_decoder__DOT__write_reg;
    }
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__waddr 
        = vlSelfRef.u_decoder__DOT__write_reg;
    if (((IData)(vlSelfRef.u_decoder__DOT__reg_write) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__reg_write))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 2072, vlSelfRef.u_decoder__DOT__reg_write, vlSelfRef.u_decoder__DOT____Vtogcov__reg_write);
        vlSelfRef.u_decoder__DOT____Vtogcov__reg_write 
            = vlSelfRef.u_decoder__DOT__reg_write;
    }
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen = vlSelfRef.u_decoder__DOT__reg_write;
    if (((IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__waddr) 
         ^ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__waddr))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 3195, vlSelfRef.u_decoder__DOT__u_regfile__DOT__waddr, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__waddr);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__waddr 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__waddr;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen) 
         ^ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__wen))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3193, vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__wen);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__wen 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__wen;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__8(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__8\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_dmem__DOT__dmem__DOT__mem_addr = (0xfffU 
                                                  & (vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.addr 
                                                     >> 2U));
    vlSelfRef.u_dmem__DOT__rack = vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.rack;
    if (((IData)(vlSelfRef.u_dmem__DOT__dmem__DOT__mem_addr) 
         ^ (IData)(vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__mem_addr))) {
        VL_COV_TOGGLE_CHG_ST_I(12, vlSymsp->__Vcoverage + 5233, vlSelfRef.u_dmem__DOT__dmem__DOT__mem_addr, vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__mem_addr);
        vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__mem_addr 
            = vlSelfRef.u_dmem__DOT__dmem__DOT__mem_addr;
    }
    if (((IData)(vlSelfRef.u_dmem__DOT__rack) ^ (IData)(vlSelfRef.u_dmem__DOT____Vtogcov__rack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 5151, vlSelfRef.u_dmem__DOT__rack, vlSelfRef.u_dmem__DOT____Vtogcov__rack);
        vlSelfRef.u_dmem__DOT____Vtogcov__rack = vlSelfRef.u_dmem__DOT__rack;
    }
    vlSelfRef.dmem_rack = vlSelfRef.u_dmem__DOT__rack;
    if (((IData)(vlSelfRef.dmem_rack) ^ (IData)(vlSelfRef.__Vtogcov__dmem_rack))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1404, vlSelfRef.dmem_rack, vlSelfRef.__Vtogcov__dmem_rack);
        vlSelfRef.__Vtogcov__dmem_rack = vlSelfRef.dmem_rack;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__9(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__9\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.u_if_id_reg__DOT__rst) {
        ++(vlSymsp->__Vcoverage[1830]);
        vlSelfRef.u_if_id_reg__DOT__ctrl_q = 0U;
    } else {
        if (vlSelfRef.u_if_id_reg__DOT__flush) {
            ++(vlSymsp->__Vcoverage[1829]);
            vlSelfRef.u_if_id_reg__DOT__ctrl_q = 0U;
        } else if (vlSelfRef.u_if_id_reg__DOT__en) {
            ++(vlSymsp->__Vcoverage[1827]);
            vlSelfRef.u_if_id_reg__DOT__ctrl_q = vlSelfRef.u_if_id_reg__DOT__ctrl_in;
        } else {
            ++(vlSymsp->__Vcoverage[1828]);
        }
        ++(vlSymsp->__Vcoverage[1831]);
    }
    ++(vlSymsp->__Vcoverage[1832]);
    if (vlSelfRef.u_if_id_reg__DOT__en) {
        ++(vlSymsp->__Vcoverage[1833]);
        vlSelfRef.u_if_id_reg__DOT__data_q = vlSelfRef.u_if_id_reg__DOT__data_in;
    } else {
        ++(vlSymsp->__Vcoverage[1834]);
    }
    ++(vlSymsp->__Vcoverage[1835]);
    if (((IData)(vlSelfRef.u_if_id_reg__DOT__ctrl_q) 
         ^ (IData)(vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_q))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1697, vlSelfRef.u_if_id_reg__DOT__ctrl_q, vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_q);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_q 
            = vlSelfRef.u_if_id_reg__DOT__ctrl_q;
    }
    vlSelfRef.u_if_id_reg__DOT__ctrl_out = vlSelfRef.u_if_id_reg__DOT__ctrl_q;
    if ((vlSelfRef.u_if_id_reg__DOT__data_q ^ vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_q)) {
        VL_COV_TOGGLE_CHG_ST_Q(64, vlSymsp->__Vcoverage + 1699, vlSelfRef.u_if_id_reg__DOT__data_q, vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_q);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_q 
            = vlSelfRef.u_if_id_reg__DOT__data_q;
    }
    vlSelfRef.u_if_id_reg__DOT__data_out = vlSelfRef.u_if_id_reg__DOT__data_q;
    if (((IData)(vlSelfRef.u_if_id_reg__DOT__ctrl_out) 
         ^ (IData)(vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_out))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1439, vlSelfRef.u_if_id_reg__DOT__ctrl_out, vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_out);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_out 
            = vlSelfRef.u_if_id_reg__DOT__ctrl_out;
    }
    vlSelfRef.id_valid = vlSelfRef.u_if_id_reg__DOT__ctrl_out;
    if ((vlSelfRef.u_if_id_reg__DOT__data_out ^ vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_out)) {
        VL_COV_TOGGLE_CHG_ST_Q(64, vlSymsp->__Vcoverage + 1569, vlSelfRef.u_if_id_reg__DOT__data_out, vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_out);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_out 
            = vlSelfRef.u_if_id_reg__DOT__data_out;
    }
    vlSelfRef.id_pc = (IData)((vlSelfRef.u_if_id_reg__DOT__data_out 
                               >> 0x20U));
    vlSelfRef.id_instruction = (IData)(vlSelfRef.u_if_id_reg__DOT__data_out);
    if (((IData)(vlSelfRef.id_valid) ^ (IData)(vlSelfRef.__Vtogcov__id_valid))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 530, vlSelfRef.id_valid, vlSelfRef.__Vtogcov__id_valid);
        vlSelfRef.__Vtogcov__id_valid = vlSelfRef.id_valid;
    }
    vlSelfRef.u_ex_mem_reg__DOT__ctrl_in = vlSelfRef.id_valid;
    if ((vlSelfRef.id_pc ^ vlSelfRef.__Vtogcov__id_pc)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 466, vlSelfRef.id_pc, vlSelfRef.__Vtogcov__id_pc);
        vlSelfRef.__Vtogcov__id_pc = vlSelfRef.id_pc;
    }
    vlSelfRef.u_decoder__DOT__PC = vlSelfRef.id_pc;
    vlSelfRef.u_execute__DOT__PC = vlSelfRef.id_pc;
    if ((vlSelfRef.id_instruction ^ vlSelfRef.__Vtogcov__id_instruction)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 402, vlSelfRef.id_instruction, vlSelfRef.__Vtogcov__id_instruction);
        vlSelfRef.__Vtogcov__id_instruction = vlSelfRef.id_instruction;
    }
    vlSelfRef.id_instruction_real = ((IData)(vlSelfRef.id_valid)
                                      ? ([&]() {
                ++(vlSymsp->__Vcoverage[1417]);
            }(), vlSelfRef.id_instruction) : ([&]() {
                ++(vlSymsp->__Vcoverage[1418]);
            }(), 0x13U));
    if (((IData)(vlSelfRef.u_ex_mem_reg__DOT__ctrl_in) 
         ^ (IData)(vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_in))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4528, vlSelfRef.u_ex_mem_reg__DOT__ctrl_in, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_in);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__ctrl_in 
            = vlSelfRef.u_ex_mem_reg__DOT__ctrl_in;
    }
    if ((vlSelfRef.u_decoder__DOT__PC ^ vlSelfRef.u_decoder__DOT____Vtogcov__PC)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2002, vlSelfRef.u_decoder__DOT__PC, vlSelfRef.u_decoder__DOT____Vtogcov__PC);
        vlSelfRef.u_decoder__DOT____Vtogcov__PC = vlSelfRef.u_decoder__DOT__PC;
    }
    if ((vlSelfRef.u_execute__DOT__PC ^ vlSelfRef.u_execute__DOT____Vtogcov__PC)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3467, vlSelfRef.u_execute__DOT__PC, vlSelfRef.u_execute__DOT____Vtogcov__PC);
        vlSelfRef.u_execute__DOT____Vtogcov__PC = vlSelfRef.u_execute__DOT__PC;
    }
    if ((vlSelfRef.id_instruction_real ^ vlSelfRef.__Vtogcov__id_instruction_real)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 532, vlSelfRef.id_instruction_real, vlSelfRef.__Vtogcov__id_instruction_real);
        vlSelfRef.__Vtogcov__id_instruction_real = vlSelfRef.id_instruction_real;
    }
    vlSelfRef.u_decoder__DOT__instruction = vlSelfRef.id_instruction_real;
    if ((vlSelfRef.u_decoder__DOT__instruction ^ vlSelfRef.u_decoder__DOT____Vtogcov__instruction)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 1938, vlSelfRef.u_decoder__DOT__instruction, vlSelfRef.u_decoder__DOT____Vtogcov__instruction);
        vlSelfRef.u_decoder__DOT____Vtogcov__instruction 
            = vlSelfRef.u_decoder__DOT__instruction;
    }
    vlSelfRef.u_decoder__DOT__funct3 = (7U & (vlSelfRef.u_decoder__DOT__instruction 
                                              >> 0xcU));
    vlSelfRef.u_decoder__DOT__u_imm = (vlSelfRef.u_decoder__DOT__instruction 
                                       >> 0xcU);
    vlSelfRef.u_decoder__DOT__i_imm_orig = (vlSelfRef.u_decoder__DOT__instruction 
                                            >> 0x14U);
    vlSelfRef.u_decoder__DOT__uj_imm_32 = (((- (IData)(
                                                       (vlSelfRef.u_decoder__DOT__instruction 
                                                        >> 0x1fU))) 
                                            << 0x14U) 
                                           | (((0xff000U 
                                                & vlSelfRef.u_decoder__DOT__instruction) 
                                               | (0x800U 
                                                  & (vlSelfRef.u_decoder__DOT__instruction 
                                                     >> 9U))) 
                                              | (0x7feU 
                                                 & (vlSelfRef.u_decoder__DOT__instruction 
                                                    >> 0x14U))));
    vlSelfRef.u_decoder__DOT__rs1 = (0x1fU & (vlSelfRef.u_decoder__DOT__instruction 
                                              >> 0xfU));
    vlSelfRef.u_decoder__DOT__rs2 = (0x1fU & (vlSelfRef.u_decoder__DOT__instruction 
                                              >> 0x14U));
    vlSelfRef.u_decoder__DOT__rd = (0x1fU & (vlSelfRef.u_decoder__DOT__instruction 
                                             >> 7U));
    vlSelfRef.u_decoder__DOT__funct7 = (vlSelfRef.u_decoder__DOT__instruction 
                                        >> 0x19U);
    vlSelfRef.u_decoder__DOT__opcode = (0x7fU & vlSelfRef.u_decoder__DOT__instruction);
    if (((IData)(vlSelfRef.u_decoder__DOT__funct3) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__funct3))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 2176, vlSelfRef.u_decoder__DOT__funct3, vlSelfRef.u_decoder__DOT____Vtogcov__funct3);
        vlSelfRef.u_decoder__DOT____Vtogcov__funct3 
            = vlSelfRef.u_decoder__DOT__funct3;
    }
    vlSelfRef.id_funct3 = vlSelfRef.u_decoder__DOT__funct3;
    if ((vlSelfRef.u_decoder__DOT__u_imm ^ vlSelfRef.u_decoder__DOT____Vtogcov__u_imm)) {
        VL_COV_TOGGLE_CHG_ST_I(20, vlSymsp->__Vcoverage + 2564, vlSelfRef.u_decoder__DOT__u_imm, vlSelfRef.u_decoder__DOT____Vtogcov__u_imm);
        vlSelfRef.u_decoder__DOT____Vtogcov__u_imm 
            = vlSelfRef.u_decoder__DOT__u_imm;
    }
    vlSelfRef.u_decoder__DOT__u_imm_32 = (vlSelfRef.u_decoder__DOT__u_imm 
                                          << 0xcU);
    if (((IData)(vlSelfRef.u_decoder__DOT__i_imm_orig) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__i_imm_orig))) {
        VL_COV_TOGGLE_CHG_ST_I(12, vlSymsp->__Vcoverage + 2540, vlSelfRef.u_decoder__DOT__i_imm_orig, vlSelfRef.u_decoder__DOT____Vtogcov__i_imm_orig);
        vlSelfRef.u_decoder__DOT____Vtogcov__i_imm_orig 
            = vlSelfRef.u_decoder__DOT__i_imm_orig;
    }
    vlSelfRef.u_decoder__DOT__i_imm_32 = (((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.u_decoder__DOT__i_imm_orig) 
                                                          >> 0xbU)))) 
                                           << 0xcU) 
                                          | (IData)(vlSelfRef.u_decoder__DOT__i_imm_orig));
    if ((vlSelfRef.u_decoder__DOT__uj_imm_32 ^ vlSelfRef.u_decoder__DOT____Vtogcov__uj_imm_32)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2974, vlSelfRef.u_decoder__DOT__uj_imm_32, vlSelfRef.u_decoder__DOT____Vtogcov__uj_imm_32);
        vlSelfRef.u_decoder__DOT____Vtogcov__uj_imm_32 
            = vlSelfRef.u_decoder__DOT__uj_imm_32;
    }
    vlSelfRef.u_decoder__DOT__JAL_target = (vlSelfRef.u_decoder__DOT__PC 
                                            + vlSelfRef.u_decoder__DOT__uj_imm_32);
    if (((IData)(vlSelfRef.u_decoder__DOT__rs1) ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__rs1))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 2182, vlSelfRef.u_decoder__DOT__rs1, vlSelfRef.u_decoder__DOT____Vtogcov__rs1);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs1 = vlSelfRef.u_decoder__DOT__rs1;
    }
    vlSelfRef.id_rs1 = vlSelfRef.u_decoder__DOT__rs1;
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1 
        = vlSelfRef.u_decoder__DOT__rs1;
    if (((IData)(vlSelfRef.u_decoder__DOT__rs2) ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__rs2))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 2192, vlSelfRef.u_decoder__DOT__rs2, vlSelfRef.u_decoder__DOT____Vtogcov__rs2);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs2 = vlSelfRef.u_decoder__DOT__rs2;
    }
    vlSelfRef.id_rs2 = vlSelfRef.u_decoder__DOT__rs2;
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2 
        = vlSelfRef.u_decoder__DOT__rs2;
    if (((IData)(vlSelfRef.u_decoder__DOT__rd) ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__rd))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 2202, vlSelfRef.u_decoder__DOT__rd, vlSelfRef.u_decoder__DOT____Vtogcov__rd);
        vlSelfRef.u_decoder__DOT____Vtogcov__rd = vlSelfRef.u_decoder__DOT__rd;
    }
    vlSelfRef.id_rd = vlSelfRef.u_decoder__DOT__rd;
    vlSelfRef.u_decoder__DOT__s_imm_lsb = vlSelfRef.u_decoder__DOT__rd;
    if (((IData)(vlSelfRef.u_decoder__DOT__funct7) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__funct7))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 2162, vlSelfRef.u_decoder__DOT__funct7, vlSelfRef.u_decoder__DOT____Vtogcov__funct7);
        vlSelfRef.u_decoder__DOT____Vtogcov__funct7 
            = vlSelfRef.u_decoder__DOT__funct7;
    }
    vlSelfRef.id_funct7 = vlSelfRef.u_decoder__DOT__funct7;
    vlSelfRef.u_decoder__DOT__s_imm_msb = vlSelfRef.u_decoder__DOT__funct7;
    if (((IData)(vlSelfRef.u_decoder__DOT__opcode) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__opcode))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 2148, vlSelfRef.u_decoder__DOT__opcode, vlSelfRef.u_decoder__DOT____Vtogcov__opcode);
        vlSelfRef.u_decoder__DOT____Vtogcov__opcode 
            = vlSelfRef.u_decoder__DOT__opcode;
    }
    if ((0x23U == (IData)(vlSelfRef.u_decoder__DOT__opcode))) {
        if ((0U == (IData)(vlSelfRef.u_decoder__DOT__funct3))) {
            vlSelfRef.u_decoder__DOT__mem_wbe = 1U;
            ++(vlSymsp->__Vcoverage[3182]);
        } else if ((1U == (IData)(vlSelfRef.u_decoder__DOT__funct3))) {
            ++(vlSymsp->__Vcoverage[3183]);
            vlSelfRef.u_decoder__DOT__mem_wbe = 3U;
        } else if ((2U == (IData)(vlSelfRef.u_decoder__DOT__funct3))) {
            ++(vlSymsp->__Vcoverage[3184]);
            vlSelfRef.u_decoder__DOT__mem_wbe = 0xfU;
        } else {
            ++(vlSymsp->__Vcoverage[3185]);
            vlSelfRef.u_decoder__DOT__mem_wbe = 0U;
        }
        ++(vlSymsp->__Vcoverage[3186]);
    } else {
        ++(vlSymsp->__Vcoverage[3187]);
        vlSelfRef.u_decoder__DOT__mem_wbe = 0U;
    }
    ++(vlSymsp->__Vcoverage[3188]);
    vlSelfRef.id_opcode = vlSelfRef.u_decoder__DOT__opcode;
    if (((IData)(vlSelfRef.id_funct3) ^ (IData)(vlSelfRef.__Vtogcov__id_funct3))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 652, vlSelfRef.id_funct3, vlSelfRef.__Vtogcov__id_funct3);
        vlSelfRef.__Vtogcov__id_funct3 = vlSelfRef.id_funct3;
    }
    vlSelfRef.u_execute__DOT__funct3 = vlSelfRef.id_funct3;
    if ((vlSelfRef.u_decoder__DOT__u_imm_32 ^ vlSelfRef.u_decoder__DOT____Vtogcov__u_imm_32)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2668, vlSelfRef.u_decoder__DOT__u_imm_32, vlSelfRef.u_decoder__DOT____Vtogcov__u_imm_32);
        vlSelfRef.u_decoder__DOT____Vtogcov__u_imm_32 
            = vlSelfRef.u_decoder__DOT__u_imm_32;
    }
    if ((vlSelfRef.u_decoder__DOT__i_imm_32 ^ vlSelfRef.u_decoder__DOT____Vtogcov__i_imm_32)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2604, vlSelfRef.u_decoder__DOT__i_imm_32, vlSelfRef.u_decoder__DOT____Vtogcov__i_imm_32);
        vlSelfRef.u_decoder__DOT____Vtogcov__i_imm_32 
            = vlSelfRef.u_decoder__DOT__i_imm_32;
    }
    if ((vlSelfRef.u_decoder__DOT__JAL_target ^ vlSelfRef.u_decoder__DOT____Vtogcov__JAL_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2468, vlSelfRef.u_decoder__DOT__JAL_target, vlSelfRef.u_decoder__DOT____Vtogcov__JAL_target);
        vlSelfRef.u_decoder__DOT____Vtogcov__JAL_target 
            = vlSelfRef.u_decoder__DOT__JAL_target;
    }
    vlSelfRef.id_jal_target = vlSelfRef.u_decoder__DOT__JAL_target;
    if (((IData)(vlSelfRef.id_rs1) ^ (IData)(vlSelfRef.__Vtogcov__id_rs1))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 658, vlSelfRef.id_rs1, vlSelfRef.__Vtogcov__id_rs1);
        vlSelfRef.__Vtogcov__id_rs1 = vlSelfRef.id_rs1;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1) 
         ^ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__raddr1))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 3269, vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__raddr1);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__raddr1 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1;
    }
    if (((IData)(vlSelfRef.id_rs2) ^ (IData)(vlSelfRef.__Vtogcov__id_rs2))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 668, vlSelfRef.id_rs2, vlSelfRef.__Vtogcov__id_rs2);
        vlSelfRef.__Vtogcov__id_rs2 = vlSelfRef.id_rs2;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2) 
         ^ (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__raddr2))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 3279, vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__raddr2);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__raddr2 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2;
    }
    if (((IData)(vlSelfRef.id_rd) ^ (IData)(vlSelfRef.__Vtogcov__id_rd))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 678, vlSelfRef.id_rd, vlSelfRef.__Vtogcov__id_rd);
        vlSelfRef.__Vtogcov__id_rd = vlSelfRef.id_rd;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__s_imm_lsb) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_lsb))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 2746, vlSelfRef.u_decoder__DOT__s_imm_lsb, vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_lsb);
        vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_lsb 
            = vlSelfRef.u_decoder__DOT__s_imm_lsb;
    }
    if (((IData)(vlSelfRef.id_funct7) ^ (IData)(vlSelfRef.__Vtogcov__id_funct7))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 638, vlSelfRef.id_funct7, vlSelfRef.__Vtogcov__id_funct7);
        vlSelfRef.__Vtogcov__id_funct7 = vlSelfRef.id_funct7;
    }
    vlSelfRef.u_execute__DOT__funct7 = vlSelfRef.id_funct7;
    if (((IData)(vlSelfRef.u_decoder__DOT__s_imm_msb) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_msb))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 2732, vlSelfRef.u_decoder__DOT__s_imm_msb, vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_msb);
        vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_msb 
            = vlSelfRef.u_decoder__DOT__s_imm_msb;
    }
    vlSelfRef.u_decoder__DOT__s_imm_orig = (((IData)(vlSelfRef.u_decoder__DOT__s_imm_msb) 
                                             << 5U) 
                                            | (IData)(vlSelfRef.u_decoder__DOT__s_imm_lsb));
    vlSelfRef.u_decoder__DOT__sb_imm_orig = (((0x1000U 
                                               & ((IData)(vlSelfRef.u_decoder__DOT__s_imm_msb) 
                                                  << 6U)) 
                                              | (0x800U 
                                                 & ((IData)(vlSelfRef.u_decoder__DOT__s_imm_lsb) 
                                                    << 0xbU))) 
                                             | ((0x7e0U 
                                                 & ((IData)(vlSelfRef.u_decoder__DOT__s_imm_msb) 
                                                    << 5U)) 
                                                | (0x1eU 
                                                   & (IData)(vlSelfRef.u_decoder__DOT__s_imm_lsb))));
    if (((IData)(vlSelfRef.u_decoder__DOT__mem_wbe) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__mem_wbe))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSymsp->__Vcoverage + 2532, vlSelfRef.u_decoder__DOT__mem_wbe, vlSelfRef.u_decoder__DOT____Vtogcov__mem_wbe);
        vlSelfRef.u_decoder__DOT____Vtogcov__mem_wbe 
            = vlSelfRef.u_decoder__DOT__mem_wbe;
    }
    vlSelfRef.id_mem_wbe = vlSelfRef.u_decoder__DOT__mem_wbe;
    if (((IData)(vlSelfRef.id_opcode) ^ (IData)(vlSelfRef.__Vtogcov__id_opcode))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 624, vlSelfRef.id_opcode, vlSelfRef.__Vtogcov__id_opcode);
        vlSelfRef.__Vtogcov__id_opcode = vlSelfRef.id_opcode;
    }
    vlSelfRef.u_control_unit__DOT__opcode = vlSelfRef.id_opcode;
    if (((IData)(vlSelfRef.u_execute__DOT__funct3) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__funct3))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 3455, vlSelfRef.u_execute__DOT__funct3, vlSelfRef.u_execute__DOT____Vtogcov__funct3);
        vlSelfRef.u_execute__DOT____Vtogcov__funct3 
            = vlSelfRef.u_execute__DOT__funct3;
    }
    if ((vlSelfRef.id_jal_target ^ vlSelfRef.__Vtogcov__id_jal_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 274, vlSelfRef.id_jal_target, vlSelfRef.__Vtogcov__id_jal_target);
        vlSelfRef.__Vtogcov__id_jal_target = vlSelfRef.id_jal_target;
    }
    if (((IData)(vlSelfRef.u_execute__DOT__funct7) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__funct7))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 3441, vlSelfRef.u_execute__DOT__funct7, vlSelfRef.u_execute__DOT____Vtogcov__funct7);
        vlSelfRef.u_execute__DOT____Vtogcov__funct7 
            = vlSelfRef.u_execute__DOT__funct7;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__s_imm_orig) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_orig))) {
        VL_COV_TOGGLE_CHG_ST_I(12, vlSymsp->__Vcoverage + 2756, vlSelfRef.u_decoder__DOT__s_imm_orig, vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_orig);
        vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_orig 
            = vlSelfRef.u_decoder__DOT__s_imm_orig;
    }
    vlSelfRef.u_decoder__DOT__s_imm_32 = (((- (IData)(
                                                      (1U 
                                                       & ((IData)(vlSelfRef.u_decoder__DOT__s_imm_orig) 
                                                          >> 0xbU)))) 
                                           << 0xcU) 
                                          | (IData)(vlSelfRef.u_decoder__DOT__s_imm_orig));
    if (((IData)(vlSelfRef.u_decoder__DOT__sb_imm_orig) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__sb_imm_orig))) {
        VL_COV_TOGGLE_CHG_ST_I(13, vlSymsp->__Vcoverage + 2844, vlSelfRef.u_decoder__DOT__sb_imm_orig, vlSelfRef.u_decoder__DOT____Vtogcov__sb_imm_orig);
        vlSelfRef.u_decoder__DOT____Vtogcov__sb_imm_orig 
            = vlSelfRef.u_decoder__DOT__sb_imm_orig;
    }
    vlSelfRef.u_decoder__DOT__sb_imm_32 = (((- (IData)(
                                                       (1U 
                                                        & ((IData)(vlSelfRef.u_decoder__DOT__sb_imm_orig) 
                                                           >> 0xcU)))) 
                                            << 0xdU) 
                                           | (IData)(vlSelfRef.u_decoder__DOT__sb_imm_orig));
    if (((IData)(vlSelfRef.id_mem_wbe) ^ (IData)(vlSelfRef.__Vtogcov__id_mem_wbe))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSymsp->__Vcoverage + 880, vlSelfRef.id_mem_wbe, vlSelfRef.__Vtogcov__id_mem_wbe);
        vlSelfRef.__Vtogcov__id_mem_wbe = vlSelfRef.id_mem_wbe;
    }
    if (((IData)(vlSelfRef.u_control_unit__DOT__opcode) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__opcode))) {
        VL_COV_TOGGLE_CHG_ST_I(7, vlSymsp->__Vcoverage + 1840, vlSelfRef.u_control_unit__DOT__opcode, vlSelfRef.u_control_unit__DOT____Vtogcov__opcode);
        vlSelfRef.u_control_unit__DOT____Vtogcov__opcode 
            = vlSelfRef.u_control_unit__DOT__opcode;
    }
    vlSelfRef.u_control_unit__DOT__next_PC_sel = (3U 
                                                  & ((0x63U 
                                                      == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                      ? 
                                                     ([&]() {
                    ++(vlSymsp->__Vcoverage[1928]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1933]);
                }(), ((0x6fU == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                       ? ([&]() {
                            ++(vlSymsp->__Vcoverage[1929]);
                        }(), 2U) : ([&]() {
                            ++(vlSymsp->__Vcoverage[1932]);
                        }(), ((0x67U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                               ? ([&]() {
                                    ++(vlSymsp->__Vcoverage[1930]);
                                }(), 3U) : ([&]() {
                                    ++(vlSymsp->__Vcoverage[1931]);
                                }(), 0U)))))));
    vlSelfRef.u_control_unit__DOT__branch_op = (1U 
                                                & ((0x63U 
                                                    == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                    ? 
                                                   ([&]() {
                    ++(vlSymsp->__Vcoverage[1922]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1923]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__regWrite = (1U & 
                                               ((((((((0x33U 
                                                       == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                                      | (0x13U 
                                                         == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                     | (3U 
                                                        == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                    | (0x67U 
                                                       == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                   | (0x6fU 
                                                      == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                  | (0x17U 
                                                     == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                 | (0x37U 
                                                    == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                                 ? 
                                                ([&]() {
                    ++(vlSymsp->__Vcoverage[1886]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1887]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__memWrite = (1U & 
                                               ((0x23U 
                                                 == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                 ? 
                                                ([&]() {
                    ++(vlSymsp->__Vcoverage[1920]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1921]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__memRead = (1U & 
                                              ((3U 
                                                == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                ? ([&]() {
                    ++(vlSymsp->__Vcoverage[1924]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1925]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__memtoReg = (1U & 
                                               ((3U 
                                                 == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                 ? 
                                                ([&]() {
                    ++(vlSymsp->__Vcoverage[1926]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1927]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__ALUOp = (7U & ((0x33U 
                                                   == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                   ? 
                                                  ([&]() {
                    ++(vlSymsp->__Vcoverage[1888]);
                }(), 0U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1901]);
                }(), ((0x13U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                       ? ([&]() {
                            ++(vlSymsp->__Vcoverage[1889]);
                        }(), 1U) : ([&]() {
                            ++(vlSymsp->__Vcoverage[1900]);
                        }(), ((0x23U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                               ? ([&]() {
                                    ++(vlSymsp->__Vcoverage[1890]);
                                }(), 5U) : ([&]() {
                                    ++(vlSymsp->__Vcoverage[1899]);
                                }(), ((3U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                       ? ([&]() {
                                            ++(vlSymsp->__Vcoverage[1891]);
                                        }(), 4U) : 
                                      ([&]() {
                                            ++(vlSymsp->__Vcoverage[1898]);
                                        }(), ((0x63U 
                                               == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                               ? ([&]() {
                                                    ++(vlSymsp->__Vcoverage[1892]);
                                                }(), 2U)
                                               : ([&]() {
                                                    ++(vlSymsp->__Vcoverage[1897]);
                                                }(), 
                                                  (((0x67U 
                                                     == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                                    | (0x6fU 
                                                       == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                                    ? 
                                                   ([&]() {
                                                            ++(vlSymsp->__Vcoverage[1893]);
                                                        }(), 3U)
                                                    : 
                                                   ([&]() {
                                                            ++(vlSymsp->__Vcoverage[1896]);
                                                        }(), 
                                                    (((0x17U 
                                                       == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                                      | (0x37U 
                                                         == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                                      ? 
                                                     ([&]() {
                                                                    ++(vlSymsp->__Vcoverage[1894]);
                                                                }(), 6U)
                                                      : 
                                                     ([&]() {
                                                                    ++(vlSymsp->__Vcoverage[1895]);
                                                                }(), 0U)))))))))))))));
    vlSelfRef.u_control_unit__DOT__operand_A = (3U 
                                                & ((0x17U 
                                                    == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                                    ? 
                                                   ([&]() {
                    ++(vlSymsp->__Vcoverage[1902]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1907]);
                }(), ((0x37U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                       ? ([&]() {
                            ++(vlSymsp->__Vcoverage[1903]);
                        }(), 3U) : ([&]() {
                            ++(vlSymsp->__Vcoverage[1906]);
                        }(), (((0x67U == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                               | (0x6fU == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                               ? ([&]() {
                                    ++(vlSymsp->__Vcoverage[1904]);
                                }(), 2U) : ([&]() {
                                    ++(vlSymsp->__Vcoverage[1905]);
                                }(), 0U)))))));
    vlSelfRef.u_control_unit__DOT__operand_B = (1U 
                                                & ((((((0x13U 
                                                        == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                                       | (0x23U 
                                                          == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                      | (3U 
                                                         == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                     | (0x17U 
                                                        == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                    | (0x37U 
                                                       == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                                    ? 
                                                   ([&]() {
                    ++(vlSymsp->__Vcoverage[1908]);
                }(), 1U) : ([&]() {
                    ++(vlSymsp->__Vcoverage[1909]);
                }(), 0U)));
    vlSelfRef.u_control_unit__DOT__extend_sel = (((
                                                   (0x13U 
                                                    == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                                   | (3U 
                                                      == (IData)(vlSelfRef.u_control_unit__DOT__opcode))) 
                                                  | (0x67U 
                                                     == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                                  ? 
                                                 ([&]() {
                ++(vlSymsp->__Vcoverage[1910]);
            }(), 0U) : ([&]() {
                ++(vlSymsp->__Vcoverage[1919]);
            }(), ((0x23U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                   ? ([&]() {
                        ++(vlSymsp->__Vcoverage[1911]);
                    }(), 1U) : ([&]() {
                        ++(vlSymsp->__Vcoverage[1918]);
                    }(), ((0x63U == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                           ? ([&]() {
                                ++(vlSymsp->__Vcoverage[1912]);
                            }(), 2U) : ([&]() {
                                ++(vlSymsp->__Vcoverage[1917]);
                            }(), (((0x17U == (IData)(vlSelfRef.u_control_unit__DOT__opcode)) 
                                   | (0x37U == (IData)(vlSelfRef.u_control_unit__DOT__opcode)))
                                   ? ([&]() {
                                        ++(vlSymsp->__Vcoverage[1913]);
                                    }(), 3U) : ([&]() {
                                        ++(vlSymsp->__Vcoverage[1916]);
                                    }(), ((0x6fU == (IData)(vlSelfRef.u_control_unit__DOT__opcode))
                                           ? ([&]() {
                                                ++(vlSymsp->__Vcoverage[1914]);
                                            }(), 4U)
                                           : ([&]() {
                                                ++(vlSymsp->__Vcoverage[1915]);
                                            }(), 0U))))))))));
    if ((vlSelfRef.u_decoder__DOT__s_imm_32 ^ vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_32)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2780, vlSelfRef.u_decoder__DOT__s_imm_32, vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_32);
        vlSelfRef.u_decoder__DOT____Vtogcov__s_imm_32 
            = vlSelfRef.u_decoder__DOT__s_imm_32;
    }
    if ((vlSelfRef.u_decoder__DOT__sb_imm_32 ^ vlSelfRef.u_decoder__DOT____Vtogcov__sb_imm_32)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2870, vlSelfRef.u_decoder__DOT__sb_imm_32, vlSelfRef.u_decoder__DOT____Vtogcov__sb_imm_32);
        vlSelfRef.u_decoder__DOT____Vtogcov__sb_imm_32 
            = vlSelfRef.u_decoder__DOT__sb_imm_32;
    }
    vlSelfRef.u_decoder__DOT__branch_target = (vlSelfRef.u_decoder__DOT__PC 
                                               + vlSelfRef.u_decoder__DOT__sb_imm_32);
    if (((IData)(vlSelfRef.u_control_unit__DOT__next_PC_sel) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__next_PC_sel))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSymsp->__Vcoverage + 1882, vlSelfRef.u_control_unit__DOT__next_PC_sel, vlSelfRef.u_control_unit__DOT____Vtogcov__next_PC_sel);
        vlSelfRef.u_control_unit__DOT____Vtogcov__next_PC_sel 
            = vlSelfRef.u_control_unit__DOT__next_PC_sel;
    }
    vlSelfRef.id_pc_sel = vlSelfRef.u_control_unit__DOT__next_PC_sel;
    if (((IData)(vlSelfRef.u_control_unit__DOT__branch_op) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__branch_op))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1874, vlSelfRef.u_control_unit__DOT__branch_op, vlSelfRef.u_control_unit__DOT____Vtogcov__branch_op);
        vlSelfRef.u_control_unit__DOT____Vtogcov__branch_op 
            = vlSelfRef.u_control_unit__DOT__branch_op;
    }
    vlSelfRef.id_branch_op = vlSelfRef.u_control_unit__DOT__branch_op;
    if (((IData)(vlSelfRef.u_control_unit__DOT__regWrite) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__regWrite))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1872, vlSelfRef.u_control_unit__DOT__regWrite, vlSelfRef.u_control_unit__DOT____Vtogcov__regWrite);
        vlSelfRef.u_control_unit__DOT____Vtogcov__regWrite 
            = vlSelfRef.u_control_unit__DOT__regWrite;
    }
    vlSelfRef.id_reg_write = vlSelfRef.u_control_unit__DOT__regWrite;
    if (((IData)(vlSelfRef.u_control_unit__DOT__memWrite) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__memWrite))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1878, vlSelfRef.u_control_unit__DOT__memWrite, vlSelfRef.u_control_unit__DOT____Vtogcov__memWrite);
        vlSelfRef.u_control_unit__DOT____Vtogcov__memWrite 
            = vlSelfRef.u_control_unit__DOT__memWrite;
    }
    vlSelfRef.id_mem_write = vlSelfRef.u_control_unit__DOT__memWrite;
    if (((IData)(vlSelfRef.u_control_unit__DOT__memRead) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__memRead))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1876, vlSelfRef.u_control_unit__DOT__memRead, vlSelfRef.u_control_unit__DOT____Vtogcov__memRead);
        vlSelfRef.u_control_unit__DOT____Vtogcov__memRead 
            = vlSelfRef.u_control_unit__DOT__memRead;
    }
    vlSelfRef.id_mem_read = vlSelfRef.u_control_unit__DOT__memRead;
    if (((IData)(vlSelfRef.u_control_unit__DOT__memtoReg) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__memtoReg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1880, vlSelfRef.u_control_unit__DOT__memtoReg, vlSelfRef.u_control_unit__DOT____Vtogcov__memtoReg);
        vlSelfRef.u_control_unit__DOT____Vtogcov__memtoReg 
            = vlSelfRef.u_control_unit__DOT__memtoReg;
    }
    vlSelfRef.id_mem_to_reg = vlSelfRef.u_control_unit__DOT__memtoReg;
    if (((IData)(vlSelfRef.u_control_unit__DOT__ALUOp) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__ALUOp))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 1854, vlSelfRef.u_control_unit__DOT__ALUOp, vlSelfRef.u_control_unit__DOT____Vtogcov__ALUOp);
        vlSelfRef.u_control_unit__DOT____Vtogcov__ALUOp 
            = vlSelfRef.u_control_unit__DOT__ALUOp;
    }
    vlSelfRef.id_alu_op = vlSelfRef.u_control_unit__DOT__ALUOp;
    if (((IData)(vlSelfRef.u_control_unit__DOT__operand_A) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__operand_A))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSymsp->__Vcoverage + 1860, vlSelfRef.u_control_unit__DOT__operand_A, vlSelfRef.u_control_unit__DOT____Vtogcov__operand_A);
        vlSelfRef.u_control_unit__DOT____Vtogcov__operand_A 
            = vlSelfRef.u_control_unit__DOT__operand_A;
    }
    vlSelfRef.id_operand_a = vlSelfRef.u_control_unit__DOT__operand_A;
    if (((IData)(vlSelfRef.u_control_unit__DOT__operand_B) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__operand_B))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1864, vlSelfRef.u_control_unit__DOT__operand_B, vlSelfRef.u_control_unit__DOT____Vtogcov__operand_B);
        vlSelfRef.u_control_unit__DOT____Vtogcov__operand_B 
            = vlSelfRef.u_control_unit__DOT__operand_B;
    }
    vlSelfRef.id_operand_b = vlSelfRef.u_control_unit__DOT__operand_B;
    if (((IData)(vlSelfRef.u_control_unit__DOT__extend_sel) 
         ^ (IData)(vlSelfRef.u_control_unit__DOT____Vtogcov__extend_sel))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 1866, vlSelfRef.u_control_unit__DOT__extend_sel, vlSelfRef.u_control_unit__DOT____Vtogcov__extend_sel);
        vlSelfRef.u_control_unit__DOT____Vtogcov__extend_sel 
            = vlSelfRef.u_control_unit__DOT__extend_sel;
    }
    vlSelfRef.id_extend_sel = vlSelfRef.u_control_unit__DOT__extend_sel;
    if ((vlSelfRef.u_decoder__DOT__branch_target ^ vlSelfRef.u_decoder__DOT____Vtogcov__branch_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2404, vlSelfRef.u_decoder__DOT__branch_target, vlSelfRef.u_decoder__DOT____Vtogcov__branch_target);
        vlSelfRef.u_decoder__DOT____Vtogcov__branch_target 
            = vlSelfRef.u_decoder__DOT__branch_target;
    }
    vlSelfRef.id_branch_target = vlSelfRef.u_decoder__DOT__branch_target;
    if (((IData)(vlSelfRef.id_pc_sel) ^ (IData)(vlSelfRef.__Vtogcov__id_pc_sel))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSymsp->__Vcoverage + 204, vlSelfRef.id_pc_sel, vlSelfRef.__Vtogcov__id_pc_sel);
        vlSelfRef.__Vtogcov__id_pc_sel = vlSelfRef.id_pc_sel;
    }
    if (((IData)(vlSelfRef.id_branch_op) ^ (IData)(vlSelfRef.__Vtogcov__id_branch_op))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 616, vlSelfRef.id_branch_op, vlSelfRef.__Vtogcov__id_branch_op);
        vlSelfRef.__Vtogcov__id_branch_op = vlSelfRef.id_branch_op;
    }
    vlSelfRef.u_execute__DOT__branch_op = vlSelfRef.id_branch_op;
    if (((IData)(vlSelfRef.id_reg_write) ^ (IData)(vlSelfRef.__Vtogcov__id_reg_write))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 614, vlSelfRef.id_reg_write, vlSelfRef.__Vtogcov__id_reg_write);
        vlSelfRef.__Vtogcov__id_reg_write = vlSelfRef.id_reg_write;
    }
    VL_ASSIGNBIT_WI(0x4cU, vlSelfRef.id_ex_data_in, 
                    ((IData)(vlSelfRef.id_valid) ? 
                     ([&]() {
                    ++(vlSymsp->__Vcoverage[1419]);
                }(), (IData)(vlSelfRef.id_reg_write))
                      : ([&]() {
                    ++(vlSymsp->__Vcoverage[1420]);
                }(), 0U)));
    if (((IData)(vlSelfRef.id_mem_write) ^ (IData)(vlSelfRef.__Vtogcov__id_mem_write))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 620, vlSelfRef.id_mem_write, vlSelfRef.__Vtogcov__id_mem_write);
        vlSelfRef.__Vtogcov__id_mem_write = vlSelfRef.id_mem_write;
    }
    VL_ASSIGNBIT_WI(0x49U, vlSelfRef.id_ex_data_in, 
                    ((IData)(vlSelfRef.id_valid) ? 
                     ([&]() {
                    ++(vlSymsp->__Vcoverage[1421]);
                }(), (IData)(vlSelfRef.id_mem_write))
                      : ([&]() {
                    ++(vlSymsp->__Vcoverage[1422]);
                }(), 0U)));
    if (((IData)(vlSelfRef.id_mem_read) ^ (IData)(vlSelfRef.__Vtogcov__id_mem_read))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 618, vlSelfRef.id_mem_read, vlSelfRef.__Vtogcov__id_mem_read);
        vlSelfRef.__Vtogcov__id_mem_read = vlSelfRef.id_mem_read;
    }
    VL_ASSIGNBIT_WI(0x4aU, vlSelfRef.id_ex_data_in, 
                    ((IData)(vlSelfRef.id_valid) ? 
                     ([&]() {
                    ++(vlSymsp->__Vcoverage[1423]);
                }(), (IData)(vlSelfRef.id_mem_read))
                      : ([&]() {
                    ++(vlSymsp->__Vcoverage[1424]);
                }(), 0U)));
    if (((IData)(vlSelfRef.id_mem_to_reg) ^ (IData)(vlSelfRef.__Vtogcov__id_mem_to_reg))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 622, vlSelfRef.id_mem_to_reg, vlSelfRef.__Vtogcov__id_mem_to_reg);
        vlSelfRef.__Vtogcov__id_mem_to_reg = vlSelfRef.id_mem_to_reg;
    }
    VL_ASSIGNBIT_WI(0x4bU, vlSelfRef.id_ex_data_in, 
                    ((IData)(vlSelfRef.id_valid) ? 
                     ([&]() {
                    ++(vlSymsp->__Vcoverage[1425]);
                }(), (IData)(vlSelfRef.id_mem_to_reg))
                      : ([&]() {
                    ++(vlSymsp->__Vcoverage[1426]);
                }(), 0U)));
    if (((IData)(vlSelfRef.id_alu_op) ^ (IData)(vlSelfRef.__Vtogcov__id_alu_op))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 596, vlSelfRef.id_alu_op, vlSelfRef.__Vtogcov__id_alu_op);
        vlSelfRef.__Vtogcov__id_alu_op = vlSelfRef.id_alu_op;
    }
    vlSelfRef.u_execute__DOT__ALU_Operation = vlSelfRef.id_alu_op;
    if (((IData)(vlSelfRef.id_operand_a) ^ (IData)(vlSelfRef.__Vtogcov__id_operand_a))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSymsp->__Vcoverage + 602, vlSelfRef.id_operand_a, vlSelfRef.__Vtogcov__id_operand_a);
        vlSelfRef.__Vtogcov__id_operand_a = vlSelfRef.id_operand_a;
    }
    vlSelfRef.u_execute__DOT__ALU_ASrc = vlSelfRef.id_operand_a;
    if (((IData)(vlSelfRef.id_operand_b) ^ (IData)(vlSelfRef.__Vtogcov__id_operand_b))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 606, vlSelfRef.id_operand_b, vlSelfRef.__Vtogcov__id_operand_b);
        vlSelfRef.__Vtogcov__id_operand_b = vlSelfRef.id_operand_b;
    }
    vlSelfRef.u_execute__DOT__ALU_BSrc = vlSelfRef.id_operand_b;
    if (((IData)(vlSelfRef.id_extend_sel) ^ (IData)(vlSelfRef.__Vtogcov__id_extend_sel))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 608, vlSelfRef.id_extend_sel, vlSelfRef.__Vtogcov__id_extend_sel);
        vlSelfRef.__Vtogcov__id_extend_sel = vlSelfRef.id_extend_sel;
    }
    vlSelfRef.u_decoder__DOT__extend_sel = vlSelfRef.id_extend_sel;
    if ((vlSelfRef.id_branch_target ^ vlSelfRef.__Vtogcov__id_branch_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 210, vlSelfRef.id_branch_target, vlSelfRef.__Vtogcov__id_branch_target);
        vlSelfRef.__Vtogcov__id_branch_target = vlSelfRef.id_branch_target;
    }
    if (((IData)(vlSelfRef.u_execute__DOT__branch_op) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__branch_op))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3723, vlSelfRef.u_execute__DOT__branch_op, vlSelfRef.u_execute__DOT____Vtogcov__branch_op);
        vlSelfRef.u_execute__DOT____Vtogcov__branch_op 
            = vlSelfRef.u_execute__DOT__branch_op;
    }
    if (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__ALU_Operation))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 3435, vlSelfRef.u_execute__DOT__ALU_Operation, vlSelfRef.u_execute__DOT____Vtogcov__ALU_Operation);
        vlSelfRef.u_execute__DOT____Vtogcov__ALU_Operation 
            = vlSelfRef.u_execute__DOT__ALU_Operation;
    }
    if ((0U == (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
                 << 7U) | (IData)(vlSelfRef.u_execute__DOT__funct7)))) {
        vlSelfRef.u_execute__DOT__ALU_Control = vlSelfRef.u_execute__DOT__funct3;
        ++(vlSymsp->__Vcoverage[3876]);
    } else if ((0x20U == (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
                           << 7U) | (IData)(vlSelfRef.u_execute__DOT__funct7)))) {
        ++(vlSymsp->__Vcoverage[3875]);
        vlSelfRef.u_execute__DOT__ALU_Control = (8U 
                                                 | (IData)(vlSelfRef.u_execute__DOT__funct3));
    } else if ((0x680U == (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
                            << 0xaU) | (((IData)(vlSelfRef.u_execute__DOT__funct3) 
                                         << 7U) | (IData)(vlSelfRef.u_execute__DOT__funct7))))) {
        ++(vlSymsp->__Vcoverage[3874]);
        vlSelfRef.u_execute__DOT__ALU_Control = vlSelfRef.u_execute__DOT__funct3;
    } else if ((0x6a0U == (((IData)(vlSelfRef.u_execute__DOT__ALU_Operation) 
                            << 0xaU) | (((IData)(vlSelfRef.u_execute__DOT__funct3) 
                                         << 7U) | (IData)(vlSelfRef.u_execute__DOT__funct7))))) {
        ++(vlSymsp->__Vcoverage[3873]);
        vlSelfRef.u_execute__DOT__ALU_Control = (8U 
                                                 | (IData)(vlSelfRef.u_execute__DOT__funct3));
    } else if ((1U == (IData)(vlSelfRef.u_execute__DOT__ALU_Operation))) {
        ++(vlSymsp->__Vcoverage[3872]);
        vlSelfRef.u_execute__DOT__ALU_Control = vlSelfRef.u_execute__DOT__funct3;
    } else if ((2U == (IData)(vlSelfRef.u_execute__DOT__ALU_Operation))) {
        ++(vlSymsp->__Vcoverage[3871]);
        vlSelfRef.u_execute__DOT__ALU_Control = (0x10U 
                                                 | (IData)(vlSelfRef.u_execute__DOT__funct3));
    } else if ((3U == (IData)(vlSelfRef.u_execute__DOT__ALU_Operation))) {
        ++(vlSymsp->__Vcoverage[3869]);
        vlSelfRef.u_execute__DOT__ALU_Control = 0x1fU;
    } else {
        ++(vlSymsp->__Vcoverage[3870]);
        vlSelfRef.u_execute__DOT__ALU_Control = 0U;
    }
    ++(vlSymsp->__Vcoverage[3877]);
    if (((IData)(vlSelfRef.u_execute__DOT__ALU_ASrc) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__ALU_ASrc))) {
        VL_COV_TOGGLE_CHG_ST_I(2, vlSymsp->__Vcoverage + 3461, vlSelfRef.u_execute__DOT__ALU_ASrc, vlSelfRef.u_execute__DOT____Vtogcov__ALU_ASrc);
        vlSelfRef.u_execute__DOT____Vtogcov__ALU_ASrc 
            = vlSelfRef.u_execute__DOT__ALU_ASrc;
    }
    if (((IData)(vlSelfRef.u_execute__DOT__ALU_BSrc) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__ALU_BSrc))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3465, vlSelfRef.u_execute__DOT__ALU_BSrc, vlSelfRef.u_execute__DOT____Vtogcov__ALU_BSrc);
        vlSelfRef.u_execute__DOT____Vtogcov__ALU_BSrc 
            = vlSelfRef.u_execute__DOT__ALU_BSrc;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__extend_sel) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__extend_sel))) {
        VL_COV_TOGGLE_CHG_ST_I(3, vlSymsp->__Vcoverage + 2066, vlSelfRef.u_decoder__DOT__extend_sel, vlSelfRef.u_decoder__DOT____Vtogcov__extend_sel);
        vlSelfRef.u_decoder__DOT____Vtogcov__extend_sel 
            = vlSelfRef.u_decoder__DOT__extend_sel;
    }
    vlSelfRef.u_decoder__DOT__extend_imm = ((1U == (IData)(vlSelfRef.u_decoder__DOT__extend_sel))
                                             ? ([&]() {
                ++(vlSymsp->__Vcoverage[3170]);
            }(), vlSelfRef.u_decoder__DOT__s_imm_32)
                                             : ([&]() {
                ++(vlSymsp->__Vcoverage[3177]);
            }(), ((2U == (IData)(vlSelfRef.u_decoder__DOT__extend_sel))
                   ? ([&]() {
                        ++(vlSymsp->__Vcoverage[3171]);
                    }(), vlSelfRef.u_decoder__DOT__sb_imm_32)
                   : ([&]() {
                        ++(vlSymsp->__Vcoverage[3176]);
                    }(), ((3U == (IData)(vlSelfRef.u_decoder__DOT__extend_sel))
                           ? ([&]() {
                                ++(vlSymsp->__Vcoverage[3172]);
                            }(), vlSelfRef.u_decoder__DOT__u_imm_32)
                           : ([&]() {
                                ++(vlSymsp->__Vcoverage[3175]);
                            }(), ((4U == (IData)(vlSelfRef.u_decoder__DOT__extend_sel))
                                   ? ([&]() {
                                        ++(vlSymsp->__Vcoverage[3173]);
                                    }(), vlSelfRef.u_decoder__DOT__uj_imm_32)
                                   : ([&]() {
                                        ++(vlSymsp->__Vcoverage[3174]);
                                    }(), vlSelfRef.u_decoder__DOT__i_imm_32))))))));
    if (((IData)(vlSelfRef.u_execute__DOT__ALU_Control) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__ALU_Control))) {
        VL_COV_TOGGLE_CHG_ST_I(6, vlSymsp->__Vcoverage + 3855, vlSelfRef.u_execute__DOT__ALU_Control, vlSelfRef.u_execute__DOT____Vtogcov__ALU_Control);
        vlSelfRef.u_execute__DOT____Vtogcov__ALU_Control 
            = vlSelfRef.u_execute__DOT__ALU_Control;
    }
    vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control 
        = vlSelfRef.u_execute__DOT__ALU_Control;
    if ((vlSelfRef.u_decoder__DOT__extend_imm ^ vlSelfRef.u_decoder__DOT____Vtogcov__extend_imm)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2212, vlSelfRef.u_decoder__DOT__extend_imm, vlSelfRef.u_decoder__DOT____Vtogcov__extend_imm);
        vlSelfRef.u_decoder__DOT____Vtogcov__extend_imm 
            = vlSelfRef.u_decoder__DOT__extend_imm;
    }
    vlSelfRef.id_extend_imm = vlSelfRef.u_decoder__DOT__extend_imm;
    if (((IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control) 
         ^ (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__ALU_Control))) {
        VL_COV_TOGGLE_CHG_ST_I(6, vlSymsp->__Vcoverage + 4014, vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__ALU_Control);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__ALU_Control 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control;
    }
    if ((vlSelfRef.id_extend_imm ^ vlSelfRef.__Vtogcov__id_extend_imm)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 688, vlSelfRef.id_extend_imm, vlSelfRef.__Vtogcov__id_extend_imm);
        vlSelfRef.__Vtogcov__id_extend_imm = vlSelfRef.id_extend_imm;
    }
    vlSelfRef.u_execute__DOT__extend = vlSelfRef.id_extend_imm;
    if ((vlSelfRef.u_execute__DOT__extend ^ vlSelfRef.u_execute__DOT____Vtogcov__extend)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3659, vlSelfRef.u_execute__DOT__extend, vlSelfRef.u_execute__DOT____Vtogcov__extend);
        vlSelfRef.u_execute__DOT____Vtogcov__extend 
            = vlSelfRef.u_execute__DOT__extend;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__0(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_comb__TOP__CoreTop__0\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_dmem__DOT__dmem__DOT__write_data = 
        vlSelfRef.u_dmem__DOT__dmem__DOT__mem[vlSelfRef.u_dmem__DOT__dmem__DOT__mem_addr];
    if ((1U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xffffff00U & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xffU & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
        ++(vlSymsp->__Vcoverage[5321]);
    } else {
        ++(vlSymsp->__Vcoverage[5322]);
    }
    ++(vlSymsp->__Vcoverage[5323]);
    if ((2U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        ++(vlSymsp->__Vcoverage[5321]);
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xffff00ffU & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xff00U & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
    } else {
        ++(vlSymsp->__Vcoverage[5322]);
    }
    ++(vlSymsp->__Vcoverage[5323]);
    if ((4U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        ++(vlSymsp->__Vcoverage[5321]);
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xff00ffffU & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xff0000U & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
    } else {
        ++(vlSymsp->__Vcoverage[5322]);
    }
    ++(vlSymsp->__Vcoverage[5323]);
    if ((8U & (IData)(vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wbe))) {
        ++(vlSymsp->__Vcoverage[5321]);
        vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
            = ((0xffffffU & vlSelfRef.u_dmem__DOT__dmem__DOT__write_data) 
               | (0xff000000U & vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.wdata));
    } else {
        ++(vlSymsp->__Vcoverage[5322]);
    }
    ++(vlSymsp->__Vcoverage[5323]);
    ++(vlSymsp->__Vcoverage[5324]);
    if ((vlSelfRef.u_dmem__DOT__dmem__DOT__write_data 
         ^ vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__write_data)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5257, vlSelfRef.u_dmem__DOT__dmem__DOT__write_data, vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__write_data);
        vlSelfRef.u_dmem__DOT__dmem__DOT____Vtogcov__write_data 
            = vlSelfRef.u_dmem__DOT__dmem__DOT__write_data;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__1(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_comb__TOP__CoreTop__1\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_dmem__DOT__rdata = vlSymsp->TOP__CoreTop__u_dmem__DOT__dbus.rdata;
    if ((vlSelfRef.u_dmem__DOT__rdata ^ vlSelfRef.u_dmem__DOT____Vtogcov__rdata)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 5157, vlSelfRef.u_dmem__DOT__rdata, vlSelfRef.u_dmem__DOT____Vtogcov__rdata);
        vlSelfRef.u_dmem__DOT____Vtogcov__rdata = vlSelfRef.u_dmem__DOT__rdata;
    }
    vlSelfRef.mem_rdata = vlSelfRef.u_dmem__DOT__rdata;
    if ((vlSelfRef.mem_rdata ^ vlSelfRef.__Vtogcov__mem_rdata)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 1338, vlSelfRef.mem_rdata, vlSelfRef.__Vtogcov__mem_rdata);
        vlSelfRef.__Vtogcov__mem_rdata = vlSelfRef.mem_rdata;
    }
    vlSelfRef.wb_write_data = ((0x800U & vlSelfRef.mem_data_out[2U])
                                ? ([&]() {
                ++(vlSymsp->__Vcoverage[1427]);
            }(), vlSelfRef.mem_rdata) : ([&]() {
                ++(vlSymsp->__Vcoverage[1428]);
            }(), vlSelfRef.mem_data_out[1U]));
    if ((vlSelfRef.wb_write_data ^ vlSelfRef.__Vtogcov__wb_write_data)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 964, vlSelfRef.wb_write_data, vlSelfRef.__Vtogcov__wb_write_data);
        vlSelfRef.__Vtogcov__wb_write_data = vlSelfRef.wb_write_data;
    }
    vlSelfRef.u_decoder__DOT__write_data = vlSelfRef.wb_write_data;
    if ((vlSelfRef.u_decoder__DOT__write_data ^ vlSelfRef.u_decoder__DOT____Vtogcov__write_data)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2084, vlSelfRef.u_decoder__DOT__write_data, vlSelfRef.u_decoder__DOT____Vtogcov__write_data);
        vlSelfRef.u_decoder__DOT____Vtogcov__write_data 
            = vlSelfRef.u_decoder__DOT__write_data;
    }
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__wdata 
        = vlSelfRef.u_decoder__DOT__write_data;
    if ((vlSelfRef.u_decoder__DOT__u_regfile__DOT__wdata 
         ^ vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__wdata)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3205, vlSelfRef.u_decoder__DOT__u_regfile__DOT__wdata, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__wdata);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__wdata 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__wdata;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__10(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_sequent__TOP__CoreTop__10\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_if_id_reg__DOT__ctrl_in = vlSelfRef.if_valid;
    if (((IData)(vlSelfRef.u_if_id_reg__DOT__ctrl_in) 
         ^ (IData)(vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_in))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1437, vlSelfRef.u_if_id_reg__DOT__ctrl_in, vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_in);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__ctrl_in 
            = vlSelfRef.u_if_id_reg__DOT__ctrl_in;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__2(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_comb__TOP__CoreTop__2\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_if_id_reg__DOT__data_in = (((QData)((IData)(vlSelfRef.if_pc)) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.if_instruction)));
    if ((vlSelfRef.u_if_id_reg__DOT__data_in ^ vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_in)) {
        VL_COV_TOGGLE_CHG_ST_Q(64, vlSymsp->__Vcoverage + 1441, vlSelfRef.u_if_id_reg__DOT__data_in, vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_in);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__data_in 
            = vlSelfRef.u_if_id_reg__DOT__data_in;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__3(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_comb__TOP__CoreTop__3\n"); );
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
    if (((IData)(vlSelfRef.u_decoder__DOT__rs1_data_bypass) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data_bypass))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3038, vlSelfRef.u_decoder__DOT__rs1_data_bypass, vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data_bypass);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data_bypass 
            = vlSelfRef.u_decoder__DOT__rs1_data_bypass;
    }
    if (((IData)(vlSelfRef.u_decoder__DOT__rs2_data_bypass) 
         ^ (IData)(vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data_bypass))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3040, vlSelfRef.u_decoder__DOT__rs2_data_bypass, vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data_bypass);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data_bypass 
            = vlSelfRef.u_decoder__DOT__rs2_data_bypass;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__4(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_comb__TOP__CoreTop__4\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1 
        = ((0U == (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1))
            ? ([&]() {
                ++(vlSymsp->__Vcoverage[3417]);
            }(), 0U) : ([&]() {
                ++(vlSymsp->__Vcoverage[3418]);
            }(), vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs
                        [vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr1]));
    vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2 
        = ((0U == (IData)(vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2))
            ? ([&]() {
                ++(vlSymsp->__Vcoverage[3419]);
            }(), 0U) : ([&]() {
                ++(vlSymsp->__Vcoverage[3420]);
            }(), vlSelfRef.u_decoder__DOT__u_regfile__DOT__regs
                        [vlSelfRef.u_decoder__DOT__u_regfile__DOT__raddr2]));
    if ((vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1 
         ^ vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rdata1)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3289, vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rdata1);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rdata1 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1;
    }
    vlSelfRef.u_decoder__DOT__rs1_data_decode = vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata1;
    if ((vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2 
         ^ vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rdata2)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3353, vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2, vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rdata2);
        vlSelfRef.u_decoder__DOT__u_regfile__DOT____Vtogcov__rdata2 
            = vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2;
    }
    vlSelfRef.u_decoder__DOT__rs2_data_decode = vlSelfRef.u_decoder__DOT__u_regfile__DOT__rdata2;
    if ((vlSelfRef.u_decoder__DOT__rs1_data_decode 
         ^ vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data_decode)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3042, vlSelfRef.u_decoder__DOT__rs1_data_decode, vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data_decode);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data_decode 
            = vlSelfRef.u_decoder__DOT__rs1_data_decode;
    }
    if ((vlSelfRef.u_decoder__DOT__rs2_data_decode 
         ^ vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data_decode)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3106, vlSelfRef.u_decoder__DOT__rs2_data_decode, vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data_decode);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data_decode 
            = vlSelfRef.u_decoder__DOT__rs2_data_decode;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__5(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_comb__TOP__CoreTop__5\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlWide<3>/*95:0*/ __Vtemp_2;
    // Body
    vlSelfRef.u_decoder__DOT__rs1_data = ((IData)(vlSelfRef.u_decoder__DOT__rs1_data_bypass)
                                           ? ([&]() {
                ++(vlSymsp->__Vcoverage[3179]);
            }(), vlSelfRef.u_decoder__DOT__write_data)
                                           : ([&]() {
                ++(vlSymsp->__Vcoverage[3178]);
            }(), vlSelfRef.u_decoder__DOT__rs1_data_decode));
    vlSelfRef.u_decoder__DOT__rs2_data = ((IData)(vlSelfRef.u_decoder__DOT__rs2_data_bypass)
                                           ? ([&]() {
                ++(vlSymsp->__Vcoverage[3181]);
            }(), vlSelfRef.u_decoder__DOT__write_data)
                                           : ([&]() {
                ++(vlSymsp->__Vcoverage[3180]);
            }(), vlSelfRef.u_decoder__DOT__rs2_data_decode));
    if ((vlSelfRef.u_decoder__DOT__rs1_data ^ vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2276, vlSelfRef.u_decoder__DOT__rs1_data, vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs1_data 
            = vlSelfRef.u_decoder__DOT__rs1_data;
    }
    vlSelfRef.id_rs1_data = vlSelfRef.u_decoder__DOT__rs1_data;
    if ((vlSelfRef.u_decoder__DOT__rs2_data ^ vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 2340, vlSelfRef.u_decoder__DOT__rs2_data, vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data);
        vlSelfRef.u_decoder__DOT____Vtogcov__rs2_data 
            = vlSelfRef.u_decoder__DOT__rs2_data;
    }
    vlSelfRef.id_rs2_data = vlSelfRef.u_decoder__DOT__rs2_data;
    if ((vlSelfRef.id_rs1_data ^ vlSelfRef.__Vtogcov__id_rs1_data)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 752, vlSelfRef.id_rs1_data, vlSelfRef.__Vtogcov__id_rs1_data);
        vlSelfRef.__Vtogcov__id_rs1_data = vlSelfRef.id_rs1_data;
    }
    vlSelfRef.u_execute__DOT__regRead_1 = vlSelfRef.id_rs1_data;
    if ((vlSelfRef.id_rs2_data ^ vlSelfRef.__Vtogcov__id_rs2_data)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 816, vlSelfRef.id_rs2_data, vlSelfRef.__Vtogcov__id_rs2_data);
        vlSelfRef.__Vtogcov__id_rs2_data = vlSelfRef.id_rs2_data;
    }
    vlSelfRef.u_execute__DOT__regRead_2 = vlSelfRef.id_rs2_data;
    if ((vlSelfRef.u_execute__DOT__regRead_1 ^ vlSelfRef.u_execute__DOT____Vtogcov__regRead_1)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3531, vlSelfRef.u_execute__DOT__regRead_1, vlSelfRef.u_execute__DOT____Vtogcov__regRead_1);
        vlSelfRef.u_execute__DOT____Vtogcov__regRead_1 
            = vlSelfRef.u_execute__DOT__regRead_1;
    }
    vlSelfRef.u_execute__DOT__JALR_target = (0xfffffffeU 
                                             & (vlSelfRef.u_execute__DOT__extend 
                                                + vlSelfRef.u_execute__DOT__regRead_1));
    vlSelfRef.u_execute__DOT__alu_in_a = ((1U == (IData)(vlSelfRef.u_execute__DOT__ALU_ASrc))
                                           ? ([&]() {
                ++(vlSymsp->__Vcoverage[4006]);
            }(), vlSelfRef.u_execute__DOT__PC) : ([&]() {
                ++(vlSymsp->__Vcoverage[4011]);
            }(), ((2U == (IData)(vlSelfRef.u_execute__DOT__ALU_ASrc))
                   ? ([&]() {
                        ++(vlSymsp->__Vcoverage[4007]);
                    }(), ((IData)(4U) + vlSelfRef.u_execute__DOT__PC))
                   : ([&]() {
                        ++(vlSymsp->__Vcoverage[4010]);
                    }(), ((3U == (IData)(vlSelfRef.u_execute__DOT__ALU_ASrc))
                           ? ([&]() {
                                ++(vlSymsp->__Vcoverage[4008]);
                            }(), 0U) : ([&]() {
                                ++(vlSymsp->__Vcoverage[4009]);
                            }(), vlSelfRef.u_execute__DOT__regRead_1))))));
    if ((vlSelfRef.u_execute__DOT__regRead_2 ^ vlSelfRef.u_execute__DOT____Vtogcov__regRead_2)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3595, vlSelfRef.u_execute__DOT__regRead_2, vlSelfRef.u_execute__DOT____Vtogcov__regRead_2);
        vlSelfRef.u_execute__DOT____Vtogcov__regRead_2 
            = vlSelfRef.u_execute__DOT__regRead_2;
    }
    vlSelfRef.u_execute__DOT__alu_in_b = ((IData)(vlSelfRef.u_execute__DOT__ALU_BSrc)
                                           ? ([&]() {
                ++(vlSymsp->__Vcoverage[4012]);
            }(), vlSelfRef.u_execute__DOT__extend) : 
                                          ([&]() {
                ++(vlSymsp->__Vcoverage[4013]);
            }(), vlSelfRef.u_execute__DOT__regRead_2));
    if ((vlSelfRef.u_execute__DOT__JALR_target ^ vlSelfRef.u_execute__DOT____Vtogcov__JALR_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3791, vlSelfRef.u_execute__DOT__JALR_target, vlSelfRef.u_execute__DOT____Vtogcov__JALR_target);
        vlSelfRef.u_execute__DOT____Vtogcov__JALR_target 
            = vlSelfRef.u_execute__DOT__JALR_target;
    }
    vlSelfRef.ex_jalr_target = vlSelfRef.u_execute__DOT__JALR_target;
    if ((vlSelfRef.u_execute__DOT__alu_in_a ^ vlSelfRef.u_execute__DOT____Vtogcov__alu_in_a)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3878, vlSelfRef.u_execute__DOT__alu_in_a, vlSelfRef.u_execute__DOT____Vtogcov__alu_in_a);
        vlSelfRef.u_execute__DOT____Vtogcov__alu_in_a 
            = vlSelfRef.u_execute__DOT__alu_in_a;
    }
    vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
        = vlSelfRef.u_execute__DOT__alu_in_a;
    if ((vlSelfRef.u_execute__DOT__alu_in_b ^ vlSelfRef.u_execute__DOT____Vtogcov__alu_in_b)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3942, vlSelfRef.u_execute__DOT__alu_in_b, vlSelfRef.u_execute__DOT____Vtogcov__alu_in_b);
        vlSelfRef.u_execute__DOT____Vtogcov__alu_in_b 
            = vlSelfRef.u_execute__DOT__alu_in_b;
    }
    vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b 
        = vlSelfRef.u_execute__DOT__alu_in_b;
    if ((vlSelfRef.ex_jalr_target ^ vlSelfRef.__Vtogcov__ex_jalr_target)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 338, vlSelfRef.ex_jalr_target, vlSelfRef.__Vtogcov__ex_jalr_target);
        vlSelfRef.__Vtogcov__ex_jalr_target = vlSelfRef.ex_jalr_target;
    }
    if ((vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
         ^ vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__alu_in_a)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 4026, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__alu_in_a);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__alu_in_a 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a;
    }
    if ((vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b 
         ^ vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__alu_in_b)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 4090, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__alu_in_b);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__alu_in_b 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b;
    }
    vlSelfRef.u_execute__DOT__u_alu__DOT__signed_greater_than_equal 
        = VL_GTES_III(32, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b);
    vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than 
        = VL_LTS_III(32, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b);
    vlSelfRef.u_execute__DOT__u_alu__DOT__unsigned_less_than 
        = (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
           < vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b);
    vlSelfRef.u_execute__DOT__u_alu__DOT__shamt = (0x1fU 
                                                   & vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b);
    if ((vlSelfRef.u_execute__DOT__u_alu__DOT__signed_greater_than_equal 
         ^ vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__signed_greater_than_equal)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 4422, vlSelfRef.u_execute__DOT__u_alu__DOT__signed_greater_than_equal, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__signed_greater_than_equal);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__signed_greater_than_equal 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__signed_greater_than_equal;
    }
    if ((vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than 
         ^ vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__signed_less_than)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 4294, vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__signed_less_than);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__signed_less_than 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than;
    }
    if ((vlSelfRef.u_execute__DOT__u_alu__DOT__unsigned_less_than 
         ^ vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__unsigned_less_than)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 4358, vlSelfRef.u_execute__DOT__u_alu__DOT__unsigned_less_than, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__unsigned_less_than);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__unsigned_less_than 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__unsigned_less_than;
    }
    if (((IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__shamt) 
         ^ (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__shamt))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 4220, vlSelfRef.u_execute__DOT__u_alu__DOT__shamt, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__shamt);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__shamt 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__shamt;
    }
    vlSelfRef.u_execute__DOT__u_alu__DOT__arithmetic_right_shift 
        = VL_SHIFTRS_III(32,32,5, vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a, (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__shamt));
    if ((vlSelfRef.u_execute__DOT__u_alu__DOT__arithmetic_right_shift 
         ^ vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__arithmetic_right_shift)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 4230, vlSelfRef.u_execute__DOT__u_alu__DOT__arithmetic_right_shift, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__arithmetic_right_shift);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__arithmetic_right_shift 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__arithmetic_right_shift;
    }
    vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_result 
        = ((0U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
            ? ([&]() {
                ++(vlSymsp->__Vcoverage[4486]);
            }(), (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                  + vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
            : ([&]() {
                ++(vlSymsp->__Vcoverage[4519]);
            }(), ((8U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                   ? ([&]() {
                        ++(vlSymsp->__Vcoverage[4487]);
                    }(), (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                          - vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                   : ([&]() {
                        ++(vlSymsp->__Vcoverage[4518]);
                    }(), ((4U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                           ? ([&]() {
                                ++(vlSymsp->__Vcoverage[4488]);
                            }(), (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                  ^ vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                           : ([&]() {
                                ++(vlSymsp->__Vcoverage[4517]);
                            }(), ((6U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                   ? ([&]() {
                                        ++(vlSymsp->__Vcoverage[4489]);
                                    }(), (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                          | vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                   : ([&]() {
                                        ++(vlSymsp->__Vcoverage[4516]);
                                    }(), ((7U == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                           ? ([&]() {
                                                ++(vlSymsp->__Vcoverage[4490]);
                                            }(), (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                  & vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                           : ([&]() {
                                                ++(vlSymsp->__Vcoverage[4515]);
                                            }(), ((2U 
                                                   == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                   ? 
                                                  ([&]() {
                                                        ++(vlSymsp->__Vcoverage[4491]);
                                                    }(), vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than)
                                                   : 
                                                  ([&]() {
                                                        ++(vlSymsp->__Vcoverage[4514]);
                                                    }(), 
                                                   ((3U 
                                                     == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                     ? 
                                                    ([&]() {
                                                                ++(vlSymsp->__Vcoverage[4492]);
                                                            }(), vlSelfRef.u_execute__DOT__u_alu__DOT__unsigned_less_than)
                                                     : 
                                                    ([&]() {
                                                                ++(vlSymsp->__Vcoverage[4513]);
                                                            }(), 
                                                     ((1U 
                                                       == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                       ? 
                                                      ([&]() {
                                                                        ++(vlSymsp->__Vcoverage[4493]);
                                                                    }(), 
                                                       (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                        << (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__shamt)))
                                                       : 
                                                      ([&]() {
                                                                        ++(vlSymsp->__Vcoverage[4512]);
                                                                    }(), 
                                                       ((5U 
                                                         == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                         ? 
                                                        ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4494]);
                                                                            }(), 
                                                         (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                          >> (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__shamt)))
                                                         : 
                                                        ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4511]);
                                                                            }(), 
                                                         ((0xdU 
                                                           == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                           ? 
                                                          ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4495]);
                                                                                }(), vlSelfRef.u_execute__DOT__u_alu__DOT__arithmetic_right_shift)
                                                           : 
                                                          ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4510]);
                                                                                }(), 
                                                           ((0x1fU 
                                                             == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                             ? 
                                                            ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4496]);
                                                                                }(), vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a)
                                                             : 
                                                            ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4509]);
                                                                                }(), 
                                                             ((0x10U 
                                                               == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                               ? 
                                                              ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4497]);
                                                                                }(), 
                                                               (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                                == vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                                               : 
                                                              ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4508]);
                                                                                }(), 
                                                               ((0x11U 
                                                                 == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                                 ? 
                                                                ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4498]);
                                                                                }(), 
                                                                 (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                                  != vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                                                 : 
                                                                ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4507]);
                                                                                }(), 
                                                                 ((0x14U 
                                                                   == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                                   ? 
                                                                  ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4499]);
                                                                                }(), vlSelfRef.u_execute__DOT__u_alu__DOT__signed_less_than)
                                                                   : 
                                                                  ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4506]);
                                                                                }(), 
                                                                   ((0x15U 
                                                                     == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                                     ? 
                                                                    ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4500]);
                                                                                }(), vlSelfRef.u_execute__DOT__u_alu__DOT__signed_greater_than_equal)
                                                                     : 
                                                                    ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4505]);
                                                                                }(), 
                                                                     ((0x16U 
                                                                       == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                                       ? 
                                                                      ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4501]);
                                                                                }(), 
                                                                       (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                                        < vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                                                       : 
                                                                      ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4504]);
                                                                                }(), 
                                                                       ((0x17U 
                                                                         == (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_Control))
                                                                         ? 
                                                                        ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4502]);
                                                                                }(), 
                                                                         (vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_a 
                                                                          >= vlSelfRef.u_execute__DOT__u_alu__DOT__alu_in_b))
                                                                         : 
                                                                        ([&]() {
                                                                                ++(vlSymsp->__Vcoverage[4503]);
                                                                                }(), 0U))))))))))))))))))))))))))))))))));
    if ((vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_result 
         ^ vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__ALU_result)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 4154, vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_result, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__ALU_result);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__ALU_result 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_result;
    }
    vlSelfRef.u_execute__DOT__u_alu__DOT__cmp_out = 
        (1U & vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_result);
    vlSelfRef.u_execute__DOT__ALU_result = vlSelfRef.u_execute__DOT__u_alu__DOT__ALU_result;
    if (((IData)(vlSelfRef.u_execute__DOT__u_alu__DOT__cmp_out) 
         ^ (IData)(vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__cmp_out))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 4218, vlSelfRef.u_execute__DOT__u_alu__DOT__cmp_out, vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__cmp_out);
        vlSelfRef.u_execute__DOT__u_alu__DOT____Vtogcov__cmp_out 
            = vlSelfRef.u_execute__DOT__u_alu__DOT__cmp_out;
    }
    vlSelfRef.u_execute__DOT__alu_cmp_out = vlSelfRef.u_execute__DOT__u_alu__DOT__cmp_out;
    if ((vlSelfRef.u_execute__DOT__ALU_result ^ vlSelfRef.u_execute__DOT____Vtogcov__ALU_result)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 3725, vlSelfRef.u_execute__DOT__ALU_result, vlSelfRef.u_execute__DOT____Vtogcov__ALU_result);
        vlSelfRef.u_execute__DOT____Vtogcov__ALU_result 
            = vlSelfRef.u_execute__DOT__ALU_result;
    }
    vlSelfRef.ex_alu_result = vlSelfRef.u_execute__DOT__ALU_result;
    if (((IData)(vlSelfRef.u_execute__DOT__alu_cmp_out) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__alu_cmp_out))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3867, vlSelfRef.u_execute__DOT__alu_cmp_out, vlSelfRef.u_execute__DOT____Vtogcov__alu_cmp_out);
        vlSelfRef.u_execute__DOT____Vtogcov__alu_cmp_out 
            = vlSelfRef.u_execute__DOT__alu_cmp_out;
    }
    vlSelfRef.u_execute__DOT__branch_taken = ((IData)(vlSelfRef.u_execute__DOT__alu_cmp_out) 
                                              & (IData)(vlSelfRef.u_execute__DOT__branch_op));
    if ((vlSelfRef.ex_alu_result ^ vlSelfRef.__Vtogcov__ex_alu_result)) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 888, vlSelfRef.ex_alu_result, vlSelfRef.__Vtogcov__ex_alu_result);
        vlSelfRef.__Vtogcov__ex_alu_result = vlSelfRef.ex_alu_result;
    }
    vlSelfRef.id_ex_data_in[0U] = (IData)((((QData)((IData)(vlSelfRef.ex_alu_result)) 
                                            << 0x20U) 
                                           | (QData)((IData)(vlSelfRef.id_rs2_data))));
    vlSelfRef.id_ex_data_in[1U] = (IData)(((((QData)((IData)(vlSelfRef.ex_alu_result)) 
                                             << 0x20U) 
                                            | (QData)((IData)(vlSelfRef.id_rs2_data))) 
                                           >> 0x20U));
    vlSelfRef.id_ex_data_in[2U] = ((0x1e00U & vlSelfRef.id_ex_data_in[2U]) 
                                   | (0x1fffU & (((IData)(vlSelfRef.id_mem_wbe) 
                                                  << 5U) 
                                                 | (IData)(vlSelfRef.id_rd))));
    if (((IData)(vlSelfRef.u_execute__DOT__branch_taken) 
         ^ (IData)(vlSelfRef.u_execute__DOT____Vtogcov__branch_taken))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 3789, vlSelfRef.u_execute__DOT__branch_taken, vlSelfRef.u_execute__DOT____Vtogcov__branch_taken);
        vlSelfRef.u_execute__DOT____Vtogcov__branch_taken 
            = vlSelfRef.u_execute__DOT__branch_taken;
    }
    vlSelfRef.ex_branch_taken = vlSelfRef.u_execute__DOT__branch_taken;
    vlSelfRef.u_ex_mem_reg__DOT__data_in[0U] = vlSelfRef.id_ex_data_in[0U];
    vlSelfRef.u_ex_mem_reg__DOT__data_in[1U] = vlSelfRef.id_ex_data_in[1U];
    vlSelfRef.u_ex_mem_reg__DOT__data_in[2U] = vlSelfRef.id_ex_data_in[2U];
    if ((0x1000U & (vlSelfRef.id_ex_data_in[2U] ^ vlSelfRef.__Vtogcov__id_ex_data_in[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1030, 
                               (vlSelfRef.id_ex_data_in[2U] 
                                >> 0xcU), (vlSelfRef.__Vtogcov__id_ex_data_in[2U] 
                                           >> 0xcU));
        vlSelfRef.__Vtogcov__id_ex_data_in[2U] = ((0xfffU 
                                                   & vlSelfRef.__Vtogcov__id_ex_data_in[2U]) 
                                                  | (0x1000U 
                                                     & vlSelfRef.id_ex_data_in[2U]));
    }
    if ((0x800U & (vlSelfRef.id_ex_data_in[2U] ^ vlSelfRef.__Vtogcov__id_ex_data_in[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1032, 
                               (vlSelfRef.id_ex_data_in[2U] 
                                >> 0xbU), (vlSelfRef.__Vtogcov__id_ex_data_in[2U] 
                                           >> 0xbU));
        vlSelfRef.__Vtogcov__id_ex_data_in[2U] = ((0x17ffU 
                                                   & vlSelfRef.__Vtogcov__id_ex_data_in[2U]) 
                                                  | (0x800U 
                                                     & vlSelfRef.id_ex_data_in[2U]));
    }
    if ((0x400U & (vlSelfRef.id_ex_data_in[2U] ^ vlSelfRef.__Vtogcov__id_ex_data_in[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1034, 
                               (vlSelfRef.id_ex_data_in[2U] 
                                >> 0xaU), (vlSelfRef.__Vtogcov__id_ex_data_in[2U] 
                                           >> 0xaU));
        vlSelfRef.__Vtogcov__id_ex_data_in[2U] = ((0x1bffU 
                                                   & vlSelfRef.__Vtogcov__id_ex_data_in[2U]) 
                                                  | (0x400U 
                                                     & vlSelfRef.id_ex_data_in[2U]));
    }
    if ((0x200U & (vlSelfRef.id_ex_data_in[2U] ^ vlSelfRef.__Vtogcov__id_ex_data_in[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1036, 
                               (vlSelfRef.id_ex_data_in[2U] 
                                >> 9U), (vlSelfRef.__Vtogcov__id_ex_data_in[2U] 
                                         >> 9U));
        vlSelfRef.__Vtogcov__id_ex_data_in[2U] = ((0x1dffU 
                                                   & vlSelfRef.__Vtogcov__id_ex_data_in[2U]) 
                                                  | (0x200U 
                                                     & vlSelfRef.id_ex_data_in[2U]));
    }
    if ((0xfU & (((vlSelfRef.id_ex_data_in[2U] << 0x1bU) 
                  | (vlSelfRef.id_ex_data_in[2U] >> 5U)) 
                 ^ ((vlSelfRef.__Vtogcov__id_ex_data_in[2U] 
                     << 0x1bU) | (vlSelfRef.__Vtogcov__id_ex_data_in[2U] 
                                  >> 5U))))) {
        VL_COV_TOGGLE_CHG_ST_I(4, vlSymsp->__Vcoverage + 1038, 
                               ((vlSelfRef.id_ex_data_in[2U] 
                                 << 0x1bU) | (vlSelfRef.id_ex_data_in[2U] 
                                              >> 5U)), 
                               ((vlSelfRef.__Vtogcov__id_ex_data_in[2U] 
                                 << 0x1bU) | (vlSelfRef.__Vtogcov__id_ex_data_in[2U] 
                                              >> 5U)));
        vlSelfRef.__Vtogcov__id_ex_data_in[2U] = ((0x1e1fU 
                                                   & vlSelfRef.__Vtogcov__id_ex_data_in[2U]) 
                                                  | (0x1e0U 
                                                     & vlSelfRef.id_ex_data_in[2U]));
    }
    if ((0x1fU & (vlSelfRef.id_ex_data_in[2U] ^ vlSelfRef.__Vtogcov__id_ex_data_in[2U]))) {
        VL_COV_TOGGLE_CHG_ST_I(5, vlSymsp->__Vcoverage + 1046, 
                               vlSelfRef.id_ex_data_in[2U], 
                               vlSelfRef.__Vtogcov__id_ex_data_in[2U]);
        vlSelfRef.__Vtogcov__id_ex_data_in[2U] = ((0x1fe0U 
                                                   & vlSelfRef.__Vtogcov__id_ex_data_in[2U]) 
                                                  | (0x1fU 
                                                     & vlSelfRef.id_ex_data_in[2U]));
    }
    if ((vlSelfRef.id_ex_data_in[1U] ^ vlSelfRef.__Vtogcov__id_ex_data_in[1U])) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 1056, 
                               vlSelfRef.id_ex_data_in[1U], 
                               vlSelfRef.__Vtogcov__id_ex_data_in[1U]);
        vlSelfRef.__Vtogcov__id_ex_data_in[1U] = vlSelfRef.id_ex_data_in[1U];
    }
    if ((vlSelfRef.id_ex_data_in[0U] ^ vlSelfRef.__Vtogcov__id_ex_data_in[0U])) {
        VL_COV_TOGGLE_CHG_ST_I(32, vlSymsp->__Vcoverage + 1120, 
                               vlSelfRef.id_ex_data_in[0U], 
                               vlSelfRef.__Vtogcov__id_ex_data_in[0U]);
        vlSelfRef.__Vtogcov__id_ex_data_in[0U] = vlSelfRef.id_ex_data_in[0U];
    }
    if (((IData)(vlSelfRef.ex_branch_taken) ^ (IData)(vlSelfRef.__Vtogcov__ex_branch_taken))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 208, vlSelfRef.ex_branch_taken, vlSelfRef.__Vtogcov__ex_branch_taken);
        vlSelfRef.__Vtogcov__ex_branch_taken = vlSelfRef.ex_branch_taken;
    }
    vlSelfRef.flush = (((1U == (IData)(vlSelfRef.id_pc_sel)) 
                        & (IData)(vlSelfRef.ex_branch_taken)) 
                       | ((2U == (IData)(vlSelfRef.id_pc_sel)) 
                          | (3U == (IData)(vlSelfRef.id_pc_sel))));
    __Vtemp_2[0U] = (vlSelfRef.u_ex_mem_reg__DOT__data_in[0U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_in[0U]);
    __Vtemp_2[1U] = (vlSelfRef.u_ex_mem_reg__DOT__data_in[1U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_in[1U]);
    __Vtemp_2[2U] = (vlSelfRef.u_ex_mem_reg__DOT__data_in[2U] 
                     ^ vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_in[2U]);
    if (__Vtemp_2) {
        VL_COV_TOGGLE_CHG_ST_W(77, vlSymsp->__Vcoverage + 4532, vlSelfRef.u_ex_mem_reg__DOT__data_in, vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_in);
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_in[0U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_in[0U];
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_in[1U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_in[1U];
        vlSelfRef.u_ex_mem_reg__DOT____Vtogcov__data_in[2U] 
            = vlSelfRef.u_ex_mem_reg__DOT__data_in[2U];
    }
    if (((IData)(vlSelfRef.flush) ^ (IData)(vlSelfRef.__Vtogcov__flush))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 72, vlSelfRef.flush, vlSelfRef.__Vtogcov__flush);
        vlSelfRef.__Vtogcov__flush = vlSelfRef.flush;
    }
}

VL_INLINE_OPT void VCoreTop_CoreTop___nba_comb__TOP__CoreTop__6(VCoreTop_CoreTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+      VCoreTop_CoreTop___nba_comb__TOP__CoreTop__6\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.real_if_id_flush = ((IData)(vlSelfRef.flush) 
                                  | (IData)(vlSelfRef.flush_d));
    if (((IData)(vlSelfRef.real_if_id_flush) ^ (IData)(vlSelfRef.__Vtogcov__real_if_id_flush))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1412, vlSelfRef.real_if_id_flush, vlSelfRef.__Vtogcov__real_if_id_flush);
        vlSelfRef.__Vtogcov__real_if_id_flush = vlSelfRef.real_if_id_flush;
    }
    vlSelfRef.u_if_id_reg__DOT__flush = vlSelfRef.real_if_id_flush;
    if (((IData)(vlSelfRef.u_if_id_reg__DOT__flush) 
         ^ (IData)(vlSelfRef.u_if_id_reg__DOT____Vtogcov__flush))) {
        VL_COV_TOGGLE_CHG_ST_I(1, vlSymsp->__Vcoverage + 1433, vlSelfRef.u_if_id_reg__DOT__flush, vlSelfRef.u_if_id_reg__DOT____Vtogcov__flush);
        vlSelfRef.u_if_id_reg__DOT____Vtogcov__flush 
            = vlSelfRef.u_if_id_reg__DOT__flush;
    }
}

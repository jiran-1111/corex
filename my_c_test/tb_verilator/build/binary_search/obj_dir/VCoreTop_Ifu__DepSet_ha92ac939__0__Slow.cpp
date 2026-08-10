// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_Ifu.h"
#include "VCoreTop__Syms.h"

VL_ATTR_COLD void VCoreTop_Ifu___configure_coverage(VCoreTop_Ifu* vlSelf, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        VCoreTop_Ifu___configure_coverage\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    (void)first;  // Prevent unused variable warning
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5336]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 14, 35, "", "v_toggle/Ifu", "clk");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5338]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 15, 35, "", "v_toggle/Ifu", "rst");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5340]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 16, 35, "", "v_toggle/Ifu", "start");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5342]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 17, 35, "", "v_toggle/Ifu", "stall");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[5344]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 18, 35, "", "v_toggle/Ifu", "program_address");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[5408]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 20, 35, "", "v_toggle/Ifu", "JAL_target");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[5472]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 21, 35, "", "v_toggle/Ifu", "JALR_target");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[5536]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 22, 35, "", "v_toggle/Ifu", "branch_target");
    vlSelf->__vlCoverToggleInsert(0, 1, 1, &(vlSymsp->__Vcoverage[5600]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 23, 35, "", "v_toggle/Ifu", "pc_sel_execute");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5604]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 24, 35, "", "v_toggle/Ifu", "branch_taken");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[5606]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 26, 35, "", "v_toggle/Ifu", "instruction");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[5670]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 27, 35, "", "v_toggle/Ifu", "inst_PC");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5734]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 28, 35, "", "v_toggle/Ifu", "valid");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[5736]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 30, 28, "", "v_toggle/Ifu", "PC_reg");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[5800]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 31, 28, "", "v_toggle/Ifu", "PC_plus4");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[5864]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 32, 28, "", "v_toggle/Ifu", "inst_PC_reg");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[5928]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 33, 28, "", "v_toggle/Ifu", "next_PC");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5992]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 35, 11, "", "v_toggle/Ifu", "imem_gnt");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5994]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 36, 11, "", "v_toggle/Ifu", "imem_err");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5996]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 37, 11, "", "v_toggle/Ifu", "fetch");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[5998]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 38, 11, "", "v_toggle/Ifu", "jump_or_branch_taken");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6000]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 50, 32, "", "v_expr/Ifu", "(branch_taken==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6001]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 50, 32, "", "v_expr/Ifu", "(branch_taken==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6002]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 50, 47, "", "v_branch/Ifu", "cond_then", "50");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6003]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 50, 48, "", "v_branch/Ifu", "cond_else", "50");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6004]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 50, 18, "", "v_line/Ifu", "case", "50");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6005]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 51, 18, "", "v_line/Ifu", "case", "51");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6006]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 52, 18, "", "v_line/Ifu", "case", "52");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6007]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 53, 13, "", "v_line/Ifu", "case", "53");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6008]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 48, 5, "", "v_line/Ifu", "block", "48-49");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6009]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 76, 18, "", "v_line/Ifu", "if", "76-77");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6010]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 76, 19, "", "v_line/Ifu", "else", "78-79");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6011]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 76, 28, "", "v_expr/Ifu", "(stall==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6012]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 76, 28, "", "v_expr/Ifu", "(start==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6013]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 76, 28, "", "v_expr/Ifu", "(start==0 && stall==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6014]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 74, 9, "", "v_line/Ifu", "elsif", "74-75");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6015]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 73, 5, "", "v_line/Ifu", "block", "73");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6016]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 91, 18, "", "v_branch/Ifu", "if", "91-92");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6017]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 91, 19, "", "v_branch/Ifu", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6018]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 91, 28, "", "v_expr/Ifu", "(fetch==1 && imem_gnt==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6019]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 91, 28, "", "v_expr/Ifu", "(imem_gnt==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6020]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 91, 28, "", "v_expr/Ifu", "(fetch==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6021]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 89, 18, "", "v_line/Ifu", "elsif", "89-90");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6022]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 87, 18, "", "v_line/Ifu", "elsif", "87-88");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6023]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 85, 9, "", "v_line/Ifu", "elsif", "85-86");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6024]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 85, 17, "", "v_expr/Ifu", "(start==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6025]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 85, 17, "", "v_expr/Ifu", "(rst==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6026]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 85, 17, "", "v_expr/Ifu", "(rst==0 && start==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6027]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 84, 5, "", "v_line/Ifu", "block", "84");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6028]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 102, 18, "", "v_branch/Ifu", "if", "102-103");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6029]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 102, 19, "", "v_branch/Ifu", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6030]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 102, 28, "", "v_expr/Ifu", "(fetch==1 && imem_gnt==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6031]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 102, 28, "", "v_expr/Ifu", "(imem_gnt==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6032]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 102, 28, "", "v_expr/Ifu", "(fetch==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6033]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 100, 18, "", "v_line/Ifu", "elsif", "100-101");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6034]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 98, 9, "", "v_line/Ifu", "elsif", "98-99");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6035]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 98, 17, "", "v_expr/Ifu", "(start==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6036]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 98, 17, "", "v_expr/Ifu", "(rst==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6037]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 98, 17, "", "v_expr/Ifu", "(rst==0 && start==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6038]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 97, 5, "", "v_line/Ifu", "block", "97");
}

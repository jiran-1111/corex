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
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[194]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 50, 32, "", "v_expr/Ifu", "(branch_taken==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[195]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 50, 32, "", "v_expr/Ifu", "(branch_taken==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[196]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 50, 47, "", "v_branch/Ifu", "cond_then", "50");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[197]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 50, 48, "", "v_branch/Ifu", "cond_else", "50");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[198]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 50, 18, "", "v_line/Ifu", "case", "50");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[199]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 51, 18, "", "v_line/Ifu", "case", "51");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[200]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 52, 18, "", "v_line/Ifu", "case", "52");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[201]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 53, 13, "", "v_line/Ifu", "case", "53");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[202]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 48, 5, "", "v_line/Ifu", "block", "48-49");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[203]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 76, 18, "", "v_line/Ifu", "if", "76-77");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[204]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 76, 19, "", "v_line/Ifu", "else", "78-79");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[205]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 76, 28, "", "v_expr/Ifu", "(stall==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[206]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 76, 28, "", "v_expr/Ifu", "(start==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[207]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 76, 28, "", "v_expr/Ifu", "(start==0 && stall==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[208]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 74, 9, "", "v_line/Ifu", "elsif", "74-75");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[209]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 73, 5, "", "v_line/Ifu", "block", "73");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[210]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 91, 18, "", "v_branch/Ifu", "if", "91-92");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[211]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 91, 19, "", "v_branch/Ifu", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[212]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 91, 28, "", "v_expr/Ifu", "(fetch==1 && imem_gnt==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[213]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 91, 28, "", "v_expr/Ifu", "(imem_gnt==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[214]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 91, 28, "", "v_expr/Ifu", "(fetch==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[215]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 89, 18, "", "v_line/Ifu", "elsif", "89-90");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[216]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 87, 18, "", "v_line/Ifu", "elsif", "87-88");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[217]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 85, 9, "", "v_line/Ifu", "elsif", "85-86");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[218]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 85, 17, "", "v_expr/Ifu", "(start==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[219]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 85, 17, "", "v_expr/Ifu", "(rst==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[220]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 85, 17, "", "v_expr/Ifu", "(rst==0 && start==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[221]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 84, 5, "", "v_line/Ifu", "block", "84");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[222]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 102, 18, "", "v_branch/Ifu", "if", "102-103");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[223]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 102, 19, "", "v_branch/Ifu", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[224]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 102, 28, "", "v_expr/Ifu", "(fetch==1 && imem_gnt==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[225]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 102, 28, "", "v_expr/Ifu", "(imem_gnt==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[226]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 102, 28, "", "v_expr/Ifu", "(fetch==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[227]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 100, 18, "", "v_line/Ifu", "elsif", "100-101");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[228]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 98, 9, "", "v_line/Ifu", "elsif", "98-99");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[229]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 98, 17, "", "v_expr/Ifu", "(start==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[230]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 98, 17, "", "v_expr/Ifu", "(rst==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[231]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 98, 17, "", "v_expr/Ifu", "(rst==0 && start==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[232]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ifu.sv", 97, 5, "", "v_line/Ifu", "block", "97");
}

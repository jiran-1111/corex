// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_IMem.h"
#include "VCoreTop__Syms.h"

VL_ATTR_COLD void VCoreTop_IMem___configure_coverage(VCoreTop_IMem* vlSelf, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VCoreTop_IMem___configure_coverage\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    (void)first;  // Prevent unused variable warning
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[6391]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 19, 17, "", "v_toggle/IMem", "clk");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[6393]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 20, 17, "", "v_toggle/IMem", "rst");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[6395]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 34, 11, "", "v_toggle/IMem", "gnt");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[6397]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 35, 11, "", "v_toggle/IMem", "err");
    vlSelf->__vlCoverToggleInsert(0, 11, 1, &(vlSymsp->__Vcoverage[6399]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 40, 32, "", "v_toggle/IMem", "mem_addr");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[6423]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 44, 28, "", "v_toggle/IMem", "rdata_q");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6487]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 51, 9, "", "v_branch/IMem", "if", "51-52");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6488]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 51, 10, "", "v_branch/IMem", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6489]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 51, 22, "", "v_expr/IMem", "(ibus.req==1 && gnt==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6490]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 51, 22, "", "v_expr/IMem", "(gnt==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6491]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 51, 22, "", "v_expr/IMem", "(ibus.req==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6492]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 50, 5, "", "v_line/IMem", "block", "50");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6493]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 63, 34, "", "v_expr/IMem", "(ibus.req==1 && gnt==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6494]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 63, 34, "", "v_expr/IMem", "(gnt==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6495]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 63, 34, "", "v_expr/IMem", "(ibus.req==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6496]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 60, 9, "", "v_branch/IMem", "if", "60-61");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6497]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 60, 10, "", "v_branch/IMem", "else", "62-63");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[6498]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 59, 5, "", "v_line/IMem", "block", "59");
}

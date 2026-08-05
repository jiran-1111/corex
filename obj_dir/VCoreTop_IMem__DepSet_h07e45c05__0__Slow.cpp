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
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[233]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 51, 9, "", "v_branch/IMem", "if", "51-52");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[234]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 51, 10, "", "v_branch/IMem", "else", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[235]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 51, 22, "", "v_expr/IMem", "(ibus.req==1 && gnt==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[236]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 51, 22, "", "v_expr/IMem", "(gnt==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[237]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 51, 22, "", "v_expr/IMem", "(ibus.req==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[238]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 50, 5, "", "v_line/IMem", "block", "50");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[239]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 63, 34, "", "v_expr/IMem", "(ibus.req==1 && gnt==1) => 1", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[240]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 63, 34, "", "v_expr/IMem", "(gnt==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[241]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 63, 34, "", "v_expr/IMem", "(ibus.req==0) => 0", "");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[242]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 60, 9, "", "v_branch/IMem", "if", "60-61");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[243]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 60, 10, "", "v_branch/IMem", "else", "62-63");
    vlSelf->__vlCoverInsert(&(vlSymsp->__Vcoverage[244]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 59, 5, "", "v_line/IMem", "block", "59");
}

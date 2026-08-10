// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_IMemTop.h"
#include "VCoreTop__Syms.h"

VL_ATTR_COLD void VCoreTop_IMemTop___configure_coverage(VCoreTop_IMemTop* vlSelf, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VCoreTop_IMemTop___configure_coverage\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    (void)first;  // Prevent unused variable warning
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[6039]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 76, 17, "", "v_toggle/IMemTop", "clk");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[6041]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 77, 17, "", "v_toggle/IMemTop", "rst");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[6043]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 80, 17, "", "v_toggle/IMemTop", "req");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[6045]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 81, 34, "", "v_toggle/IMemTop", "addr");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[6109]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 84, 18, "", "v_toggle/IMemTop", "gnt");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[6111]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 85, 18, "", "v_toggle/IMemTop", "ack");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[6113]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 86, 18, "", "v_toggle/IMemTop", "err");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[6115]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/imem.sv", 87, 35, "", "v_toggle/IMemTop", "rdata");
}

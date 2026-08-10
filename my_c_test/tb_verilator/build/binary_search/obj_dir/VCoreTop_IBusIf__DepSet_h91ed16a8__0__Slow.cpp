// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_IBusIf.h"
#include "VCoreTop__Syms.h"

VL_ATTR_COLD void VCoreTop_IBusIf___configure_coverage(VCoreTop_IBusIf* vlSelf, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VCoreTop_IBusIf___configure_coverage\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    (void)first;  // Prevent unused variable warning
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[6499]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ibus_if.sv", 20, 11, "", "v_toggle/IBusIf", "req");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[6501]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ibus_if.sv", 21, 28, "", "v_toggle/IBusIf", "addr");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[6565]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ibus_if.sv", 29, 11, "", "v_toggle/IBusIf", "gnt");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[6567]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ibus_if.sv", 30, 11, "", "v_toggle/IBusIf", "ack");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[6569]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ibus_if.sv", 31, 11, "", "v_toggle/IBusIf", "err");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[6571]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/ibus_if.sv", 32, 28, "", "v_toggle/IBusIf", "rdata");
}

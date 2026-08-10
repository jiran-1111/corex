// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_DBusIf.h"
#include "VCoreTop__Syms.h"

VL_ATTR_COLD void VCoreTop_DBusIf___configure_coverage(VCoreTop_DBusIf* vlSelf, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VCoreTop_DBusIf___configure_coverage\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    (void)first;  // Prevent unused variable warning
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[6179]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dbus_if.sv", 18, 11, "", "v_toggle/DBusIf", "read");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[6181]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dbus_if.sv", 19, 11, "", "v_toggle/DBusIf", "write");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[6183]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dbus_if.sv", 20, 28, "", "v_toggle/DBusIf", "addr");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[6247]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dbus_if.sv", 21, 28, "", "v_toggle/DBusIf", "wdata");
    vlSelf->__vlCoverToggleInsert(0, 3, 1, &(vlSymsp->__Vcoverage[6311]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dbus_if.sv", 22, 32, "", "v_toggle/DBusIf", "wbe");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[6319]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dbus_if.sv", 25, 11, "", "v_toggle/DBusIf", "gnt");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[6321]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dbus_if.sv", 26, 11, "", "v_toggle/DBusIf", "rack");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[6323]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dbus_if.sv", 27, 11, "", "v_toggle/DBusIf", "wack");
    vlSelf->__vlCoverToggleInsert(0, 0, 0, &(vlSymsp->__Vcoverage[6325]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dbus_if.sv", 28, 11, "", "v_toggle/DBusIf", "err");
    vlSelf->__vlCoverToggleInsert(0, 31, 1, &(vlSymsp->__Vcoverage[6327]), first, "/home/ranrr/pku_workspace/corex/hdl_sv/core/dbus_if.sv", 29, 28, "", "v_toggle/DBusIf", "rdata");
}

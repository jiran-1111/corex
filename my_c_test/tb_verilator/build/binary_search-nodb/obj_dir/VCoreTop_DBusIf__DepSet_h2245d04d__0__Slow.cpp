// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_DBusIf.h"

VL_ATTR_COLD void VCoreTop_DBusIf___ctor_var_reset(VCoreTop_DBusIf* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            VCoreTop_DBusIf___ctor_var_reset\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->read = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13916498648420597437ull);
    vlSelf->write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6996823270756637333ull);
    vlSelf->addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14934084843038794831ull);
    vlSelf->wdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12890271867161903902ull);
    vlSelf->wbe = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16743329354995135245ull);
    vlSelf->gnt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12311452861025780666ull);
    vlSelf->rack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4526036584141475410ull);
    vlSelf->wack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11010353815286133213ull);
    vlSelf->err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10541192957841604819ull);
    vlSelf->rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10065165116613087284ull);
}

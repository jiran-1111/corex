// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_IBusIf.h"

VL_ATTR_COLD void VCoreTop_IBusIf___ctor_var_reset(VCoreTop_IBusIf* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VCoreTop_IBusIf___ctor_var_reset\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13082299938826996746ull);
    vlSelf->addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14934084843038794831ull);
    vlSelf->gnt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12311452861025780666ull);
    vlSelf->ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4249660348707286186ull);
    vlSelf->err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10541192957841604819ull);
    vlSelf->rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10065165116613087284ull);
}

VL_ATTR_COLD void VCoreTop_IBusIf___configure_coverage(VCoreTop_IBusIf* vlSelf, bool first) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VCoreTop_IBusIf___configure_coverage\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    (void)first;  // Prevent unused variable warning
}

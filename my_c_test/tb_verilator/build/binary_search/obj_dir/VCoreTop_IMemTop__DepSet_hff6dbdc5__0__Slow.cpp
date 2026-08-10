// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_IMemTop.h"

VL_ATTR_COLD void VCoreTop_IMemTop___ctor_var_reset(VCoreTop_IMemTop* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+          VCoreTop_IMemTop___ctor_var_reset\n"); );
    VCoreTop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13082299938826996746ull);
    vlSelf->addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14934084843038794831ull);
    vlSelf->gnt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12311452861025780666ull);
    vlSelf->ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4249660348707286186ull);
    vlSelf->err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10541192957841604819ull);
    vlSelf->rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 10065165116613087284ull);
    vlSelf->__Vtogcov__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8977754005702907422ull);
    vlSelf->__Vtogcov__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6831442562242317817ull);
    vlSelf->__Vtogcov__req = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14624555523238898304ull);
    vlSelf->__Vtogcov__addr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15196738177229683842ull);
    vlSelf->__Vtogcov__gnt = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16808793585744629073ull);
    vlSelf->__Vtogcov__ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14740064200053253335ull);
    vlSelf->__Vtogcov__err = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 347842528286250480ull);
    vlSelf->__Vtogcov__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9813798444969789124ull);
}

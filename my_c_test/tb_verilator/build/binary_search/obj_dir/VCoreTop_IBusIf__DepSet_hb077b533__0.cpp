// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VCoreTop.h for the primary calling header

#include "VCoreTop__pch.h"
#include "VCoreTop_IBusIf.h"

std::string VL_TO_STRING(const VCoreTop_IBusIf* obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+              VCoreTop_IBusIf::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->name() : "null");
}

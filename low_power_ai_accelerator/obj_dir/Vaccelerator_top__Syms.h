// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VACCELERATOR_TOP__SYMS_H_
#define VERILATED_VACCELERATOR_TOP__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vaccelerator_top.h"

// INCLUDE MODULE CLASSES
#include "Vaccelerator_top___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES)Vaccelerator_top__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vaccelerator_top* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vaccelerator_top___024root     TOP;

    // CONSTRUCTORS
    Vaccelerator_top__Syms(VerilatedContext* contextp, const char* namep, Vaccelerator_top* modelp);
    ~Vaccelerator_top__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard

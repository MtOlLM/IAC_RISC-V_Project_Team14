// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdut.h for the primary calling header

#ifndef VERILATED_VDUT___024ROOT_H_
#define VERILATED_VDUT___024ROOT_H_  // guard

#include "verilated.h"


class Vdut__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdut___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(eq,0,0);
    VL_IN8(opcode,6,0);
    VL_IN8(funct3,14,12);
    VL_IN8(funct7_5,0,0);
    VL_OUT8(reg_write,0,0);
    VL_OUT8(pc_src,0,0);
    VL_OUT8(imm_src,1,0);
    VL_OUT8(ALU_control,2,0);
    VL_OUT8(ALU_src,0,0);
    VL_OUT8(mem_write,0,0);
    VL_OUT8(result_src,0,0);
    CData/*0:0*/ control_unit__DOT__branch;
    CData/*1:0*/ control_unit__DOT__ALU_op;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<0> __VactTriggered;
    VlTriggerVec<0> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdut__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdut___024root(Vdut__Syms* symsp, const char* v__name);
    ~Vdut___024root();
    VL_UNCOPYABLE(Vdut___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard

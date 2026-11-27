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
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*3:0*/ top__DOT__branch_ctrl;
    CData/*0:0*/ top__DOT__reg_write;
    CData/*1:0*/ top__DOT__pc_src;
    CData/*2:0*/ top__DOT__imm_src;
    CData/*3:0*/ top__DOT__ALU_control;
    CData/*1:0*/ top__DOT__ALU_src;
    CData/*3:0*/ top__DOT__mem_write;
    CData/*1:0*/ top__DOT__result_src;
    CData/*0:0*/ top__DOT____Vcellinp__control_unit__funct7_5;
    CData/*2:0*/ top__DOT____Vcellinp__control_unit__funct3;
    CData/*6:0*/ top__DOT____Vcellinp__control_unit__opcode;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactContinue;
    SData/*15:0*/ __VdfgRegularize_hd87f99a1_0_0;
    VL_OUT(a0,31,0);
    IData/*31:0*/ top__DOT__pc;
    IData/*31:0*/ top__DOT__inc_pc;
    IData/*31:0*/ top__DOT__imm_op;
    IData/*31:0*/ top__DOT__ALU_out;
    IData/*31:0*/ top__DOT__alu_op1;
    IData/*31:0*/ top__DOT__alu_op2;
    IData/*31:0*/ top__DOT__rs1;
    IData/*31:0*/ top__DOT__rs2;
    IData/*24:0*/ top__DOT____Vcellinp__sign_ext__in;
    IData/*31:0*/ top__DOT__regfile__DOT__unnamedblk1__DOT__i;
    IData/*31:0*/ top__DOT__program_counter__DOT__relative_pc;
    IData/*31:0*/ top__DOT__program_counter__DOT__absolute_pc;
    IData/*31:0*/ top__DOT__program_counter__DOT__next_pc;
    IData/*31:0*/ top__DOT__MCU__DOT__ram_data_out;
    IData/*23:0*/ __VdfgRegularize_hd87f99a1_0_1;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 4096> top__DOT__instr_mem__DOT__rom_array;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__regfile__DOT__register_file;
    VlUnpacked<CData/*7:0*/, 131072> top__DOT__MCU__DOT__data_RAM__DOT__ram_array;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

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

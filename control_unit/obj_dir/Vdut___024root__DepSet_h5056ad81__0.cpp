// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "Vdut__pch.h"
#include "Vdut___024root.h"

void Vdut___024root___ico_sequent__TOP__0(Vdut___024root* vlSelf);

void Vdut___024root___eval_ico(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vdut___024root___ico_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*0:0*/, 128> Vdut__ConstPool__TABLE_h15bd3065_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vdut__ConstPool__TABLE_h213f2dee_0;
extern const VlUnpacked<CData/*1:0*/, 128> Vdut__ConstPool__TABLE_ha4d94837_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vdut__ConstPool__TABLE_h899171e2_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vdut__ConstPool__TABLE_hff6fb0c7_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vdut__ConstPool__TABLE_h675ff796_0;
extern const VlUnpacked<CData/*0:0*/, 128> Vdut__ConstPool__TABLE_h6d51447d_0;

VL_INLINE_OPT void Vdut___024root___ico_sequent__TOP__0(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___ico_sequent__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = vlSelfRef.opcode;
    vlSelfRef.reg_write = Vdut__ConstPool__TABLE_h15bd3065_0
        [__Vtableidx1];
    vlSelfRef.control_unit__DOT__ALU_op = Vdut__ConstPool__TABLE_h213f2dee_0
        [__Vtableidx1];
    vlSelfRef.imm_src = Vdut__ConstPool__TABLE_ha4d94837_0
        [__Vtableidx1];
    vlSelfRef.ALU_src = Vdut__ConstPool__TABLE_h899171e2_0
        [__Vtableidx1];
    vlSelfRef.control_unit__DOT__branch = Vdut__ConstPool__TABLE_hff6fb0c7_0
        [__Vtableidx1];
    vlSelfRef.mem_write = Vdut__ConstPool__TABLE_h675ff796_0
        [__Vtableidx1];
    vlSelfRef.result_src = Vdut__ConstPool__TABLE_h6d51447d_0
        [__Vtableidx1];
    vlSelfRef.pc_src = ((~ (IData)(vlSelfRef.eq)) & (IData)(vlSelfRef.control_unit__DOT__branch));
    vlSelfRef.ALU_control = ((2U & (IData)(vlSelfRef.control_unit__DOT__ALU_op))
                              ? ((4U & (IData)(vlSelfRef.funct3))
                                  ? ((2U & (IData)(vlSelfRef.funct3))
                                      ? ((1U & (IData)(vlSelfRef.funct3))
                                          ? 2U : 3U)
                                      : 0U) : ((2U 
                                                & (IData)(vlSelfRef.funct3))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelfRef.funct3))
                                                    ? 0U
                                                    : 5U)
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelfRef.funct3))
                                                    ? 0U
                                                    : 
                                                   (((IData)(vlSelfRef.opcode) 
                                                     >> 5U) 
                                                    & (IData)(vlSelfRef.funct7_5)))))
                              : (IData)(vlSelfRef.control_unit__DOT__ALU_op));
}

void Vdut___024root___eval_triggers__ico(Vdut___024root* vlSelf);

bool Vdut___024root___eval_phase__ico(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__ico\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vdut___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vdut___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vdut___024root___eval_act(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vdut___024root___eval_nba(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vdut___024root___eval_triggers__act(Vdut___024root* vlSelf);

bool Vdut___024root___eval_phase__act(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__act\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<0> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vdut___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vdut___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vdut___024root___eval_phase__nba(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__nba\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vdut___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__ico(Vdut___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__nba(Vdut___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__act(Vdut___024root* vlSelf);
#endif  // VL_DEBUG

void Vdut___024root___eval(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vdut___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("control_unit.sv", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vdut___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vdut___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("control_unit.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelfRef.__VactIterCount))) {
#ifdef VL_DEBUG
                Vdut___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("control_unit.sv", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vdut___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vdut___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vdut___024root___eval_debug_assertions(Vdut___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_debug_assertions\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY((vlSelfRef.eq & 0xfeU))) {
        Verilated::overWidthError("eq");}
    if (VL_UNLIKELY((vlSelfRef.opcode & 0x80U))) {
        Verilated::overWidthError("opcode");}
    if (VL_UNLIKELY((vlSelfRef.funct3 & 0xf8U))) {
        Verilated::overWidthError("funct3");}
    if (VL_UNLIKELY((vlSelfRef.funct7_5 & 0xfeU))) {
        Verilated::overWidthError("funct7_5");}
}
#endif  // VL_DEBUG

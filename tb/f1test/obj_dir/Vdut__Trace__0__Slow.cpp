// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


VL_ATTR_COLD void Vdut___024root__trace_init_sub__TOP__0(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_init_sub__TOP__0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+68,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+70,0,"a0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("top", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+71,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+68,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+70,0,"a0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"instr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"inc_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+5,0,"imm_op",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"ALU_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"mem_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+8,0,"result",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"alu_op1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"alu_op2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"rs1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"rs2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"branch_ctrl",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+14,0,"reg_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"pc_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+16,0,"imm_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+17,0,"ALU_control",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+18,0,"ALU_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,1);
    tracep->declBus(c+19,0,"mem_write",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+20,0,"result_src",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->pushPrefix("ALU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+71,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+9,0,"ALUOp1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+10,0,"ALUOp2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+17,0,"ALUctrl",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+6,0,"ALUout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+13,0,"branch_ctrl",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("ALU_op1_mux", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+71,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"in0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+21,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+9,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("ALU_op2_mux", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+71,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"in0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+5,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+22,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+10,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("MCU", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+71,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+68,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"w_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+23,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+6,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"data_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"ram_data_out",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("data_RAM", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+72,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+68,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+19,0,"w_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+12,0,"data_in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"data_out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+25,0,"addr_low",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 16,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("control_unit", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+13,0,"branch_ctrl",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+26,0,"opcode",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+23,0,"funct3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 14,12);
    tracep->declBit(c+27,0,"funct7_5",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"reg_write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+15,0,"pc_src",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+16,0,"imm_src",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+17,0,"ALU_control",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+18,0,"ALU_src",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,1);
    tracep->declBus(c+19,0,"mem_write",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+20,0,"result_src",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+73,0,"ADD",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+74,0,"OPTYPE_R",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+75,0,"OPTYPE_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+76,0,"OPTYPE_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+77,0,"OPTYPE_B",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+78,0,"OPTYPE_LUI",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+79,0,"OPTYPE_AUIPC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+80,0,"OPTYPE_JALR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+81,0,"OPTYPE_I_L",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->declBus(c+82,0,"OPTYPE_JAL",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 6,0);
    tracep->popPrefix();
    tracep->pushPrefix("instr_mem", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+83,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+2,0,"data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+28,0,"addr_low",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 11,0);
    tracep->popPrefix();
    tracep->pushPrefix("program_counter", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+84,0,"RESET_PC",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+68,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+11,0,"rs1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+15,0,"pc_src",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+5,0,"imm_op",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+3,0,"pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"inc_pc",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+29,0,"relative_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+30,0,"absolute_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+31,0,"next_pc",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("regfile", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+71,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+85,0,"ADDRESS_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+32,0,"AD1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+33,0,"AD2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+34,0,"AD3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBit(c+68,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+14,0,"WE3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+8,0,"WD3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+11,0,"RD1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+12,0,"RD2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+70,0,"a0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("register_file", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+35+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->pushPrefix("unnamedblk1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+1,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("result_mux", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+71,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+6,0,"in0",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+7,0,"in1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+5,0,"in2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+4,0,"in3",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+20,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 1,0);
    tracep->declBus(c+8,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->pushPrefix("sign_ext", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+71,0,"OUTPUT_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+67,0,"in",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,7);
    tracep->declBus(c+16,0,"imm_src",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+5,0,"out",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vdut___024root__trace_init_top(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_init_top\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vdut___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vdut___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vdut___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdut___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vdut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vdut___024root__trace_register(Vdut___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_register\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vdut___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vdut___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vdut___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vdut___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vdut___024root__trace_const_0_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vdut___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_const_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vdut___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vdut___024root__trace_const_0_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_const_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+71,(0x20U),32);
    bufp->fullIData(oldp+72,(0x11U),32);
    bufp->fullCData(oldp+73,(0U),4);
    bufp->fullCData(oldp+74,(0x33U),7);
    bufp->fullCData(oldp+75,(0x13U),7);
    bufp->fullCData(oldp+76,(0x23U),7);
    bufp->fullCData(oldp+77,(0x63U),7);
    bufp->fullCData(oldp+78,(0x37U),7);
    bufp->fullCData(oldp+79,(0x17U),7);
    bufp->fullCData(oldp+80,(0x67U),7);
    bufp->fullCData(oldp+81,(3U),7);
    bufp->fullCData(oldp+82,(0x6fU),7);
    bufp->fullIData(oldp+83,(0xcU),32);
    bufp->fullIData(oldp+84,(0U),32);
    bufp->fullIData(oldp+85,(5U),32);
}

VL_ATTR_COLD void Vdut___024root__trace_full_0_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vdut___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_full_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vdut___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vdut___024root__trace_full_0_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_full_0_sub_0\n"); );
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelfRef.top__DOT__regfile__DOT__unnamedblk1__DOT__i),32);
    bufp->fullIData(oldp+2,(((vlSelfRef.top__DOT__instr_mem__DOT__rom_array
                              [(0xfffU & ((IData)(3U) 
                                          + vlSelfRef.top__DOT__pc))] 
                              << 0x18U) | vlSelfRef.__VdfgRegularize_hd87f99a1_0_1)),32);
    bufp->fullIData(oldp+3,(vlSelfRef.top__DOT__pc),32);
    bufp->fullIData(oldp+4,(vlSelfRef.top__DOT__inc_pc),32);
    bufp->fullIData(oldp+5,(vlSelfRef.top__DOT__imm_op),32);
    bufp->fullIData(oldp+6,(vlSelfRef.top__DOT__ALU_out),32);
    bufp->fullIData(oldp+7,(((4U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                              ? ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                  ? vlSelfRef.top__DOT__MCU__DOT__ram_data_out
                                  : ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                      ? (0xffffU & vlSelfRef.top__DOT__MCU__DOT__ram_data_out)
                                      : (0xffU & vlSelfRef.top__DOT__MCU__DOT__ram_data_out)))
                              : ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                  ? vlSelfRef.top__DOT__MCU__DOT__ram_data_out
                                  : ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                      ? (((- (IData)(
                                                     (1U 
                                                      & (vlSelfRef.top__DOT__MCU__DOT__ram_data_out 
                                                         >> 0xfU)))) 
                                          << 0x10U) 
                                         | (0xffffU 
                                            & vlSelfRef.top__DOT__MCU__DOT__ram_data_out))
                                      : (((- (IData)(
                                                     (1U 
                                                      & (vlSelfRef.top__DOT__MCU__DOT__ram_data_out 
                                                         >> 7U)))) 
                                          << 8U) | 
                                         (0xffU & vlSelfRef.top__DOT__MCU__DOT__ram_data_out)))))),32);
    bufp->fullIData(oldp+8,(((2U & (IData)(vlSelfRef.top__DOT__result_src))
                              ? ((1U & (IData)(vlSelfRef.top__DOT__result_src))
                                  ? vlSelfRef.top__DOT__inc_pc
                                  : vlSelfRef.top__DOT__imm_op)
                              : ((1U & (IData)(vlSelfRef.top__DOT__result_src))
                                  ? ((4U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                      ? ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                          ? vlSelfRef.top__DOT__MCU__DOT__ram_data_out
                                          : ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                              ? (0xffffU 
                                                 & vlSelfRef.top__DOT__MCU__DOT__ram_data_out)
                                              : (0xffU 
                                                 & vlSelfRef.top__DOT__MCU__DOT__ram_data_out)))
                                      : ((2U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                          ? vlSelfRef.top__DOT__MCU__DOT__ram_data_out
                                          : ((1U & (IData)(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3))
                                              ? (((- (IData)(
                                                             (1U 
                                                              & (vlSelfRef.top__DOT__MCU__DOT__ram_data_out 
                                                                 >> 0xfU)))) 
                                                  << 0x10U) 
                                                 | (0xffffU 
                                                    & vlSelfRef.top__DOT__MCU__DOT__ram_data_out))
                                              : (((- (IData)(
                                                             (1U 
                                                              & (vlSelfRef.top__DOT__MCU__DOT__ram_data_out 
                                                                 >> 7U)))) 
                                                  << 8U) 
                                                 | (0xffU 
                                                    & vlSelfRef.top__DOT__MCU__DOT__ram_data_out)))))
                                  : vlSelfRef.top__DOT__ALU_out))),32);
    bufp->fullIData(oldp+9,(vlSelfRef.top__DOT__alu_op1),32);
    bufp->fullIData(oldp+10,(vlSelfRef.top__DOT__alu_op2),32);
    bufp->fullIData(oldp+11,(vlSelfRef.top__DOT__rs1),32);
    bufp->fullIData(oldp+12,(vlSelfRef.top__DOT__rs2),32);
    bufp->fullCData(oldp+13,(vlSelfRef.top__DOT__branch_ctrl),4);
    bufp->fullBit(oldp+14,(vlSelfRef.top__DOT__reg_write));
    bufp->fullCData(oldp+15,(vlSelfRef.top__DOT__pc_src),2);
    bufp->fullCData(oldp+16,(vlSelfRef.top__DOT__imm_src),3);
    bufp->fullCData(oldp+17,(vlSelfRef.top__DOT__ALU_control),4);
    bufp->fullCData(oldp+18,(vlSelfRef.top__DOT__ALU_src),2);
    bufp->fullCData(oldp+19,(vlSelfRef.top__DOT__mem_write),4);
    bufp->fullCData(oldp+20,(vlSelfRef.top__DOT__result_src),2);
    bufp->fullBit(oldp+21,((1U & (IData)(vlSelfRef.top__DOT__ALU_src))));
    bufp->fullBit(oldp+22,((1U & ((IData)(vlSelfRef.top__DOT__ALU_src) 
                                  >> 1U))));
    bufp->fullCData(oldp+23,(vlSelfRef.top__DOT____Vcellinp__control_unit__funct3),3);
    bufp->fullIData(oldp+24,(vlSelfRef.top__DOT__MCU__DOT__ram_data_out),32);
    bufp->fullIData(oldp+25,((0x1ffffU & vlSelfRef.top__DOT__ALU_out)),17);
    bufp->fullCData(oldp+26,(vlSelfRef.top__DOT____Vcellinp__control_unit__opcode),7);
    bufp->fullBit(oldp+27,(vlSelfRef.top__DOT____Vcellinp__control_unit__funct7_5));
    bufp->fullSData(oldp+28,((0xfffU & vlSelfRef.top__DOT__pc)),12);
    bufp->fullIData(oldp+29,(vlSelfRef.top__DOT__program_counter__DOT__relative_pc),32);
    bufp->fullIData(oldp+30,(vlSelfRef.top__DOT__program_counter__DOT__absolute_pc),32);
    bufp->fullIData(oldp+31,(vlSelfRef.top__DOT__program_counter__DOT__next_pc),32);
    bufp->fullCData(oldp+32,((0x1fU & (vlSelfRef.__VdfgRegularize_hd87f99a1_0_1 
                                       >> 0xfU))),5);
    bufp->fullCData(oldp+33,(((0x10U & (vlSelfRef.top__DOT__instr_mem__DOT__rom_array
                                        [(0xfffU & 
                                          ((IData)(3U) 
                                           + vlSelfRef.top__DOT__pc))] 
                                        << 4U)) | (0xfU 
                                                   & (vlSelfRef.__VdfgRegularize_hd87f99a1_0_1 
                                                      >> 0x14U)))),5);
    bufp->fullCData(oldp+34,((0x1fU & ((IData)(vlSelfRef.__VdfgRegularize_hd87f99a1_0_0) 
                                       >> 7U))),5);
    bufp->fullIData(oldp+35,(vlSelfRef.top__DOT__regfile__DOT__register_file[0]),32);
    bufp->fullIData(oldp+36,(vlSelfRef.top__DOT__regfile__DOT__register_file[1]),32);
    bufp->fullIData(oldp+37,(vlSelfRef.top__DOT__regfile__DOT__register_file[2]),32);
    bufp->fullIData(oldp+38,(vlSelfRef.top__DOT__regfile__DOT__register_file[3]),32);
    bufp->fullIData(oldp+39,(vlSelfRef.top__DOT__regfile__DOT__register_file[4]),32);
    bufp->fullIData(oldp+40,(vlSelfRef.top__DOT__regfile__DOT__register_file[5]),32);
    bufp->fullIData(oldp+41,(vlSelfRef.top__DOT__regfile__DOT__register_file[6]),32);
    bufp->fullIData(oldp+42,(vlSelfRef.top__DOT__regfile__DOT__register_file[7]),32);
    bufp->fullIData(oldp+43,(vlSelfRef.top__DOT__regfile__DOT__register_file[8]),32);
    bufp->fullIData(oldp+44,(vlSelfRef.top__DOT__regfile__DOT__register_file[9]),32);
    bufp->fullIData(oldp+45,(vlSelfRef.top__DOT__regfile__DOT__register_file[10]),32);
    bufp->fullIData(oldp+46,(vlSelfRef.top__DOT__regfile__DOT__register_file[11]),32);
    bufp->fullIData(oldp+47,(vlSelfRef.top__DOT__regfile__DOT__register_file[12]),32);
    bufp->fullIData(oldp+48,(vlSelfRef.top__DOT__regfile__DOT__register_file[13]),32);
    bufp->fullIData(oldp+49,(vlSelfRef.top__DOT__regfile__DOT__register_file[14]),32);
    bufp->fullIData(oldp+50,(vlSelfRef.top__DOT__regfile__DOT__register_file[15]),32);
    bufp->fullIData(oldp+51,(vlSelfRef.top__DOT__regfile__DOT__register_file[16]),32);
    bufp->fullIData(oldp+52,(vlSelfRef.top__DOT__regfile__DOT__register_file[17]),32);
    bufp->fullIData(oldp+53,(vlSelfRef.top__DOT__regfile__DOT__register_file[18]),32);
    bufp->fullIData(oldp+54,(vlSelfRef.top__DOT__regfile__DOT__register_file[19]),32);
    bufp->fullIData(oldp+55,(vlSelfRef.top__DOT__regfile__DOT__register_file[20]),32);
    bufp->fullIData(oldp+56,(vlSelfRef.top__DOT__regfile__DOT__register_file[21]),32);
    bufp->fullIData(oldp+57,(vlSelfRef.top__DOT__regfile__DOT__register_file[22]),32);
    bufp->fullIData(oldp+58,(vlSelfRef.top__DOT__regfile__DOT__register_file[23]),32);
    bufp->fullIData(oldp+59,(vlSelfRef.top__DOT__regfile__DOT__register_file[24]),32);
    bufp->fullIData(oldp+60,(vlSelfRef.top__DOT__regfile__DOT__register_file[25]),32);
    bufp->fullIData(oldp+61,(vlSelfRef.top__DOT__regfile__DOT__register_file[26]),32);
    bufp->fullIData(oldp+62,(vlSelfRef.top__DOT__regfile__DOT__register_file[27]),32);
    bufp->fullIData(oldp+63,(vlSelfRef.top__DOT__regfile__DOT__register_file[28]),32);
    bufp->fullIData(oldp+64,(vlSelfRef.top__DOT__regfile__DOT__register_file[29]),32);
    bufp->fullIData(oldp+65,(vlSelfRef.top__DOT__regfile__DOT__register_file[30]),32);
    bufp->fullIData(oldp+66,(vlSelfRef.top__DOT__regfile__DOT__register_file[31]),32);
    bufp->fullIData(oldp+67,(vlSelfRef.top__DOT____Vcellinp__sign_ext__in),25);
    bufp->fullBit(oldp+68,(vlSelfRef.clk));
    bufp->fullBit(oldp+69,(vlSelfRef.rst));
    bufp->fullIData(oldp+70,(vlSelfRef.a0),32);
}

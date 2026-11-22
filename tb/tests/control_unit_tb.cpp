#include "base_testbench.h"

unsigned int ticks = 0;

class ControlUnitTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override { decode(0); }

    void decode(unsigned opcode, unsigned funct3 = 0,
                unsigned bit30 = 0, unsigned flags = 0)
    {
        top->opcode = opcode;
        top->funct3 = funct3;
        top->funct7_5 = bit30;
        top->branch_ctrl = flags;
        top->eval();
    }
};

TEST_F(ControlUnitTestbench, JalSelectsRelativeTarget)
{
    decode(0x6f);
    EXPECT_EQ(top->pc_src, 1);
    EXPECT_EQ(top->reg_write, 1);
    EXPECT_EQ(top->result_src, 3);
    EXPECT_EQ(top->imm_src, 4);
}

TEST_F(ControlUnitTestbench, JalrIsUnconditional)
{
    for (unsigned flags = 0; flags < 16; flags++)
    {
        decode(0x67, 0, 0, flags);
        EXPECT_EQ(top->pc_src, 2) << "flags = " << flags;
        EXPECT_EQ(top->reg_write, 1);
        EXPECT_EQ(top->result_src, 3);
        EXPECT_EQ(top->imm_src, 0);
    }
}

TEST_F(ControlUnitTestbench, ImmediateBitsDoNotSelectRegisterOperations)
{
    // Negative constants can set instruction bit 30.
    for (unsigned funct3 : {0u, 2u, 3u, 4u, 6u, 7u})
        for (unsigned bit30 = 0; bit30 < 2; bit30++)
            {
                decode(0x13, funct3, bit30);
                EXPECT_EQ(top->ALU_control, funct3);
                EXPECT_EQ(top->ALU_src, 2);
                EXPECT_EQ(top->reg_write, 1);
            }
}

TEST_F(ControlUnitTestbench, ImmediateShiftsUseTheCorrectOperation)
{
    decode(0x13, 1);
    EXPECT_EQ(top->ALU_control, 1);  // SLLI
    decode(0x13, 5);
    EXPECT_EQ(top->ALU_control, 5);  // SRLI
    decode(0x13, 5, 1);
    EXPECT_EQ(top->ALU_control, 13); // SRAI
}

TEST_F(ControlUnitTestbench, RegisterOperationsKeepTheirEncoding)
{
    for (unsigned funct3 = 0; funct3 < 8; funct3++)
    {
        decode(0x33, funct3);
        EXPECT_EQ(top->ALU_control, funct3);
    }
    decode(0x33, 0, 1);
    EXPECT_EQ(top->ALU_control, 8);  // SUB
    decode(0x33, 5, 1);
    EXPECT_EQ(top->ALU_control, 13); // SRA
}

TEST_F(ControlUnitTestbench, BranchesUseTheCorrectComparison)
{
    // Flags: equality, unused, signed less-than, unsigned less-than.
    const unsigned functions[] = {0, 1, 4, 5, 6, 7};
    const unsigned rows[][7] = {
        {8, 1, 0, 0, 1, 0, 1},
        {3, 0, 1, 1, 0, 1, 0},
        {2, 0, 1, 1, 0, 0, 1},
        {1, 0, 1, 0, 1, 1, 0},
        {0, 0, 1, 0, 1, 0, 1}
    };
    for (const auto &row : rows)
        for (unsigned i = 0; i < 6; i++)
        {
            decode(0x63, functions[i], 0, row[0]);
            EXPECT_EQ(top->pc_src, row[i + 1])
                << "funct3 = " << functions[i] << ", flags = " << row[0];
            EXPECT_EQ(top->imm_src, 2);
        }
    decode(0);
    EXPECT_EQ(top->pc_src, 0);
}

TEST_F(ControlUnitTestbench, MemoryAndUpperInstructionsKeepTheirPaths)
{
    const unsigned masks[] = {1, 3, 15};
    for (unsigned funct3 = 0; funct3 < 3; funct3++)
    {
        decode(0x23, funct3, 1);
        EXPECT_EQ(top->mem_write, masks[funct3]);
        EXPECT_EQ(top->ALU_control, 0);
        EXPECT_EQ(top->ALU_src, 2);
        EXPECT_EQ(top->imm_src, 1);
        EXPECT_EQ(top->reg_write, 0);
    }
    decode(0x03, 2, 1);
    EXPECT_EQ(top->ALU_control, 0);
    EXPECT_EQ(top->result_src, 1);
    EXPECT_EQ(top->reg_write, 1);
    decode(0x17, 0, 1);
    EXPECT_EQ(top->ALU_control, 0);
    EXPECT_EQ(top->ALU_src, 3);
    decode(0x37);
    EXPECT_EQ(top->result_src, 2);
}

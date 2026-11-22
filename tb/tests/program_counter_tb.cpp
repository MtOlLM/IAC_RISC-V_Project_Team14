#include "testbench.h"

unsigned int ticks = 0;

class ProgramCounterTestbench : public Testbench
{
protected:
    void initializeInputs() override
    {
        top->clk = 0;
        top->rst = 1;
        top->rs1 = 0;
        top->pc_src = 0;
        top->imm_op = 0;
        runSimulation(2);
        top->rst = 0;
    }
};

TEST_F(ProgramCounterTestbench, ResetMatchesTheProjectLinkAddress)
{
    EXPECT_EQ(top->pc, 0xBFC00000u);
}

TEST_F(ProgramCounterTestbench, SequentialInstructionsAdvanceByFour)
{
    runSimulation(1);
    EXPECT_EQ(top->pc, 0xBFC00004u);
    EXPECT_EQ(top->inc_pc, 0xBFC00008u);
}

TEST_F(ProgramCounterTestbench, RelativeJumpsWorkInBothDirections)
{
    top->pc_src = 1;
    top->imm_op = 16;
    runSimulation(1);
    EXPECT_EQ(top->pc, 0xBFC00010u);
    top->imm_op = static_cast<unsigned int>(-8);
    runSimulation(1);
    EXPECT_EQ(top->pc, 0xBFC00008u);
}

TEST_F(ProgramCounterTestbench, JalrClearsTheLowTargetBit)
{
    top->pc_src = 2;
    top->rs1 = 0x101;
    runSimulation(1);
    EXPECT_EQ(top->pc, 0x100u);
    top->imm_op = 3;
    runSimulation(1);
    EXPECT_EQ(top->pc, 0x104u);
    top->rs1 = 0x105;
    top->imm_op = static_cast<unsigned int>(-4);
    runSimulation(1);
    EXPECT_EQ(top->pc, 0x100u);
}

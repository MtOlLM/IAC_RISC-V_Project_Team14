#include "gtest/gtest.h"
#include "Vdut.h"
#include "verilated.h"

Vdut *top;
VerilatedVcdC *tfp;
unsigned int ticks = 0;

class controlUnitTest : public ::testing::Test
{
protected:
    void SetUp() override
    {
        initializeInputs();
    }

    void TearDown() override
    {
    }

    void initializeInputs()
    {
        top->opcode = 0;
        top->funct3 = 0;
        top->funct7_5 = 0;
        top->eq = 0;
    }

    void run(int op, int f3, int f7, int eq)
    {
        top->opcode = op;
        top->funct3 = f3;
        top->funct7_5 = f7;
        top->eq = eq;
        top->eval();
    }

    void expectSignals(int reg_write, int ALU_src, int mem_write, int result_src, int imm_src, int ALU_control, int pc_src)
    {
        EXPECT_EQ(top->reg_write,   reg_write);
        EXPECT_EQ(top->ALU_src,     ALU_src);
        EXPECT_EQ(top->mem_write,   mem_write);
        EXPECT_EQ(top->result_src,  result_src);
        EXPECT_EQ(top->imm_src,     imm_src);
        EXPECT_EQ(top->ALU_control, ALU_control);
        EXPECT_EQ(top->pc_src,      pc_src);
    }
};

TEST_F(controlUnitTest, add)
{
    run(0b0110011, 0b000, 0, 0);
    expectSignals(1, 0, 0, 0, 0b00, 0b000, 0);
}

TEST_F(controlUnitTest, sub)
{
    run(0b0110011, 0b000, 1, 0);
    expectSignals(1, 0, 0, 0, 0b00, 0b001, 0);
}

TEST_F(controlUnitTest, slt)
{
    run(0b0110011, 0b010, 0, 0);
    expectSignals(1, 0, 0, 0, 0b00, 0b101, 0);
}

TEST_F(controlUnitTest, orTest)
{
    run(0b0110011,0b110, 0, 0);
    expectSignals(1, 0, 0, 0, 0b00, 0b011, 0);
}

TEST_F(controlUnitTest, andTest)
{
    run(0b0110011,0b111, 0, 0);
    expectSignals(1, 0, 0, 0, 0b00, 0b010, 0);
}

TEST_F(controlUnitTest, addi)
{
    run(0b0010011,0b000, 0, 0);
    expectSignals(1, 1, 0, 0, 0b00, 0b000, 0);
}

TEST_F(controlUnitTest, addi30)
{
    run(0b0010011, 0b000, 1, 0);
    expectSignals(1, 1, 0, 0, 0b00, 0b000, 0);
}

TEST_F(controlUnitTest, slti)
{
    run(0b0010011, 0b010, 0, 0);
    expectSignals(1, 1, 0, 0, 0b00, 0b101, 0);
}

TEST_F(controlUnitTest, ori)
{
    run(0b0010011,0b110, 0, 0);
    expectSignals(1, 1, 0, 0, 0b00, 0b011, 0);
}

TEST_F(controlUnitTest, andi)
{
    run(0b0010011,0b111, 0, 0);
    expectSignals(1, 1, 0, 0, 0b00, 0b010, 0);
}

TEST_F(controlUnitTest, lw)
{
    run(0b0000011,0b010, 0, 0);
    expectSignals(1, 1, 0, 1, 0b00, 0b000, 0);
}

TEST_F(controlUnitTest, sw)
{
    run(0b0100011,0b010, 0, 0);
    expectSignals(0, 1, 1, 0, 0b01, 0b000, 0);
}

TEST_F(controlUnitTest, bneNotEq)
{
    run(0b1100011,0b001, 0, 0);
    expectSignals(0, 0, 0, 0, 0b10, 0b001, 1);
}

TEST_F(controlUnitTest, bneEq)
{
    run(0b1100011,0b001, 0, 1);
    expectSignals(0, 0, 0, 0, 0b10, 0b001, 0);
}

TEST_F(controlUnitTest, unknownOp)
{
    run(0b1111111,0b000, 0, 1);
    expectSignals(0, 0, 0, 0, 0b00, 0b000, 0);
}

int main(int argc, char **argv)
{
    top = new Vdut;

    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();

    top->final();
    delete top;

    return res;
}

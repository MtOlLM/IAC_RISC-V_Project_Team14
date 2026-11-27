#include "testbench.h"

unsigned int ticks = 0;

class AtomicCpuTestbench : public Testbench
{
protected:
    void initializeInputs() override
    {
        top->clk = 0;
        top->rst = 1;
        runSimulation(2);
        top->rst = 0;
    }
};

TEST_F(AtomicCpuTestbench, AtomicProgram)
{
    for (unsigned cycle = 0; cycle < 5000 && top->a0 != 1; cycle++)
    {
        runSimulation(1);
        ASSERT_FALSE(top->fault);
        ASSERT_NE(top->a0, 0xffffffffu) << "Assembly check failed";
    }
    ASSERT_EQ(top->a0, 1u) << "Program did not finish";

    // The last instruction checks an unaligned access.
    runSimulation(4);
    ASSERT_TRUE(top->fault);
    runSimulation(10);
    EXPECT_TRUE(top->fault);
    EXPECT_EQ(top->a0, 1u);

    top->rst = 1;
    runSimulation(2);
    EXPECT_FALSE(top->fault);
}

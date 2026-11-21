/*
 *  Verifies the results of the mux, exits with a 0 on success.
 */

#include "base_testbench.h"

unsigned int ticks = 0;

class MuxTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->sel = 0;
        top->in0 = 0;
        top->in1 = 0;
        // output: out
    }
};

TEST_F(MuxTestbench, Mux0WorksTest)
{
    top->sel = 0;
    top->in0 = 1;
    top->in1 = 0;

    top->eval();

    EXPECT_EQ(top->out, 1);
}

TEST_F(MuxTestbench, Mux1WorksTest)
{
    top->sel = 1;
    top->in0 = 0;
    top->in1 = 1;

    top->eval();

    EXPECT_EQ(top->out, 1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

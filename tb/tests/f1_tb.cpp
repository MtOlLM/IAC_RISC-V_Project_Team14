#include "testbench.h"
#include <array>
#include <iostream>

unsigned int ticks = 0;

class F1Testbench : public Testbench
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

TEST_F(F1Testbench, TwoSequences)
{
    // Check two complete rounds.
    const std::array<unsigned int, 19> expected = {
        0,
        1, 3, 7, 15, 31, 63, 127, 255, 0,
        1, 3, 7, 15, 31, 63, 127, 255, 0
    };

    unsigned int previous = 0;
    unsigned int last_change = 0;
    std::size_t next = 1;

    for (unsigned int cycle = 1; cycle <= 30000; cycle++)
    {
        runSimulation(1);
        const unsigned int output = top->a0;

        if (output == previous)
            continue;

        // Check each new light pattern.
        ASSERT_EQ(output, expected[next])
            << "Wrong pattern at cycle " << cycle;

        // Check that each pattern was held long enough.
        const unsigned int minimum = (previous == 255) ? 512 : 256;

        ASSERT_GE(cycle - last_change, minimum)
            << "Delay too short at cycle " << cycle;

        std::cout << "Cycle " << cycle
                  << ": a0 = " << output << '\n';

        previous = output;
        last_change = cycle;
        next++;

        if (next == expected.size())
            return;
    }

    FAIL() << "Two F1 sequences did not finish";
}
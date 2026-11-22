#include "base_testbench.h"
#include <cstdint>

unsigned int ticks = 0;

class SignExtTestbench : public BaseTestbench
{
protected:
    void initializeInputs() override
    {
        top->in = 0;
        top->imm_src = 4;
    }
};

TEST_F(SignExtTestbench, JalOffsetsAreSignExtended)
{
    const int32_t offsets[] = {0, 2, 4, 2048, 1048574, -2, -4, -24, -1048576};
    for (int32_t offset : offsets)
    {
        // Encode JAL from its signed byte offset.
        const uint32_t bits = static_cast<uint32_t>(offset);
        const uint32_t instruction =
            (((bits >> 20) & 1) << 31) |
            (((bits >> 1) & 0x3ff) << 21) |
            (((bits >> 11) & 1) << 20) |
            (((bits >> 12) & 0xff) << 12) | 0x6f;
        top->in = instruction >> 7;
        top->eval();
        EXPECT_EQ(top->out, static_cast<uint32_t>(offset))
            << "offset = " << offset;
    }
}

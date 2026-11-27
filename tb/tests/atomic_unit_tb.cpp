#include "testbench.h"
#include <cstdint>

unsigned int ticks = 0;

class AtomicUnitTestbench : public Testbench
{
protected:
    void initializeInputs() override
    {
        top->clk = 0;
        top->rst = 1;
        top->enable = 1;
        top->atomic_en = 0;
        top->funct5 = 0;
        top->funct3 = 2;
        top->rs2_zero = 1;
        top->addr = 0;
        top->data_in = 0;
        top->mem_data = 0;
        top->store_en = 0;
        runSimulation(2);
        top->rst = 0;
    }

    void apply(unsigned op, uint32_t addr = 0x1000,
               uint32_t value = 7, uint32_t old = 11)
    {
        top->atomic_en = 1;
        top->funct5 = op;
        top->funct3 = 2;
        top->rs2_zero = 1;
        top->addr = addr;
        top->data_in = value;
        top->mem_data = old;
        top->store_en = 0;
        top->eval();
    }

    void reserve()
    {
        apply(2);
        runSimulation(1);
    }

    void store(uint32_t addr, unsigned mask)
    {
        top->atomic_en = 0;
        top->addr = addr;
        top->store_en = mask;
        runSimulation(1);
        top->store_en = 0;
    }
};

TEST_F(AtomicUnitTestbench, AmoResults)
{
    // old word, operand, funct5, expected new word
    const uint32_t cases[][4] = {
        {0xffffffff, 1,          0x00, 0},
        {11,         7,          0x01, 7},
        {0xaaaaaaaa, 0xffffffff, 0x04, 0x55555555},
        {0xf0000000, 0x0f0f0000, 0x08, 0xff0f0000},
        {0xf0f0f0f0, 0xff00ff00, 0x0c, 0xf000f000},
        {0x80000000, 0x7fffffff, 0x10, 0x80000000},
        {0x80000000, 0x7fffffff, 0x14, 0x7fffffff}
    };

    for (const auto &test : cases)
    {
        apply(test[2], 0x1000, test[1], test[0]);
        EXPECT_FALSE(top->fault);
        EXPECT_EQ(top->result, test[0]);
        EXPECT_EQ(top->write_data, test[3]);
        EXPECT_EQ(top->write_en, 15);
    }
}

TEST_F(AtomicUnitTestbench, LoadReservedAndStoreConditional)
{
    apply(3);
    EXPECT_EQ(top->result, 1u);
    EXPECT_EQ(top->write_en, 0);

    reserve();
    apply(3);
    EXPECT_EQ(top->result, 0u);
    EXPECT_EQ(top->write_data, 7u);
    EXPECT_EQ(top->write_en, 15);
    runSimulation(1);
    apply(3);
    EXPECT_EQ(top->result, 1u);

    reserve();
    apply(3, 0x1004);
    EXPECT_EQ(top->result, 1u);
    runSimulation(1);
    apply(3);
    EXPECT_EQ(top->result, 1u);
}

TEST_F(AtomicUnitTestbench, StoresInvalidateOverlappingReservations)
{
    const uint32_t addresses[] = {0x1000, 0x1001, 0x0fff};
    const unsigned masks[] = {15, 1, 3};

    for (unsigned i = 0; i < 3; i++)
    {
        reserve();
        store(addresses[i], masks[i]);
        apply(3);
        EXPECT_EQ(top->result, 1u);
        EXPECT_EQ(top->write_en, 0);
    }

    reserve();
    store(0x1004, 15);
    apply(3);
    EXPECT_EQ(top->result, 0u);
}

TEST_F(AtomicUnitTestbench, ResetAndDisable)
{
    reserve();
    top->enable = 0;
    apply(3);
    EXPECT_EQ(top->write_en, 0);
    runSimulation(1);
    top->enable = 1;
    top->eval();
    EXPECT_EQ(top->result, 0u);

    top->rst = 1;
    runSimulation(1);
    top->rst = 0;
    apply(3);
    EXPECT_EQ(top->result, 1u);
}

TEST_F(AtomicUnitTestbench, InvalidRequestsCannotWrite)
{
    for (unsigned op : {0u, 1u, 2u, 3u, 4u, 8u, 12u, 16u, 20u})
        for (uint32_t addr : {0x1001u, 0x20000u})
        {
            apply(op, addr);
            EXPECT_TRUE(top->fault);
            EXPECT_EQ(top->write_en, 0);
        }

    apply(2);
    top->rs2_zero = 0;
    top->eval();
    EXPECT_TRUE(top->fault);
    EXPECT_EQ(top->write_en, 0);

    apply(0);
    top->funct3 = 3;
    top->eval();
    EXPECT_TRUE(top->fault);

    apply(0x0a);
    EXPECT_TRUE(top->fault);
    EXPECT_EQ(top->write_en, 0);
}

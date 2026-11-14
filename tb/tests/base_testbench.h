#pragma once

#include <memory>

#include "Vdut.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "gtest/gtest.h"

#define MAX_SIM_CYCLES 10000

extern unsigned int ticks;

class BaseTestbench : public ::testing::Test
{
public:
    void SetUp() override
    {
        contextp = std::make_unique<VerilatedContext>();
        contextp->traceEverOn(true);
        top = std::make_unique<Vdut>(contextp.get());
        tfp = std::make_unique<VerilatedVcdC>();
        top->trace(tfp.get(), 99);
        std::string name = std::string(
            ::testing::UnitTest::GetInstance()->current_test_info()->name()) + ".vcd";
        tfp->open(name.c_str());
        initializeInputs();
    }

    void TearDown() override
    {
        top->final();
        tfp->close();
    }

    virtual void initializeInputs() = 0;

protected:
    std::unique_ptr<VerilatedContext> contextp;
    std::unique_ptr<Vdut> top;
    std::unique_ptr<VerilatedVcdC> tfp;
};
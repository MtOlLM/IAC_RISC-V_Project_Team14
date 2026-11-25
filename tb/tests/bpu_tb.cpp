#include "testbench.h"

#include <cstdint>

unsigned int ticks = 0;

// Instruction memory at 0xBFC00000 - 0xBFC00FFF
const uint32_t mem_base = 0xBFC00000;

enum BrType : uint8_t
{
    BR_COND = 0,
    BR_JUMP = 1,
    BR_CALL = 2,
    BR_RET = 3,
    BR_CORO = 4
};

// predictor output in fetch stage
struct Prediction
{
    bool taken;
    uint32_t target;
    uint32_t ras_ptr;
};

// what actually happened in execution stage
struct Outcome
{
    BrType type;
    bool taken;
    uint32_t target;
};

// testbench is used since clk is involved
class BpuTestbench : public Testbench
{
protected:
    void initializeInputs() override
    {
        top->clk = 0;
        top->rst = 0;
        top->fetch_en = 0;
        top->pcF = mem_base;
        top->up_en = 0;
        top->up_pc = mem_base;
        top->up_type = 0;
        top->up_taken = 0;
        top->up_target = mem_base;
        top->mispredict = 0;
        top->up_ras_ptr = 0;

        top->rst = 1;
        runSimulation(2);
        top->rst = 0;
    }

    // only fetch and pc are mandatory
    Prediction cycle(bool fetch, uint32_t pc,
                     bool up_en = false, uint32_t up_pc = mem_base, Outcome o = {BR_COND, false, mem_base},
                     bool mispredict = false, uint32_t up_ras_ptr = 0)
    {
        top->fetch_en = fetch;
        top->pcF = pc;
        top->up_en = up_en;
        top->up_pc = up_pc;
        top->up_type = o.type;
        top->up_taken = o.taken;
        top->up_target = o.target;
        top->mispredict = mispredict;
        top->up_ras_ptr = up_ras_ptr;
        top->eval(); // evaluate the combinational logics for the prediction output

        Prediction p = {bool(top->pred_takenF), uint32_t(top->pred_targetF), uint32_t(top->ras_ptrF)};
        runSimulation(1); // rising edge: predictor updates

        // reset
        top->fetch_en = 0;
        top->up_en = 0;
        top->mispredict = 0;
        return p;
    }

    static bool is_mispredict(const Prediction &p, const Outcome &o)
    {
        return p.taken != o.taken || (o.taken && p.target != o.target);
    }

    Prediction fetch(uint32_t pc)
    {
        return cycle(true, pc);
    }

    bool execute(uint32_t pc, const Outcome &o, const Prediction &p)
    {
        bool mis = is_mispredict(p, o);
        cycle(false, mem_base, true, pc, o, mis, p.ras_ptr);
        return mis;
    }

    bool run(uint32_t pc, const Outcome &o)
    {
        Prediction p = fetch(pc);
        return execute(pc, o, p);
    }
};

TEST_F(BpuTestbench, ColdPredictsNotTaken)
{
    for (uint32_t off = 0; off < 0x1000; off += 0x124)
        EXPECT_FALSE(fetch(mem_base + off).taken);
}

TEST_F(BpuTestbench, LearnsTaken)
{
    const uint32_t pc = mem_base + 0x100;
    const Outcome o = {BR_COND, true, mem_base + 0x0F0};

    EXPECT_TRUE(run(pc, o)); // weak not taken -> weak taken, BTB entry created

    Prediction p = fetch(pc);
    EXPECT_TRUE(p.taken);
    EXPECT_EQ(p.target, o.target);
    EXPECT_FALSE(execute(pc, o, p));
}

TEST_F(BpuTestbench, BimodalBehaviour)
{
    const uint32_t pc = mem_base + 0x100;
    const Outcome taken = {BR_COND, true, mem_base + 0x0F0};
    const Outcome not_taken = {BR_COND, false, mem_base + 0x0F0};

    run(pc, taken); // counter 01 -> 10, BTB entry created
    run(pc, taken); // counter 10 -> 11

    Prediction p = fetch(pc);
    EXPECT_TRUE(p.taken);
    execute(pc, not_taken, p); // 11 -> 10

    p = fetch(pc);
    EXPECT_TRUE(p.taken);
    execute(pc, not_taken, p); // 10 -> 01

    p = fetch(pc);
    EXPECT_FALSE(p.taken);
}

TEST_F(BpuTestbench, NotTakenStaysNotTaken)
{
    const uint32_t pc = mem_base + 0x200;
    const Outcome o = {BR_COND, false, mem_base + 0x300};

    EXPECT_FALSE(run(pc, o));
    EXPECT_FALSE(fetch(pc).taken);
}

TEST_F(BpuTestbench, JumpAlwaysTaken)
{
    const uint32_t pc = mem_base + 0x040;
    const Outcome o = {BR_JUMP, true, mem_base + 0x800};

    EXPECT_TRUE(run(pc, o)); //no entry in BTB
    for (int i = 0; i < 12; i++)
    {
        Prediction p = fetch(pc);
        EXPECT_TRUE(p.taken);
        EXPECT_EQ(p.target, o.target);
        EXPECT_FALSE(execute(pc, o, p));
    }
}

TEST_F(BpuTestbench, TwoWaysHoldConflictingBranches)
{
    const Outcome a = {BR_JUMP, true, mem_base + 0x500};
    const Outcome b = {BR_JUMP, true, mem_base + 0x600};

    //same set: 6'b00_0000
    run(mem_base + 0x100, a);
    run(mem_base + 0x200, b);

    Prediction pa = fetch(mem_base + 0x100);
    Prediction pb = fetch(mem_base + 0x200);
    EXPECT_TRUE(pa.taken);
    EXPECT_EQ(pa.target, a.target);
    EXPECT_TRUE(pb.taken);
    EXPECT_EQ(pb.target, b.target);
}

TEST_F(BpuTestbench, OverwriteOldest)
{
    run(mem_base + 0x100, {BR_JUMP, true, mem_base + 0x500}); // way 0
    run(mem_base + 0x200, {BR_JUMP, true, mem_base + 0x600}); // way 1
    run(mem_base + 0x300, {BR_JUMP, true, mem_base + 0x700}); // set full: replaces way 0

    EXPECT_FALSE(fetch(mem_base + 0x100).taken);
    EXPECT_TRUE(fetch(mem_base + 0x200).taken);
    EXPECT_TRUE(fetch(mem_base + 0x300).taken);
}

TEST_F(BpuTestbench, UpdatingExistingEntry)
{
    run(mem_base + 0x100, {BR_JUMP, true, mem_base + 0x500}); // way 0
    run(mem_base + 0x100, {BR_JUMP, true, mem_base + 0x580}); // same branch, new target: overwrite way 0
    run(mem_base + 0x200, {BR_JUMP, true, mem_base + 0x600}); // way 1

    Prediction p = fetch(mem_base + 0x100);
    EXPECT_TRUE(p.taken);
    EXPECT_EQ(p.target, mem_base + 0x580);
    EXPECT_TRUE(fetch(mem_base + 0x200).taken);
}

TEST_F(BpuTestbench, CallAndReturn)
{
    const uint32_t call_pc = mem_base + 0x200;
    const uint32_t ret_pc = mem_base + 0x40C;
    const Outcome call = {BR_CALL, true, mem_base + 0x400};
    const Outcome ret = {BR_RET, true, call_pc + 4};

    // first time: both miss in the BTB, the repair path pushes/pops instead
    EXPECT_TRUE(run(call_pc, call));
    EXPECT_TRUE(run(ret_pc, ret));

    // second time: both predicted
    Prediction pc_call = fetch(call_pc);
    EXPECT_TRUE(pc_call.taken);
    EXPECT_EQ(pc_call.target, call.target);
    EXPECT_FALSE(execute(call_pc, call, pc_call));

    Prediction pc_ret = fetch(ret_pc);
    EXPECT_TRUE(pc_ret.taken);
    EXPECT_EQ(pc_ret.target, ret.target);
    EXPECT_FALSE(execute(ret_pc, ret, pc_ret));
}

TEST_F(BpuTestbench, NestedCallsReturn)
{
    // main: call A at 0x100 -> 0x300
    // A:    call B at 0x310 -> 0x500
    // B:    ret at 0x50C    -> 0x314
    // A:    ret at 0x320    -> 0x104
    const uint32_t call_a = mem_base + 0x100, call_b = mem_base + 0x310;
    const uint32_t ret_b = mem_base + 0x50C, ret_a = mem_base + 0x320;
    const Outcome o_call_a = {BR_CALL, true, mem_base + 0x300};
    const Outcome o_call_b = {BR_CALL, true, mem_base + 0x500};
    const Outcome o_ret_b = {BR_RET, true, call_b + 4};
    const Outcome o_ret_a = {BR_RET, true, call_a + 4};

    for (int pass = 0; pass < 2; pass++)
    {
        const bool trained = (pass == 1);
        Prediction p;

        p = fetch(call_a);
        EXPECT_EQ(execute(call_a, o_call_a, p), !trained);
        p = fetch(call_b);
        EXPECT_EQ(execute(call_b, o_call_b, p), !trained);

        p = fetch(ret_b);
        if (trained)
        {
            EXPECT_EQ(p.target, o_ret_b.target);
        }
        EXPECT_EQ(execute(ret_b, o_ret_b, p), !trained);

        p = fetch(ret_a);
        if (trained)
        {
            EXPECT_EQ(p.target, o_ret_a.target);
        }
        EXPECT_EQ(execute(ret_a, o_ret_a, p), !trained);
    }
}

TEST_F(BpuTestbench, CoroutinePrediction)
{
    const uint32_t call_pc = mem_base + 0x100;
    const uint32_t coro_pc = mem_base + 0x310;
    const uint32_t ret_pc  = mem_base + 0x108;
    const Outcome  call    = {BR_CALL, true, mem_base + 0x300};
    const Outcome  coro    = {BR_CORO, true, call_pc + 4};
    const Outcome  ret     = {BR_RET,  true, coro_pc + 4};

    // first passes to the BTB - misprediction expected
    EXPECT_TRUE(run(call_pc, call));
    EXPECT_TRUE(run(coro_pc, coro));
    EXPECT_TRUE(run(ret_pc, ret));

    // second passes - expect correct prediction
    Prediction p_call = fetch(call_pc);
    EXPECT_FALSE(execute(call_pc, call, p_call));

    Prediction p_coro = fetch(coro_pc);
    EXPECT_TRUE(p_coro.taken);
    EXPECT_EQ(p_coro.target, coro.target);
    EXPECT_FALSE(execute(coro_pc, coro, p_coro));

    Prediction p_ret = fetch(ret_pc);
    EXPECT_EQ(p_ret.ras_ptr, p_coro.ras_ptr);
    EXPECT_EQ(p_ret.target, ret.target);
    EXPECT_FALSE(execute(ret_pc, ret, p_ret));

    EXPECT_EQ(fetch(mem_base + 0x000).ras_ptr, p_call.ras_ptr);
}

TEST_F(BpuTestbench, CoroutineRestore)
{
    const uint32_t call_pc = mem_base + 0x100;
    const uint32_t coro_pc = mem_base + 0x310;
    const uint32_t ret_pc  = mem_base + 0x108;
    const Outcome  call    = {BR_CALL, true, mem_base + 0x300};
    const Outcome  coro    = {BR_CORO, true, call_pc + 4};
    const Outcome  ret     = {BR_RET,  true, coro_pc + 4};

    // the coroutine switch stays unknown for prediction
    run(call_pc, call);
    run(ret_pc, {BR_RET, true, call_pc + 4});

    Prediction p_call = fetch(call_pc);  // predicted, pushes 0x104
    EXPECT_FALSE(execute(call_pc, call, p_call));

    // first encounter: BTB miss, so the push and pop happen in the restore path
    Prediction p_coro = fetch(coro_pc);
    EXPECT_FALSE(p_coro.taken);
    EXPECT_TRUE(execute(coro_pc, coro, p_coro));

    Prediction p_ret = fetch(ret_pc);  //predicted, pop
    EXPECT_EQ(p_ret.ras_ptr, p_coro.ras_ptr); //should be the same pointer if the restore is correct
    EXPECT_EQ(p_ret.target, ret.target); // should be coro_pc + 4
}

TEST_F(BpuTestbench, RasRepairedAfterWrongPathReturn)
{
    const uint32_t call_pc = mem_base + 0x200;
    const uint32_t branch_pc = mem_base + 0x400; // first instruction of the function
    const uint32_t ret_pc = mem_base + 0x404;    // the instruction after the branch
    const Outcome call = {BR_CALL, true, branch_pc};
    const Outcome ret = {BR_RET, true, call_pc + 4};
    const Outcome branch = {BR_COND, true, mem_base + 0x480}; // actually taken

    // train the call and the return
    run(call_pc, call);
    run(ret_pc, ret);

    // call (predicted, pushes 0x204)
    Prediction p_call = fetch(call_pc);
    EXPECT_FALSE(execute(call_pc, call, p_call));

    // branch: BTB miss, predicted not taken
    Prediction p_branch = fetch(branch_pc);
    EXPECT_FALSE(p_branch.taken);

    // wrong path: the return is fetched and pops the RAS
    Prediction p_wrong = fetch(ret_pc);
    EXPECT_EQ(p_wrong.target, ret.target);

    // branch resolves as mispredicted while another wrong-path return is in fetch:
    // the repair must win over that fetch's pop
    ASSERT_TRUE(is_mispredict(p_branch, branch));
    cycle(true, ret_pc, true, branch_pc, branch, true, p_branch.ras_ptr);

    // correct path later reaches the real return: RAS must be back to holding 0x204
    Prediction p_ret = fetch(ret_pc);
    EXPECT_EQ(p_ret.ras_ptr, p_branch.ras_ptr);
    EXPECT_EQ(p_ret.target, ret.target);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    auto res = RUN_ALL_TESTS();
    return res;
}
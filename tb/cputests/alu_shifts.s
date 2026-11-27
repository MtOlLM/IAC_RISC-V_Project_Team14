/* basic arithmetic and SHIFTS
*
*/

.text
.equ shift_32, 32

main:
    JAL     ra, test_arith
    JAL     ra, test_logic
    JAL     ra, test_shifts
    ADDI    a0, zero, 1
forever:
    J       forever

test_arith:
    LI      t0, 0x7FFFFFFF # wraps negative
    ADDI    t1, t0, 1
    LI      t2, 0x80000000
    BNE     t1, t2, fail

    ADD     t3, t1, t1 # register add -> wraps to 0
    BNE     t3, zero, fail

    SUB     t4, t3, t0 # subtraction
    LI      t5, 0x80000001
    BNE     t4, t5, fail
    RET

test_logic:
    LI      t0, 0xF0F0AA55 # AND
    LI      t1, 0x0FF055AA
    AND     t2, t0, t1
    LI      t3, 0x00F00000
    BNE     t2, t3, fail

    OR      t4, t0, t1 # OR
    LI      t5, 0xFFF0FFFF
    BNE     t4, t5, fail

    XOR     t6, t0, t0 # XOR
    BNE     t6, zero, fail
    RET

test_shifts:
    LI      t0, 0x80000000 # SRL
    SRL     t1, t0, 1
    LI      t2, 0x40000000
    BNE     t1, t2, fail

    SRA     t3, t0, 1 # SRA -> keep sign bit
    LI      t4, 0xC0000000
    BNE     t3, t4, fail

    LI      t5, 1 # SLLI fill bottom w 0
    SLLI    t6, t5, 31
    BNE     t6, t0, fail

    LI      a1, shift_32 # SLL
    SLL     a2, t5, a1          
    BNE     a2, t5, fail
    RET

fail:
    ADDI    a0, zero, 0
    J       forever
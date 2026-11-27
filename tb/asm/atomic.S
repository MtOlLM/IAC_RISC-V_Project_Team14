.text
.globl main

main:
    addi    a0, zero, 0
    li      s0, 0x1000
    jal     ra, test_amo
    jal     ra, test_lrsc
    jal     ra, test_reservation
    jal     ra, test_registers
    jal     ra, test_ordering
    addi    a0, zero, 1

    # The testbench expects this access to fault.
    li      t0, 0x1001
    amoadd.w zero, t1, (t0)
    addi    a0, zero, -1
done:
    jal     zero, done

fail:
    addi    a0, zero, -1
    jal     zero, fail

test_amo:

    # amoadd.w
    li      t0, 0x7fffffff
    sw      t0, 0(s0)
    li      t1, 1
    amoadd.w t2, t1, (s0)
    bne     t2, t0, fail
    lw      t3, 0(s0)
    li      t4, 0x80000000
    bne     t3, t4, fail

    # amoswap.w
    li      t0, 0x11223344
    sw      t0, 0(s0)
    li      t1, 0x55667788
    amoswap.w t2, t1, (s0)
    bne     t2, t0, fail
    lw      t3, 0(s0)
    li      t4, 0x55667788
    bne     t3, t4, fail

    # amoxor.w
    li      t0, 0xa5a55a5a
    sw      t0, 0(s0)
    li      t1, 0xffff0000
    amoxor.w t2, t1, (s0)
    bne     t2, t0, fail
    lw      t3, 0(s0)
    li      t4, 0x5a5a5a5a
    bne     t3, t4, fail

    # amoand.w
    li      t0, 0xf0f0f0f0
    sw      t0, 0(s0)
    li      t1, 0xff00ff00
    amoand.w t2, t1, (s0)
    bne     t2, t0, fail
    lw      t3, 0(s0)
    li      t4, 0xf000f000
    bne     t3, t4, fail

    # amoor.w
    li      t0, 0xf0000000
    sw      t0, 0(s0)
    li      t1, 0x0f0f0000
    amoor.w t2, t1, (s0)
    bne     t2, t0, fail
    lw      t3, 0(s0)
    li      t4, 0xff0f0000
    bne     t3, t4, fail

    # amomin.w
    li      t0, 0x80000000
    sw      t0, 0(s0)
    li      t1, 0x7fffffff
    amomin.w t2, t1, (s0)
    bne     t2, t0, fail
    lw      t3, 0(s0)
    li      t4, 0x80000000
    bne     t3, t4, fail

    # amomax.w
    li      t0, 0x80000000
    sw      t0, 0(s0)
    li      t1, 0x7fffffff
    amomax.w t2, t1, (s0)
    bne     t2, t0, fail
    lw      t3, 0(s0)
    li      t4, 0x7fffffff
    bne     t3, t4, fail
    jalr    zero, 0(ra)

test_lrsc:

    # SC without LR must fail.
    addi    t0, zero, 11
    sw      t0, 0(s0)
    addi    t1, zero, 7
    sc.w    t2, t1, (s0)
    beq     t2, zero, fail
    lw      t3, 0(s0)
    bne     t3, t0, fail

    # A matching SC succeeds once.
    lr.w    t2, (s0)
    bne     t2, t0, fail
    sc.w    t2, t1, (s0)
    bne     t2, zero, fail
    lw      t3, 0(s0)
    bne     t3, t1, fail
    sc.w    t2, t0, (s0)
    beq     t2, zero, fail
    lw      t3, 0(s0)
    bne     t3, t1, fail

    # A failed SC also clears the reservation.
    lr.w    t2, (s0)
    addi    s1, s0, 4
    sc.w    t2, t0, (s1)
    beq     t2, zero, fail
    sc.w    t2, t0, (s0)
    beq     t2, zero, fail

    # Only the latest LR is used.
    sw      t0, 0(s1)
    lr.w    t2, (s0)
    lr.w    t2, (s1)
    sc.w    t2, t1, (s1)
    bne     t2, zero, fail
    lw      t3, 0(s1)
    bne     t3, t1, fail
    jalr    zero, 0(ra)

test_reservation:

    addi    t0, zero, 11
    addi    t1, zero, 7
    sw      t0, 0(s0)

    # Writes to the reserved word cancel SC.
    lr.w    t2, (s0)
    sw      t0, 0(s0)
    sc.w    t2, t1, (s0)
    beq     t2, zero, fail

    lr.w    t2, (s0)
    sb      t0, 1(s0)
    sc.w    t2, t1, (s0)
    beq     t2, zero, fail

    # This halfword crosses into the reserved word.
    lr.w    t2, (s0)
    sh      t0, -1(s0)
    sc.w    t2, t1, (s0)
    beq     t2, zero, fail

    # The existing RAM wraps ordinary store addresses.
    lr.w    t2, (s0)
    li      s1, 0x21000
    sb      t0, 0(s1)
    sc.w    t2, t1, (s0)
    beq     t2, zero, fail

    # Other words and ordinary reads keep the reservation.
    lr.w    t2, (s0)
    sw      t0, 4(s0)
    lw      t3, 0(s0)
    sc.w    t2, t1, (s0)
    bne     t2, zero, fail

    # An AMO to the same word cancels SC.
    lr.w    t2, (s0)
    amoadd.w t3, t0, (s0)
    sc.w    t2, t1, (s0)
    beq     t2, zero, fail

    # An AMO to another word keeps the reservation.
    lr.w    t2, (s0)
    addi    s1, s0, 4
    amoadd.w t3, t0, (s1)
    sc.w    t2, t1, (s0)
    bne     t2, zero, fail
    jalr    zero, 0(ra)

test_registers:

    addi    t0, zero, 11
    addi    t1, zero, 7
    sw      t0, 0(s0)

    # rd = x0 still changes memory.
    amoadd.w zero, t1, (s0)
    lw      t2, 0(s0)
    addi    t3, zero, 18
    bne     t2, t3, fail
    bne     zero, zero, fail

    # rd = rs2 uses the original source value.
    amoswap.w t1, t1, (s0)
    bne     t1, t3, fail
    lw      t2, 0(s0)
    addi    t3, zero, 7
    bne     t2, t3, fail

    # rd = rs1 still uses the original address.
    addi    s1, s0, 0
    amoadd.w s1, t0, (s1)
    bne     s1, t3, fail
    lw      t2, 0(s0)
    addi    t3, zero, 18
    bne     t2, t3, fail

    # LR and SC also work with rd = x0.
    lr.w    zero, (s0)
    sc.w    zero, t0, (s0)
    lw      t2, 0(s0)
    bne     t2, t0, fail

    # SC may overwrite its source register with the status.
    lr.w    t2, (s0)
    addi    t1, zero, 7
    sc.w    t1, t1, (s0)
    bne     t1, zero, fail
    lw      t2, 0(s0)
    addi    t3, zero, 7
    bne     t2, t3, fail

    # SC may overwrite its address register too.
    lr.w    t2, (s0)
    addi    s1, s0, 0
    sc.w    s1, t0, (s1)
    bne     s1, zero, fail
    lw      t2, 0(s0)
    bne     t2, t0, fail

    # LR saves the address before writing rd.
    addi    s1, s0, 0
    lr.w    s1, (s1)
    bne     s1, t0, fail
    sc.w    t2, t3, (s0)
    bne     t2, zero, fail
    jalr    zero, 0(ra)

test_ordering:
    # Check the ordering encoding (plain).
    addi    t0, zero, 11
    sw      t0, 0(s0)
    addi    t1, zero, 7
    amoadd.w t2, t1, (s0)
    bne     t2, t0, fail
    lw      t3, 0(s0)
    addi    t4, zero, 18
    bne     t3, t4, fail
    lr.w t2, (s0)
    bne     t2, t4, fail
    sc.w t2, t0, (s0)
    bne     t2, zero, fail
    lw      t3, 0(s0)
    bne     t3, t0, fail
    # Check the ordering encoding .aq.
    addi    t0, zero, 11
    sw      t0, 0(s0)
    addi    t1, zero, 7
    amoadd.w.aq t2, t1, (s0)
    bne     t2, t0, fail
    lw      t3, 0(s0)
    addi    t4, zero, 18
    bne     t3, t4, fail
    lr.w.aq t2, (s0)
    bne     t2, t4, fail
    sc.w.aq t2, t0, (s0)
    bne     t2, zero, fail
    lw      t3, 0(s0)
    bne     t3, t0, fail
    # Check the ordering encoding .rl.
    addi    t0, zero, 11
    sw      t0, 0(s0)
    addi    t1, zero, 7
    amoadd.w.rl t2, t1, (s0)
    bne     t2, t0, fail
    lw      t3, 0(s0)
    addi    t4, zero, 18
    bne     t3, t4, fail
    lr.w.rl t2, (s0)
    bne     t2, t4, fail
    sc.w.rl t2, t0, (s0)
    bne     t2, zero, fail
    lw      t3, 0(s0)
    bne     t3, t0, fail
    # Check the ordering encoding .aqrl.
    addi    t0, zero, 11
    sw      t0, 0(s0)
    addi    t1, zero, 7
    amoadd.w.aqrl t2, t1, (s0)
    bne     t2, t0, fail
    lw      t3, 0(s0)
    addi    t4, zero, 18
    bne     t3, t4, fail
    lr.w.aqrl t2, (s0)
    bne     t2, t4, fail
    sc.w.aqrl t2, t0, (s0)
    bne     t2, zero, fail
    lw      t3, 0(s0)
    bne     t3, t0, fail
    jalr    zero, 0(ra)

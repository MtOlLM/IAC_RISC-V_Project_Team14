# Atomic extension

Implements the nine instructions on page 2 of RISCV_CARD.pdf:
lr.w, sc.w, amoswap.w, amoadd.w, amoand.w, amoor.w, amoxor.w,
amomax.w and amomin.w.

AMOs return the old memory word and write the new value to RAM.
AMOOR uses funct5 0x08; the card incorrectly prints 0x0a.
MIN and MAX compare signed values.

The decoder selects the atomic path in the memory controller. The address
comes from rs1. The old word is returned to rd, and the new word is written
on the same clock edge.

LR records a four-byte reservation. SC returns 0 and writes rs2 when it
matches; otherwise it returns 1 without writing. Every executed SC clears
the reservation. A new LR replaces it. Reset and overlapping writes also
clear it, including ordinary byte and halfword stores.

This is for the current single-core CPU with uncached RAM. Its memory
operations complete in order, so aq/rl need no extra ordering hardware.
A cache, another hart, or another RAM writer needs additional integration.

Bad atomic encodings, unaligned addresses and addresses outside RAM assert
fault and stop the CPU until reset. Faulting instructions cannot write memory
or a register. There is no additional trap-handler or CSR system.

Run from the repository root:

~~~bash
bash tb/run_atomic.sh
~~~

There are two testbenches: one checks the atomic unit directly; the other
runs asm/atomic.S on the CPU. The assembly checks all nine instructions,
reservation invalidation, register overlap, x0 and ordering encodings. It ends
with an unaligned access to check that fault holds the CPU until reset.
Five directed unit tests check calculations, LR/SC, overlapping stores,
reset/disable and invalid requests.

The runner builds in /tmp and prints the waveform folder. It does not
overwrite the project's program.hex. It needs the existing RISC-V GNU
toolchain, Verilator, Make and GoogleTest.

Only the requested nine-instruction subset is implemented. The pre-existing
ALU arithmetic-shift issue and other unrelated modules are unchanged.

References:
- https://github.com/riscv/riscv-opcodes/blob/master/extensions/rv_a
- https://docs.riscv.org/reference/isa/unpriv/a-st-ext.html

#!/usr/bin/env bash
set -euo pipefail

project_dir=$(cd "$(dirname "$0")/.." && pwd)
export PATH="$PATH:/opt/riscv/bin"

work=$(mktemp -d /tmp/iac-atomic.XXXXXX)
ln -s "$project_dir" "$work/project"
project="$work/project"
mkdir -p "$work/run"
cp "$project/tb/sine.mem" "$work/run/sine.mem"

build() {
    local module="$1" source="$2" name="$3"
    verilator -Wall -Wno-fatal --trace --cc \
        "$project/rtl/$module.sv" --top-module "$module" \
        -y "$project/rtl" --exe "$project/tb/tests/$source" \
        --prefix Vdut --Mdir "$work/$name" \
        -CFLAGS "-std=c++17" \
        -LDFLAGS "-lgtest -lgtest_main -lpthread" \
        --build -j 2 -o Vtest > "$work/$name-build.log" 2>&1 \
        || { cat "$work/$name-build.log"; return 1; }
}

riscv64-unknown-elf-as -march=rv32ia -mabi=ilp32 \
    -o "$work/atomic.o" "$project/tb/asm/atomic.S"
riscv64-unknown-elf-ld -melf32lriscv -e main -Ttext=0xBFC00000 \
    -o "$work/atomic.elf" "$work/atomic.o"
riscv64-unknown-elf-objcopy -O binary -j .text \
    "$work/atomic.elf" "$work/atomic.bin"

if [ "$(wc -c < "$work/atomic.bin")" -gt 4096 ]; then
    echo "Atomic program exceeds instruction memory"
    exit 1
fi
od -v -An -t x1 "$work/atomic.bin" > "$work/run/program.hex"

build atomic_unit atomic_unit_tb.cpp unit
(cd "$work/run" && "$work/unit/Vtest")

build top atomic_cpu_tb.cpp cpu
(cd "$work/run" && "$work/cpu/Vtest")

echo "Build logs and waveforms: $work"

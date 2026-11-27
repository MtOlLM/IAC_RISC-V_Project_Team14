#!/bin/bash
# asm2hex.sh - convert every .s file in a folder to a .hex file with the same name.
#
# Usage:
#   ./asm2hex.sh [folder]          (default folder: current directory)
#
# Options (environment variables):
#   PREFIX   toolchain prefix, default riscv64-unknown-elf-
#            (use PREFIX=riscv64-linux-gnu- if that is what you installed)
#   WORDS    set to 1 for one 32-bit word per line instead of one byte per line
#            (use whichever matches the array width your ROM reads)
#
# Example:
#   PREFIX=riscv64-linux-gnu- ./asm2hex.sh tb/asm
#
# Each foo.s becomes foo.hex in the same folder. An existing foo.hex is overwritten.

set -u

DIR="${1:-.}"
PREFIX="${PREFIX:-riscv64-unknown-elf-}"
WORDS="${WORDS:-0}"

for tool in as ld objcopy; do
    if ! command -v "${PREFIX}${tool}" >/dev/null 2>&1; then
        echo "error: ${PREFIX}${tool} not found. Install the RISC-V toolchain or set PREFIX." >&2
        exit 1
    fi
done

# Intermediate files go in a temporary folder that is removed on exit.
TMP=$(mktemp -d)
trap 'rm -rf "$TMP"' EXIT

ok=0
failed=0
found=0

for src in "$DIR"/*.s; do
    [ -e "$src" ] || continue
    found=1

    name=$(basename "$src" .s)
    out="$DIR/$name.hex"

    if "${PREFIX}as"      -march=rv32i -mabi=ilp32 -o "$TMP/$name.o" "$src" &&
       "${PREFIX}ld"      -melf32lriscv -Ttext=0x0 -o "$TMP/$name.elf" "$TMP/$name.o" &&
       "${PREFIX}objcopy" -O binary -j .text "$TMP/$name.elf" "$TMP/$name.bin"; then

        if [ "$WORDS" = "1" ]; then
            od -An -v -tx4 -w4 "$TMP/$name.bin" | tr -d ' ' > "$out"
        else
            od -An -v -tx1 -w1 "$TMP/$name.bin" | tr -d ' ' > "$out"
        fi

        echo "ok    $name.hex"
        ok=$((ok + 1))
    else
        echo "FAIL  $src"
        rm -f "$out"
        failed=$((failed + 1))
    fi
done

if [ "$found" -eq 0 ]; then
    echo "no .s files found in $DIR" >&2
    exit 1
fi

echo "$ok converted, $failed failed"
[ "$failed" -eq 0 ]

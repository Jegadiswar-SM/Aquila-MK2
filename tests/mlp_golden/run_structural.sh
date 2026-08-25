#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR=$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)
BUILD_DIR=$(mktemp -d /tmp/aquila-mlp-structural.XXXXXX)
trap 'rm -rf "$BUILD_DIR"' EXIT

iverilog -g2012 -Wall -Wno-timescale -I"$ROOT_DIR/rtl" \
    "$ROOT_DIR/rtl/mlp_inference.v" \
    "$ROOT_DIR/tb/tb_mlp_transaction.v" \
    -o "$BUILD_DIR/tb_mlp_transaction"

timeout 30s "$BUILD_DIR/tb_mlp_transaction" | tee "$BUILD_DIR/result.log"
grep -q '^RESULT: PASS' "$BUILD_DIR/result.log"

iverilog -g2012 -Wall -Wno-timescale \
    "$ROOT_DIR/rtl/mlp_inference.v" \
    "$ROOT_DIR/tb/tb_mlp_qaa_oracle.v" \
    -o "$BUILD_DIR/tb_mlp_qaa_oracle"
qaa_output=$("$BUILD_DIR/tb_mlp_qaa_oracle")
printf '%s\n' "$qaa_output"
grep -q 'qaa(2)=ffff.*qaa(8192)=0000.*qaa(8193)=1f06' <<< "$qaa_output"
grep -q 'neg16384=e0fa.*neg32768=8800' <<< "$qaa_output"
echo 'MLP STRUCTURAL/TRANSACTION CHECK: PASS'

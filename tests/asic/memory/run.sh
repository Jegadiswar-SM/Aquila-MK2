#!/usr/bin/env bash
set -eu
ROOT_DIR=$(cd "$(dirname "$0")/../../.." && pwd)
BUILD_DIR=$(mktemp -d /tmp/aquila-memory.XXXXXX)
trap 'rm -rf "$BUILD_DIR"' EXIT
iverilog -g2012 -Wall -Wno-timescale -I"$ROOT_DIR/rtl" \
  "$ROOT_DIR/rtl/mlp_weight_sram_wrapper.v" \
  "$ROOT_DIR/tests/asic/memory/tb_mlp_weight_sram_wrapper.v" \
  -o "$BUILD_DIR/tb_memory"
timeout 30s "$BUILD_DIR/tb_memory"

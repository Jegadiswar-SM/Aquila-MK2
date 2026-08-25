#!/usr/bin/env bash
set -eu

ROOT_DIR=$(cd "$(dirname "$0")/.." && pwd)
BUILD_DIR="$ROOT_DIR/build/iverilog-regression"
TIMEOUT_SECONDS=${TIMEOUT_SECONDS:-30}

rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR/bin" "$BUILD_DIR/log"

passed=0
total=0

run_tb() {
    name=$1
    shift
    total=$((total + 1))
    exe="$BUILD_DIR/bin/$name"
    log="$BUILD_DIR/log/$name.log"

    echo "[RUN] $name"
    iverilog -g2012 -Wall -Wno-timescale -I "$ROOT_DIR/rtl" \
        "$ROOT_DIR/tb/$name.v" "$@" -o "$exe"
    timeout "$TIMEOUT_SECONDS" "$exe" > "$log" 2>&1
    if ! grep -Eq '(^RESULT: PASS|^NR2_SWEEP_PASS$)' "$log"; then
        echo "[FAIL] $name"
        sed -n '1,120p' "$log"
        exit 1
    fi
    echo "[PASS] $name"
    passed=$((passed + 1))
}

run_tb tb_aad "$ROOT_DIR/rtl/aad.v"
run_tb tb_affhc "$ROOT_DIR/rtl/affhc.v"
run_tb tb_cbpf_2sos "$ROOT_DIR/rtl/cbpf_2sos.v"
run_tb tb_fwes "$ROOT_DIR/rtl/fwes.v"
run_tb tb_plwd "$ROOT_DIR/rtl/plwd.v"
run_tb tb_poly_decim "$ROOT_DIR/rtl/poly_decim.v"
run_tb tb_ptdl_8stage "$ROOT_DIR/rtl/ptdl_8stage.v"
run_tb tb_rcim "$ROOT_DIR/rtl/rcim.v"
run_tb tb_rcim_negative "$ROOT_DIR/rtl/rcim.v"
run_tb tb_rls_engine_sat "$ROOT_DIR/rtl/rls_engine.v"
run_tb tb_nr2_isolated "$ROOT_DIR/rtl/rls_engine.v"
run_tb tb_mlp_schedule "$ROOT_DIR/rtl/mlp_inference.v" "$ROOT_DIR/rtl/mlp_weight_sram_wrapper.v"

CORE_RTL=(
    "$ROOT_DIR/rtl/aad.v"
    "$ROOT_DIR/rtl/affhc.v"
    "$ROOT_DIR/rtl/cbpf_2sos.v"
    "$ROOT_DIR/rtl/fwes.v"
    "$ROOT_DIR/rtl/lat_prof.v"
    "$ROOT_DIR/rtl/mlp_inference.v"
    "$ROOT_DIR/rtl/mlp_weight_sram_wrapper.v"
    "$ROOT_DIR/rtl/plwd.v"
    "$ROOT_DIR/rtl/poly_decim.v"
    "$ROOT_DIR/rtl/ptdl_8stage.v"
    "$ROOT_DIR/rtl/rcim.v"
    "$ROOT_DIR/rtl/rls_dnn_top.v"
    "$ROOT_DIR/rtl/rls_engine.v"
    "$ROOT_DIR/rtl/rst_sync.v"
)

run_tb tb_top_admission "${CORE_RTL[@]}"
run_tb tb_top_alignment "${CORE_RTL[@]}"
run_tb tb_top_output_hold "${CORE_RTL[@]}"
run_tb tb_top_read "${CORE_RTL[@]}"
run_tb tb_control_plane "${CORE_RTL[@]}"
run_tb tb_fault_status_top "${CORE_RTL[@]}"
run_tb tb_top_long_transaction "${CORE_RTL[@]}"

echo "REGRESSION: $passed/$total PASS"

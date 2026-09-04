#!/usr/bin/env bash
set -euo pipefail

ROOT_DIR=$(cd "$(dirname "$0")/../.." && pwd)
SIM=${SIM:-irun}
TEST=${1:-tb_top_admission}
GUI=${GUI:-0}

cd "$ROOT_DIR"

if ! command -v "$SIM" >/dev/null 2>&1; then
    echo "ERROR: simulator '$SIM' was not found in PATH" >&2
    echo "Use SIM=irun for Incisive or SIM=xrun for Xcelium." >&2
    exit 127
fi

case "$TEST" in
    tb_rls_dnn_top|tb_top_admission|tb_top_alignment|tb_top_output_hold|\
    tb_top_read|tb_control_plane|tb_fault_status_top|tb_top_long_transaction)
        FILELIST="cadence/incisive/filelists/chip/$TEST.f"
        ;;
    tb_aad|tb_affhc|tb_cbpf_2sos|tb_fwes|tb_plwd|tb_poly_decim|\
    tb_ptdl_8stage|tb_rcim|tb_rcim_negative|tb_rls_engine_sat|\
    tb_nr2_isolated|tb_mlp_schedule)
        FILELIST="cadence/incisive/filelists/unit/$TEST.f"
        ;;
    *)
        echo "ERROR: unknown test '$TEST'" >&2
        echo "Run: $0 <testbench-name>" >&2
        exit 2
        ;;
esac

GUI_ARGS=()
if [[ "$GUI" == "1" ]]; then
    GUI_ARGS+=("-gui" "-linedebug")
fi

exec "$SIM" -64bit -sv -timescale 1ns/1ps \
    "${GUI_ARGS[@]}" -f "$FILELIST" -top "$TEST" -access +rwc -R

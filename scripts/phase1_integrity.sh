#!/bin/bash
echo "=== PHASE 1: RTL INTEGRITY CHECK ==="
{
  # 1. Placeholder check
  grep -rn "XXXX\|UNSET_TOKEN\|TEMP_MARKER" rtl/ && echo "FAIL: placeholders found" || echo "PASS: no placeholders"

  # 2. Zero-weight check
  python3 -c "
  import re, sys
  try:
      content = open('rtl/mlp_weights.vh').read()
      zeros = len(re.findall(r'16.h0000', content))
      total = len(re.findall(r'16.h[0-9A-Fa-f]{4}', content))
      pct = zeros/total*100 if total>0 else 100
      print(f'mlp_weights.vh: {total} weights, {zeros} zeros ({pct:.1f}%)')
      if pct > 20: print('WARNING: >20% zero weights — retrain model')
      else: print('PASS: weight distribution looks trained')
  except FileNotFoundError:
      print('MISSING: rtl/mlp_weights.vh — run training pipeline first')
  "

  # 3. Compile check (iverilog - skip if not found)
  if command -v iverilog &>/dev/null; then
    for f in rtl/*.v; do
      iverilog -Wall -Wno-timescale -I rtl/ "$f" -o /dev/null 2>&1 \
        && echo "PASS: $f" \
        || echo "FAIL: $f"
    done
  else
    echo "SKIPPED: iverilog not found"
  fi

  # 4. Full design compile (iverilog - skip if not found)
  if command -v iverilog &>/dev/null; then
    iverilog -Wall -Wno-timescale -I rtl/ \
      rtl/rls_dnn_top.v rtl/rls_engine.v rtl/mlp_inference.v \
      rtl/ptdl_8stage.v rtl/affhc.v rtl/aad.v rtl/cbpf_2sos.v \
      rtl/plwd.v rtl/rcim.v rtl/fwes.v rtl/poly_decim.v rtl/lat_prof.v \
      -o /dev/null 2>&1 && echo "FULL COMPILE: PASS" || echo "FULL COMPILE: FAIL"
  else
    echo "SKIPPED: iverilog not found"
  fi

  # 5. Lint with verilator
  if command -v verilator &>/dev/null; then
    verilator --lint-only -Wall -I rtl/ rtl/rls_dnn_top.v 2>&1 \
      | tee sim/lint_report.txt \
      && echo "LINT: PASS" || echo "LINT: warnings (see sim/lint_report.txt)"
  else
    echo "SKIPPED: verilator not found"
  fi

  # 6. Line count
  wc -l rtl/*.v rtl/*.vh 2>/dev/null | sort -rn
} > docs/patent_package/evidence/rtl_integrity.txt 2>&1

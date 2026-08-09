#!/bin/bash
echo "=== PHASE 2: SIMULATION ==="
for tb in tb_rls_dnn_top tb_affhc tb_aad tb_cbpf_2sos tb_plwd tb_rcim; do
  echo "--- Testing $tb ---"
  if command -v iverilog &>/dev/null; then
    iverilog -Wall -Wno-timescale -I rtl/ tb/${tb}.v rtl/*.v -o sim/${tb} 2>&1 | tee sim/${tb}_compile.log
    if [ ${PIPESTATUS[0]} -eq 0 ]; then
       cd sim && ./${tb} 2>&1 | tee ${tb}_sim.log && cd ..
       if [ -f "sim/${tb}.vcd" ]; then
         echo "VCD generated: $(wc -c < sim/${tb}.vcd) bytes"
       else
         echo "WARNING: no VCD generated"
       fi
       grep -E "SNR|PASS|FAIL|assert|error|convergence|fault|latency" sim/${tb}_sim.log >> docs/patent_package/evidence/simulation_results.txt
    else
       echo "COMPILE FAILED: $tb" >> docs/patent_package/errors.log
    fi
  else
    echo "SKIPPED: iverilog not found for $tb"
    echo "PHASE 2: FAILED (No iverilog) for $tb" >> docs/patent_package/errors.log
  fi
done

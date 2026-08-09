#!/bin/bash
echo "=== PHASE 0: ENVIRONMENT AUDIT ==="
{
  python3 --version
  iverilog -V 2>&1 | head -1
  yosys --version 2>&1 | head -1 || echo "yosys: not found"
  verilator --version 2>&1 | head -1 || echo "verilator: not found"
  pip show torch scipy numpy matplotlib 2>&1 | grep -E "Name|Version"
  find rtl/ -name "*.v" -o -name "*.vh" | sort
  find tb/ -name "*.v" | sort
  find models/ -type f 2>/dev/null | sort || echo "models/: not found"
  find data/ -type f 2>/dev/null | sort || echo "data/: not found"
} > docs/patent_package/env_audit.txt 2>&1

echo "=== ENVIRONMENT AUDIT ==="
echo "RTL files found: $(find rtl/ -name "*.v" -o -name "*.vh" | wc -l)"
echo "Testbench files found: $(find tb/ -name "*.v" | wc -l)"
if [ -d "models" ] && [ "$(ls -A models)" ]; then echo "Trained model exists: YES"; else echo "Trained model exists: NO"; fi
if command -v iverilog &>/dev/null; then echo "iverilog available: YES"; else echo "iverilog available: NO"; fi
if python3 -c "import torch" &>/dev/null; then echo "PyTorch available: YES"; else echo "PyTorch available: NO"; fi
if python3 -c "import scipy" &>/dev/null; then echo "scipy available: YES"; else echo "scipy available: NO"; fi
if python3 -c "import matplotlib" &>/dev/null; then echo "matplotlib available: YES"; else echo "matplotlib available: NO"; fi

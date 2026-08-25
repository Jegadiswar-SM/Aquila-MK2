# =============================================================================
# Makefile — MHDA Simulation
# SPDX-License-Identifier: Apache-2.0
# =============================================================================
# Usage:
#   make              Build and run the checked-in Icarus regression
#   make lint         Verilator lint all design files
#   make regression   Same as the default target
#   make clean        Remove build artifacts
# =============================================================================

VERILATOR ?= verilator

RTL_DIR   := ../rtl
TB_DIR    := ../tb
BUILD_DIR := ../build

VL_FLAGS  := --lint-only --timing -Wall --Wno-fatal \
             +incdir+$(abspath $(RTL_DIR))

# The pad wrapper is technology-specific and currently names SkyWater cells.
# Core simulation/lint must not depend on that wrapper or on any foundry IO model.
RTL_SRCS  := $(filter-out $(RTL_DIR)/mhda_io_ring.v,$(wildcard $(RTL_DIR)/*.v))
.PHONY: all lint regression clean

all: regression

# The Icarus script performs actual compilation, simulation, timeout
# handling, and result checking.  Verilator lint remains a separate target.
regression:
	bash ../scripts/run_iverilog_regression.sh

# --- Lint all design modules -----------------------------------------------
lint:
	$(VERILATOR) $(VL_FLAGS) --top-module rls_dnn_top $(RTL_SRCS)

# --- Clean ----------------------------------------------------------------
clean:
	rm -rf $(BUILD_DIR) obj_dir *.vcd

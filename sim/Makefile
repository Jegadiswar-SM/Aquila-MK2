# =============================================================================
# Makefile — MHDA Simulation
# SPDX-License-Identifier: Apache-2.0
# =============================================================================
# Usage:
#   make              Build and run all testbenches
#   make <tgt>        Run specific testbench (e.g., make tb_rls_dnn_top)
#   make lint         Verilator lint all design files
#   make clean        Remove build artifacts
# =============================================================================

VERILATOR ?= verilator

RTL_DIR   := ../rtl
TB_DIR    := ../tb
BUILD_DIR := ../build

VL_FLAGS  := --lint-only --timing -Wall +incdir+$(abspath $(RTL_DIR)) \
             -Wno-UNOPTFLAT -Wno-CASEINCOMPLETE -Wno-WIDTH \
             -Wno-UNUSEDSIGNAL -Wno-UNUSEDPARAM -Wno-PINCONNECTEMPTY \
             -Wno-SYNCASYNCNET -Wno-BLKSEQ

RTL_SRCS  := $(wildcard $(RTL_DIR)/*.v)
TB_SRCS   := $(wildcard $(TB_DIR)/*.v)

# All testbench module names (strip .v prefix)
TB_MODS   := $(notdir $(basename $(TB_SRCS)))

.PHONY: all lint clean $(TB_MODS)

all: $(TB_MODS)

# --- Run a single testbench ------------------------------------------------
define TB_RULE
$(1): $(RTL_SRCS) $(TB_DIR)/$(1).v
	mkdir -p $(BUILD_DIR)
	$(VERILATOR) $(VL_FLAGS) --top-module $(1) \
		$(TB_DIR)/$(1).v $(RTL_SRCS) 2>&1 | \
		grep -vE "^(%Warning|.*Warning|- Verilator)" | cat
	@echo "--- $(1): LINT $$? ---"
endef

$(foreach tb,$(TB_MODS),$(eval $(call TB_RULE,$(tb))))

# --- Lint all design modules -----------------------------------------------
lint:
	$(VERILATOR) $(VL_FLAGS) --top-module rls_dnn_top $(RTL_SRCS)

# --- Clean ----------------------------------------------------------------
clean:
	rm -rf $(BUILD_DIR) obj_dir *.vcd

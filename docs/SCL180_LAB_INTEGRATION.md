# Aquila-MK2 SCL180 laboratory integration

This document describes the handoff boundary from the technology-independent
RTL repository to the university/laboratory SCL180 environment.  No PDK,
Cadence database, library, macro, or foundry cell is included here.

## Core synthesis boundary

Synthesize the module:

```text
rls_dnn_top
```

The core clock and reset ports are `clk` and `rst_n`.  The reviewed core has
one logical clock domain.  `mhda_io_ring` is not the ASIC synthesis top: it
contains hard-coded SkyWater IO-cell references and must be replaced by a
laboratory SCL180 IO wrapper.

## RTL source set

Include the following core RTL files:

```text
rtl/aad.v
rtl/affhc.v
rtl/cbpf_2sos.v
rtl/fwes.v
rtl/lat_prof.v
rtl/mlp_inference.v
rtl/mlp_weight_sram_wrapper.v
rtl/plwd.v
rtl/poly_decim.v
rtl/ptdl_8stage.v
rtl/rcim.v
rtl/rls_dnn_top.v
rtl/rls_engine.v
rtl/rst_sync.v
```

Do not include:

```text
rtl/mhda_io_ring.v       # SkyWater-specific pad wrapper
rtl/mlp_weights.vh       # stale zero/old-topology artifact; not used by the current MLP
syn/constraints/*.xdc    # FPGA constraints
syn/constraints/rls_dnn_top.sdc  # legacy pad-level constraints, not an approved ASIC SDC
tb/*                     # verification-only sources
models/*, data/*         # model/data artifacts, not synthesis sources
```

The behavioral `mlp_weight_sram_wrapper` is included for RTL elaboration and
functional simulation.  In the lab, replace its storage implementation or
bind the real memory wrapper without changing the logical interface.

## Memory dependency

The current logical memory is 8192 rows × 256 bits, with:

- one synchronous read command: `ren`, `raddr[12:0]`;
- one-cycle read response: `rdata[255:0]`, `rvalid`;
- one 16-bit sequential programming write: `wload_en`, `wload_addr[16:0]`,
  `wload_data[15:0]`;
- `wload_addr[16:4]` selecting a row and `[3:0]` selecting one 16-bit lane.

Required logical capacity is approximately 2.1 Mbit.  The actual SCL180
macro, aspect ratio, port configuration, read-during-write behavior, timing,
test interface, and macro-to-wrapper adaptation are:

**LAB PDK DEPENDENCY — FILL FROM ACTUAL SCL180 INSTALLATION.**

No SRAM or ROM cell name is assumed by this repository.

## IO replacement

The laboratory wrapper must provide IOs for:

- `clk`, `rst_n`, and `sample_enable`;
- 32-bit `s_axis_tdata`, `s_axis_tvalid`, `s_axis_tready`;
- 16-bit `m_axis_tdata`, `m_axis_tvalid`, `m_axis_tready`;
- 8-bit control address/write and read address channels;
- 32-bit control write/read data;
- control valid/ready/response signals;
- 17-bit weight-load address, weight-load enable, and 16-bit weight data;
- `clk_gate_en` and `irq_fault` outputs;
- the required SCL180 power and ground pad strategy.

Actual pad cell names, voltage domains, ESD requirements, power-pad count,
placement rules, drive strengths, input thresholds, and electrical models are:

**LAB PDK DEPENDENCY — FILL FROM ACTUAL SCL180 INSTALLATION.**

## Libraries and Cadence setup

The lab flow must provide, at minimum, the approved SCL180:

- standard-cell Liberty timing/power views;
- standard-cell LEF and GDS views;
- technology LEF and extraction data;
- IO/pad Liberty, LEF, GDS, and electrical views;
- filler, tap, endcap, tie, and antenna collateral;
- approved SRAM/ROM macro views if macros are used;
- DRC, LVS, antenna, extraction, and reliability decks;
- the installed Cadence tool versions and any required licenses.

Every item above is a **LAB PDK DEPENDENCY — FILL FROM ACTUAL SCL180 INSTALLATION**.

Set the lab-specific search paths, library names, MMMC corners, and tool
configuration in local files derived from the templates.  Do not commit the
PDK or local absolute paths.

## Constraints

Start from [rls_dnn_top.sdc.template](../constraints/asic/rls_dnn_top.sdc.template).
The approved clock period, uncertainty, input delays, output delays, drive,
load, and any reset exception are not established in this repository.  The
legacy 100-MHz value in the old constraints is not treated as an approved
ASIC target.

## Genus and Innovus entry requirements

Before Genus, fill in:

1. actual tool version;
2. actual SCL180 library and search paths;
3. the core RTL file list above;
4. `rls_dnn_top` as the top;
5. an approved MMMC setup;
6. the completed ASIC SDC template;
7. the selected memory implementation and wrapper;
8. the replacement SCL180 IO wrapper if a pad-level top is required.

The actual Genus and Innovus commands are intentionally not prescribed here:
they depend on the installed Cadence release, site scripts, library naming,
and lab methodology.  **LAB PDK DEPENDENCY — FILL FROM ACTUAL INSTALLATION.**

## DFT and signoff

The RTL exposes no implemented scan chain.  The lab must define scan clocks,
scan enable, test reset, clock-gating bypass, memory test strategy, scan
compression (if any), and controllability/observability requirements using
the actual DFT flow.  DFT execution is **NOT VERIFIED** here.

Physical signoff still requires actual timing, power, IR/EM, DRC, LVS,
antenna, reliability, and GDS checks in the SCL180 environment.  None of
those results are present in this repository.

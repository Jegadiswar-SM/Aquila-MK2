# Cadence Incisive simulation flow

This directory contains the simulator-facing organization for Aquila-MK2.
The source of truth remains `rtl/` and `tb/`; the filelists provide categorized
views without duplicating or moving those files.

## Directory organization

```text
cadence/incisive/
├── filelists/
│   ├── rtl/core.f       # technology-independent chip RTL
│   ├── chip/*.f         # rls_dnn_top integration testbenches
│   └── unit/*.f         # individual block testbenches
└── run.sh               # irun/xrun launcher
```

The core list excludes `rtl/mhda_io_ring.v`. That wrapper instantiates
SkyWater pad cells and is not usable until the foundry IO simulation models
are available. `rtl/mlp_weights.vh` is included by the RTL and is not a
standalone compilation unit.

## Run with Incisive

From the repository root:

```bash
SIM=irun cadence/incisive/run.sh tb_top_admission
SIM=irun cadence/incisive/run.sh tb_control_plane
SIM=irun cadence/incisive/run.sh tb_rls_dnn_top
```

## Run with the Incisive GUI / SimVision

Use `GUI=1`. This invokes Incisive with `-gui -linedebug`, opens SimVision,
and starts the selected testbench:

```bash
GUI=1 SIM=irun cadence/incisive/run.sh tb_top_admission
```

In SimVision, add signals from `tb_top_admission.dut` or the testbench scope
to the waveform window, then use **Run** or **Run Until**. The testbench also
creates a VCD file for the tests that contain `$dumpfile`/`$dumpvars`.

For a direct GUI invocation:

```bash
irun -64bit -sv -timescale 1ns/1ps -gui -linedebug \
  -f cadence/incisive/filelists/chip/tb_top_admission.f \
  -top tb_top_admission -access +rwc -R
```

The default test is `tb_top_admission`. The same flow works with Xcelium:

```bash
SIM=xrun cadence/incisive/run.sh tb_top_read
```

Available chip-level tests are `tb_rls_dnn_top`, `tb_top_admission`,
`tb_top_alignment`, `tb_top_output_hold`, `tb_top_read`, `tb_control_plane`,
`tb_fault_status_top`, and `tb_top_long_transaction`. Unit-level tests are
listed under `filelists/unit/`.

For a direct invocation, for example:

```bash
irun -64bit -sv -timescale 1ns/1ps \
  -f cadence/incisive/filelists/chip/tb_top_admission.f \
  -top tb_top_admission -access +rwc -R
```

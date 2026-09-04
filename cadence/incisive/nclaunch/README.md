# NClaunch setup

Start `nclaunch` from this directory so the local Cadence library setup is
used:

```bash
cd cadence/incisive/nclaunch
nclaunch -gui
```

In NClaunch, add the repository root as the project/source location and use
one of the chip filelists from:

```text
../filelists/chip/
```

For the complete chip testbench, select:

```text
../filelists/chip/tb_rls_dnn_top.f
```

Set the simulation top to `tb_rls_dnn_top`, choose **Compile**, then
**Elaborate**, and finally **Simulate/Run**. For the focused chip tests, use
the matching filelist and top name, for example
`tb_control_plane.f` / `tb_control_plane`.

The RTL and testbenches use SystemVerilog constructs. In NClaunch, enable the
SystemVerilog language option for compilation (equivalent to passing `-sv` to
`ncvlog` and `irun`). Without it, loop declarations, block-local
declarations, `.*` port connections, and signed integer declarations are
reported as compile errors.

The filelists use paths relative to the repository root. If NClaunch resolves
filelist paths relative to its launch directory, start it from the repository
root instead and select:

```bash
nclaunch -gui
```

Then select `cadence/incisive/filelists/chip/tb_rls_dnn_top.f`.

The core list deliberately excludes `rtl/mhda_io_ring.v`, since that wrapper
requires SkyWater pad-cell simulation models. Add that wrapper only after the
foundry IO models and their `cds.lib` definitions are available.

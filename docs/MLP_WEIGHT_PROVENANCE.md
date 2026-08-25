# MLP weight provenance

## Conclusion

**MLP VERIFICATION BLOCKED — AUTHORITATIVE CURRENT-TOPOLOGY WEIGHTS ARE NOT
PRESENT.** No weight values are being invented, retrained, zero-filled as
trained data, or loaded into the RTL baseline.

The RTL schedule requires 8→128→384→128→1. The required parameter count is:

```text
8*128 + 128 + 128*384 + 384 + 384*128 + 128 + 128*1 + 1 = 100097
```

| Artifact | Topology | Trained? | Format | Quantization | Matches RTL? | Status |
|---|---|---|---|---|---|---|
| `rtl/mlp_weights.vh` | Declares current tensor sizes | No; all 100097 words are zero placeholders | Verilog localparams | Nominal Q1.15 words | No trained values | BLOCKED / stale placeholder |
| `models/best_mlp.pt` | 8→64→32→1 | Appears to be a historical trained checkpoint; provenance not independently authenticated | PyTorch state-dict archive, float tensors | No RTL quantization in artifact | No; 2689 parameters | REJECTED: topology mismatch |
| `scripts/models/best_mlp.pt` | 8→64→32→1 | Same historical class of artifact | PyTorch state-dict archive, float tensors | No RTL quantization in artifact | No; 2689 parameters | REJECTED: topology mismatch |
| `models/train_metrics.json` | Claims 100097 parameters | Training metadata only | JSON | Not applicable | Conflicts with checkpoint tensor sizes | INCONSISTENT metadata |
| `data/*.npz` | Dataset unknown locally | Not available | Git-LFS pointer text | Not available | Cannot train or generate vectors | BLOCKED |
| `scripts/mhda_mlp.py` | 8→128→384→128→1 | Model definition only | PyTorch module | QAT helper uses Q1.15 round/clamp | Defines expected topology | AVAILABLE definition |
| `scripts/export_weights.py` | Expects current model keys/shapes | Converter, not source data | Verilog localparam output | `round(value*32768)`, clamp to int16 | Intended shape matches RTL, but stale checkpoint cannot load | AVAILABLE but unexecuted here |
| `scripts/export_mlp_memory.py` | Requires exact current state-dict shapes | Deterministic SRAM-loader converter | 131072 lines of 16-bit hex words | Signed Q1.15 round/clamp; explicit RTL row/lane map | Rejects stale checkpoint before output | AVAILABLE; execution blocked by missing torch/model |

Observed SHA-256 values:

```text
models/best_mlp.pt          2fa3d5633a7967993997490bd4b0be7d5eeab77782d8896b50b7262cf89a458e
scripts/models/best_mlp.pt  4e5ae08129226654f132938b467a511594a58636d8a2b310459a1f618b173f59
rtl/mlp_weights.vh          c978fc1cc1e8b25bbc611f880fb73f9580b173fa23bc1e2fb60b2ea8213fd523
```

The two checkpoint files are not byte-identical. Both archive inventories have
the six storages corresponding to 2689 float32 parameters; neither is accepted
as the current authoritative model.

## Required import contract

When an authorized current-topology checkpoint becomes available, the existing
model definition and exporter must be run with strict shape validation for:

```text
fc1.weight [128, 8]       fc1.bias [128]
fc2.weight [384, 128]     fc2.bias [384]
fc3.weight [128, 384]     fc3.bias [128]
fc4.weight [1, 128]       fc4.bias [1]
```

The converter must reject any missing key, extra key, shape mismatch,
non-finite value, or topology mismatch before writing an image. It must record
the source SHA-256, converter version, tensor shapes, Q-format, rounding,
saturation, flattening order, memory-row map, and generated-image SHA-256.

No generated image or checksum is claimed in this repository because no
authoritative source was available.

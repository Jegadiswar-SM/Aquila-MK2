# Aquila-MK1 MLP Weight Forensic Report

Investigation date: 2026-08-25 UTC

## Executive result

**CASE D — no usable authoritative current-topology weight artifact is
available in the repository or reachable Git object database.**

No weights were invented, regenerated, randomized, retrained, or written into
the RTL. The trained-model and golden-vector blocker therefore remains valid.

## Artifact classification

| Artifact | Layer/topology | Dimensions | Format | Trained? | Matches RTL? | Provenance | Status |
|---|---|---:|---|---|---|---|---|
| `rtl/mlp_weights.vh` | Current nominal layer declarations | 100097 16-bit words | Verilog localparams | No evidence; all values are zero | Nominal dimensions only; not connected to current SRAM wrapper | Header explicitly says stale/old topology and zero placeholders; SHA-256 `c978fc1cc1e8b25bbc611f880fb73f9580b173fa23bc1e2fb60b2ea8213fd523` | **STALE PLACEHOLDER** |
| `models/best_mlp.pt` | 8→64→32→1 | 512, 64, 2048, 32, 32, 1 float32 values | PyTorch zip checkpoint | Nonzero checkpoint, but no current-topology authority | **NO** | SHA-256 `2fa3d5633a7967993997490bd4b0be7d5eeab77782d8896b50b7262cf89a458e`; six storages imply 2689 parameters | **TOPOLOGY MISMATCH** |
| `scripts/models/best_mlp.pt` | 8→64→32→1 | 512, 64, 2048, 32, 32, 1 float32 values | PyTorch zip checkpoint | Nonzero checkpoint, but no current-topology authority | **NO** | SHA-256 `4e5ae08129226654f132938b467a511594a58636d8a2b310459a1f618b173f59`; binary differs from root copy | **TOPOLOGY MISMATCH / DUPLICATE** |
| `models/train_metrics.json` | Claims current training run | `params=100097` | JSON metrics | Metrics claim training, but no matching state dict | Cannot bind to checkpoint | Same file content as `scripts/models/train_metrics.json`; no weight checksum or model checksum | **INCONSISTENT METADATA** |
| `data/*.npz` | Intended datasets | LFS pointers only | Git-LFS pointer text | Not present locally | N/A | Pointer OIDs are present, payloads are absent | **UNAVAILABLE** |
| `scripts/data/*.npz` | Intended datasets | LFS pointers only | Git-LFS pointer text | Not present locally | N/A | Different LFS pointer OIDs; payloads are absent | **UNAVAILABLE** |
| `scripts/export_weights.py` | Intended 8→128→384→128→1 export | Exact current state-dict keys/shapes | Python/PyTorch exporter | Converter, not source | Shape contract matches RTL | Execution cannot recover the missing checkpoint; local Python lacks `torch` | **CONVERTER ONLY** |
| `scripts/export_mlp_memory.py` | Intended current SRAM image | 131072 16-bit words | Hex memory image + manifest | Converter, not source | Address map matches RTL | Strict importer rejects wrong keys/shapes; no source image generated | **INFRASTRUCTURE ONLY** |

## Direct statistics

`rtl/mlp_weights.vh` contains exactly 100,097 words across W1/B1/W2/B2/W3/B3/W4/B4.
All 100,097 words are `16'h0000`; every declaration has one unique value and
zero signed minimum/maximum. It is not evidence of a trained network and is
not functionally connected to the current behavioral SRAM wrapper.

The root checkpoint has six float32 storages with sizes corresponding to:

```text
fc1.weight [64, 8], fc1.bias [64]
fc2.weight [32, 64], fc2.bias [32]
fc3.weight [1, 32], fc3.bias [1]
```

The scripts copy has the same shapes but a different checksum and therefore
cannot be treated as a byte-identical duplicate.

## Search scope

The investigation searched RTL, Verilog includes, Python training/export and
verification scripts, model/data directories, JSON metadata, testbenches,
constraints, all tracked candidate paths, all refs, Git history, reflog, and
unreachable Git objects. The repository has one reachable commit
`168b7989e9a71bbcfa614903f55880ce68892b3d`; `git fsck` found no unreachable
objects containing recoverable artifacts.

## Required authoritative artifact

The missing artifact must contain the exact current topology, source-model
provenance, quantization scale and rounding rule, tensor ordering, bias
convention, export-tool version/commit, and SHA-256 of both source and
generated 131072-word image. Required tensor shapes are documented in
`MLP_VERIFICATION_BLOCKER.md`.

# Aquila-MK1 MLP Verification Blocker

Status: **BLOCKED — authoritative current-topology model/weights unavailable.**

## 1. What was searched

- `rtl/mlp_inference.v`, `rtl/mlp_weight_sram_wrapper.v`, and `rtl/mlp_weights.vh`
- all repository paths containing MLP, weight, model, training, export,
  inference, quantization, golden, vector, checkpoint, memory, hex, or binary
  references
- Python model, training, export, verification, and dataset-generation scripts
- `.pt`, `.pth`, `.npy`, `.npz`, `.onnx`, `.mem`, `.hex`, `.bin`, `.csv`, and
  JSON candidates
- Git tracked paths, all refs, file history, reflog, and unreachable objects

## 2. What was found

1. The active MLP RTL requires 8→128→384→128→1 and externally loaded SRAM
   rows 0–6256.
2. `rtl/mlp_weights.vh` declares current-sized arrays but contains 100% zero
   values, labels itself stale/old-topology, and is not included by the active
   MLP implementation.
3. Both committed PyTorch checkpoints are nonzero but encode 8→64→32→1,
   totaling 2689 parameters. They are not valid inputs to the current exporter
   or RTL topology.
4. The training metrics claim 100097 parameters but have no matching model
   checksum and conflict with both checkpoints.
5. Dataset files are Git-LFS pointer text without local payloads.

## 3. Why verification cannot be completed

There is no authoritative set of current-topology values that can be loaded
into the SRAM and compared against a software model. The zero placeholder is
not a trained model, and the old checkpoints cannot be projected into the
current topology without changing functionality or inventing data.

## 4. Exact artifact required to unblock

Provide one authorized source checkpoint or deterministic 131072-word memory
image implementing:

```text
fc1.weight [128, 8]       fc1.bias [128]
fc2.weight [384, 128]     fc2.bias [384]
fc3.weight [128, 384]     fc3.bias [128]
fc4.weight [1, 128]       fc4.bias [1]
```

The source and conversion record must specify:

- signed/real source format and tensor dtype;
- Q1.15 scale, rounding, clipping, and saturation policy;
- row-major tensor ordering and whether any transpose is applied;
- bias scaling compatible with the executable RTL bias alignment;
- activation contract (the RTL QAA approximation, not generic float tanh);
- export script/tool version and source revision;
- source-model SHA-256 and generated memory-image SHA-256.

The generated image must contain exactly 131072 lines of four-hex-digit words,
with the row/lane map in `MLP_RTL_NUMERICAL_CONTRACT.md`.

## 5. What is verified now

The exact integer reference, row map, schedule checks, and transaction test
infrastructure are prepared. They do not establish trained-model equivalence.

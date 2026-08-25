# MLP golden-vector specification

## Current status

**BLOCKED — authoritative 8→128→384→128→1 weights are required.** The
schedule-only zero-memory test is not a functional MLP equivalence test.

## Reference contract

The reference model must reproduce the executable RTL, not merely call a
generic neural-network layer. It shall explicitly implement:

- eight signed 16-bit Q1.15 feature values packed in PTDL order;
- signed 16×16 multiplication into 32-bit products;
- sign extension into the 40-bit accumulator;
- the exact RTL bias alignment (`bias_reg` concatenated with 16 zero bits);
- the four-segment `qaa_tanh` approximation, including thresholds and shifts;
- final-layer signed saturation and output slice;
- RTL memory row/lane ordering and one-cycle read latency;
- the measured transaction latency and valid timing.

The bias alignment is recorded as executable behavior, not silently corrected.
Whether the trained software model's bias scaling is intended to match that
alignment remains **REQUIRES SPECIFICATION** until authoritative model/export
provenance is supplied.

## Required vector classes

For each class, record packed input, expected output, RTL output, signed
absolute error, and bit-exact result:

1. all-zero vector;
2. one positive impulse in each of eight positions;
3. one negative impulse in each position;
4. alternating signs;
5. minimum representable values;
6. maximum representable values;
7. threshold/boundary values around every QAA segment;
8. deterministic pseudo-random vectors;
9. multiple consecutive transactions;
10. reset/restart and output-stall scenarios.

The acceptance target is **BIT-EXACT MATCH**. No numerical tolerance is
authorized by the current repository.

## Golden-vector file contract

The future `tests/mlp_golden/` harness shall use a text or JSONL format with:

```text
vector_id, packed_input_hex, expected_output_hex, rtl_output_hex,
absolute_error, bit_exact
```

The manifest shall include weight-image SHA-256, source-model SHA-256,
converter version, and vector-generation version. Until those values exist,
no MLP equivalence result may be marked VERIFIED.

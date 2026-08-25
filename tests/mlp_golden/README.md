# MLP golden-vector tests

This directory is reserved for authoritative-weight golden vectors. The
harness must not generate trained-model vectors until a current
8→128→384→128→1 model is provided. See `docs/MLP_GOLDEN_VECTOR_SPEC.md`.

The available direct check is a non-authoritative zero-memory transaction and
schedule test. It verifies reset, busy-time admission behavior, repeated
transactions, soft reset cancellation, and completion timing without claiming
that the zero placeholder is trained:

```sh
bash tests/mlp_golden/run_structural.sh
```

When available, run:

```text
python3 tests/mlp_golden/run_golden.py \
  --weights <authorized-weights.mem> \
  --vectors <authorized-vectors.jsonl>
```

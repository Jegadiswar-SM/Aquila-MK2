#!/usr/bin/env python3
"""
Independently reproduce the MLP suppression figures (3.7095 dB incremental /
8.7913 dB total) directly from the AS-BUILT quantized weights in
rtl/mlp_weights.vh — because the committed models/best_mlp.pt is a mismatched
2689-parameter (8->64->32->1) checkpoint that does NOT match the RTL, the
mhda_mlp.MHDA_MLP class, or train_metrics.json (100097 params).

We parse the Q1.15 weights from the RTL include, rebuild the 8->128->384->128->1
network, and run float-tanh inference on the canonical test split (data/test.npz).
Because the RTL stores QUANTIZED (Q1.15) weights rather than the original float
weights, the reproduced numbers are expected to sit very close to — but not bit
-identical to — the committed float-checkpoint figures.
"""
import os, re, json
import numpy as np

SCRIPTS = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(SCRIPTS)
VH = os.path.join(ROOT, "rtl", "mlp_weights.vh")

txt = open(VH).read()

def parse(name, n):
    m = re.search(rf"{name}\s*=\s*\d+'h([0-9A-Fa-f]+)\s*;", txt)
    if not m:
        raise RuntimeError(f"{name} not found")
    h = m.group(1)
    assert len(h) == n * 4, f"{name}: {len(h)} != {n*4}"
    vals = np.array([int(h[i:i+4], 16) for i in range(0, len(h), 4)], dtype=np.int64)
    vals = np.where(vals >= 0x8000, vals - 0x10000, vals)  # sign-extend Q1.15
    return vals.astype(np.float64) / 32768.0

W1 = parse("W1_INIT", 1024).reshape(128, 8)
B1 = parse("B1_INIT", 128)
W2 = parse("W2_INIT", 49152).reshape(384, 128)
B2 = parse("B2_INIT", 384)
W3 = parse("W3_INIT", 49152).reshape(128, 384)
B3 = parse("B3_INIT", 128)
W4 = parse("W4_INIT", 128).reshape(1, 128)
B4 = parse("B4_INIT", 1)

def forward(x):
    x = np.tanh(x @ W1.T + B1)
    x = np.tanh(x @ W2.T + B2)
    x = np.tanh(x @ W3.T + B3)
    return x @ W4.T + B4

data = np.load(os.path.join(ROOT, "data", "test.npz"))
X = data["X"].astype(np.float64)
Y = data["Y"].astype(np.float64)
pred = forward(X)

input_power = 0.22156404  # reproduced separately (verify_and_convergence.py)
rls_power = float(np.mean(Y ** 2))
post_mlp_power = float(np.mean((Y - pred) ** 2))

def db(a, b):
    return 10 * np.log10((a + 1e-8) / (b + 1e-8))

print("=== MLP verification from AS-BUILT rtl/mlp_weights.vh (Q1.15 weights) ===")
print(f"  rls_residual_power (=mean Y^2)     = {rls_power:.8f}   (committed 0.06875677)")
print(f"  post_mlp_residual_power            = {post_mlp_power:.8f}   (committed 0.02926628)")
print(f"  mlp_incremental_improvement_db     = {db(rls_power, post_mlp_power):.4f} dB   (claim 3.7095)")
print(f"  total_improvement_over_unfiltered  = {db(input_power, post_mlp_power):.4f} dB   (claim 8.7913)")

out = os.path.join(ROOT, "docs", "patent_package", "real_figures", "verify_mlp_from_rtl.json")
json.dump({
    "source": "rtl/mlp_weights.vh (as-built Q1.15 weights)",
    "rls_residual_power": rls_power,
    "post_mlp_residual_power": post_mlp_power,
    "mlp_incremental_improvement_db": db(rls_power, post_mlp_power),
    "total_improvement_over_unfiltered_db": db(input_power, post_mlp_power),
}, open(out, "w"), indent=2)
print("saved", out)

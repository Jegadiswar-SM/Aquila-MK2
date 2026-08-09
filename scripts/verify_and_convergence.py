#!/usr/bin/env python3
"""
(1) Independently verify the RLS-only improvement (5.0818 dB claim) by
    reconstructing the canonical test-split residuals with the hardware-accurate
    numpy RLS model in gen_dataset.simulate_rls_hw (no torch needed).
(2) Emit a REAL RLS convergence trace (error power settling over samples) for a
    representative signal, saved as JSON for the Fig-13 plot.

If torch is available, also load the committed best_mlp.pt and verify the
3.7095 dB incremental / 8.7913 dB total figures and add the post-MLP residual.
"""
import os, sys, json
import numpy as np

SCRIPTS = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(SCRIPTS)
sys.path.insert(0, SCRIPTS)
import gen_dataset as gd

OUT = os.path.join(ROOT, "docs", "patent_package", "real_figures")
os.makedirs(OUT, exist_ok=True)

N_SIGNALS = 500
SAMPLES = 5000


def reconstruct(n_signals, samples_per_signal):
    """Mirror measure_rls_split.reconstruct_residual_series (RLS part only)."""
    gd.rng = np.random.RandomState(gd.SEED)
    input_residual, rls_residual = [], []
    conv_trace = None  # (interf, e, clean) for the first signal
    # Ensemble accumulators: mean squared value at each within-signal sample index,
    # averaged across all signals, to show the true RLS convergence transient
    # (weights reset per signal) rather than one non-representative realization.
    ens_interf_sq = np.zeros(samples_per_signal, dtype=np.float64)
    ens_resid_sq = np.zeros(samples_per_signal, dtype=np.float64)
    ens_count = 0
    for si in range(n_signals):
        n_total = samples_per_signal + 100
        t = np.arange(n_total, dtype=np.float64) / gd.FS
        f_clean = gd.rng.uniform(400, 600)
        clean = (np.sin(2 * np.pi * f_clean * t) * gd.rng.uniform(0.1, 0.4)).astype(np.float32)
        interference_gen = gd.rng.choice(gd.INTERFERENCE_GENS)
        interference = interference_gen(n_total, gd.rng)
        noisy = np.clip(clean + interference, -1.0, 1.0).astype(np.float32)
        e, _ = gd.simulate_rls_hw(noisy, interference.copy(), N=8)
        e = e[100:]; clean = clean[100:]; interference = interference[100:]
        max_abs = max(np.max(np.abs(e)), np.max(np.abs(clean)))
        if max_abs > 1e-9:
            s = 1.0 / max_abs
            e *= s; clean *= s; interference *= s
        residual_after_rls = e - clean
        if si == 0:
            conv_trace = dict(interference=interference.tolist(),
                              rls_residual=residual_after_rls.tolist())
        m = min(samples_per_signal, len(interference))
        ens_interf_sq[:m] += interference[:m].astype(np.float64) ** 2
        ens_resid_sq[:m] += residual_after_rls[:m].astype(np.float64) ** 2
        ens_count += 1
        for n in range(7, len(e)):
            input_residual.append(interference[n])
            rls_residual.append(residual_after_rls[n])
    input_residual = np.array(input_residual, np.float32).reshape(-1, 1)
    rls_residual = np.array(rls_residual, np.float32).reshape(-1, 1)
    idx = gd.rng.permutation(len(rls_residual))
    n_train = int(0.8 * len(idx)); n_val = int(0.1 * len(idx))
    test_idx = idx[n_train + n_val:]
    conv_trace["ensemble_interference_msq"] = (ens_interf_sq / ens_count).tolist()
    conv_trace["ensemble_rls_residual_msq"] = (ens_resid_sq / ens_count).tolist()
    conv_trace["ensemble_n_signals"] = ens_count
    return input_residual[test_idx], rls_residual[test_idx], conv_trace


def db(num, den):
    return float(10 * np.log10((num + 1e-8) / (den + 1e-8)))


input_res, rls_res, conv = reconstruct(N_SIGNALS, SAMPLES)
input_power = float(np.mean(input_res ** 2))
rls_power = float(np.mean(rls_res ** 2))
rls_only_db = db(input_power, rls_power)
print("=== RLS-only verification (numpy, hardware-accurate) ===")
print(f"  unfiltered_interference_power = {input_power:.8f}")
print(f"  rls_residual_power            = {rls_power:.8f}")
print(f"  rls_only_improvement_db       = {rls_only_db:.4f} dB   (claim: 5.0818 dB)")

result = {
    "rls_only_improvement_db": rls_only_db,
    "unfiltered_interference_power": input_power,
    "rls_residual_power": rls_power,
}

# --- Optional MLP verification if torch present ---
post_mlp_power = None
try:
    import torch
    from mhda_mlp import MHDA_MLP
    data = np.load(os.path.join(ROOT, "data", "test.npz"))
    x_test = torch.tensor(data["X"], dtype=torch.float32)
    y_test = data["Y"].astype(np.float32)
    model = MHDA_MLP()
    model.load_state_dict(torch.load(os.path.join(ROOT, "models", "best_mlp.pt"), map_location="cpu"))
    model.eval()
    with torch.no_grad():
        mlp_pred = model(x_test).numpy()
    post_mlp_power = float(np.mean((y_test - mlp_pred) ** 2))
    result["post_mlp_residual_power"] = post_mlp_power
    result["mlp_incremental_improvement_db"] = db(rls_power, post_mlp_power)
    result["total_improvement_over_unfiltered_db"] = db(input_power, post_mlp_power)
    print("=== MLP verification (torch, committed best_mlp.pt) ===")
    print(f"  post_mlp_residual_power = {post_mlp_power:.8f}")
    print(f"  mlp_incremental_db      = {result['mlp_incremental_improvement_db']:.4f} dB  (claim: 3.7095)")
    print(f"  total_improvement_db    = {result['total_improvement_over_unfiltered_db']:.4f} dB  (claim: 8.7913)")
except Exception as e:
    print(f"  [torch unavailable — MLP figures not reproduced here: {e}]")

with open(os.path.join(OUT, "verify_numbers.json"), "w") as f:
    json.dump(result, f, indent=2)
with open(os.path.join(OUT, "convergence_trace.json"), "w") as f:
    json.dump(conv, f)
print("saved verify_numbers.json and convergence_trace.json")

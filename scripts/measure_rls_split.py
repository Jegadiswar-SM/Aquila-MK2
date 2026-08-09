#!/usr/bin/env python3
"""Measure RLS-only and MLP-on-RLS residual improvement on the test split."""

import argparse
import json
import os
import sys

import numpy as np
import torch

SCRIPTS = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(SCRIPTS)
sys.path.insert(0, SCRIPTS)

import gen_dataset as gd
from mhda_mlp import MHDA_MLP


def reconstruct_residual_series(n_signals, samples_per_signal):
    """Rebuild the canonical generator stream and return per-window residuals."""
    gd.rng = np.random.RandomState(gd.SEED)
    input_residual = []
    rls_residual = []

    for _ in range(n_signals):
        n_total = samples_per_signal + 100
        t = np.arange(n_total, dtype=np.float64) / gd.FS

        f_clean = gd.rng.uniform(400, 600)
        clean = (
            np.sin(2 * np.pi * f_clean * t) * gd.rng.uniform(0.1, 0.4)
        ).astype(np.float32)

        interference_gen = gd.rng.choice(gd.INTERFERENCE_GENS)
        interference = interference_gen(n_total, gd.rng)
        noisy = np.clip(clean + interference, -1.0, 1.0).astype(np.float32)

        e, _ = gd.simulate_rls_hw(noisy, interference.copy(), N=8)

        e = e[100:]
        clean = clean[100:]
        interference = interference[100:]

        max_abs = max(np.max(np.abs(e)), np.max(np.abs(clean)))
        if max_abs > 1e-9:
            scale = 1.0 / max_abs
            e = e * scale
            clean = clean * scale
            interference = interference * scale

        residual_after_rls = e - clean
        for n in range(7, len(e)):
            input_residual.append(interference[n])
            rls_residual.append(residual_after_rls[n])

    input_residual = np.array(input_residual, dtype=np.float32).reshape(-1, 1)
    rls_residual = np.array(rls_residual, dtype=np.float32).reshape(-1, 1)
    idx = gd.rng.permutation(len(rls_residual))
    n_train = int(0.8 * len(idx))
    n_val = int(0.1 * len(idx))
    test_idx = idx[n_train + n_val:]
    return input_residual[test_idx], rls_residual[test_idx], len(idx)


def db_ratio(numerator, denominator):
    return float(10 * np.log10((numerator + 1e-8) / (denominator + 1e-8)))


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--data-dir", default=os.path.join(ROOT, "data"))
    parser.add_argument("--model-dir", default=os.path.join(ROOT, "models"))
    parser.add_argument("--n-signals", type=int, default=500)
    parser.add_argument("--samples-per-signal", type=int, default=5000)
    parser.add_argument(
        "--out",
        default=os.path.join(
            ROOT, "docs", "patent_package", "evidence", "rls_mlp_split.json"
        ),
    )
    args = parser.parse_args()

    data = np.load(os.path.join(args.data_dir, "test.npz"))
    x_test = torch.tensor(data["X"], dtype=torch.float32)
    y_test = data["Y"].astype(np.float32)

    input_residual, rls_residual, total_windows = reconstruct_residual_series(
        args.n_signals, args.samples_per_signal
    )
    max_y_diff = float(np.max(np.abs(y_test - rls_residual)))
    if max_y_diff > 1e-6:
        raise RuntimeError(
            f"reconstructed RLS residual does not match test.npz: {max_y_diff}"
        )

    model = MHDA_MLP()
    model.load_state_dict(
        torch.load(os.path.join(args.model_dir, "best_mlp.pt"), map_location="cpu")
    )
    model.eval()
    with torch.no_grad():
        mlp_pred = model(x_test).numpy()

    post_mlp_residual = y_test - mlp_pred
    input_power = float(np.mean(input_residual**2))
    rls_power = float(np.mean(rls_residual**2))
    post_mlp_power = float(np.mean(post_mlp_residual**2))

    result = {
        "generator_seed": gd.SEED,
        "n_signals": args.n_signals,
        "samples_per_signal": args.samples_per_signal,
        "total_windows": total_windows,
        "test_windows": int(len(y_test)),
        "max_reconstructed_y_abs_diff": max_y_diff,
        "unfiltered_interference_power": input_power,
        "rls_residual_power": rls_power,
        "post_mlp_residual_power": post_mlp_power,
        "rls_only_improvement_db": db_ratio(input_power, rls_power),
        "mlp_incremental_improvement_db": db_ratio(rls_power, post_mlp_power),
        "total_improvement_over_unfiltered_db": db_ratio(input_power, post_mlp_power),
    }
    # Compatibility aliases used by the patent readiness checks.
    result["rls_only_snr"] = result["rls_only_improvement_db"]
    result["mlp_incremental_snr"] = result["mlp_incremental_improvement_db"]
    result["total_snr"] = result["total_improvement_over_unfiltered_db"]

    metrics_path = os.path.join(args.model_dir, "train_metrics.json")
    if os.path.exists(metrics_path):
        with open(metrics_path) as f:
            metrics = json.load(f)
        result["train_metrics_test_snr_db"] = metrics.get("test_snr")

    os.makedirs(os.path.dirname(args.out), exist_ok=True)
    with open(args.out, "w") as f:
        json.dump(result, f, indent=2)

    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()

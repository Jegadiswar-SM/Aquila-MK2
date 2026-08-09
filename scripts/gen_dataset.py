#!/usr/bin/env python3
"""
Synthetic underwater acoustic dataset generator for MHDA MLP training.
Generates clean + interference signals, runs RLS simulation, produces
8-sample PTDL windows (X) and target residuals (Y) as .npz files.
"""
# SPDX-License-Identifier: Apache-2.0

import os, argparse, warnings
warnings.filterwarnings("ignore")
import numpy as np
from scipy.signal import lfilter
from tqdm import tqdm

FS = 8000
SEED = 42
rng = np.random.RandomState(SEED)

# ---------------------------------------------------------------------------
# Interference generators
# ---------------------------------------------------------------------------
def tonal_interference(N, rng):
    """Type A: Narrowband tonal with harmonics (propeller cavitation sim)."""
    t = np.arange(N, dtype=np.float64) / FS
    f0 = rng.uniform(80, 400)
    A0 = rng.uniform(0.2, 0.9)
    phi = rng.uniform(0, 2 * np.pi)
    sig = A0 * np.sin(2 * np.pi * f0 * t + phi)
    for k in range(2, 6):
        sig += (A0 / k**1.5) * np.sin(2 * np.pi * k * f0 * t + rng.uniform(0, 2 * np.pi))
    return sig.astype(np.float32)

def broadband_noise(N, rng):
    """Type B: Coloured noise (flow noise sim) — 1st-order IIR."""
    white = rng.randn(N).astype(np.float32)
    target_rms = rng.uniform(0.15, 0.45)
    b = np.array([1.0], dtype=np.float32)
    a = np.array([1.0, -0.92], dtype=np.float32)
    coloured = lfilter(b, a, white)
    coloured *= target_rms / (np.std(coloured) + 1e-9)
    return coloured.astype(np.float32)

def transient_impulse(N, rng):
    """Type C: Gaussian pulse (sonar ping / mechanical shock)."""
    t = np.arange(N, dtype=np.float64) / FS
    sig = np.zeros(N, dtype=np.float32)
    n_impulses = max(1, N // rng.randint(50, 201))
    for _ in range(n_impulses):
        t0 = rng.uniform(0, N / FS)
        sigma = rng.uniform(0.0005, 0.002)
        fc = rng.uniform(200, 1000)
        A = rng.uniform(0.5, 1.0)
        envelope = np.exp(-((t - t0) ** 2) / (2 * sigma ** 2))
        carrier = np.sin(2 * np.pi * fc * (t - t0))
        sig += A * envelope * carrier
    return np.clip(sig, -1.0, 1.0).astype(np.float32)

def mixed_interference(N, rng, types=None):
    """Type D: Random combination of other types."""
    if types is None:
        types = [tonal_interference, broadband_noise, transient_impulse]
    k = rng.randint(2, 4)
    chosen = rng.choice(types, k, replace=False)
    sig = np.zeros(N, dtype=np.float32)
    for gen in chosen:
        comp = gen(N, rng)
        w = rng.uniform(0.3, 1.0)
        sig += w * comp
    peak = np.max(np.abs(sig))
    if peak > 1e-9:
        sig /= peak
    return np.clip(sig * rng.uniform(0.5, 0.9), -1.0, 1.0).astype(np.float32)

INTERFERENCE_GENS = [tonal_interference, broadband_noise, transient_impulse, mixed_interference]

# ---------------------------------------------------------------------------
# RLS simulation (hardware-accurate diagonal-P, 8 taps)
# Matches rls_engine.v: single p_scalar, P *= 129/128 per iter, leak factor
# ---------------------------------------------------------------------------
def _to_q(value, frac_bits, total_bits=16):
    scale = 1 << frac_bits
    xi = int(round(value * scale))
    return max(-(1 << (total_bits - 1)), min((1 << (total_bits - 1)) - 1, xi))

def _nr2_recip_q214(denom):
    """Corrected RTL-equivalent two-stage NR reciprocal.

    D is Q1.15, x/residual are signed Q2.14. The +2.0 term is saturated
    to 16'h7FFF because exact +2.0 is outside signed 16-bit Q2.14.
    """
    d_q15 = max(0x4000, min(0x7FFF, _to_q(denom, 15)))
    lut_idx = (d_q15 >> 10) & 0x1F
    d_mid = (lut_idx + 0.5) / 32.0
    x0 = _to_q(2.0 - d_mid, 14)
    two_q214 = 0x7FFF

    dx0_q214 = (d_q15 * x0) >> 15
    residual1 = two_q214 - dx0_q214
    x1 = (x0 * residual1) >> 14
    x1 = max(-32768, min(32767, x1))

    dx1_q214 = (d_q15 * x1) >> 15
    residual2 = two_q214 - dx1_q214
    x2 = (x1 * residual2) >> 14
    x2 = max(-32768, min(32767, x2))
    return x2 / 16384.0

def simulate_rls_hw(d, x, N=8, lam_q15=0x7F00, p_start=0x0800,
                     leak_q15=0x7FE0):
    """Hardware-accurate diagonal-P RLS returning e[n], y_hat[n]."""
    L = len(d)
    LAMBDA = lam_q15 / 32768.0
    LEAK = leak_q15 / 32768.0
    p = p_start / 32768.0
    P_Q15_MAX = 32767
    FRAC = 15

    w = np.zeros(N, dtype=np.float64)
    delay = np.zeros(N, dtype=np.float64)
    e_out = np.zeros(L, dtype=np.float64)
    y_out = np.zeros(L, dtype=np.float64)

    for n in range(L):
        delay = np.roll(delay, 1)
        delay[0] = x[n]
        x_vec = delay.copy()

        # y_hat = w @ x (hardware Q1.15 MAC, clipped)
        y_hat = np.clip(w @ x_vec, -1.0, 1.0)
        e = np.clip(d[n] - y_hat, -1.0, 1.0)

        # Hardware denominator: lambda + p * sum(x^2)
        xTx = np.sum(x_vec ** 2)
        denom = LAMBDA + p * xTx
        inv_denom = _nr2_recip_q214(denom)

        # Hardware weight update with leakage (E2)
        # w[j] = leak * w[j] + (p * inv_denom * x[j] * e)
        scale = p * inv_denom
        for j in range(N):
            w_j = LEAK * w[j]
            ke = scale * x_vec[j] * e
            w[j] = np.clip(w_j + ke, -1.0, 1.0)

        # P update: p += p >> 7  (in Q1.15 int units)
        p_int = int(round(p * 32768.0))
        p_int += p_int >> 7
        p_int = min(p_int, P_Q15_MAX)
        p = p_int / 32768.0

        e_out[n] = e
        y_out[n] = y_hat

    return e_out.astype(np.float32), y_out.astype(np.float32)

# ---------------------------------------------------------------------------
# Main generation
# ---------------------------------------------------------------------------
def generate_windowed_dataset(n_signals=200, samples_per_signal=5000):
    """Generate training/validation/test datasets."""
    all_X, all_Y = [], []
    total_windows = 0

    pbar = tqdm(range(n_signals), desc="Generating signals")
    for _ in pbar:
        N = samples_per_signal + 100  # extra samples for filter settling
        t = np.arange(N, dtype=np.float64) / FS

        # Clean signal: 400–600 Hz sine
        f_clean = rng.uniform(400, 600)
        clean = (np.sin(2 * np.pi * f_clean * t) * rng.uniform(0.1, 0.4)).astype(np.float32)

        # Pick interference type
        gen = rng.choice(INTERFERENCE_GENS)
        interf = gen(N, rng)

        # Noisy = clean + interference, clipped
        noisy = np.clip(clean + interf, -1.0, 1.0).astype(np.float32)

        # Reference = interference (what RLS tries to cancel)
        ref = interf.copy()

        # Run RLS (hardware-accurate diagonal-P)
        e, y_hat = simulate_rls_hw(noisy, ref, N=8)

        # Skip settling region (first 100 samples)
        e = e[100:]
        clean = clean[100:]
        noisy = noisy[100:]

        # Normalize e and clean to [-1, 1] range
        max_abs = max(np.max(np.abs(e)), np.max(np.abs(clean)))
        if max_abs > 1e-9:
            scale = 1.0 / max_abs
            e *= scale
            clean *= scale

        # PTDL windows: X = 8 consecutive RLS error samples
        # Target Y = clean[n] - (noisy[n] - e[n])  = clean[n] - y_hat[n]
        # Wait, the RLS error is e = noisy - y_hat.
        # So y_hat = noisy - e.
        # The noise component in 'noisy' is 'interf'.
        # The RLS error 'e' is 'noisy - y_hat'.
        # We want to train the MLP to map 'e' to 'interf'.
        # So Target Y = e[n] - clean[n] is wrong.
        # It should be Target Y = e[n] - (noisy[n] - clean[n]) = e[n] - interf[n].
        # Let's re-verify:
        # noisy = clean + interf
        # e = noisy - y_hat = clean + interf - y_hat
        # e = clean + (interf - y_hat)
        # We want MLP to learn (interf - y_hat).
        # So Y = e[n] - clean[n]
        for n in range(7, len(e)):
            X = e[n - 7:n + 1]  # 8 taps
            Y = e[n] - clean[n]
            all_X.append(X)
            all_Y.append([Y])
            total_windows += 1

        pbar.set_postfix({"windows": total_windows})

    all_X = np.array(all_X, dtype=np.float32)
    all_Y = np.array(all_Y, dtype=np.float32)

    # Check for degenerate targets
    if np.std(all_Y) < 0.05:
        print(f"  WARNING: Y has low variance (std={np.std(all_Y):.6f}) — targets might be degenerate")

    # Shuffle and split
    idx = rng.permutation(len(all_X))
    all_X = all_X[idx]
    all_Y = all_Y[idx]
    n_train = int(0.8 * len(all_X))
    n_val = int(0.1 * len(all_X))

    X_train, Y_train = all_X[:n_train], all_Y[:n_train]
    X_val, Y_val = all_X[n_train:n_train + n_val], all_Y[n_train:n_train + n_val]
    X_test, Y_test = all_X[n_train + n_val:], all_Y[n_train + n_val:]

    return (X_train, Y_train), (X_val, Y_val), (X_test, Y_test)

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate MHDA synthetic dataset")
    parser.add_argument("--n_signals", type=int, default=200, help="Number of signals to generate")
    parser.add_argument("--samples", type=int, default=5000, help="Samples per signal (default: 5000)")
    parser.add_argument("--fs", type=int, default=8000, help="Sample rate (Hz)")
    parser.add_argument("--seed", type=int, default=42, help="Random seed")
    parser.add_argument("--out_dir", type=str, default="data", help="Output directory")
    args = parser.parse_args()

    FS = args.fs
    SEED = args.seed
    rng = np.random.RandomState(SEED)
    os.makedirs(args.out_dir, exist_ok=True)

    print(f"Generating dataset: n_signals={args.n_signals}, fs={FS}, seed={SEED}")
    (X_tr, Y_tr), (X_val, Y_val), (X_te, Y_te) = generate_windowed_dataset(args.n_signals, args.samples)

    np.savez(os.path.join(args.out_dir, "train.npz"), X=X_tr, Y=Y_tr)
    np.savez(os.path.join(args.out_dir, "val.npz"), X=X_val, Y=Y_val)
    np.savez(os.path.join(args.out_dir, "test.npz"), X=X_te, Y=Y_te)

    print(f"Dataset: train={len(X_tr)} val={len(X_val)} test={len(X_te)} windows")
    print(f"X range: [{X_tr.min():.4f}, {X_tr.max():.4f}]  Y range: [{Y_tr.min():.4f}, {Y_tr.max():.4f}]")

#!/usr/bin/env python3
"""
FIGURE 13 (real) — RLS convergence trace built from the REAL residual series in
real_figures/convergence_trace.json, produced by scripts/verify_and_convergence.py
using the hardware-accurate numpy RLS model (gen_dataset.simulate_rls_hw) on the
canonical test signal (generator seed 42, signal 0).

This is an HONEST convergence figure: it plots the settling of the RLS residual
error power against the unfiltered interference power over the sample index, using
a sliding-window RMS. It is NOT a capture of the top-level Verilator testbench
(which emits zero output samples for the shipped stimulus); the RLS convergence
behaviour is instead reproduced from the same numpy model that yields the locked
5.0818 dB RLS-only figure.

If real_figures/verify_numbers.json contains a post-MLP residual power (i.e. torch
was available when verify_and_convergence.py ran), a horizontal reference line for
the post-MLP steady-state residual is drawn as well.
"""
import os, json
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

SCRIPTS = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(SCRIPTS)
RF = os.path.join(ROOT, "docs", "patent_package", "real_figures")

trace = json.load(open(os.path.join(RF, "convergence_trace.json")))
FS = 8000.0

# Prefer the ensemble-averaged per-sample power (mean over all 500 test signals),
# which shows the true RLS convergence transient rather than one non-representative
# realization. Fall back to the single-signal series if the ensemble is absent.
if "ensemble_rls_residual_msq" in trace:
    interf_msq = np.asarray(trace["ensemble_interference_msq"], dtype=np.float64)
    resid_msq = np.asarray(trace["ensemble_rls_residual_msq"], dtype=np.float64)
    n_sig = trace.get("ensemble_n_signals", "?")
    label_src = f"ensemble mean over {n_sig} test signals"
else:
    interf_msq = np.asarray(trace["interference"], dtype=np.float64) ** 2
    resid_msq = np.asarray(trace["rls_residual"], dtype=np.float64) ** 2
    label_src = "canonical test signal (seed 42)"

n = len(resid_msq)
t_ms = np.arange(n) / FS * 1000.0

# Light smoothing of the ensemble power curves (25 ms window).
W = 200
def smooth(x, w):
    csum = np.concatenate([[0.0], np.cumsum(x)])
    out = np.empty(len(x))
    for i in range(len(x)):
        a = max(0, i - w + 1)
        out[i] = (csum[i + 1] - csum[a]) / (i + 1 - a)
    return out

ref = np.mean(interf_msq) + 1e-12
interf_db = 10 * np.log10(smooth(interf_msq, W) / ref + 1e-12)
resid_db = 10 * np.log10(smooth(resid_msq, W) / ref + 1e-12)

# steady-state RLS suppression over the last 60% of the trace
tail = slice(int(0.4 * n), n)
rls_supp = 10 * np.log10(np.mean(interf_msq[tail]) / (np.mean(resid_msq[tail]) + 1e-12))
print(f"steady-state RLS suppression ({label_src}) ~ {rls_supp:.2f} dB")

# optional post-MLP steady-state line
post_mlp_db = None
vn_path = os.path.join(RF, "verify_numbers.json")
if os.path.exists(vn_path):
    vn = json.load(open(vn_path))
    if vn.get("post_mlp_residual_power") and vn.get("unfiltered_interference_power"):
        post_mlp_db = 10 * np.log10(vn["post_mlp_residual_power"] /
                                    vn["unfiltered_interference_power"] + 1e-12)

plt.rcParams.update({"font.family": "sans-serif", "font.size": 10})
fig, ax = plt.subplots(figsize=(8, 4))
ax.plot(t_ms, interf_db, color="0.6", linewidth=1.0, label="Unfiltered interference (0 dB ref.)")
ax.plot(t_ms, resid_db, "k-", linewidth=1.3, label="RLS residual error power")
ax.axhline(-rls_supp, color="black", linestyle="--", linewidth=1,
           label=f"RLS steady-state ≈ -{rls_supp:.1f} dB")
if post_mlp_db is not None:
    ax.axhline(post_mlp_db, color="black", linestyle="-.", linewidth=1,
               label=f"post-MLP steady-state ≈ {post_mlp_db:.1f} dB")
ax.set_xlabel("Time (ms)")
ax.set_ylabel("Residual power relative to interference (dB)")
ax.set_title("Fig. 13 — RLS residual-error convergence\n"
             f"(hardware-accurate numpy RLS model, {label_src}) — see verification note")
ax.legend(fontsize=7.5, framealpha=1, edgecolor="black", loc="upper right")
ax.grid(True, linestyle=":", color="gray", alpha=0.5)
ax.set_xlim([0, t_ms[-1]])
plt.tight_layout()
out = os.path.join(RF, "fig13_convergence_real.png")
plt.savefig(out, dpi=300, bbox_inches="tight")
print("saved", out)

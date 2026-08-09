#!/usr/bin/env python3
"""
FIGURE 12 (honest) — measured end-of-training metrics for the fixed-point neural
stage, replacing the previous synthetic SNR-vs-epoch curve.

The original scripts/plot_training.py produced an SNR-vs-epoch plot only by falling
back to a synthetic random-walk when models/training_loss_curve.npy was absent — the
per-epoch SNR history was NOT retained. Rather than draw a fabricated curve, this
figure reports the actual retained end-of-training metrics from models/train_metrics.json
and states plainly that no per-epoch history exists.

Values are read verbatim from models/train_metrics.json (not hard-coded).
"""
import os, json
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

SCRIPTS = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(SCRIPTS)
m = json.load(open(os.path.join(ROOT, "models", "train_metrics.json")))

snr = m["test_snr"]
enob = m["test_enob"]
mse = m["test_mse"]
epochs = m.get("epochs_trained", "?")
best_epoch = m.get("best_epoch", "?")

plt.rcParams.update({"font.family": "sans-serif", "font.size": 10})
fig, (axb, axt) = plt.subplots(1, 2, figsize=(9, 4), gridspec_kw={"width_ratios": [1.15, 1]})

# Left: measured metric bars (untrained baseline vs trained endpoint).
labels = ["Test SNR\n(dB)", "Test ENOB\n(bits)"]
baseline = [0.0, 0.0]
trained = [snr, enob]
x = np.arange(len(labels))
w = 0.38
axb.bar(x - w / 2, baseline, w, color="0.8", edgecolor="black", label="Untrained baseline")
axb.bar(x + w / 2, trained, w, color="0.35", edgecolor="black", label="Trained (measured)")
for xi, v in zip(x + w / 2, trained):
    axb.text(xi, v + 0.05, f"{v:.2f}", ha="center", va="bottom", fontsize=9, fontweight="bold")
axb.set_xticks(x); axb.set_xticklabels(labels)
axb.set_ylabel("Measured value")
axb.set_ylim([0, max(trained) * 1.25])
axb.legend(fontsize=8, framealpha=1, edgecolor="black", loc="upper right")
axb.set_title("Measured end-of-training metrics")
axb.grid(True, axis="y", linestyle=":", color="gray", alpha=0.5)

# Right: text panel of the retained record + honest note.
axt.axis("off")
lines = [
    "Neural stage — retained metrics",
    "(models/train_metrics.json)",
    "",
    f"  Test SNR (incremental) : {snr:.4f} dB",
    f"  Test ENOB              : {enob:.4f} bits",
    f"  Test MSE               : {mse:.6f}",
    f"  Epochs trained         : {epochs}  (best @ {best_epoch})",
    "",
    "Note: per-epoch SNR history was not",
    "retained during training, so no SNR-vs-",
    "epoch curve is shown. Only the measured",
    "end-of-training metrics above are plotted;",
    "no interpolated or synthetic curve is used.",
]
axt.text(0.0, 0.98, lines[0], fontsize=11, fontweight="bold", va="top", transform=axt.transAxes)
axt.text(0.0, 0.90, lines[1], fontsize=8, style="italic", va="top", transform=axt.transAxes)
axt.text(0.02, 0.80, "\n".join(lines[3:7]), fontsize=9.5, family="monospace",
         va="top", transform=axt.transAxes)
axt.text(0.0, 0.40, "\n".join(lines[8:]), fontsize=8.5, va="top", transform=axt.transAxes,
         bbox=dict(boxstyle="round", facecolor="0.95", edgecolor="black"))

fig.suptitle("Fig. 12 — Fixed-point neural-stage measured metrics (honest record)",
             fontsize=12)
plt.tight_layout(rect=[0, 0, 1, 0.96])
out = os.path.join(ROOT, "docs", "patent_package", "real_figures", "fig12_metrics_real.png")
plt.savefig(out, dpi=300, bbox_inches="tight")
print("saved", out, f"(SNR={snr:.4f} dB, ENOB={enob:.4f})")

#!/usr/bin/env python3
"""
FIGURE 8 (real) — CBPF frequency response computed from the ACTUAL quantized
Q1.15 coefficients as implemented in rtl/cbpf_2sos.v (not the ideal float design).

Coefficients are read directly from the RTL localparams so the plot reflects the
as-built filter, including quantization and the A1_S1 clamp to 0.99997.
"""
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from scipy.signal import freqz

Q = 32768.0  # Q1.15 scale
FS = 8000.0

# --- Exact integer coefficients from rtl/cbpf_2sos.v (localparams) ---
# Section 1
B0_S1, B1_S1, B2_S1 =  687,  1374,  687
A1_S1, A2_S1        =  32767, -15792
# Section 2
B0_S2, B1_S2, B2_S2 =  16384, -32768, 16384
A1_S2, A2_S2        =  29000, -13663

# DFII-T recursion in RTL: w0 = x + (A1*w1 + A2*w2)>>15 ; y = (B0*w0+B1*w1+B2*w2)>>15
# => H(z) = (b0 + b1 z^-1 + b2 z^-2) / (1 - a1 z^-1 - a2 z^-2)  with stored (negated) a's.
def section(b0, b1, b2, a1, a2):
    b = np.array([b0, b1, b2]) / Q
    a = np.array([1.0, -a1 / Q, -a2 / Q])  # denominator 1 - a1 z^-1 - a2 z^-2
    return b, a

b1, a1 = section(B0_S1, B1_S1, B2_S1, A1_S1, A2_S1)
b2, a2 = section(B0_S2, B1_S2, B2_S2, A1_S2, A2_S2)

w, h1 = freqz(b1, a1, worN=8192, fs=FS)
_, h2 = freqz(b2, a2, worN=8192, fs=FS)
h = h1 * h2

mag = 20 * np.log10(np.abs(h) + 1e-12)
# Normalise to passband peak so the shape (not the intentional CBPF attenuation
# that the RLS stage compensates) is what is read off the axis.
mag_norm = mag - mag.max()

# Report the realised -3 dB edges
peak_i = np.argmax(mag)
def edge(lo, hi):
    band = (w >= lo) & (w <= hi)
    return w[band][np.argmin(np.abs(mag_norm[band] + 3.0))]
f_lo = edge(50, w[peak_i]); f_hi = edge(w[peak_i], 3000)
f_pk = w[peak_i]
print(f"realised peak at {f_pk:.1f} Hz, -3 dB edges ~ {f_lo:.0f} / {f_hi:.0f} Hz")

plt.rcParams.update({"font.family": "sans-serif", "font.size": 10})
fig, ax = plt.subplots(figsize=(8, 4))
ax.plot(w, mag_norm, "k-", linewidth=1.6, label=f"As-built response (peak {f_pk:.0f} Hz)")
ax.axvspan(300, 800, color="0.85", label="300–800 Hz design target")
ax.axvline(f_pk, color="black", linestyle="-.", linewidth=1,
           label=f"realised peak {f_pk:.0f} Hz")
ax.axhline(-3, color="black", linestyle=":", linewidth=0.9, label="-3 dB")
ax.set_xlim([0, 4000]); ax.set_ylim([-80, 3])
ax.set_xlabel("Frequency (Hz)"); ax.set_ylabel("Normalised magnitude (dB)")
ax.set_title("Fig. 8 — CBPF as-built response from Q1.15 RTL coefficients\n"
             "(realised passband does NOT meet the 300–800 Hz design target — see note)")
ax.legend(fontsize=7.5, framealpha=1, edgecolor="black", loc="lower center")
ax.grid(True, linestyle=":", color="gray", alpha=0.5)
plt.tight_layout()
out = "docs/patent_package/real_figures/fig8_cbpf_response_real.png"
plt.savefig(out, dpi=300, bbox_inches="tight")
print("saved", out)

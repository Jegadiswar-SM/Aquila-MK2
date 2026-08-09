#!/usr/bin/env python3
"""
CBPF Coefficient Computation
4th-order Butterworth bandpass 300-800 Hz @ Fs=8 kHz
Implements scipy.signal.butter, then quantises to Q1.15 with
per-section scaling to fit [-1, +1).

Output: Q1.15 hex values for cbpf_2sos.v localparam ROM.

Run: python3 coeff_cbpf.py
"""
# SPDX-License-Identifier: Apache-2.0

import numpy as np

def sos2q15(sos_row, scale=1.0):
    """Convert one SOS row (b0,b1,b2,a0,a1,a2) to Q1.15 integers.
    a0 is always 1.0; we negate a1,a2 for DFII-T adds.
    """
    b = sos_row[:3] * scale
    # a1,a2 are stored as positive in scipy convention;
    # we negate for DFII-T: y = b0*x + b1*z1 + b2*z2 + a1*z1 + a2*z2
    a1 = -sos_row[4] * scale
    a2 = -sos_row[5] * scale

    def to_q15(x):
        # Clamp to [-1, 1-2^-15]
        x = max(-1.0, min(1.0 - 2**-15, x))
        return int(round(x * 2**15))

    b0 = to_q15(b[0])
    b1 = to_q15(b[1])
    b2 = to_q15(b[2])
    a1_q = to_q15(a1)
    a2_q = to_q15(a2)
    return b0, b1, b2, a1_q, a2_q

def main():
    from scipy.signal import butter
    sos = butter(2, [300, 800], btype='bandpass', fs=8000, output='sos')
    print("=== CBPF SOS Coefficients (4th-order Butterworth, 300-800 Hz @ 8 kHz) ===")
    print(f"sos array:\n{sos}\n")

    # Per-section scaling so all coefficients fit Q1.15
    scales = [0.70009, 0.50000]

    for i, (row, sc) in enumerate(zip(sos, scales)):
        b0, b1, b2, a1_q, a2_q = sos2q15(row, scale=sc)
        raw_b = row[:3]
        raw_a1 = -row[4]
        raw_a2 = -row[5]
        print(f"\n--- Section {i+1} (scale={sc}) ---")
        print(f"  Raw b = {raw_b}  a1={raw_a1}  a2={raw_a2}")
        print(f"  B0 = {b0:7d}  0x{b0:04X}  (Q1.15)")
        print(f"  B1 = {b1:7d}  0x{b1:04X}  (Q1.15)")
        print(f"  B2 = {b2:7d}  0x{b2:04X}  (Q1.15)")
        print(f"  A1 = {a1_q:7d}  0x{a1_q:04X}  (Q1.15, negated for DFII-T)")
        print(f"  A2 = {a2_q:7d}  0x{a2_q:04X}  (Q1.15, negated for DFII-T)")

    # Combined gain
    gain = sos[0, :3].sum() / sos[0, 4:].sum() * sos[1, :3].sum() / sos[1, 4:].sum()
    print(f"\n  Combined DC gain (theoretical): {gain:.6f}")
    print(f"  Combined with scaling: {gain * scales[0] * scales[1]:.6f}")
    print(f"  RLS adaptive filter will compensate for gain.")

if __name__ == '__main__':
    main()

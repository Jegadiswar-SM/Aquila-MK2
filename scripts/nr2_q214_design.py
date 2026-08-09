"""
NR2 Fixed-Point Design: Q2.14 format.
Root-cause: 16'sh4000 = 0.5 in Q1.15, but formula needs 2.0 (unrepresentable).
Fix: LUT and intermediate x held in Q2.14; downstream rescale to Q1.15.

Q2.14: 2 integer bits, 14 fractional bits, signed 16-bit total.
Range: [-2.0, 1.99994],  Resolution: 2^-14 ≈ 6.1e-5
"""
import numpy as np

FRAC_Q115 = 15  # Q1.15 fraction bits
FRAC_Q214 = 14  # Q2.14 fraction bits
N_LUT = 32      # must match RTL: indexed by d_norm[14:10]

def to_q214(val):
    """Convert float to Q2.14 integer (saturate)."""
    max_val = 32767 / 16384.0  # ~1.99994
    min_val = -32768 / 16384.0  # -2.0
    clipped = np.clip(val, min_val, max_val)
    return int(np.round(clipped * 16384))

def from_q214(i):
    """Convert Q2.14 integer back to float."""
    return i / 16384.0

def to_q115(val):
    """Convert float to Q1.15 integer (saturate to 0..0.99997)."""
    clipped = np.clip(val, 0, 32767/32768.0)
    return int(np.round(clipped * 32768))

def from_q115(i):
    return i / 32768.0

def compute_lut(verbose=True):
    """Compute 32-entry LUT for initial reciprocal estimate in Q2.14.
    For D in [0, 1.0), divide into 32 equal segments.
    LUT entry = 2 - D_mid (range ~[1.0, 2.0]), stored in Q2.14.
    """
    lut = []
    print(f"N_LUT = {N_LUT}")
    for idx in range(N_LUT):
        d_low  = idx / N_LUT
        d_high = (idx + 1) / N_LUT
        d_mid  = (d_low + d_high) / 2.0
        ideal  = 2.0 - d_mid   # NR initial guess (range [2.0-1.0))
        lut_val = to_q214(ideal)
        lut_float = from_q214(lut_val)
        if verbose:
            print(f"  [{idx:2d}] D∈[{d_low:.4f},{d_high:.4f}) mid={d_mid:.5f}  "
                  f"2-D_mid={ideal:.6f} → Q2.14=0x{lut_val:04X} ({lut_float:.6f})")
        lut.append(lut_val)
    return lut

def nr2_q214(d_float, lut, verbose=False):
    """Two-stage Newton-Raphson reciprocal in Q2.14 format.
    Args:
        d_float: D value in [0, 1.0)
        lut: Q2.14 LUT values
    Returns:
        recip_float: final reciprocal
        intermediates: dict of debug info
    """
    d_q115 = to_q115(d_float)
    d_fx = from_q115(d_q115)

    # LUT address: index by d_norm[14:10] (5 bits for 32 entries)
    lut_idx = (d_q115 >> 10) & 0x1F  # bits [14:10]
    x0_int = lut[lut_idx]
    x0 = from_q214(x0_int)

    # Stage 1: residual1 = 2 - D * x0
    DX0 = d_q115 * x0_int  # Q1.15 * Q2.14 = Q3.29
    DX0_q214 = DX0 >> FRAC_Q115  # >> 15 → Q2.14 (floor divide)
    DX0_float = from_q214(DX0_q214)
    TWO_Q214 = 0x7FFF  # 1.99994 in Q2.14
    residual1_int = TWO_Q214 - DX0_q214  # Q2.14
    residual1 = from_q214(residual1_int)

    # x1 = x0 * residual1
    prod1 = x0_int * residual1_int  # Q2.14 * Q2.14 = Q4.28
    x1_int = prod1 >> FRAC_Q214  # >> 14 → Q2.14
    x1 = from_q214(x1_int)

    # Stage 2: residual2 = 2 - D * x1
    DX1 = d_q115 * x1_int  # Q1.15 * Q2.14 = Q3.29
    DX1_q214 = DX1 >> FRAC_Q115  # → Q2.14
    residual2_int = TWO_Q214 - DX1_q214
    residual2 = from_q214(residual2_int)

    # x2 = x1 * residual2
    prod2 = x1_int * residual2_int  # Q4.28
    x2_int = prod2 >> FRAC_Q214  # → Q2.14
    x2 = from_q214(x2_int)

    # Rescale from Q2.14 to Q1.15: shift right by 1 (divide by 2)
    x2_q115_int = x2_int >> 1  # Q2.14 → Q1.15
    x2_q115 = from_q115(x2_q115_int)

    true_recip = 1.0 / d_fx if d_fx != 0 else 1.0
    nr_error = abs(x2 - true_recip)

    if verbose:
        print(f"\nD={d_float:.6f} (q115=0x{d_q115:04X}, fx={d_fx:.6f})")
        print(f"  LUT idx={lut_idx} x0=0x{x0_int:04X} ({x0:.6f})")
        print(f"  DX0=0x{DX0:08X}→0x{DX0_q214:04X} ({DX0_float:.6f})")
        print(f"  residual1=0x{residual1_int:04X} ({residual1:.6f})")
        print(f"  x1=0x{x1_int:04X} ({x1:.6f})")
        print(f"  DX1=0x{DX1:08X}→0x{DX1_q214:04X}")
        print(f"  residual2=0x{residual2_int:04X} ({residual2:.6f})")
        print(f"  x2=0x{x2_int:04X} ({x2:.6f})")
        print(f"  x2_q115=0x{x2_q115_int:04X} ({x2_q115:.6f})")
        print(f"  true 1/D={true_recip:.6f}  error={nr_error:.6f}")

    return x2, {
        'd_q115': d_q115,
        'x0': x0, 'x0_int': x0_int,
        'x1': x1, 'x1_int': x1_int,
        'x2': x2, 'x2_int': x2_int,
        'r1_int': residual1_int, 'r1': residual1,
        'r2_int': residual2_int, 'r2': residual2,
        'nr_error': nr_error, 'true_recip': true_recip,
    }


def main():
    print("=" * 72)
    print("NR2 Q2.14 Design Verification")
    print("=" * 72)

    # ---- LUT ----
    print("\n--- LUT (Q2.14) ---")
    lut = compute_lut(verbose=True)

    # ---- Single-point test ----
    print("\n--- Single-point test: D = 0.75 ---")
    x2, _ = nr2_q214(0.75, lut, verbose=True)
    print(f"  Final Q2.14 reciprocal = {x2:.6f}")

    #     # ---- Sweep test: realistic D range (≥0.5) ----
    print("\n--- Sweep: 200 points across [0.5, 0.999) ---")
    errors = []
    for d in np.linspace(0.5, 0.999, 200):
        x2, info = nr2_q214(d, lut)
        errors.append(info['nr_error'])
    max_err = max(errors)
    mean_err = float(np.mean(errors))
    print(f"\n  Max error (Q2.14 domain): {max_err:.6f}")
    print(f"  Mean error: {mean_err:.6f}")
    if max_err < 0.01:
        print("  ✓ PASS: max error < 0.01")
    else:
        print(f"  ✗ FAIL: max error {max_err:.6f} >= 0.01")

    # ---- Golden values for RTL testbench ----
    print("\n--- Golden NR2 values for RTL testbench ---")
    test_vectors = [
        ("lambda=0x5000 (D=0.625)", 0x5000),
        ("lambda=0x4000 (D=0.5)",   0x4000),
        ("lambda=0x6000 (D=0.75)",  0x6000),
        ("lambda=0x7F00 (D≈0.992)", 0x7F00),
        ("lambda=0x7FFF (D≈1.0)",   0x7FFF),
    ]
    for label, d_q115 in test_vectors:
        d_float = from_q115(d_q115)
        x2, info = nr2_q214(d_float, lut)
        print(f"  {label}: D_q115=0x{d_q115:04X} x2_int=0x{info['x2_int']:04X} "
              f"x2={x2:.6f} err={info['nr_error']:.6f}")
        # Also print all intermediates for RTL comparison
        print(f"    d_norm=0x{d_q115:04X} x0=0x{info['x0_int']:04X} "
              f"residual1=0x{info['r1_int']:04X} nr_x1=0x{info['x1_int']:04X} "
              f"residual2=0x{info['r2_int']:04X}")

if __name__ == '__main__':
    main()

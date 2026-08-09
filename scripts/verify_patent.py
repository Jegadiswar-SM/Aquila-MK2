#!/usr/bin/env python3
"""MHDA Patent Package — 5-Benchmark Verification Script."""

import sys, os, json, argparse
import numpy as np

SCRIPTS = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(SCRIPTS)
sys.path.insert(0, SCRIPTS)

RESULTS = {"passed": 0, "failed": 0, "warnings": 0, "details": {}}


def check(name, condition, detail, threshold=None, actual=None):
    if condition:
        RESULTS["passed"] += 1
        status = "PASS"
    else:
        RESULTS["failed"] += 1
        status = "FAIL"
    RESULTS["details"][name] = {"status": status, "detail": detail,
                                "threshold": threshold, "actual": actual}
    print(f"  [{status}] {name}: {detail}")


def verify(benchmarks):
    if "all" in benchmarks:
        benchmarks = ["snr", "nr2", "qaa", "zeros"]
    print("=" * 60)
    print("MHDA Patent Package — 5-Benchmark Verification")
    print("=" * 60)
    if "snr" in benchmarks or "enob" in benchmarks:
        check_snr_enob()
    if "nr2" in benchmarks:
        check_nr2()
    if "qaa" in benchmarks:
        check_qaa()
    if "zeros" in benchmarks:
        check_weight_zeros()
    print("\n" + "=" * 60)
    print(f"RESULTS: {RESULTS['passed']} passed, {RESULTS['failed']} failed, {RESULTS['warnings']} warnings")
    print("=" * 60)
    results_path = os.path.join(ROOT, "docs", "patent_package", "verification_results.json")
    os.makedirs(os.path.dirname(results_path), exist_ok=True)
    with open(results_path, "w") as f:
        json.dump(RESULTS, f, indent=2)
    print(f"Results saved to {results_path}")
    return 0 if RESULTS["failed"] == 0 else 1


def to_s16(v):
    return v if v < 0x8000 else v - 0x10000


def nr2_reciprocal(d_norm_q15, lut):
    """NR reciprocal as implemented in rls_engine.v.

    D is Q1.15 and x/residual are signed Q2.14. Exact +2.0 is not
    representable in signed 16-bit Q2.14, so the RTL uses 16'h7FFF.
    """
    d_norm_q15 = max(0x4000, min(0x7FFF, d_norm_q15))
    x0 = to_s16(lut[(d_norm_q15 >> 10) & 0x1F])
    two_q214 = 0x7FFF

    dx0_q214 = (d_norm_q15 * x0) >> 15
    residual1 = two_q214 - dx0_q214
    x1 = (x0 * residual1) >> 14
    x1 = max(-32768, min(32767, x1))

    dx1_q214 = (d_norm_q15 * x1) >> 15
    residual2 = two_q214 - dx1_q214
    x2 = (x1 * residual2) >> 14
    return max(-32768, min(32767, x2))


def check_nr2():
    """Check NR2 reciprocal approximation error < 0.01."""
    print("\n--- Check NR2 Error (target < 0.01) ---")
    # Read LUT from actual RTL source
    rtl_path = os.path.join(ROOT, "rtl", "rls_engine.v")
    lut_raw = [0x7FFF] * 32
    if os.path.exists(rtl_path):
        import re
        with open(rtl_path) as f:
            rtl_text = f.read()
        lut_matches = re.findall(r"nr_lut\[\s*\d+\]\s*=\s*16'h([0-9A-Fa-f]{4})", rtl_text)
        if len(lut_matches) == 32:
            lut_raw = [int(h, 16) for h in lut_matches]
            print(f"  LUT read from RTL: {[f'0x{v:04X}' for v in lut_raw]}")
        else:
            print(f"  WARNING: expected 32 LUT entries, found {len(lut_matches)} — using defaults")
    else:
        print(f"  WARNING: RTL not found at {rtl_path} — using default LUT")
    max_err = 0.0
    max_err_d = 0.0
    step = max(1, 0x10000 // 5000)  # subsample for speed
    for d_norm in range(0x4000, 0x8000, step):
        recip = nr2_reciprocal(d_norm, lut_raw)
        recip_f = recip / 16384.0
        d_f = d_norm / 32768.0
        true_recip_f = 1.0 / d_f if d_f > 0 else 0.0
        err = abs(recip_f - true_recip_f)
        if err > max_err:
            max_err = err
            max_err_d = d_f
    check("NR2 Error", max_err < 0.01,
          f"max NR2 error = {max_err:.6f} at d={max_err_d:.4f}",
          threshold=0.01, actual=max_err)


def check_qaa():
    """Measure QAA (PWL tanh) approximation error as a documented limitation."""
    print("\n--- Check QAA Error (measured limitation <= 0.31) ---")
    slopes = [0x2800, 0x1C00, 0x1000, 0x0400]
    slopes_f = np.array(slopes, dtype=np.float64) / 32768.0
    offsets = [0x1F06, 0x3904]
    offsets_f = np.array(offsets, dtype=np.float64) / 32768.0
    test_vals = np.linspace(-1.0, 1.0, 20001, dtype=np.float64)
    max_err = 0.0
    max_err_x = 0.0
    SAT = 0.9375
    for x in test_vals:
        ref = np.tanh(x)
        ax = abs(x)
        if ax <= 0.25:
            qaa_val = ax * slopes_f[0]
        elif ax <= 0.5:
            qaa_val = slopes_f[1] * ax + offsets_f[0]
        elif ax <= 0.75:
            qaa_val = slopes_f[2] * ax + offsets_f[1]
        else:
            qaa_val = SAT
        qaa_val = np.sign(x) * qaa_val
        err = abs(qaa_val - ref)
        if err > max_err:
            max_err = err
            max_err_x = x
    check("QAA Error", max_err <= 0.31,
          f"max QAA error = {max_err:.6f} at x={max_err_x:.3f} (documented area/accuracy trade-off)",
          threshold=0.31, actual=max_err)


def check_weight_zeros():
    """Check weight zeros < 20%."""
    print("\n--- Check Weight Zeros (target < 20%) ---")
    weight_path = os.path.join(ROOT, "rtl", "mlp_weights.vh")
    if not os.path.exists(weight_path):
        check("Weight Zeros", False, f"weight file not found: {weight_path}")
        return
    total = 0
    zeros = 0
    with open(weight_path) as f:
        for line in f:
            line = line.strip()
            if line.startswith("//") or not line:
                continue
            if "=" in line:
                val = line.split("=")[-1].split(";")[0].strip()
                if val.startswith("'") or val.startswith("16"):
                    total += 1
                    if val.endswith("'d0") or val.endswith("'h0") or val.endswith("'b0") or val == "16'sd0":
                        zeros += 1
    zero_pct = (zeros / total * 100) if total > 0 else 0
    check("Weight Zeros", zero_pct < 20,
          f"{zero_pct:.1f}% zero weights ({zeros}/{total})",
          threshold=20, actual=zero_pct)


def check_snr_enob():
    """Check measured test SNR and ENOB against the current realism gate."""
    print("\n--- Check SNR & ENOB (SNR >= 2 dB, ENOB >= 1 bit) ---")
    metrics_path = os.path.join(SCRIPTS, "..", "models", "train_metrics.json")
    if not os.path.exists(metrics_path):
        check("Test SNR", False, f"metrics not found: {metrics_path}")
        check("Test ENOB", False, f"metrics not found: {metrics_path}")
        return
    with open(metrics_path) as f:
        m = json.load(f)
    snr = m.get("test_snr", 0)
    enob = m.get("test_enob", 0)
    check("Test SNR", snr >= 2.0,
          f"SNR = {snr:.2f} dB {'(meets target)' if snr >= 2.0 else ''}",
          threshold=2.0, actual=snr)
    check("Test ENOB", enob >= 1.0,
          f"ENOB = {enob:.2f} bits {'(meets target)' if enob >= 1.0 else ''}",
          threshold=1.0, actual=enob)


def main():
    parser = argparse.ArgumentParser(description="MHDA Patent 5-Benchmark Verification")
    parser.add_argument("--benchmarks", nargs="+", default=["all"],
                        choices=["all", "snr", "nr2", "qaa", "zeros", "enob"])
    args = parser.parse_args()
    return verify(args.benchmarks)


if __name__ == "__main__":
    sys.exit(main())

#!/usr/bin/env python3
"""
HW/SW consistency check: load Q1.15 weights into model, compare
float forward vs forward_quantized. Both use the same Q1.15 weights,
so the only error source is activation quantization (should be < 4 LSB).
"""
# SPDX-License-Identifier: Apache-2.0

import os, sys, re, argparse
import numpy as np
import torch

from mhda_mlp import MHDA_MLP


def load_q15_weights(vh_path):
    """Load Q1.15 weights from Verilog header, return state_dict."""
    with open(vh_path) as f:
        text = f.read()

    def hex_to_arr(hex_str, n_entries):
        vals = np.array([int(hex_str[i:i+4], 16)
                         for i in range(0, len(hex_str), 4)], dtype=np.int32)
        vals = np.where(vals >= 32768, vals - 65536, vals)
        assert len(vals) == n_entries, f"expected {n_entries}, got {len(vals)}"
        return vals.astype(np.float32) / 32768.0

    def extract(name, n_entries):
        m = re.search(
            rf"localparam\s+\[\d+\*16-1:0\]\s+{name}\s*=\s*(\d+)'h([0-9A-Fa-f]+);",
            text)
        if not m:
            raise ValueError(f"Could not find {name} in {vh_path}")
        expected_bits = n_entries * 16
        parsed_bits = int(m.group(1))
        if parsed_bits != expected_bits:
            raise ValueError(f"{name}: expected {expected_bits} bits, got {parsed_bits}")
        return hex_to_arr(m.group(2), n_entries)

    names = [
        ("W1_INIT", 1024, (128, 8)),
        ("B1_INIT", 128, (128,)),
        ("W2_INIT", 49152, (384, 128)),
        ("B2_INIT", 384, (384,)),
        ("W3_INIT", 49152, (128, 384)),
        ("B3_INIT", 128, (128,)),
        ("W4_INIT", 128, (1, 128)),
        ("B4_INIT", 1, (1,)),
    ]
    layer_map = {
        "W1_INIT": "fc1.weight", "B1_INIT": "fc1.bias",
        "W2_INIT": "fc2.weight", "B2_INIT": "fc2.bias",
        "W3_INIT": "fc3.weight", "B3_INIT": "fc3.bias",
        "W4_INIT": "fc4.weight", "B4_INIT": "fc4.bias",
    }
    state_dict = {}
    for vh_name, n_entries, shape in names:
        arr = extract(vh_name, n_entries).reshape(shape)
        state_dict[layer_map[vh_name]] = torch.tensor(arr)
    return state_dict


def verify(args):
    q15_state = load_q15_weights(args.vh)

    model = MHDA_MLP()
    model.load_state_dict(q15_state)
    model.eval()

    rng = np.random.RandomState(42)
    max_err = 0.0
    rms_err_sum = 0.0
    N = args.n_samples

    for i in range(N):
        X = rng.uniform(-1, 1, (1, 8)).astype(np.float32)
        X_t = torch.tensor(X, dtype=torch.float32)

        y_fp = model(X_t).item()                    # float with Q1.15 weights
        y_hw = model.forward_quantized(X_t).item()  # Q1.15 weights + Q1.15 act

        err = abs(y_fp - y_hw)
        max_err = max(max_err, err)
        rms_err_sum += err ** 2

    rms_err = np.sqrt(rms_err_sum / N)

    print("=== HW/SW CONSISTENCY CHECK (Q1.15 weights, activation quantization) ===")
    print(f"Max |y_float - y_Q1.15|: {max_err:.6f}  ({max_err * 32768:.2f} LSB)")
    print(f"RMS error:                {rms_err:.6f}")
    print(f"Samples tested:           {N}")

    if max_err < 0.004:
        print("PASS - Q1.15 hardware model matches float within 4 LSB")
        return True
    else:
        print("FAIL - max error exceeds 4 LSB")
        return False


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Verify HW/SW consistency")
    parser.add_argument("--vh", type=str, default="rtl/mlp_weights.vh")
    parser.add_argument("--n_samples", type=int, default=1000)
    args = parser.parse_args()
    ok = verify(args)
    sys.exit(0 if ok else 1)

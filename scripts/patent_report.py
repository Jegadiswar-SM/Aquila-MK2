#!/usr/bin/env python3
"""
Generate patent documentation report: docs/training_report.md
"""
# SPDX-License-Identifier: Apache-2.0

import os, json, argparse
import numpy as np
import torch

from mhda_mlp import MHDA_MLP


def generate_report(args):
    with open(os.path.join(args.model_dir, "train_metrics.json")) as f:
        metrics = json.load(f)

    model = MHDA_MLP()
    state = torch.load(os.path.join(args.model_dir, "best_mlp.pt"),
                       map_location="cpu")
    model.load_state_dict(state)

    param_counts = {
        "FC1": 8 * 128 + 128,
        "FC2": 128 * 384 + 384,
        "FC3": 384 * 128 + 128,
        "FC4": 128 * 1 + 1,
        "Total": model.count_params(),
    }

    # HW/SW consistency check results
    max_err_hw = args.max_err if args.max_err else "?"
    max_err_lsb = f"{float(max_err_hw) * 32768:.2f}" if args.max_err else "?"

    # Weight statistics from export
    from export_weights import quantize_to_q15
    weight_stats = {}
    for layer_name in ["fc1.weight", "fc1.bias", "fc2.weight", "fc2.bias", "fc3.weight", "fc3.bias", "fc4.weight", "fc4.bias"]:
        name_map = {
            "fc1.weight": "W1_INIT", "fc1.bias": "B1_INIT",
            "fc2.weight": "W2_INIT", "fc2.bias": "B2_INIT",
            "fc3.weight": "W3_INIT", "fc3.bias": "B3_INIT",
            "fc4.weight": "W4_INIT", "fc4.bias": "B4_INIT",
        }
        t = state[layer_name].numpy()
        t_q = quantize_to_q15(t)
        weight_stats[name_map[layer_name]] = {
            "min": int(t_q.min()),
            "max": int(t_q.max()),
            "zeros": int(np.sum(t_q == 0)),
            "saturation_pct": float(np.sum(np.abs(t_q) == 32767) / t_q.size * 100),
        }

    lines = []
    lines.append("# MLP Training Results — MHDA Rev 1.1")
    lines.append("")
    lines.append("## Model Architecture")
    lines.append("| Layer | In | Out | Activation | Params |")
    lines.append("|-------|----|-----|------------|--------|")
    lines.append(f"| FC1   | 8  | 128 | tanh       | {param_counts['FC1']}   |")
    lines.append(f"| FC2   | 128| 384 | tanh       | {param_counts['FC2']}  |")
    lines.append(f"| FC3   | 384| 128 | tanh       | {param_counts['FC3']}  |")
    lines.append(f"| FC4   | 128| 1   | linear     | {param_counts['FC4']}    |")
    lines.append(f"| Total |    |     |            | {param_counts['Total']}  |")
    lines.append("")
    lines.append("## Training Configuration")
    lines.append("- Optimizer: Adam, lr=0.001, weight_decay=1e-5")
    lines.append("- Loss: MSE (float32 training, Q1.15 quantized at export)")
    lines.append(f"- Epochs: {metrics.get('epochs_trained', '?')}")
    lines.append("- Dataset: 160k/20k/20k train/val/test windows")
    lines.append("- Interference types: tonal, coloured-noise, transient, mixed")
    lines.append("")
    lines.append("## Test Set Performance")
    lines.append("| Metric | Value |")
    lines.append("|--------|-------|")
    lines.append(f"| Test MSE | {metrics['test_mse']:.6f} |")
    lines.append(f"| Test SNR | {metrics['test_snr']:.2f} dB |")
    lines.append(f"| Test ENOB | {metrics['test_enob']:.2f} bits |")
    lines.append(f"| HW/SW max error | {max_err_hw} ({max_err_lsb} LSB) |")
    lines.append("")
    lines.append("## Q1.15 Weight Statistics")
    lines.append("| ROM | Elements | Min | Max | Zeros | Saturation % |")
    lines.append("|-----|----------|-----|-----|-------|--------------|")
    for name in ["W1_INIT", "B1_INIT", "W2_INIT", "B2_INIT", "W3_INIT", "B3_INIT", "W4_INIT", "B4_INIT"]:
        s = weight_stats[name]
        n = {
            "W1_INIT": 1024, "B1_INIT": 128, "W2_INIT": 49152,
            "B2_INIT": 384, "W3_INIT": 49152, "B3_INIT": 128,
            "W4_INIT": 128, "B4_INIT": 1,
        }[name]
        lines.append(f"| {name} | {n} | {s['min']} | {s['max']} | {s['zeros']} | {s['saturation_pct']:.2f}% |")
    lines.append("")
    lines.append("## Benchmark vs Untrained (zeros)")
    lines.append("| Metric | Untrained | Trained | Delta |")
    lines.append("|--------|-----------|---------|-------|")
    lines.append(f"| Test SNR | 0 dB | {metrics['test_snr']:.2f} dB | +{metrics['test_snr']:.2f} dB |")
    lines.append(f"| Test ENOB | 0 bits | {metrics['test_enob']:.2f} bits | +{metrics['test_enob']:.2f} |")
    lines.append("")

    os.makedirs("docs", exist_ok=True)
    out_path = "docs/training_report.md"
    with open(out_path, "w") as f:
        f.write("\n".join(lines) + "\n")
    print(f"Report written to {out_path}")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Generate patent training report")
    parser.add_argument("--model_dir", type=str, default="models")
    parser.add_argument("--max_err", type=float, default=None,
                        help="Max HW/SW error from verify step")
    args = parser.parse_args()
    generate_report(args)

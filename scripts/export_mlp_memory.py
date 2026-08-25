#!/usr/bin/env python3
"""Export an authoritative Aquila MLP checkpoint to the SRAM word image.

The exporter is deliberately strict: it rejects the repository's historical
8->64->32->1 checkpoint and any other shape mismatch before writing output.
It does not train, synthesize, or invent weights.

Output format: one 16-bit hexadecimal word per line, in ascending
``wload_addr`` order.  For each 256-bit row, lane 0 is emitted first, matching
``mlp_weight_sram_wrapper`` address ``wload_addr[3:0]``.
"""

from __future__ import annotations

import argparse
import hashlib
import json
import math
from pathlib import Path

import numpy as np
import torch

EXPECTED = {
    "fc1.weight": (128, 8),
    "fc1.bias": (128,),
    "fc2.weight": (384, 128),
    "fc2.bias": (384,),
    "fc3.weight": (128, 384),
    "fc3.bias": (128,),
    "fc4.weight": (1, 128),
    "fc4.bias": (1,),
}

ROWS = 8192
LANES = 16
USED_ROWS = 6257


def sha256_file(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as stream:
        for block in iter(lambda: stream.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def load_state(path: Path) -> dict:
    artifact = torch.load(path, map_location="cpu")
    if isinstance(artifact, dict) and "state_dict" in artifact:
        artifact = artifact["state_dict"]
    if not isinstance(artifact, dict):
        raise ValueError("checkpoint is not a state-dict mapping")
    return artifact


def validate_state(state: dict) -> None:
    actual = set(state)
    expected = set(EXPECTED)
    missing = sorted(expected - actual)
    extra = sorted(actual - expected)
    if missing or extra:
        raise ValueError(f"topology/key mismatch: missing={missing} extra={extra}")
    for name, shape in EXPECTED.items():
        value = state[name].detach().cpu().numpy()
        if tuple(value.shape) != shape:
            raise ValueError(
                f"topology mismatch for {name}: got {tuple(value.shape)}, expected {shape}"
            )
        if not np.isfinite(value).all():
            raise ValueError(f"non-finite value in {name}")


def q15(value: float) -> int:
    # Match scripts/export_weights.py: round-to-nearest (NumPy ties-to-even)
    # followed by signed Q1.15 saturation.
    quantized = int(np.rint(float(value) * 32768.0))
    return max(-32768, min(32767, quantized))


def quantized_state(state: dict) -> dict[str, np.ndarray]:
    return {
        name: np.asarray(
            [[q15(x) for x in row] for row in value.detach().cpu().numpy()]
            if value.detach().cpu().numpy().ndim == 2
            else [q15(x) for x in value.detach().cpu().numpy()],
            dtype=np.int16,
        )
        for name, value in state.items()
    }


def make_image(q: dict[str, np.ndarray]) -> np.ndarray:
    image = np.zeros((ROWS, LANES), dtype=np.int16)

    w1 = q["fc1.weight"]
    for node in range(128):
        image[node // 2, (node % 2) * 8:(node % 2 + 1) * 8] = w1[node]
    image[64:72, :] = q["fc1.bias"].reshape(8, 16)

    w2 = q["fc2.weight"]
    for node in range(384):
        for step in range(8):
            image[72 + node * 8 + step, :] = w2[node, step * 16:(step + 1) * 16]
    image[3144:3168, :] = q["fc2.bias"].reshape(24, 16)

    w3 = q["fc3.weight"]
    for node in range(128):
        for step in range(24):
            image[3168 + node * 24 + step, :] = w3[node, step * 16:(step + 1) * 16]
    image[6240:6248, :] = q["fc3.bias"].reshape(8, 16)

    image[6248:6256, :] = q["fc4.weight"].reshape(8, 16)
    image[6256, 0] = q["fc4.bias"][0]
    return image


def write_image(image: np.ndarray, path: Path) -> None:
    with path.open("w", encoding="ascii") as stream:
        for row in image:
            for value in row:
                stream.write(f"{int(value) & 0xFFFF:04X}\n")


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--model", required=True, type=Path)
    parser.add_argument("--out", required=True, type=Path)
    parser.add_argument("--manifest", required=True, type=Path)
    args = parser.parse_args()

    state = load_state(args.model)
    validate_state(state)
    q = quantized_state(state)
    image = make_image(q)
    args.out.parent.mkdir(parents=True, exist_ok=True)
    args.manifest.parent.mkdir(parents=True, exist_ok=True)
    write_image(image, args.out)

    manifest = {
        "format_version": 1,
        "topology": [8, 128, 384, 128, 1],
        "parameter_count": 100097,
        "source_model": str(args.model),
        "source_sha256": sha256_file(args.model),
        "quantization": "signed Q1.15; round(value*32768), ties-to-even, clamp [-32768,32767]",
        "memory_format": "131072 lines of 16-bit hex words; row*16+lane address order",
        "rows": ROWS,
        "lanes_per_row": LANES,
        "used_rows": USED_ROWS,
        "layer_row_ranges": {
            "W1": [0, 63], "B1": [64, 71], "W2": [72, 3143],
            "B2": [3144, 3167], "W3": [3168, 6239], "B3": [6240, 6247],
            "W4": [6248, 6255], "B4": [6256, 6256],
        },
        "image_sha256": sha256_file(args.out),
    }
    args.manifest.write_text(json.dumps(manifest, indent=2) + "\n", encoding="utf-8")
    print(json.dumps(manifest, indent=2))


if __name__ == "__main__":
    main()

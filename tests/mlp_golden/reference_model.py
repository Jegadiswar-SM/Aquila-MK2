"""Bit-level software reference for the executable mlp_inference RTL.

This module intentionally uses Python integer arithmetic and the RTL's
explicit row/lane map. It does not provide weights; callers must supply the
authorized 131072-word image.
"""

from pathlib import Path


def signed(value: int, bits: int) -> int:
    value &= (1 << bits) - 1
    return value - (1 << bits) if value & (1 << (bits - 1)) else value


def qaa_tanh(x: int) -> int:
    x = signed(x, 16)
    abs_x = signed((~x + 1) if x < 0 else x, 16)
    abs_u = abs_x & 0xFFFF
    if abs_u <= 8192:
        # The executable RTL operands are 16-bit signed values. The
        # multiplication therefore has 16-bit expression width before >>>.
        product = signed(signed(abs_x, 16) * signed(0x7C00, 16), 16)
        y_mag = signed(product >> 15, 16)
    elif abs_u <= 16384:
        # The mixed signed/unsigned 16-bit expression is modeled as compiled.
        delta = (abs_u - 8192) & 0xFFFF
        product = (delta * 0x6800) & 0xFFFF
        y_mag = signed((0x1F06 + (product >> 15)) & 0xFFFF, 16)
    elif abs_u <= 24576:
        delta = (abs_u - 16384) & 0xFFFF
        product = (delta * 0x3800) & 0xFFFF
        y_mag = signed((0x3904 + (product >> 15)) & 0xFFFF, 16)
    else:
        y_mag = 0x7800
    return signed((~y_mag + 1) if x < 0 else y_mag, 16)


def load_word_image(path: Path) -> list[int]:
    words = [int(line.strip(), 16) for line in path.read_text().splitlines() if line.strip()]
    if len(words) != 8192 * 16:
        raise ValueError(f"expected 131072 words, got {len(words)}")
    return [signed(word, 16) for word in words]


def row(image: list[int], address: int) -> list[int]:
    return image[address * 16:(address + 1) * 16]


def infer(image: list[int], features: list[int]) -> int:
    if len(features) != 8:
        raise ValueError("expected eight signed 16-bit features")
    activations = [signed(x, 16) for x in features]

    # Exact executable RTL row map.  Bias rows precede each layer's weight
    # region as implemented by mlp_inference.v; this is deliberately not a
    # reconstruction from the stale historical mlp_weights.vh artifact.
    layer_specs = ((128, 8, 64, 0, True),
                   (384, 128, 3144, 72, False),
                   (128, 384, 6240, 3168, False),
                   (1, 128, 6256, 6248, False))
    for layer, (nodes, inputs, bias_base, weight_base, first_layer) in enumerate(layer_specs):
        next_values = []
        for node in range(nodes):
            bias_row = row(image, bias_base + node // 16)
            acc = signed(bias_row[node % 16] << 16, 40)
            if first_layer:
                weights = row(image, node // 2)[0 if node % 2 == 0 else 8:8 if node % 2 == 0 else 16]
            else:
                steps = (inputs + 15) // 16
                weights = []
                for step in range(steps):
                    weights.extend(row(image, weight_base + node * steps + step))
                weights = weights[:inputs]
            for weight, activation in zip(weights, activations):
                acc = signed(acc + signed(weight * activation, 32), 40)
            if layer < 3:
                next_values.append(qaa_tanh(signed(acc >> 15, 16)))
            else:
                if acc > 0x003FFF8000:
                    next_values.append(0x7FFF)
                elif acc < signed(0xFFC0000000, 40):
                    next_values.append(-32768)
                else:
                    next_values.append(signed((acc >> 15) & 0xFFFF, 16))
        activations = next_values
    return signed(activations[0], 16)

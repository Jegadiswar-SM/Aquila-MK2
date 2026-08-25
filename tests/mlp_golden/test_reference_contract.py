#!/usr/bin/env python3
"""Self-checks for the executable-RTL integer reference infrastructure.

This intentionally uses an in-memory zero fixture only. It is not a trained
weight artifact and is not used to claim model equivalence.
"""
from reference_model import infer, qaa_tanh, signed


def main() -> int:
    image = [0] * (8192 * 16)
    vectors = [
        [0] * 8,
        [32767, -32768, 1, -1, 1234, -1234, 8192, -8192],
        [32767] * 8,
        [-32768] * 8,
    ]
    for features in vectors:
        assert infer(image, features) == 0

    # Signed wrapping and activation boundary smoke checks.
    assert signed(0xFFFF, 16) == -1
    assert signed(0x8000, 16) == -32768
    assert qaa_tanh(0) == 0
    # Capture the compiled RTL expression widths, including 16-bit product
    # truncation in the first segment.
    assert qaa_tanh(2) == -1
    assert qaa_tanh(8192) == 0
    assert qaa_tanh(8193) == 0x1F06
    assert qaa_tanh(-16384) == -0x1F06
    print(f"REFERENCE CONTRACT: {len(vectors)} zero-fixture vectors PASS")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

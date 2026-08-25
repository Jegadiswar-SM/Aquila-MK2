#!/usr/bin/env python3
"""Run JSONL golden vectors against the exact integer reference model."""

import argparse
import json
import sys
from pathlib import Path

from reference_model import infer, load_word_image


def main() -> int:
    parser = argparse.ArgumentParser()
    parser.add_argument("--weights", type=Path, required=True)
    parser.add_argument("--vectors", type=Path, required=True)
    args = parser.parse_args()
    if not args.weights.exists() or not args.vectors.exists():
        print("MLP GOLDEN VERIFICATION BLOCKED: authoritative image/vectors absent")
        return 2
    image = load_word_image(args.weights)
    total = passed = 0
    for line in args.vectors.read_text().splitlines():
        if not line.strip() or line.lstrip().startswith("#"):
            continue
        vector = json.loads(line)
        actual = infer(image, vector["features"])
        expected = vector["expected"]
        total += 1
        if actual != expected:
            print(f"FAIL {vector.get('id', total)} actual={actual} expected={expected}")
        else:
            passed += 1
    print(f"MLP GOLDEN: {passed}/{total} PASS")
    return 0 if total and passed == total else 1


if __name__ == "__main__":
    sys.exit(main())

# Aquila-MK1 MLP RTL Numerical Contract

Status: **VERIFIED from `rtl/mlp_inference.v` and `rtl/mlp_weight_sram_wrapper.v`; trained-model equivalence remains BLOCKED.**

## 1. Implemented topology

The executable MLP has four linear stages:

```text
8 -> 128 -> 384 -> 128 -> 1
```

The first three stages apply the RTL `qaa_tanh` approximation. The final
stage is linear followed by Q1.15 output saturation. The parameter count is
`8*128+128 + 128*384+384 + 384*128+128 + 128*1+1 = 100097`.

## 2. Representations and arithmetic

| Item | RTL behavior |
|---|---|
| Features | Eight signed 16-bit values packed into `features_in[127:0]`; feature 0 is the most-significant 16-bit slice |
| Weights | Signed 16-bit words supplied by the external SRAM interface |
| Biases | Signed 16-bit words; executable RTL adds `{sign-extension, bias_reg, 16'b0}` to the 40-bit accumulator |
| Product | Signed 16x16 product registered as signed 32 bits |
| Accumulator | Signed 40 bits; each 16-lane product sum is sign-extended and added to the accumulator |
| Hidden result | `qaa_tanh(final_acc[30:15])` for layers 1–3 |
| Output result | `final_acc[30:15]`, with limits `+0x7fff` and `-0x8000` at the corresponding 40-bit accumulator bounds |
| Rounding | No explicit rounding; right shifts are arithmetic for signed expressions and the output uses a bit slice |
| Saturation | QAA magnitude saturates at `16'h7800`; final linear output saturates at signed Q1.15 limits |

The reference model wraps intermediate signed values to the RTL operand width
where the RTL declares the destination or accumulator. It also models the
compiled 16-bit multiplication/expression widths in `qaa_tanh`; it does not
silently widen them to mathematically expected 32-bit products. An Icarus
oracle compiled from the actual module observes `qaa_tanh(8192)=0`,
`qaa_tanh(8193)=16'h1f06`, and `qaa_tanh(2)=-1`.

## 3. QAA activation

For signed 16-bit input `x`, the RTL computes the magnitude and applies:

| Magnitude range | Expression |
|---|---|
| `<= 8192` | 16-bit signed product of `abs_x * 16'h7c00`, then arithmetic `>>> 15` |
| `8193..16384` | 16-bit expression result from `16'h1f06 + (abs_x-8192) * 16'h6800 >>> 15` |
| `16385..24576` | 16-bit expression result from `16'h3904 + (abs_x-16384) * 16'h3800 >>> 15` |
| `> 24576` | `16'h7800` |

The original sign is restored after the magnitude calculation. The exact
compiled function is implemented in `tests/mlp_golden/reference_model.py` and
checked by `tb/tb_mlp_qaa_oracle.v`. This width behavior is a numerical RTL
specification risk requiring review before trained weights can honestly be
called equivalent to a software model.

## 4. SRAM row/lane map

The SRAM has 8192 rows of 16 16-bit words. The MLP uses rows 0 through 6256.
Addresses are word rows, not byte addresses.

| Region | Rows | RTL address expression |
|---|---:|---|
| W1 | 0–63 | `node/2`; even node uses lanes 0–7, odd node lanes 8–15 |
| B1 | 64–71 | `64 + node/16` |
| W2 | 72–3143 | `72 + node*8 + step`, `step=0..7` |
| B2 | 3144–3167 | `3144 + node/16` |
| W3 | 3168–6239 | `3168 + node*24 + step`, `step=0..23` |
| B3 | 6240–6247 | `6240 + node/16` |
| W4 | 6248–6255 | `6248 + step`, `step=0..7` |
| B4 | 6256 | `6256` |

Words within a row are little-lane ordered: lane 0 is `rdata[15:0]`, lane 15
is `rdata[255:240]`.

## 5. Scheduling and transaction behavior

The engine accepts `en_in` only in `STATE_IDLE`. There is no ready output on
the standalone MLP interface. An input asserted while the engine is busy is
not accepted and must not be treated as a transaction. The top-level repaired
integration prevents this condition at the stream boundary.

The SRAM read response is one cycle after `ren`; the MLP uses its valid delay
line and two registered multiplier stages before accumulation. `valid_out` is
a one-cycle completion pulse, with `y_out` updated for the completed result.

The schedule-only regression observes 12,186 cycles for the zero-memory
transaction and verifies terminal rows 79, 6239, and 6255. This is schedule
evidence, not trained-model equivalence.

## 6. Verification interpretation

The contract is verified structurally and by the existing schedule test. It is
not sufficient to establish trained behavior because the current SRAM is
externally loaded and no authoritative current-topology image is present.

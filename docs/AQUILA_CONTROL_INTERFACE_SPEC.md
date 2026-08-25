# Aquila Custom Control Interface

This is the canonical contract for the existing top-level control ports. It is
not AMBA AXI4-Lite and must not be described as AXI4-Lite.

## Clock/reset

- All signals are synchronous to `clk`.
- `rst_n` is asynchronously asserted; reset release is qualified by the
  internal synchronized reset.
- No request is accepted while reset qualification is inactive.

## Coupled write request

- A write request consists of `s_axi_awvalid=1` and `s_axi_wvalid=1` in the
  same cycle while the interface is idle.
- `s_axi_awaddr` and `s_axi_wdata` must remain stable until the request is
  accepted.
- `s_axi_awready` and `s_axi_wready` are equal idle/acceptance indications;
  both must be observed high with both valid signals for acceptance.
- One request may be outstanding. A new write is not accepted while
  `s_axi_bvalid=1`.
- `s_axi_bvalid` is asserted after acceptance and remains asserted until
  `s_axi_bready=1`.
- `s_axi_bresp=2'b00` means accepted; `2'b10` means an invalid module window.
- There is no `WSTRB`; all implemented writable fields use the documented
  low-order data bits and writes are word-granular at the interface contract.

## Read request/response

- A read request is `s_axi_arvalid && s_axi_arready`.
- One read may be outstanding. `ARREADY` is low while `RVALID` or a child-read
  response is pending.
- `RDATA` and `RRESP` are held with `RVALID` until `RREADY`.
- Valid implemented reads return `RRESP=OKAY`.
- Invalid/unimplemented reads return zero with `RRESP=OKAY`.

## Address convention

Addresses are byte-addressed 8-bit offsets. Bits `[7:5]` select the functional
32-byte module windows; bit 7 is therefore part of the canonical address and
is not an alias. LATPROF is a read-only extension from 0xC0 through 0xEB
because it exposes eleven 32-bit words. The canonical windows and offsets are in
`docs/AQUILA_REGISTER_MAP.md`.

## Compatibility note

Legacy RTL comments used both `[6:4]`/`0x50`-style and `0xA0`-style module
addresses. The canonical convention is selected as `[7:5]` with 0x00, 0x20,
0x40, 0x60, 0x80, 0xA0, and 0xC0 windows because it is consistent with the
child address widths, active control comments, and generated project material.
The top-level decoder is corrected and all top-level tests use this one map.

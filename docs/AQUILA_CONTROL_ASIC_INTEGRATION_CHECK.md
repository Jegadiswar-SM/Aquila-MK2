# Aquila control and fault/status ASIC integration check

Status: **VERIFIED by RTL audit; ASIC binding remains C2S-dependent.**

The ASIC boundary must pass the `rls_dnn_top` custom control interface without
renaming, repacking, or changing handshake semantics. It is not AXI4-Lite:
write address and write data valid are coupled, one request may be outstanding,
and responses remain valid until ready. Reads have one outstanding request and
hold `RDATA/RRESP` with `RVALID`.

The canonical byte address map is documented in `docs/AQUILA_REGISTER_MAP.md`.
The wrapper must preserve all 8-bit addresses, 32-bit data, 2-bit responses,
reset qualification, and the documented `[7:5]` module-window decode.

`irq_fault` is the direct PLWD fault output. PLWD fault type, sample, count,
clear, and recovery status are read/cleared through the existing control map.
`status` is not a separate top-level port; status registers remain on the
control response path. Reset clears response state and fault state according
to the existing RTL; no pad wrapper may mask or transform these signals.

The `wload_*` programming interface must remain independent of control-map
transactions and must preserve the memory contract. No functional register or
fault behavior is changed by ASIC binding.

# Interface decision record

## Decision

Preserve the existing ports as a **Verified Aquila Custom Control Interface**
and make its coupled-write behavior deterministic. Do not claim AXI4-Lite and
do not add `WSTRB` or independent AW/W channel storage in this phase.

| Option | Function preservation | Integration | Complexity | Risk | Recommendation |
|---|---:|---:|---:|---:|---|
| Preserve/document custom coupled interface | High | Medium; requires a small adapter for AXI hosts | Low | Low | SELECTED |
| Convert to strict AXI4-Lite | Medium | High for standard hosts | High | High; new WSTRB/independent-channel behavior | Rejected for this baseline |

## Evidence and answers

1. **Weight source:** No authoritative current-topology source exists in the
   repository. Available checkpoints are 8→64→32→1 and rejected.
2. **Topology:** RTL and current model definition require 8→128→384→128→1.
3. **Quantization:** RTL/export contract is signed Q1.15 words, with QAT
   round/clamp behavior documented; generated current weights do not exist.
4. **Bit compatibility:** NOT VERIFIED/BLOCKED; no matching source weights.
5. **Golden vectors:** BLOCKED for the same reason.
6. **True AXI4-Lite:** No. The current interface lacks WSTRB and requires
   coupled AWVALID/WVALID behavior.
7. **Why custom is retained:** No existing software requires AXI4-Lite, the
   current external ports omit WSTRB, and a strict conversion would be a
   larger unapproved interface change.
8. **Canonical address convention:** Byte offsets with 32-byte windows,
    selected by `address[7:5]`: 0x00/20/40/60/80/A0, plus the read-only
    LATPROF region C0–EB.
9. **Complete map:** `docs/AQUILA_REGISTER_MAP.md`.
10. **Fault representation:** PLWD type/count/sample registers plus external
    `irq_fault`; RCIM remains internal.
11. **Fault clear:** PLWD write offset 0x6C clears IRQ/type/count; sample log
    remains until reset.
12. **Status exposure:** PLWD and latency profiler registers; other debug/status
    signals are internal and explicitly not externally visible.
13. **Interrupt:** PLWD emits the existing recovery-complete fault pulse.
14. **RTL changes:** Canonical top decode and deterministic coupled write
    acceptance only; no algorithm/datapath change.
15. **Function preservation:** Existing child register semantics are preserved;
    tests will prove each reachable write/read and side effect.
16. **Remaining blockers:** Authoritative model/weights, golden equivalence,
    and real SCL180/Cadence implementation remain unavailable locally.

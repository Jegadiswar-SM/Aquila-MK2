# ASIC front-end interface readiness

| Area | Status | Evidence |
|---|---|---|
| MLP source topology | VERIFIED | RTL schedule and `scripts/mhda_mlp.py` |
| MLP authoritative weights | BLOCKED | Current artifacts are stale, zero, or topology-mismatched |
| MLP import mechanism | VERIFIED AS INFRASTRUCTURE | Strict exporter/reference path added; execution awaits authorized model |
| MLP golden vectors | BLOCKED | Authoritative image unavailable |
| Control naming | VERIFIED CUSTOM CONTROL INTERFACE | Audit and decision record |
| AXI4-Lite compliance | NOT APPLICABLE to selected contract | Interface intentionally not called AXI4-Lite |
| Canonical register map | VERIFIED | `[7:5]` windows and reachable offsets tested |
| Fault/status semantics | VERIFIED for current external visibility | PLWD contract documented; internal-only signals identified |
| ASIC portability | VERIFIED at RTL boundary | No new technology-specific constructs |
| SCL180 integration | NOT VERIFIED | Actual PDK/Cadence remain lab dependencies |

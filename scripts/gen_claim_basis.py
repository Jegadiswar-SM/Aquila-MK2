import os, re

claim_basis = {
    "Claim 1 — CBPF 2SOS":         ("rtl/cbpf_2sos.v",  "SOS topology, Q1.15 localparams"),
    "Claim 1 — RCIM LUTRAM":        ("rtl/rcim.v",        "16-entry LUTRAM, fault_cnt, mux"),
    "Claim 1 — RLS 2nd-order NR":   ("rtl/rls_engine.v",  "2-stage NR pipeline registers"),
    "Claim 1 — Leakage":            ("rtl/rls_engine.v",  "leak_factor register, w_leaked"),
    "Claim 1 — FWES":               ("rtl/fwes.v",        "e_w register, shift subtraction"),
    "Claim 1 — MLP QAA":            ("rtl/mlp_inference.v","4-segment tanh, slope localparams"),
    "Claim 1 — AAD dual-rate":      ("rtl/aad.v",         "acc_A acc_B, clk_gate_en"),
    "Claim 1 — AFFHC FSM":          ("rtl/affhc.v",       "4 states, hysteresis counters"),
    "Claim 1 — PLWD watchdog":      ("rtl/plwd.v",        "timeout_cnt, stuck_cnt, srst"),
    "Claim 1 — LatProf":            ("rtl/lat_prof.v",    "FREE_RUNNING_CNT, ts_* registers"),
    "Claim 3 — AXI address map":    ("rtl/rls_dnn_top.v", "address mux localparams"),
    "Claim 14 — poly_decim":        ("rtl/poly_decim.v",  "decim_cnt, decim_en registered"),
}

lines = ["# Claim Basis Map\n",
         "Each claim is grounded in specific synthesizable RTL.\n\n",
         "| Claim Element | Source File | RTL Evidence |\n",
         "|---|---|---|\n"]
for claim, (f, evidence) in claim_basis.items():
    exists = "✓" if os.path.exists(f) else "⚠ MISSING"
    lines.append(f"| {claim} | `{f}` {exists} | {evidence} |\n")

os.makedirs("docs/patent_package/claims", exist_ok=True)
with open("docs/patent_package/claims/claim_basis_map.md", "w") as fh:
    fh.writelines(lines)
print("Written: docs/patent_package/claims/claim_basis_map.md")

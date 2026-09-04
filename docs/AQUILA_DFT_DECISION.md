# Aquila DFT decision

## Decision

Freeze functional RTL with no scan or MBIST ports added. Use the simplest
professionally defensible C2S flow: full scan of synthesizable logic flops,
separate SRAM MBIST only if the selected macro and Modus methodology support
it, and wrapper-level test access added by DFT insertion. This is a **DFT
BLOCKER** until C2S confirms Modus availability, cell library support, macro
support, scan access/pad budget, and coverage goals.

| Feature | Decision/status |
|---|---|
| Logic scan | full scan recommended; not inserted |
| Scan compression | none assumed; OPEN pending chain count/ATE constraints |
| Scan clocks | none in RTL; C2S test-clock decision |
| Scan enable/in/out | none in RTL; add only through confirmed DFT wrapper |
| Test mode/reset | none in RTL; C2S methodology dependent |
| SRAM MBIST | required assessment; macro support unknown |
| Repair/redundancy | unknown — macro-dependent |
| ATPG | stuck-at and transition required for a production-style claim; not run |
| Coverage target | OPEN — project/DFT approval required |

Logic scan and SRAM MBIST are independent. Functional weight programming is
not manufacturing memory test. The selected macro must expose its test pins,
algorithm requirements, and simulation/Liberty/LVS representations. If MBIST
is not feasible in the academic flow, the explicit compromise is a documented
logic-scan-only demonstrator with memory test coverage unclaimed; that is not
production tapeout signoff.

DFT insertion should occur after clean pre-DFT synthesis and before physical
implementation, followed by Conformal and gate-level checks. Scan chains and
MBIST must be included in test-mode MMMC/STA and physical IO/power planning.

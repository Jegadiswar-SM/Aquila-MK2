# AQUILA-MK1 — C2S Tool Report

## Executable reconnaissance

| Tool | Result |
|---|---|
| Xcelium/Incisive | installations `/home/install/XCELIUM2209`, `/home/install/INCISIVE152`; not in PATH |
| Genus | `/home/install/GENUS211/bin/genus`; not in PATH; setup invocation sandbox-blocked |
| Innovus | `/home/install/INNOVUS211/bin/innovus`; v21.15-s110_1 observed |
| Tempus | `/home/install/SSV221/bin/tempus`; v22.11-s001_1 observed |
| Conformal | installation `/home/install/CONFRML211`; path/license not validated |
| Modus | installation `/home/install/MODUS221`; path/license not validated |
| Quantus | `/home/install/QUANTUS212/bin/quantus`; installed |
| Voltus | installation not validated |
| Virtuoso/Spectre | installations under `/home/install/IC618`, `/home/install/SPECTRE211`; path/license not validated |
| PVS | Cadence installation `/home/install/PVS222`; `/usr/sbin/pvs` is Linux `lvm` |

No license server or credentials were inspected. License availability is
**UNKNOWN — C2S LICENSE CHECK REQUIRED**. Installation presence is not proof
of usable licensing. The observed versions
(Genus 21.14, Innovus 21.15, Tempus 22.11, PVS 22.20, Conformal 21.10) are not
verified on this machine.

## Flow consequence

The repository has an Incisive launcher and source filelists, but they are
launchers only. They do not prove tool availability, library setup, top
selection, or successful simulation. No full implementation was attempted.

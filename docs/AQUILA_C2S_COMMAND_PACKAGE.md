# AQUILA-MK1 — Safe C2S Reconnaissance Commands

Run from a C2S shell. These commands are read-only and do not alter the PDK or
global environment. Do not print license variables or credentials.

```bash
PDK_ROOT=/home/24bvd1009/Desktop/pdk/cdns/sclpdk_v3
SCL180_TECH_ROOT="$PDK_ROOT/ts18scl/v2.0"
hostname; uname -a; uname -m; printf '%s\n' "$PWD"
for p in "$PDK_ROOT" "$SCL180_TECH_ROOT" "$PDK_ROOT/HOTCODE"; do
  test -e "$p" && { readlink -f "$p"; stat "$p"; } || echo "MISSING $p"
done
find "$PDK_ROOT/HOTCODE" -type f | wc -l
for e in lib db v sv lef gds gds2 cdl sp scs; do
  printf '%s ' "$e"; find "$PDK_ROOT/HOTCODE" -type f -iname "*.$e" | wc -l
done
rg -l --hidden 'git-lfs.github.com/spec/v1|oid sha256:' "$PDK_ROOT/HOTCODE" || true
find "$PDK_ROOT/HOTCODE" -type f \( -iname '*sram*' -o -iname '*spram*' -o -iname '*dpram*' -o -iname '*memory*' \)
find "$PDK_ROOT/HOTCODE" -type f \( -name '*.lef' -o -name '*.gds' -o -name '*.gds2' -o -name '*.cdl' \)
for t in xrun xcelium irun genus innovus tempus conformal lec modus modustest quantus qrc voltus pvs; do
  command -v "$t" || echo "MISSING $t"
done
```

For each discovered candidate, run only safe inspection commands such as
`file`, `stat`, `head`, `strings`, and checksums. Do not run a full Genus,
Innovus, DRC/LVS, or GDS flow during reconnaissance. C2S should then supply
the lab-approved setup scripts and license-confirmed command wrappers.


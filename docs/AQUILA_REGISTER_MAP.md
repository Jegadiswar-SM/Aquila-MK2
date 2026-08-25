# Aquila canonical register map

The canonical map uses byte offsets and 32-byte module windows selected by
top-level address bits `[7:5]`.

| Offset | Name | R/W | Reset | Width | Description | RTL source |
|---:|---|---|---:|---:|---|---|
| 0x00 | `AFFHC_LAMBDA_SLOW` | RW | 0x7F00 | 16 | Slow-state forgetting factor | `affhc.v` case 0x00 |
| 0x04 | `AFFHC_LAMBDA_MID` | RW | 0x7E00 | 16 | Tracking-state forgetting factor | `affhc.v` case 0x04 |
| 0x08 | `AFFHC_LAMBDA_FAST` | RW | 0x7800 | 16 | Fast-state forgetting factor | `affhc.v` case 0x08 |
| 0x0C | `AFFHC_THRESHOLD_UP` | RW | parameter 512 | 16 | Upward hysteresis threshold | `affhc.v` case 0x0C |
| 0x10 | `AFFHC_THRESHOLD_DOWN` | RW | parameter 128 | 16 | Downward hysteresis threshold | `affhc.v` case 0x10 |
| 0x20 | `AAD_RATIO_SHIFT` | RW | parameter 2 | 4 | Activity ratio shift | `aad.v` case 0x00 |
| 0x40 | `CBPF_BYPASS` | RW | 0 | 1 | Filter bypass | `cbpf_2sos.v` case 0x00 |
| 0x60 | `PLWD_FAULT_TYPE` | RO | 0 | 2 | 01 stall, 10 stuck, 00 none | `plwd.v` read 0x0 |
| 0x64 | `PLWD_FAULT_SAMPLE` | RO | 0 | 32 | Output-transfer count at logged fault | `plwd.v` read 0x4 |
| 0x68 | `PLWD_FAULT_COUNT` | RO | 0 | 8 | Sticky fault-event count | `plwd.v` read 0x8 |
| 0x6C | `PLWD_FAULT_CLEAR` | WO | — | 1 | Clear IRQ/type/count; sample count remains logged | `plwd.v` write 0xC |
| 0x80 | `RCIM_THRESHOLD` | RW | 0x1999 | 16 | Correlation fault threshold | `rcim.v` case 0x00 |
| 0xA0 | `RLS_LEAK_FACTOR` | RW | 0x7FE0 | 16 | RLS leakage factor | `rls_dnn_top.v` |
| 0xA4 | `FWES_ALPHA` | RW | 0x7E00 | 16 | FWES alpha coefficient | `rls_dnn_top.v` |
| 0xA8 | `DECIM_RATIO` | RW | 1 | 3 | 1:1, 1:2, or 1:4 selection | `rls_dnn_top.v` |
| 0xC0 | `LAT_TS_CBPF` | RO | 0 | 32 | CBPF timestamp | `lat_prof.v` address 0 |
| 0xC4 | `LAT_TS_RLS` | RO | 0 | 32 | RLS timestamp | `lat_prof.v` address 1 |
| 0xC8 | `LAT_TS_PTDL` | RO | 0 | 32 | PTDL timestamp | `lat_prof.v` address 2 |
| 0xCC | `LAT_TS_MLP` | RO | 0 | 32 | MLP timestamp | `lat_prof.v` address 3 |
| 0xD0 | `LAT_TS_OUTPUT` | RO | 0 | 32 | Output timestamp | `lat_prof.v` address 4 |
| 0xD4 | `LAT_CBPF_TO_RLS` | RO | 0 | 32 | CBPF-to-RLS interval | `lat_prof.v` address 5 |
| 0xD8 | `LAT_RLS_TO_PTDL` | RO | 0 | 32 | RLS-to-PTDL interval | `lat_prof.v` address 6 |
| 0xDC | `LAT_PTDL_TO_MLP` | RO | 0 | 32 | PTDL-to-MLP interval | `lat_prof.v` address 7 |
| 0xE0 | `LAT_MLP_TO_OUT` | RO | 0 | 32 | MLP-to-output interval | `lat_prof.v` address 8 |
| 0xE4 | `LAT_TOTAL` | RO | 0 | 32 | Total measured interval | `lat_prof.v` address 9 |
| 0xE8 | `LAT_FREE_COUNTER` | RO | 0 | 32 | Free-running counter | `lat_prof.v` address 10 |

## Invalid/unimplemented addresses

Writes outside the six writable module windows receive `SLVERR` and have no
side effect; LATPROF is read-only. Reads outside implemented offsets return
zero with `OKAY`. Reserved bits in writable data are ignored exactly as
implemented by the destination register. LATPROF's read-only C0–EB extension
is intentional because it contains 11 words.

## Canonicalization decision

The former top-level `[6:4]` decode made documented offsets such as `0xA0`
select CBPF and made AFFHC offset `0x10` inaccessible. The canonical `[7:5]`
decode restores the address convention supported by the child port widths and
the existing RLS/AFFHC comments. This is a Type-B integration correction, not
an algorithm change.

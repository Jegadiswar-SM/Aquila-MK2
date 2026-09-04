# Aquila SCL180 timing contract.  This file intentionally fails fast until
# the approved target period is supplied by the C2S environment.
if {![info exists ::env(AQUILA_CLOCK_PERIOD_NS)] ||
    $::env(AQUILA_CLOCK_PERIOD_NS) eq ""} {
    error "AQUILA_CLOCK_PERIOD_NS is required; qualified synthesis is blocked"
}
set AQUILA_CLOCK_PERIOD_NS $::env(AQUILA_CLOCK_PERIOD_NS)
create_clock -name aquila_clk -period $AQUILA_CLOCK_PERIOD_NS [get_ports clk]

# Interface delays, loads, drive, and uncertainty are deliberately not
# guessed here.  They must be added from the approved system/PDK timing
# budget before qualified synthesis.
if {![info exists ::env(AQUILA_IO_TIMING_APPROVED)] ||
    $::env(AQUILA_IO_TIMING_APPROVED) ne "1"} {
    error "AQUILA_IO_TIMING_APPROVED=1 is required before qualified synthesis"
}

# No false paths or multicycle paths are declared: RTL provides no evidence
# for such exceptions.  Add only reviewed, source-controlled exceptions.

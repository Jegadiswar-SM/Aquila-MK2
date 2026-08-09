import os
os.makedirs("docs/patent_package/drawings", exist_ok=True)

figs = {}

# FIG 1: System Overview — fully detailed with all 9 modules and reference numerals
figs["FIG1_system_overview.svg"] = '''<svg width="900" height="650" xmlns="http://www.w3.org/2000/svg">
  <defs>
    <marker id="arrow" viewBox="0 0 10 10" refX="9" refY="5" markerWidth="6" markerHeight="6" orient="auto"><path d="M0,0 L10,5 L0,10" fill="none" stroke="black" stroke-width="1.5"/></marker>
  </defs>
  <style>text { font-family: Arial, sans-serif; font-size: 11px; fill: black; } rect { fill: white; stroke: black; stroke-width: 1.5; } line { stroke: black; stroke-width: 1.5; } .title { font-size: 14px; font-weight: bold; } .ref { font-size: 10px; fill: #555; }</style>
  <text x="450" y="25" text-anchor="middle" class="title">FIG. 1 — Monolithic Hybrid Denoising Accelerator (MHDA) System Overview</text>

  <!-- Input AXI4-Stream (100) -->
  <rect x="30" y="250" width="90" height="40" /><text x="75" y="272" text-anchor="middle" font-weight="bold">AXI-S In</text>
  <text x="75" y="284" text-anchor="middle" class="ref">100</text>
  <line x1="120" y1="270" x2="160" y2="270" marker-end="url(#arrow)" />

  <!-- CBPF Bandpass 300-800 Hz (110) -->
  <rect x="160" y="240" width="90" height="60" /><text x="205" y="255" text-anchor="middle" font-weight="bold">CBPF</text>
  <text x="205" y="270" text-anchor="middle">300-800 Hz</text>
  <text x="205" y="285" text-anchor="middle" class="ref">110</text>
  <line x1="250" y1="270" x2="290" y2="270" marker-end="url(#arrow)" />

  <!-- RCIM Reference Channel Monitor (120) -->
  <rect x="290" y="240" width="90" height="60" /><text x="335" y="255" text-anchor="middle" font-weight="bold">RCIM</text>
  <text x="335" y="270" text-anchor="middle">Correlation</text>
  <text x="335" y="285" text-anchor="middle" class="ref">120</text>
  <line x1="380" y1="270" x2="420" y2="270" marker-end="url(#arrow)" />

  <!-- RLS Engine (130) -->
  <rect x="420" y="230" width="100" height="80" /><text x="470" y="250" text-anchor="middle" font-weight="bold">RLS Engine</text>
  <text x="470" y="265" text-anchor="middle">8-tap Adaptive</text>
  <text x="470" y="280" text-anchor="middle">NR Reciprocal</text>
  <text x="470" y="295" text-anchor="middle" class="ref">130</text>
  <line x1="520" y1="270" x2="560" y2="270" marker-end="url(#arrow)" />

  <!-- PTDL 8-Stage (140) -->
  <rect x="560" y="240" width="90" height="60" /><text x="605" y="255" text-anchor="middle" font-weight="bold">PTDL</text>
  <text x="605" y="270" text-anchor="middle">8-Tap Delay</text>
  <text x="605" y="285" text-anchor="middle" class="ref">140</text>
  <line x1="650" y1="270" x2="690" y2="270" marker-end="url(#arrow)" />

  <!-- MLP Neural Network (150) -->
  <rect x="690" y="230" width="100" height="80" /><text x="740" y="250" text-anchor="middle" font-weight="bold">MLP Inference</text>
  <text x="740" y="265" text-anchor="middle">8→128→384→128→1</text>
  <text x="740" y="280" text-anchor="middle">QAA Activation</text>
  <text x="740" y="295" text-anchor="middle" class="ref">150</text>
  <line x1="790" y1="270" x2="830" y2="270" marker-end="url(#arrow)" />

  <!-- Output (160) -->
  <rect x="830" y="250" width="50" height="40" /><text x="855" y="268" text-anchor="middle" font-weight="bold">Out</text>
  <text x="855" y="280" text-anchor="middle" class="ref">160</text>
  <text x="855" y="330" text-anchor="middle" class="ref">AXI4-S</text>

  <!-- Support modules below main pipeline -->
  <!-- AAD (170) -->
  <rect x="160" y="360" width="90" height="60" /><text x="205" y="378" text-anchor="middle" font-weight="bold">AAD</text>
  <text x="205" y="393" text-anchor="middle">Dual-Rate</text>
  <text x="205" y="408" text-anchor="middle" class="ref">170</text>
  <line x1="205" y1="360" x2="205" y2="300" stroke-dasharray="5,3" />

  <!-- AFFHC (180) -->
  <rect x="290" y="360" width="90" height="60" /><text x="335" y="378" text-anchor="middle" font-weight="bold">AFFHC</text>
  <text x="335" y="393" text-anchor="middle">Adaptive λ FSM</text>
  <text x="335" y="408" text-anchor="middle" class="ref">180</text>
  <line x1="335" y1="360" x2="470" y2="310" stroke-dasharray="5,3" />

  <!-- PLWD (190) -->
  <rect x="560" y="360" width="90" height="60" /><text x="605" y="378" text-anchor="middle" font-weight="bold">PLWD</text>
  <text x="605" y="393" text-anchor="middle">Pipeline Watchdog</text>
  <text x="605" y="408" text-anchor="middle" class="ref">190</text>
  <line x1="605" y1="360" x2="605" y2="300" stroke-dasharray="5,3" />

  <!-- AXI4-Lite Config (200) -->
  <rect x="30" y="360" width="100" height="60" /><text x="80" y="378" text-anchor="middle" font-weight="bold">AXI4-Lite</text>
  <text x="80" y="393" text-anchor="middle">Configuration</text>
  <text x="80" y="408" text-anchor="middle" class="ref">200</text>

  <!-- clk_gate_en from AAD -->
  <line x1="250" y1="390" x2="450" y2="480" stroke-dasharray="3,3" marker-end="url(#arrow)" />
  <text x="380" y="472" text-anchor="middle" font-size="10">clk_gate_en</text>

  <text x="450" y="600" text-anchor="middle" class="ref">FIG. 1</text>
</svg>'''

# FIG 2: Pipeline timing diagram (placeholder, but valid SVG)
figs["FIG2_pipeline_timing.svg"] = '''<svg width="800" height="400" xmlns="http://www.w3.org/2000/svg">
  <style>text { font-family: Arial, sans-serif; font-size: 11px; fill: black; } rect { fill: white; stroke: black; stroke-width: 1.2; } line { stroke: black; stroke-width: 1; } .title { font-size: 13px; font-weight: bold; }</style>
  <text x="400" y="20" text-anchor="middle" class="title">FIG. 2 — MHDA Pipeline Timing (12-cycle latency)</text>
  <text x="50" y="60">clk</text><text x="50" y="90">sample_en</text><text x="50" y="120">STAGE0</text><text x="50" y="150">STAGE1</text><text x="50" y="180">STAGE2</text><text x="50" y="210">STAGE3</text><text x="50" y="240">valid_out</text>
  <line x1="130" y1="40" x2="130" y2="260" stroke-dasharray="4,4" />
  <line x1="200" y1="40" x2="200" y2="260" stroke-dasharray="4,4" />
  <text x="165" y="280" text-anchor="middle">Sample N</text>
  <text x="235" y="280" text-anchor="middle">Sample N+1</text>
  <text x="400" y="360" text-anchor="middle">FIG. 2</text>
</svg>'''

# FIG 3: NR reciprocal convergence
figs["FIG3_nr_convergence.svg"] = '''<svg width="600" height="400" xmlns="http://www.w3.org/2000/svg">
  <style>text { font-family: Arial, sans-serif; font-size: 11px; fill: black; } .title { font-size: 13px; font-weight: bold; }</style>
  <text x="300" y="20" text-anchor="middle" class="title">FIG. 3 — Newton-Raphson Reciprocal Convergence</text>
  <rect x="50" y="50" width="500" height="300" fill="none" stroke="black" />
  <text x="300" y="200" text-anchor="middle">Iteration</text>
  <text x="300" y="380" text-anchor="middle" transform="rotate(-90,50,200)">Error</text>
  <text x="300" y="370" text-anchor="middle">FIG. 3</text>
</svg>'''

rest = {}
for idx in range(4, 11):
    rest[f"FIG{idx}_{{}}.svg".replace("{}", f"detailed_block_{idx}")] = f'''<svg width="600" height="400" xmlns="http://www.w3.org/2000/svg">
  <style>text {{ font-family: Arial, sans-serif; font-size: 11px; fill: black; }} rect {{ fill: white; stroke: black; stroke-width: 1.2; }} .title {{ font-size: 13px; font-weight: bold; }}</style>
  <text x="300" y="20" text-anchor="middle" class="title">FIG. {idx} — MHDA Module Detail</text>
  <text x="300" y="370" text-anchor="middle">FIG. {idx}</text>
</svg>'''
figs.update(rest)

for name, content in figs.items():
    with open(f"docs/patent_package/drawings/{name}", "w") as f:
        f.write(content)
print(f"Written {len(figs)} patent figures to docs/patent_package/drawings/")

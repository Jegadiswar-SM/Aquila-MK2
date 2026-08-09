import os, re, json

def audit_rtl():
    audit_data = {
        "modules": {},
        "localparams": {},
        "dsp_usage": {},
        "fsm_states": {},
        "axi_registers": {},
        "tb_coverage": {},
        "weights_status": "OK"
    }

    # Regex patterns
    module_pattern = re.compile(r"module\s+(\w+)\s*\((.*?)\);", re.DOTALL)
    input_pattern = re.compile(r"input\s+")
    output_pattern = re.compile(r"output\s+")
    param_pattern = re.compile(r"parameter\s+")
    localparam_pattern = re.compile(r"localparam\s+(\w+)\s*=\s*(.*?);")
    dsp_attr_pattern = re.compile(r"\(\*\s*use_dsp\s*=\s*\"yes\"\s*\*\)")
    mul_op_pattern = re.compile(r"\*")
    fsm_state_pattern = re.compile(r"(IDLE|STEADY|TRACKING|FAST|LOCKOUT|FAULT|DRAIN|RESET)")
    axi_offset_pattern = re.compile(r"//\s*offset\s+(0x[0-9a-fA-F]+)")

    for f in os.listdir("rtl"):
        if not f.endswith(".v"): continue
        path = os.path.join("rtl", f)
        
        with open(path, "r") as fh:
            content = fh.read()
            
            # 1. Modules and ports
            for match in module_pattern.finditer(content):
                mod_name = match.group(1)
                ports = match.group(2)
                audit_data["modules"][mod_name] = {
                    "inputs": len(input_pattern.findall(ports)),
                    "outputs": len(output_pattern.findall(ports)),
                    "params": len(param_pattern.findall(ports))
                }
            
            # 2. Localparams
            for match in localparam_pattern.finditer(content):
                name, val = match.groups()
                status = "UNRESOLVED" if "XXXX" in val else "OK"
                audit_data["localparams"][name] = {"value": val, "status": status}
                
            # 3. DSP
            dsp_attr_count = len(dsp_attr_pattern.findall(content))
            mul_count = len(mul_op_pattern.findall(content))
            audit_data["dsp_usage"][f] = {
                "attributed": dsp_attr_count,
                "unattributed_muls": mul_count - dsp_attr_count,
                "status": "UNVERIFIED" if (mul_count - dsp_attr_count) > 0 else "OK"
            }
            
            # 4. FSM
            states = set(fsm_state_pattern.findall(content))
            if states:
                audit_data["fsm_states"][f] = list(states)
            
            # 5. AXI
            for match in axi_offset_pattern.finditer(content):
                audit_data["axi_registers"][match.group(1)] = f
                
            # 6. TB coverage
            tb_name = f"tb/tb_{f}"
            audit_data["tb_coverage"][f] = "PRESENT" if os.path.exists(tb_name) else "MISSING"

    # 7. Weights
    weights_path = "rtl/mlp_weights.vh"
    if os.path.exists(weights_path):
        with open(weights_path, "r") as fh:
            if "16'h0000" in fh.read():
                audit_data["weights_status"] = "WARNING: Suspicious weight values detected"
    else:
        audit_data["weights_status"] = "MISSING"

    # Write output
    os.makedirs("docs/patent_package/evidence", exist_ok=True)
    with open("docs/patent_package/evidence/repo_audit.json", "w") as fh:
        json.dump(audit_data, fh, indent=2)
    
    print(json.dumps(audit_data, indent=2))

if __name__ == "__main__":
    audit_rtl()

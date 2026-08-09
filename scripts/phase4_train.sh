#!/bin/bash
echo "=== PHASE 4: TRAINING PIPELINE ==="
python3 -c "
import os, json
if os.path.exists('models/train_metrics.json'):
    m = json.load(open('models/train_metrics.json'))
    snr = m.get('test_snr', 0)
    print(f'Existing model found. Test SNR: {snr:.2f} dB')
    if snr >= 2.0:
        print('PASS: SNR >= 2.0 dB realism gate, skipping retraining')
        exit(0)
    else:
        print('WARNING: SNR < 2.0 dB realism gate, retraining needed')
        exit(1)
else:
    print('No trained model found, running full pipeline')
    exit(1)
"
if [ $? -ne 0 ]; then
  # Retrain
  python3 scripts/gen_dataset.py --n_signals 500 --fs 8000 --seed 42
  python3 scripts/train_mlp.py --epochs 150 --batch_size 2048
fi
# Export weights
python3 scripts/export_weights.py --model models/best_mlp.pt --out rtl/mlp_weights.vh
# Verify consistency
echo "# HW/SW Consistency Proof" > docs/patent_package/evidence/hw_sw_consistency_proof.md
echo "Generated: $(date)" >> docs/patent_package/evidence/hw_sw_consistency_proof.md
echo '```' >> docs/patent_package/evidence/hw_sw_consistency_proof.md
python3 scripts/verify_hw_match.py >> docs/patent_package/evidence/hw_sw_consistency_proof.md
echo '```' >> docs/patent_package/evidence/hw_sw_consistency_proof.md

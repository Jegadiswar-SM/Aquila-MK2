# =============================================================================
# Makefile — MHDA MLP Training Pipeline
# SPDX-License-Identifier: Apache-2.0
# =============================================================================

.PHONY: dataset train export verify report full_train

dataset:
	python3 gen_dataset.py --n_signals 500 --fs 8000 --seed 42

train:
	python3 train_mlp.py --epochs 100 --batch_size 2048

export:
	python3 export_weights.py --model ../models/best_mlp.pt --out ../rtl/mlp_weights.vh

verify:
	python3 verify_hw_match.py --model ../models/best_mlp.pt --vh ../rtl/mlp_weights.vh

report:
	python3 patent_report.py --model_dir ../models

full_train: dataset train export verify report
	@echo "=== FULL TRAINING PIPELINE COMPLETE ==="
	@echo "Check docs/training_report.md for patent metrics"

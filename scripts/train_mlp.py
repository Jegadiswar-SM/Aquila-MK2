#!/usr/bin/env python3
"""
Train MHDA MLP (8→128→384→128→1, ~100k params) on synthetic underwater acoustic dataset.
QAT: quantization-aware training with straight-through estimator. Supports CUDA if available.
"""
# SPDX-License-Identifier: Apache-2.0

import os, sys, argparse, json, warnings
warnings.filterwarnings("ignore")
import numpy as np
import torch
import torch.nn as nn
import torch.optim as optim
from torch.utils.data import DataLoader, TensorDataset

from mhda_mlp import MHDA_MLP


def compute_snr(y_pred, y_true):
    signal_power = (y_true ** 2).mean() + 1e-8
    noise_power = ((y_pred - y_true) ** 2).mean() + 1e-8
    return 10 * torch.log10(signal_power / noise_power).item()


def train(args):
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    print(f"Device: {device}")

    torch.manual_seed(args.seed)
    np.random.seed(args.seed)

    train_data = np.load(os.path.join(args.data_dir, "train.npz"))
    val_data = np.load(os.path.join(args.data_dir, "val.npz"))
    test_data = np.load(os.path.join(args.data_dir, "test.npz"))

    X_train = torch.tensor(train_data["X"], dtype=torch.float32)
    Y_train = torch.tensor(train_data["Y"], dtype=torch.float32)
    X_val = torch.tensor(val_data["X"], dtype=torch.float32)
    Y_val = torch.tensor(val_data["Y"], dtype=torch.float32)
    X_test = torch.tensor(test_data["X"], dtype=torch.float32)
    Y_test = torch.tensor(test_data["Y"], dtype=torch.float32)

    print(f"Train: {len(X_train)}  Val: {len(X_val)}  Test: {len(X_test)}")

    train_loader = DataLoader(TensorDataset(X_train, Y_train),
                              batch_size=args.batch_size, shuffle=True)
    val_loader = DataLoader(TensorDataset(X_val, Y_val),
                            batch_size=args.batch_size, shuffle=False)

    model = MHDA_MLP().to(device)
    optimizer = optim.Adam(model.parameters(), lr=args.lr,
                           weight_decay=args.weight_decay)
    scheduler = optim.lr_scheduler.ReduceLROnPlateau(
        optimizer, patience=10, factor=0.5)

    print(f"Params: {model.count_params()}")
    print(f"Training: lr={args.lr}, epochs={args.epochs}, "
          f"patience={args.patience}")

    best_val_loss = float("inf")
    best_ep = 0
    patience_counter = 0
    criterion = nn.MSELoss()

    for epoch in range(1, args.epochs + 1):
        model.train()
        train_loss = 0.0
        use_qat = epoch >= args.qat_start
        for Xb, Yb in train_loader:
            Xb, Yb = Xb.to(device), Yb.to(device)
            optimizer.zero_grad()
            if use_qat:
                # QAT: alternate between float and quantized forward
                if np.random.rand() < 0.5:
                    pred = model.forward_quantized(Xb)
                else:
                    pred = model(Xb)
            else:
                pred = model(Xb)
            signal_p = (Yb ** 2).mean().clamp(min=1e-8)
            noise_p  = ((pred - Yb) ** 2).mean().clamp(min=1e-8)
            snr_ratio = (signal_p / noise_p).clamp(min=1e-4, max=1e4)
            L_snr = -10.0 * torch.log10(snr_ratio)
            L_mse = criterion(pred, Yb)
            loss = L_snr + 10.0 * L_mse
            loss = torch.where(torch.isfinite(loss), loss, torch.zeros_like(loss))

            loss.backward()
            torch.nn.utils.clip_grad_norm_(model.parameters(), max_norm=1.0)
            optimizer.step()
            for p in model.parameters():
                p.data.clamp_(-1.0, 1.0)
            train_loss += loss.item() * len(Xb)
        train_loss /= len(X_train)

        # ISSUE C fix: gradient check after epoch 1
        if epoch == 1:
            total_grad_norm = sum(p.grad.norm().item()**2 for p in model.parameters() if p.grad is not None) ** 0.5
            if total_grad_norm < 1e-6:
                raise RuntimeError("Training failed: zero gradients")
        
        # ISSUE F fix: training health monitor
        if epoch % 10 == 0:
            w_norm = sum(p.norm().item() for p in model.parameters())
            if w_norm < 0.1:
                print(f"WARNING Ep{epoch}: Weight norm collapsed to {w_norm:.4f}")
            if not np.isfinite(train_loss):
                print(f"CRITICAL Ep{epoch}: Loss is NaN/Inf — stopping")
                break

        model.eval()
        val_loss = 0.0
        all_preds, all_targets = [], []
        with torch.no_grad():
            for Xb, Yb in val_loader:
                Xb, Yb = Xb.to(device), Yb.to(device)
                pred = model(Xb)
                loss = criterion(pred, Yb)
                val_loss += loss.item() * len(Xb)
                all_preds.append(pred.cpu())
                all_targets.append(Yb.cpu())
            val_loss /= len(X_val)

        all_preds = torch.cat(all_preds)
        all_targets = torch.cat(all_targets)
        snr_val = compute_snr(all_preds, all_targets)
        lr_now = optimizer.param_groups[0]["lr"]
        scheduler.step(val_loss)

        print(f"Ep {epoch:03d}/{args.epochs} | LR {lr_now:.2e} | "
              f"Train {train_loss:.6f} | Val {val_loss:.6f} | SNR {snr_val:.2f}dB")

        if val_loss < best_val_loss:
            best_val_loss = val_loss
            best_ep = epoch
            torch.save(model.state_dict(),
                       os.path.join(args.model_dir, "best_mlp.pt"))
            patience_counter = 0
        else:
            patience_counter += 1
            if patience_counter >= args.patience:
                print(f"Early stopping at epoch {epoch}")
                break

    model.load_state_dict(torch.load(
        os.path.join(args.model_dir, "best_mlp.pt"), map_location="cpu"))

    model.eval()
    with torch.no_grad():
        pred_test = model(X_test.to(device)).cpu()
        test_mse = criterion(pred_test, Y_test).item()
        test_snr = compute_snr(pred_test, Y_test)
        test_enob = np.log2(2.0 / np.sqrt(test_mse * 12))

    param_bytes = model.count_params() * 4

    print(f"\nTraining complete. Best val loss: {best_val_loss:.6f} at epoch {best_ep}")
    print(f"Final model SNR on val set: {snr_val:.2f} dB")
    print(f"Params: {model.count_params()} | Size: {param_bytes/1024:.1f} KB float32")
    print(f"\n=== TEST RESULTS ===")
    print(f"Test MSE:  {test_mse:.6f}")
    print(f"Test SNR:  {test_snr:.2f} dB")
    print(f"Test ENOB: {test_enob:.2f} bits")

    if test_snr < 14.0:
        print("WARNING: Test SNR below historical 14.0 dB analytical target")

    metrics = {
        "test_mse": test_mse,
        "test_snr": test_snr,
        "test_enob": test_enob,
        "best_epoch": best_ep,
        "best_val_loss": best_val_loss,
        "params": model.count_params(),
        "epochs_trained": epoch,
    }
    os.makedirs(args.model_dir, exist_ok=True)
    with open(os.path.join(args.model_dir, "train_metrics.json"), "w") as f:
        json.dump(metrics, f, indent=2)
    print(f"Metrics saved to {args.model_dir}/train_metrics.json")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Train MHDA MLP")
    parser.add_argument("--lr", type=float, default=0.0003)
    parser.add_argument("--epochs", type=int, default=150)
    parser.add_argument("--batch_size", type=int, default=2048)
    parser.add_argument("--weight_decay", type=float, default=1e-4)
    parser.add_argument("--patience", type=int, default=20)
    parser.add_argument("--seed", type=int, default=42)
    parser.add_argument("--qat_start", type=int, default=50)
    parser.add_argument("--data_dir", type=str, default="data")
    parser.add_argument("--model_dir", type=str, default="models")
    args = parser.parse_args()
    train(args)

"""
MHDA MLP model definition — 4-layer architecture: 8→128→384→128→1 (~100k params).
"""
# SPDX-License-Identifier: Apache-2.0

import torch
import torch.nn as nn

class StraightThroughQ15(torch.autograd.Function):
    @staticmethod
    def forward(ctx, x):
        return (x * 32768).round().clamp(-32768, 32767) / 32768.0
    @staticmethod
    def backward(ctx, grad):
        return grad

q15 = StraightThroughQ15.apply

class MHDA_MLP(nn.Module):
    def __init__(self):
        super().__init__()
        self.fc1 = nn.Linear(8, 128)
        self.fc2 = nn.Linear(128, 384)
        self.fc3 = nn.Linear(384, 128)
        self.fc4 = nn.Linear(128, 1)

    def forward(self, x):
        x = torch.tanh(self.fc1(x))
        x = torch.tanh(self.fc2(x))
        x = torch.tanh(self.fc3(x))
        x = self.fc4(x)
        return x

    def forward_quantized(self, x):
        x = torch.tanh(torch.nn.functional.linear(
            q15(x), q15(self.fc1.weight), q15(self.fc1.bias)))
        x = q15(x)
        x = torch.tanh(torch.nn.functional.linear(
            x, q15(self.fc2.weight), q15(self.fc2.bias)))
        x = q15(x)
        x = torch.tanh(torch.nn.functional.linear(
            x, q15(self.fc3.weight), q15(self.fc3.bias)))
        x = q15(x)
        x = torch.nn.functional.linear(
            x, q15(self.fc4.weight), q15(self.fc4.bias))
        return q15(x)

    def count_params(self):
        return sum(p.numel() for p in self.parameters())

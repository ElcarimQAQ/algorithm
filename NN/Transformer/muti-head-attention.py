import torch
from torch import nn
import torch.nn.functional as F

n_embd = 128
class Attention(nn.Module):
    def __init__(self, head_dim) -> None:
        super().__init__()
        self.softmax = nn.Softmax(dim=-1)
        self.query = nn.Linear(n_embd, head_dim)
        self.key = nn.Linear(n_embd, head_dim)
        self.value = nn.Linear(n_embd, head_dim)
        
    
    def forward(self, q: torch.Tensor, k: torch.Tensor ,v: torch.Tensor, mask=None):
        q = self.query(q)
        k = self.key(k)
        v = self.value(v)
        wei = q @ k.transpose(1, 2)
        _, _, d_k = k.shape
        wei = wei * d_k ** -0.5  
        # wei = wei / sqrt(d_k)
        if mask != None:
            wei = wei.masked_fill(mask == 0, float('-inf'))
        attn = self.softmax(wei) 
        # attn = F.softmax(wei, dim=-1)
        output = attn @ v
        return output

class MutiHeadAttention(nn.Module):
    def __init__(self, d_model, n_head):
        super(MutiHeadAttention, self).__init__()
        self.head_dim = d_model // n_head
        self.heads = nn.ModuleList([Attention(self.head_dim) for _ in range(n_head)])
        self.ffl = nn.Linear(d_model, d_model)
        
    def forward(self, q, k ,v, mask=None):
        out = torch.cat([h(q, k, v, mask) for h in self.heads], dim=-1)
        out = self.ffl(out)
        return out

batch_size = 128
seq_len = 512
nums_head = 4
q = torch.randn(batch_size, seq_len, n_embd)
k = torch.randn(batch_size, seq_len, n_embd)
v = torch.randn(batch_size, seq_len, n_embd)
att = MutiHeadAttention(n_embd, nums_head)
mask = torch.tril(torch.ones(seq_len, seq_len))
print(att(q, k ,v, mask).shape)

        
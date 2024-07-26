import torch
from torch import nn
import torch.nn.functional as F

class Attention(nn.Module):
    def __init__(self) -> None:
        super().__init__()
        self.softmax = nn.Softmax(dim=-1)
    
    def forward(self, q: torch.Tensor, k: torch.Tensor ,v: torch.Tensor, mask=None):
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
    
        
if __name__ == "__main__":
    batch = 32
    seq_len = 1024
    d_q = d_k = d_v = 128
    q = torch.randn(batch, seq_len, d_q)
    k = torch.randn(batch, seq_len, d_k)
    v = torch.randn(batch, seq_len, d_v)
    # torch.tril 函数用于将一个矩阵的上三角部分（不包括对角线）置为0，仅保留下三角部分。
    mask = torch.tril(torch.ones(seq_len, seq_len))
    model = Attention()
    print(model(q, k, v, mask).shape)
    
n, q = map(int, input().split())
ops = list(map(int, input().split()))
ans = []
for i in  range(1, n+1):
    ans.append(i)

for i in range(0, len(ops), 3):
    a = ops[i]
    b = ops[i + 1]
    op = ops[i + 2]
    ans.remove(a)
    idx = ans.index(b)
    if op == 0:
        ans.insert(idx, a)
    else:
        ans.insert(idx + 1, a)
        
print(' '.join(map(str, ans)))
    
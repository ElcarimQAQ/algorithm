from cmath import inf


q = int(input())
r = inf
l = -inf
for _ in range(q):
    m ,d = map(int, input().split())
    
    l = max(l, m-d)
    r = min(r, m+d)
    if l > r:
        print(-1)
        exit()

print(max(l,r))
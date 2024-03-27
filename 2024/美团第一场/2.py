import sys

n, q = map(int, sys.stdin.readline().split())
a = list(map(int, sys.stdin.readline().split()))
sumn = sum(a)
cnt = a.count(0)
while q:
    maxn, minn = 0, 0
    q -= 1
    l, r = map(int, sys.stdin.readline().split())
    maxn = sumn + cnt * r
    minn = sumn + cnt * l
    print(minn, maxn)


     

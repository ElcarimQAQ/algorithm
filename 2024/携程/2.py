n ,m, k = map(int, input().split())
a = list(map(int, input().split()))


a = sorted(a)
# print(a)

r = 0
res = 0

for l in range(n):
    while r + 1 < n and a[r + 1] - a[l] <= k and r - l <= m:
        r += 1
    if r >= n:
        break
    if r - l + 1 == m and a[r] - a[l] <= k:
        res += 1

print(n - res)
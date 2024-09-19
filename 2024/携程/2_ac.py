n ,m, k = map(int, input().split())
a = list(map(int, input().split()))
# m [2, 1e6] n [1, 1e6] k [1, 1e9]

a = sorted(a)
# print(a)

r = 0
res = 0

for i in range(n-m+1):
    if a[i+m-1] - a[i] <= k:
        res += 1

print(n - res)
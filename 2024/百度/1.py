t = int(input())

for _ in range(t):
    a, b ,c , d, K = map(int, input().split())
    ans = a*b*c*d
    for i in range(K+1):
        for j in range(K+1-i):
            for k in range(K+1-i-j):
                l = K - i -j - k
                pro = (a+i) * (b+j) * (c+k) * (d+l)
                ans = max(pro, ans)
    print(ans)  
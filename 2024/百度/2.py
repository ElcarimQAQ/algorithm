from cmath import inf


t = int(input())

for _ in range(t):
    n, K = map(int, input().split())
    a = list( map(int, input().split()))
    dp1 = [-inf] * (n+1)
    dp2 = [-inf] * (n+1)
    pre = [-inf] * (n+1)
    last = [-inf] * (n+1)
    
    dp1[0] = a[0]
    dp2[n-1] = a[n-1]
    pre[0] = a[0]
    last[n-1] = a[n-1]
    
    for i in range(1, n):
        dp1[i] = max(dp1[i-1]+a[i], a[i])
        pre[i] = max(pre[i-1], dp1[i])
        
    for i in range(n-2, -1, -1):
        dp2[i] = max(dp2[i+1]+a[i], a[i])
        last[i] = max(last[i-1], dp2[i])

    ans = -inf
    for i in range(n):
        j = i + K + 1
        if j >= n:
            break
        ans = max(ans, pre[i]+last[j])
    print(ans)
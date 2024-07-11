
n = int(input())

for m in range(n):
    a = input().split()
    # print(a)
    s1 = str(a[0])
    s2 = str(a[1])
    # print(f'{s} {target}')
    l1 = len(s1)
    l2 = len(s2)

    dp = [[1e5] * (l2+1) for _ in range(l1+1)]
    for i in range(l1+1):
        dp[i][0] = i
    for j in range(l2+1):
        dp[0][j] = j
    for i in range(l1):
        for j in range(l2):
            if s1[i] == s2[j]:
                dp[i+1][j+1] = dp[i][j]
            else:
                dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j], dp[i][j]) + 1   

    print(dp[l1][l2])
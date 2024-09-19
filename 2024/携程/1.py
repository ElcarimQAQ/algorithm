import sys
q  = int(input())
for _ in range(q):
    n, m , k = map(int, input().split())
    ans = 0
    cnt = 0
    # i [0, n-1]
    # j [0, m-1]
    i = j = 0
    while cnt < k:
        while i < n:
            i += 1
            if cnt == k or i == n:
                break
            cnt += 1
            ans += j + i * m
            # print('?')
            # print(i, j, ans)
        if cnt == k:
            break
        if  i == n:
            i -= 1
        while j < m:
            j += 1
            if cnt == k or j == m:
                break
            cnt += 1
            ans += j + i * m
            # print('*')
            # print(i, j, ans)
            
        if cnt == k:
            break
        if j == m:
            j -= 1
        j -= 1
        ans += j + i * m
        # print(i, j, ans)
        cnt += 1
    print(ans)
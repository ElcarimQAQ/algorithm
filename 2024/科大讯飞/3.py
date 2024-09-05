t = int(input())

a = []
b = []
i = 0
while  2**i <= 10**9:
    a.append(2**i)
    b.append(3**i)
    i += 1

cal = []
for i in a:
    for j in b:
        if i * j <= 10**9:
            cal.append(i*j)
        else:
            break
    if i * b[1] > 10**9:
        break
cal.sort(reverse=True)
# print(a, len(a))
# print(b, len(b))
# print(cal, len(cal))
for _ in range(t):
    n = int(input())
    nums = []
    ans = []
    cnt = 0 
    for i in range(len(cal)):
        if cal[i] <= n:
            nums.append(cal[i])
            if n >= cal[i]:
                n -= cal[i]
                ans.append(cal[i])
            if n == 0:
                break
    print(len(ans))
    print(*ans)    
    
    
    
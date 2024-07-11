import sys

# 计算Cnm全组合
def cal(n,m):
    res = 1
    for i in range(n-m+1,n+1):
        res *= i
    for i in range(1,m+1):
        res /= i
    return int(res)
        
        
for line in sys.stdin:
    a = str(line.split()[0])
    # print(a)
    set_str = {}
    # print(set_str)
    cnt = len(set_str)
    for i in a:
        if i not in set_str:
            cnt += 1
        set_str.setdefault(i,0)
        set_str[i] += 1
    # print(cnt)
    
    ans = 0
    for i in range(1, cnt+1):
        ans += cal(cnt, i)
    print(ans) 
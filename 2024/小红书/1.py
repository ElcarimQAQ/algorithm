mod = 10**9+7
def ksm(a, b):
    ans = 1
    a %= mod
    while b > 0:
        if b % 2:
            ans = ans * a % mod
        a = a * a % mod
        b //= 2
    return ans 
    

t = int(input())
for _ in range(t):
    n = int(input())
    s = str(input())
    max_n = max((int(c) for c in s))
    # print(max_n)
    min_n = min(int(c) for c in s)
    if max_n == 9 or min_n == 0:
        print(0)
    else:
        ans = ksm(10, n)
        a = ksm(10 -min_n, n)
        b = ksm(max_n+1, n)
        c = ksm(max_n - min_n+1, n)
        ans = (ans-a-b +c) % mod
        print(ans)
        # print(f'ans: {ans}')
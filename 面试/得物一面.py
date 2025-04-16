# encoding: utf-8
# a = input("please input a number:")
def slove(s):
    maxl = 1
    n = len(s)
    begin = 0
    dp = [[0]*n for _ in range(n)]
    for i in range(0 ,len(s)-1):
        if s[i] == s[i+1]:
            dp[i][i+1] = True
            maxl = 2
            begin = i
        else:
            dp[i][i+1] = False
        dp[i][i] = True

    for l in range(3, len(s)):
        for i in range(0, len(s)):
            r = i + l - 1 
            if r >= len(s):
                break
            if dp[i+1][r-1] and s[i] == s[r]:
                dp[i][r] = True
                maxl = max(maxl, l)
                begin = i
            else:
                dp[i][r] = False
    return s[begin:begin+maxl]

print(slove("babad"))

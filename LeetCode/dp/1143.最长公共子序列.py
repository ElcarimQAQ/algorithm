#
# @lc app=leetcode.cn id=1143 lang=python3
#
# [1143] 最长公共子序列
#

# @lc code=start
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        dp = [[0 for _ in range(len(text2)+1)] for _ in range(len(text1)+1)]
        for i in range(1, len(text1)+1):
            for j in range(1, len(text2)+1):
                if(text1[i-1] == text2[j-1]):
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        
        return dp[len(text1)][len(text2)]

# 优化为一个维度, 空间复杂度0(m)
class Solution:
    def longestCommonSubsequence(self, s: str, t: str) -> int:
        n = len(s)
        m = len(t)
        
        f = [0] * (m+1)
        for i, x in enumerate(s):
            pre = f[0]
            for j, y in enumerate(t):
                tmp = f[j+1]
                f[j+1] = pre + 1 if x == y else max(f[j], f[j+1])
                pre = tmp
        
        return f[m]
            
if __name__ == "__main__":
    s = Solution()
    print(s.longestCommonSubsequence("abcde", "ace"))
#
# @lc app=leetcode.cn id=1143 lang=python3
#
# [1143] 最长公共子序列
#

# @lc code=start
from functools import cache


class Solution:
    def longestCommonSubsequence(self, s: str, t: str) -> int:
        n = len(s)
        m = len(t)
        
        @cache
        def dfs(i, j):
            if i < 0 or j < 0:
                return 0
            if s[i] == t[j]:
                return dfs(i-1, j-1) + 1
            return max(dfs(i-1, j), dfs(i, j-1))
        
        return dfs(n-1, m-1)
         
if __name__ == "__main__":
    s = Solution()
    print(s.longestCommonSubsequence("abcde", "ace"))
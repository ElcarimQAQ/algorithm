#
# @lc app=leetcode.cn id=322 lang=python3
#
# [322] 零钱兑换
#
# https://leetcode.cn/problems/coin-change/description/
#
# algorithms
# Medium (48.50%)
# Likes:    2860
# Dislikes: 0
# Total Accepted:    879.4K
# Total Submissions: 1.8M
# Testcase Example:  '[1,2,5]\n11'
#
# 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
# 
# 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
# 
# 你可以认为每种硬币的数量是无限的。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：coins = [1, 2, 5], amount = 11
# 输出：3 
# 解释：11 = 5 + 5 + 1
# 
# 示例 2：
# 
# 
# 输入：coins = [2], amount = 3
# 输出：-1
# 
# 示例 3：
# 
# 
# 输入：coins = [1], amount = 0
# 输出：0
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= coins.length <= 12
# 1 <= coins[i] <= 2^31 - 1
# 0 <= amount <= 10^4
# 
# 
#

# @lc code=start
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        
        f = [[inf] * (amount+1) for _ in range(n+1)]
        f[0][0] = 0
        
        for i, x in enumerate(coins):
            for c in range(amount+1):
                if c < x:
                    f[i+1][c] = f[i][c]
                else:
                    f[i+1][c] = min(f[i][c], f[i][c-x]+1)
        ans = f[n][amount]
        return ans if ans < inf else -1
# @lc code=end
# 优化空间复杂度到O(amount)
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        
        f = [inf] * (amount+1) 
        f[0] = 0
        for x in coins:
            for c in range(x, amount+1):
                    f[c] = min(f[c], f[c-x]+1)
        ans = f[amount]
        return ans if ans < inf else -1


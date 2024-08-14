#
# @lc app=leetcode.cn id=494 lang=python3
#
# [494] 目标和
#
# https://leetcode.cn/problems/target-sum/description/
#
# algorithms
# Medium (48.30%)
# Likes:    1971
# Dislikes: 0
# Total Accepted:    477.1K
# Total Submissions: 979.9K
# Testcase Example:  '[1,1,1,1,1]\n3'
#
# 给你一个非负整数数组 nums 和一个整数 target 。
# 
# 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：
# 
# 
# 例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
# 
# 
# 返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
# 
# 
# 
# 示例 1：
# 
# 
# 输入：nums = [1,1,1,1,1], target = 3
# 输出：5
# 解释：一共有 5 种方法让最终目标和为 3 。
# -1 + 1 + 1 + 1 + 1 = 3
# +1 - 1 + 1 + 1 + 1 = 3
# +1 + 1 - 1 + 1 + 1 = 3
# +1 + 1 + 1 - 1 + 1 = 3
# +1 + 1 + 1 + 1 - 1 = 3
# 
# 
# 示例 2：
# 
# 
# 输入：nums = [1], target = 1
# 输出：1
# 
# 
# 
# 
# 提示：
# 
# 
# 1 <= nums.length <= 20
# 0 <= nums[i] <= 1000
# 0 <= sum(nums[i]) <= 1000
# -1000 <= target <= 1000
# 
# 
#

# @lc code=start
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        # p
        # s - p
        # p - (s-p) = t
        #2p = s+t
        target += sum(nums)
        if target < 0 or target % 2:
            return 0
        target //= 2
        
        n = len(nums)
        
        f = [[0] * (target+1) for _ in range(n+1)]
        f[0][0] = 1
        
        for i, x in enumerate(nums):
            for c in range(target+1):
                if c < x:
                    f[i+1][c] = f[i][c]
                else:
                    f[i+1][c] = f[i][c] + f[i][c-x]
        return f[n][target]

# 优化空间
class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        # p
        # s - p
        # p - (s-p) = t
        #2p = s+t
        target += sum(nums)
        if target < 0 or target % 2:
            return 0
        target //= 2
        
        n = len(nums)
        
        f = [[0] * (target+1) for _ in range(2)]
        f[0][0] = 1
        
        for i, x in enumerate(nums):
            for c in range(target+1):
                if c < x:
                    f[(i+1)%2][c] = f[i%2][c]
                else:
                    f[(i+1)%2][c] = f[i%2][c] + f[i%2][c-x]
        return f[n%2][target]

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        # p
        # s - p
        # p - (s-p) = t
        #2p = s+t
        target += sum(nums)
        if target < 0 or target % 2:
            return 0
        target //= 2
        
        n = len(nums)
        
        f = [0] * (target+1)
        f[0] = 1
        
        for i, x in enumerate(nums):
            for c in range(target, x-1, -1):
                f[c] = f[c] + f[c-x]
        return f[target]  
 

# @lc code=end


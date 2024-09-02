#
# @lc app=leetcode.cn id=209 lang=python3
#
# [209] 长度最小的子数组
#

# @lc code=start
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        ans = n+1
        s = 0
        left = 0
        # 枚举右端点写法
        for right, x in enumerate(nums):
            s += x
            while s - nums[left] >= target:
                s -= nums[left]
                left += 1
            if s >= target:
                ans = min(ans, right-left+1)
        return  ans if ans <= n else 0 
# @lc code=end

#
# @lc app=leetcode.cn id=209 lang=python3
#
# [209] 长度最小的子数组
#

# @lc code=start
# 第二种写法
class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n = len(nums)
        ans = n+1
        s = 0 
        left = 0
        for right, x in enumerate(nums):
            s += x
            # 单调性
            while s >= target:
                ans = min(ans, right-left+1)
                s -= nums[left]
                left += 1 # 至多是n次
        return  ans if ans <= n else 0 
# @lc code=end


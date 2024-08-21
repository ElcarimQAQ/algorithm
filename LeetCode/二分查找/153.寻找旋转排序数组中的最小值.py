#
# @lc app=leetcode.cn id=153 lang=python3
#
# [153] 寻找旋转排序数组中的最小值
#

# @lc code=start
from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        l = 0
        r = len(nums) - 1
        if(nums[r] >= nums[l]):
            return nums[l]
        while(l < r):
            m = l + r >> 1
            if(nums[m] > nums[r]):
                l = m + 1
            else:
                r = m
        
        return nums[l]
# @lc code=end

        
if __name__ == "__main__":
    nums = [2,1]
    print(Solution().findMin(nums))


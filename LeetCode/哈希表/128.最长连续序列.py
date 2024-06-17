#
# @lc app=leetcode.cn id=128 lang=python3
#
# [128] 最长连续序列
#
from typing import List
# @lc code=start
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        max_len = 0
        nums_set = set(nums)
        for num in nums:
            if((num - 1) in nums_set):
                continue
            st = num
            ll = 1
            while((st + 1) in nums_set):
                ll += 1
                st = st +1
            max_len = max(ll, max_len)
        return max_len        
# @lc code=end

if __name__ == "__main__":
    nums = [100,4,200,1,3,2]
    print(Solution().longestConsecutive(nums))
from typing import List


class Solution:
    def lower1(self, nums, target: int):
        # 闭区间 [left, right]
        l = 0
        r = len(nums) - 1
        while l <= r : # 区间不为空
            m = (l + r) // 2
            if nums[m] < target:
                l = m + 1
            else:
                r = m - 1
        return l
    
    def lower2(self, nums, target: int):
        # 左闭右开区间 [left, right]
        l = 0
        r = len(nums)
        while l < r : # 区间不为空
            m = (l + r) // 2
            if nums[m] < target:
                l = m + 1 # [mid+1, r)
            else:
                r = m  # [l, mid)
        return l
    
    def lower3(self, nums, target: int):
        # 左闭右开区间 (left, right)
        l = -1
        r = len(nums) 
        while l + 1 < r : # 区间不为空
            m = (l + r) // 2
            if nums[m] < target:
                l = m # (mid+1, r)
            else:
                r = m  # [l, mid)
        return l   
    
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        start = self.lower1(nums, target)
        if start == len(nums) or nums[start] != target:
            return [-1, -1]
        end = self.lower1(nums, target+1) - 1
        return [start, end]
    
nums = [5,7,7,8,8,10]
s = Solution()
print(s.searchRange(nums, 8))
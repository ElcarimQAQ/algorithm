from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        f1 = f0 = 0
        for i, x in enumerate(nums):
            new_f = max(f1, f0 + x)
            f0 = f1
            f1= new_f
        return f1
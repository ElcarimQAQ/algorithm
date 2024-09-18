from collections import Counter
from typing import List


class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        c = Counter(nums)
        ans = []
        for k ,v in c.items():
            if v == 2:
                ans.append(k)
        return ans

class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        for i in range(len(nums)):
            while nums[i] != nums[nums[i] - 1]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
                   
        return [num for i, num in enumerate(nums) if num-1 != i ]

      
nums = [4,3,2,7,8,2,3,1]
print(Solution().findDuplicates(nums))
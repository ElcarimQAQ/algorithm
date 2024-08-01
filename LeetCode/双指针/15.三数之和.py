from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans = []
        n = len(nums)
        for i in range(n - 2):
            x = nums[i]
            # 不相同
            if i > 0 and x == nums[i-1]:
                continue
            if x + nums[i+1] + nums[i+2] > 0:
                break
            if x + nums[-2] + nums[-1] < 0:
                continue
            j = i + 1
            k = n - 1
        
            while j < k:
                if x + nums[j] + nums[k] == 0:
                    ans.append([x, nums[j], nums[k]])
                    j += 1
                    while j < k and nums[j] == nums[j-1]:
                        j += 1
                    k -= 1
                    while j < k and nums[k] == nums[k+1]:
                        k -= 1
                elif x + nums[j] + nums[k] < 0:
                    j += 1
                else:
                    k -= 1
        return ans
             
from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        ans = 0
        l = 0
        r = len(height) - 1
        while l < r:
            ans = max(ans, (r - l) * min(height[l], height[r]))
            if height[l] > height[r]:
                r -= 1
            else:
                l += 1
        return ans

height = [1,8,6,2,5,4,8,3,7]
print(Solution().maxArea(height))
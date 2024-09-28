from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        pre_max = [0] * n
        end_max = [0] * n
        pre_max[0] = height[0]
        end_max[n - 1] = height[n - 1]
        for i in range(1, n):
            pre_max[i] = max(height[i], pre_max[i-1])
        for i in range(n - 2, -1, -1):
            end_max[i] = max(height[i], end_max[i+1])
        
        ans = 0
        for i in range(n):
            ans += min(pre_max[i], end_max[i]) - height[i]
        return ans

# 双指针优化空间复杂度
class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        ans = 0
        left = 0
        right = n - 1
        pre_max = height[0]
        end_max = height[n-1]
        while left <= right : # 相等可以算等于的位置的接水容量
            pre_max = max(pre_max, height[left])
            end_max = max(end_max, height[right])
            if pre_max < end_max:
                ans += min(pre_max, end_max) - height[left]
                left += 1
            else:
                ans += min(pre_max, end_max) - height[right]
                right -= 1
        return ans        
    
height = [0,1,0,2,1,0,1,3,2,1,2,1]
print(Solution().trap(height))
from typing import List
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def quick_sort(nums, left, right):
            base = nums[left]
            while left < right:
                while left < right and nums[right] <= base:
                    right -= 1
                nums[left] = nums[right]
                while left < right and nums[left] >= base:
                    left +=  1
                nums[right] = nums[left]
            nums[left] = base
            return left
        
        l = 0
        r = len(nums)-1
        while l <= r:
            p = quick_sort(nums, l, r)
            if p + 1 == k:
                return nums[p]
            elif p + 1 < k:
                l = p+1
            else:
                r = p-1



class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        def quick_sort(nums, left, right, k):
            if left >= right:
                return nums[k-1]
            base = nums[left]
            l = left
            r = right
            while left < right:
                while left < right and nums[right] <= base:
                    right -= 1
                while left < right and nums[left] >= base:
                    left +=  1
                nums[left], nums[right] = nums[right], nums[left] 
            nums[left], nums[l] = nums[l], nums[left]
            
            if k <= left:
                return quick_sort(nums, l, left-1, k)
            else:
                return quick_sort(nums, left+1, r, k)
        
        return quick_sort(nums, 0, len(nums) -1, k)

nums = [3,2,1,5,6,4]
k = 2
print(Solution().findKthLargest(nums, k)   )  
        
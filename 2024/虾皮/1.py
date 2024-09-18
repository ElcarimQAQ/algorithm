
#
# Note: 类名、方法名、参数名已经指定，请勿修改
#
#
# 
# @param nums int整型 一维数组 给定整数数组 nums
# @param k int整型  给定整数 k
# @return int整型
#
class Solution:
    def findKthLargest(self, nums, k) :
        # write code here
        nums.sort()
        return nums[-k]
print(Solution().findKthLargest([3,2,1,5,6,4], 2))
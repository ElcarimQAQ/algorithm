
nums = [12, 34, 52, 1, 45, 67, 98, -100, -80]

def quick_sort(nums, left, right):
    if  left >= right:
        return
    # print(nums)
    base = nums[left]
    l = left
    r = right
    while left < right:
        while left < right and nums[right] <= base:
            right -= 1
        while left < right and nums[left] >= base:
            left += 1
        nums[left], nums[right] = nums[right], nums[left]
    
    nums[left], nums[l] = nums[l], nums[left]
    
    quick_sort(nums, l, left-1)
    quick_sort(nums, left+1, r)

quick_sort(nums, 0, len(nums) - 1)

print(nums)
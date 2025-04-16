def slove(nums):
    left = 0
    ans = 1
    pr = 1
    for right, x in enumerate(nums):
        pr *= x
        ans = max(ans, pr)
        if pr < ans:
            left += 1
            pr /= nums[left]
    return ans

nums = [2,3,-2,4]
print(slove(nums))
n = int(input())

def slove(nums, base):
    cnt = 0
    while(nums > 0):
        i = nums % base
        if i == 1:
            cnt += 1
        # print(nums)
        nums = nums // base
    return cnt

ans = 0
for i in range(2, 37):
    cnt = slove(n, i)
    ans = max(ans, cnt)
print(ans)
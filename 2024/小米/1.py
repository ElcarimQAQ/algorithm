n = int(input())
a = map(int, input().split())

def slove(a):
    ans = 0
    cnt = 0
    max_neg = -10**10
    min_pos = 10**10
    pos = []
    neg = []
    for i, x in enumerate(a):
        if x < 0:
            cnt += 1
            max_neg = max(max_neg, x)
            neg.append(x)
        else:
            min_pos = min(min_pos, x)
            pos.append(x)
            ans += x
    # print(ans)
    neg_sum = sum(abs(x) for x in neg)
    # print(neg_sum)
    if cnt == 0:
        return ans
    elif cnt % 2 == 0:
        ans += neg_sum
        return ans
    else:
        ans += neg_sum
        if  min_pos != 10**10:
            ans -= 2 * min_pos
        else:
            ans -= 2 * abs(max_neg)
        return ans
        
ans = slove(a)
print(ans)
    
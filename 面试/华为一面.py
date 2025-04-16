from collections import Counter

def slove(s):
    ans = 0
    cnt = Counter()
    left = 0
    
    for right, c in enumerate(s):
        cnt[c] += 1
        while cnt[c] > 1:
            cnt[s[left]] -= 1
            left += 1
        ans = max(ans, right - left + 1)
    return ans

print(slove("abcabcbb"))  
print(slove("bbbbb"))
print(slove("pwwkew"))
        
    
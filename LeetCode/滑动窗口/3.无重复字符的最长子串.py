#
# @lc app=leetcode.cn id=3 lang=python3
#
# [3] 无重复字符的最长子串
#

# @lc code=start
from collections import Counter


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # 时间复杂度 O(N)
        # 空间复杂度 O(len(set(s)))
        ans = 0
        cnt = Counter()
        left = 0
        for right, c in enumerate(s):
            cnt[c] += 1
            while cnt[c] > 1:
                cnt[s[left]] -= 1
                left += 1
            ans = max(ans, right-left+1)
        return ans        
# @lc code=end

s = "abcabcbb"
print(Solution().lengthOfLongestSubstring(s))
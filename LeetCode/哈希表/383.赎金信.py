#
# @lc app=leetcode.cn id=383 lang=python3
#
# [383] 赎金信
#

# @lc code=start
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        m1 = {}
        for i in magazine:
            if i not in m1:
                m1[i] = 1
            else:
                m1[i] = m1[i] + 1
        
        for i in ransomNote:
            if i in m1:
                m1[i] = m1[i] - 1
                if m1[i] < 0 :
                    return False
            else:
                return False    
        return True
                
# @lc code=end


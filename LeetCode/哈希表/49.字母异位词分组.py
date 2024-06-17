#
# @lc app=leetcode.cn id=49 lang=python3
#
# [49] 字母异位词分组
#
from typing import Dict, List

# @lc code=start
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
# @lc code=end
        ans_dict: Dict[str, List[int]] = {}
        ans: List[List[str]] = []
        for i in range(len(strs)):
            ss = ''.join(sorted(strs[i]))
            ans_dict.setdefault(ss, []).append(i)
        
        for ss in ans_dict:
            ans2 = []
            for i in ans_dict[ss]:
                ans2.append(strs[i])
            ans.append(ans2)
        return ans
            
        
        
if __name__ == "__main__":
    strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
    print(Solution().groupAnagrams(strs))
        

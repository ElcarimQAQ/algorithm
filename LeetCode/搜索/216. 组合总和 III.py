from typing import List


class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        ans = []
        path = []
        
        def dfs(i, t):
            if len(path) == k and t == 0:
                ans.append(path.copy())
                return
            d = k - len(path)
            if t < 0 or t > (i + 10) * (d+1) // 2:
                return
            if 10 - i + 1 < d:
                return
            
            for j in range(i, 10-d):
                path.append(j)
                dfs(j+1, t-j)
                path.pop()
        
        dfs(1, n)
        return ans

print(Solution().combinationSum3(3, 7))
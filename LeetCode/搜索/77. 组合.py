from typing import List
class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ans = []
        path = []
        
        def dfs(i):
            if len(path) == k:
                ans.append(path.copy())
                return
            if n - i + 1 < k - len(path):
                return
            for j in range(i, n+1):
                path.append(j)
                dfs(j+1)
                path.pop()
        
        dfs(1)
        return ans
    
print(Solution().combine(4, 2))
            
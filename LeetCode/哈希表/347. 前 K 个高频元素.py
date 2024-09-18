from collections import Counter
from typing import List
import heapq


class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        c = Counter(nums)
        
        q = [] 
        for key, v in c.items():
            heapq.heappush(q, (v, key))
            if len(q) > k:
                heapq.heappop(q) 
        return [item[1]  for item in q] 

nums = [1,1,1,2,2,3]
print(Solution().topKFrequent(nums, 2))
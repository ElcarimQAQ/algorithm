from typing import List
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        ans: List[List[int]] = []
        
        intervals.sort(key=lambda x:x[0])
        la = intervals[0]
        for i in range(1, len(intervals)):
            if la[1] >= intervals[i][0]:
                if(la[1] >= intervals[i][1]):
                    la[1] = la[1]
                else:
                    la[1] = intervals[i][1]
                if la[0] >= intervals[i][0]:
                    la[0] = intervals[i][0] 
            else:
                ans.append(la)
                la = intervals[i]
        ans.append(la)
        return ans
            
if __name__ == "__main__":
    s = Solution()
    intervals = [[1,3],[2,6],[8,10],[15,18]]
    print(s.merge(intervals))
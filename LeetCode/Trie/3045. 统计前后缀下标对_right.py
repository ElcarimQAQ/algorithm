from typing import List


class Node:
    def __init__(self):
        self.son = dict()
        self.cnt = 0
        
class Solution:
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        root = Node()
        ans = 0
        for word in words:
            cur = root
            for p in zip(word, word[::-1]):
                if p not in cur.son:
                    cur.son[p] = Node()
                cur = cur.son[p]
                #  前面有cnt 个词数可以配对
                ans += cur.cnt 
            #  词加一
            cur.cnt += 1
        return ans

if __name__ == "__main__":
    words = ["a","aba","ababa","aa"]
    print(Solution().countPrefixSuffixPairs(words))
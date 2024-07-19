class Solution:
    idx1 = 0
    idx2 = 0
    def insert(string s):
        p1 = 0
        p2 = 0
        j = len(s) - 1
        for i in range(len(s)):
            u = s[i] - 'a'
            v = s[j] - 'a'
            if not son1[p1][u]:
                idx1 = idx1 + 1
                son1[p1][u] = idx1
            p1 = son1[p1][u]
            if not son2[p2][v]:
                idx2 = idx2 + 1
                son2[p2][v] = idx2
            p2 = son2[p2][v]
        cnt[p1] += 1
    
    def query(string s):
        p1 = 0
        p2 = 0
        for i in range(len(s)):
            u = s[i] - 'a'
            v = s[j] - 'a'
            if not son1[p1][u] and not son2[p2][v]
                return 0
            p1 = son1[p1][u]
            p2 = son2[p2][v]
        return cnt[p1]  
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        for word in words:
            insert(word)
        
        ans = 0
        for word in words:
            ans += query(word1)
        return ans
                
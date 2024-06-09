/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_set<char> mp;
    int lengthOfLongestSubstring(string s) {
        // mp.clear();
        if (s.size() == 0)
            return 0;
        int l = 0,len = 0;
        for(int i = 0;i < s.size(); i++){
            char c = s[i];
           
            while(mp.find(c) != mp.end()){
                mp.erase(s[l]);
                l++;
            }
            mp.insert(c);
            len = max(len, i - l + 1);         
        }
        return len;
    }
};
// @lc code=end

int main()
{
    Solution s;
    // cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    // cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << s.lengthOfLongestSubstring("pwwkew") << endl;
    cout<<s.lengthOfLongestSubstring("au")<<endl;
    return 0;
}

/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
bool dp[1005][1005];

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2 ) return s;
        int maxl = 1;
        int begin = 0;
        for(int i = 0 ;i < s.size();i++){
            if(s[i] == s[i+1] && i <s.size()-1){  
                dp[i][i+1] = true;
                maxl = 2;
                begin = i;
            }
            else
                dp[i][i+1] = false;
            dp[i][i] = true;
        }
        int l=0,r=0;
        // 长度从小到大
        for(l = 3; l <= s.size(); l++){
            for(int i = 0;i < s.size();i++){
                r = i +  l - 1;
                if(r >= s.size()) break;
                if(dp[i+1][r-1] && s[i] == s[r]) {
                    dp[i][r] = true;
                    if(l > maxl){
                        begin = i;
                        maxl = l;
                    }
                }
                else dp[i][r] = false;
            }
        }
        return s.substr(begin, maxl);
    }
};
// @lc code=end

int main()
{
    Solution s = Solution();
    cout<<s.longestPalindrome("aaaaaa");
    return 0;
}
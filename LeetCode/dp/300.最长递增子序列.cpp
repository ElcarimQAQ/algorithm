/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int dp[10005];
    int lengthOfLIS(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            dp[i] = 1;
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int ans = 0;
        for(auto u:dp){
            ans = max(ans, u);
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution s = Solution();
    vector<int> nums = {0,1,0,3,2,3};
    cout<<s.lengthOfLIS(nums)<<endl;
    return 0;
}


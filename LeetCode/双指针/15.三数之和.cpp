/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i = 0;i <nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = nums.size() - 1;
            while ( j  < k)
            {
                if(nums[i] + nums[j] + nums[k] < 0)
                    j++;
                else if(nums[i] + nums[j] + nums[k] > 0)
                    k--;
                else{
                    vector<int> cur = {nums[i], nums[j], nums[k]};
                    ans.push_back(cur);
                    while(j < k && nums[j] == nums[j+1]) j++;
                    while (k > j && nums[k-1] == nums[k]) k--;
                    j++;
                    k--;
                }
            }  
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    vector<int> nums = {-1,0,1,2,-1,-4};
    Solution s = Solution();
    
    return 0;
}


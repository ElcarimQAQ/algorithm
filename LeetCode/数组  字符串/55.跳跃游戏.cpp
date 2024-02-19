/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int idx = 0;
        for(int i = 0; i < nums.size(); i++){
             if (i > idx)
                break;
            idx = max(idx, i + nums[i]);
        }
        cout<<idx<<endl;
        if(idx >= nums.size() - 1)
            return true;
        else
            return false;
    }
};
// @lc code=end

int main()
{
    Solution s;
    s = Solution();
    vector<int> num = {2,3,1,1,4};
    cout<<s.canJump(num)<<endl;
    return 0;
}


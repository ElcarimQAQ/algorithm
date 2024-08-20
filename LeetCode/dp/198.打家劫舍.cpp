//
// Created by lbyang on 23-10-25.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int dp[150][2];
        dp[0][0] = nums[0];
        dp[0][1] = 0;
        for(int i = 1;i < nums.size(); i++) {
            dp[i][0] = max(dp[i - 1][1] + nums[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]);
        }
        return max(dp[nums.size()-1][0], dp[nums.size()-1][1]);
    }
};
//
// Created by lbyang on 23-9-15.
//
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int pre_cnt = 0, pre;
        pre = nums[0];
        pre_cnt++;
        for(int i = 1;i < nums.size(); i++) {
            if(pre_cnt == 0)
                pre = nums[i];
            if(pre == nums[i])
                pre_cnt++;
            else
                pre_cnt--;
        }

        return pre;
    }
};
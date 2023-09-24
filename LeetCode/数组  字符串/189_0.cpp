//
// Created by lbyang on 23-9-21.
//
#include <bits/stdc++.h>
using namespace std;
vector<int> ans;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        ans.clear();
        int l = nums.size();
        int cnt = k % l;
        int i = nums.size() - cnt;
        while(i < nums.size() && ans.size() <= cnt){
            ans.push_back(nums[i]);
            i++;
        }
        for(int j = 0; j < nums.size() - cnt; j++) ans.push_back(nums[j]);
        nums = ans;
    }
};
//
// Created by lbyang on 23-9-21.
//
#include <bits/stdc++.h>
using namespace std;
vector<int> ans;


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int l = nums.size();
        int cnt = k % l;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + cnt);
        reverse(nums.begin() + cnt, nums.end());
    }
};
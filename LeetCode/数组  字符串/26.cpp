//
// Created by lbyang on 23-9-14.
//
#include <bits/stdc++.h>

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx1 = 0, idx2 = 0;
        while(idx2 + 1< nums.size()){
            if(nums[idx1]+nums[idx1+1] != nums[idx2]+nums[idx2+1] ) {
                idx1++;
                nums[idx1+1] = nums[idx2+1];
            }
            idx2++;
        }
        return idx1+2 <nums.size() ? idx1+2 :nums.size() ;
    }
};
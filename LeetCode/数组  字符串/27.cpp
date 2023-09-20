//
// Created by lbyang on 23-9-13.
//

#include <bits/stdc++.h>

using namespace std;
vector<int> nums;
int val;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx1 = 0, idx2 = 0;
        while(idx1 < nums.size() && idx2 < nums.size()) {
            if(nums[idx2] != val) {
                nums[idx1] = nums[idx2];
                idx1++;
            }
            idx2++;
        }
        return  idx1;
    }
};

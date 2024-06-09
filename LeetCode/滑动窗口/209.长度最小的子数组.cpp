#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int hh = 0, tt =-1, sum = 0, l = nums.size();
        int q[100005];
        for(int i = 0;i <= nums.size();i++) {
            while(hh <= tt && sum >= target) {
                l = min(l, tt-hh + 1);
                sum -= q[hh];
                hh++;
            }
            if(i == nums.size())
                break;
            q[++tt] = nums[i];
            sum += nums[i];
        }
        if (hh == 0)
            return 0;
        return l;
    }
};
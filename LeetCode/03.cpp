#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findRepeatNumber(vector<int>& nums) {
            for(int i = 0;i < nums.size() ;i++ ){
                nums[i] = nums[i]+1;
                int x = abs(nums[i]);
                if(nums[x] < 0) return x -1;
                nums[x] = -abs(nums[x]);
            }
        }

};

// int main()
// {
//     Solution s ;
//     vector<int> nums = {1,3,2,1};
//     cout<<s.findRepeatNumber(nums)<<endl;;
//     return 0;
// }
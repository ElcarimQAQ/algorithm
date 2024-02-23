/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int mid = l + r >> 1;
            cout<<"idx"<<mid<<"mid"<<nums[mid]<<endl;
            if(nums[mid] == target){
                int s = -1, e =-1;
                for(int j = l; j <= r; j++){ 
                    if(nums[j] == target && s == -1) 
                        s = j;
                    if(nums[j] == target) 
                        e = j;
                //     if(nums[j] != target && s != -1 && e == -1)
                //         e = j;
                }
                cout<<s<<" "<<e<<endl;
                return {s,e};
            }
            else if(nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        if(nums.size() != 0 &&nums[l] == target)
            return {l,l};
        return {-1,-1};
    }
};
// @lc code=end

int main()
{
    Solution solve;
    vector<int> nums = {5,7,7,8,8,10};
    vector<int> res = solve.searchRange(nums, 8);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}

/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // int find(int l,int r, vector<int>& nums){
    //     int mid = l + r >> 1;
    //     if(l == r) return l;
    //     if(nums[mid]> nums[mid-1] && nums[mid]  > nums[mid+1]) return mid; 
    //     if(nums[mid] > nums[mid-1])
    //         return find(mid+1, r, nums);
    //     else
    //         return find(l, mid-1, nums); 
    // }

    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid;
        while(l < r){
            mid = l + r >> 1;
            if(mid > 0 && mid < nums.size() - 1 && nums[mid]> nums[mid-1] && nums[mid]  > nums[mid+1]) return mid; 
            if(nums[mid] < nums[mid+1]) l = mid+1;
            else r = mid;
        }
        return l;
    }
};
// @lc code=end

int main()
{
    Solution s = Solution();
    vector<int> num = {2,1};
    cout<<s.findPeakElement(num)<<endl;
    return 0;
}
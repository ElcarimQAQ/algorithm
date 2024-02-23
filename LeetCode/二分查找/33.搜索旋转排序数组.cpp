/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include<bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1, mid;
        if(nums[l] == target) return l;
        if(nums[r] == target) return r;
        while(l < r) {
            cout<<l<<" "<<r<<endl;
            mid = l + r >> 1;
            cout<<mid<<"**"<<nums[mid]<<endl;
            if(nums[mid] == target) return mid;
            
            if (nums[mid] < nums[r]){
                if(target > nums[mid] && target < nums[r])
                    l = mid+1;
                else
                    r = mid;
            }
            else {
                if(target <  nums[mid] && target > nums[0])
                    r = mid;
                else l = mid+1;
            }
        }
        return -1;
    }
};
// @lc code=end

int main()
{
    Solution s = Solution();
    vector<int> nums = {1,3};
    cout<<s.search(nums, 3)<<endl;
}

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0, r = nums.size() -1, mid;
        while(l < r) {
            mid = l + r >> 1;
            if(nums[mid] == target) return mid;
            else if (nums[mid] > target) r = mid;
            else l = mid+1;
        }
        cout<<l<<r<<endl;
        if (l == nums.size() -1 && nums[l] < target)
            l = nums.size();
        return l;
    }
};

int main()
{
    Solution s;
    vector<int> num = {1, 3, 5, 6};
    s.searchInsert(num, 7);
    return 0;
}
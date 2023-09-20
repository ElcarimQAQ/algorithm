#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;
vector<int> nums1, nums2;
int m, n;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> num;
        int l1 = 0, l2= 0;
        while(l1 < m && l2  < n) {
            if (nums1[l1] <= nums2[l2]) {
                num.push_back(nums1[l1]);
                l1++;
            }
            else{
                num.push_back(nums2[l2]);
                l2++;
            }
        }
       while(num.size() < m + n) {
           if (l1 == m) {
               num.push_back(nums2[l2]);
               l2++;
           }
           else{
               num.push_back(nums1[l1]);
               l1++;
           }
       }
       for(int i =0 ;i < m +n ;i++){
           nums1[i] = num[i];
       }
    }
};
 
int main() {
    nums1 = {1,2,3,0,0,0};
    nums2 = {2,5,6};
    m = n =3;
    Solution s = Solution();
    s.merge(nums1, m, nums2, n);
    return 0;
}
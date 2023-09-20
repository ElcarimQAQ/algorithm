#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        list<int> num1, num2;
        for(int i = 0; i < m; i++) 
            num1.push_back(nums1[i]);
        for(int i = 0; i < n; i++) 
            num2.push_back(nums2[i]);
        int i, j= 0;
        while(i< m  || j < n) {
            if (nums1[i] <= nums2[j]) {
                num1.insert(next(num1.begin()), nums2[j]);
                j++;
            }
            else {
                num1.insert(prev(num1.begin()), nums2[j]);
                i++;
            }
        }
        int idx = 0;
        for (auto c: num1)
            nums1[idx++] = c;
    }
};
 
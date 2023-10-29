#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;  
        int l = 0, r = height.size() -2;
        int lmax = 0, rmax =height[height.size() -1];
        while(l <= r) {
            lmax = max(lmax , height[l]);
            rmax = max(rmax, height[r]);
            if(lmax > rmax){
                ans += max(lmax - height[r], 0);
                r--;
            }
            else{
                ans += max(rmax - height[l], 0);
                l++;
            }

        }
        return ans;
    }
};

int main() {
    vector<int> h ={0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    int ans = s.trap(h);
    cout<<ans;
}
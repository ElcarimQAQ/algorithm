#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int dp[maxn][2];
        dp[0][0] = 0;
        dp[height.size() - 1][1] = 0;
        for(int i = 1;i <height.size(); i++)
            dp[i][0] = max(height[i-1], dp[i-1][0]);
        for(int i = height.size()-2;i >= 0; i--)
            dp[i][1] = max(height[i+1], dp[i+1][1]);
        for(int i = 0; i< height.size(); i++)
            ans += max(0, min(dp[i][0], dp[i][1]) - height[i]);

        return ans;
    }
};

int main() {
    vector<int> h ={0,2,0};
    Solution s;
    int ans = s.trap(h);
    cout<<ans;
}
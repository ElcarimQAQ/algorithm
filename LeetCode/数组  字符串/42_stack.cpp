#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int trap(vector<int>& height) {
    int l = 0, r = 0, ans = 0;
    stack<int> st;

    for(int i = 0; i < height.size(); i++){
        while(!st.empty() && height[i] > height[st.top()]){
            int cur = st.top();
            st.pop();
            if (st.empty()) break;
            int r = i;
            int l = st.top();
            int h = min(height[l], height[r]) - height[cur];
            ans += (r - l -1)*h;
        }
        st.push(i);
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
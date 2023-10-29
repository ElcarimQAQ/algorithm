#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> profit;
        for(int i = 1; i < prices.size(); i++) {
            profit.push_back(prices[i] - prices[i-1]);
        }
        int ans = 0;
        for(auto p: profit){
            if(p > 0){
                ans+=p;
            }
        }
        return ans;
    }
};

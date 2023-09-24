//
// Created by lbyang on 23-9-24.
//
#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int idx_min = 0,ans = 0;
        for(int i =0; i < prices.size(); i++) {
            if(prices[idx_min] > prices[i])
                idx_min = i;
            ans = max(ans, prices[i] - prices[idx_min]);
        }
        return ans;
    }
};
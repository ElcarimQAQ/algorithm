#include <bits/stdc++.h>
using namespace std;
const int  maxn = 2005;
class Solution {
    int f[maxn][maxn];
    vector<int> p;
    public:
    int dp(int i,int j)
    {
        if(f[i][j] != -1)
            return f[i][j];
        f[i][j] = 0;
        for(int k = max(1,j - 1);k <= j + 1;k++){
            int x = p[i] - k;
            if(dp(x,k)){
                f[i][j] = 1;
                break;
            }
        }
        return f[i][j];
    }
    bool canCross(vector<int>& stones) {
        p = stones;
        unordered_map <int,int> hash;
        for(int i =0;i < stones.size();i++)
            hash[stones[i]] = i;
        f[0][1] = 1;
        for(int i = 0;i <= stones.size() ; i++){
            memset(f,-1,sizeof(f));
            if(dp(stones.size() - 1,i))
                return true;
        }
        return false;
    }
};
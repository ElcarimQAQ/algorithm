#include <bits/stdc++.h>
using namespace std;


class Solution {
    typedef long long ll;
    map<ll,int> vis;
    public:
        bool judgeSquareSum(ll c) {
            while(c > 0){
                int f = 1;
                for(int i = 2;i <= sqrt(c) ; i++){
                    if(c % i == 0){
                        vis[i]++;
                        c = c/i;
                        f = 0;
                        break;
                    }
                }
                if(f){
                    vis[c]++;
                    break;
                }
            }
            for(auto i :vis){
                if(i.first % 4 == 3 && (i.second & 1 == 0))
                    return true;
            }
            return false;
        }
};
// 本题为考试多行输入输出规范示例，无需提交，不计分。
#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 5e6+5;
int a[maxn],dp[maxn];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;++i)
        cin>>a[i];
    dp[0] = 0;
    for(int i = 1;i <= maxn -5;i++)
        dp[i] = -1;
    for(int i = 0;i <= maxn - 5;i++){
        for(int j = 1;j<= n;++j){
            int t = i- a[j];
            // if(t == 850) {
            //     cout<<"?"<<endl;
            // }
            if(t < 0) continue;
            if(dp[t]  == -1) continue;
            // cout<<i<<endl;
            if(dp[t] >> (j-1) & 1) continue;
            if(i >= m) {
                cout<<i<<endl;
                return 0;
            }
            dp[i] = 0;
            dp[i] |= (1 << (j-1));
            // cout<<dp[t]<<endl; 
        }
    }
    return 0;
}
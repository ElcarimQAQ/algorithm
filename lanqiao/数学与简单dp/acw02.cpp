#include<bits/stdc++.h>
using namespace std;
const int maxn  = 1005;
int v[maxn],w[maxn];
int dp[maxn][maxn];
int main()
{
    int n,vv;
    cin>>n>>vv;
    for(int i = 1;i <= n; i++){
        cin>>v[i]>>w[i];
    }
    for(int i = 1;i <= n; i++){
        for(int j = 0;j <= vv;j++){
            if(j - v[i] >= 0)
                dp[i][j] = max(dp[i - 1][j],dp[i - 1][j - v[i]] + w[i]);
            else
                dp[i][j] = dp[i -1][j];
        }
    }
    cout<<dp[n][vv]<<endl;
    return 0;
}
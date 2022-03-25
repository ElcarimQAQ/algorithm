#include <bits/stdc++.h>
using namespace  std;
const int maxn = 1e7;
int dp[maxn];

int main()
{
    int n,m;
    cin>>n>>m;
    dp[n] = 1,dp[m] = 1;
    int ans = 0;
    for(int i = 1 ;i <= maxn ;i++){
        //cout<<i<<endl;
        if((i>= n && dp[i - n] == 1)|| (i>= m && dp[i - m]) ){
            dp[i] = 1;
            //cout<<"?"<<endl;
        }
        if(dp[i] == 0)
            ans = i;
    }
    cout<<ans<<endl;
    return 0;
} 
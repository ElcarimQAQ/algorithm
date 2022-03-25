#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=1005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
ll a[maxn][maxn];
ll dp[maxn][maxn][2];
ll dp2[maxn][maxn][2];

ll popcnt(ll x)
{
    ll cnt = x;
    while(x) {
        if(x & 1)
            cnt++;
        x >>= 1;
    }
    return cnt;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 1; i <= n ;i++)
        for(int j = 1; j <= m; j++)
            cin>>a[i][j];
    ll ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 2; j <= m ;j++ ){
            dp[i][j][0] = max(dp[i][j-1][0],dp[i][j-1][1] + popcnt(a[i][j] ^ a[i][j-1]));
            dp[i][j][1] = max(dp[i][j-1][1],dp[i][j-1][0]);
        }
        ans += max(dp[i][m][0],dp[i][m][1]);
    }
    for(int j = 1; j <= m; j++){
        for(int i = 2; i <= n ;i++ ){
            dp2[i][j][0] = max(dp2[i-1][j][0],dp2[i-1][j][1] + popcnt(a[i-1][j] ^ a[i][j]));
            dp2[i][j][1] = max(dp2[i-1][j][1],dp2[i-1][j][0]);
        }
        ans += max(dp2[n][j][0],dp2[n][j][1]);
    }
    cout << ans << endl;
    return 0;
}
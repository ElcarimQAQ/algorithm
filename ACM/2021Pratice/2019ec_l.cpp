#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=100005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
int a[105],b[105],c[105];
int dp[105][105][10005];
int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i = 1;i <= n ;i++)
            cin>>a[i]>>b[i]>>c[i];
        dp[1][1][n] = a[n];
        for(int i = n -1 ; i >= 1;i--){
            for(int j = 1 ; j < n ; j++){
                int down = (i + i + j) * (j-1) / 2 + n,up = (n + n - j + 1) / 2;
                for(int k = n; ; ){
                    dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j - 1][k - i] + a[i]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j][k] + (k - i * j) * b[i]);
                    dp[i][j][k] = max(dp[i][j][k], dp[i + 1][j][k] + k * c[i]);
                }
            }
        }
    }
    return 0;
}
#include<bits/stdc++.h>
#include <algorithm>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=5e5+7;
typedef long long ll;
const int mod=1e9+7;
#define pi acos(-1)
#define INF 0x3f3f3f3f
int a[maxn],b[maxn];
int dp[maxn][3];

int main ()
{
    int n,y;
    cin>>n>>y;
    for(int i = 1; i <= n;i++){
        cin>>a[i];
        //a[i] %= y;
    }
    for(int i = 1; i <= n;i++){
        cin >> b[i];
        //b[i] %= y;
    }
    int sum = 0;
    for(int i = 1 ; i <= n;i++){
        int t = max(dp[i-1][0],dp[i-1][1]);
        t =  max(t,dp[i-1][2]);
        dp[i][0]= (t + a[i] + b[i]) % y;
        dp[i][1]= (t + a[i] - b[i]) % y;
        dp[i][2]= (t + a[i] ) % y;
    }
    cout <<max(max(dp[n][0],dp[n][1]),dp[n][2])<< endl;
	return 0;
}

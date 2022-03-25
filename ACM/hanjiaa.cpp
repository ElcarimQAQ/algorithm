#include<bits/stdc++.h>
#include <algorithm>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=1e6+7;
typedef long long ll;
const int mod=1e9+7;
#define pi acos(-1)
#define INF 0x3f3f3f3f
ll dp[maxn];

int main ()
{
    //freopen("data.in", "r", stdin);
    //freopen("1.out", "w", stdout);	
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    dp[2]=1;
    for(int i=2;i<n;i++){
        dp[i+1]=(dp[i]*(i+1)*26-i+dp[i])%mod;
    }
    cout<<dp[n]<<endl;
    return 0;
}

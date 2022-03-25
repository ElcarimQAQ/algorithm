#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=60005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
int r[maxn];
int dp[maxn][2];
vector<int> g[maxn];
void dfs(int u,int fa)
{
    dp[u][1] = r[u];
    dp[u][0] = -INF;
    for(int i =0; i< g[u].size(); i++){
        int v = g[u][i];
        if(v == fa)
            continue;
        dfs(v,u);
        dp[u][1] = max(dp[u][1], dp[u][1] + dp[v][0]); 
        if(dp[u][0] == -INF) dp[u][0] = max(dp[v][1],dp[v][0]);      
        else dp[u][0] = max(dp[u][0], dp[u][0] + max(dp[v][1],dp[v][0]));
    }
}

int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    for(int i = 1;i <= n; i++)
        cin>>r[i];
    int l,k;
    int r = (1 + n) * n / 2;
    for(int i =1; i < n; i++){
        cin>>l>>k;
        r -= l;
        g[l].push_back(k);
        g[k].push_back(l);
    }
    // cout<<r<<endl;
    dfs(r,-1);
    cout<<max(dp[r][0],dp[r][1])<<endl;
    return 0;
}
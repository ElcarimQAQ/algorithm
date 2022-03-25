#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=2005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
ll hp[maxn];
ll dp[2][maxn][maxn];
ll siz[maxn];
vector<int> g[maxn];

void dfs(int u,int fa){
    dp[1][u][1] = hp[u];
    dp[0][u][0] = 0; 
    siz[u] = 1;
    for(int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i];
        if(v == fa)
            continue;
        dfs(v,u);
        for(int j = siz[u]; j >= 0; j--){
            for(int k = siz[v]; k >= 0; k--){
                dp[0][u][j + k] = min(dp[0][u][j + k], dp[0][u][j] + min(dp[0][v][k], dp[1][v][k]));
                dp[1][u][j + k] = min(dp[1][u][j + k], dp[1][u][j] + min(dp[0][v][k], dp[1][v][k] + hp[v]));
            }
        }
        siz[u] = siz[u] + siz[v];
    }
}

void init(int n){
    for(int i = 1;i <= n; i++){
        g[i].clear();
        siz[i] = 0;
    }
    for(int i = 0;i <= n; i++)
        for(int j = 0; j <= n; j++)
            dp[0][i][j] = dp[1][i][j] = 1e18;
}

int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
    ios::sync_with_stdio(false); cin.tie(0);
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n;
        init(n);
        int v;
        for(int i = 2 ;i <= n;i++){
            cin>>v;
            g[i].push_back(v);
            g[v].push_back(i);
        }
        for(int i =1 ;i <= n;i++)
            cin>>hp[i];
        dfs(1,-1);
        for(int i = n; i >= 0; i--)
            cout<<min(dp[0][1][i], dp[1][1][i])<<" ";
        cout<<endl;
    }
    return 0;
}
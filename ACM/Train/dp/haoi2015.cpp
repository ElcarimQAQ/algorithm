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
ll dp[maxn][maxn];
int siz[maxn];
int n,k;
ll ans = 0;

struct node
{
    int f,t;
    ll dis;
};

vector<node> g[maxn];

ll cal(int x,int y)
{
    return 1ll *x * (k - x) + (y - x) * (n - y - k +x);
}

void dfs(int u,int fa)
{
    siz[u] = 1;
    dp[u][0] = dp[u][1] = 0;
    for(int i = 0;i < g[u].size(); i++){
        node no = g[u][i];
        int v = no.t;
        if(v == fa)
            continue;
        dfs(v,u);
        siz[u] += siz[v];
        for(int j = min(k,siz[u]);j >= 0; j--){
            for(int m = 0; m <= min(j,siz[v]) ; m++){
                dp[u][j] = max(dp[u][j],dp[v][m] + dp[u][j - m] + cal(m,siz[v]) * no.dis);
            } 
        }
    
    }
}


// void dfs1(int u,int fa)
// {
//     dp[u][0] = dp[u][1] = 0;
//     for(int i = 0;i < g[u].size(); i++){
//         node no = g[u][i];
//         int v = no.t;
//         if(v == fa)
//             continue;
//         dfs1(v,u);
//         for(int j = min(k,siz[u]);j >= 0; j--){
//             for(int m = 0; m <= min(j,siz[v]) ; m++){
//                 if(dp[u][j - m] == -1)
//                     continue;
//                 dp[u][j] = max(dp[u][j],dp[v][m] + dp[u][j - m] + cal(m,siz[v]) * no.dis);
//             } 
//         }
//     }
// }

int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
     ios::sync_with_stdio(false); cin.tie(0);
    cin>>n>>k;
    memset(dp,-INF,sizeof(dp));
    int r = (1 + n) * n / 2;
    for(int i = 1;i < n; i++){
        node n1,n2;
        cin>>n1.f>>n1.t>>n1.dis;
        r -= n1.t; 
        n2.f = n1.t;
        n2.t = n1.f;
        n2.dis = n1.dis;
        g[n1.f].push_back(n1);
        g[n2.f].push_back(n2);
    }
    dfs(1,-1);
    //dfs1(r,-1);
    cout<<dp[1][k]<<endl;
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int maxn = 200005;
typedef long long ll;
typedef int ll;
ll a[maxn];
int vis[maxn];
int fl[maxn];

vector<int> g[maxn];
int T,n,m,s,t;
int ans =0;

int dfs(int u,int fa)
{
    vis[u] = 1;
    for(int i = 0;i < g[u].size();i++){
        int v = g[u][i];
        if(v == t)
            return 1;
        if(v == fa || vis[v])
            continue;
        if(dfs(v,u) == 1)
            return 1;
    }
    return 0;
}

void dfs2(int u,int fa)
{
    vis[u] = 1;
    for(int i = 0;i < g[u].size();i++){
        int v = g[u][i];
        if(vis[v])
            continue;
        if((fl[u] & fl[v]) == 1)    
            fl[0] = 1;
        if(fl[u] != fl[v])
            dfs2(v,u);
        ans += fl[v];
    }
}

int check(ll x){
    memset(vis,0,sizeof(vis));
    fl[0] = 0; 
    for(int i = 1 ;i <= n;i++){
        if(a[i] >= x) fl[i] = 1;
        else fl[i] = -1;
    }
    ans = fl[s];
    dfs2(s,-1);
    if((ans >= 0 && vis[t] ==  1)|| fl[0] == 1)
        return 1;
    else
        return 0;
}

int main()
{
    cin>>T;
    while(T--){
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>s>>t;
        int mi,ma;
        for(int i = 1;i <= n;i++){
            g[i].clear();
            cin>>a[i];
            if(i == 1){mi = ma = a[1];}
            mi = min(mi,a[i]);
            ma = max(ma,a[i]);
        }
        int u,v;
        for(int i = 1;i <= m;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(dfs(s,-1)){
            cout<<"YES"<<endl;
            ll l = 1,r = 1e9;
            while( l <= r){
                ll m = (l + r) >> 1;
                if(check(m))
                    l = m + 1;
                else
                    r = m - 1;
            }
            cout<<l<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
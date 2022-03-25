#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=200005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
ll a[maxn];
ll f[maxn];
ll ma[maxn];
ll ans[maxn];
vector<int> g[maxn];
ll mx  = 0;
ll dfs(int u,int fa)
{
    for(int i = 0;i < g[u].size() ;i++){
        int v = g[u][i];
        if(v == fa)
            continue;
        ll son = dfs(v,u);
        f[u] += son;
        if(ma[v] >= ma[u]){
            ma[u] = ma[v];
        }
    }
    f[u] += a[u];
    if(f[u] >= ma[u])
        ma[u] = f[u];
    return f[u];
}

void dfs2(int u,int fa)
{
    ll mx1 = -1e18,mx2 = -1e18;
    for(int i =0;i<g[u].size();i++){
        int v= g[u][i];
        if(v== fa)
            continue;
        if(ma[v] >= mx1){
            mx2 = mx1;
            mx1 = ma[v];
        }
        else if(ma[v] >= mx2)
            mx2 = ma[v];
        dfs2(v,u);
    }
    if(mx2 != -1e18)
        mx= max(mx,mx1+mx2); 
}

int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin.sync_with_stdio(false);
    int n,m;
    cin>>n; 
    for(int i = 1;i <= n;i++)
        cin>>a[i];
    int u,v;
    for(int i = 1;i <= n-1; i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    dfs2(1,0);
    if(mx!=-1e18)
        cout<< mx <<endl;
    else
        cout<<"Error"<<endl;
    return 0;
}
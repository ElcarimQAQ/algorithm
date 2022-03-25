#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int maxn = 200005;
typedef long long ll;

int a[maxn];
int vis[maxn];
int fa[maxn];

vector<int> g[maxn];
int T,n,m,s,t;
int ans =0;
bool flag = false;

int find(int x){
    return fa[x] == x ? x : fa[x] = find(fa[x]); 
}
void dfs(int u,int x)
{
    vis[u] = 1;
    for(auto v : g[u]){
        if(a[u] >= x && a[v] >= x)
            flag = true;
        if(!vis[v])
            dfs(v,x);
    }
}

void dfs2(int u,int x)
{
    vis[u] = 1;
    for(auto v : g[u]){
        if(!vis[v] && (a[u] >= x) != (a[v] >= x))
            dfs2(v,x);
    }
}

int check(int x){
    memset(vis,0,sizeof(vis));
    flag = false;
    dfs(s,x);
    if(flag)
        return 1;
    if(a[s] < x && a[t] < x)
        return false;
    memset(vis,0,sizeof(vis));
    dfs2(s,x);
    if(vis[t] == 1)
        return 1;
    else
        return 0;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        cin>>n>>m>>s>>t;
        for(int i = 1;i <= n;i++){
            g[i].clear();
            fa[i] = i;
            cin>>a[i];
        }
        int u,v;
        for(int i = 1;i <= m;i++){
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            fa[find(u)] = find(v);
        }
        if(find(s) == find(t)){
            cout<<"YES"<<endl;
            int l = 1,r = 1e9;
            while( l <= r){
                int m = (l + r) >> 1;
                if(check(m))
                    l = m + 1;
                else
                    r = m - 1;
            }
            cout<<r<<endl;
        }
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 5005;
#define INF 0x3f3f3f3f
struct edge
{
    int u,v;
    void add(int a,int b){
        u = a;
        v = b;
    }
}e[maxn];

vector<int> g[maxn];
int ans[maxn];
int vis [maxn];
int cnt = 1;
int flag;
int del_u,del_v;

int dfs(int u,int fa){
    if(!flag){
        if(u > ans[cnt])
            return 1;
        if(u < ans[cnt])
            flag = 1;
    }
    vis[u] = 1;
    ans[cnt++] = u;
    for(auto v: g[u]){
        if(vis[v])
            continue;
        if((u == del_u && v == del_v) || (u == del_v && v == del_u))
             continue;
        if(dfs(v,u)) return 1;
    }
    return 0;
}

int main()
{
    
    int n,m,u,v;
    cin>>n>>m;
    memset(ans,INF,sizeof(ans));
    for(int i = 0;i < m; i++ ){
        cin>>u>>v;
        e[i].add(u,v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1;i <= n; i++)
        sort(g[i].begin(),g[i].end());
    if(n - 1 ==m ){
        dfs(1,0);
        for(int i = 1;i <= n; i++)
            cout<<ans[i]<<" "; 
    }
    else{
        for(int i = 0;i < m; i++){
            memset(vis,0,sizeof(vis));
            del_u = e[i].u;
            del_v = e[i].v;
            flag = 0;
            cnt = 1;
            dfs(1,0);
        }
        for(int i = 1;i <= n; i++)
            cout<<ans[i]<<" ";
        
    }
    return 0;
}

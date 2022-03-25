#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
vector<int> g[maxn];
int dis[maxn];
int timb[maxn],tima[maxn];
int pos,n,t,x,y;
int ans = 0;

void dfs(int u,int fa)
{
    dis[u] = dis[fa] + 1;
    if(dis[u] & 1)
        timb[u] = timb[fa] + 1;
    else timb[u] = timb[fa];
    // cout<<"t"<<u<<" "<<timb[u]<<" "<<endl;
    for(auto v : g[u]){
        if(v != fa)
            dfs(v,u);
    }
}

int dfs2(int u,int fa,int cnt)
{
    if(cnt == t)
        return u;
    // cout<<"t"<<u<<" "<<cnt<<endl;
    for(auto v : g[u]){
        if(v != fa && dis[v] < dis[u])
            return dfs2(v,u,cnt + 1);
    }
    return 0;
}


void dfs3(int u,int fa)
{
    tima[u] = tima[fa] + 1;
    // cout<<"t"<<u<<" "<<tima[u]<<endl;
    if(tima[u] >= timb[fa]){
        ans = max(ans,timb[u]);
        return;
    }
    for(auto v : g[u]){
        if(v != fa){
            dfs3(v,u);
        }
    }
}

int main()
{
    cin>>n>>t;
    for(int i = 0;i < n - 1; i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dis[0] = -1,timb[0] = t ,tima[0] = t - 1,ans = 0;
    dfs(n,0);
    pos = dfs2(1,0,0);
    dfs3(pos,0);
    // cout<<"pos"<<pos<<endl;
    cout<<ans - t<<endl;
    return 0;
}

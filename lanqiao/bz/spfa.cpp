#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
#define INF 0x3f3f3f3f
typedef long long ll;
int vis[maxn],dis[maxn];
struct  edge
{
    int u,v,w;
}e[maxn];

vector<edge> g[maxn];

void spfa(int s)
{
    memset(dis,INF,sizeof(dis));
    memset(vis,0,sizeof(vis));
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    vis[s] = 1;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for(auto i : g[x]){
            int v = i.v;
            if(dis[v] > dis[x] + i.w){
                dis[v] = dis[x] + i.w;
                if(!vis[v]){
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    

}


int main()
{   
    int n,m;
    cin>>n>>m;
    int u,v;
    for(int i = 1 ;i <= m ;i++){
        cin>>u>>v;
        edge e1,e2;
        e1.u = e2.v = u;
        e1.v = e2.u = v;
        e1.w = e2.w = 1;
        g[u].push_back(e1);
        g[v].push_back(e2);
    }
    spfa(1);
    cout<<dis[n]-1<<endl;
    return 0;
}
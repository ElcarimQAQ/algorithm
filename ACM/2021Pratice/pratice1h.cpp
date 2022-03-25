#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=100005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
int n,m;
struct edge{
    int u,v,w;//出发点，目标点，距离
}ed[maxn];
vector<edge> g[maxn];//邻接表
int vis[maxn],dis[maxn];//标记i是否在队列中，起始点到i点的距离
void sqfa(int s)
{
    queue<int> q;
    memset(vis,0,sizeof(vis));
    memset(dis,INF,sizeof(dis));//初始化
    q.push(s);//起始点
    dis[s] = 0;
    vis[s] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for(int i = 0;i < g[x].size() ;i++){
            edge nx = g[x][i];
            //如果更新的结果更好，进行松弛操作，将下一个点距离更新，并加入队列
            if(dis[nx.v] > dis[x] + nx.w){
                dis[nx.v] = dis[x] + nx.w;
                if(!vis[nx.v]){
                    q.push(nx.v);
                    vis[nx.v]  = 1;
                }
            }
        }
    }
}
int main()
{
    
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
    sqfa(1);
    cout<<dis[n]-1<<endl;
    return 0;
}
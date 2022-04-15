#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int maxn = 100005;
#define INF 0x3f3f3f3f
typedef pair<int,int> PII;
vector<PII> g[maxn];
int dis[maxn],vis[maxn];
int n,m,x,y,z;

void dij() {
    memset(dis, INF , sizeof dis);
    dis[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0,1});
    while(heap.size() != 0) {
        PII t = heap.top();
        heap.pop();

        int v = t.second, distance = t.first;
        if(vis[v]) continue;
        vis[v] = 1;
        for(auto ed :g[v]) {
            int j = ed.first;
            if(dis[j] > dis[v] + ed.second){
                dis[j] = dis[v] + ed.second;
                heap.push({dis[j],j});
            }
        }
    }  
    if(dis[n] == INF) 
        cout<<-1<<endl;
    else cout<<dis[n]<<endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    while(m--) {
        cin>>x>>y>>z;
        g[x].push_back({y,z});
    }
   
    dij();
    return 0;
}
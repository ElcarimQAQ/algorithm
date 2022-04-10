#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int maxn = 505;
#define INF 0x3f3f3f3f
int g[maxn][maxn], cost[maxn][maxn];
int st[maxn] , dis[maxn], C[maxn];
int pre[maxn];
stack<int> road;
int n,m,S,D;

void dij()
{
    memset(dis, INF, sizeof(dis));
    memset(C, INF, sizeof(C));
    memset(pre, -1 ,sizeof(pre));
    dis[S] = 0, C[S] = 0;
    for(int i = 0;i < n; i++){
        int t = -1;
        for(int j = 0;j < n;j++) 
            if(!st[j] && (t == -1 || dis[j] <= dis[t] ) ) 
                t= j;
        
        st[t] = 1;
    
        for(int j = 0; j< n;j++) {
            if(dis[j] > dis[t] + g[t][j]){
                dis[j] = dis[t] + g[t][j];
                C[j] = C[t] + cost[t][j];
                pre[j] = t;
            } else if(dis[j] == dis[t] + g[t][j]) {
                dis[j] = dis[t] + g[t][j];
                C[j] = min(C[j], C[t] + cost[t][j]);
                pre[j] = t;
            }
        }
    }
}

void printRoad(int t)
{
    road.push(t);
    while (pre[t] != -1) {
        road.push(pre[t]);
        t = pre[t];
    }
    while(!road.empty()) {
        cout<<road.top()<<" ";
        road.pop();
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
  
    cin>>n>>m>>S>>D;
    memset(g,INF,sizeof(g));
    memset(cost,INF,sizeof(cost));
    int a,b,c,d;
    while(m--) {
        cin >> a >> b >> c >> d;
        g[a][b] = g[b][a] = min(g[a][b], c);
        cost[a][b] = cost[b][a] = min(cost[a][b], d);
    }
    dij();
    printRoad(D);
    cout<<dis[D]<<" "<<C[D]<<endl;
   
    return 0;
}
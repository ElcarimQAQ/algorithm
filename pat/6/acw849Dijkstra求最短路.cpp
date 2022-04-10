#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int maxn = 505;
#define INF 0x3f3f3f3f
int g[maxn][maxn];
int st[maxn] , dis[maxn];
  int n,m,x,y,z;

void dij()
{
    memset(dis, INF, sizeof(dis));
    dis[1] = 0;
    for(int i = 1;i <= n; i++){
        int t = -1;
        for(int j = 1;j <= n;j++) 
            if(!st[j] && (t == -1 || dis[j] < dis[t]))
                t= j;
        st[t] = 1;
        for(int j =1; j<= n;j++) {
            if(dis[j] > dis[t] + g[t][j])
                dis[j] = dis[t] + g[t][j];
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
  
    cin>>n>>m;
    memset(g,INF,sizeof(g));
    while(m--) {
        cin >> x >> y >>z;
        g[x][y] = min(g[x][y], z);
    }
    dij();
    if(dis[n] != INF)
        cout<<dis[n]<<endl;
    else cout<<-1<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 205;
int g[maxn][maxn];
int V[maxn];
int cnt = 0;
int Mcost = INF;
int num = 0;
int main() 
{
    std::ios::sync_with_stdio(false);
    memset(g ,INF, sizeof g);
    int n,m,u,v,c,k;
    cin>>n>>m;
    while(m--) {
        cin>>u>>v>>c;
        g[u][v] = g[v][u] = c;
    }
    cin>>k;
    int N;
    for(int i = 1;i <= k; i++)
    {
        cin>>N;
        bool flag = true;
        if(n != N) flag = false;
        int cost = 0;
        unordered_set<int> vis;
        for(int j = 0;j < N; j++) {
            cin>> v;
            vis.insert(v);
            if(!flag) continue;
            V[j] = v;
            if((j == 0 && g[v][0] == INF) ||(j == N-1 && g[v][0] == INF) || ( j != 0 && g[v][V[j - 1]] == INF) )  {
                flag = false;
            }
            if(j == 0 || j == N - 1)  cost += g[v][0];
            if(j != 0) 
                cost += g[v][V[j - 1]]; //bug2,最后一点也在
        }
        if(vis.size() != N) flag = false; //bug1,，注意所有的点也要访问到
        if(!flag) continue;
        cnt++;
        if(cost < Mcost) {
            Mcost = cost;
            num = i;
        }
    }
    cout<<cnt<<endl;
    cout<<num<<" "<<Mcost<<endl;
    return 0;
}
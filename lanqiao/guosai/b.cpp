#include <bits/stdc++.h>
using namespace  std;
#define  INF 0x3f3f3f3f
const int maxn = 10005;
int  vis[maxn][maxn];
int dir[4][2] = {1,0,-1,0,0,1,0-1};
int ans = 4;

void dfs(int x,int y,int t){
    if(t == 2020)
        return;
    // cout<<t<<endl;
    vis[x][y] = t;
    for(int i = 0; i < 4;i++){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1]; 
        
        if(vis[nx][ny] != INF && vis[nx][ny] >= vis[x][y] + 1 ) continue;
        if(vis[nx][ny] == INF) ans++;
        dfs(nx,ny,t+1);
    }
}

int main()
{
    memset(vis,INF,sizeof(vis));
    dfs(0 + 2020 ,0 + 2020,0);
    dfs(2020 + 2020,11 + 2020,0);
    dfs(11 + 2020,14 + 2020,0);
    dfs(2000 + 2020,2000 + 2020,0);
    cout<<ans<<endl;
}
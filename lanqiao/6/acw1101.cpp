#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
#define INF 0x3f3f3f3f
typedef long long ll;
string g[maxn];
int vis[maxn][maxn];
int t,r,c;
int dir[4][2] = {0,1,0,-1,1,0,-1,0};
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

struct node{
    int x,y,l;
};

node s,e;
int bfs(int x,int y)
{
    memset(vis,-1,sizeof(vis));
    queue<node> q;
    q.push(s);
    vis[s.x][s.y] = 0;
    while(!q.empty()){
        node now = q.front();
        q.pop();
        for(int i = 0; i < 4;i++){
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;  // 出界
            if (g[nx][ny] == '#') continue;  // 障碍物
            if (vis[nx][ny] != -1) continue;  // 之前已经遍历过
            node next = {nx,ny,now.l+1};
            vis[nx][ny] = vis[now.x][now.y]+1;
            q.push(next);
            
        }
    }
    return vis[e.x][e.y];
}

int main()
{
   cin>>t;
    while (t--)
    {
        cin>>r>>c;
        for(int i = 0; i < r;i++){
            cin>>g[i];
            for(int j = 0; j < c ;j++){
                if(g[i][j] == 'S')
                    s = {i,j,0};
                if(g[i][j] == 'E')
                    e = {i,j,0};
            }

        }
        int ans = bfs(s.x,s.y);
        if(ans == -1)
            cout<<"oop!"<<endl; 
        else
            cout<<ans<<endl;
    }
    return 0;
}
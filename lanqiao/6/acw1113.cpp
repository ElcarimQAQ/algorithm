#include <bits/stdc++.h>
using namespace std;
const int maxn = 205;
#define INF 0x3f3f3f3f
typedef long long ll;
string g[maxn];
int vis[maxn][maxn];
int w,h;
int dir[4][2] = {0,1,0,-1,1,0,-1,0};

int ans = 0;
void  dfs(int x,int y){
    vis[x][y] = 1;
    for(int i = 0;i < 4; ++i){
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if(nx < 0 || nx >= h ||ny < 0 ||ny >= w) continue;
        if(vis[nx][ny]) continue;
        if(g[nx][ny] == '#') continue;
        // cout<<"?"<<endl;
        ans++;
        dfs(nx,ny);
    }

}

int main()
{   
    
    while(cin>>w>>h){
        if(w == 0 && h == w )
            break;
        ans = 0;
        memset(vis,0,sizeof(vis));
        for(int i = 0; i < h; i++){
            cin>>g[i];
        }
        for(int i = 0; i < h; ++i){
            for(int j = 0; j <  w; ++j) {
                if(g[i][j] == '@'){
                    dfs(i,j);
                    // cout<<i<< " " <<j<<endl;
                }
            }
        }
        cout<<ans+1<<endl;
    }
    return 0;
}
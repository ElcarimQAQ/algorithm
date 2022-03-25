#include <bits/stdc++.h>
using namespace  std;
#define  INF 0x3f3f3f3f
const int maxn = 10005;
typedef long long ll;

int f[maxn][maxn];
int vis[maxn][maxn];
int ans = 0;

void dfs(int x,int y,int l){
    if(x < 0 || x >= 4 || y < 0 || y >= 4) return;
    if(vis[x][y]) 
        return;
    if(l == 16){ 
        ans++;
        return ;
    }
    vis[x][y] = 1;
    dfs(x + 1,y,l+1);
    dfs(x,y+1,l + 1);
    dfs(x - 1,y,l + 1);
    dfs(x,y - 1,l + 1);
    vis[x][y] = 0;
}
int main()
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++){
            dfs(i,j,1);
        }
    cout<<ans<<endl;
    return 0;
}
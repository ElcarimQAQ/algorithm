#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
const int maxn = 1005;
int a[maxn][maxn];
int f[maxn][maxn];
int n;
int vis[maxn][maxn];
int px[] = {-1, 0, 1, 0};   
int py[] = {0, -1, 0, 1};
struct node{
    int x,y;
}
no[maxn];
int ans = 1e9;


void bfs(int x,int y)
{
    queue<node> q;
    node no;
    no.x = x;
    no.y = y;
    q.push(no); 
    while(!q.empty()){
        node no = q.front();
        q.pop();
        for(int i = 0;i < 4;i++){
            int nx = no.x + px[i];
            int ny = no.y + py[i];
            if(nx < 1 || nx> n ||ny < 1 || ny > n ||f[nx][ny] == f[x][y])
                continue;
            if(vis[nx][ny] == 0 &&f[nx][ny] != f[x][y] ){
                node now;
                now.x = nx;
                now.y = ny; 
                vis[nx][ny] = 1;
                q.push(now);
            }
            if(a[nx][ny] == 1)
                ans = min(ans,abs(nx - x)+ abs(ny - y));
        }
    }
}

void dfs(int x,int y)
{
    for(int i = 0;i < 4;i++){
        int nx = x + px[i];
        int ny = y + py[i];
        if(a[nx][ny] == 1 && (f[nx][ny] == 0)){
            if(nx >= 1 && nx<= n &&ny >= 1 && ny <= n){
                f[nx][ny] = 1;
                //vis[nx][ny] = 1;
                dfs(nx,ny);
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 1;i <= n; i++){
        for(int j = 1;j <= n;j++){
            cin>>a[i][j];
        }
    }
    int flag = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(a[i][j] && (!f[i][j]) && flag == 0){
                dfs(i,j);
                flag = 1;
            }
            if(flag == 1 && a[i][j] &&f[i][j] != 1)
                f[i][j] = 2; 
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(a[i][j]){
                memset(vis,0,sizeof(vis));
                bfs(i,j);
            }
        }
    }
    cout<<ans - 1 <<endl;
    return 0;
}

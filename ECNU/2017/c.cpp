#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const  int maxn = 1e7+5;
#define inf 0x3f3f3f3f3f3f3f
ll vis[maxn];
ll x,y;


void bfs()
{
    memset(vis,0x3f,sizeof(vis));
    queue<int> q;
    int u = 0;
    vis[0] = 0;
    q.push(u);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        if(now + 1 < maxn && vis[now + 1] > vis[now] + x){
            vis[now + 1] = min(vis[now + 1],vis[now]+ x);
            u = now + 1;
            q.push(u);
        }
        if(now * 2 < maxn && vis[now * 2] > vis[now] + y ){
            vis[now * 2] = min(vis[now * 2],vis[now] + y);
            u = now * 2;
            q.push(u);  
        }
        if(now - 1 < 0)
            continue;
        if(vis[now - 1] > vis[now] + x){
            vis[now - 1] = min(vis[now - 1],vis[now] + x);
            u = now - 1;
            q.push(u);
        }
    }
}

int main()
{
    int n;   
    cin>>n>>x>>y;
    bfs();
    cout<<vis[n]<<endl;
    return 0;
}
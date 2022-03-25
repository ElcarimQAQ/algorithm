#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
#define INF 0x3f3f3f3f
struct  edge
{
    int to,cap,rev;
    void add(int a,int b,int c){
        to = a,cap = b,rev = c;
    }
};

vector<edge> g[maxn];
int vis[maxn],ans[maxn];
int T,n,m,k;

void add(int u,int v,int cap){
    edge e1,e2;
    e1.add(v,cap,g[v].size());
    g[u].push_back(e1);
    e2.add(u,0,g[u].size() - 1);
    g[v].push_back(e2);
}

int dfs(int u,int t,int f)
{
    if(u == t)
        return f;
    vis[u] = 1;
    for(int i = 0;i < g[u].size(); i++){
        edge &e = g[u][i];
        // cout<<e.to<<endl;
        if(!vis[e.to] && e.cap > 0){
            int d = dfs(e.to,t,min(f,e.cap));
            if(d > 0){
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                // cout<<d<<endl;
                return d;   
            }
        }
    }
    // puts("0");
    return 0;
}

int max_flow(int s,int t)
{
    int res = 0;
    for(;;){
        memset(vis,0,sizeof(vis));
        int f = dfs(s,t,INF);
        if(f == 0) return res;
        res += f;
    }
}

void init(int x)
{
    for(int i = 1;i <= x; i++)
        g[i].clear();
    // memset(ans,0,sizeof(ans));
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        int f;
        cin>>n>>m;
        int s = n + m + 1,t = s + 1;
        // cout<<s<<t<<endl;
        init(t);
        for(int i = 1;i <= m; i++){
            cin>>k;
            for(int j = 1;j <= k; j++){
                cin>>f;
                add(i, f + m,1);
            }
             add(s,i,1);
        }
        for(int i = 1;i <= n; i++)
            add(m + i, t, (m + 1) / 2);
        int an = max_flow(s,t);
        // cout<<an<<endl;
        if(an == m){
            cout<<"YES"<<endl;
            for(int i = 1; i <= m; i++){
                for(int j = 0;j < g[i].size(); j++){
                    if(g[i][j].cap == 0 )
                        ans[i] = g[i][j].to - m ;
                }
            }
            for(int i = 1;i <= m; i++)
                cout<<ans[i] <<" ";
            cout<<endl;
        }
        else
             cout<<"NO"<<endl;

    }
}
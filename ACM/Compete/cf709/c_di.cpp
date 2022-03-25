#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;
#define INF 0x3f3f3f3f
struct  edge
{
    int to,cap,rev;
    void add(int a,int b,int c){
        to = a,cap = b,rev = c;
    }
};

int level[maxn],iter[maxn],ans[maxn];
vector<edge> g[maxn];

void add_edge(int u,int v,int cap){
    edge e1,e2;
    e1.add(v,cap,g[v].size());
    g[u].push_back(e1);
    e2.add(u,0,g[u].size() - 1);
    g[v].push_back(e2);
}

void bfs(int s)
{
    memset(level,-1,sizeof(level));
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0;i < g[u].size(); i++){
            edge &e = g[u][i];
            if(e.cap > 0 && level[e.to] < 0){
                level[e.to] = level[u] + 1;
                q.push(e.to);
            }
        }
    }
    
}



int dfs(int u,int t,int f){
    if(u == t)
        return f;
    for(int &i = iter[u];i < g[u].size() ;i++){
        edge &e = g[u][i];
        if(e.cap > 0 && level[u] < level[e.to]){
            int d = dfs(e.to,t,min(f,e.cap));
            // cout<<d<<endl;
            if(d > 0){
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}



int max_flow(int s,int t){
    int flow = 0;
    for(;;){
        bfs(s);
        if(level[t] < 0){
            return flow;
            cout<<"flow"<<flow<<endl;
        }
        memset(iter,0,sizeof(iter));
        int f;
        while(f = dfs(s,t,INF) > 0)
            flow += f;
    }
    return flow;
}


void init(int x)
{
    for(int i = 1;i <= x; i++)
        g[i].clear();
    // memset(ans,0,sizeof(ans));
}

int main()
{
    int T,n,m;
    cin>>T;
    while (T--)
    {
        int k,j,s,t;
        cin>>n>>m;
        s = n + m + 1,t = s + 1;
        init(t);
        for(int i = 1;i <= m; i++){
            cin>>k;
            while(k--){
                cin>>j;
                add_edge(i,m + j,1);
            }
            add_edge(s,i,1);
        }
        for(int i = 1; i <= n; i++)
            add_edge(m + i,t,(m + 1) / 2);
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
            cout<<"NO"<<endl;;
    }
    
    return 0;
}
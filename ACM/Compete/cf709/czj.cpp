#include<bits/stdc++.h>
using namespace std;

const int maxn=100050,maxm=400050;
const int INF=0x3f3f3f3f;

struct edge{
    int u,v,cap,flow;
    edge(){}
    edge(int u,int v,int cap,int flow):u(u),v(v),cap(cap),flow(flow){}
}eg[maxm<<1];
int tot,dis[maxn<<1],cur[maxn<<1];
vector<int> tab[maxn<<1];
void init(int n){
    tot=0;
    while(n)tab[n--].clear();
}
void addedge(int u,int v,int cap){
    tab[u].push_back(tot);
    eg[tot++]=edge(u,v,cap,0);
    tab[v].push_back(tot);
    eg[tot++]=edge(v,u,0,0);
}
int bfs(int s,int t){
    queue<int> q;
    q.push(s);
    memset(dis,INF,sizeof dis);
    dis[s]=0;
    while(!q.empty()){
        int h=q.front(),i;
        q.pop();
        for(i=0;i<tab[h].size();i++){
            edge &e=eg[tab[h][i]];
            if(e.cap>e.flow&&dis[e.v]==INF){
                dis[e.v]=dis[h]+1;
                q.push(e.v);
            }
        }
    }
    return dis[t]<INF;
}
int dfs(int x,int maxflow,int s,int t){
    if(x==t||maxflow==0)
        return maxflow;
    int flow=0,i,f;
    for(i=cur[x];i<tab[x].size();i++){
        cur[x]=i;
        edge &e=eg[tab[x][i]];
        if(dis[e.v]==dis[x]+1&&(f=dfs(e.v,min(maxflow,e.cap-e.flow),s,t))>0){
            e.flow+=f;
            eg[tab[x][i]^1].flow-=f;
            flow+=f;
            maxflow-=f;
            if(maxflow==0)
                break;
        }
    }
    return flow;
}
int dinic(int s,int t){
    int flow=0;
    while(bfs(s,t)){
        memset(cur,0,sizeof(cur));
        flow+=dfs(s,INF,s,t);
    }
    return flow;
}

int ans[maxn];

void solve()
{
    int n,m;
    cin>>n>>m;
    init(m+n+2);
    for(int i=1;i<=m;i++)
    {
        int t;
        cin>>t;
        while(t--)
        {
            int j;
            cin>>j;
            addedge(i,j+m,1); //第i天向第j个朋友连边
        }
        addedge(n+m+1,i,1); //源点向第i天连边
    }
    for(int i=1;i<=n;i++)
        addedge(i+m,n+m+2,(m+1)/2); //第i个朋友向汇点连边
    if(dinic(n+m+1,n+m+2)==m) //m个点全都能完成匹配
    {
        cout<<"YES\n";
        for(int i=0;i<tot;i+=2)
        {
            if(eg[i].u<=m&&eg[i].flow) //残量网络中如果这条边被使用
                ans[eg[i].u]=eg[i].v-m;
        }
        for(int i=1;i<=m;i++)
            cout<<ans[i]<<' ';
        cout<<'\n';
    }
    else
        cout<<"NO\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}

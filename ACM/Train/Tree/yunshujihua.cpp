#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 400005;
const int M = 25;
#define INF 0x3f3f3f3f
int dep[maxn],pa[M][maxn];
int sum[maxn],dis[maxn],seq[maxn],cnt = 0;
int flca[maxn];

struct edge
{
    int u,v,t;
    void add(int a,int b,int c){
        u = a;
        v = b;
        t = c;
    }
}e[maxn];

vector<edge> g[maxn];
int n,m,a,b,c;

void dfs(int u,int fa,int d)
{
    seq[++cnt] = u;
    // cout<<"u"<<u<<endl;
    pa[0][u] = fa;
    dep[u] = d;
    for(int i = 0;i < g[u].size(); i++){
        int vv = g[u][i].v;
        if(vv == fa) continue;
        dis[vv] = dis[u] + g[u][i].t;
        dfs(vv,u,d + 1);
    }
}

void init()
{
    dfs(1,-1,0);
    for(int i = 0 ;i < M; i++){
        for(int v = 1 ;v <= n; v++){
            if(pa[i][v] == -1) pa[i + 1][v] = -1;
            else pa[i + 1][v] = pa[i][pa[i][v]];
        }
    }
}

int lca(int u,int v)
{
    if(dep[u] > dep[v]) swap(u,v);
    for(int k = 0; k < M ;k++){
        if(dep[v] - dep[u] >> k & 1)
            v = pa[k][v];
    }
    if(u == v) return u;
    for(int k = M - 1; k>= 0; k--){
        if(pa[k][u] != pa[k][v]){
            u = pa[k][u];
            v = pa[k][v];
        }
    }
    return pa[0][u];  
}

bool check(int mid)
{
    int s = 0;
    memset(sum,0,sizeof(sum));
    int ma = 0;
    for(int i = 0;i < m; i++){
        int v = e[i].v,u = e[i].u;
        int l = e[i].t;
        if(l > mid){ 
            ma = max(ma,l);//路径的最大值
            sum[v] += 1,sum[u] += 1;
            sum[flca[i]] -= 2; 
            s++;
        }
    }
    // cout<<"s"<<s<<endl;
    if(!s) return true;

    //dfs序
    for(int i = n;i >= 1; i--){
        int ne = seq[i];
        sum[pa[0][i]] += sum[ne];
        // cout<<"ne"<<ne<<endl;
    }
    
    for(int i = 1;i <= n; i++){
        if(sum[i] == s && mid + dis[i] - dis[pa[0][i]] >= ma)
            // cout<<"s"<<s<<endl;
            return true;
        
    }
    return false;
}

int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    memset(pa,-1,sizeof(pa));
    cin>>n>>m;
    for(int i = 0;i < n - 1 ; i++){
        cin>>a>>b>>c;
        edge e1,e2;
        e1.add(a,b,c);
        e2.add(b,a,c);
        g[a].push_back(e1);
        g[b].push_back(e2);
    }
    init();
    int u,v,ll;
    for(int i = 0;i < m ;i++){
        cin>>u>>v;
        flca[i] = lca(u,v);
        ll = dis[v] + dis[u] - 2 * dis[flca[i]];
        e[i].add(u,v,ll);
        // cout<<flca[i]<<endl;
    }

    int l = 0,r = 1e9;
    while(l < r)
    {
        int mid = l + r >> 1;
        // cout<<mid<<endl;
        if(check(mid))  r = mid;
        else l = mid + 1;
    }
    cout<<r<<endl;
    return 0;
}

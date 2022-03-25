#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
#define INF 0x3f3f3f3f
typedef long long ll;
ll f[maxn];
ll a[maxn];
vector<ll> g[maxn];

void dfs(int u,int fa){
    f[u] = a[u];
    for(auto v:g[u]){
        // cout<<v<<endl;
        if(v == fa ) continue;
        dfs(v,u); 
        f[u] = max(f[u],f[u] + f[v]);
        // cout<<f[u]<< " "<<f[v]<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i = 1;i <= n; ++i)
        cin>>a[i];
    int u,v;
    // memset(f,-INF,sizeof(f));
    for(int i = 1;i <= n - 1; ++i )  {
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    ll ans = -INF;
    for(int i = 1;i <= n; i++)
        ans = max(ans,f[i]);
    cout<<ans<<endl;
    return 0;
}
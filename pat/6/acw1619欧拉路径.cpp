#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int maxn = 505;
#define INF 0x3f3f3f3f
int w[maxn],vis[maxn];
vector<int> g[maxn];
int n,m,a,b;
int cnt = 0;
bool dfs(int u)
{   
    cnt++;
    vis[u] = 1;
    for(auto v : g[u]){
        if(!vis[v]) {
            dfs(v);
        }
    }
    if(cnt == n) return true;
    return false;
}

int main()
{
    std::ios::sync_with_stdio(false);

    cin>>n>>m;
    while(m--){
        cin>> a>> b;
        g[a].push_back(b);
        g[b].push_back(a);
        w[a]++;
        w[b]++;
    }
    int odd = 0,even  = 0;
    for(int i = 1; i<= n;i ++){
        if(w[i] % 2)
            odd++;
        else 
            even++;
        if(i == n) cout<<w[i]<<endl;
        else cout<<w[i]<<" ";
    }
    if(dfs(1)) {
        if(even == n) puts("Eulerian");
        else if(odd == 2 && even == n-2) puts("Semi-Eulerian");
        else puts("Non-Eulerian");
    } else puts("Non-Eulerian");
   
    return 0;
}
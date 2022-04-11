#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int maxn = 505;
#define INF 0x3f3f3f3f
int ans[maxn];
vector<int> g[maxn];
int H = 0;
void dfs(int u,int h)
{
    H = max (H,h);
    if(g[u].size() == 0)
        ans[h]++;
    for(auto v : g[u]) 
        dfs(v, h+1); 
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n,m,u,k,v;
    cin>>n>>m;
    while(m--) {
        cin>>u>>k;
        while(k--){
            cin>>v;
            g[u].push_back(v);
        }
    }
    dfs(1,1);
    for(int i = 1;i <= H; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
vector<int> g[maxn];
int vis[maxn];
int H = 0,e = 0;
void dfs(int u,int h) {
    for(auto v : g[u]) {
        dfs(v, h +1 );
    }
    if(h > H){
        H = h;
        e = u;
    }
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n,k,j;
    cin>>n;
    for(int i = 1; i <= n;i ++) {
        cin>>k;
        while(k--) {
            cin>>j;
            vis[j] = 1;
            g[i].push_back(j);
        }
    }
    int s;
    for(int i = 1;i <= n; i++) {
        if(vis[i] == 0){
            s = i;
            break;
        }
    }
    dfs(s, 1);
    cout<<e<<endl;
    return 0;
}
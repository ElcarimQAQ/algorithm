#include <bits/stdc++.h>
using namespace std;
const int N = 50000;
int vis[N], c[N], d[N], x[N];
vector<int> g[N];

pair<int, int > dfs(int u, int fa, int cnt){
    int res = 0;
    int CNT = cnt;
    vis[u] = 1;
    for(int i = 0; i < g[u].size(); i++){
        int v = g[u][i];
        if(v == fa || vis[v]) continue;
        res += dfs(v, u, CNT+1).first;
    }
    return make_pair(res, CNT);
}
int main(){
    // fast;
    int n, b;
    cin >> n >> b;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if(i >= 2) {
            cin>>c[i]>>d[i]>>x[i];
            g[i].append(x[i]);
        }
        else
            cin>>c[i]>>d[i];
    }
    for(int i = 1; i<= n;i++){
        if (vis[i] == 0)
        {
            pair<int, int> res= dfs(i, 0, 0);
            if(res.first <= b){
                ans += res.second;
                b -= res.first;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
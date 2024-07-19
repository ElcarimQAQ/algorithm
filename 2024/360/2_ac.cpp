#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int x[N], y[N];
vector<int> g[N];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin>>x[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin>>y[i];
    }
    for (int i = 1; i<= n; i++){
        for (int j = 1; j <= n; j++){
            if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= k)
                g[i].push_back(j);
        }
    }
    
    int ans = 0;
    vector<int> vis(n + 1, 0);
    for(int i = 1; i <= n; i++){
        if(vis[i])  continue;
        queue<int> q;
        q.push(i);
        vis[i] = 1;
        int cnt = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(auto v : g[u]){
                if(!vis[v]){
                    cnt++;
                    q.push(v);
                    vis[v] = 1;
                    ans = max(ans, cnt);
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 10005;
vector<int> g[maxn];
int pre[maxn];
int len = 0;

vector<int> ans,road;

void dfs(int u) {
    for(auto v : g[u]) {
        road.push_back(v);
        dfs(v);
        road.pop_back();
    }
    if(g[u].size() == 0) {
        if( road.size() > len) {
            len = road.size();
            ans = road;
        }
        if(road.size() == len) 
            ans = min(ans,road);
    }
}


int main() 
{
    std::ios::sync_with_stdio(false);
    ans.reserve(maxn);
    
    int n , k, u, head;
    cin>>n;
    for(int i= 0; i < n; i++) 
        pre[i] = -1;
    
    for(int i = 0; i< n; i++) {
        cin>>k;
        while(k--) {
            cin>>u;
            g[i].push_back(u);
            pre[u] = i;
        }
    }
    for(int i = 0; i < n; i++) {
        if(pre[i] == -1) {
            head = i;
            break;
        }
    }
    road.push_back(head);
    dfs(head);

    cout<<len<<endl;
    for(int i = 0;i< ans.size();i ++){ 
        if(i == ans.size() - 1) cout<<ans[i]<<endl;
        else cout<<ans[i]<<" ";
    }
    return 0;
}
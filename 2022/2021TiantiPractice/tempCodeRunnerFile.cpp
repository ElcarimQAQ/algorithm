#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 10005;
vector<int> g[maxn];
int pre[maxn],h[maxn];
int node[maxn]; //高度下最小点
int len = 0;
stack<int> road;
void dfs(int u,int fa) {
    for(auto v : g[u]) {
        if(v == fa) continue;
        h[v] = h[u] + 1;
        len = max(len, h[v]);
        node[h[v]] = min(node[h[v]], v);
        dfs(v, u);
    }
}

void print(int p) 
{
    cout<<p;
    while(pre[p] != -1) {
        road.push(pre[p]);
        p = pre[p];
    }
    while(!road.empty()) {
        cout<<" "<<road.top();
        road.pop();
    }
}

int main() 
{
    std::ios::sync_with_stdio(false);
    int n , k, u, head;
    cin>>n;
    for(int i= 0; i< n; i++) {
        pre[i] = -1;
        node[i] = INF;
    }
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
    h[head] = 1;
    dfs(head, -1);
    int end = node[len];
    cout<<len<<endl;
    print(end);

    return 0;
}
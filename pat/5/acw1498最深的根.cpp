#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005; 
vector<int> g[maxn];
int vis[maxn],nodeH[maxn];
int maxh ,H = 0;
bool flag = true;
int pre[maxn];
set<int> Count;
int find(int x){
    if (pre[x] != x) pre[x] = find(pre[x]);
    return pre[x];  
}

void dfs2(int u,int fa,int h)
{
    if(h > maxh)
        maxh = h;
    
    for(auto  v : g[u]) {
        if(v != fa ) {
            dfs2(v, u, h + 1);
        }
    }
}

int main()
{
    std :: ios::sync_with_stdio(false);

    int n,u,v;
    cin >> n;
     for(int i =  1 ; i<= n;i++) {
        pre[i] = i;
    }
    int cnt = n;
    for(int i = 0; i< n - 1;i++){ //bug1,不看题，n-1
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        if (find(u) != find(v))
        {
            cnt -- ;
            pre[find(u)] = find(v);
        }
    }
   
    if( cnt > 1) {
        printf("Error: %d components\n",cnt);
        return 0;
    }
    for(int i = 1 ;i <= n;i ++){
        maxh = 0;
        dfs2(i, 0, 1);
        nodeH[i] = maxh;
        H= max(H,maxh);
    }

    for(int i = 1; i <= n; i++){
        if(nodeH[i] == H)
            cout<<i<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 10050;
vector<int> g[maxn];
int pre[maxn];
int len = 0;

vector<string> ans;

void dfs(int u,int fa,string road) {
    for(auto v : g[u]) {
        string next = road ;
        next.push_back(v +'0');
        dfs(v, u, next);
    }
    if(g[u].size() == 0) {
        if((int) road.size() > len) {
            len = (int) road.size();
            ans.clear();
        }
        if((int) road.size() == len) 
            ans.push_back(road);
    }
}


int main() 
{
    std::ios::sync_with_stdio(false);
    int n , k, u, head;
    cin>>n;
    for(int i= 0; i< n; i++) 
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
    string str = "";
    str.push_back(head +'0');
    dfs(head, -1, str);

    cout<<len<<endl;
    sort(ans.begin(),ans.end());
    for(int i = 0;i< ans[0].size();i ++){ 
        if(i == ans[0].size() - 1) cout<<ans[0][i]<<endl;
        else cout<<ans[0][i]<<" ";
    }
    return 0;
}
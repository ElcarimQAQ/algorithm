#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 1005;
int hx[maxn],tr[maxn];
int cnt = 1;

void dfs(int x)
{
    if(tr[x] == 0)
        return;
    dfs(x * 2);
    dfs(x * 2 + 1);
    tr[x] = hx[cnt++];
}

int main() 
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i = 1; i <=n;i++) {
        cin>>hx[i];
        tr[i] = 1;
    }
    dfs(1);
    for(int i = 1;i <=n; i++) {
        if(i == n) cout<<tr[i]<<endl;
        else cout<<tr[i]<<" ";
    }
    
    return 0;
}
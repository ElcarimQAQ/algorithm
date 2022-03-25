#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[30],vis[30];
int n,m;

void dfs(int cnt)
{
    if(cnt > m){
        for(int i = 1;i <= m;++i)
            cout<<a[i]<<" ";
        cout<<endl;
        return ;
    }
    for(int i = 1;i <= n; i++){
        if(vis[i])
            continue;
        if(i > a[cnt - 1]){
            a[cnt] = i;
            dfs(cnt+1);
            vis[i] = 0;
        }
    }
}

int main()
{
    cin>>n>>m;
    dfs(1);
    return 0;
}
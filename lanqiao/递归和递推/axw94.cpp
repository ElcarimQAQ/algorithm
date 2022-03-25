#include <bits/stdc++.h>
using namespace std;
int a[20];
int vis[15];
int n;

void dfs(int l,int cnt){
    if(cnt > l){
       for(int i =1;i <= l;++i)
            cout<<a[i]<<" ";
        cout<<endl;
        return;
    }
    for(int i = 1;i <= n;++i){
        if(vis[i])
            continue;
        a[cnt] = i;
        vis[i] = 1;
        dfs(l,cnt + 1);
        vis[i] = 0;
    }
}

int main()
{
    cin>>n;
    // cout<<endl;
    // for(int i =1;i <= n; ++i)
    dfs(n,1);

}
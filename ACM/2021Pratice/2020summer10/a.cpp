#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e6;
int vis[maxn];
int ans[maxn];
int main()
{
    int t,p;
    cin>>t;
    while(t--){
        int flag = 1;
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
        cin>>p;
        ans[1] = 1;
        vis[1] = 1; 
        for(int i = 2;i < p ; i++){
            int v  = ans[i - 1] * 2 % p;
            int w  = ans[i - 1] * 3 % p;
            if(vis[w] && vis[v]){
                flag = 0;
                break;
            }
            if(!vis[v])
               ans[i] = v;
            else ans[i] = w;
            vis[ans[i]] = 1;
        }
        if(flag){
            for(int i = 1;i < p; i++)
                cout<<ans[i]<<" ";
            cout<<"\n";
        }
        else
            cout<<-1<<endl;

    }
    return 0;
}
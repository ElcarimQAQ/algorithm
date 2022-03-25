#include <bits/stdc++.h>
using namespace std;
const int maxn = 1500005;
#define INF 0x3f3f3f3f
typedef long long ll;
int vis[maxn];
ll answer = 1;

ll cal(int x){
    ll res = 1;
    for(int i = 1;i <= x ;i++)
        res *= (1ll*i);
    return res;
}

int main()
{
    int x;
    while(cin>>x){
        int sum = 0,tot = 0 ;
        // ans.clear();
        // memset(vis,0,sizeof(vis));
        for(int i = 2;i * i <= x; i++){
            vis[++sum] = 0;
            while (x  % i == 0)
            {
                x /= i;
                vis[sum]++;
                tot++;
            }      
        }
        if(x != 1){
            vis[++sum] = 0;
            vis[sum]++;
            tot++;
        }
    
        answer = cal(tot);
        // cout<<sum<<" "<<answer<<endl;
        for(int i = 1;i <= sum ; ++i){
            answer /= cal(vis[i]);
        }
        cout<<sum <<" "<< answer<<endl;
    }
    return 0;
}
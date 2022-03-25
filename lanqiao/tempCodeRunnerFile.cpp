#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn  = 22005;
#define INF 1e15
ll vis[maxn];
ll dfs(ll x)
{
    if(x == 0) return 0;
    if(x == 1) return 1;
    if(vis[x] != 0) return vis[x];
    ll ans = INF;
    for(ll l = 0;l <= x - 1 ;l++ ){
        ll r = x- 1 - l;
        ll ql = dfs(l);
        ll qr = dfs(r);
        ll t = min(2 * ql + 3 * qr + l * l * r,2 * qr + 3 * ql + r * r *l) +1;
        ans = min(t,ans);
    }
    return vis[x] = ans;
}
int main()
{
    cout<<dfs(2021)<<endl;
    return 0;
}
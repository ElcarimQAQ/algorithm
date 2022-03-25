#include<bits/stdc++.h>
#include <algorithm>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=5e6+7;
const int mod=998244353;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
//ll f[maxn][maxn];
ll dp[maxn];
ll jc[maxn];
ll ksm(ll a,ll b ,ll m){
    ll ans = 1;
    while(b)
    {
        if(b & 1) ans = a * ans % m;
        b >>= 1;
        a = a * a % m;
    }
    return ans;
}

ll C(ll n,ll m) {
    if(m < 0 || n < m)
        return 0;
    return jc[n] * ksm((jc[m])% mod, mod - 2,mod) % mod* ksm((jc[n - m]) % mod, mod - 2,mod) % mod;
}

int main ()
{
    //freopen("data.in", "r", stdin);
    //freopen("1.out", "w", stdout);	
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,m,ans;
    ans = 0;
    cin>>n>>m;
    jc[0] = 1;
    for(int i = 1 ;i <= m + n ; i++)
        jc[i] = (jc[i-1] * i) % mod;
    for(int d = 1;d <= n-1;d++){
        ans += C(m-2+d,d) * d % mod * (n - d);
        ans %= mod;
    }
    cout<<ans<<endl;
    return 0;
}

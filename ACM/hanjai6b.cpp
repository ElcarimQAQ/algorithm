#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=100005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 3
const int inf=1<<30;
int a[105],b[105],c[105];
int dp[105][105][10005];

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
    ll fz = 1,fm = 1; 
    for(ll i = 1; i <= m; i++){
        fz = fz * (n + i - m) % mod;
        fm = fm * i % mod;
    }
    return fz * ksm(fm, mod - 2,mod) % mod;
}

ll lucas(ll n,ll m){
    if(m == 0)
        return 1;
    return (C(n % mod,m % mod) * lucas(n / mod,m / mod) )% mod;
}
int main()
{
    int t;
    cin>>t;
    ll n,k;
    while(t--){
        cin>>n>>k;
        ll ans = 1;
        ans = (ksm(-1,2 * n - k,mod)*lucas(2 * n,k) + mod) %mod;
        cout<<ans<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
#include <algorithm>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=1e4+7;
typedef long long ll;
const int mod=1e9+7;
#define pi acos(-1)
#define INF 0x3f3f3f3f
ll x[maxn],p[maxn];
ll prime[maxn];
ll vis[maxn];//
set<ll> fj;
ll pp[maxn];
ll viss[maxn];

void cal_prime()
{
    memset(vis,0,sizeof(vis));
    for(ll i =2;i<=maxn;i++){
        for(ll j =i*2;j <=maxn;j+=i)
            vis[j] =1;
    }
    for(ll i=2,j=1;i<=maxn;i++){
        if(vis[i] == 0)
            prime[j++] = i;
    }
}

ll poww(ll d,ll pr){
    ll ans= 1;
    while(pr--){
        ans=(ans*d)%mod;
    }
    return ans;
}
int main ()
{
    //freopen("data.in", "r", stdin);
    //freopen("1.out", "w", stdout);	
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    for(ll i = 1;i <=n;i++)
        cin>>x[i];
    for(ll i = 1;i <=n;i++)
        cin>>p[i];
    cal_prime();
    ll num=x[1];
    ll k = 0;
    while(1){
        for(ll j = 1;j <= maxn;j++){
            ll zs=prime[j];
            if(zs == 0)
                break;
            if(num%zs == 0){
                num = num/zs;
                if(viss[k] != zs)
                    viss[++k] = zs;
                pp[zs]++;
                break;
            }
        }
        if(num == 1)
            break;
    }
    for(ll i =1;i<=k;i++){
        pp[viss[i]] *= p[1];
    }
    for(ll i=2;i <= n; i++){
        num=x[i];
        for(ll j = 1;j <= k; j++)
        {
            ll cnt = 0;
            while(num%viss[j] == 0){
                num = num/viss[j];
                cnt++;
            }
            cnt *= p[i];
            pp[viss[j]] =min(pp[viss[j]],cnt);
        }
    }
    ll ans=1;
    for(ll i=1; i<= k;i++){
        ll zs=viss[i];
        ans = ans*poww(zs,pp[zs])%mod;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}

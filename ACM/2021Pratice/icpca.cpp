#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=100005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 1000000007
const int inf=1<<30;
ll A[maxn];
ll J[maxn];
ll ksm(ll a,ll b,ll m)
{
    ll ans = 1;
    while(b){
        if(b & 1) ans = (ans*a) % m ;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}
 
void amn(ll m,ll n){
    A[0] = 1;
    for(ll i = 1,j = m;i<= n;i++){
        A[i] = A[i-1] * j;
        A[i] %= mod;
        j--; 
    }
}
 
void jiechen(ll k)
{
    J[0] = 1;
    for(int i  = 1 ; i <= k;i++ ){
        J[i] = (J[i-1] * i) % mod;
    }
}
 
ll cmn(ll m ,ll n)
{
    return (A[n] * ksm(J[n],mod-2,mod)) %mod;
}
 
int main()
{
    int t,n,k;
    cin>>t;
    jiechen(100000);
    for(int i = 1; i <= t; i++){
        cin>>n>>k;
        if( k > n){
            printf("Case #%d: 0\n",i);
            continue;
        }
        ll ans = ksm(2,n,mod);
        ll jishu = 0;
        amn(n,k);
        for(ll j = k-1 ; j >= 0; j--){
            jishu += cmn(n,j);
            jishu %= mod;
        }
        ans = (ans - jishu + mod) % mod;
        printf("Case #%d: %lld\n",i,ans);
    }
    return 0;
}
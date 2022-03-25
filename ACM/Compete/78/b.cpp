#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=200005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
ll a[maxn];
ll b[maxn];
vector<ll> vis[maxn];
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin.sync_with_stdio(false);
    ll n,m;
    cin>>n>>m; 
    for(ll i = 1;i <= n;i++)
        cin>>a[i];
    cin>>b[1];
    ll ans = 0,ans1 = a[b[1]];
    ll sum = 0;
    vis[b[1]].push_back(1);
    for(ll i = 2;i <= m;i++){
        cin>>b[i];
        vis[b[i]].push_back(i);
        if(vis[b[i]].size() == 1){
            sum += ans1;
            ans1 += a[b[i]] ;
            continue;
        }
        ll l = vis[b[i]].size()-2;
        ll j = vis[b[i]][l];
        ll ans = 0;
        for( j = j+1 ; j < i ;j++)
            ans += a[b[j]] ;
        sum += ans ;
    }
    cout<< sum <<endl;
    return 0;
}
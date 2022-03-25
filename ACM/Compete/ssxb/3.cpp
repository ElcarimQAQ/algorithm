#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#define INF 1e18+5
typedef long long ll;
using namespace std;

const ll maxn =  1005;
ll a[maxn];
ll vis[maxn],vis2[maxn];
ll l[maxn];
vector<ll> ans;

int main() {
	
    ll n;
    cin>>n;
    for(ll i = 1;i <= n; i++)
        cin>>a[i];
    for(ll i = 1;i <= n; i++){
        ll cnt = 0,mi = INF,f = 0;
        for(ll j  = 1;j <= n; j++){
            if(vis[j] || l[j] == j) continue;
            if(a[j] % (j - l[j])){
                cnt = a[j] / (j-l[j]) + 1;
            }
            else
                cnt = a[j] / (j-l[j]);
            if(cnt < mi){
                mi =  cnt ;
                f = j;
            }
        }
        vis[f] = 1;

        ll cnt2 = 1;
                    // cout<<f<<endl;
        if(f!=0)
            ans.push_back(f);

        memset(vis2,0 ,sizeof(vis2));
        for(ll j = 1;j <= n; j++){
            if(vis[j]||l[j] == j) continue;
            if(j < f)
                a[j] -= mi * (j - l[j]);
            else{
                a[j] -= mi * (j - l[j]);
                a[j] += cnt2;
                if(a[j] <= 0){
                    ans.push_back(j);
                    vis[j] = 1;
                    vis2[j] = 1;
                    cnt2++;
                }
            }
        }
        ll cnt3 = 1;
        for(ll j = f;j <= n;j++){
            l[j] += cnt3;
            if(vis2[j])
                cnt3++;
        }
    }
    for(ll i = 0 ;i < ans.size();i++)
        cout<<ans[i]<<" ";
    return 0;
}

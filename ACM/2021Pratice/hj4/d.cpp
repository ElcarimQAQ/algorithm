#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 100005;
ll sum[maxn],num[maxn];
ll a[maxn];

void check(ll x)
{
    ll ans = 0;
}

int main()
{
    ll t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(ll i = 1;i <= n; i++){
            cin>>a[i];
            num[i % k]++;
            sum[i % k ] += a[i];
        }
        ll j = (n % k + 1) % k;
        ll x; 
        if(j != 1)
            x = (sum[1] - sum[j]) / (num[1] - num[j]);
        else{
            int f = 1;
            for(int i = 0;i < k;i++){
                if(sum[i] != sum[1]){
                    f = 0;
                    break;
                }
            }
            if(f == 0){
                cout<<-1<<endl;
                continue;
            }
            ll mx  = 0;
            for(int i = 1;i <= n; i++)
                 mx = max(mx ,a[i]);
            ll l = mx,r = 1e10;
            while(l < r){
                ll m =  (l + r) >> 1ll;
                for(int i = 0;i < k-1; i++){
                    if(m * num[i] - sum[i] == m * num[i+1] - sum[i+1])
                        continue;
                    else{
                        f = 0;
                        break; 
                    }
                }
            }
        }
        int f = 1;
        for(int i = 0;i < k-1; i++){
            if(x * num[i] - sum[i] == x * num[i+1] - sum[i+1])
                continue;
            else{
                f = 0;
                break; 
            }
        }
        if(f && x != 0)
            cout<<x - a[1]<<endl;
        else
            cout<<-1<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int maxn = 1e9;
typedef long long ll;
vector<ll> p;
vector<ll> po;
int main()
{
    ll ans = 1;
    p.push_back(1);
    po.push_back(1);
    ll x = 1;
    for(int i = 1;;i++){
        x *= 2;
        po.push_back(x);
        ans += x;
        if(ans > maxn){
            //cout<<i<<endl;
            break;
        }
        p.push_back(ans);
    }
    int t;
    ll n;
    cin>>t;
    while(t--){
        cin>>n;
        int l = lower_bound(p.begin(),p.end(),n) - p.begin();
        // cout<<l<<" "<<p[l]<<endl;
        if(p[l] == n)
            cout<<l + 1<<endl;
        else{
            for(int i = l ;i >= 0;i--){
                //cout<<p[i]<<" "<<po[i]<<endl;
                if((n - p[i]) % po[i] == 0){
                    cout<<i + 1 + (n - p[i]) / po[i]<<endl;
                    break;
                }
            }
            // if((n - p[l - 1]) % po[l -1])
            //     ll ans = l  + (n - p[l - 1]) / po[l -1] +1;
            // cout<<l  + (n - p[l - 1]) / po[l -1]<<endl;
        }
    }
    return 0;
}
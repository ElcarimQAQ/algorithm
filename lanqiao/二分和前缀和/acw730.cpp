#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
typedef long long ll;
ll h[maxn];
int n;
int check(ll x)
{
    // cout<<x<<endl; 
    for(int i = 1;i<= n;i++){
        if(h[i] > x)
            x -= (h[i] -x);
        else
            x += (x -h[i]);
        // cout<<x<<endl; 
        if(x < 0){
            // cout<<0<<endl;
            return 0;
        }
        if(x > 1e5+5)
            return 1;
    }
    // cout<<1<<endl;
    return 1;
}
int main()
{
    // int n;
    cin>>n;
    for(int i =1 ;i <= n; i++ )
        cin>>h[i];
    ll l = 0,r = 1e7;
    while(l < r){
        ll m = (l + r) >> 1;
        if(check(m) == 0) l = m + 1;
        else r = m;
    }
    cout<<l<<endl;
    return 0;
}
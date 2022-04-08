#include <bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;
const double PI =  3.141592653589;
const int maxn = 1e6+5;
const ll mod =  1e9+7;
ll a[maxn];

int main() 
{
    int n;
    std::ios::sync_with_stdio(false);
    cin>>n;
    ll ans = 1;
    for(int i = 1; i <= n; i++) {
        cin>>a[i];
        ans = (ans * a[i]) % mod;
    }
    cout<<ans<<endl;
    
    return 0;
}
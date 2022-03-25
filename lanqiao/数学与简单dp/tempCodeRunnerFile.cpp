#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1005;
#define mod 100000007
ll f[maxn][maxn];

ll slove(ll x,ll m){
    if(x > 0)
        return x % m;    
    else
        return (x % m + m )% m;
}
int main()
{
    ll n,s,a,b;
    cin>>n>>s>>a>>b;
    f[0][0] = 1;
    for(ll i = 1;i <= n;i++){
        for(ll j = 0;j < n;j++){
            f[i][j] = (f[i-1][slove(j - a * (n - i),n)] % mod + f[i- 1][slove(j + b * (n - i),n)] %mod) %mod;
        }
    }
    cout<<f[n - 1][slove(s,n)]<<endl;
    return 0;
}
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define pi acos(-1.0)
const int maxn=10005;
const int mod = 1e9+7;
using namespace std;
typedef long long ll;
long double A[maxn];

ll ksm (ll a,ll b ,ll m){
    ll ans = 1;
    while(b){
        if(b&1) ans = (ans * a) % m;
        b >>= 1;
        a = (a * a) % m;
    }
    return ans; 
}

int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int t,n,m,k;
    cin>>t;
    for(int cas = 1; cas <= t;cas++){
        cin>>n>>m>>k;
        ll ans = 0;
        for(int i = 2;i <= k ;i++)
            ans = (ans + ksm(i-1,m+n-2,mod)) % mod;
        ans = ans * m % mod * n % mod;
        ans = ans * ksm(k,(n-1)*(m-1),mod) % mod;
        ans = (ans + ksm(k,n*m,mod)) % mod;
        cout<<"Case #"<<cas <<": "<< ans << endl;
    }
    
	return 0;
}

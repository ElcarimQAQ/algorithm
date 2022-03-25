#include <bits/stdc++.h>
#define INF 0x3f3f3f3f;
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;

ll pow_mod(ll a,ll k)
{
    ll ans = 1;
    a %= MOD;
    while(k)
    {
        if(k % 2) ans *= a;
        a = (a * a) % MOD;
        k /= 2;
        ans %= MOD;
    }
    return ans;
}

int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int t,a,b,c,d,e,f,g;
    cin>>t;
    while(t--){
        cin>>a>>b>>c>>d>>e>>f>>g;
        if(pow_mod(a,d)+pow_mod(b,e)+pow_mod(c,f)==g)
            printf("Yes\n");
        else
            printf("No\n");
    }
	return 0;
}

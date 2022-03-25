#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
typedef long long ll;
const ll mod =1e9+7;
int a[maxn],b[maxn];


ll A(ll n){
    ll ans = 1;
    for(int i = n;i >= 2; i--)
        ans = ans * i % mod;
    // cout<<n<<" "<<ans<<endl;
    return ans % mod;
}

int main()
{
    ll t,k,n;
    cin>>t;
    // int nu =5&1&1; 
    // cout<<nu<<endl;
    while(t--){
       cin>>n;
       int sum = (~0);
       int mi = 1e9+5;
       for(ll i = 1;i <= n; ++i){
            cin>>a[i];
            mi =  min(mi,a[i]);
            sum &= a[i];  
       }
       cout<<sum<<endl;
       ll cnt = 0;
       for(ll i =1;i <= n; ++i ){
        //    b[i] = sum &a[i];
           if(a[i] == mi)
                cnt++;
       }
       ll ans;
       if(cnt <= 1|| ((sum & mi) != mi)) 
            ans = 0;
        else 
           ans = cnt*(cnt-1) % mod * A(n-2) %mod; 
        cout<<ans<<endl;
    }
    return 0;
}
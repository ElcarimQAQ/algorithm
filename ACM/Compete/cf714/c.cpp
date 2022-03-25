#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005;
typedef long long ll;
const ll mod =1e9+7;
ll a[15],b[15];

int main()
{
    ios::sync_with_stdio(false);
    ll t,m,n;
    cin>>t;
    while(t--){
       ll ans =0 ;
       memset(a,0,sizeof(a));
       memset(b,0,sizeof(b));
       cin>>n>>m;
       while(n){
           ll p = n % 10;
           b[10 - p]++;
           n /= 10;
           ans++;
       }
       for(int i =1;i <= m;i++){
           int j;
           if(i % 10 == 0)
                j = 10;
           else j = i % 10;
           if(j == 1){
               for(int k =1;k<=10;++k)
                    a[k] = b[k];
           }
           if(a[j] != 0){
               ans = ans + a[j] % mod;
               int k = i + 9;
               if(k % 10 == 0)
                    k = 10;
               else k = i % 10;
               b[k] =(a[k] + a[j] )% mod;
               k = i + 10;
               if(k % 10 == 0)
                    k = 10;
               else k = i % 10;
               b[k] =(a[k] + a[j]) %mod;
           }
       }
       cout<<ans<<endl;
    }
    return 0;
}
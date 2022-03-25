#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
const int maxn = 2e5+5;
ll a[maxn],b[maxn],c[maxn];

int main ()
{
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    ll suma = 0,sumb = 0;
    for(int i = 1;i <= n; ++i){
        cin>>a[i];
        suma = (suma +a[i]) % mod;
    }
    for(int i = 1;i <= n; ++i){
        cin>>b[i];
        sumb =(sumb + b[i]) % mod;
    }
    for(int i = 1;i <= n; ++i){
        if(i == 1){
            for(int j =2;j <= n; ++j){
                c[i] = (c[i] + a[j] * (sumb + mod - b[1]) % mod) %mod;
                // c[i] = (c[i] + b[j] * (suma + mod - a[i])% mod) %mod;
            }
        }
        if(i == 2){
            for(int j = 3;j <= n; ++j){
                c[i] = (c[i] + a[1] * b[j] %mod) %mod;
                c[i] = (c[i] + b[1] *a[j] %mod) %mod;
            }
            c[i] =(c[i] + a[1] * b[1] )% mod;
        }
        if(i == 3)
            c[i] = (a[1] * b[2] + a[2] * b[1] )% mod;
        if(i > 3)
            c[i] = 0;
        cout<<c[i]<<" ";
    }
    cout<<endl;
    return 0;
}

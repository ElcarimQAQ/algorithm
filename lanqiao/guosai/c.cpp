#include <bits/stdc++.h>
using namespace  std;
#define  INF 0x3f3f3f3f
const int maxn = 10005;
typedef long long ll;

int p[maxn];
int main()
{
    for(int i = 2;i <= 100;i++){
        int n = i;
        for(int j = 2 ;j <= n / j;j++){
            while(n % j == 0){
                p[j]++;
                n /= j;
            }
        }
        if(n > 1)
            p[n]++;
    }
    // cout<<sum<<endl;;
    ll ans = 1;
    // for(auto i :mp){
    //     cout<<prime[i]<<",";
    //     ans = ans * ll(prime[i]+1); 
    // }
    for(int i = 2; i <= 100; i++)
        if(p[i]){
            ans *= (p[i] + 1);
            cout<<ans<<endl;
        }
    cout<<ans<<endl;
    return 0;
}
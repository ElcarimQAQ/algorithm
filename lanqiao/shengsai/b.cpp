#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a % b);
}
int main()
{
    ll ans = 0;
    // cout<<gcd(15,20);
    for(int i = 1;i <= 2020; ++i){
        for(int j = 1;j <= 2020 ;++j){
            if(gcd(i,j) == 1)
                ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
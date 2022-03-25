#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,a;
    cin>>n;
    while(n--){
        cin>>a;
        ll cnt = sqrt(2 * a);
        if(cnt * (cnt + 1) / 2  + 1== a)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}
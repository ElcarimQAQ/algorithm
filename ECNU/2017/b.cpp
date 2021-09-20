#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
int main()
{
    ll t;
    ll a,b;
    cin>>t;
    for(ll c = 1;c <= t;c++){
        cin>>a>>b;
        ll sum = a;
        bitset<64> tmp = bitset<64>(a);
        for(ll i = 0;i <= 64; i++){
            if(tmp[i] == 0){
                if(sum + (1ll << i)  > b){
                    break;
                }
                else sum += (1ll << i);
            }
        }
        printf("Case %d: ",c);
        cout<<sum<<endl;
    }
    return 0;
}
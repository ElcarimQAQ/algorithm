#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

ll slove(ll a, ll b , ll p)
{
    ll ans = 0;
    for( ;b ; b >>= 1){
        if( b&1 ) 
            ans = ( ans + a )% p;
        a = (a +a) % p;
    }
    return ans;
}

int main()
{
    ll a,b,p;
    cin >> a >> b>> p;
    cout << slove(a,b,p) << endl;
    //system("pause");
    return 0;
} 
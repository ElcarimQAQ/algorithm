#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[70];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    w[0] = 1;
    for(int i = 1; i <= 64; i++)
        w[i] = w[i - 1] << 1;
    for(int i = 1; i <= t; i++)
    {
        ll a, b;
        cin >> a >> b;
        ll ans = a, maxnum = 0;
        bitset<70> temp = bitset<70>(a);
        for(int i = 0; i < 64; i++)
        {
            if(temp[i] == 0)
                ans += w[i];
            if(ans > b)
            {
                ans -= w[i];
                break;
            }
 
        }
        cout << "Case " << i << ": ";
        cout << ans << endl;
    }
 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;

ll visx[maxn];
ll visy[maxn];

ll k1[3*maxn],k2[3*maxn];
int main()
{
    ll n,x,y;
    ll cnt = 0;
    cin>>n;
    while(n--){
        cin>>x>>y;
        if(visx[x] != 0)
            cnt += visx[x];
        if(visy[y] != 0) 
            cnt += visy[y];    
        visx[x]++;
        visy[y]++;
        if(k1[y - x + maxn] != 0)
            cnt += k1[y-x + maxn];
        if(k2[x + y + maxn] != 0)
            cnt += k2[x+y +maxn];
        k1[y - x + maxn]++;
        k2[x + y + maxn]++;

    }
    cout<<cnt<<endl;
    return 0;
}
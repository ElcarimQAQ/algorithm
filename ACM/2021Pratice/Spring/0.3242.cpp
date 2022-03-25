#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
typedef long long ll;
ll h[maxn];
ll l[maxn],r[maxn];
ll q[maxn];

int main()
{
    int n;
    while(cin>>n && n){
        ll ans = 0;
        for(int i = 1; i <= n ; i++)
            cin>>h[i];
        h[0] = h[n + 1] = -1;
        int t = 0;
        q[0] = 0;
        for(int i = 1;i <= n ;i++){
            while(h[q[t]] >= h[i]) t--;
            l[i] = i - q[t];
            q[++t] = i;
        }
        t = 0;
        q[0] = n + 1;
        for(int i = n;i >= 1 ;i--){
            while(h[q[t]] >= h[i]) t--;
            r[i] = q[t] - i;
            q[++t] = i;
        }
        for(int i = 1;i <= n; i++)
            ans = max(ans,(l[i] + r[i] - 1) * h[i]);
        cout<<ans<<endl;
    }
    return 0;
}
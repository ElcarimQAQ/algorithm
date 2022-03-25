#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=200005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
ll a[maxn],b[maxn];
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
    ll t,n,k;
    cin>>t;
    while(t--){
        cin>>n;
        ll x ,y;
        int cnt1 = 0,cnt2 = 0; 
        for(int i = 1;i <= n *2;i++){
            cin>>x>>y;
            if(x == 0){
                if(y > 0)
                a[++cnt1] = y;
                else a[++cnt1] = -y;
            }
            if(y == 0){
                if(x > 0)
                b[++cnt2] = x;
                else b[++cnt2] = -x;
            }
        }
    sort(b+1,b+n+1);
    sort(a+1,a+n+1);
    double ans = 0.0;
    for(int i =1;i <= n; i++){
        ans += sqrt(a[i] * a[i]*1.0 + b[i] *b[i]*1.0);
    }
    printf("%.15lf\n",ans);
        

    }
    return 0;
}
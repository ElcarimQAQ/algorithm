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
    ios::sync_with_stdio(false); cin.tie(0);
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        for(int i = 1 ;i <= n; i++)
            cin>>a[i];
        for(int i = 1 ;i <= m; i++)
            cin>>b[i];
        sort(a + 1,a + 1 + n);
        sort(b + 1,b + 1 + m);
        b[0] = -INF;
        b[m+1] = INF;
        int ans = 0;
        for(int i = 1;i <= m + 1; i++){
            int l = upper_bound(a + 1,a + n + 1,b[i-1]) - a;
            int r = lower_bound(a + 1,a + n + 1,b[i]) - a;
            ans = max(ans,r - l );
        }
        //ans = max(ans,cnt);
        if(ans <= 0)
            cout<<"Impossible"<<endl;
        else
            cout<<ans<<endl;
    }
    return 0;
}
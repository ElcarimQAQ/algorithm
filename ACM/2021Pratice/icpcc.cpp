#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=100005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 1000000007
const int inf=1<<30;
ll s[maxn];
ll a[maxn],b[maxn];

int main()
{
    int t,n;
    cin>>t;
    for(int c =1 ;c <= t ;c++){
        cin>>n;
        double ans = 0.0;
        for(int i = 1;i <= n+1; i++){
            scanf("%lld",&s[i]);
            ans += s[i];
        }
        for(int i = 1;i <= n; i++ )
            scanf("%lld %lld",&a[i],&b[i]);
        sort(b+1, b+1+n);
        ans += b[n];
        printf("Case #%d: %.8lf\n",c,ans); 
    }
    return 0;
}
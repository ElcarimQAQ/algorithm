#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=100005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
ll p[10];

ll slove(int id)
{
    if(id >= 1 && id < 49)
        return p[1];
    if(id >= 49 && id < 57)
        return p[2];
    if(id >=57 && id < 61)
        return p[3];   
    if(id >=61 && id < 63)
        return p[4];
    return p[5];  
}
int main()
{
    int t,n;
    cin>>t;
    for(int j = 1; j <= t ;j++){
        for(int i = 1; i <= 5; i++)
            scanf("%lld",&p[i]);
        scanf("%d",&n);
        int id;
        ll ans = 0;
        for(int i =1;i <= n;i++){
            scanf("%d",&id);
            ans += slove(id);
        }
        ans *= 10000;
        printf("Case #%d: %lld\n",j,ans);
    }
    return 0;
}
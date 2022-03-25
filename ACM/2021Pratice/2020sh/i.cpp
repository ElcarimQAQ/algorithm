#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=2005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const double PI = acos(-1);
const int inf = 1<<30;
double a[maxn],b[maxn];

int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
     ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin>>n>>m;
    double cnt = 0.0;
    for(int i = 1; i < 2 * m;i++){
        cnt += min(2.0, PI * min(i*1.0,2.0 * m - i) / m);
    }
    a[1] = b[1] = cnt;
    for(int i = 2;i <= n;i++){
        b[i] = i * 1.0 * b[1];
        a[i] = a[i - 1] + b[i] + 2.0 * m * (i - 1);
    }
    double ans = 0.0;
    for(int i =1 ;i <= n;i++){
        ans += (a[i] - b[i]) * 2.0 * m + b[i] * 2.0 * m / 2.0;
        if(m > 1)
            ans += 2.0 * m * i; 
    }
    printf("%.10lf\n",ans);
    return 0;
}
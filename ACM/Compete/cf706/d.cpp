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
int p[maxn];
int l[maxn],r[maxn];

int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1; i <= n;i++){
        cin>>p[i];
    }
    l[1] = 1;
    r[n] = 1;
    for(int i =2 ;i <= n;i++)
        l[i] = (p[i] > p[i-1])? l[i-1] + 1 : 1;
    for(int i = n-1 ;i >= 1; i--)
        r[i] = (p[i] > p[i+1]) ? r[i+1] + 1 : 1;
    int ma = 0,cnt = 0,vis = 0;
    for(int i = 1;i <= n;i++){
        if(l[i] > ma || r[i] > ma){
            ma = max(l[i],r[i]);
            cnt = 1;
            vis = i;
        }
        else if(l[i] == ma || r[i] == ma){
            cnt = 0;
        }
    }
    int ans;
    int mx = l[vis] > r[vis]? l[vis] : r[vis];
    int mi = l[vis] > r[vis]? r[vis] : l[vis];
    if(cnt && mx % 2 &&mx == mi)
        ans = 1;
    else
        ans = 0;
    cout<<ans<<endl;
    return 0;
}
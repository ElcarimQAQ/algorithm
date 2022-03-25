#include <bits/stdc++.h>
#include <algorithm>
#include<iostream>
#include <stdio.h>
#define INF 0x3f3f3f3f
//const int maxn=;
using namespace std;
typedef long long ll;
ll a[100005];
ll pre[100005];

bool cmp(ll x,ll y){
    return x>y;
}
int main (){
    int n,x,y;
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,cmp);
    pre[0]=0;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
        //cout<<pre[i]<<endl;
    }
    cin>>x>>y;
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            ans+=pre[i*j];
        }
    }
    cout<<ans<<endl;
    return 0;
}

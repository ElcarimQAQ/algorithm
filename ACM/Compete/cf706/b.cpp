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
ll a[maxn];
set<ll> vis;
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
    ll t,n,k;
    cin>>t;
    string s,s1;
    while(t--){
        cin>>n>>k;
        vis.clear();
        memset(a,0,sizeof(a));
        for(ll i = 1;i <= n;i++){
            cin>>a[i];
            vis.insert(a[i]);
        }
        sort(a+1,a+1+n);
        ll aa,bb;
        bb = a[n];
        ll cnt = 0;
        if(k == 0){
            cout<<vis.size()<<endl; 
            continue;
        }
        ll i ;
        for( i =1 ;i <= n;i++){
            if(i == 1 && a[i] != 0)
            {
                 aa = 0;
                 break;
            }
            if(a[i+1] != a[i]+1 ){
                aa = a[i]+1;
                break;
            }
        }
        ll b = (aa + bb +1) / 2;
        cnt++;
        if(vis.find(b) != vis.end() || cnt == k){
            vis.insert(b);
            cout<<vis.size()<<endl; 
        }
        else{ //找不到
            if(aa > bb)
                cout<<vis.size() + k<<endl;
            else
                cout<<vis.size() + 1<<endl;
        }
    }
    return 0;
}
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
ll b[maxn];
int vis[maxn];
int pl[maxn];
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin.sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i =1 ;i <= n;i++)
        cin>>a[i];
    int t = 0;
    ll ans = 0;
    ll cnt = 0;
    for(int i =1 ;i <= m;i++){
        cin>>b[i];
        set<int>s;
        for(int j = i-1 ;j;--j){
            if(b[i] == b[j])
                break;
            if(s.find(b[j]) == s.end()){
                s.insert(b[j]);
                ans +=  a[b[j]];
            }
        }
    }
    cout<< ans<<endl;
    return 0;
}
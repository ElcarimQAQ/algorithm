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
int a[maxn];
int dis[maxn];

int main()
{
    int n,m,u,v;
    cin>>n>>m;
    int s1 =0,s2 = 0;
    for(int i = 1;i <= n;i++){
        cin>>a[i];
        if(a[i])
            s1++;
        else s2++;
    }
    int f = 0;
    for(int i = 1;i <= m;i++) {
        cin>>u>>v;
        if(a[u] != a[v]){
            dis[u]++;
            dis[v]++;
            f  = 1;
        }
    }
    int vis1 = 0,vis2 = 0;
    for(int i = 1;i <= n;i++){
        if(a[i] && (dis[i] != 0))
            vis1++;
        if(!a[i] && (dis[i] != 0))
            vis2++;
    }
    for(int i = 1;i <= n;i++){
        int ans = 0;
        if(a[i]){
            ans += s1 - 1 + dis[i];
            if(f && (dis[i] != 0))
                ans += 2 * (s2 - dis[i]);
            if(f && (dis[i] == 0))
                ans += 3 * (s2 - vis2) + 2 * vis2;
        }
        else{
            ans += s2 - 1 + dis[i];
            if(f && (dis[i] != 0))
                ans += 2 * (s1 - dis[i]);
            if(f && (dis[i] == 0))
                ans += 3 * (s1 - vis1) + 2 * vis1;
        }
        if(i == n)
            cout<<ans<<endl;
        else
            cout<<ans<<" ";
    }
    return 0;
}
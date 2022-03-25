#include<bits/stdc++.h>
#include <algorithm>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=1e6+7;
typedef long long ll;
const int mod=1e9+7;
#define pi acos(-1)
#define INF 0x3f3f3f3f
int tm[25];
int ac[25],vis[25];
int main ()
{
    //freopen("data.in", "r", stdin);
    //freopen("1.out", "w", stdout);	
    cin.tie(0);
    ios::sync_with_stdio(false);
    int m,n,a;
    string op;
    cin>>m>>n;
    while(m--){
        cin>>a>>op;
        tm[a]++;
        if(op=="AC")
            ac[a]++;
        if(ac[a]*1.0/tm[a]<0.5)
            vis[a]=1;
    }
    int f=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0&&tm[i]!=0){
            if(f==0){
                cout<<i;
                f=1;
            }
            else
                cout<<" "<<i;
        }
    }
    cout<<endl;
    return 0;
}

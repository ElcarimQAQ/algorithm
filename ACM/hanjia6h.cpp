#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=30005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
int pre[maxn];
int deep[maxn];
int n;
struct edge
{
    int u,v,w;
}ed[maxn],ee[maxn];

bool cmp(edge a,edge b)
{
    return a.w < b.w;
}

void init(int n)
{
    for(int i = 1;i <= n; i++){
        pre[i] = i;
        deep[i] = 1;
    }
}

int find(int x)
{
    if(pre[x] == x)
        return pre[x];
    return pre[x] = find(pre[x]);
}

void merge(int x,int y)
{
    int fx = find(x),fy = find(y);
    if(deep[fx] == deep[fy] ){
        deep[fy]++;   
        pre[fx] = fy;
    }
    else{
        if(deep[fx] < deep[fy])
            pre[fx] = fy;
        else 
            pre[fy] = fx;
    }
}

ll krusal(int l,int r)
{
    ll ans = 0;
    int cnt = 0;
    sort(ee,ee+r-l+1,cmp);
    for(int i = 0; i < r-l+1; i++){
        if(find(ee[i].u) != find(ee[i].v)){
            merge(ee[i].u,ee[i].v);
            ans += ee[i].w;
            cnt++;
        }
    }
    if(cnt == n-1)
        return ans ;
    else
        return -1;
}

int main()
{
    int m,q;
    cin>>n>>m>>q;
    for(int i = 1;i <= m;i++)
        cin>>ed[i].u>>ed[i].v>>ed[i].w;
    while(q--){
        init(m);
        int opt,x,y,z,t,l,r;
        cin>>opt;
        if(opt == 1){
            cin>>x>>y>>z>>t;
            ed[x].u = y;
            ed[x].v = z;
            ed[x].w = t;
        }
        else{
            cin>>l>>r;
            for(int i = l;i <= r; i++)
                ee[i-l] = ed[i];
            ll ans = krusal(l,r);
            if(ans == -1)
                cout<<"Impossible"<<endl;
            else
                cout<<ans<<endl;
        }
    }
    return 0;
}
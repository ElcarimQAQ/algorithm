#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
typedef long long ll ;
int a[maxn];
int n,m;

struct  node
{
    int l,r;
    int ma;
}tr[4*maxn];

void pushup(int u)
{
    tr[u].ma = max(tr[u<<1].ma,tr[u<<1 | 1].ma);

}

void build(int u,int l,int r){
    if(l  == r) tr[u] = {l,r,a[r]};
    else{
        tr[u] = {l,r};
        int mid = l +r >> 1;
        build(u << 1,l,mid);
        build(u << 1|1,mid+1,r);
        pushup(u);
    }
}

int querry(int u ,int l,int r){
    if( l <= tr[u].l &&r >= tr[u].r) return tr[u].ma;
    int mid = tr[u].l+tr[u].r >> 1;
    int ma = 0;
    if(l <= mid)
        ma = querry(u << 1,l,r);
    if(r > mid) ma = max(ma,querry(u << 1|1,l,r));
    return ma;
}

int main()
{
    // ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i = 1;i <= n;++i)
        scanf("%d",&a[i]);
    build(1,1,n);
    int x,y;
    while (m--)
    {
        scanf("%d %d",&x,&y);
        printf("%d\n",querry(1,x,y));
    }
    
    return 0;
}
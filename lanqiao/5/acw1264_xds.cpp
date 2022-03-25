#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int s[maxn];
int n,m;

struct  node
{
    int l,r;
    int sum;
    /* data */
}tr[maxn*4];


void pushup(int u){
    tr[u].sum = tr[u<<1].sum + tr[u << 1 | 1].sum;
}

void build(int u,int l,int r){
    if(l == r) tr[u] = {l,r,s[r]};
    else{
        tr[u] = {l,r};
        int mid = l +r >>1;
        build(u<<1,l,mid),build(u<<1|1,mid+1,r);
        pushup(u);
    }

}

void modify(int u,int x,int v)
{
    if(tr[u].l == tr[u].r) tr[u].sum += v;
    else{
        int mid= tr[u].l + tr[u].r >> 1;
        if(x <= mid) modify(u<<1,x,v);
        if(x > mid) modify(u<<1|1,x,v);
        pushup(u);
    }
}

int querry(int u,int l,int r){
    if(tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    int mid = tr[u].l + tr[u].r >>1;
    int sum = 0;
    if(l <= mid) sum += querry(u<<1,l,r);
    if(r > mid) sum += querry(u<<1 |1,l,r);
    return sum;
}
int main ()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    int k,a,b;
    for(int i= 1;i <= n; ++i) 
    {   
        cin>>s[i];
    }
    build(1,1,n);
    while(m--){
        cin>>k>>a>>b;
        if(k == 1){
            modify(1,a,b);
        }
        if(k == 0)
            cout<<querry(1,a,b)<<endl;;
    }
    return 0;
}
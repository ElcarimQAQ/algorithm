#include<bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int a[maxn];
struct tree
{
    /* data */

    struct node
    {
        int l, r,sum;
        int lazy;
    }tr[4*maxn];

    void pushup(int u){
        tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
    }

    void pushdown(int u)
    {
        tr[u << 1].sum += (tr[u].lazy) * (tr[u << 1].r - tr[u << 1].l + 1);
        tr[u << 1].lazy += tr[u].lazy;
        tr[u << 1 | 1].sum += (tr[u].lazy) * (tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1);
        tr[u << 1 | 1].lazy += tr[u].lazy;

        tr[u].lazy = 0;
    }

    void build(int u,int l,int r){
        if(l == r)
            tr[u] = {l,r,a[r]};  
        else{
            tr[u] = {l,r};
            int mid  = l + r >> 1; 
            build(u << 1,l,mid);
            build(u << 1 |1 ,mid+1,r);
            pushup(u);
        }
    }

    void update(int u,int l,int r,int v){
        if(l <= tr[u].l && tr[u].r <= r){
            tr[u].lazy += v;
            tr[u].sum += (tr[u].r - tr[u].l + 1 ) * v;
        }
        else{
            if(tr[u].lazy) pushdown(u);
            int mid = tr[u].l + tr[u].r >> 1;
            if(l <= mid)
                update(u<<1,l,mid,v);
            if(r > mid) update(u<< 1 | 1, mid + 1 , r, v);
            pushup(u);
        }
    }

    int query(int u,int x){
        if(tr[u].l == tr[u].r) return tr[u].sum;
        else{
            if(tr[u].lazy) pushdown(u);
            int mid =  tr[u].l + tr[u].r >> 1;
            int res = 0;
            if(x <= mid)  res = query(u << 1,x);
            if(x > mid) res = query(u << 1 |1, x);
            return res;
        }
    }

}seg;


int main()
{
    int n,m,l,r,c;
    cin>>n>>m;
    for(int i = 1; i <= n; i++)
        cin>>a[i];
    seg.build(1,1,n);
    while(m--){
        cin>>l>>r>>c;
        seg.update(1,l,r,c);
        for(int i = 1; i <= n;i++)
            cout<<seg.query(1,i)<<" ";
    }
        

    return 0;
}
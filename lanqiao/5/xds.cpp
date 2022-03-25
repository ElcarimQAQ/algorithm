#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

int a[N];

struct SegmentTree{

    int val[N << 2];
    int lazy[N << 2];
    
    #define lson rt << 1, l, mid
    #define rson rt << 1 | 1, mid + 1, r

    void pushup(int rt){
        val[rt] = val[rt << 1] + val[rt << 1 | 1];
    }

    void pushdown(int rt, int l ,int r)
    {
        val[rt] += lazy[rt]  * (r - l + 1);
        int mid = l + r >> 1;
        lazy[rt << 1] += lazy[rt] * (mid - l + 1);
        lazy[rt << 1 | 1] += lazy[rt] * (r - mid);
        
        lazy[rt] = 0;
    }

    void build(int rt, int l, int r)
    {
        if(l == r){
            val[rt] = a[l]; 
            return ;
        }
        int mid = l + r >> 1;
        build(lson);
        build(rson);
        pushup(rt);
    }

    void update(int rt, int l, int r, int x, int v){
        if(l == r){
            val[rt] += v;
            return ;
        }
        int mid = l + r >> 1;
        if(x <= mid) update(lson, x, v);
        else update(rson, x, v);

        pushup(rt);
    }

    void updateRange(int rt ,int l, int r, int ql, int qr, int v)
    {
        if(ql <= l && r <= qr){
            lazy[rt] += v;
            return ;
        }

        if(lazy[rt]) pushdown(rt, l, r);

        int mid = l + r >> 1;
        
        if(qr <= mid) updateRange(lson, ql, qr, v);
        else if(ql > mid) updateRange(rson, ql, qr, v);
        else{
            updateRange(lson, ql, mid, v);
            updateRange(rson, mid + 1, qr, v);
        }

        pushup(rt);
    }

    int querry(int rt ,int l,int r,int ql,int qr){
        if(ql <= l&& qr >= r)
            return val[rt];
        int mid =  l + r >> 1;
        int res = 0;
        if( ql <= mid) res += querry(rt << 1,l,mid,ql, qr);
        if( qr > mid) res += querry(rt << 1 | 1,mid+1,r, ql , qr);
    }

};
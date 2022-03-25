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
int tree[4 * maxn][420];
int ans[300];
int tmp[300];
int n;
struct edge
{
    int u,v,w;
}ed[maxn],ee[maxn];

bool cmp(edge a,edge b)
{
    return a.w < b.w;
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
    pre[fx] = fy;
}

void pushup(int x,int l,int r){
    for(int i = 1;i <= n; i++){
        pre[i] = i;
        tree[x][i] = 0;
    }
    int p = 1,q = 1;
    for(int i = 0 ; i < n ;){
        int e1 = tree[l][p];
        int e2 = tree[r][q];
        if(e1 == 0 && e2 == 0)
            break;
        if(e2 == 0 || (ed[e1].w <= ed[e2].w && (e1 != 0))){
            int uu = ed[e1].u;
            int vv = ed[e1].v;
            if(find(uu) != find(vv)){
                merge(uu,vv);
                i++;
                tree[x][i] = e1;
            }
            p++;
        }
        else{
            int uu = ed[e2].u;
            int vv = ed[e2].v;
            if(find(uu) != find(vv)){
                merge(uu,vv);
                i++;
                tree[x][i] = e2;
            }
            q++;
        }
    }
}
void hebin(int l)
{
    for(int i = 1;i <= n; i++){
        pre[i] = i;
        tmp[i] = 0;
    }
    int p = 1,q = 1;
    for(int i = 0 ; i < n ;){
        int e1 = tree[l][p];
        int e2 = ans[q];
        if(e1 == 0 && e2 == 0)
            break;
        if(e2 == 0 || (ed[e1].w < ed[e2].w &&e1 != 0)){
            int uu = ed[e1].u;
            int vv = ed[e1].v;
            if(find(uu) != find(vv)){
                merge(uu,vv);
                i++;
                tmp[i] = e1;
            }
            p++;
        }
        else{
            int uu = ed[e2].u;
            int vv = ed[e2].v;
            if(find(uu) != find(vv)){
                merge(uu,vv);
                i++;
                tmp[i] = e2;
            }
            q++;
        }
    }
    for(int i = 1;i <= n; i++ )
        ans[i] = tmp[i];
}

void build(int p, int l, int r)
{
    if(l == r){
        tree[p][1] = l;
        return ;
    }
    int m = (l + r) / 2;
    build(p*2, l, m);
    build(p*2+1, m+1, r);
    pushup(p,p*2,p*2+1);
}

void change(int p,int l,int r,int pos)
{
    if(l == r){
        return ;
    }
    int m = (l + r) / 2;
    if(pos <= m)
        change(p*2, l, m, pos);
    else
        change(p*2+1, m+1, r ,pos);
    pushup(p, p*2, p*2+1);
        
}
void qurry(int p,int l,int r,int x,int y)
{
    if(x <= l && y >= r){
        hebin(p);
        return;
    }
    int m = (l + r) / 2;
    if(x <= m)
        qurry(p*2, l, m ,x ,y);
    if(y > m)
        qurry(p*2+1, m+1, r, x ,y);
}

int main()
{
    int m,q;
    cin>>n>>m>>q;
    for(int i = 1;i <= m;i++)
        cin>>ed[i].u>>ed[i].v>>ed[i].w;
    build(1,1,m);
    while(q--){
        int opt,x,y,z,t,l,r;
        cin>>opt;
        if(opt == 1){
            cin>>x>>y>>z>>t;
            ed[x].u = y;
            ed[x].v = z;
            ed[x].w = t;
            change(1,1,m,x);
        }
        else{
            cin>>l>>r;
            memset(ans,0,sizeof(ans));
            qurry(1,1,m,l,r);
            ll sum = 0;
            if(ans[n-1] == 0)
                cout<<"Impossible"<<endl;
            else
            {
                for(int i =  1;i <= n-1 ;i++)
                    sum += ed[ans[i]].w;
                cout<<sum<<endl;
            }
        }
    }
    return 0;
}
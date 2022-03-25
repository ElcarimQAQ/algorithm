#include <bits/stdc++.h>
using namespace  std;
#define  INF 0x3f3f3f3f
const int maxn = 2000005;
typedef long long ll;
int a[maxn];
int pre[maxn];

void init(int x)
{
    for(int i = 1;i <= x;i++)
        pre[i] = i;
}

int find(int x)
{
    if(x == pre[x]) return pre[x];
    else return pre[x] = find(pre[x]);
}

void merge(int a,int b)
{
    int p = find(a);
    int q = find(b);
    if(p != q)
        pre[p] = q;
}

int main()
{
    int n;
    cin>>n;
    init(maxn-5);
    for(int i = 1;i <= n; i++){
        cin>>a[i];
        int x = find(a[i]);
        cout<<x<<" ";
        pre[x] = x+1;

    }
    
    return 0;
}
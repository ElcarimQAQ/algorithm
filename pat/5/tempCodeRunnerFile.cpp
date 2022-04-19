#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int maxn = 10005;
#define INF 0x3f3f3f3f
int node[maxn];
int t[maxn];
int cnt = 0;
int n;
// void build(int l, int r,int n,int cnt) {
//     if(r < l)
//         return;
//     int p;
//     int h = log(n+1) / log(2) + 1; // log_2^(n+1)
//     int lastN = n - pow(2,h - 1) + 1;
//     if(lastN <= pow(2,h - 2)) p = pow(2, h-1) / 2 + lastN - 1;
//     else p = pow(2, h) / 2 + lastN - pow(2,h - 2) - 1;
//     int root = node[l + p];
//     t[cnt] = root;
//     build(l , l + p - 1, p - 1, cnt * 2);
//     build(l + p + 1, r, n - p, cnt * 2 + 1);
// }

void dfs(int i) {
    if(i * 2 <= n ) dfs(i*2);
    t[i] = node[cnt++];
    if(i*2 + 1 <= n) dfs(i*2 + 1);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i = 0 ;i < n;i++)
        cin>>node[i];
    sort(node , node + n );
    // build(0 , n - 1, n, 1);
    dfs(1);
    for(int i = 1;i <= n; i++)
        cout<<t[i]<<" ";
    // cout<<root;
    return 0;
}
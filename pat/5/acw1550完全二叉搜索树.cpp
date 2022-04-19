#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const int maxn = 10005;
#define INF 0x3f3f3f3f
int node[maxn];
int t[maxn];
int cnt = 0;
int n;

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
    dfs(1);
    for(int i = 1;i <= n; i++)
        cout<<t[i]<<" ";
    return 0;
}
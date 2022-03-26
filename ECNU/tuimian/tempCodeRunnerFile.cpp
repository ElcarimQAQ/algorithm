#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e4+5;
bitset<maxn> g[maxn];

int main()
{
    int n,m,u,v,q,s,t;
    cin>>n>>m;
    while(m--){
        cin>>u>>v;
        g[u][v] = 1;
        g[v][u] = 1;
    }   
    cin>>q;
    while(q--){
        cin>>s>>t;
        int cnt = 0;
        bitset <maxn> tmp = (g[s] & g[t]);
        cnt = tmp.count();
        cout<<cnt<<endl;
    }
    return 0;
}
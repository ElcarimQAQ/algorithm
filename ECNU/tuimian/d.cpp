#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e4+5;
map<int, set<int> > g;


int main()
{
    int n,m,u,v,q,s,t;
    cin>>n>>m;
    while(m--){
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
    }   
    cin>>q;
    while(q--){
        cin>>s>>t;
        int cnt = 0;
        set<int>::iterator it1 = g[s].begin();
        set<int>::iterator it2 = g[t].begin();
        // cout<<*it1<<endl;
        while (it1 != g[s].end() && it2 != g[t].end()) 
        {
            if( *it1 < *it2)
                it1++;
            else if( *it1 == *it2){
                it1++;
                it2++;
                cnt++;
            }
            else
                it2++;
        }
        cout<<cnt<<endl;
    
    }
    return 0;
}
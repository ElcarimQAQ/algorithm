#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+5;

map<int, int> pa;

set<pair<int,int>> edge;
set<int> pe;
vector< pair<int, pair<int,int>>> query;

int find(int p){
    if(pa[p] == p)
        return p;
    else
        return pa[p] = find(pa[p]);

}

int main(){
    int n, m ,q, u, v,op;
    cin>>n>>m>>q;
    while(m--){
        cin>>u>>v;
        if(pe.find(u) == pe.end()){
            pe.insert(u);
            pa[u] = u;
        }
        if(pe.find(v) == pe.end()){
            pe.insert(v);
            pa[v] = v;
        }
        if(v < u){
            int t = v;
            v = u;
            u = t;
        }
        edge.insert({u,v});
    }
    while(q--){
        cin>>op>>u>>v;
        if(v < u){
            int t = v;
            v = u;
            u = t;
        }
        if(op == 1) {
            if(edge.find({u, v}) != edge.end()){
                query.push_back({op, {u,v}});
                edge.erase({u, v});
            }
        }
        else
            query.push_back({op, {u,v}});
    }
    for(auto e :edge)
        pa[find(e.first)] = find(e.second);
    vector<int> ans;
    for(int i = query.size()-1; i >= 0; i--){
        int op = query[i].first;
        int u = query[i].second.first;
        int v = query[i].second.second;
        if(op == 2) {
            if(find(u) == find(v))
                ans.push_back(1);
            else
                ans.push_back(0);
        }
        else
            pa[find(u)] = find(v);  
         
    }
    for(int i = ans.size()-1; i >= 0; i--){
        if(ans[i] == 0)    
            cout<<"No"<<'\n';
        else
            cout<<"Yes"<<'\n';
    }
    return 0;
}
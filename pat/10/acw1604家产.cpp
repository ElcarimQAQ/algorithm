#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
vector<pair<int,int>> edge;
int pre[maxn],E[maxn],A[maxn],C[maxn];
set<int> pe;
struct family {
    int id,m,sumE,sumA;

    bool operator < (family const& a) const 
    {
        if(sumA * a.m != a.sumA * m) 
            return sumA * a.m > a.sumA * m;
        return id < a.id;
    }
};
vector<family> ans;


int find(int x) {
    if(x != pre[x]) pre[x] = find(pre[x]);
    return pre[x];
}

int join(int a,int b) {
    int pa = find(a);
    int pb = find(b);
    if(pa != pb) {
        pre[max(pa, pb)] =  min(pa ,pb);
        E[min(pa, pb)] += E[max(pa,pb)];
        A[min(pa, pb)] += A[max(pa,pb)];
        C[min(pa,pb)] += C[max(pa,pb)];
        return 0;
    }
    return 1;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n,id,fa,mo,k,ch,estate,area;
    cin>>n;
    for(int i = 0; i <= maxn; i++) { 
        pre[i] = i;
        C[i] = 1;
    }
    
    for(int i = 0; i < n;i++) {
        cin>>id>>fa>>mo>>k;
        if(fa != -1) edge.push_back({id,fa});
        if(mo != -1) edge.push_back({id,mo});
        pe.insert(id);
        pe.insert(fa);
        pe.insert(mo);
        for(int j = 0; j < k; j++) {
            cin>>ch;
            edge.push_back({id,ch});
            pe.insert(ch);
        }
        cin>>estate>>area;
        E[id] = estate;
        A[id] = area;
    }

    for(auto v : edge) 
        join(v.first, v.second);
    
    

    for(auto v : pe) {
        if(pre[v] == v) 
            ans.push_back({v, C[v], E[v], A[v]});
    }

    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for(auto v : ans) {
        // cout<<v.id<<" "<<v.m<<" "<< v.sumE * 1.0 / v.m<<" "<<v.sumA* 1.0 / v.m<<endl;
        printf("%04d %d %.3lf %.3lf\n",v.id, v.m, v.sumE * 1.0 / v.m, v.sumA* 1.0 / v.m);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int pre[maxn];
set<int> pe;
struct family {
    int id,m,sumE,sumA;
    double avgE,avgA;

    bool operator < (family const& a) const 
    {
        if(avgA != a.avgA) 
            return avgA > a.avgA;
        else return id < a.id;
    }
};

unordered_map<int, pair<int,int>> mp;
unordered_map<int, family> ans;
vector<family> sortA;


int find(int x) {
    if(x != pre[x]) pre[x] = find(pre[x]);
    return pre[x];
}

int join(int a,int b) {
    int mi = min(a,b);
    int ma = max(a,b);
    if(find(mi) != find(ma)) {
        pre[find(ma)] = find(mi);
        return 0;
    }
    return 1;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n,id,fa,mo,k,ch,estate,area;
    cin>>n;
    for(int i = 0; i <= maxn; i++)
        pre[i] = i;
    for(int i = 0; i < n;i++) {
        cin>>id>>fa>>mo>>k;
        join(id,fa);
        join(id,mo);
        pe.insert(id);
        pe.insert(fa);
        pe.insert(mo);
        for(int j = 0; j < k; j++) {
            cin>>ch;
            join(id,ch);
            pe.insert(ch);
        }
        cin>>estate>>area;
        mp[id] = {estate,area};
    }

    for(auto v : pe) {
        if(pre[v] == v) 
            ans[v] = {v,1,mp[v].first, mp[v].second};
        
        int P = pre[v];
        ans[P].m++;
        ans[P].sumE += mp[v].first;
        ans[P].sumA += mp[v].second;  
    }
    for(auto v : ans) {
        v.second.avgA = v.second.sumA * 1.0 / v.second.m;
        v.second.avgE = v.second.avgE * 1.0 / v.second.m;
        sortA.push_back(v.second);
    }
    sort(sortA.begin(),sortA.end());
    cout<<ans.size()<<endl;
    for(auto v : sortA)
        cout<<v.id<<" "<<v.m<<" "<< v.avgE<<" "<<v.avgA<<endl;
    return 0;
}
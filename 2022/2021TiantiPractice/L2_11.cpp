#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int, vector<int> > PIV ;
const int maxn = 10050;
map<vector<int>,int> mp; //模块的个数
vector<PIV> ans;

bool cmp(PIV a, PIV b) {
    if(a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main() 
{
    std::ios::sync_with_stdio(false);
    int n,m,u;
    cin>>n>>m;
    for(int i = 0;i < n; i++ ) {
        vector<int> fu; // bug1，忘记清空
        for(int j = 0;j < m;j++) {
            cin>>u;
            fu.push_back(u);
        }
        if(mp.find(fu) == mp.end()){
            ans.push_back({0,fu});
            mp[fu] = 1;
        } else mp[fu]++;  
    }
 
    for(int i = 0;i <ans.size();i++) 
        ans[i].first = mp[ans[i].second] ;      
    sort(ans.begin(),ans.end(),cmp);
    
    cout<<ans.size()<<endl;;
    for(auto u : ans) {
        cout<<mp[u.second];
        for(auto v : u.second)
            cout<<" "<<v;
        cout<<endl;
    }

    return 0;
}
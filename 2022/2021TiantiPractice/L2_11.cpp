#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
typedef pair<int, vector<int> > PIV ;
const int maxn = 10050;
vector<int> fu;
map<vector<int>,int> mp; //模块的个数
vector<PIV> ans;

bool cmp(PIV a, PIV b) {
    if(a.first == b.first) {
        return a.second > b.second;
    }
    return a.first > b.first;
}

int main() 
{
    std::ios::sync_with_stdio(false);
    int n,m,u;
    cin>>n>>m;
    for(int i = 0;i < n; i++ ) {
        for(int j = 0;j<m;j++) {
            cin>>u;
            fu.push_back(u);
        }
        mp[fu]++;  
        ans.push_back({0,fu});
    }
    for(int i = 0;i < n; i++) {
        ans[i].first = mp[ans[i].second] ;      
    }
    sort(ans.begin(),ans.end(),cmp);
    for(auto v : ans) {
        cout<<v.first<<" ";
        for(auto c :v.second)
            cout<<c<<" ";
        cout<<endl;
    }
    return 0;
}
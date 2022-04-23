#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
vector <pair<int,int>> st;
int vis[maxn] ;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k,s,score1,score2;
    cin>>n>>k>>s;
    for(int i = 0;i <n;i++) {
        cin>>score1>>score2;
        st.push_back({score1, score2});
    }
    sort(st.begin(),st.end());
    // for(int i =0;i<st.size();i ++)
    //     cout<<st[i].first<<" "<<st[i].second<<endl;
    int cnt = 0;
    while(k--) {
        int la = 0;
        for(int i =0;i<st.size();i ++) {
            auto u = st[i];
            if(vis[i] || u.first < 175) continue;
            if(u.first == la && u.second >= s) {
                cnt++;
                vis[i] = 1;
            }
            if(u.first > la) {
                la = u.first;
                cnt++;
                vis[i] = 1;
            }
        }
    }
    cout<<cnt <<endl;
    return 0;
}
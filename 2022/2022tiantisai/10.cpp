#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;


vector<pair<string,string>> t;
bool cmp(pair<string,string> a,pair<string,string> b)
{
    return a.second < b.second;
}
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    string s,e;
    char c;
    while(n--) {
        cin>>s>>c >>e;
        t.push_back({s,e});
    }
    sort(t.begin() ,t.end());
    string la = "00:00:00",en = "23:59:59";
    for(int i = 0;i <t.size();i ++) {
        if(la == t[i].first) {
            la = t[i].second;
            continue;
        }
        cout<<la << " - "<<t[i].first<<endl;
        la = t[i].second;
    }
    if(la != en)
       cout<<la << " - "<<en<<endl;
    return 0;
}
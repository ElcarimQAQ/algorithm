#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 1005;

struct people {
    string name,id;
    int hh,mm,si,day;

    bool operator < (const people &p) const {
        if(hh == p.hh)
            return mm < p.mm;
        return hh <p.hh;
    } 
};
vector<people> re;

unordered_map<string,int> mp;
vector<people> ans;
set<pair<string,string>> WarnP;

int main() 
{
    std::ios::sync_with_stdio(false);
    int d,p,t,s;
    char ch;
    cin>>d>>p;
    for(int i = 1; i<= d; i++) {
        cin>>t>>s;
        re.clear();
        people pe;
        for(int j = 0;j < t; j++) {
            cin>>pe.name>>pe.id>>pe.si>>pe.hh>>ch>>pe.mm;
            if(pe.id.size() != 18) continue;
            re.push_back(pe);
            if(pe.si == 1 ) {
               WarnP.insert({pe.name, pe.id});
            } 
        }
        sort(re.begin(), re.end());
        for(auto now :re){
            if(mp.find(now.id) != mp.end() && i < mp[now.id] + p + 1 )
                continue;
            mp[now.id] = i;
            cout<<now.name<<" "<<now.id<<endl;
            ans.push_back(now);
            s--;
            if(s == 0) break;
        }
    }
    for(auto v :WarnP) 
        cout<<v.first<<" "<<v.second<<endl;
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 1005;
struct people {
    string name,id,time;
    int si,cnt;

    bool operator < (const people &p) const {
        if(time == p.time) {
            return cnt < p.cnt;
        }
        return time < p.time;
    } 
};
vector<people> re;

unordered_map<string,int> lastD,vis;
unordered_map<string,people> mp;
vector<string> WarnP;

bool check(string id) {
    if(id.size() != 18) return false;
    for(auto v :id) {
        if(v < '0' || v > '9') return false; //注意题目必须是数字
    }
    return true;
}

int main() 
{
    std::ios::sync_with_stdio(false);
    int d,p,t,s;
    cin>>d>>p;
    for(int i = 1; i<= d; i++) {
        cin>>t>>s;
        re.clear();
        people pe;
        for(int j = 0; j < t; j++) {
            cin>>pe.name>>pe.id>>pe.si>>pe.time;
            pe.cnt = j;
            if(!check(pe.id)) continue;
            
            re.push_back(pe);
            mp[pe.id] = pe;
            
            if(pe.si == 1 && vis[pe.id] == 0) {
                WarnP.push_back(pe.id);
                vis[pe.id] = 1;
            }
        }

        sort(re.begin(), re.end());
        for(auto now :re){
            if(lastD[now.id] != 0 && i < lastD[now.id] + p + 1 )
                continue;
            lastD[now.id] = i;
            cout<<now.name<<" "<<now.id<<endl;
            s--;
            if(s == 0) break;
        }
    }
    for(auto v :WarnP) {
        cout<<mp[v].name<<" "<<mp[v].id<<endl;
    }
    
    return 0;
}
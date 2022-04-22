#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int maxn = 10005;
unordered_map<string,pair<string,char> > mp;
unordered_set<string> pa; //五代内祖先

int main() 
{
    int n,m;
    cin>>n;
    string Fname,Sname;
    while(n--) {
        cin>>Fname>>Sname;
        int l = Sname.size();
        if(Sname[l - 1] == 'm' || Sname[l - 1] == 'f') 
            mp[Fname] = {"", Sname[l - 1]};
        else if (Sname[l - 1] == 'n') {
            Sname = Sname.substr(0,l - 4);
            mp[Fname] = {Sname, 'm'};
        } else if (Sname[l - 1] == 'r') {
            Sname = Sname.substr(0,l - 7);
            mp[Fname] = {Sname, 'f'};
        } 
        cout<<Sname<<endl;
    }
    cin>>m;
    string f1,s1,f2,s2;
    while(m--) {
        pa.clear();
        cin>>f1>>s1>>f2>>s2;
        if(mp.count(f1) == 0 || mp.count(f2) == 0){
            cout<<"NA"<<'\n';
            continue;
        }
        if(mp[f1].second == mp[f2].second) {
            cout<<"Whatever"<<'\n';
            continue;
        }
        int cnt = 1;
        string p1 = f1,p2 = f2;
        pa.insert(f1);
        pa.insert(f2);
        bool flag = true;
        while(cnt <= 4 ) {
            p1 = mp[p1].first;
            if(pa.count(p1) ==  0)
                pa.insert(p1);
            else {
                flag = false;
                break;
            }
           
            p2 = mp[p2].first;
            if(pa.count(p2) == 0)
                pa.insert(p2);
            else {
                flag = false;
                break;
            }
            cnt++;
        }
        if(flag) cout<<"Yes"<<"\n";
        else cout<<"No"<<'\n';
    }
    return 0;
}
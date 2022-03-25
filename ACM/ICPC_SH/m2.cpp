#include<bits/stdc++.h>
using namespace std;
#define seed 131
int T;
double n,p1,v1,p2,v2;
double x1,x2,x3;
double t1,t2,t3;
map<string,int> mp;
vector<string>s1,s2;

int main()
{
    int t,n,m;
    cin>>t;
    int ans = n;
    while(t--){
        mp.clear();
        s1.clear();
        s2.clear();
        cin>>n>>m;
        string s;
        for(int i= 0 ;i< n+m ;i++){
            cin>>s;
            s1.push_back(s);
            //根
            for(int j = 0 ;j <= s.size(); j++){
                if(s[j] == '/'){
                    string sub = s.substr(0,j);
                    mp[sub]  = 1;
                }
            }
        }
        for(int i = 0;i< m;i++){
            cin>>s;
            for(int j = 0 ;j <= s.size(); j++){
                if(s[j] == '/'){
                    string sub = s.substr(0,j);
                    if(mp[sub] == 1){
                        mp[sub] = 2;
                    }
                    if(mp[sub] == 2)
                        ans--;
                    //if(mp[sub] == 0)
                }
            }
        }
        cout<<ans<<endl;    
    }
    system("pause");
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define seed 131
int T;
double n,p1,v1,p2,v2;
double x1,x2,x3;
double t1,t2,t3;
vector<string>s1,s2;
map<string,int>mp;
vector<string>ml;
int main()
{
    int t,n,m;
    cin>>t;
    while(t--){
        mp.clear();
        s1.clear();
        s2.clear();
        cin>>n>>m;
        string s;
        int sum = 0;//根
        for(int i = 0 ;i < n ;i++){
            cin>>s;
            s1.push_back(s);
            mp[s]++;
            for(int j = s.size()-1;j >= 0; j--){
                if(s[j] == '/'){
                    string ss=s.substr(0,j-1);
                    if( mp[ss] != 0){
                        sum++;
                        mp[ss]++;
                        ml.push_back(ss);
                        break;
                    }
                    mp[ss]++;
                }
            }
        }
        int sum =0;
        for(int i = 0;i< m;i++){
            cin>>s;
            s2.push_back(s);
            for(int j = s.size();j>=0;j--){
                if(s[j] == '/'){
                    string ss = s.substr(0,j);
                    if(mp[ss]){
                        sum ++;
                        break;
                    }
                }
            }
        }
        cout<<mp.size()-sum<<endl;
    }
    system("pause");
    return 0;
}
#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=2005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
vector<int> g[maxn];
vector<string> str1,str2;
map<string,int> vis;
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
     ios::sync_with_stdio(false); cin.tie(0);
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        string s;
        vis.clear();
        str1.clear();
        str2.clear();
        for(int i = 0; i< n;i++){
            cin>>s;
            str1.push_back(s);
        }
        for(int i = 0; i< m;i++){
            cin>>s;
            str2.push_back(s);
            string ss="";
            for(int j = 0; j < s.size(); j++){
                ss += s[j];
                if(s[j] == '/'||j == s.size() - 1){
                    vis[ss] = 1;
                   // cout<<ss<<endl;
                }
            }
        }
        int ans = n;
        for(int i = 0;i < n; i++){
            string ss = "";
            for(int j = 0;j < str1[i].size(); j++){
                ss += str1[i][j];
                if(str1[i][j] == '/'||j == str1[i].size() - 1){
                    //cout<<ss<<endl;
                    if(vis[ss] == 2){
                        ans--;
                        break;
                    }
                    if(vis[ss] == 0)
                        vis[ss] = 2;

                }
                //cout<<ss<<endl;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
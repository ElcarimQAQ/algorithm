#include<bits/stdc++.h>
#include <iostream>
using namespace std;
const int maxn  = 20005;
string s1,s2;
set<char> vis;
map<char,int> mp;
bool check(int l,int r)
{
    mp.clear();
    for(int i = l;i <= r;i++){
        // cout<<i << r<<endl;
        // cout<<s1[i]<<endl;
        if(vis.count(s1[i]) == 0 || mp[s1[i]] == 1){
            return false;   
        }
        mp[s1[i]] = 1;
    }    
    return true;
}
int main() {
    cin>>s1>>s2;
    for(int i = 0;i< s2.size();i++){
        vis.insert(s2[i]);  
    }
    int ans = 0;
    int n = s1.size(),m = s2.size();
    for(int i = 0;i < n;i++){
        int j  = i + m ;
        if(check(i,j-1)){
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}
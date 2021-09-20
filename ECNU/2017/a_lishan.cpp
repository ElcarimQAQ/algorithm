#include<bits/stdc++.h>
using namespace std;

struct node{
    string sign;
    int c;
};

unordered_map<int,int> mp;
vector<node> eql;

int main()
{
    int n;
    string x,sign;
    int c;
    cin>>n;
    while(n--){
        cin>>x>>sign>>c;
        mp[c-1]++;
        mp[c]++;  
        mp[c+1]++;  
        node a;
        a.sign = sign;
        // cout<<sign<<endl;
        a.c = c;
        eql.push_back(a);
    }
    int ma = 0;
    for(auto v:mp){
        int cnt = 0;
        for(auto u : eql){
            // cout<<u.sign<<endl;
            if (u.sign == "<"){
                if(v.first < u.c)
                    cnt++;
            }
            if(u.sign == "<="){
                if(v.first <= u.c)
                    cnt++;
            }
            if(u.sign == "="){
                if(v.first == u.c)
                    cnt++;
            }
            if(u.sign == ">"){
                if(v.first > u.c)
                    cnt++;
            }
            if(u.sign == ">="){
                if(v.first >= u.c)
                    cnt++;
            }     
        }
        ma = max(ma,cnt);
    }
    cout<<ma<<endl;
    return 0;
}
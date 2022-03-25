#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=200005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
string str[maxn];
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin.sync_with_stdio(false);
    int n,q;
    cin>>n; 
    string s;
    for(int i =1 ;i <= n; i++){
       cin>>str[i];
       sort(str[i].begin(),str[i].end());
    }
    cin>>q;
    while(q--){
        cin>>s;
        sort(s.begin(),s.end());
        int cnt = 0;
        for(int i =1;i <= n; i++) {
            if(s == str[i])
                cnt++;    
        }
        cout<<cnt<<endl;
    }
    return 0;
}
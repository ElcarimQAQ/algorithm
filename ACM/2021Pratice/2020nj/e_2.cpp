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
int vis[10];
int a[4] = {0,1,2,3};
char c[4] = {'U','D','L','R'};
int dir[4][2] = {0,1,0,-1,-1,0,1,0};
string ans;
bool judge(int x,int y)
{
    ans.clear();
    int nx = 0,ny = 0;
    for(int i = 0;i < 4 ;i++){
        int cnt = vis[a[i]];
        while(cnt--){
            ans += c[a[i]];
            nx += dir[a[i]][0];
            ny += dir[a[i]][1];
            if(nx == x && ny == y)
                return false;
        }
    }
    return true;
}
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
    int t,x,y;
    cin>>t;
    string s;
    while(t--){
        int f = 0;
        sort(a,a+4);
        memset(vis,0,sizeof(vis));
        cin>>x>>y;
        cin>>s;
        if(x == 0 && y == 0){
            cout<<"Impossible"<<endl;
            continue;
        }
        for(int i = 0;i < s.size();i++){
            if(s[i] == 'U')
                vis[0]++;
            if(s[i] == 'D')
                vis[1]++;
            if(s[i] == 'L')
                vis[2]++;
            if(s[i] == 'R')
                vis[3]++;
        }
        do
        {
            if(judge(x,y)){
                f = 1;
                break;
            }
        }while(next_permutation(a,a+4));            
        if(f)
            cout<<ans<<endl;
        else
            cout<<"Impossible"<<endl;
    }
    return 0;
}
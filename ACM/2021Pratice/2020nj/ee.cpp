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

int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
    int t,x,y;
    cin>>t;
    string s;
    while(t--){
        string ans;
        string str;
        memset(vis,0,sizeof(vis));
        cin>>x>>y;
        cin>>s;
        for(int i = 0;i< s.size();i++){
            if(s[i] == 'L')
                vis[1]++;
            if(s[i] == 'R')
                vis[2]++;
            if(s[i] == 'U')
                vis[3]++;
            if(s[i] == 'D')
                vis[4]++; 
        }
        int nx,ny;
        nx =vis[2] - vis[1];
        ny = vis[3] - vis[4];
        if((nx == x && ny ==y) || (x == 0 && y == 0)){
            cout<<"Impossible"<<endl;
            continue;
        }
        if(x != 0 && y!= 0){
            if(x != nx){
                for(int i = 0;i < vis[1] ;i++)
                    ans += 'L';
                for(int i = 0;i < vis[2] ;i++)
                    ans += 'R';
                for(int i = 0;i < vis[3] ;i++)
                    ans += 'U';
                for(int i = 0;i < vis[4] ;i++)
                    ans += 'D';
                cout<<ans<<endl;
                continue;
            }
            if(y != ny){
                for(int i = 0;i < vis[3] ;i++)
                    ans += 'U';
                for(int i = 0;i < vis[4] ;i++)
                    ans += 'D';
                for(int i = 0;i < vis[1] ;i++)
                    ans += 'L';
                for(int i = 0;i < vis[2] ;i++)
                    ans += 'R';
                cout<<ans<<endl;
                continue;
            }
        }
        if(x==0 || y == 0){
            if(x == 0){
                if(vis[1] != 0 || vis[2] != 0){
                    if(vis[1] > vis[2]){
                        for(int i = 0;i < vis[1];i++)
                            ans += 'L';
                        for(int i = 0;i < vis[3] ;i++)
                            ans += 'U';
                        for(int i = 0;i < vis[4] ;i++)
                            ans += 'D';
                        for(int i = 0;i < vis[2] ;i++)
                            ans += 'R';
                    }
                    else{
                         for(int i = 0;i < vis[2] ;i++)
                            ans += 'R';
                        for(int i = 0;i < vis[3] ;i++)
                            ans += 'U';
                        for(int i = 0;i < vis[4] ;i++)
                            ans += 'D';
                        for(int i = 0;i < vis[1] ;i++)
                            ans += 'L';
                    }
                }
                else{
                    if(abs(ny) >= abs(y) && ny*y >0){
                    cout<<"Impossible"<<endl;
                    continue;
                    }
                    if(y>0){
                        for(int i = 0;i < vis[4] ;i++)
                            ans += 'D';
                         for(int i = 0;i < vis[3] ;i++)
                            ans += 'U';
                    }
                    else{
                        for(int i = 0;i < vis[3] ;i++)
                            ans += 'U';
                        for(int i = 0;i < vis[4] ;i++)
                            ans += 'D';
                    }
                }
            }
            else{
                if(vis[3] != 0 || vis[4] != 0){
                    if(vis[3] > vis[4]){
                        for(int i = 0;i < vis[3] ;i++)
                            ans += 'U';
                        for(int i = 0;i < vis[1] ;i++)
                            ans += 'L';
                        for(int i = 0;i < vis[2] ;i++)
                            ans += 'R';
                        for(int i = 0;i < vis[4] ;i++)
                            ans += 'D';
                    }
                    else{
                        for(int i = 0;i < vis[4] ;i++)
                            ans += 'D';
                        for(int i = 0;i < vis[1] ;i++)
                            ans += 'L';
                        for(int i = 0;i < vis[2] ;i++)
                            ans += 'R';
                        for(int i = 0;i < vis[3] ;i++)
                            ans += 'U';
                    }
                }
                else{
                     if(abs(nx) >= abs(x) && nx*x >0){
                    cout<<"Impossible"<<endl;
                    continue;
                }
                    if(x > 0){
                        for(int i = 0;i < vis[1] ;i++)
                            ans += 'L';
                        for(int i = 0;i < vis[2] ;i++)
                            ans += 'R';
                    }
                    else{
                        for(int i = 0;i < vis[2] ;i++)
                            ans += 'R';
                         for(int i = 0;i < vis[1] ;i++)
                            ans += 'L';
                    }
                }
            }
            cout<<ans<<endl;
        }
        
    }
    return 0;
}
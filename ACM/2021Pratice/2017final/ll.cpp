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
int t,a,b,c,d;
int vis[4][4][3] = {1,0,-1,1,0,-1,1,0,-1,1,0,-1};

int dfs(int s)
{
    int cnt =0;
    int score = 0;
    int w1 = 0,l1= 0,t1= 0;
    int w2 = 0,t2= 0;
    int w3 = 0,t3= 0;
    int w4 = 0,t4= 0;
    for(int i =0 ;i < 3;i++){
        for(int j =0 ;j < 3;j++){
            for(int k =0;k < 3;k++){
                for(int m =0 ;m < 3;m++){
                    if(vis[1][i] == 1)
                        w1++;
                    if(vis[j] == 1)
                        w2++;
                    if(vis[k] == 1)
                        w3++;
                    if(vis[m] == 1)
                        w4++;
                    if(vis[i] == 0)
                        t1++;
                    if(vis[j] == 0)
                        t2++;
                    if(vis[k] == 0)
                        t3++;
                    if(vis[m] == 0)
                        t4++;
                     /*
                    if(vis[i] == -1)
                        l++;
                    if(vis[j] == -1)
                        l++;
                    if(vis[k] == -1)
                        l++;
                    if(vis[m] == -1)
                        l++;
                    */
                    if(3 * w1 + 1 * t == s)
                        cnt++;
                    }
                }
            }
        }
    }
    return cnt;
}
             


int main()
{
    //freopen("data.in","r",stdin);
    //freopen("1.out","w",stdout);
    cin>>t;
    for(int cas =1;cas <=t ;cas++){
        cin>>a>>b>>c>>d;
    }
    // system("pause");
    return 0;
}
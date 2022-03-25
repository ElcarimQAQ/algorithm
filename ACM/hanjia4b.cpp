#include<bits/stdc++.h>
#include <algorithm>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=1e4+7;
typedef long long ll;
const int mod=1e9+7;
#define pi acos(-1)
#define INF 0x3f3f3f3f
int g[maxn][maxn];

void slove(int x,int y,int k){
    int cnt =0;
    for(int i = 1; i <= k;i++){
        for(int j = 1; j<= k;j++){
            if(i%2 == 1)
                g[x+i-1][y+j-1] = ++cnt;
            else if(i==2)
                g[x+i-1][y-j+1] = ++cnt; 
        }
        if(i%2==1)
            y = y+k-1;
        else 
            y = y-k+1;
    }
}


int main ()
{
    //freopen("data.in", "r", stdin);
    //freopen("1.out", "w", stdout);	
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,x,y,k;
    cin>>n>>m;
    while(m--){
        cin>>x>>y>>k;
        slove(x,y,k);    
    }
    for(int i =1 ;i <= n;i++){
        for(int j =1; j<=n;j++)
            if(j==n)
                cout<<g[i][j]<<endl;
            else
                cout<<g[i][j]<<" ";
    }
    return 0;
}

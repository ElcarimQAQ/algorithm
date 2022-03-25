#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define INF 0x7fffffff;
using namespace std;
int s1,s2,m,n;
int vis[25];
int a[25];
int dir[2]={0,1};
int cnt=0;
void dfs(int x){
    if(x>m+n)
        return;
    if(a[x]==0&&vis[x]==2&&x==m+n){
        cnt++;
        return;
    }
    for(int i=0;i<2;i++){
        if(dir[i]==0&&s1<m){
            s1++;
            a[x+1]=2*a[x];
            vis[x+1]=1;
            dfs(x+1);
            s1--;
        }
        if(dir[i]==1&&s2<n){
            s2++;
            vis[x+1]=2;
            a[x+1]=a[x]-1;
            dfs(x+1);
            s2--;
        }
        vis[x+1]=0;
    }
}
int main (){
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    cin>>m>>n;
    s1=s2=0;
    //memset(a,1,sizeof(a));
    memset(vis,0,sizeof(vis));
    a[0]=2;
    dfs(0);
    printf("%d\n",cnt);
    return 0;
}



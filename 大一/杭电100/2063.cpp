#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int map[505][505];
int vis[505];
int pre[505];
int k,m,n,a,b,cnt;
int find(int x){
    for(int i=1;i<=m;i++){
        if(vis[i]==0&&map[i][x]){
            vis[i]=1;
            if(pre[i]==0||find(pre[i])){
                pre[i]=x;
                return 1;
            }
        }
    }
    return 0;
    }

int main ()
{
    //freopen("D:\\input.txt","r",stdin);
    while(~scanf("%d",&k)&&k!=0){
        cin>>m>>n;
        memset(map,0,sizeof(map));
        memset(pre,0,sizeof(pre));
        while(k--){
            cin>>a>>b;
            map[a][b]=1;
        }
            cnt=0;
            for(int i=1;i<=n;i++){
                memset(vis,0,sizeof(vis));
                if (find(i))
                    cnt++;
            }
    printf("%d\n",cnt);
    }
    return 0;
}


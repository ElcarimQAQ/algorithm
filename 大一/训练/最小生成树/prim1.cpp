#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define INF 0x7fffffff
#define M 10000+10
using namespace std;
int map[M][M],dis[M],vis[M],edge[M];
struct node{
    int x,y;
}po[M];
int n,m;
void init()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&po[i].x,&po[i].y);
        for(int j=1;j<i;j++)
            map[i][j]=map[j][i]=(po[i].x-po[j].x)*(po[i].x-po[j].x)+(po[i].y-po[j].y)*(po[i].y-po[j].y);
        map[i][i]=INF;
    }
    scanf("%d",&m);
    int x,y;
    while(m--){
        scanf("%d%d",&x,&y);
        map[x][y]=map[y][x]=0;
    }
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    for(int i=1;i<=n;i++){
        dis[i]=map[i][1];
        edge[i]=1;
    }
}
void prim(){
    for(int i=1;i<n;i++){
        int minn=INF;
        int po_min;
        for(int j=1;j<=n;j++){
            if(vis[j]==0&&minn>dis[j]){
                minn=dis[j];
                po_min=j;
            }
        }
        vis[po_min]=1;
        for(int k=1;k<=n;k++){
            if(vis[k]==0&&dis[k]>map[po_min][k]){
                edge[k]=po_min;
                dis[k]=map[po_min][k];
            }
        }
        if(map[edge[po_min]][po_min])
            printf("%d %d\n",edge[po_min],po_min);
    }
}
int main ()
{
    freopen("D:\\input.txt", "r", stdin);
    init();
    prim();
    return 0;
}


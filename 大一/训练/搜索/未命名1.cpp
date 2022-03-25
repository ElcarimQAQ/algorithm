#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define INF 0x7fffffff;
using namespace std;
int maze[10][10];
int vis[10][10];
int dr[4][2]={0,1,0,-1,1,0,-1,0};
struct node{
    int x,y;
    node last;
};
void pr(node n){
    pr(n.last);
    printf("(%d,%d)\n",n.x-1,n.y-1);
}
void bfs(){
    node a,next;
    vis[1][1]=1;
    a.x=1;
    a.y=1;
    queue<node> q;
    q.push(a);
    while(q.size()){
        a=q.front();
        q.pop();
        if(a.x==5&&a.y==5){
            pr(a);
            break;
        }
        for(int i=0;i<4;i++){
            next.x=a.x+dr[i][0];
            next.y=a.y+dr[i][1];
            if(vis[next.x][next.y]==0&&maze[next.x][next.y]==0&&next.x>=1&&next.x<=5&&next.y>=1&&next.y<=5){
                q.push(next);
                next.last=a;
                vis[next.x][next.y]=1;
            }
        }
    }


}
int main ()
{
    freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++)
            scanf("%d",&maze[i][j]);
    memset(vis,0,sizeof(vis));
    bfs();
}


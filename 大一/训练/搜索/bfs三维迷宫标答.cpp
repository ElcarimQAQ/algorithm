#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
using namespace std;
 
char maps[35][35][35];
int vis[35][35][35];
int df[6][3]={0,1,0,0,-1,0,1,0,0,-1,0,0,0,0,1,0,0,-1};
int l,r,c,sx,sy,sz,ex,ey,ez;
 
struct node{
    int x,y,z,step;
};
 
int main(){
	freopen("D:\\input.txt", "r", stdin);
    int i,j,k;
    while(scanf("%d%d%d",&l,&r,&c)){
        if(l==0&&r==0&&c==0)
            break;
        for(i=0;i<l;i++){
            for(j=0;j<r;j++){
                scanf("%s",maps[i][j]);
                for(k=0;k<c;k++){
                    if(maps[i][j][k]=='S'){
                        sx=i;sy=j;sz=k;
                    }
                    if(maps[i][j][k]=='E'){
                        ex=i;ey=j;ez=k;
                    }
                }
            }
        }
        memset(vis,0,sizeof(vis));
        int ans=0;
        queue<node> que;
        node a,next;
        a.x=sx; a.y=sy; a.z=sz; a.step=0;
        que.push(a);
        vis[a.x][a.y][a.z]=1;
        while(!que.empty()){
            a=que.front();
            que.pop();
            if(a.x==ex&&a.y==ey&&a.z==ez){   ans=a.step; break;  }
            for(i=0;i<6;i++){
                next=a;
                next.x=a.x+df[i][0];
                next.y=a.y+df[i][1];
                next.z=a.z+df[i][2];
                if(next.x<0||next.y<0||next.z<0||next.x>=l||next.y>=r||next.z>=c||vis[next.x][next.y][next.z]==1||maps[next.x][next.y][next.z]=='#')
                    continue;
                vis[next.x][next.y][next.z]==1;
                next.step=a.step+1;
                que.push(next);
            }
        }
        if(ans)
            printf("Escaped in %d minute(s).\n",ans);
        else
            printf("Trapped!\n");
    }
    return 0;
}
 
 


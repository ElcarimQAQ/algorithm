#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define INF 0x7fffffff;
using namespace std;
int v[25][25];
int vis[25][25];
char s[25][25];
int fa[8]={0,1,1,0,-1,0,0,-1};
int n,m;
struct node{
    int x,y;
};
bool check(node ne){
    if(ne.x>0&&ne.y>0&&ne.x<=n&&ne.y<=m&&s[ne.x][ne.y]!='@'&&s[ne.x][ne.y]==0){
        //printf("?\n");
        return 1;
    }
        return 0;
}

void bfs(node st){
    queue<node>q;
    node next,now;
    q.push(st);
    vis[st.x][st.y]=1;
    //printf("?\n");
    while(!q.empty()){
        int c;
        now=q.front();
        q.pop();
        for(int i=0;i<7;i=i+2){
            next.x=now.x+fa[i];
            next.y=now.y+fa[i+1];
            //printf("%d%d\n",next.x,next.y);
            if(check(next)){
                v[next.x][next.y]==1;
                if(s[next.x][next.y]=='#'&&next.x!=0&&next.y!=0)
                    c=vis[now.x][now.y]+2;
                if(s[next.x][next.y]=='.'&&next.x!=0&&next.y!=0)
                    c=vis[now.x][now.y]+1;
                if(vis[next.x][next.y]>c){
                    vis[next.x][next.y]=c;
                    q.push(next);
                   // printf("%d\n",c);
                }
            }
        }
    }
}

int main(){
    freopen("D:\\input.txt", "r", stdin);
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0)
            break;
        else{
                /*
            for(int i=1;i<=n;i++)
                scanf("%s",s[i]);
                */
            for(int i=1;i<=n;i++){
            getchar();
            for(int j=1;j<=m;j++)
                scanf("%c",&s[i][j]);
            }
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(s[i][j]=='*'){
                        s[i][j]='@';//商店
                        for(int k=0;k<7;k=k+2){
                            int a=i+k;
                            int b=j+k+1;
                            if(s[a][b]=='.')
                                s[a][b]='@';//商店附近的路不能走
                        }
                    }
                }
            }
            memset(vis,0,sizeof(vis));
            memset(v,0,sizeof(v));
            node st;
            st.x=1;
            st.y=1;
            bfs(st);
            if(vis[n][m]==0)
                printf("buybuybuy!\n");
            else
                printf("%d\n",vis[n][m]-1);
                /*
            for(int i=1;i<=n;i++){
            	for(int j=1;j<=m;j++)
            		printf("%d",vis[i][j]);
            	printf("\n");


            }
            */

        }
    }
    return 0;
}



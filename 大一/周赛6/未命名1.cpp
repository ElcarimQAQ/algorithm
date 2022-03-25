#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define INF 0x7fffffff;
using namespace std;
int n,k;
int vis[100000];
int d[3];
void bfs(){
    int c;
    memset(vis,-1,sizeof(vis));
    queue<int> q;
    q.push(n);
    vis[n]=0;
    while(!q.empty()){
        c=q.front();
        q.pop();
        if(c==k)
            break;
        else{
        d[0]=c-1;
        d[1]=c+1;
        d[2]=c*2;
            for(int i=0;i<3;i++){
                if(d[i]>=0&&d[i]<=100000&&vis[d[i]]==-1){
                    q.push(d[i]);
                    vis[d[i]]=vis[c]+1;
                }
            }
        }
    }
    printf("%d\n",vis[k]);

}

int main ()
{

    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    cin>>n>>k;
    bfs();
    return 0;
}



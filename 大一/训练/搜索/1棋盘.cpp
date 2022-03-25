#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

char mapn[10][10];
int vis[10];
int cnt;
int sum;
int n,k;
void dfs(int s){
    if(cnt==k){
        sum++;
        return;

    }
    else{
        if(s>=n)
            return;
        else{
            for(int i=0;i<n;i++){
                if(mapn[s][i]=='#'&&!vis[i]){
                    vis[i]=1;
                    cnt++;
                    dfs(s+1);
                    cnt--;
                    vis[i]=0;
                }
            }
            dfs(s+1);
        }


    }
}


int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    while(~scanf("%d%d",&n,&k)){
        if(n==-1&&k==-1)
            break;
       for(int i=0;i<n;i++)
            scanf("%s",mapn[i]);
       cnt=sum=0;
       dfs(0);
       printf("%d\n",sum);
    }
    return 0;
}


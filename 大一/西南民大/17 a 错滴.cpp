#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define INF 0x7fffffff;
using namespace std;
char a[1005][1005];
int b[1005][1005][5];
int main()
{
    freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int n,m,q,x,y;
    char dir;
    scanf("%d%d%d",&n,&m,&q);
    memset(b,0,sizeof(b));
   for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j)
            scanf(" %c",&a[i][j]);
    for(int i = 1;i <= n;++i){
        for(int j = 1;j <= m;++j){
            for(int k=j;j<=m;j++){
                if(a[i][k]=='#'){
                    b[i][j][1]=0;
                    break;
                }
            }
            for(int k=j;j>=1;j--){
                if(a[i][k]=='#'){
                    b[i][j][2]=0;
                    break;
                }
            }
            for(int k=i;k<=n;k--){
                if(a[k][j]=='#'){
                    b[i][j][3]=0;
                    break;
                }
            }
             for(int k=i;k>=1;k--){
                if(a[k][j]=='#'){
                    b[i][j][4]=0;
                    break;
                }
            }
        }
    }

    while(q--){
        int cnt=1;
        scanf("%d%d %c",&x,&y,&dir);
        if(dir=='R'){
            if(b[y][x][1]==0){
                 printf("NO\n");
                cnt=0;
            }
        }
         if(dir=='L'){
            if(b[y][x][2]==0){
                 printf("NO\n");
                cnt=0;
            }
        }
         if(dir=='D'){
            if(b[y][x][3]==0){
                 printf("NO\n");
                cnt=0;
            }

        }
        if(dir=='U'){
            if(b[y][x][1]==0){
                 printf("NO\n");
                cnt=0;
            }
        }
        if(cnt==1)
            printf("YES\n");
    }
    return 0;
}

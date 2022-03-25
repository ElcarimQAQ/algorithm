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
int main()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int n,m,q,x,y;
    char dir;
    scanf("%d%d%d",&n,&m,&q);
   for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j)
                scanf(" %c",&a[i][j]);
    while(q--){
        int cnt=1;
        scanf("%d%d %c",&x,&y,&dir);
        if(dir=='R'){
            for(int j=y;j<=m;j++){
                if(a[x][j]=='#'){
                    printf("NO\n");
                    cnt=0;
                    break;
                }
            }
        }
         if(dir=='L'){
            for(int j=y;j>=1;j--){
                if(a[x][j]=='#'){
                    printf("NO\n");
                    cnt=0;
                    break;
                }
            }
        }
         if(dir=='D'){
            for(int i=x;i<=n;i++){
                //printf("%c",a[i][y]);
                if(a[i][y]=='#'){
                    printf("NO\n");
                    cnt=0;
                    break;
                }
            }
        }
        if(dir=='U'){
            for(int i=x;i>=1;i--){
                if(a[i][y]=='#'){
                    printf("NO\n");
                    cnt=0;
                    break;
                }
            }
        }
        if(cnt==1)
            printf("YES\n");
    }
    return 0;
}


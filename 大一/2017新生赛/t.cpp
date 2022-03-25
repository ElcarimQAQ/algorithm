#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[4][4],b[4][4];

int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    memset(b,1,sizeof(b));//Å¼Êý¹Ø±Õ
     for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            scanf("%d",&a[i][j]);
            while(a[i][j]--){
                b[i-1][j]++;
                b[i][j-1]++;
                b[i][j]++;
                b[i][j+1]++;
                b[i+1][j]++;
            }
        }
     }
     for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            printf("%d",b[i][j]%2);
        }
        printf("\n");
     }
     return 0;
}


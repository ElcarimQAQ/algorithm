#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define INF 0x7fffffff;
using namespace std;
int a[1005];
int main (){
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int b,c;
    while(~scanf("%d%d",&b,&c)){
        memset(a,0,sizeof(a));
        int sum;
        sum=b+c;
        int i=1;
        if(sum==0)
            printf("%d\n",0);
        else{
            while(sum>0){
                if(i%4==0){
                    a[i++]=-1;
                    continue;
                }
                a[i++]=sum%10;
                sum/=10;
            }
            //printf("%d\n",i);
            for(int j=i-1;j>0;j--){
                if(a[j]==-1)
                    printf(",");
                else
                    printf("%d",a[j]);
            }
            printf("\n");
        }
    }

    return 0;
}



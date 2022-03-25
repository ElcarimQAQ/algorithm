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
    int x;
    while(~scanf("%d",&x)){
        int j=1;
        for(int i=0;i<=x/2;i++){
            printf("%d. %d+%d=\n",j++,i,x-i);
        }
    }
    return 0;
}


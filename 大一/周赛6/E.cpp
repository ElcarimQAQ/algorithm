#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define INF 0x7fffffff;
using namespace std;

int main(){

    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int t,n,k;
    cin>>t;
    while(t--){
        scanf("%d%d",&n,&k);
        if(k>=n)
            printf("A\n");
        else if(n%2==1&&k==1)
            printf("A\n");
        else
            printf("B\n");
    }
    return 0;
}


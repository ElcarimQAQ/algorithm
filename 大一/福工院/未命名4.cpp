#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int judge(int x1,int y1,int x2,int y2,int x3,int y3,int x,int y){
    int cnt=0;
    if((x2-x)*(x1-x)+(y2-y)*(y1-y)>0)
        cnt++;
    if((x2-x)*(x3-x)+(y2-y)*(y3-y)>0)
        cnt++;
    if((x1-x)*(x3-x)+(y1-y)*(y3-y)>0)
        cnt++;
    if(cnt>=2)
        return 0;
    else
        return 1;

}

int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int x1,y1,x2,y2,x3,y3,x,y;
    while(~scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3)){
        scanf("%d%d",&x,&y);
        if(judge(x1,y1,x2,y2,x3,y3,x,y))
            printf("YES\n");
        else
            printf("N0\n");
    }
    return 0;
}

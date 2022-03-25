#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[105];
struct point{
    int x,y;
};

bool cmp1(point p1,point p2){
    return p1.x<p2.x;
}

bool cmp2(point p1,point p2){
    return p1.y<p2.y;
}

int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
     int t,n;
     point p[1005];
     cin>>t;
     while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)
            scanf("%d%d",&p[i].x,&p[i].y);
        sort(p+1,p+n+1,cmp1);
        int l=p[n].x-p[1].x;
        sort(p+1,p+n+1,cmp2);
        int w=p[n].y-p[1].y;
        printf("%d\n",l*w);

     }
     return 0;
}


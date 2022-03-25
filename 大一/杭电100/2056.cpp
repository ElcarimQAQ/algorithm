#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
double x[5],y[5];
int main ()
{
    freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);

    double x1,y1,x2,y2,x3,y3,x4,y4;
    while(~scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)){
        x[0]=x1;x[1]=x2;x[2]=x3;x[3]=x4;
        y[0]=y1;y[1]=y2;y[2]=y3;y[3]=y4;
        sort(y,y+4);
        sort(x,x+4);
        double h,l;
        h=fabs(x2-x1)+fabs(x4-x3)-(x[3]-x[0]);
        l=fabs(y2-y1)+fabs(y4-y3)-(y[3]-y[0]);
        if(h<0||l<0)
            printf("0.00\n");
        else
            printf("%.2lf\n",h*l);
    }
	return 0;
}

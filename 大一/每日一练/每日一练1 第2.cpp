#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define EPS 1e-8
using namespace std;

double cal(double mid,double R2,int r){
    double v2;
    v2=acos(-1.0)*mid*(R2*R2+r*r+R2*r)/3;
    //printf("%d\n",v2)
    return v2;
}


int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int t,h,R,r;
    double H;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&h,&R,&r);
        double v=acos(-1.0)*h*(R*R+r*r+R*r)/6;
        double lb=h*1.0;
        double rb=0.0;
        double R2;

        for( int i = 0; i < 100; ++ i )
        {
            double m =(lb + rb) / 2;
            R2=(R-r)*m/h+r;
            if(cal(m,R2,r)>=v) lb=m;
            else
                rb=m;
        }
        H=lb;
        //printf("%lf\n",R2);
        //printf("%lf\n",v1);
        printf("%.3lf\n",H);
    }
	return 0;
}

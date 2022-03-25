#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define EPS 1e-8
#define pi  acos(-1.0)
using namespace std;

int t,h,R,r;

double cal(double mid,double R2){
    double v2;
    v2=pi*mid*(R2*R2+r*r+R2*r)/3;
    //printf("%d\n",v2)
    return v2;
}


int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    double H=1.0;
    cin>>t;
    while(t--){
        scanf("%d%d%d",&h,&R,&r);
        double v=pi*h*(R*R+r*r+R*r)/6;
        double lb=h;
        double rb=0;
        double R2;
        while(lb-rb>=EPS){
            double mid=(lb+rb)/2;
            R2=(R-r)*mid/h+r;
            if(cal(mid,R2)<=v)
                rb=mid;
            if(cal(mid,R2)>v)
                lb=mid;
        }
        H=rb;
        //printf("%lf\n",R2);
        //printf("%lf\n",v1);
        printf("%.3lf\n",H);
    }
	return 0;
}


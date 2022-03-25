#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int t,r,d;
    double pi=acos(-1);
    double d1,s,l,l1,l2;
    cin>>t;
    while(t--){
        cin>>r>>d;
        d1=d/360.0*2*pi;
        //printf("%lf\n",pi);
        //printf("%lf\n",d1);
        l1=2*r*sin(d1/2);
        l2=2*r*cos(d1/2);
        l=(l1+l2)*2;
        s=l1*l2;
        printf("%lf %lf\n",l,s);

    }
	return 0;
}


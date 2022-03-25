#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main ()
{
    int r;
    double s,v;
    scanf("%d",&r);
  
    s=3.14*4*r*r;
    v=3*3.14*r*r*r/4;
    printf ("%lf %lf",s,v);
	return 0;
}


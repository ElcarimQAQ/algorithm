#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main ()
{
	float r=0.025;
	float d;
	int n,c;
	scanf ("%d%d",&n,&c);
	d=c*pow(1+r,n);
	printf ("%lf",d);
	return 0;
}

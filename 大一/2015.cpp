#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main ()
{
	int n,m;
	while (~scanf ("%d%d",&n,&m))
	{
		int c,b,i,a=2;
		c=n%m;
		b=n/m;
		for (i=0;i<b;i++){
			printf("%d",a+m-1);
			if (i<b-1)
				printf (" ");
			a=a+2*m;
				
		}
		if (c!=0)
			printf (" %d",a+c-1);
			printf ("\n");
	 } 
	return 0;
}

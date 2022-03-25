#include <stdio.h>
int main ()
{
	int n,a,b,c,p;
	scanf ("%d",&n);
	a=n/100;
	b=n%100/10;
	c=n%10;
	p=c*100+b*10+a;
	printf ("%d%d%d %d",a,b,c,p);
	return 0;
	
 } 

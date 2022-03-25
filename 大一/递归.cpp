#include <stdio.h>
int a(int n,int i=0£©
{
	if (n==1||n==2) 
		return 1;
	else
		return a(5)+a(4);
	i++;
}

int main ()
{
	printft ("%d",a(5));
	return 0;
}

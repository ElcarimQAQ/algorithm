#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main ()
{
	int n,a,s;
	
	while (scanf ("%d",&n)!=EOF&&n!=0)
	{
		s=0;
	
		
		
	
	while (n--){
		cin>>a;
		s+=a/100;
		a=a%100;
		s+=a/50;
		a%=50;
		s+=a/10;
		a%=10;
		s+=a/5;
		a%=5;
		s+=a/2;
		a%=2;
		s+=a;
	}
	printf ("%d\n",s);
}
	
	return 0;
}

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;


int main ()
{
	char x[1000];
	int n,l,a,b,c,d,e;
	cin>>n;
	getchar ();
	while (n--){
		gets(x);
		a=b=c=d=e=0;
		l=strlen(x);
		for (int i=0;i<l;i++){
			if (x[i]=='a')
				a++; 
			if (x [i]=='e')
				b++;
			if (x [i]=='i')
				c++;
			if (x [i]=='o')
				d++;
			if (x [i]=='u')
				e++;	
		}
		printf ("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",a,b,c,d,e);
		//printf ("%d",n);
		if (n) 
			printf ("\n");	
		}
	return 0;
	}


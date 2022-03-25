#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
char a [110]; 

int main ()
{
	int l;
	while (gets(a)){
		l=strlen(a);
		a [0]=a[0]-32;
		for (int i=0;i<l;i++){
			if (a[i]==' ')
				a[i+1]=a[i+1]-32;
		printf ("%c",a [i]);
		}
		printf ("\n");
	}
	return 0;
}

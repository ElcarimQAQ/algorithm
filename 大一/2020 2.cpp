#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int a[110];

int main ()
{
	int n,i,temp;
	scanf ("%d",&n);
	while (n--){
		i=0;
		scanf ("%d",a [i]);
		i++;
	}
	for (i=0;i<n;i++){
		a [i]=fabs (a [i]);
	}
	for (i=0;i<n-1;i++){
		for (int j=i+1;j<n-1-j;j++){
			if (a [i]<a [j]){
				temp=a[i];
				a [i]=a [j];
				a [j]=temp;
				
			}
		}
	}
	for (i=0;i<n-1;i++){
		scanf ("%d ",a [i]);
	}
	printf ("%d\n",a [n-1]);

	
	return 0;
}

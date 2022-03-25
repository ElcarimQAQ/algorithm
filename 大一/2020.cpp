#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}

int a[110];

int main ()
{
	int n,i;
	cin>>n;
	while (n--){
		int m=0;
		i=0;
		cin>>a [i];
		i++;
	}
	for (i=0;i<n;i++){
		if (a[i]<0) 
			a[i]=-a[i];
	}
	sort (a,a+n,cmp);
	for (i=0;i<n-1;i++){
		scanf ("%d ",a [i]);
	}
	printf ("%d\n",a [n-1]);

	
	return 0;
}

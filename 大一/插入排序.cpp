#include <stdio.h>
int a[1000];

int main ()
{
	int k,n,j;
	scanf ("%d",&n);
	for (int i =0;i<n;i++){
		scanf ("%d",&a [i]);
	}
	
	for (int i = 1;i<n;i++){
		k=a [i];
		for (j=i-1;j>=0&&a [j]>k;j--){
			a [j+1]=a [j];
			i--;
		}
		a [j+1]=k;
	}
	for (int i = 0;i<n;i++){
		printf ("%d ",a [i]);
	}
	return 0;
	
}

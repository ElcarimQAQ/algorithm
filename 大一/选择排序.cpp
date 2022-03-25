#include <stdio.h>
int a[10];

int main ()
{
	int min,temp;
	for (int i = 0;i<10;i++){
		scanf ("%d",&a[i]);
	}
	for (int i = 0;i<9;i++){
		min=i;
		for (int j=i+1;j<10;j++){
			if (a [j]<a[min])
				min=j;
		}
		temp=a[i];
		a[i]=a [min];
		a [min]=temp;
	
	}
	for (int i = 0;i<10;i++){
		printf ("%d ",a[i]);
	} 
	return 0;
}

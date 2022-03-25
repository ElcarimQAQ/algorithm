#include <stdio.h>
int a[1000];

int main ()
{
	int n,temp,min,m;
	while (scanf("%d",&n)!=EOF){
		
		if (n==0) break;
		else {
			for (int i=0;i<n;i++){
				scanf("%d",&a[i]);
			}
		}
		min = a[0];
		for (int i=0;i<n;i++){
			
				if (a[i]<=a [min]){
				
					min =a [i];
					m=i;
				
			}
		}
		temp=a [m];
		a [m]=a [0];
		a [0]=temp;
		for (int i=0;i<n;i++){
			printf ("%d ",a [i]);
		}
		printf ("\n");
	}
	return 0;
 } 

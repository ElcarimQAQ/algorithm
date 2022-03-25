#include <stdio.h>
int main ()

{
	int x,n,min,temp;
	int a[100];
	while (scanf ("%d",&n)!=EOF){
		if (n==0) break;
		else { 
		    for (int i=0;i<n;i++){
				scanf ("%d",&a[i]);
			}
		} 
		for (int i=1;i<n;i++){
			min=a[0];
			if (a[i]<min) {
				min=a[i];
				x=i;
			}
		}
		if (x!=0){
		
		temp=a[0];
		a[0]=min;
		a[x]=temp;
		}
		for (int i=0;i<n;i++){
			printf ("%d ",a[i]);

		}
		printf ("\n");
	}
	return 0;
}

#include <stdio.h>
int main ()
{
	int a[1005]; 
	a[4]=1;
    for(int i=5;i<=1000;i++){
	    a[i]=a[i-1]*2%10000;
	}
	for(int i=5;i<=1000;i++){
		printf("%d,",a[i]);
		if(i%10==0)
			printf("\n");
	}
	return 0;
} 

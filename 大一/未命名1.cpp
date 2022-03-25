#include <stdio.h>
int main ()
{
	int n,m,a;
	while (scanf ("%d%d",&n,&m)!=EOF){
		if (m==1){
			a=2;
			for (int i=0;i<n;i++){
				printf ("&d ",a);
				a=a+2;
			}
			printf ("\n");
		}
		else {
			if (n%m==0){
				for (int i=0;i<n/m;i++){
					for (int j=0;j<m;j++){
						sum=0;
						sum+=a;
						a=a+2;
					}
				printf ("%d",sum/m);
				}
				printf ("\n");
			}
			else 
		}
	}
 } 

#include <stdio.h>
int main ()
{
	int n,m,sum;

	while (scanf ("%d%d",&n,&m)!=EOF){
			int a=2;
				for (int i=0;i<n/m;i++){
					sum=0;
					for (int j=0;j<m;j++){
						sum+=a;
						a=a+2;
					}
				printf ("%d ",sum/m);
				}
				if(n%m==0) printf ("\n");
				else{
					int b=a/2;
					sum=0;
				 	for (int i=b;i<=n;i++){
				 	
				 		sum+=a;
				 		a=a+2;
					 }
					 printf ("%d\n",sum/(n-b));
		}
	}
	return 0;
 } 

#include<stdio.h>
#include<math.h>
int main ()
{
	double a,sum;
	int m,n;
	while (scanf("%d %d",&m,&n)!=EOF){
		sum=0.0;
		a=m*1.0;
		for (int i=0;i<n;i++){
			sum+=a;
			a=sqrt(a);
		}
		printf("%.2lf\n",sum);
	}
	return 0;
}
 

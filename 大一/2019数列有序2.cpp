#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int a[110];

int main ()
{
	int n,m,i;
	while (~scanf ("%d%d",&n,&m)){
		if (n==0&&m==0) break;
		else {
			for (i=0;i<n;i++){
				scanf ("%d",&a [i]);
			}
			for (i=0;i<n;i++){
				if (m<a [i]) 
					break;
			}
		}
		for (int j=0;j<i;j++){
			printf("%d ",a[j]);
		} 
		printf ("%d",m);
		for (int j=i;j<n;j++)
			printf (" %d ",a[j]);
			printf ("\n");

		
	}
	return 0;
}

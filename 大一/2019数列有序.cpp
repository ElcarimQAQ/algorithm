#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int a[110];

int main ()
{
	int n,m;
	while (cin>>n>>m){
		if (n==0&&m==0) break;
		else {
			for (int i=0;i<n;i++){
				scanf ("%d",&a [i]);
			}
			for (int i=0;i<n;i++){
				if (m>a [i]) {
					for (int j=n+1;j>i;j--){
						a [j+1]=a [j];//同一个数往后传 
						 
					}
					a[i+1]=m;
					
				}   //插入 其他往后移 
			}
		}
		for (int i=0;i<n+1;i++){
			printf("%d ",a[i]);
		} 
		printf ("\n");
	}
	return 0;
}

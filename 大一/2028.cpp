#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int a[10000];

int main ()
{
	int n,i,m,flag;
	scanf ("%d",&n);
	while (n--){
		flag=0;
		i=0;
		scanf ("%d",&a[i]);
		i++;
	}
	for(int j=1;;j++){
		m=a[0]*j;
		for (i=0;i<n;i++){
			if (m%a[i]!=0){
				flag=1;
				break;
			}
		}
	if (flag==1) {
		printf ("%d/n",m);
		break;
	}
		
	} 
	return 0;
}

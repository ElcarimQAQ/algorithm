#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int a[100];
int slove(int i)
{
    if (i==1)
        return 1;
    if (i==2)
        return 2;
    if (i==3)
        return 3;
    else
        return slove(i-1)+slove(i-3);
}

int main ()
{
	int n,sum;
	while (scanf ("%d",&n)!=EOF&&n!=0){
	sum=slove(n);

	printf ("%d\n",sum);
	}
	return 0;
}
 

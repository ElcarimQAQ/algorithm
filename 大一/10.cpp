#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int a[4];

int main ()
{
    int min,max,t1,t2;
    for (int i=0;i<5;i++){
        scanf("%d",&a [i]);
    }
    max=min=0;
    for (int i=0;i<5;i++){
        
        if (a[i]<=a[min])
            min=i;
        if (a[i]>=a[max])
            max=i;
            
    }
    t1=a[0];
    a[0]=a[min];
    a[min]=t1;
    t2=a[4];
    a[4]=a[max];
    a[max]=t2;//½»»»
    for (int i=0;i<5;i++)
        printf("%d ",a[i]);
	return 0;
}


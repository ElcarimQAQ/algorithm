#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int a[4];

int main ()
{
    for (int i=0;i<5;i++){
        cin>>a[i];
    }
    for (int i=0;i<4;i++){
        for (int j=0;j<4-i;j++){
            if (a[j+1]<a [j]){
                int temp=a [j+1];
                a [j+1]=a [j];
                a [j]=temp;
            }
        }
    }
    for (int i=0;i<5;i++){
        printf("%d ",a [i]);
    }

	return 0;
}


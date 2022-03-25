#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int a[3][3];

int main ()
{
    int max=a[0][0];
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            cin>>a[i][j];
        }  // ‰»Î 
    }
    for (int i=0;i<4;i++){
        for (int j=0;j<4;j++){
            if (a[i][j]>max)
                max=a[i][j];
        }
    }
    printf("%d",max);

	return 0;
}


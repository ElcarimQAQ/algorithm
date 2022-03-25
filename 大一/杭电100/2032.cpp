#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int a[40][40];

int main ()
{
    int n;

    while(~scanf("%d",&n)){
        for (int i=1;i<=n;i++){
            a [i][1]=1;
            a [i][i]=1;
        }
        for (int i=3;i<=n;i++){
            for (int j=2;j<=i-1;j++){
                a [i][j]=a[i-1][j-1]+a[i-1][j];
            }
        }
        for (int i=1;i<=n;i++){
            printf("%d",a[i][1]);
            for (int j=2;j<=i;j++){
                printf(" %d",a[i][j]);
            }
            printf("\n");
        }
        printf("\n");

    }


	return 0;
}


#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
long long a [25];

int main ()

{
    int c,n;
    long long sum;
    double p;
    cin >> c;
    while (c--){
        scanf("%d",&n);
        sum=1;
        for (int i=1;i<=n;i++){
            sum*=i;
        }
        a [1]=0;
        a [2]=1;
        a [3]=2;

        for (int i=4;i<=n;i++){
            a [i]=(i -1)*(a [i-1]+a [i-2]);

        }
        p=a [n]*100.0/sum;
        printf("%.2lf%%\n",p);

    }


	return 0;
}



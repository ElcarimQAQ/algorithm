#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn=1e6+5;
const int c=1e9;
int a [maxn];

int main ()
{
    int n,t;
    scanf("%d",&t);
    while(t--){
            scanf("%d",&n);
            a [1]=1;
            a [2]=1;
            for (int i=3;i<=n;i++){
                a [i]=a [i-1]+a[i-2];
            }
            int b=a [n]%c;
            printf("%d\n",b);

    }


	return 0;
}


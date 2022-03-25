#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn =1e6+5;
int a [maxn];
const int c=1e9;


int main ()
{
    a [1]=1;
    a [2]=1;
    for (int i=3;i<=maxn;i++){
        a [i]=(a [i-1]%c+a [i-2]%c)%c;
    }
    int n,t;
    scanf("%d",&t);
    while(t--){
            scanf("%d",&n);
            printf("%d\n",a [n]);

    }


	return 0;
}



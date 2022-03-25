#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn=1e6+5;
int a [maxn];

int main ()
{
    long long n;
    while (~scanf("%d",&n)){
        a [1]=1;
        a [2]=1;
        for (int i=3;i<=n;i++){
            a [i]=(a [i-1]+a [i-2])%3;
        }
        printf("%d\n",a [n]);
    }


	return 0;
}

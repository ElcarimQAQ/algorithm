#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn=1e5+5;


int main ()
{
    int n;
    while(~scanf("%d",&n)){
        if(n>15)
            printf("%d %d %d %d %d\n",n-15,n-7,n-4,n-2,n-1);
        else if(n>7&&n<=15)
            printf("%d %d %d %d\n",n-7,n-4,n-2,n-1);
        else if(n>4&&n<=7)
            printf("%d %d %d\n",n-4,n-2,n-1);
        else if(n>2&&n<=4)
            printf("%d %d\n",n-2,n-1);
        else
            printf("%d\n",n-1);
    }

	return 0;
}

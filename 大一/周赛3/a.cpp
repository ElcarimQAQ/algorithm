#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int main ()
{
    long long  n,m,k,l;
    while(~scanf("%lld%lld%lld%lld",&n,&m,&k,&l)){

        if(k+l>n)
            printf("-1\n");
        else{
            long long s=(k+l)/m;
            if ((k+l)%m!=0){
                s++;
            }
            if (s*m>n)
                printf("-1\n");
            else
                printf("%lld\n",s);
            }
    }

	return 0;
}


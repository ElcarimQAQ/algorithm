#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    long long a,b,c;
    while(scanf("%llx%llx",&a,&b)!=EOF){
        c=a+b;
        if (c>=0)
            printf("%llx\n",c);
        else
            printf("-%llx\n",-c);
    }
	return 0;
}

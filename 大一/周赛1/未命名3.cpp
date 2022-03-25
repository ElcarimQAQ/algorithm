#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[4];

int main ()
{
    long long n;
    while (~scanf("%lld",&n)){


            int s=n%8;
            if (s==1||s==2||s==7)
                printf("1\n");
            else if (s==3||s==5||s==6)
                printf("2\n");
            else
                printf("0\n");



    }
	return 0;
}




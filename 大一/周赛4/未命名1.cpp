#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
long long  a[1005];

int main ()
{
    int t;
    cin>>t;
    long long a,b,c;
    while(t--){
        cin>>a>>b>>c;
        if(a>b)
            swap(a,b);
        if(a>c)
            swap(a,c);
        if(b>c)
            swap(b,c);
        if(a+b<c/2)
            printf("%lld\n",a+b);
        else
            printf("%lld\n",(a+b+c)/3);
    }
	return 0;
}


#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main ()
{
    int t,b,n,m;
    long double a;
    scanf("%d",&t);
    while (t--){
        
        scanf("%d%d",&n,&m);
        a=pow(n,m);
        b=log10(a);
		      
        printf("%d\n",b+1);
    }
	return 0;
}

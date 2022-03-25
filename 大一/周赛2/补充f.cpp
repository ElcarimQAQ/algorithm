#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int main ()
{
    int t,a,b,x,aa;
    char s;
    while(t--){
        scanf("%d%d",&a,&b);
        scanf("UTC");
        scanf("%c%d",&s,&x);
        if(s=='+'){
            aa=a+x-8;
            if(aa>=24)
                printf("%d:%d\n",aa-24,b);
            else
                printf("%d:%d\n",aa,b);
        }
        else{
            aa=a-x-8;
            if(aa<0)
                printf("%d:%d\n",aa+24,b);
            else
                printf("%d:%d\n",aa,b);
        }


    }

	return 0;
}

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main ()
{
  
    int n,d,m,x,y;
     scanf("%d%d",&n,&d);
        scanf("%d",&m);
        while(m--){
            scanf("%d%d",&x,&y);
            if (y<d-x)
                printf("NO\n");
            else if(y>x+d)
                printf("NO\n");
            else if(y>2*n-d-x)
                printf("NO\n");
            else if(y<x-d)
                printf("NO\n");
            else
                 printf("YES\n");
        }
	return 0;
}


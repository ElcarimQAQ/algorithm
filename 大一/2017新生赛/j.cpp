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
   int n,m;
   while(~scanf("%d%d",&n,&m)){
        if(n==1&&m==1)
            printf("Win\n");
        else
            printf("Lose\n");
   }
   return 0;
}



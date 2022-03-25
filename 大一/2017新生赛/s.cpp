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
     int n,sum,i,j,x,p;
     scanf("%d",&n);
     sum=i=1;
     while(i<=n){
        x=j=1;
        while(j<=i){
            p=x*(4*j-2);
            x=p/(j+1);
            j++;
        }

            i++;
            sum=sum+x;

     }
     printf("%d\n",sum);
     return 0;
}



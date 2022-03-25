#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main ()
{
    
    int a,b;
    while(scanf("%d %d",&a,&b)){
    	if (a==0&&b==0)
    		break;
        int sum=1;
        for (int i=0;i<b;i++){
            sum=sum*a%1000;
        }
        printf("%d\n",sum);
    }
    return 0;
}
  

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
    	if(m==0&&n==0)
    		break;
    	for(int j=(int)sqrt(2*m);j>=1;j--){
    		int i; 
    		i=(int)(2*m/j+1-j)/2;
    		if ((i+i+j-1)*j/2==m)
    			printf("[%d,%d]\n",i,i+j-1);
		}
    
        printf("\n");
    }
	return 0;
}

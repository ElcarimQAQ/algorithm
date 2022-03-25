#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int f(long long x){
    int sum=0;
    int a;
    if(x==0)
        return 0;
    while(x>0){
        a=x%10;
        sum+=a;
        x/=10;
    }
    return sum;
}


int main ()

{
    int t;
    long long x,k;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld",&x,&k);
        //printf("%d\n",f(x));
        x=f(x);
        for(int i=0;i<k;i++){
            x=f(x);
            if(x/10==0)
                break;
        }
        printf("%d\n",x);
    }
	return 0;
}


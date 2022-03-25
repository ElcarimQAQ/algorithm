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

int g(long long x,long long k){
    if(k==0)
        return f(x);
    else
        return g(f(x),k-1);


}


int main ()

{
    int t;
    long long x,k;
    cin>>t;
    while(t--){
        cin>>x>>k;
        //printf("%d\n",f(x));
        int a=g(x,k);
        printf("%d\n",a);
    }
	return 0;
}

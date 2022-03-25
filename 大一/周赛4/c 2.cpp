#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
long long  a[1005];
long long f(int i,int n){
    long long max=a[i],min=a[i];
    long long sum=0;
    for(int j=i+1;j<=n;j++){
        if(a[j]>max)
            max=a[j];
        if(a [j]<min);
            min=a[j];
        sum+=(max-min);

    }
    return sum;
}


int main ()
{
    int t,n;
    scanf("%d",&t);
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i){
            scanf("%lld",&a [i]);
        }
        long long sum=0;
        for(int i=1;i<n;i++){
            sum+=f(i,n);

        }
    printf("%lld\n",sum);
    }
	return 0;
}


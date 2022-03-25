#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int  a[1005];
long long f(int i,int n){
    long long max=a[i],min=a[1];
    int sum=0;
    for(i;i<n;i++){
    if(a[i]>max)
        max=a[i];
    if(a [i]<min);
        min=a[i];
    sum+=(max-min);
    return sum;
    }
}


int main ()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i){
            scanf("%d",a [i]);
        }
        int sum=0;
        for(int i=1;i<n;i++){
            sum+=f(i,n);

        }
    printf("%d\n",sum);
    }
	return 0;
}


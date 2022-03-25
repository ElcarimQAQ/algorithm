#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
long long a[100005];
long long b[100005];

int main ()
{
    int s;
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    long long x,n;

    b[0]=0;
    scanf("%lld",&n);
    long long sum1=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        b[i]=b[i-1]+a[i]+i;
    }

    long long maxn=0;
    for (int x=0;x<=n;x++){
        long long sum=0;
        for(int i=x+1;i<=n;i++){
            sum=b[i]+a[i]+n+1-i;
        }
        if(sum>=maxn){
            maxn=sum;
            s=x;
        }

    }
    printf("%d\n",s);
	return 0;
}


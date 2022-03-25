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
        sum1+=a [i];
    }

    long long maxn=0;
    long long sum2,sum;
    for (int x=0;x<=n;x++){
        sum2=(1+x)*x/2;
        for(int i=x+1;i<=n;i++){
            sum2=sum2+n+1-i;
        }
        sum=sum1+sum2;
        if(sum>=maxn){
            maxn=sum;
            s=x;
        }

    }
    printf("%d\n",s);
	return 0;
}


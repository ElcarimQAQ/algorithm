#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
long long a[100005];

int main ()
{
    int s;
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int n;
    scanf("%d",&n);
    long long sum1=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum1+=a[i];
    }

    long long maxn=0;
    long long sum2,sum,sum3;
    for (int x=0;x<=n;++x){
        sum2=(1+x)*x/2;
        sum3=(n-x+1)*(n-x)/2;
        sum=sum1+sum2+sum3;
        if(sum>=maxn){
            maxn=sum;
            s=x;
        }

    }
    printf("%d\n",s);
	return 0;
}


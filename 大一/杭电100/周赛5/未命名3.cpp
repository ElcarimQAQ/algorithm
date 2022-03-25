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
    long long x,n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
 
    long long maxn=0;
    for (int x=0;x<=n;x++){
        long long sum=0;
        for(int i=1;i<=x;i++)
            sum=sum+a[i]+i;
        for(int i=x+1;i<=n;i++){
            sum=sum+a[i]+n+1-i;
        }
        if(sum>=maxn){
            maxn=sum;
            s=x;
        }
 
    }
    printf("%d\n",s);
    return 0;
}

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define INF 0x7fffffff;
using namespace std;
long long ks(long long a,long long b){
    long long r=1,base=a;
    while(b!=0){
        if(b&1) r*=base%10000019;
        base*=base;
        base%=10000019;
        b>>=1;
    }
    return r%10000019;
}
int main()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int n;
    long long s,sum;
    sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld",&s);
        sum+=ks(s%10000019,i);
        sum%=10000019;
    }
    printf("%lld\n",sum%10000019);
    return 0;
}

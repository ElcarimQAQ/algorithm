#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int f[30];
long long cnm(int n,int m){
    long long up,down;
    up=down=1;
    for(int i=n;i>=n-m+1;i--)
        up*=i;
    for(int i=m;i>=1;i--)
        down*=i;
    return up/down;
}

int main ()
{
    int n;
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    f[1]=0;
    f[2]=1;
    for(int i=3;i<=25;i++)
        f[i]=(i-1)*(f[i-1]+f[i-2]);
    while(cin>>n&&n!=0){
        int m=n/2;
        long long sum=0;
        for(int i=1;i<=m;i++){
            long long evo=0;
            long long ad=cnm(n,i);
            evo=f[i]*ad;
            sum+=evo;
        }
        printf("%lld\n",sum+1);
    }
    return 0;
}


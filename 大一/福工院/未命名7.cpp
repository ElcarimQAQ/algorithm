#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
long long dp[10000000];
int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int t;
    long long k,x,y;
    cin>>t;
    while(t--){
        scanf("%lld%lld%lld",&k,&x,&y);
        for(long long i=1;i<=k;i++){
            long long j=x;
            while(i-j>0&&j>=x&&j<=y)
            dp[i]=min(dp[i-j],dp[i]);
            j++;
        }
        if(dp[k]<=y-x+1)
            printf("Y\n");
        else
            printf("N\n");
    }

    return 0;
}



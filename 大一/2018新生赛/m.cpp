#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int s[100005];

int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int t,n,a,b,l,r;
    scanf("%d",&t);
    while(t--){
        scanf(("%d%d%d%d%d"),&n,&a,&b,&l,&r);
        for(int i=1;i<=n;i++)
            scanf("%d",&s[i]);
        long long sum=0;
        for(int i=a;i<=b;i++){
            sum+=s[i]%s[l];
        }

        printf("%lld\n",sum);
    }
	return 0;
}



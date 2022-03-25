#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[1005],b[1005];
int main ()
{
    freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int n,l,r;
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    int cnt=0;
    for(int i=l;i<=r;i++){
        if(a[i]<=l&&b[i]>=r)
            cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}


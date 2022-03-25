#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int A[1005],B[1000005],C[1000005];
int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int n,m,q,a;
    while(scanf("%d%d%d",&n,&m,&q)!=EOF){
        for(int i=1;i<=n;i++)
            scanf("%d",&A[i]);
        for(int i=1;i<=m;i++){
            scanf("%d%d",&a,&B[i]);
            if(A[a]>=B[i]){
                A[a]=A[a]-B[i];
                C[i]=0;
            }
            else{
                C[i]=B[i]-A[a];
                A[a]=0;
            }

        }
        while(q--){
            int i;
            scanf("%d",&i);
            if(C[i]==0)
                printf("Yes\n");
            else
                printf("%d\n",C[i]);
        }
    }
    return 0;
}


#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[105],b[105];
int found(int x,int n);

int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int n,m,j;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    while(m--){
        scanf("%d",&j);//²éÑ¯±àºÅj
        printf("%d\n",found(a[j],n));
       // printf("%d\n",a[j]);
        //for(int i=1;i<=n;i++)
         //   printf("%d ",b[i]);
    }
	return 0;
}

int found(int x,int n){
    for(int i=1;i<=n;i++){
        if(x==b[i]){
            return i;
            break;
        }
    }
}

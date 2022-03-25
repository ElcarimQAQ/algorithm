#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
//long long slove(int n){
//    if(n==1&&n==0)
//        return 1;
//    else
//        return slove(n-1)+slove(n-2);

//}

int main ()
{
    long long s[55];
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int n;
    s[0]=0;
    s[1]=1;
    for(int i=2;i<=50;i++){
        s[i]=s[i-1]+s[i-2];
    }
    while(~scanf("%d",&n)&&n!=-1){
        printf("%lld\n",s[n]);

    }
	return 0;
}


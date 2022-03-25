#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[1005]={0,1,0,2};

int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int t,n;
    for(int i=4;i<=1000;++i){
           a[i]=(a[i-1]%10000+a[i-2]*2%10000)%10000;
        }
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("%d\n",a[n]);
    }
	return 0;
}

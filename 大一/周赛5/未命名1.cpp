#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[10005]
int com(int x,int y){
    int sum1,sum2,sum3;
    sum1=sum2=sum3=0;
    for(int i=1;i<=x;i++)
        sum1+=a[i];
    for(int i=x+1;i<=y;i++)
        sum2+=a[i];
    for(int i=y+1;i<=n;i++)
        sum3+=a [i];
    if(sum1==sum2&&sum1==sum3)
        return true;
    else
        return false;
}
int main ()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        for (int i = 1;i < = n;++i)
            scanf("%d",&a [i]);
        int x,y;
        x=2;
        y=n-1;
        while(1){
            if(y<x)
            if(com(x,y))
                printf("%d %d\n",x,y)
            x++;
            y--;
        }
    }
	return 0;
}


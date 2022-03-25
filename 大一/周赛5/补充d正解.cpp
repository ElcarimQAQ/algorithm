#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[100005];


int main ()
{
    freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int n,s;
    while(~scanf("%d%d",&n,&s)){
            int sum=0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        if(sum<s)
            printf("0\n");
        else{
            int i,j;
            sum=0;
            i=j=1;
            int minn=n+1;
            while(1){
                while(j<=n&&sum<s){
                    sum+=a[j];
                    j++;
                }
                if(sum<s)
                    break;
                minn=min(minn,j-i);
                sum-=a[i++];
            }
            printf("%d\n",minn);
        }
    }
	return 0;
}


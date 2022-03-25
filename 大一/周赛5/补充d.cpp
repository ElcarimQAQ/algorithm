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
            while(1){
                if(j>n||j-i<0)
                    break;
                int minn=n;
                if(sum<s){
                    sum+=a[j];
                    j++;
            	}
                else{
                minn=min(minn,j-i+1);
                sum-=a[i++];
           		}
            }
            printf("%d\n",j-i+1);
        }
        
        
    }
	return 0;
}


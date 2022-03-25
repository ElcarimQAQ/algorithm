#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[15],b[15];

int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int n,x,y;
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++)
            scanf("%d%d",&a[i],&b[i]);
        for(int i=b[1];i<=100000;i++){
            int j=1;
            int flag=1;
            while(j<=n){
                int c=i-b[j];
                if(c%a[j]==0&&c!=0)
                    j++;
                else{
                    flag=0;
                    break;
                }
            }
        if(flag==1){
            printf("%d\n",i);
            break;
            }
        }
    }
	return 0;
}


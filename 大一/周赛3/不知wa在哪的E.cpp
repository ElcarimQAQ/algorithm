#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[110];
int main ()
{
    int n;
    while(~scanf("%d",&n)){
        int sum=0;
        for(int i=1;i<=n;++i){
            scanf("%1d",&a [i]);
            sum+=a[i];
        }
        //输入数组

        int flag=0;
        for (int i=2;i<n;i++){
            if(sum%i==0){
                int b=sum/i;//每组数大小
                int s=0;
                int cnt=1;
                for(int j=cnt;j<=n;j++){
                    s+=a[j];
                    if(s==b){
                        cnt=j+1;
                        s=0;
                        if(cnt==n+1)
                            flag=1;
                    }
                    if(s>b)
                        break;
                }
            }
        }
        if(flag==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
	return 0;
}

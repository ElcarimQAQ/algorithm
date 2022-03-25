#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[200005];
int s[200005];
int m[200005];
void xb(int b,int n)
{
    for(int i=1;i<=n;i++){
        if (a[i]==b)
            m[b]=i;
    }

}//返回数组下标

int main ()
{
    memset(s,'0',sizeof(s));
    int n,b,k;

    scanf("%d",&n);
    int N=n;
    for(int i=1;i<=n;i++){
        scanf("%d",&k);
        a [i]=k;//第i本书编号为k
        s [i]=1;
    }
    int c=1;
    while(n--){
        scanf("%d",&b);
        xb(b,N);
        b=m[b];
        if(s[b]!=0){

            int cnt=0;
            for (int j=c;j<=b;j++){
                if(s[j]!=0){
                    cnt++;
                    s [j]=0;

                }
            }
            c=b;
            printf("%d ",cnt);
        }

        else
            printf("0 ");
    }
    printf("\n");
	return 0;
}


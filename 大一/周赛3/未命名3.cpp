#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[200005];
int sum(int b)
{
    int cnt=0;
    for (int j=1;j<=b;j++){
        if(a [j]==1){
            cnt++;
            a [j]=0;
        }
    }
     return cnt;
}

int main ()
{
    //reopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    memset(a,'0',sizeof(a));
    int n,b,k;
    int cnt;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>k;
        a [k]=1;
    }
    while(n--){
        cin>>b;
        if (a[b]==1){
            cnt=sum(b);
            printf("%d ",cnt);
        }

        else
            printf("0 ");

    }
	return 0;
}


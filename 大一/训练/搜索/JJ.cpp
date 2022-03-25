#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define INF 0x7fffffff;
using namespace std;
int a[1005];
int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    int n,m,s,sum;
    while(~scanf("%d",&n)){
            sum=0;
        for (int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        scanf("%d",&m);
        if(sum>=m)
            printf("%d\n",sum-m);
        sort(a+1,a+1+n);
        s=m;
        for(int i=n;i>=1;i--){
            s=s-a[i];
            if(s<10)
                break;
        }
        printf("%d\n",s);
    }
    return 0;
}

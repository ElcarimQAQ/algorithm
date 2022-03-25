#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define INF 0x7fffffff;
using namespace std;
typedef long long ll;
struct bs{
    int a,b;
}c[1005];
bool cmp(bs x,bs y){
    return x.b<y.b;
}
int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i].a);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i].b);
    sort(c+1,c+1+n,cmp);
    int i,s;
    s=0;
    for(i=1;i<=n;i++){
        s+=c[i].a;
        if(s>c[i].b)
            break;
        s=s+2;
    }
    //printf("%d\n",i);
    if(i==n+1)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

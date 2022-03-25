#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
long long a[25];
int zh (int m,int n){
    int a,b,c;
    a=b=c=1;
    for (int i=1;i<=n;i++)
        a*=i;
    for (int i=1;i<=m;i++)
        b*=i;
    for (int i=1;i<=n-m;i++)
        c*=i;
    return a/b/c;
}

int main ()

{
    int c,n,m;
    cin>>c;
    while (c--){
        scanf("%d%d",&n,&m);
        int s=zh(m,n);
        //cout<<s<<endl;
        a [1]=0;
        a [2]=1;
        a [3]=2;
        for (int i=4;i<=m;i++)
            a [i]=(i-1)*(a [i-1]+a [i-2]);
        printf("%lld\n",s*a[m]);

    }

	return 0;
}

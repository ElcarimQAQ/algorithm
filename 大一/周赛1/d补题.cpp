#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include<algorithm>
using namespace std;
const int N=2e5+10;
int a [N];
long long p[N],s[N];

int main ()
{
    int n,m,x;
    long long f=1,ma;
    cin>>n>>m>>x;
    while(m--)
        f*=x;
    for (int i=1;i<=n;i++)
        cin>>a [i];

    p[0]=0;
    for (int i=1;i<=n;i++)
        p[i]=p[i-1]|a [i];
    s [n+1]=0;
    for (int i=n;i>=1;i--)
        s[i]=s[i+1]|a [i];
    ma =0;
    for (int i=1;i<=n;i++){
        ma=max(ma,p[i-1]|s[i+1]|f*a [i]);
    }
    printf("%lld",ma);




	return 0;
}

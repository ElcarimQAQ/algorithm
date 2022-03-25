#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
long long  a[1005];

int main ()
{
    int t,n;
    scanf("%d",&t);
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i){
            scanf("%lld",&a [i]);
        }
        long long sum=0;
        long long ma,mi;
        for(int i=1;i<n;i++){
                mi=ma=a[i];
            for(int j=i+1;j<=n;++j){
                ma=max(ma,a[j]);
                mi=min(mi,a[j]);
                sum+=ma-mi;
            }

        }
    printf("%lld\n",sum);
    }
	return 0;
}

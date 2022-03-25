#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int s=1e9+7;
long long a[100005],b[10005];

int main ()
{

    int t,n,i;
    cin>>t;
    while(t--){
        cin>>n;
        if (n==0)
            printf("1\n");

        else {
            a [0]=1;
            if (n<=1e5){
                for (i=1;i<=n;i++){
                    a [i]=(a[i-1]%s)*(i%s)%s;

                }
                printf("%lld\n",a [i]);
            }
            else{
                for (i=1;i<=n-1e5;i++){
                    b[i]=b[i-1]*n;
                    b [i]%=s;
                }
                printf("%lld\n",b [i]);
            }



        }
    }
	return 0;
}


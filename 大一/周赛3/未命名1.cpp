#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
//long long *p=(long long*malloc() 
const int a=1e9+7;

int main ()
{
  
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        long long sum=1;
        if (n==0)
            printf("1\n");
        else {
            for (int i=1;i<=n;i++){
                sum=(sum%a)*(i%a)%a;

            }
            printf("%lld\n",sum);
        }
    }
	return 0;
}


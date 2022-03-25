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
    int t;
    long long n;
    cin>>t;
    while(t--){
        int sum=0;
        cin>>n;
        int a=1;
        while(n%2==0){
            n=n/2;
            sum+=a;
            a*=2;

        }
        printf("%d\n",sum);
    }
	return 0;
}

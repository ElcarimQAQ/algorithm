#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int main ()
{
    int t;
    long long n;
    cin>>t;
    while(t--){
        int cnt=0;
        cin>>n;
        if(n==1)
            printf("0\n");
        else if(n==2)
            printf("1\n");
        else{
            while(n%2==0){
                cnt++;
                n/=2;
            }
            if(n==1)
                cnt++;
            printf("%d\n",cnt);
        }
    }
	return 0;
}


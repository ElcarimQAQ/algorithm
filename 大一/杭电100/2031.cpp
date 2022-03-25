#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int a[1000];

int main ()
{
    int n,r,i,t;
    while(cin>>n>>r){
            t=i=0;
        if (n<0){
            t=1;
            n=-n;
        }
        while(n){
            a[i++]=n%r;
            n=n/r;
        }
        if (t)
            printf("-");
        for (int j=i-1;j>=0;j--){
            if (a[j]<10)
                printf("%d",a[j]);
            else{
                    switch(a[j]){
                        case 10:printf("A");break;
                        case 11:printf("B");break;
                        case 12:printf("C");break;
                        case 13:printf("D");break;
                        case 14:printf("E");break;
                        case 15:printf("F");break;
                    }
            }
        }
        printf("\n");
    }

	return 0;
}



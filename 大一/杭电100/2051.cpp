#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int a[1000000];
int main ()

{
    int n,i;
    while (cin>>n){
        i=1;
       while (n){
            a [i]=n%2;
            i++;
            n/=2;
       }
        for (int j=i-1;j>=1;j--){
		   //cout<<j<<endl; 
           printf("%d",a [j]);
        } 
        cout<<endl;
    }

	return 0;
}


#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

long long a [55];
int main ()

{
    int n;
    a [1]=3;
    a [2]=6;
    a [3]=6;
    while (cin>>n){

            for (int i=4;i<=n;i++){
                a [i]=a[i-1]+2*a[i-2];
            }
            cout << a[n] << endl;

    }
	return 0;
}

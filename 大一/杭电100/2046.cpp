#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
long long s[55];
int main ()

{
    int n;
    while (cin>>n){
        s [1]=1;
        s [2]=2;
        for (int i=3;i<=n;i++){
            s [i]=s [i-1]+s [i-2];
        }
        cout <<s [n]<<endl;
    }

	return 0;
}

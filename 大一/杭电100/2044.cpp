#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
long long s[55];
int main ()

{
    int n,a,b;
    cin>>n;
    while (n--){
        cin>>a>>b;
        s[a+1]=1;
        s[a+2]=2;
        for (int i=a+3;i<=b;i++)
            s[i]=s[i-1]+s[i-2];
        cout<<s [b] <<endl;
    }


	return 0;
}


#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int a[35];
int main ()

{

    int n,j;
    cin>>n;
    while (n--){
        cin>>j;
        a [j]=3;
        for (int i=j-1;i>=0;i--){
                a [i]=2*(a[i+1]-1);

        }
        printf("%d\n",a [0]);
    }




	return 0;
}


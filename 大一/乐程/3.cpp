#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
void swap(int*n,int*m){
    int t;
    t=*n;
    *n=*m;
    *m=t;
}

int main ()
{
    int a,b,c;
    cin>>a>>b>>c;
    getchar ();
    if (a<b)
        swap(a,b);
    if (a<c)
        swap(a,c);
    if (b<c)
        swap(b,c);
    printf("%d %d %d",a,b,c);
}


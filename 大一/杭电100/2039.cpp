#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
void slove (float a,float b,float c){
    if (a+b>c&&a+c>b&&b+c>a)
        printf("YES\n");
    else 
        printf("NO\n");
}

int main ()
{
    int m;
	float a,b,c;
    cin>>m;
    getchar();
    while (m--){
        cin>>a>>b>>c;
        slove(a,b,c);
        
    }
    return 0;
}


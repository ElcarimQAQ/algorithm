#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;


int main ()
{
    int n,a,b,c,d,e,f,g,h,i;
    cin>>n;
    getchar(); 
    while (n--){
        cin>>a>>b>>c>>d>>e>>f;
        if (c+f>59){
            i=c+f-60;
            b++;
        }
        else 
            i=c+f;
        if (b+e>59){
            h=b+e-60;
            a++;
        }
        else
            h=b+e;
        g=a+d;
        printf("%d %d %d\n",g,h,i);
    }
   
	return 0;
}


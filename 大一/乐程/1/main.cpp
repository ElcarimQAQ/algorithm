#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
char m[100000];

int main ()
{
    int a,b,c;
    gets(a);
    getchar();
    int l=strlen(a);
    for(int i=0;i<l;i++){
        if (m[i]='0')
            a++;
        if(m[i]='1')
            b++;
        if (m[i]='2')
            c++;
    }
    for(int i=0;i<a;i++)
        printf("0");
    for(int i=0;i<b;i++)
        printf("1");
    for(int i=0;i<c;i++)
        printf("3");

	return 0;
}

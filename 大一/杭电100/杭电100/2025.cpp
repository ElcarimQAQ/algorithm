#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
char a [100];

int main ()
{
    int l;
    char max;
    while (gets(a)){
        l=strlen(a);
        max =a[0];
        for (int i=0;i<l;i++){
            if (a[i]>max)
                max=a[i];
        }
        for (int i=0;i<l;i++){
            printf("%c",a[i]);
            if (a[i]==max)
                printf("(max)");
        }
    printf ("\n");
    }
	return 0;
}

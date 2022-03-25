#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
char a[1000];

int main ()
{
    int n,l;
    cin>>n;
    getchar();
    while (n--){
    	int count=0;
        gets(a);
        l=strlen(a);
        for (int i=0;i<l;i++){
            if ((a[i])<0)
            	count++;

        }
        printf("%d\n",count/2);
    }

	return 0;
}


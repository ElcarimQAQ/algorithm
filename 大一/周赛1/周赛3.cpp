#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
char a[100000000];

int main ()
{
    int l; 
    gets(a);
    l=strlen(a);
    for (int i=0;i<l-1;i++){
        for (int j=0;j<l-1-i;j++){
            char temp;
            if (a [j]>a[j+1]){
                temp=a [j+1];
                a [j+1]=a [j];
                a [j]=temp;
            }
        }
    }
    
    printf("%s\n",a);
  
    
    
	return 0;
}

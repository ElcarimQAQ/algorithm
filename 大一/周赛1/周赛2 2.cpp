#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include<algorithm>
using namespace std;
char a[100000000];

int main ()
{
    int l; 
    gets(a);
    l=strlen(a);
    sort (a,a+l);
    
    printf("%s\n",a);
  
    
    
	return 0;
}

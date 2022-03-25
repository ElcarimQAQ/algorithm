#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int main ()

{
	int x; 
	cin>>x;
    int sum=0;
    int a;
    while(x>0){
        a=x%10;
        sum+=a;
        x/=10;
    }
    printf("%d\n",sum);

	return 0;
}


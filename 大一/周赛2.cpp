#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[105]={0};

int main ()
{
    int n,id,cont;
    char b;
    cont=1;
    scanf("%d",&n);
    while (n--){

        scanf("%c%d",&b,&id);
        a [id]=1;
    }
    for (int i=1;i<=104;i++){
        if (a [i]==1)
            cont++;

    }
	printf("%d\n",cont);

	return 0;
}


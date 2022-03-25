#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
char a[6];
char b[6];
int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    scanf("%s",&a);
    int flag=0;
    int l=strlen(a);
    if(l==1)
        exit(0);
    for(int i=0;i<l;i++){
        if(a[i]=='0'){
            for(i;i<l-1;i++){
               b[i]=a[i+1];
            }
            flag=1;
            break;
        }
        b[i]=a[i];
    }
    if(flag==1)
        printf("%s\n",b);
    else{
        for(int i=0;i<l-2;i++)
            printf("%c",b[i]);
        printf("1\n");

    }

	return 0;

}


#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
char a [100];

int main ()
{
    int n,l,flag;
    cin>>n;
    getchar();
    while (n--){
            flag=0;
        gets(a);
        l=strlen(a);
        if (a[0]>='a'&&a[0]<='z'||a[0]>='A'&&a[0]<='Z'||a [0]=='_'){
            for (int i=1;i<l;i++){
                if (a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z'||a [i]=='_'||a [i]>='0'&&a [i]<='9')
                    flag=1;
                else {
                    flag=0;
                    break;
                }
            }
           if (flag==1)
                printf("yes\n");
           else
                printf("no\n");
        }
        else
            printf("no\n");

    }
	return 0;
}

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

char a[55];
int main ()

{
    int m,f1,f2,f3,f4;
    cin>>m;
    getchar();

    while(m--){
        f1=f2=f3=f4=0;
        gets(a);
        int l=strlen(a);
        if (8<=l&&l<=16){
            for (int i=0;i<l;i++){
                if (a [i]>='A'&&a [i]<='Z')
                    f1=1;
                else if (a [i]>='a'&&a [i]<='z')
                    f2=1;
                else if (a [i]>='0'&&a [i]<='9')
                    f3=1;
                else
                    f4=1;
            }
            if (f1+f2+f3+f4>=3)
                printf("YES\n");
            else
                printf("NO\n");

        }
        else
            printf("NO\n");
    }
	return 0;
}

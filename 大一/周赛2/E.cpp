#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int main ()
{
	//freopen("D:\\input.txt", "r", stdin);
	//freopen("D:\\output.txt", "w", stdout);

    int t,r,p,q;
    char s[20],T[15];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&r);
        scanf("%s",&s);
        scanf("%d",&p);
        scanf("%s",&T);
		int l=strlen(T);
        if (strcmp(T,"Running")==0){

            cin>>q;
        }
        printf("%3d|%-16s|%d|",r,s,p);
        if(strcmp(T,"FB")==0)
            printf("[    AC*   ]");
        else if(strcmp(T,"Running")==0){
            printf("[");
            for (int i=0;i<q;i++)
                printf("X");
            for (int i=q;i<10;i++)
                printf(" ");
            printf("]");
        }
        else if(l==3)
            printf("[    %s   ]",T);
        else{
            printf("[    %s    ]",T);
        }
        printf("\n");


    }


	return 0;
}


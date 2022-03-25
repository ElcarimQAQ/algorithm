#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
char s[1000];

int main ()
{
    freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        int l=strlen(s);
        int l1=(l+2)/3;
        int l2=l-2*l1;
        if(l==3)
            printf("%s\n",s);
        else{
            for(int i=0;i<l1-1;i++){
                printf("%c",s[i]);
                for(int j=0;j<l2;j++)
                    printf(" ");
                printf("%c\n",s[l-1-i]);
            }
            for(int i=l1-1;i<=l-l1;i++)
                printf("%c",s[i]);//
            printf("\n");
        }
        if(t)
            printf("\n");
    }
	return 0;
}



#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
char s[105];
int vis[200];
char z[105];
int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int k,l,m;
    while(scanf("%d",&k)!=EOF){
            int m=0;
        memset(vis,0,sizeof(vis));
        scanf("%s",s);
        l=strlen(s);
        if(l%k)
            printf("-1\n");
        else{
            for(int i=0;i<l;i++){
                vis[(int)s[i]]++;
            }
            int i;

                for(i='a';i<='z';i++){
                    if(vis[i]==0)
                        continue;
                    if(vis[i]%k){
                        printf("-1\n");
                        break;
                    }
                    else{
                        for(int j=0;j<vis[i]/k;j++)
                            z[m++]=i;
                            //printf("%c\n",i);


                    }
                }
            //printf("%d",i);
            if(i==123){
                //printf("0");
               while(k--)
                    printf("%s",z);
                printf("\n");
            }
            }

        }

    return 0;
}




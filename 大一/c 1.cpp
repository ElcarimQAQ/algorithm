#include<stdio.h>
#include<iostream>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<algorithm>                
#include<string>
#include<vector>
using namespace std;
char s[1000005];
int vis[1005];
int main ()
{
    int l,x;
    scanf("%s",&s);
    l=strlen(s);
    for (int i=0;i<l;i++){
        if (s[i]==','){
            vis[x]=1;
            x=0;
        }
        else
            x=x*10+s[i]-'0';

    }
    vis[x]=1;
    int flag=0;
    int st =-1;

    for (int i=1;i<=1000;i++){
        if (vis[i]==1){
            if(st==-1)
                st=i;

        }
        else {
            if(st==-1)
                continue;
            if (flag==0)
                 flag=1;
            else
                printf(",");
            if  (i-st==1){
                printf("%d",st);
            }
            else
                printf("%d-%d",st,i-1);
            st=-1;
        }
    }
    printf("\n");
	return 0;
}


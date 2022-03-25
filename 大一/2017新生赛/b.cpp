#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[105];
char s1[105],s2[105];

int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    int t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s1);
        scanf("%d",&n);
        int flag=1;
        char mc[105];
        memset(mc,'z',sizeof(mc));
        while(n--){
            scanf("%s",s2);
            int l=strlen(s1);
            for(int i=0;i<l;i++){
                if(s1[i]!=s2[i]){
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                if(strcmp(mc,s2)>=0)
                    strcpy(mc,s2);
            }
        }
        if (flag==1)
            printf("%s\n",mc);
        else
            printf("%s\n",s1);
    }
	return 0;
}


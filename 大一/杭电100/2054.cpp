#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int havepoint(char str[]){
    int i,len;
    len=strlen(str);
    for(i=0;i<len;i++){
        if(str[i]=='.')
            return 1;
    }
    return 0;
}
void change(char str[]){
    int i,len;
    len=strlen(str);
    if(havepoint(str)){
        for(i=len-1;str[i]=='0';i--){
            str[i]='\0';
            len--;
        }
        if(str[i]=='.')
            str[i]='\0';
    }

}

int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    char str1[1000000],str2[1000000];
    while(~scanf("%s %s",str1,str2))
    {
        change(str1);
        change(str2);
        if(strcmp(str1,str2)==0)
            printf("YES\n");
        else
            printf("NO\n");

    }
	return 0;
}


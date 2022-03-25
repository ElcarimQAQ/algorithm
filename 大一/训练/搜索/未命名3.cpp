#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int dp[45];
char a[45];
char s[3];
int n,cnt;
void dfs(int x){
	//printf("%d",cnt);
	if(a[x-1]!=a[x-2]&&a[x-1]!=a[x-3]&&a[x-3]!=a[x-2]&&x>3){
        return;
    }
    if(x-1==n){
        cnt++;
        dp[n-1]=cnt;
        if(x<=40)
    		dfs(x+1);
        return;
    }
    for(int i=0;i<3;i++){
            a[x]=s[i];
            dfs(x+1);
    }
}
int main ()
{
    s[0]='s';
    s[1]='m';
    s[2]='b';
    dfs(1);
    cnt=0;
    while(~scanf("%d",&n)){
        
        printf("%d\n",dp[n]);
    }
     
    return 0;
}

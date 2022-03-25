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
    int n,m;
    while(~scanf("%d%d",&n,&m)||n!=0&&m!=0){
        int st=1;
        while(st<=m||st<=n){
            int sum=0;
            for(int i=st;i<=n;i++){
                sum+=i;
                if(sum==m){
                    printf("[%d,%d]\n",st,i);
                    break;
                }
            }
            st++;
        }
        printf("\n");
    }
	return 0;
}

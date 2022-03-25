#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int x[15],y[15];
int main ()
{
    int n;
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++)
            scanf("%d%d",&x[i],&y[i]);
        for(int i=1;i;i++){
            int cnt=0;
            for(int j=1;j<=n;j++){
                if(i%x[j]==y[j])
                    cnt++;
            }
            if(cnt==n){
                printf("%d\n",i);
                break;
            }
        }

    }
	return 0;
}



#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
//+,/



int main ()
{
    char s[100][100];
    for (int i=1;i<=100;i++){
            for (int j=1;j<=100;j++)
                s[i][j]='.';

    }
	int t,a,b,c,st,en,k;
	scanf("%d",&t);
	while (t--){
      scanf("%d%d%d",&a,&b,&c);
      st=2*b+1;
      en=2*a+2*b+1;
      for (int i =1;i<=2*c+2*b+1;i++){
            if (i%2==1){
                for (int j=st;j<=en;j=j+2){
                    s[i][j]='+';
                    if (st>1)
                        s[i][j+1]='-';
                    else{
                        for  (j=2;j<=2*a;j=j+2)
                            s[i][j]='-';
                    }

                }
                if (st>1)
                    st--;//st=1时，进入正面
                if (i>2*c+1)
                    en--;
            }
            else{
                for (int j=st;j<=en;j=j+2){
                    if(st>1){
                        s[i][j]='/';

                        for(k=en;k<=en;k=k-2)
                            s[i][k]='|';
                    }
                    else {
                        for(j>2*a+1;j<=en;j=j+2)
                            s [i][j]='/';
                        s[i][j]='|';
                    }
                }

                if (st>1)
                    st--;//st=1时，进入正面
                if (i>2*c+1)
                    en--;
            }
        }
        for (int i=1;i<=2*c+2*b+1;i++){
            for (int j=1;j<=en;j++)
                printf("%c",s[i][j]);
            printf("\n"); 
        }
	}
	return 0;
}

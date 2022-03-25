#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
char s[100][100];


int main ()
{
    memset(s,'.',sizeof(s));
	int t,a,b,c;
	while (t--){
      cin>>a>>b>>c;
      for (int i =1;i<=2c+2b+1;i++){
            int st=2b+1;
            int en=2a+2b+1;
            if (i%2==1){
                for (int j=st;j<=2a+2b+1;j=j+2){
                    s[i][j]='+';
                    s[i][j+1]='-';
                }
                if (st>1)
                    st--;
            }
            else{
                for (int j=st;j<=2a+2b+1;j=j+2){
                    s[i][j]='/';
                }
                s[i][2a+2b+1]='|';
                if (st>1)
                    st--;
            }
        }
      }

	}
	return 0;
}

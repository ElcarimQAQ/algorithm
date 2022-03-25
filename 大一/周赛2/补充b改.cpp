#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn=1e6+5;
int x[maxn];

int main ()
{

    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int i=1;
        int l=n;
        while(n--){
            cin>>x [i];
            i++;
        }
        int flag=0;
        for (int j=1;j<=l;j++){
            if (x [j]==x [j+1]==x[j+2]==x [j+3]){
                printf("%d\n",j+3);
                flag=1;
                break;
            }
            else if ()
            for(int k=j+2;k<=l;k+=2){
                if (x [k]>=x [j]){
                    printf("%d\n",k);
                    flag=1;
                    break;
                }
            }
            if (flag==1)
                break;
        }
        if (flag==0)
            printf("Catch you\n");
    }

	return 0;
}


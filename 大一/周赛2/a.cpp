#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn=1e6+5;
int a[maxn];

int main ()
{
    char f;
    int id,m,now,n;
    memset(a,0,sizeof(a));
    m=now=0;
    cin>>n;
    while (n--){
        scanf("%c%d",&f,&id);
        if (f=='+'){
            now++;
            a [id]=1;
            m=max(m,now);
        }
        else{
            if (a[id]){
                a [id]=0;
                now--;
            }
            else{
                m++;
            }
        }

    }
     printf("%d\n",m);


	return 0;
}


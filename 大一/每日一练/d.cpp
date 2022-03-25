#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int main ()
{
    int n;
    scanf("%d",&n);
    int s=1;
    for(int i=1;i<=n;i++){
            s*=i;
        while(s%10==0){
            s/=10;
        }
            s=s%10000;
    }
    printf("%d",s%10);
    //freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);

	return 0;
}


#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main ()

{
    //freopen("in1.txt","r",stdin);
    //feropen("out1.txt","w",stdout);
    int m,a,b;
    cin>>m;
    while(m--){
        cin>>a>>b;
        int sum=0;
        for (int i=1;i<a;i++){
            if(a%i==0)
                sum+=i;
            
        }
        if (sum==b)
            printf("YES\n");
        else
            printf("NO\n");
    }
   
   
	return 0;
}


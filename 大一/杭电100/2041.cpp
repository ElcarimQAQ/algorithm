#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int a(int m){

    if (m==1|m==2)
        return 1;
    if (m>2) 
        return a(m-1)+a(m-2);
    
}

int main ()

{
    //freopen("in1.txt","r",stdin);
    //feropen("out1.txt","w",stdout);
    int n,m;
    cin>>n;
    getchar();
    while(n--){
        cin>>m;
        int t;
        t=a(m);
        printf("%d\n",t);
    }
    
	return 0;
}


#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

void gcd(int a,int b)
{
    int r;
    int ma=a;
    int mn=b;
    while(mn>0){
    r=mn;
    mn=ma%mn;
    ma=r;
    }
    printf("%d/%d ",a/ma,b/ma);
}


int main ()
{
	//freopen("D:\\input.txt", "r", stdin);
	//freopen("D:\\output.txt", "w", stdout);
 int t,h,m,s,a,b,c;
    cin>>t;
    while (t--){
        scanf("%d:%d:%d",&h,&m,&s);
        h=h%12;
		h=h*3600+m*60+s;
		m=m*720+s*12;
		s=s*720;


    	a=abs(h-m);
    	b=abs(h-s);
    	c=abs(m-s);
    	if(a>21600)
    		a=43200-a;
    	if (b>21600)
    		b=43200-b;
    	if (c>21600)
    		c=43200-c;
     if(a%120)
            gcd(a,120);
        else
            printf("%d ",a/120);
        if(b%120)
            gcd(b,120);
        else
            printf("%d ",b/120);
        if(c%120)
            gcd(c,120);
        else
            printf("%d ",c/120);
        printf("\n");


    }
	return 0;
}


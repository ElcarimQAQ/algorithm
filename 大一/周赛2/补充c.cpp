#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int jiaodu (int n1,int n2)
{
    int m;
    if (n1>=n2){
        if (n1-n2<=30)
            m=n1-n2;
        else
            m=60-(n1-n2);
    }
    else{
        if (n2-n1<=30)
            m=n2-n1;
        else
            m=60-(n2-n1);
    }
    return m;
}



int main ()
{
    int t,h,m,s,a,b,c;
    cin>>t;
    while (t--){
        scanf("%d:%d:%d",&h,&m,&s);
        int h=a%12£»
		h=h*3600+m*60+s;
		m=m*720+s*12;
		s=s*720;//½Ç¶ÈÀ©´ó120±¶£» 
        
    }
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
    		gcd(a)

	}
	return 0;
}


#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main ()
{
    int n,l,i,flag;
    char s[1000];
    char b[1000];//bÊÇµßµ¹ºóµÄ
    cin>>n;
    getchar();
    while (n--){
    	flag=0;
        gets(s);
        l=strlen(s);
        for (i=0;i<l;i++){
        	
            b[i]=s[l-1-i];
        }
       for (i=0;i<l;i++){
      
     		if (s[i]==b[i])
		    	flag++;
			else 
				break; 
	   }
	   if (flag==l)
			printf ("yes\n");
	   else 
			printf ("no\n");
    }
    
	return 0;
}

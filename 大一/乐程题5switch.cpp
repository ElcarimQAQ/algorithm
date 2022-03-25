#include <stdio.h>
int main ()
{
	int n;
	int flag=0;
	double p;
	scanf ("%d",&n);
	switch (n){
		case 1:
		 	p=2.4;
		 	break;
		case 2:
			 p=3.5;
			 break;
		 case 3:
			 p=5.9;
			 break;
		 case 4:
			 p=6.3;
			 break;
		 case 5:
			 p=9.8;
			 break;
		default:
			 printf ("ÊäÈë´íÎó");
			 flag=1; 
		 
	}
	if (flag=0)
		printf ("%.2lf",p); 
	return 0;
 } 

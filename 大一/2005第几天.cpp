#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int m[]={31,29,31,30,31,30,31,31,30,31,30,31};
int n[]= {31,28,31,30,31,30,31,31,30,31,30,31};
int main ()
{
	int a,b,c;
	while(~scanf("%d/%d/%d",&a,&b,&c)){
		int sum=0;
		if (a%4==0&&a%100!=0||a%400==0)
			{
				for (int i=0;i<b-1;i++){
					sum+=m[i];
				}
				sum=sum+c;
			}
		else {
			for (int i=0;i<b-1;i++)
				sum+=n[i];
			sum=sum+c;
		}
		printf ("%d\n",sum);
			
		
	}
	return 0;
}

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include<algorithm>
using namespace std;

int main ()
{
	int t,m,n,s;
	cin>>t;
	getchar();
	while (t--){
		cin>>n>>m;
		s=m*log10(n);
		printf("%d\n",s+1);
	} 
	return 0;
}

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int a[100];

int main ()
{
	int n;
	while (cin>>n){
		for (int i=0;i<n;i++){
			cin>>a[i];
		}
		int m=a [0];
		for (int i=1;i<n;i++){
			if (a [0]%a[i]!=0){
				a [0]+=m;
				i=0;
			}
		}
		cout<<a[0]<<endl;
	}
	return 0;
}

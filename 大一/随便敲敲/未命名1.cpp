#include <stdio.h>
#include <string.h>

int main ()
{
	int a[10]={12,30,51,47,92,31,2,84,13,24};
	//for(int i=0;i<10;i++)
		//scanf("%d",&a[i]);
	for(int i=0;i<9;i++){
		for(int j=0;j<9-i;j++){
			if(a[j+1]<a[j]){
				int temp;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	for(int i=0;i<10;i++)
		printf("%d ",a[i]);
	return 0;
 } 

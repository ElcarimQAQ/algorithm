#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int a[110],b[110];

int main ()
{
    int n,m;
    while (~scanf("%d%d",&n,&m)){
    	if (n==0&&m==0)
    		break;
    	int flag=0;
        for (int i=0;i<n;i++){
            cin>>a [i];
        }
        for (int i=0;i<m;i++){
            cin>>b[i];
        }// ‰»Î
        for(int i=0;i<n;i++){
            for (int j=0;j<m;j++){
                if (a[i]==b[j]){
                    a[i]=0;
               
                }
            }
        }
        for(int j=0;j<n-1;j++){
        	for (int k=0;k<n-1-j;k++){
        		if (a[k]>a[k+1]){
        			int temp;
        			temp=a[k+1];
        			a [k+1]=a [k];
        			a [k]=temp;
				}
			}			
		}
        int cout=0;
        for (int i=0;i<n;i++){
        
            if (a[i]!=0){
            	
            	
                printf("%d ",a [i]);
                flag=1;
        }
    }
        if (flag==0)
        	printf("NULL\n");
        else
        printf("\n");
    	}
	
	return 0;
}


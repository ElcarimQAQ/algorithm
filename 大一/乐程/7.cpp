#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int a[7];

int main ()
{
    int num,flag;
    for (int i=0;i<8;i++){
    cin>>a [i];		//ÊäÈë 
    }
    cin>>num;
    flag=0;
    for (int i=0;i<8;i++){
        if (num==a [i]){
            printf("%d",i+1);
            flag=1;
        }
    }
    if (flag==0)
        printf ("No Data");

	return 0;
}


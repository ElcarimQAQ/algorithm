#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int a[30005];
int main ()
{
    int w,n,d,cnt,i,j;
    cnt=0;
    scanf("%d",&w);
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        cin>>a [i];
    }
    sort(a,a+n);
    j=n-1;
    i=0;
    while(i<=j){

        if (a [i]+a [j]>w){
            cnt++;
            j--;
        }
        else{
            cnt++;
            j--;
            i++;
        }
    }
    cout<<cnt<<endl;




	return 0;
}



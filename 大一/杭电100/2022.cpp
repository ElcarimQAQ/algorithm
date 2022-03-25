#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int a [100][100];

int main ()
{
    int m,n,c,b,s;
    while (cin>>m>>n){
	

    c=b=0;
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            scanf ("%d",&a[i][j]);
            if (abs(a[i][j])>abs(a[b][c])){
                b=i;
                c=j;
            }
        }
    }
    s=a[b][c];
    printf("%d %d %d\n",b+1,c+1,s);
}
	return 0;
}

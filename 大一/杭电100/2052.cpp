#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
char s [100][100];

int main ()

{
    int n,m,j;
    while (cin>>n>>m){
        if (0<n&&m<75){

            for (int i=0;i<=m+1;i++){
                if (i==0||i==m+1){
                    cout<<'+';
                    for (int j=1;j<=n;j++)
                        cout <<'-';
                    cout<<'+'<<endl;
                }
                else{
                    for (int j=0;j<=n+1;j++){
                        if (j==0)
                            cout<<'|';
                        else if(j==n+1)
                            cout<<'|'<<endl;
                        else
                            cout<<' ';
                    }
                }
        	}
        cout<<endl;
        }
    }


	return 0;
}
	

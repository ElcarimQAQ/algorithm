#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int a[55][10];//a[n][m]
int b[10];
int main ()
{
    int n,m,sum1,sum2,count,flag;
    cin>>n>>m;
    getchar();
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for (int i=0;i<n;i++){
        sum1=0;
        for (int j=0;j<m;j++){
            sum1+=a[i][j];
            if (j==m-1)
                printf("%.2lf",sum1/m*1.0); 
        }
        if (i==n-1)
            printf("\n");
        else
            printf(" ");
    }
    for (int j=0;j<m;j++){
        sum2=0;
        for (int i=0;i<n;i++){
            sum2+=a[i][j];
            if (j==m-1){
                for (int k=0;k<m;k++){
                    b[k]=sum2/n*1.0;
                }
                printf("%.2lf",sum2/n*1.0);
            }
        }
        if (j==m-1)
            printf("\n");
        else
            printf(" ");
    }
    count=flag=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (a[i][j]<=b[j]){
                flag=1;
                break;
            }
        }
       if (flag==0)
        count++;
    }
    printf ("%d",count);

    return 0;
}


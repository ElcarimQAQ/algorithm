#include <stdio.h>


int main ()
{
    int n=0;
    for (int i=1;i<5;i++){
        for (int j=1;j<5;j++){
            for (int k=1;k<5;k++){
                printf("%d%d%d ",i,j,k);
                n++;
            }
        }
    }
    printf("�����%d��",n);
	return 0;
}

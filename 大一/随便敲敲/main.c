#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum=0;
    for (int i=1;i<=100;i++){
        for (int j=2;j<i;j++){
            if (i%j==0)
                break;
            else
                sum+=i;
        }
    }
    printf("%d",sum);
    return 0;
}

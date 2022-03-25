#include <stdio.h>
int main ()

{
    int n,m;//n×ÜÊı£¬mÍÈ
    scanf("%d%d",&n,&m);
    for (int i=0;i<=n;i++){//i¼¦
        if (m==2*i+4*(n-i))
            printf("%d %d",i,n-i);
    }
    return 0;
}


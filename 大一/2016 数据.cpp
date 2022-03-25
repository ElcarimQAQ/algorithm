#include <stdio.h>

int main()
{
    int n;
    int i, min, k, t=0;

    while (scanf("%d", &n) && n != 0) 
    {
        int a[n];
        for (i = 0; i < n; i++) 
        {
            scanf("%d", &a[i]);
        }
    
        min = a[0];             
        for (i = 0; i < n; i++)
        {
            if (min > a[i])   
            {
                min = a[i];
                t = i;
            }
        }

        k = a[0];
        a[0] = min;
        a[t] = k;
        for (i = 0; i < n-1; i++)
        {
            printf("%d ", a[i]);
        }
        printf("%d\n", a[n - 1]);  
    }

    return 0;
}


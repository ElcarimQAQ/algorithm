#include<stdio.h>
#include<string.h>
 
int main()
{
    long long t, p, i, j, n, counter, q;
    char s[100000];
 
    scanf("%lld", &t);
    getchar();
    while(t--)
    {
        counter = 0;
        gets(s);
        n = strlen(s);
        p = (strlen(s) + 2) / 3;
        counter = n - (2 * p);
        for(i = 0, j = n - 1; i < p - 1, j > n - p; i++, j--)
        {
            printf("%c", s[i]);
            for(q = 1; q <= counter; q++)
            {
                printf(" ");
            }
            printf("%c\n", s[j]);
        }
        for(i = p - 1; i <= n - p; i++)
        {
            printf("%c", s[i]);
        }
        if(t != 0)
        {
            printf("\n\n");
        }
 
    }
}

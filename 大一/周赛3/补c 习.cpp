#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<string.h>
#include<vector>
#include<string>
#include<algorithm>
#include<memory.h>
using namespace std;


int a[200006],n,sw,num;

int main()
{
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", &num);//±àºÅ
        a[num] = i;
    }
    int tmp = 0;
    int cnt = 0;
    int tmpn = n;
    while(n--)
    {
        cnt++;
        scanf("%d", &sw);
        if(a[sw] <= tmp)
        {
            printf("0");
        }
        if(a[sw] > tmp)
        {
            printf("%d",a[sw] - tmp);
            tmp = a[sw];
        }
        if(cnt < tmpn)
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}

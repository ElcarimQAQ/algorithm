#include<stdio.h>
#include<math.h>
int main()
{
    int i, n;
    double item, sum;
 
    scanf("%lf%d", &item, &n);
    sum = 0.0;
 
    for(i = 1; i <= n; i++)
    {
        sum += item;  //累加当前项
        item = sqrt(item);  //计算下一项
    }
 
    printf("%.2f\n", sum);
    return 0;
}


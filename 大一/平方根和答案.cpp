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
        sum += item;  //�ۼӵ�ǰ��
        item = sqrt(item);  //������һ��
    }
 
    printf("%.2f\n", sum);
    return 0;
}


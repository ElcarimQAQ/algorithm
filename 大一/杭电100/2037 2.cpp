#include<stdio.h>
#include<algorithm>
using namespace std;
struct d
{
    int m;
    int n;
};

bool cmp(d m,d n)//�Խṹ�����򣻽�����˸�ʽ������sort���ã� 
{
    return m.n<n.n;
}

int main()
{
    int n;
    
    while(~scanf("%d",&n)&&n)
    {
        d jiemu[100],t;//c++�ж���ṹ����������struct; 
        int i,count=1;
        for(i=0;i<n;i++)
        scanf("%d %d",&jiemu[i].m,&jiemu[i].n);
        
        sort(jiemu,jiemu+n,cmp);
        
        t.n=jiemu[0].n;
        for(i=1;i<n;i++)
        {
            if(jiemu[i].m>=t.n)
            {
                count++;
                t.n=jiemu[i].n;
            }
        }
        printf("%d\n",count);        
        
    }
    return 0;
}

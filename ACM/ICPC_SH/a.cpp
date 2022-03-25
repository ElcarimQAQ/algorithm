#include<bits/stdc++.h>
using namespace std;
int T;
int main()
{
    int x,y,i,j,sum=0;
    scanf("%d",&T);
    while(T--)
    {
        sum=0;
        scanf("%d%d",&x,&y);
        for(i=0;i<=x;i++)
        {
            j=0;
            if(i==0) j=1;
            for(j;j<=y;j++)
            {
                if((i&j)==0) sum=sum+log(i+j)/log(2)+1;
            }
        }
        printf("%d\n",sum);
    }
    system("pause");
    return 0;
}
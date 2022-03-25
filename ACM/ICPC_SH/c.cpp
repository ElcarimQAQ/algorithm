#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long t,i,j,k,x,y,an=0;
    cin>>t;
    while(t--)
    {
        an=0;
        cin>>x>>y;
        for(i=0;i<=x;i++)
        {
            j=0;
            if(i==0)
            {
                j=1;
            }
            for(j;j<=y;j++)
            {
                if((i&j)==0)
                {
                    an=an+(log(i+j)/log(2))+1;
                }
            }

        }
        cout<<an<<endl;
        system("pause");
    }
    return 0;
}
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
#define long long
using namespace std;
char mmp[100][100];
int h,l,r;
void sob()
{
    for(int i=l*2+1;i<=l*2 + r*2+1;i++)
    {
        for(int j=1;j<=2*h+1;j++)
        {
            if((i-l*2-1)%2)
                if(j%2)mmp[i][j]='|';
                else mmp[i][j]='.';
            else
                if(j%2)mmp[i][j]='+';
                else mmp[i][j]='-';
        }
    }
    for(int i=1;i<=l*2;i++)
    {
        for(int j=1;j<=2*h+1+2*l-i+1;j++)
        {
            if(i%2)
                if(j<=2*l+1-i)mmp[i][j]='.';
                else
                    if(j%2)mmp[i][j]='+';
                    else mmp[i][j]='-';
            else
                if(j<=2*l+1-i)mmp[i][j]='.';
                else
                    if(j%2)mmp[i][j]='.';
                    else mmp[i][j]='/';
        }
    }
    for(int i=1;i<=l*2 + r*2+1;i++)
    {
        for(int j=1;j<=2*h+1+2*l;j++)
            if(!mmp[i][j])
                if(i%2)
                    if(j%2)mmp[i][j]='+';
                    else mmp[i][j]='.';
                else
                    if(j%2)mmp[i][j]='|';
                    else mmp[i][j]='/';
    }
    for(int i=1;i<=2*l; i++)
    {
        int ti = i+2*r+1;
        for(int j=2*h+1+2*l-i+1;j<2*h+1+2*l+1;j++)
            mmp[ti][j]='.';
    }
}
 
int main() {
 
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(mmp,0,sizeof(mmp));
        scanf("%d%d%d",&h,&l,&r);
        sob();
        for(int i=1;i<=2*(l+r+1)-1;i++)
        {
            for(int j=1;j<=h*2+1+l*2;j++)
                printf("%c",!mmp[i][j]?' ':mmp[i][j]);
            printf("\n");
        }
    }
    return 0;
}


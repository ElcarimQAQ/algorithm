#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int n,m,a,b,k,s,p;
int point[1000005];
int ma[1000005];

int found(int x){
    int q,tmp;
    q=x;
    while(x!=point[x])
        x=point[x];
    while(q!=x){
        tmp=point[q];
        point[q]=x;
        q=tmp;
    }
    return x;
}

void join(int x,int y){
    int a=found(x);
    int b=found(y);
    if(a!=b)
        point[a]=b;
}

int main ()
{
    freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
    while(~scanf("%d%d",&n,&m)){
        memset(ma,'0',sizeof(ma));
        for(int i=1;i<=n;i++)
            point[i]=i;
        while(m--){
            scanf("%d%d",&a,&b);
            join(a,b);
        }
        scanf("%d",&k);
        while(k--){
            scanf("%d",&s);
            p=found(s);
            ma[p]=1;
        }
        int cnt=0;
        for(int i=1;i<=n;i++){
            if (ma[i]==1)
                cnt++;
        }
        printf("%d\n",cnt);
    }
	return 0;
}


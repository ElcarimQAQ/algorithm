#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define INF 0x7fffffff;
using namespace std;
int pre[105];
struct edge{
int a,b,p;
bool operator< (const edge&b) const {return p<b.p;}
}e[10000];
int found(int x){
    if(pre[x]==x)
        return x;
    else
        return found(pre[x]);
}
/*
void join(int x,int y){
    int p=found(x);
    int q=found(y);
    if(p!=q)
        pre[q]=p;
        cnt++;
}
*/
int main(){

    //freopen("D:\\input.txt", "r", stdin);
    int n,m,cnt,sum;
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=105;i++)
            pre[i]=i;
        for(int i=1;i <= m; ++i)
            scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].p);
        sort(e+1,e+m+1);
        cnt=sum=0;
        for(int i=1;i<=m;i++){
            int fu=found(e[i].a);
            int fv=found(e[i].b);
            if(fu==fv) continue;
            sum+=e[i].p;
            pre[fu]=fv;
            cnt++;
        }
        if(cnt>=n-1)
            printf("%d\n",sum);
        else
            printf("No!\n");
            //printf("%d\n",cnt);
    }
    return 0;
}



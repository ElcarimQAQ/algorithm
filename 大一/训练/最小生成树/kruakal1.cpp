#include <stdio.h>
#include <iostream>
#include <string.h>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define INF 0x7fffffff
#define M 10000+10
using namespace std;
int pre[M];
int n,m;
int ant=0;
int ans=0;
int k=0;
struct node{
    int x,y;
    int val;
}road[100010];

bool cmp(node a,node b){
    return a.val<b.val;
}
void init(int v){
    for(int i=0;i<=v;i++)
        pre[i]=i;
}
int find(int x){
    return x==pre[x]?x:pre[x]=find(pre[x]);
}
bool unite(int a,int b){
    int fa=find(a);
    int fb=find(b);
    if(fa!=fb){
        pre[fa]=fb;
        return true;
    }
    return false;
}
void kruskal(){
    ans=0;
    for(int i=0;i<k;i++){
        if(ant==n-1)
            break;
        if(unite(road[i].x,road[i].y)){
            ant++;
            ans+=road[i].val;
        }
    }
}
int main ()
{
    while(~scanf("%d",&n)){
        init(n);
        k=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&road[k].val);
                road[k].x=i;
                road[k].y=j;
                k++;
            }
        }
        ant=0;
        sort(road,road+k,cmp);
        kruskal();
        printf("%d\n",ans);
    }
    return 0;
}


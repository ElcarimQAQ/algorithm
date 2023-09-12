#include <bits/stdc++.h>
using namespace std;
#define M 10000+10
using namespace std;

int pre[M];             // 存储并查集的父节点
int n,m;                // 节点数和边数
int ant=0;              // 当前生成树中的边数
int ans=0;              // 当前生成树的权值和
int k=0;                // 边数
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

// 并查集查找函数
int find(int x){
    return x==pre[x]?x:pre[x]=find(pre[x]);
}

// 并查集合并函数
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
                road[k].y=j;   // 记录起点和终点
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


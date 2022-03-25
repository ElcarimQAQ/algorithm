#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
const int maxn=1005;

int pre[maxn],n;
int cnt[1005],num;

struct point{
    int x;
    int y;
};
point pt[maxn];

int found(int a){
    if(pre[a]==a)
        return a;
    return found(pre[a]);
}

int dis(point a,point b,int d){
    double c=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
    if(c<=d)
        return 1;
    else
        return 0;
}




void join(int a,int b){
    int x=found(a);
    int y=found(b);
    if(x!=y)
        pre[y]=x;
}


int main ()
{
    freopen("D:\\input.txt", "r", stdin);
    //freopen("D:\\output.txt", "w", stdout);
	int num=1;
	int d,p,q;
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<1005;i++)
		pre[i]=i;
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&pt[i].x,&pt[i].y);
    char a[2];
    while(scanf("%s",a)!=EOF){
        if(a[0]=='0'){
            scanf("%d",&p);
            for(int i=1;i<=num;i++){
                if(dis(pt[cnt[i]],pt[p],d))
                    join(p,cnt[i]);

            }
            cnt[num++]=p;
        }
        if(a[0]=='S'){
            scanf("%d%d",&p,&q);
            if(found(p)==found(q))
                printf("SUCCESS\n");
            else
                printf("FAIL\n");
        }
    }
	return 0;
}


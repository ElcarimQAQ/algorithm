#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
 
int father[1005],n;
int COUNT[1005],num;
struct POINT
{
	int x;
	int y;
};
POINT pt[1005];
 
int find(int p)
{
	if(p==father[p])
		return p;
	return find(father[p]);
}
 
int dis(POINT a,POINT b,int d)
{
	double c;
	c=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)*1.0);
	if(c<=d)
		return 1;
	else
		return 0;
}
 
void Union(int a,int b)
{
	int x,y;
	x=find(a);
	y=find(b);
	if(x!=y)
		father[y]=x;
}
 
int main()
{
	freopen("D:\\input.txt", "r", stdin);
	int i,x,y;
	int d;
	char control[2];
	scanf("%d%d",&n,&d);
	num=1;
	memset(COUNT,0,sizeof(COUNT));
	for(i=1;i<=1005;i++)
		father[i]=i;

	for(i=1;i<=n;i++)
		scanf("%d%d",&pt[i].x,&pt[i].y);
	while(scanf("%s",control)!=EOF)
	{
		if(control[0]=='O')
		{
			scanf("%d",&x);
			for(i=1;i<=num;i++)
			{
				if(dis(pt[COUNT[i]],pt[x],d))
					Union(x,COUNT[i]);
			}
			COUNT[num++]=x;
		}
		if(control[0]=='S')
		{
			scanf("%d%d",&x,&y);
			if(find(x)==find(y))
				printf("SUCCESS\n");
			else
				printf("FAIL\n");
		}
	}
	return 0;
}


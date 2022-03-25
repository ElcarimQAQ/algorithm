#include<stdio.h>
#include<string.h>
#include<queue>
#include<stdlib.h>
using namespace std;
int map[7][7];
int vis[7][7];     //标记
int d[4][2]={1,0,0,1,0,-1,-1,0};      //四个方向
struct node{
	int x,y;
	int step;    //步数
	node *last;  //指向上一个状态
};
node* Bfs(int x,int y){
	int i;
	memset(vis,0,sizeof(vis));
	vis[0][0]=1;
	queue<node *>q;
	node *s;
	s=(node *)malloc(sizeof(node));
	s->x=x;
	s->y=y;
	s->step=0;
	s->last=NULL;
	q.push(s);
	while(!q.empty()){
		s=q.front();
		q.pop();
		if(s->x==4&&s->y==4)
			return s;
		for(i=0;i<4;i++){
			int xx=s->x+d[i][0];
			int yy=s->y+d[i][1];
			if(xx<0||yy<0||xx>4||yy>4)continue;
			if(map[xx][yy])continue;
			if(vis[xx][yy])continue;
			vis[xx][yy]=1;
			node *e;       //注意e必须定义在循环里面
			e=(node *)malloc(sizeof(node));
			e->x=xx;
			e->y=yy;
			e->step=s->step+1;
			e->last=s;
			q.push(e);
		}
	}
	return NULL;
}
void Output(node *s){    //递归地输出路径
	if(s==NULL)return;
	Output(s->last);
	printf("(%d, %d)\n",s->x,s->y);
}
int main()
{
	freopen("D:\\input.txt", "r", stdin);
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			scanf("%d",&map[i][j]);
		}
	}
	Output(Bfs(0,0));
	return 0;
}


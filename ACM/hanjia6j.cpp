#include<bits/stdc++.h>
#include <algorithm>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=5e3+7;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
bool vis[maxn];//判断顶点是否被访问过，需要初始化
ll d[maxn];
ll w[maxn][maxn];//边的价值，w[from][to]
map<string,int> mp;

int n,m;//n为顶点数,m为边数

void prime()
{
    ll sum=0;
	for (int i = 1; i <= n; i++)//先选第一个点为集合
	{
		vis[i] = 0;
		d[i] = w[1][i];//存与第一个点成的集合到相连的点的权值
	}
    vis[1]=1;
	for (int i = 1; i <= n; i++)
	{
		int min1 = inf,p=0;
		for (int j = 1; j <= n; j++)
		{
			if (!vis[j] && d[j] < min1)//找出不属于集合，但是相连权值最小的点
			{
				min1 = d[j];
				p = j;
			}
		}
		if(min1==inf) break;//如果找不到了，就说明已经找完了，这里找的次数是n，如果没有这个条件很容易把inf算入
		//cout<<min1<<endl;
		vis[p] = 1;//标记已经加入集合了
		sum += min1;//加入答案中
		for (int j = 1; j <= n; j++)//更新一下于集合相连的点的权值
		{
			if (!vis[j] && w[p][j] < d[j])
			{
				d[j] = w[p][j];
			}
		}
	}
    for(int i = 1;i <= n;i++){
        if(vis[i]==0){
            cout<<"No!"<<endl;
            return;
        }
    }
	cout << sum << endl;
}

int main()
{
    while(cin>>n>>m)
    {
        mp.clear();
        memset(vis,0,sizeof(vis));

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                w[i][j]=inf;
        string tmp;
        int cnt = 0;
        cin>>tmp;
        for(int i=1;i<=m;i++)
        {
            string a,b;
            int from,to;
            ll cost;
            cin>>a>>b>>cost;
            if(!mp.count(a))
                mp[a] = ++cnt ;
            if(!mp.count(b))
                mp[b] = ++cnt;
            from = mp[a];
            to = mp[b];
            if(w[from][to] > cost)//为了谨慎些，还是判断下
            {
                w[from][to] = cost;
                w[to][from] = cost;//无向图
            }
        }
        if(m < n-1)
            cout<<"No!"<<endl;
        else
            prime();
    }
    return 0;
}
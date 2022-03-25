#include<bits/stdc++.h>
#include<iostream>
#include <stdio.h>
using namespace std;
const int maxn=100005;
const int base=131;
typedef long long ll;
#define pi acos(-1)
#define INF 0x3f3f3f3f
#define mod 998244353
const int inf=1<<30;
int a[1005][1005];
int main()
{
	int i,j,m,n,t;
	scanf("%d",&t);
	int cas=0;
	while(t--)
	{
		memset(a,0,sizeof(a));
		cas++; 
		int l,r;
        char ss[1005];
        cin.getline(ss,1005);
		scanf(" %d %d",&l,&r);
		scanf("%d",&n);
		int x,y;
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			a[x][y]=1;
		}
		int ans_mx=0,ans_mi=0,men=0;
		for(int i=0;i<l;i++)
		{
			for(int j=0;j<r;j++)
			{
				if(a[i][j]==1)
				{
					if(men==1)
					{
						ans_mx+=1;
						ans_mi+=1;
						men=0;
					}
					else
					{
						ans_mx+=men/2+men%2;
						ans_mi+=men/2;
						men=0;
					}
				}
				else
				{
					men++;
				}
			}
			if(men==1)
			{
				ans_mx+=1;
				ans_mi+=1;
				men=0;
			}
			else
			{
				ans_mx+=men/2+men%2;
				ans_mi+=men/2;
				men=0;
			}
			
		}
		printf("Case #%d: %d %d\n",cas,ans_mx,ans_mi);
	}
	return 0;
 }
#include<stdio.h>
int main()
{
	int a,b,c,d,t;
	scanf("%d",&t);
	while(t--)
	{
		int flag=0;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int a1[3];a1[0]=0,a1[1]=1,a1[2]=3; 
		int p[10][10][10]={0};
		for(int i=0;i<3;i++)
		{
			p[1][2][i]=a1[i],p[1][3][i]=a1[i],p[1][4][i]=a1[i];
			p[2][3][i]=a1[i],p[2][4][i]=a1[i],p[3][4][i]=a1[i];
		}	















        
		int a2=0,b2=0,c2=0,d2=0;
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				for(int k=0;k<3;k++)
				{
					for(int l=0;l<3;l++)
					{
						for(int r=0;r<3;r++)
						{
							for(int y=0;y<3;y++)
							{
								a2=0,b2=0,c2=0,d2=0;
								if(p[1][2][i]==3) a2+=3; if(p[1][2][i]==1) a2+=1,b2+=1;
								if(p[1][3][j]==3) a2+=3; if(p[1][3][j]==1) a2+=1,c2+=1;
								if(p[1][4][k]==3) a2+=3; if(p[1][4][k]==1) a2+=1,d2+=1;
								if(p[2][3][l]==3) b2+=3; if(p[2][3][l]==1) b2+=1,c2+=1;
								if(p[2][4][r]==3) b2+=3; if(p[2][4][r]==1) b2+=1,d2+=1;
								if(p[3][4][y]==3) c2+=3; if(p[3][4][y]==1) c2+=1,d2+=1;
								if(a2==a&&b2==b&&c2==2&&d2==d)
								flag++;
							}
						}
					}
				}	
			}
		 } 
		 if(flag==1) printf("Yes\n");
		 else if(flag>1) printf("No\n");
		 else printf("Wrong Scoreboard\n");
	}
	return 0;
 }
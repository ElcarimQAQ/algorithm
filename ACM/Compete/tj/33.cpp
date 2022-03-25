#include<iostream>
#include<cmath>
int b[1003],c[1003];
using namespace std;
int main()
{
	double o,n,an,an1;
	int i,j,k;
	char a;
	double p;
	string str;
	cin>>n;
	an=0;
	an1=0;
	while(n)
	{
		cin>>k>>a>>str;;
		if(k==0)
		{
			for(i=1;i<=1000;i++)
			{
				b[i]=0;
				c[i]=0;
			}
			if(an1!=0)
			{
				p=an/an1;
				if(p-int(an/an1)>=0.5)
				{
					cout<<an1<<" "<<int(an+an1-1)/an1<<endl;
				}
				else
				{
					cout<<an1<<" "<<int(an/an1)<<endl;
				}
			}
			else
			cout<<0<<" "<<0<<endl;
			an=0;
			an1=0;
			n--;
		}
		else
		{
			if(a=='S')
			{
				if(b[k]==0)
				{
					b[k]=((str[0]-'0')*10+str[1]-'0')*60+(str[3]-'0')*10+str[4]-'0';
					c[k]=1;
				 } 
			}
			if(a=='E')
			{
				if(c[k]==1)
				{
					an+=((str[0]-'0')*10+str[1]-'0')*60+(str[3]-'0')*10+str[4]-'0'-b[k];
					b[k]=0;
					c[k]=0;
					an1++;
				}
			}
		}
	}
 }
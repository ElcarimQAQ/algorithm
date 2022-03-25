#include <stdio.h>
int main()
{
	int n,i,a[10],c,d,min,max,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	min=max=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]<=min)
		  {
		  	min=a[i];
		  	j=i;
		  }
	}
	c=a[0];
	a[0]=min;
	a[j]=c;
	for(i=0;i<n;i++)
	{
		if(a[i]>=max)
		  {
		  	max=a[i];
		  	j=i;
		  }
	}
	d=max;
	a[j]=a[n-1];
	a[n-1]=d;
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	return 0;
}


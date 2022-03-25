#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int bro [1005],vis[1005];


int find(int x){
    if(bro[x]==x)
        return x;
    return bro[x]=find(bro[x]);
    }

void join(int x,int y){
    int p,q;
    p=find(x);
    q=find(y);
    if(p!=q)
        bro[p]=q;
}

int main ()
{
	freopen("D:\\input.txt","r",stdin);
    
    
    int t,n,m,a,b;
    cin>>t;
    while(t--){
    	for(int i=1;i<=1005;i++){
    	bro [i]=i;
    }
    memset(vis,0,sizeof(vis));
        cin>>n>>m;
        while(m--){
            cin>>a>>b;
            join(a,b);
        }
        int sum1,sum2;
        sum1=sum2=0;
        for(int i=1;i<=n;i++){
            int c=find(i);
            vis[c]++;
        }

        for(int i=1;i<=n;i++){
            if(vis[i]!=0)
                sum1++;
            if(vis[i]>sum2)
                sum2=vis[i];
        }
        printf("%d %d\n",sum1,sum2);



    }
}

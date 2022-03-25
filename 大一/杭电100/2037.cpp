#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include<algorithm>
using namespace std;
struct d
{
    int m;
    int n;
};

bool cmp(d m,d n){
    return m.n<n.n;
}
d j[110];
int main ()

{
   // freopen("in1.txt","r",stdin);
   
    d t;
    int n;
    
    while(cin>>n&&n!=0){
		int count=1;
       for (int i=0;i<n;i++){
            cin>>j[i].m>>j[i].n;
       }
       sort (j,j+n,cmp);
       t.n=j[0].n;
       for (int i=1;i<n;i++){
            if (j[i].m>=t.n){
                count++;
                t.n=j[i].n;
            }
       }
       printf("%d\n",count);
    }
    
   
	return 0;
}


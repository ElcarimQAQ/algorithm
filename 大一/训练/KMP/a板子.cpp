#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#define INF 0x7fffffff
using namespace std;
typedef long long ll;
#define M 1000005
char a[M],b[M];
int next[M];
int m,n,cnt;
void getnext()
{
    next[0]=-1;
    for(int i=1,j=0;i<m;i++,j++){
        while(j!=-1&&b[i]!=b[j])
            j=next[j];
        next[i+1]=j+1;
    }
}
void KMP(){
    for(int i=0,j=0;i<n;i++,j++){
        while(j!=-1&&a[i]!=b[j])
            j=next[j];
        if(j==m-1)
            cnt++;
    }
}
int main ()
{
    //freopen("D:\\input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--){
        cnt=0;
        scanf("%s%s",b,a);
        n=strlen(a);
        m=strlen(b);
        getnext();
        KMP();
        printf("%d\n",cnt);
    }
    return 0;
}

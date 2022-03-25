#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
#define MAXN 1005
#define INF 0x3fffffff
#define PI atan(1.0)*4
int dp[MAXN][MAXN];
int main ()
{
   	//freopen("D://input.txt","r",stdin);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            scanf("%d",&dp[i][j]);
    for(int i=n-1;i>=1;i--){
        for(int j=1;j<=i;j++){
            dp[i][j]=dp[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
        }
    }
    printf("%d\n",dp[1][1]);
    return 0;
}


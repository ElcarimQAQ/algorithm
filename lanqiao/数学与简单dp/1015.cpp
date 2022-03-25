#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int a[maxn][maxn];
int dp[maxn][maxn];

int main()
{
    int t,c,r;
    cin>>t;
    while (t--)
    {
        cin>>r>>c;
        for(int i = 1;i <= r; i++){
            for(int j = 1;j <= c; j++)
                cin>>a[i][j];
        }
        // dp[1][1] = a[1][1];
        for(int i = 1;i <= r; i++){
            for(int j = 1;j <= c; j++){
                dp[i][j] = a[i][j];
                dp[i][j] = dp[i][j] + max(dp[i - 1][j],dp[i][j - 1]);
            }
        }
        cout<<dp[r][c]<<endl;
    }
    
    return 0;
}
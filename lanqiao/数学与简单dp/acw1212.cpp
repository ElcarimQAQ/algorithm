#include <bits/stdc++.h>
using namespace std;
const int maxn = 100;
#define mod 1000000007
typedef long long ll;
ll g[maxn][maxn];
ll dp[maxn][maxn][15][15];

int main()
{
    int n,m,kk;
    cin>>n>>m>>kk;
    ll ans = 0;
    for(int i = 1;i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin>>g[i][j];
            g[i][j]++; 
        }
    }
    dp[1][1][1][g[1][1]] = 1;
    dp[1][1][0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1;j <= m; j++){
            if(i == 1 && j == 1) continue;
            for(int k = 0; k <= kk;k++){
                for(int c = 0;c <= 14;c++){
                    ll &val = dp[i][j][k][c];
                    val = (val + dp[i - 1][j][k][c] + dp[i][j - 1][k][c]) % mod;
                    if(k > 0 && (c == g[i][j])){ 
                        for(int cc = 0;cc < c;cc++){    
                            val = (val + dp[i - 1][j][k - 1][cc] + dp[i][j - 1][k - 1][cc]) % mod;
                        }
                    }
                }
            }
        }
        
    }
    
    for(int i = 0;i <= 14; i++)
        ans = (ans + dp[n][m][kk][i] )%mod;
    cout<<ans<<endl;
    return 0;
}
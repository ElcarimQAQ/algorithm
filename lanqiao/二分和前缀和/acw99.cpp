#include<bits/stdc++.h>
using namespace std;
const int maxn = 5002;
#define INF 1e18
typedef long long ll;
int f[maxn][maxn];

// int a[maxn];

int main()
{
    ios::sync_with_stdio(false);
    int n,r,x,y,v,mx = 0,my = 0;
    cin>>n>>r;
    r = min(5001,r);
    mx = r,my = r;
    for(int i = 1;i <= n;i++){
        cin>>x>>y>>v;
        f[x + 1][y + 1] += v;
        mx = max( x + 1, mx);
        my = max( y + 1, my);

    }
    for(int i = 1;i <= mx; i++){
        for(int j = 1;j <= my; j++){
            f[i][j] += f[i - 1][j] + f[i][j - 1] -f[i - 1][j - 1]; 
        }
    }
    // for(int i = 1;i <= n; i++){
    //     for(int j = 1;j <= n; j++){
    //         cout<<f[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int ans = 0;
    for(int i = r;i <= mx; i++){
        int cnt = 0;
        for(int j = r;j <= my; j++){
            // cnt = f[i][j] + f[i - r][j - r];
            cnt = f[i][j] - f[i][j - r] - f[i - r][j] + f[i - r][j - r];
            ans = max(ans,cnt);
        }
    }
    cout<<ans<<endl;
    return 0;    
}
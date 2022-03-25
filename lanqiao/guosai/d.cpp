#include <bits/stdc++.h>
using namespace  std;
#define  INF 0x3f3f3f3f
const int maxn = 10005;
typedef long long ll;

int f[maxn][maxn];
int vis[maxn];


int main()
{
    string s;
    cin>>s;
    int n = s.length();
    for(int i = 0;i < n;i++){
        if(!vis[s[i] - '0'] )f[i][i] = 1;
        vis[s[i] - '0'] = 1;
        for(int j = 0;j < i; j++){
            f[i][j] = f[i - 1][j];
            if(s[i] > s[j])
                f[i][i] += f[i - 1][j];
        }
    }
    int ans  = 0;
    for(int  i = 0;i < n;i++)
        ans += f[n-1][i];
    cout<<ans<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int f[maxn][maxn];
int main()
{
    int t,m,n;
    cin>>t;
    while(t--){
        memset(f,0,sizeof(f));
        f[0][0] = 1;

        cin>>m>>n;
        for(int i = 0; i <= m; ++i){
            for(int j = 1;j <= n; ++j){
                f[i][j] = f[i][j - 1] ;
                if(i >= j) f[i][j] += f[i - j][j];
            }
        }
        cout<<f[m][n]<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define eps 1e-8
typedef long long ll;
const  int maxn = 1005;
ll a[maxn][maxn];
ll le[maxn][maxn];

int main()
{
    int n,m,q,x1,x2,y1,y2;
    cin>>n>>m>>q;
    for(int i = 1; i <= n;++i){
        for(int j = 1;j <= m; ++j){
            cin>>a[i][j];
            le[i][j] = le[i][j - 1] + a[i][j];
        }
    }
    while(q--){
        cin>>x1>>y1>>x2>>y2;
        ll ans = 0;
        for(int i = x1;i <= x2; i++){
            ans += le[i][y2] - le[i][y1 -1];
        }
        cout<<ans<<endl;
    }
    return 0;
}